#include "shmpch.h"
#include "CoreSystemsLayer.h"
#include "Logger.h"
#include "Events\Event.h"

namespace Shmeckle
{
	CoreSystemsLayer::CoreSystemsLayer(const std::string& layerName)
		:Layer(layerName)
	{
	}

	void CoreSystemsLayer::OnEnabled(size_t layerIndex)
	{
		// Unused param
		(void)layerIndex;

		Logger::Initialize();
		EventBus::Initialize();
	}

	void CoreSystemsLayer::OnDisabled()
	{
		EventBus::CleanUp();
	}

	void CoreSystemsLayer::Update()
	{
		//Logger::InfoCore("Dispatching queued events...");
		EventBus::Instance().DispatchAll();
	}

}