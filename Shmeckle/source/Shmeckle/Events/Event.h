#pragma once
#include "Shmeckle\Core.h"

namespace shmeckle
{
	class SHMECKLE_API Event
	{
	public:
		// These types need to be implemented as event classes
		enum class Type
		{
			None = 0,
			WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved, // Found in ApplicationEvent.h
			KeyPressed, KeyReleased,                                                  // Found in KeyEvent.h
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled        // Found in MouseEvent.h
		};

		// This is here to make sure you can check for all Input events for example, without having to check every one separately
		// Look at 'Core.h' for the definition of Bit(x)
		enum Category
		{
			None = 0,                          // 0000 0000
			EventCategoryApplication = Bit(0), // 0000 0001
			EventCategoryInput = Bit(1),       // 0000 0010
			EventCategoryKeyboard = Bit(2),    // 0000 0100
			EventCategoryMouse = Bit(3),       // 0000 1000
			EventCategoryMouseButton = Bit(4)  // 0001 0000
		};

	public:
		virtual ~Event() = default;

		virtual Event::Type GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(Event::Category category) { return GetCategoryFlags() & category; }

	protected:
		Event() = default;

		Event(const Event& other) = delete;
		Event& operator=(const Event& other) = delete;
		Event(Event&& other) = delete;
		Event& operator=(Event&& other) = delete;

		bool m_Completed = false;

	private:
		//friend class EventDispatcher;
		friend class EventBus;
	};

	class EventBus
	{
	public:
		static void Initialize();
		static void CleanUp();

		static EventBus& Instance();

		using EventCallback = std::function<void(Event&)>;

		struct EventCallbackWrapper 
		{
			int id; // Unique identifier for the callback
			EventCallback callback;
		};

		template<typename EventClassType>
		int RegisterListener(std::function<void(EventClassType&)> callback)
		{
			//static_assert(std::is_base_of<Event, EventClassType>::value, "EventClassType must derive from Event");

			Event::Type type = EventClassType::GetStaticType();

			int id = GenerateUniqueID();

			// Wrap the specific callback into a generic one
			EventCallback wrappedCallback = [callback](Event& baseEvent)
			{
				// Perform a runtime cast to ensure the baseEvent is of the correct type
				EventClassType& specificEvent = static_cast<EventClassType&>(baseEvent);
				callback(specificEvent);
			};

			m_Listeners[type].push_back({ id, wrappedCallback });
			return id;
		}

		void UnregisterListener(Event::Type type, int id);

		inline void QueueEvent(std::unique_ptr<Event> event) 
		{
			m_EventQueue.push(std::move(event));
		}

		void DispatchEvents();

	private:
		EventBus() = default;
		~EventBus() = default;

		int GenerateUniqueID();

		std::unordered_map<Event::Type, std::vector<EventCallbackWrapper>> m_Listeners;
		std::queue<std::unique_ptr<Event>> m_EventQueue;
	};

	/*class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{

		}
		~EventDispatcher() = default;

		EventDispatcher(const EventDispatcher& other) = delete;
		EventDispatcher& operator=(const EventDispatcher& other) = delete;
		EventDispatcher(EventDispatcher&& other) = delete;
		EventDispatcher& operator=(EventDispatcher&& other) = delete;

		template<typename EventClassType>
		bool Dispatch(std::function<bool(EventClassType&)> function)
		{
			if (m_Event.GetEventType() == EventClassType::GetStaticType())
			{
				EventClassType& specificEvent = static_cast<EventClassType&>(m_Event);
				m_Event.m_Completed = function(specificEvent);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};*/

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}