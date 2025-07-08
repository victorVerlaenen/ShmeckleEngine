#pragma once
#include <string>

#include "Core.h"

namespace Shmeckle
{

	class Layer
	{
	public:
		Layer(const std::string& layerName = "Untitled");
		virtual ~Layer();

		Layer(const Layer& other) = delete;
		Layer& operator=(const Layer& other) = delete;
		Layer(Layer&& other) = default;
		Layer& operator=(Layer&& other) = default;

		SHM_API virtual void OnEnabled(size_t layerIndex);
		SHM_API virtual void OnDisabled();
		SHM_API virtual void Update();

		SHM_API inline const std::string& GetName() const { return name_; }

	protected:
		std::string name_;
	};

}