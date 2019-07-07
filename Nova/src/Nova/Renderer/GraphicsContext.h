#pragma once 

namespace Nova
{
	class GraphicsContext
	{
	public:
		//GraphicsContext(){}
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}