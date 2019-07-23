#pragma once
#include <iostream>
#include "Events/Event.h"
namespace Nova
{

	struct WindowProps
	{
		std::string Title;
		uint32_t Width, Height;

		WindowProps(std::string Title = "Nova Window", uint32_t width = 1280, uint32_t height = 720):
		Title(Title),Width(width), Height(height)
		{}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual inline uint32_t GetWidth() const = 0;
		virtual inline uint32_t GetHeight() const = 0;
		virtual inline void* GetNativeWindow() const = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetAspectRatio(uint32_t x, uint32_t y) = 0;
		virtual void SetTitle(const char* title) = 0;
		virtual inline bool IsVsync() const = 0;
		virtual void SetVsync(bool state) = 0;
		virtual void Update() = 0;

	public:
		static Window* Create(const WindowProps& props = WindowProps());
	private:

	};
}