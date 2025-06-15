#pragma once
#include "Shmeckle/Core.h"
#include <string>
#include <functional>
#include <queue>

namespace Shmeckle
{

	// These types need to be implemented as an event
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,	// WindowEvent.h
		KeyPressed, KeyReleased,												// KeyEvent.h
		MousePressed, MouseReleased, MouseMoved, MouseScrolled					// MouseEvent.h
	};

	enum EventCategory
	{
		None = 0,							// 0000 0000
		EventCategoryApplication = Bit(0),	// 0000 0001
		EventCategoryInput = Bit(1),		// 0000 0010
		EventCategoryKeyboard = Bit(2),		// 0000 0100
		EventCategoryMouse = Bit(3),		// 0000 1000
		EventCategoryMouseButton = Bit(4)	// 0001 0000
	};

	class SHM_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool isHandled_{ false };
	};

	class SHM_API EventBus
	{
	public:
		void Initialize();
		void CleanUp();

		static EventBus& Instance();

		template<typename EventType>
		void Subscribe(std::function<bool(EventType&)> callback)
		{
			subscribers_[EventType::GetStaticType()].push_back(callback);
		}

		void Publish(std::unique_ptr<Event> event)
		{
			eventQueue_.push(std::move(event));
		}

		void DispatchEvents() // Shiould happen somewhere at the end of a frame
		{
			// Dispatch all events
		}

	private:
		std::unordered_map<EventType, std::vector<std::function<bool(Event&)>>> subscribers_;
		std::queue<std::unique_ptr<Event>> eventQueue_;
	};
}