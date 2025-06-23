#pragma once
#include <format>

#include "Event.h"

namespace Shmeckle
{

	class SHM_API WindowEvent : public Event
	{
	public:
		inline virtual int GetCategoryFlags() const override { return (EventCategoryInput | EventCategoryMouse | EventCategoryApplication); }

		inline static EventType GetStaticType() { return EventType::MousePressed; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "MousePressed"; }

	protected:
		WindowEvent() = default;
	};
	
	class SHM_API WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent() {};

		std::string ToString() const override
		{
			return GetName();
		}

		inline static EventType GetStaticType() { return EventType::WindowClose; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "WindowClose"; }
	};

	class SHM_API WindowResizeEvent : public WindowEvent
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: width_(width), height_(height) {
		}

		inline unsigned int GetWidth() const { return width_; }
		inline unsigned int GetHeight() const { return height_; }

		std::string ToString() const override
		{
			return std::format("WindowResizeEvent: ({}, {})", width_, height_);
		}

		inline static EventType GetStaticType() { return EventType::WindowResize; }
		inline virtual EventType GetEventType() const override { return GetStaticType(); }
		inline const char* GetName() const override { return "WindowResize"; }

		private:
			unsigned int width_;
			unsigned int height_;
	};
}