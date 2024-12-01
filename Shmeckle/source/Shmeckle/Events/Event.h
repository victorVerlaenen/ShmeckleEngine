#pragma once
#include "Shmeckle\Core.h"

namespace shmeckle
{
	// These types need to be implemented as event classes
	enum class EventType
	{
		None = 0,
		WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved, // Found in ApplicationEvent.h
		KeyPressed, KeyReleased,                                                  // Found in KeyEvent.h
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled        // Found in MouseEvent.h
	};

	// This is here to make sure you can check for all Input events for example, without having to check every one separately
	// Look at 'Core.h' for the definition of Bit(x)
	enum EventCategory
	{
		None = 0,                          // 0000 0000
		EventCategoryApplication = Bit(0), // 0000 0001
		EventCategoryInput = Bit(1),       // 0000 0010
		EventCategoryKeyboard = Bit(2),    // 0000 0100
		EventCategoryMouse = Bit(3),       // 0000 1000
		EventCategoryMouseButton = Bit(4)  // 0001 0000
	};

	class SHMECKLE_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

	protected:
		Event() = default;
		virtual ~Event() = default;

		Event(const Event& other) = delete;
		Event& operator=(const Event& other) = delete;
		Event(Event&& other) = delete;
		Event& operator=(Event&& other) = delete;

		bool m_Completed = false;

	private:
		friend class EventDispatcher;
	};

	class EventDispatcher
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
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}