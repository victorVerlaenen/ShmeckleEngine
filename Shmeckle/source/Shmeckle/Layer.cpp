#include "shmpch.h"
#include "Layer.h"

namespace Shmeckle
{

	Layer::Layer(const std::string& layerName)
		:name_{ layerName }
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::OnEnabled(size_t layerIndex)
	{
		// Unused param
		(void)layerIndex;
	}

	void Layer::OnDisabled()
	{
	}

	void Layer::Update()
	{
	}

}