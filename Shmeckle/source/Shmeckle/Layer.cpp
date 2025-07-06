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

	void Layer::OnEnabled(unsigned int layerIndex)
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