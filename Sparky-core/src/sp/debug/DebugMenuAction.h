#pragma once

#include "sp/sp.h"
#include "sp/String.h"

#include "DebugMenu.h"
#include "sp/graphics/ui/Slider.h"

#include "sp/maths/maths.h"

namespace sp { namespace debug {

	struct IAction
	{
		String name;
		virtual void OnAction() = 0;
		virtual String ToString() = 0;
	};

	struct EmptyAction : public IAction
	{
		EmptyAction(const String& name) { this->name = name; }
		void OnAction() override {}
		String ToString() override { return name; }
	};

	struct BooleanAction : public IAction
	{
		using Getter = std::function<bool()>;
		using Setter = std::function<void(bool)>;
	private:
		Getter m_Getter;
		Setter m_Setter;
	public:
		BooleanAction(const String& name, const Getter& getter, const Setter& setter)
			: m_Getter(getter), m_Setter(setter) { this->name = name; }

		void OnAction() override
		{
			m_Setter(!m_Getter());
		}

		String ToString() override
		{
			return name + "     " + (m_Getter() ? "v" : "x");
		}
	};

	template<typename T>
	struct ValueAction : public IAction
	{
		using Getter = std::function<T()>;
		using Setter = std::function<void(T)>;
	private:
		Getter m_Getter;
		Setter m_Setter;
		T m_Min, m_Max;
	public:
		ValueAction(const String& name, const Getter& getter, const Setter& setter, T minValue, T maxValue)
			: m_Getter(getter), m_Setter(setter), m_Min(minValue), m_Max(maxValue) { this->name = name; }

		void OnAction() override
		{
			SP_ASSERT(false, "Not implemented!");
		}

		String ToString() override
		{
			return name + " " + StringFormat::ToString(m_Getter());
		}
	};

	typedef ValueAction<int32> IntAction;
	typedef ValueAction<float> FloatAction;

	typedef ValueAction<maths::vec2> Vec2Action;
	typedef ValueAction<maths::vec3> Vec3Action;
	typedef ValueAction<maths::vec4> Vec4Action;

} }
