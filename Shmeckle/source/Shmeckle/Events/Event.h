#pragma once
#include <string>
#include <functional>
#include <queue>
#include <memory>
#include <iostream>
#include <format>

#include "Shmeckle/Core.h"

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
		EventCategoryWindow = Bit(4)		// 0001 0000
	};

	class SHM_API Event
	{
	public:
		~Event() = default;

		Event(const Event& other) = delete;
		Event(Event&& other) = delete;
		Event& operator=(const Event& other) = delete;
		Event& operator=(Event&& other) = delete;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		static const unsigned int NUMBER_OF_TYPES_{ 11 }; // You should increment this for each new element type added

	protected:
		Event() = default;

		bool isHandled_{ false };
	};

	class EventBus
	{
	public:
		~EventBus() = default;

		EventBus(const EventBus& other) = delete;
		EventBus(EventBus&& other) = delete;
		EventBus& operator=(const EventBus& other) = delete;
		EventBus& operator=(EventBus&& other) = delete;

		SHM_API static void Initialize();
		SHM_API static void CleanUp();

		SHM_API static EventBus& Instance();

		// layerIndex will be used to represent the priority
		template<typename EventClassType>
		SHM_API void Subscribe(std::function<bool(EventClassType&)> callback, int layerIndex)
		{
			static_assert(std::is_base_of<Event, EventClassType>::value, "\"EventClassType\" must be an Event");

			auto wrapper
			{
				[callback](Event& event)->bool
				{
					return callback(static_cast<EventClassType&>(event));
				}
			};

			subscribers_[EventClassType::GetStaticType()].push_back({ layerIndex, wrapper });
		}

		SHM_API inline void QueueEvent(std::unique_ptr<Event> event)
		{
			eventQueue_.push(std::move(event));
		}

		SHM_API void DispatchAll();
		SHM_API void Dispatch(std::unique_ptr<Event> event);


	private:
		struct Subscriber
		{
			int priority;
			std::function<bool(Event&)> callback;
		};

		EventBus() = default;

		std::unordered_map<EventType, std::vector<Subscriber>> subscribers_;
		std::queue<std::unique_ptr<Event>> eventQueue_;
	};

}

// Specialize std::formatter
template <>
struct std::formatter<Shmeckle::Event> : std::formatter<std::string> {
	auto format(const Shmeckle::Event& p, format_context& ctx) {
		return formatter<std::string>::format(
			std::format("{}", p.ToString()), ctx);
	}
};