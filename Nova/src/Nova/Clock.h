#pragma once
#include "Nova/Core.h"

namespace Nova
{
	class NOVA_API Clock
	{
	public:
		Clock() :
			m_DeltaTime(0.0f), m_FrameRate(0.01f){}
		inline float GetDeltaTime() { return m_DeltaTime; }
		inline void SetDeltaTime(float deltatime) { m_DeltaTime = deltatime; }
		inline void SetFrameRate(float fps) { m_FrameRate = fps; }
		inline float GetFrameRate() { return m_FrameRate; }
	private:
		float m_DeltaTime;
		float m_FrameRate;
	};

}