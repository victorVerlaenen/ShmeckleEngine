#include "shmpch.h"

#include "Event.h"
#include "Shmeckle/Logger.h"

namespace Shmeckle
{
	static std::unique_ptr<EventBus> supInstance{ nullptr };

	void EventBus::Initialize()
	{
		if (supInstance)
		{
			Logger::WarningCore("The eventbus is already initialized. Canceling initialization...");
			return;
		}

		supInstance = std::unique_ptr<EventBus>(new EventBus());
	}

	void EventBus::CleanUp()
	{
		supInstance.reset();
	}

	EventBus& EventBus::Instance()
	{
		if (!supInstance)
		{
			Logger::ErrorCore("The eventbus needs to be initialized first");
			throw std::runtime_error("The eventbus needs to be initialized first"); // TEMPORARY
		}

		return *supInstance;
	}

	void EventBus::DispatchAll()
	{
		std::unique_ptr<Event> upCurrentEvent{ nullptr };
		EventType evaluatedEventType{ EventType::None };

		while (!eventQueue_.empty())
		{
			upCurrentEvent = std::move(eventQueue_.front());
			evaluatedEventType = upCurrentEvent->GetEventType();
			eventQueue_.pop();

			for (auto subscriber : subscribers_[evaluatedEventType])
			{
				if (subscriber.callback(*upCurrentEvent))
				{
					break;
				}
			}
		}
	}

	void EventBus::Dispatch(std::unique_ptr<Event> event)
	{
		EventType evaluatedEventType{ event->GetEventType() };

		for (auto subscriber : subscribers_[evaluatedEventType])
		{
			if (subscriber.callback(*event))
			{
				break;
			}
		}
	}

}