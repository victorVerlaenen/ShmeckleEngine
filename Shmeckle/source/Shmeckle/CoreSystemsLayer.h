#pragma once
#include "Layer.h"

namespace Shmeckle
{

	class CoreSystemsLayer : public Layer
	{
	public:
		CoreSystemsLayer(const std::string& layerName = "CoreSystemsLayer");
		virtual ~CoreSystemsLayer() = default;

		virtual void OnEnabled(size_t layerIndex) override;
		virtual void OnDisabled() override;
		virtual void Update() override;
	};

}