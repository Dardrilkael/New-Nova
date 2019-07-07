#pragma once 

#include "Nova/Events/Event.h"

namespace Nova
{ 

	class KeyPressedEvent : public Event
	{
		// Herdado por meio de Event
	public:
		KeyPressedEvent(uint32_t keycode):m_KeyCode(keycode){}
		inline uint32_t GetKeyCode() { return m_KeyCode; }
		EVENT_CLASS_TYPE(KeyPressed);
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	private:
		uint32_t m_KeyCode;
	};

	class KeyReleasedEvent : public Event
	{
		// Herdado por meio de Event
	public:
		KeyReleasedEvent(uint32_t keycode) :m_KeyCode(keycode) {}
		inline uint32_t GetKeyCode() { return m_KeyCode; }
		EVENT_CLASS_TYPE(KeyReleased);
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	private:
		uint32_t m_KeyCode;
	};

	class KeyTypedEvent : public Event
	{
		// Herdado por meio de Event
	public:
		KeyTypedEvent(uint32_t codepoint) :m_CodePoint(codepoint) {}
		inline uint32_t GetCodePoint() { return m_CodePoint; }
		EVENT_CLASS_TYPE(KeyTyped);
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	private:
		uint32_t m_CodePoint;
	};
}