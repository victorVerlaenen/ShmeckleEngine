#pragma once
#include <vector>
#include <memory>

#include "Core.h"
#include "Layer.h"

namespace Shmeckle
{

	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack() = default;

		LayerStack(const LayerStack& other) = delete;
		LayerStack& operator=(const LayerStack& other) = delete;
		LayerStack(LayerStack&& other) = delete;
		LayerStack& operator=(LayerStack&& other) = delete;

		SHM_API void PushLayer(std::unique_ptr<Layer> layer);
		SHM_API void RemoveLayer(std::unique_ptr<Layer> layer);
		SHM_API void PushOverlayLayer(std::unique_ptr<Layer> layer);
		SHM_API void RemoveOverlayLayer(std::unique_ptr<Layer> layer);

		SHM_API std::vector<std::unique_ptr<Layer>>::iterator begin() {return layers_.begin(); }
		SHM_API std::vector<std::unique_ptr<Layer>>::iterator end() {return layers_.end(); }

	private:
		std::vector<std::unique_ptr<Layer>> layers_;
		std::vector<std::unique_ptr<Layer>>::iterator layerInsertPoint_;
	};

}