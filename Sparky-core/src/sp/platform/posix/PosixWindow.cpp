#include "sp/sp.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "sp/utils/Log.h"
#include "sp/app/Window.h"
#include "sp/graphics/API/Context.h"
#include "sp/graphics/Renderer.h"


namespace sp {

	using namespace events;
	using namespace graphics;

	bool Window::PlatformInit()
	{
        GLFWwindow *window;

        if(!glfwInit())
        {
            SP_ERROR("Could not initialize GLFW!");
            return false;
        }

        window = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Title.c_str(), NULL, NULL);
        if(!window)
        {
            SP_ERROR("Could not create GLFW window!");
            glfwTerminate();
            return false;
        }

		RegisterWindowClass(window, this);

		graphics::API::Context::Create(m_Properties, window);

		//ShowWindow(hWnd, SW_SHOW);
		//SetFocus(hWnd);

        // resize

		return true;
	}

	void Window::PlatformUpdate()
	{
        /* TODO
		MSG message;
		while (PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE) > 0)
		{
			if (message.message == WM_QUIT)
			{
				m_Closed = true;
				return;
			}
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		m_InputManager->PlatformUpdate();
		Renderer::Present();
        */
	}

	void Window::SetTitle(const String& title)
	{
        /* TODO
		m_Properties.title = title + "  |  Renderer: " + Renderer::GetTitle();
		SetWindowText(hWnd, m_Properties.title.c_str());
        */
	}

    /* TODO
	void ResizeCallback(Window* window, int32 width, int32 height)
	{
		window->m_Properties.width = width;
		window->m_Properties.height = height;
		FontManager::SetScale(maths::vec2(window->m_Properties.width / 32.0f, window->m_Properties.height / 18.0f));

		if (window->m_EventCallback)
			window->m_EventCallback(ResizeWindowEvent((uint)width, (uint)height));
	}

	void FocusCallback(Window* window, bool focused)
	{
		if (!focused)
		{
			window->m_InputManager->ClearKeys();
			window->m_InputManager->ClearMouseButtons();
		}
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = NULL;
		Window* window = Window::GetWindowClass(hWnd);
		if (window == nullptr)
			return DefWindowProc(hWnd, message, wParam, lParam);

		InputManager* inputManager = window->GetInputManager();
		switch (message)
		{
		case WM_ACTIVATE:
		{
			if (!HIWORD(wParam)) // Is minimized
			{
				// active
			}
			else
			{
				// inactive
			}

			return 0;
		}
		case WM_SYSCOMMAND:
		{
			switch (wParam)
			{
			case SC_SCREENSAVE:
			case SC_MONITORPOWER:
				return 0;
			}
			result = DefWindowProc(hWnd, message, wParam, lParam);
		} break;
		case WM_SETFOCUS:
			FocusCallback(window, true);
			break;
		case WM_KILLFOCUS:
			FocusCallback(window, false);
			break;
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
			KeyCallback(inputManager, lParam, wParam, message);
			break;
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
			MouseButtonCallback(inputManager, message, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;
		case WM_SIZE:
			ResizeCallback(window, LOWORD(lParam), HIWORD(lParam));
			break;
		default:
			result = DefWindowProc(hWnd, message, wParam, lParam);
		}
		return result;
	}
    */

}
