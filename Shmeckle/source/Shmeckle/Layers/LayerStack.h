#pragma once
#include "Shmeckle\Core.h"
#include "Layer.h"

namespace shmeckle
{
	class SHMECKLE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlayLayer(Layer* layer);
		void PopOverlayLayer(Layer* layer);

		inline std::vector<Layer*>::iterator Begin() { return m_Layers.begin(); }
		inline std::vector<Layer*>::iterator End() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}