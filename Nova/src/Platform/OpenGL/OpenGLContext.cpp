#include "novapch.h"
#include "OpenGLContext.h"
#include "GLFW/glfw3.h"
#include "Nova/Core.h"
#include "glad/glad.h"
#include "Nova/Log.h"

namespace Nova
{
OpenGLContext::OpenGLContext(GLFWwindow * WindowHandle):
	m_WindowHandle(WindowHandle)
{
	NOVA_CORE_ASSERT(WindowHandle,"WindowHandle is null\n");
}

void OpenGLContext::Init()
{
	
	glfwMakeContextCurrent(m_WindowHandle);
	NOVA_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Could not Initialize Glad\n");
}

void OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}

}
