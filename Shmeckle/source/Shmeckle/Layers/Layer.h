#pragma once
#include "Shmeckle\Core.h"
#include "Shmeckle\Events\Event.h"

namespace shmeckle
{
	class SHMECKLE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnEnable();
		virtual void OnDisable();
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);

		inline const std::string& GetName() const { return m_Name; }

	protected:
		std::string m_Name;
	};
}