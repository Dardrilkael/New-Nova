#pragma once

#include "Nova/Layer.h"
		  
//#include "Nova/Events/ApplicationEvent.h"
#include "Nova/Events/KeyEvent.h"
#include "Nova/Events/MouseEvent.h"

namespace Nova {

	class NOVA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}