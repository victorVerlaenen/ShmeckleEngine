#include "shmpch.h"
#include "LayerStack.h"

Shmeckle::LayerStack::LayerStack()
{
	layerInsertPoint_ = layers_.begin();
}

void Shmeckle::LayerStack::PushLayer(std::unique_ptr<Layer> layer)
{
	layerInsertPoint_ = layers_.emplace(layerInsertPoint_, std::move(layer));
	size_t index = std::distance(layers_.begin(), layerInsertPoint_);
	layers_.at(index)->OnEnabled(index);
}

void Shmeckle::LayerStack::RemoveLayer(std::unique_ptr<Layer> layer)
{
	auto layerIt = std::find(layers_.begin(), layers_.end(), layer);
	if (layerIt != layers_.end())
	{
		layers_.erase(layerIt);
		layerInsertPoint_--;
	}
	layer->OnDisabled();
}

void Shmeckle::LayerStack::PushOverlayLayer(std::unique_ptr<Layer> layer)
{
	size_t index = layers_.size();
	layer->OnEnabled(index);
	layers_.emplace_back(std::move(layer));
}

void Shmeckle::LayerStack::RemoveOverlayLayer(std::unique_ptr<Layer> layer)
{
	auto layerIt = std::find(layers_.begin(), layers_.end(), layer);
	if (layerIt != layers_.end())
	{
		layers_.erase(layerIt);
	}
	layer->OnDisabled();
}
