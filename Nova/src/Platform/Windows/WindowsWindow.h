#include "Nova/Window.h"
#include "GLFW/glfw3.h"
#include "Nova/Renderer/GraphicsContext.h"
namespace Nova
{

	class WindowsWindow:public Window
	{
	public:
	struct  WindowData
	{
		std::string Title;
		uint32_t Width, Height;
		bool Vsync;
		EventCallbackFn EventCallback;
	};
		
		// Herdado por meio de Window
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		virtual inline uint32_t GetWidth() const override { return m_Data.Width; }
		virtual inline uint32_t GetHeight() const override { return m_Data.Height; }
		virtual inline void * GetNativeWindow() const override {return m_Window;}
		
		// Herdado por meio de Window
		virtual inline bool IsVsync() const override { return m_Data.Vsync; };
		virtual void SetVsync(bool state) override;;

		WindowsWindow(const WindowProps& props);
		~WindowsWindow();
	private:
	private:
		GLFWwindow* m_Window;
		WindowData m_Data;
		GraphicsContext* m_Context;

		// Herdado por meio de Window
		virtual void Update() override;

		// Herdado por meio de Window
		virtual void SetTitle(const char* title) override;
		virtual void SetAspectRatio(uint32_t x, uint32_t y) override;
	};
}