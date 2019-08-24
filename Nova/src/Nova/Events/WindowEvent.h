#pragma once 

#include "Nova/Events/Event.h"

namespace Nova
{
	class WindowCloseEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class WindowFocusEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowFocus);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowLostFocus);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};
	

	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent(int xpos, int ypos)
			: m_Xpos(xpos), m_Ypos(ypos){}
		EVENT_CLASS_TYPE(WindowMoved, );
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	private:
		int m_Xpos, m_Ypos;
	};	

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int width, int height)
			:m_Width(width), m_Height(height)
		{}
		EVENT_CLASS_TYPE(WindowResized);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	private:
		int m_Width, m_Height;
	};
}