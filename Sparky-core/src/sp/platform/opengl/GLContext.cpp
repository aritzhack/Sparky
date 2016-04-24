#include "sp/sp.h"
#include "GLContext.h"

#ifdef _MSC_VER
#undef NOGDI
#include <Windows.h>
#define NOGDI
#else
#include <GLFW/glfw3.h>
#endif
#include "sp/utils/Log.h"

#include <GL/glew.h>

namespace sp { namespace graphics { namespace API {

    #ifdef _MSC_VER
	static HDC hDc;
    #else
    GLFWwindow *window;
    #endif

	GLContext::GLContext(WindowProperties, void* deviceContext)
	{
        #ifdef _MSC_VER
		hDc = GetDC((HWND)deviceContext);
		HGLRC hrc = wglCreateContext(hDc);
		if (hrc)
		{
			if (!wglMakeCurrent(hDc, hrc))
			{
				SP_ERROR("Failed setting OpenGL context!");
				SP_ASSERT(false);
			}
		}
		else
		{
			SP_ERROR("Failed creating OpenGL context!");
			SP_ASSERT(false);
		}
        #else
        window = (GLFWwindow *) deviceContext;
        glfwMakeContextCurrent(window);
        #endif

		if (glewInit() != GLEW_OK)
		{
			SP_FATAL("Could not initialize GLEW!");
			SP_ASSERT(false);
		}
	}

	void GLContext::Present()
	{
        #ifdef _MSC_VER
		SwapBuffers(hDc);
        #else
        glfwSwapBuffers(window);
        #endif
	}

} } }
