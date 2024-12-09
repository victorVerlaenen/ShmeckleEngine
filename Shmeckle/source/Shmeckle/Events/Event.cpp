#include "smpch.h"
#include "Event.h"
#include "Shmeckle\Logger.h"

namespace shmeckle
{
	static EventBus* s_pInstance{ nullptr };

	void EventBus::Initialize()
	{
		if (s_pInstance)
		{
			Logger::CoreWarning("The EventBus is already initialized. Exiting Initialize()...");
			return;
		}

		s_pInstance = new EventBus();
	}

	void EventBus::CleanUp()
	{
		delete s_pInstance;
		s_pInstance = nullptr;
	}

	EventBus& EventBus::Instance()
	{
		if (!s_pInstance)
		{
			Logger::CoreWarning("The EventBus needs to be initialized first. Can't dereference a nullptr...");
			throw std::runtime_error("The EventBus needs to be initialized first. Can't dereference a nullptr...");
		}

		return *s_pInstance;
	}

	int EventBus::RegisterListener(Event::Type type, EventCallback callback)
	{
		int id = GenerateUniqueID();
		m_Listeners[type].push_back({ id, callback });
		return id;
	}

	void EventBus::UnregisterListener(Event::Type type, int id)
	{
		auto& listeners = m_Listeners[type];
		listeners.erase(
			std::remove_if(
				listeners.begin()
				, listeners.end()
				, [id](const EventCallbackWrapper& wrapper) { return wrapper.id == id; })
			, listeners.end());
	}

	void EventBus::DispatchEvents()
	{
		while (!m_EventQueue.empty()) {
			auto event = std::move(m_EventQueue.front());
			m_EventQueue.pop();

			auto& listeners = m_Listeners[event->GetEventType()];
			for (auto& wrapper : listeners) {
				wrapper.callback(*event);
			}
		}
	}

	int EventBus::GenerateUniqueID()
	{
		static int idCounter = 0;
		return ++idCounter;
	}
}