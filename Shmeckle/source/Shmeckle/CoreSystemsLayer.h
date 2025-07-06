#pragma once
#include "Layer.h"

namespace Shmeckle
{

	class CoreSystemsLayer : public Layer
	{
		CoreSystemsLayer(const std::string& layerName = "CoreSystemsLayer");
		virtual ~CoreSystemsLayer() = default;

		virtual void OnEnabled(unsigned int layerIndex) override;
		virtual void OnDisabled() override;
		virtual void Update() override;
	};

}