#include "Event.h"
#include "Shmeckle/Logger.h"

namespace Shmeckle
{
	static std::unique_ptr<EventBus> supInstance{ nullptr };

	void EventBus::Initialize()
	{
		if (supInstance)
		{
			SM_WARNING_CORE("The eventbus is already initialized. Canceling initialization...");
			return;
		}

		supInstance = std::unique_ptr<EventBus>(new EventBus());
	}

	void EventBus::CleanUp()
	{
		// Might need some cleanup
	}

	EventBus& EventBus::Instance()
	{
		if (!supInstance)
		{
			SM_ERROR_CORE("The eventbus needs to be initialized first");
			throw std::runtime_error("The eventbus needs to be initialized first");
		}

		return *supInstance;
	}

	void EventBus::DispatchEvents()
	{
		std::unique_ptr<Event> upCurrentEvent{ nullptr };
		EventType evaluatedEventType{ EventType::None };

		while (!eventQueue_.empty())
		{
			upCurrentEvent = std::move(eventQueue_.front());
			evaluatedEventType = upCurrentEvent->GetEventType();
			eventQueue_.pop();

			for (auto callback : subscribers_[evaluatedEventType])
			{
				if (callback(*upCurrentEvent))
				{
					break;
				}
			}
		}
	}

}