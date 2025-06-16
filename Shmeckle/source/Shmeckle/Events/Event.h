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

		template<typename EventClassType>
		void Subscribe(std::function<bool(EventClassType&)> callback)
		{
			static_assert(std::is_base_of<Event, EventClassType>::value, "\"EventType\" must be an Event");

			subscribers_[EventClassType::GetStaticType()].push_back(callback);
			// TODO : complete
		}

		void Publish(std::unique_ptr<Event> event)
		{
			eventQueue_.push(std::move(event));
			// TODO : complete
		}

		void DispatchEvents()
		{
			std::unique_ptr<Event> upEvaluatedEvent{ nullptr };
			EventType evaluatedEventType{ EventType::None };

			while (!eventQueue_.empty())
			{
				upEvaluatedEvent = std::move(eventQueue_.front());
				evaluatedEventType = upEvaluatedEvent->GetEventType();
				eventQueue_.pop();

				for (std::function<bool(Event&)> callback : subscribers_[evaluatedEventType])
				{
					if (callback(*upEvaluatedEvent))
					{
						break;
					}
				}
			}
		}

	private:
		std::unordered_map<EventType, std::vector<std::function<bool(Event&)>>> subscribers_;
		std::queue<std::unique_ptr<Event>> eventQueue_;
	};
}