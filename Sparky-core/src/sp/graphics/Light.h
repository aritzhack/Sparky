#pragma once

#include "sp/Types.h"
#include "sp/maths/maths.h"

#if defined(_MSC_VER)
    #define ALIGNED_(x) __declspec(align(x))
#elif defined(__GNUC__)
   #define ALIGNED_(x) __attribute__ ((aligned(x)))
#endif

namespace sp { namespace graphics {

	struct ALIGNED_(16) SP_API Light
	{
		maths::vec4 color;
		maths::vec3 position;
		float p0;
		maths::vec3 direction;
		float p1;
		maths::vec3 lightVector;
		float intensity;

		Light(const maths::vec3& direction, float intensity = 1.0f, const maths::vec4& color = maths::vec4(1.0f));
	};

} }