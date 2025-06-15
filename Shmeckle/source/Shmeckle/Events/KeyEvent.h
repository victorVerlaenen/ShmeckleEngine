#pragma once
#include "Core.h"
#include "Event.h"

#include <format>

namespace Shmeckle
{

	class SHM_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode_; }

		inline virtual int GetCategoryFlags() const override
		{
			return (EventCategoryKeyboard | EventCategoryInput);
		}

	protected:
		KeyEvent(int keyCode) : keyCode_(keyCode) {}

		const int keyCode_;
	};

	class SHM_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, bool isHolding)
			: KeyEvent(keyCode), holding_(isHolding)
		{
		}

		inline bool IsHolding() const { return holding_; }

		inline std::string ToString() const override
		{
			return std::format("KeyPressedEvent: {}{}", GetName(), holding_ ? "(Held down)" : "");
		}

		inline static EventType GetStaticType() { return EventType::KeyPressed; }
		inline virtual EventType GetEventType() const override {return GetStaticType(); }
		inline const char* GetName() const override { return "KeyPressed"; }

	private:
		bool holding_;
	};

}