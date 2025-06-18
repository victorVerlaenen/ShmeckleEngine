#pragma once
#include "Shmeckle/Core.h"
#include "Event.h"
#include <format>

namespace Shmeckle
{

	class SHM_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() const { return button_; }

		inline virtual int GetCategoryFlags() const override { return (EventCategoryInput | EventCategoryMouse | EventCategoryApplication); }

	protected:
		MouseButtonEvent(int button) :button_{ button } {}

		int button_;
	};

	class SHM_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :MouseButtonEvent{ button } {}

		std::string ToString() const override
		{
			return std::format("MouseButtonPressedEvent: {}", button_);
		}

		inline static EventType GetStaticType() { return EventType::MousePressed; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "MousePressed"; }
	};

	class SHM_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :MouseButtonEvent{ button } {}

		std::string ToString() const override
		{
			return std::format("MouseButtonReleasedEvent: {}", button_);
		}

		inline static EventType GetStaticType() { return EventType::MouseReleased; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "MouseReleased"; }
	};

	class SHM_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xPos, float yPos) :xPos_{ xPos }, yPos_{ yPos } {}

		inline float GetXPos() { return xPos_; }
		inline float GetYPos() { return yPos_; }

		std::string ToString() const override
		{
			return std::format("MouseMovedEvent: ({}, {})", xPos_, yPos_);
		}

		inline virtual int GetCategoryFlags() const override { return (EventCategoryInput | EventCategoryMouse | EventCategoryApplication); }

		inline static EventType GetStaticType() { return EventType::MouseMoved; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "MouseMoved"; }

	private:
		float xPos_, yPos_;
	};

	class SHM_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset_{ xOffset }, yOffset_{ yOffset } {}

		inline float GetXOffset() const { return xOffset_; }
		inline float GetYOffset() const { return yOffset_; }

		std::string ToString() const override
		{
			return std::format("MouseScrolledEvent: ({}, {})", GetXOffset(), GetYOffset());
		}

		inline virtual int GetCategoryFlags() const override { return (EventCategoryInput | EventCategoryMouse | EventCategoryApplication); }

		inline static EventType GetStaticType() { return EventType::MouseScrolled; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "MouseScrolled"; }

	private:
		float xOffset_, yOffset_;
	};
}