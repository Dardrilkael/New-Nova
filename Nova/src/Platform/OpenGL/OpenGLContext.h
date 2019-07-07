#pragma once
#include "Nova/Renderer/GraphicsContext.h"
struct GLFWwindow;

namespace Nova
{
class OpenGLContext:public GraphicsContext
{
public:
	OpenGLContext(GLFWwindow* WindowHandle);
	//~OpenGLContext();

	// Herdado por meio de GraphicsContext
	virtual void Init() override;
	virtual void SwapBuffers() override;
private:
	GLFWwindow* m_WindowHandle;
};
}

