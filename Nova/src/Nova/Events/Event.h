#pragma once
#include "novapch.h"
#include "Nova/Core.h"

namespace Nova
{

	enum class EventType
	{
		None = -1,
		WindowClose, WindowFocus, WindowLostFocus, WindowMoved, WindowResized,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, KeyReleased, KeyTyped,
		AppUpdate, AppTick, AppRender
	};

	enum EventCategory
	{


		EventCategoryApplication  = BIT(0),
		EventCategoryInput        = BIT(1),
		EventCategoryKeyboard     = BIT(2),
		EventCategoryMouse        = BIT(3),
		EventCategoryMouseButton  = BIT(4),
	};


#define EVENT_CLASS_TYPE(type)\
	virtual const char* GetName()const override {return #type;}\
	static EventType GetStaticType() {return EventType::##type;}\
	virtual EventType GetEventType() const override {return GetStaticType();}


#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const {return category;}

	

	class NOVA_API Event
	{
	public:
		bool Handled;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}