#pragma once

#include <GL/glew.h>
#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#else
#define DEBUG_BREAK
#endif

namespace sp {
	extern GLenum GLCheckError();
	extern bool GLLogCall(const char* function, const char* file, int32 line);
}

#ifdef SP_DEBUG
	#define GLCall(x) sp::GLCheckError();\
		x; \
		if (!sp::GLLogCall(#x, __FILE__, __LINE__)) DEBUG_BREAK;
#else
	#define GLCall(x) x
#endif
