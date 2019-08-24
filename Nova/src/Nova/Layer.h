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


		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnEvent(Event& e) {};
		virtual void OnUpdate() {};
		virtual void OnImGuiRender() {};
		inline const std::string& GetName(){ return m_Name; }

	protected:
		std::string m_Name;

	};

}
