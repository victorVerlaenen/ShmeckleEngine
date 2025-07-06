#include "shmpch.h"
#include "CoreSystemsLayer.h"
#include "Logger.h"
#include "Events\Event.h"

namespace Shmeckle
{

	void CoreSystemsLayer::OnEnabled(unsigned int layerIndex)
	{
		Logger::Initialize();
		EventBus::Initialize();
	}

	void CoreSystemsLayer::OnDisabled()
	{
		EventBus::CleanUp();
	}

	void CoreSystemsLayer::Update()
	{
		Logger::InfoCore("Dispatching queued events...");
		EventBus::Instance().DispatchAll();
	}

}