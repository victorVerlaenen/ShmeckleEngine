#pragma once
#include "Shmeckle/Core.h"
#include <string>
#include <functional>
#include <queue>
#include <memory>

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

	class EventBus
	{
	public:
		SHM_API static void Initialize();
		SHM_API static void CleanUp();

		SHM_API static EventBus& Instance();

		template<typename EventClassType>
		SHM_API void Subscribe(std::function<bool(EventClassType&)> callback)
		{
			static_assert(std::is_base_of<Event, EventClassType>::value, "\"EventClassType\" must be an Event");

			auto wrapper
			{
				[callback](Event& event)->bool
				{
					return callback(static_cast<EventClassType&>(event));
				}
			};

			subscribers_[EventClassType::GetStaticType()].push_back(wrapper);
		}

		SHM_API inline void Publish(std::unique_ptr<Event> event)
		{
			eventQueue_.push(std::move(event));
		}

		SHM_API void DispatchEvents();

	private:
		EventBus() = default;

		std::unordered_map<EventType, std::vector<std::function<bool(Event&)>>> subscribers_{};
		std::queue<std::unique_ptr<Event>> eventQueue_{};
	};
}