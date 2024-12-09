#pragma once
#include "Event.h"

namespace shmeckle
{
	class SHMECKLE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), 
			m_Height(height) 
		{

		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		static inline Event::Type GetStaticType() { return Event::Type::WindowResized; }

		virtual inline Event::Type GetEventType() const override { return GetStaticType(); }
		virtual inline const char* GetName() const override { return "WindowResized"; }
		virtual inline int GetCategoryFlags() const override { return EventCategoryApplication; }

	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class SHMECKLE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() 
		{

		}

		static inline Event::Type GetStaticType() { return Event::Type::WindowClosed; }

		virtual inline Event::Type GetEventType() const override { return GetStaticType(); }
		virtual inline const char* GetName() const override { return "WindowClosed"; }
		virtual inline int GetCategoryFlags() const override { return EventCategoryApplication; }
	};
}