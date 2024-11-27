#pragma once
#include "Event.h"
#include <sstream>

namespace shmeckle
{
	class SHMECKLE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const 
		{ 
			return m_KeyCode; 
		}

		virtual inline int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }

	protected:
		KeyEvent(int keycode) 
			: m_KeyCode(keycode) 
		{

		}

		int m_KeyCode;
	};

	class SHMECKLE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, bool held) 
			: KeyEvent(keycode), 
			m_Held(held)
		{

		}

		inline bool IsHeldDown() const 
		{ 
			return m_Held;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << (m_Held ? "Held down" : "Single press") << ")";
			return ss.str();
		}

		static inline EventType GetStaticType() { return EventType::KeyPressed; }

		virtual inline EventType GetEventType() const override 	{ return GetStaticType(); }
		virtual inline const char* GetName() const override { return "KeyPressed"; }

	private:
		bool m_Held;
	};

	class SHMECKLE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) 
		{

		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		static inline EventType GetStaticType() { return EventType::KeyReleased; }

		virtual inline EventType GetEventType() const override { return GetStaticType(); }
		virtual inline const char* GetName() const override { return "KeyReleased"; }
	};
}