#include "novapch.h"
#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Nova/Application.h"
namespace Nova
{
Input* Input::s_Instance = new WindowsInput;
bool WindowsInput::Impl_IsKeyPressed(int key)
{
	return  glfwGetKey((GLFWwindow*)Application::Get()->GetWindow().GetNativeWindow(), key);
}

bool WindowsInput::Impl_IsMouseButtonPressed(int button)
{
	return  glfwGetMouseButton((GLFWwindow*)Application::Get()->GetWindow().GetNativeWindow(),button);
}

std::pair<float, float> WindowsInput::Impl_GetMousePos()
{
	double xpos, ypos;
	glfwGetCursorPos((GLFWwindow*)Application::Get()->GetWindow().GetNativeWindow(), &xpos, &ypos);
	return {xpos,ypos};
}

float WindowsInput::Impl_GetMouseXPos()
{
	return this->Impl_GetMousePos().first;
}

float WindowsInput::Impl_GetMouseYPos()
{
	return this->Impl_GetMousePos().second;
}


}
