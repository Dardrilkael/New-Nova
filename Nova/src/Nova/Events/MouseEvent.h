#pragma once
#include "Event.h"

namespace Nova
{ 
class MouseButtonPressedEvent : public Event
{
public:
	MouseButtonPressedEvent(uint32_t button):
		m_Button(button){}
	uint32_t GetButton() { return m_Button; }

	EVENT_CLASS_TYPE(MouseButtonPressed);
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton);
private:
	uint32_t m_Button;
};

class MouseButtonReleasedEvent : public Event
{
public:
	MouseButtonReleasedEvent(uint32_t button) :
		m_Button(button) {}
	uint32_t GetButton() { return m_Button; }

	EVENT_CLASS_TYPE(MouseButtonReleased);
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton);
private:
	uint32_t m_Button;
};

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(float xpos, float ypos) :
		m_xPos(xpos), m_yPos(ypos) {}
	float GetXpos() { return m_xPos; }
	float GetYpos() { return m_yPos; }


	EVENT_CLASS_TYPE(MouseMoved);
	EVENT_CLASS_CATEGORY(EventCategoryMouse);
private:
	float m_xPos, m_yPos;
};

class MouseScrolledEvent : public Event
{
public:
	MouseScrolledEvent(float xofsset, float yofsset) :
		m_xOfsset(xofsset), m_yOfsset(yofsset) {}
	float GetXofsset() { return m_xOfsset; }
	float GetYofsset() { return m_yOfsset; }


	EVENT_CLASS_TYPE(MouseScrolled);
	EVENT_CLASS_CATEGORY(EventCategoryMouse);
private:
	float m_xOfsset, m_yOfsset;
};

}