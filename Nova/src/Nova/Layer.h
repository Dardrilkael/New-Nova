#pragma once
#include "Nova/Core.h"
#include <string>
#include "Nova/Events/Event.h"
namespace Nova
{

	class NOVA_API Layer
	{
	public:
		Layer(const std::string& name = "layer") :m_Name(name) {}


		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnEvent(Event& e) = 0;
		virtual void OnUpdate() = 0;

		inline const std::string& GetName(){ return m_Name; }

	protected:
		std::string m_Name;

	};

}
