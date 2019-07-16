#pragma once 
#include "Core.h"

namespace Nova
{
	class NOVA_API Input
	{
	public:
		inline static bool IsKeyPressed(int key) { return  s_Instance->Impl_IsKeyPressed(key); }
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->Impl_IsMouseButtonPressed(button); }
		inline static std::pair<float,float> GetMousePos() { return  s_Instance->Impl_GetMousePos(); }
		inline static float GetMouseXPos() { return s_Instance->Impl_GetMouseXPos(); }
		inline static float GetMouseYPos() { return s_Instance->Impl_GetMouseYPos(); }
	protected:
		virtual bool Impl_IsKeyPressed(int key) = 0;
		virtual bool Impl_IsMouseButtonPressed(int button) = 0;
		virtual std::pair<float, float> Impl_GetMousePos() = 0;
		virtual float Impl_GetMouseXPos() = 0;
		virtual float Impl_GetMouseYPos() = 0;
	private:
		static Input* s_Instance;
	};


}