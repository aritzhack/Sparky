cmake_minimum_required(VERSION 2.8)

project(Sparky-core)

set (SRC_LIST 	src/sp/app/Input.cpp
				src/sp/debug/DebugMenuItem.cpp
				src/sp/debug/DebugMenuSlider.cpp
				src/sp/events/WindowEvent.cpp
				src/sp/graphics/API/Texture2D.cpp
				src/sp/graphics/API/TextureCube.cpp
				src/sp/graphics/API/TextureDepth.cpp
				src/sp/graphics/API/VertexBuffer.cpp
				src/sp/graphics/camera/FPSCamera.cpp
				src/sp/debug/DebugRenderer.cpp
				src/sp/graphics/API/Context.cpp
				src/sp/graphics/DeferredRenderer.cpp
				src/sp/graphics/API/Framebuffer2D.cpp
				src/sp/graphics/API/FramebufferDepth.cpp
				src/sp/graphics/GBuffer.cpp
				src/sp/graphics/Light.cpp
				src/sp/graphics/LightSetup.cpp
				src/sp/graphics/Model.cpp
				src/sp/graphics/PBRMaterial.cpp
				src/sp/graphics/postfx/PostEffects.cpp
				src/sp/graphics/postfx/PostEffectsPass.cpp
				src/sp/graphics/Renderer.cpp
				src/sp/graphics/shaders/ShaderManager.cpp
				src/sp/platform/opengl/GLError.cpp
				src/sp/platform/opengl/GLFramebuffer2D.cpp
				src/sp/platform/opengl/GLFramebufferDepth.cpp
				src/sp/platform/opengl/GLRenderer.cpp
				src/sp/platform/opengl/GLTexture2D.cpp
				src/sp/platform/opengl/GLTextureCube.cpp
				src/sp/platform/opengl/GLTextureDepth.cpp
				src/sp/graphics/ui/Button.cpp
				src/sp/graphics/ui/Panel.cpp
				src/sp/graphics/ui/Slider.cpp
				src/sp/graphics/ui/Widget.cpp
				src/sp/maths/Rectangle.cpp
				src/sp/platform/opengl/GLVertexBuffer.cpp
				src/sp/platform/opengl/GLContext.cpp
				src/sp/platform/opengl/GLShader.cpp
				src/sp/platform/opengl/GLShaderResource.cpp
				src/sp/platform/opengl/GLVertexArray.cpp
				src/sp/platform/opengl/GLShaderUniform.cpp
				src/sp/platform/opengl/GLIndexBuffer.cpp
                src/sp/platform/posix/PosixTimer.cpp
                src/sp/platform/posix/PosixApplication.cpp
                src/sp/platform/posix/PosixWindow.cpp
                src/sp/platform/posix/PosixLog.cpp
                src/sp/platform/posix/PosixInput.cpp
                src/sp/platform/posix/PosixMemoryManager.cpp
                src/sp/platform/posix/PosixFileSystem.cpp
				src/sp/app/Application.cpp
				src/sp/audio/Sound.cpp
				src/sp/audio/SoundManager.cpp
				src/sp/debug/DebugLayer.cpp
				src/sp/debug/DebugMenu.cpp
				src/sp/embedded/Embedded.cpp
				src/sp/entity/component/Component.cpp
				src/sp/entity/component/MeshComponent.cpp
				src/sp/entity/component/TransformComponent.cpp
				src/sp/entity/Entity.cpp
				src/sp/events/Event.cpp
				src/sp/events/KeyEvent.cpp
				src/sp/events/MouseEvent.cpp
				src/sp/graphics/BatchRenderer2D.cpp
				src/sp/graphics/API/BufferLayout.cpp
				src/sp/graphics/API/IndexBuffer.cpp
				src/sp/graphics/API/VertexArray.cpp
				src/sp/graphics/camera/Camera.cpp
				src/sp/graphics/camera/MayaCamera.cpp
				src/sp/graphics/Font.cpp
				src/sp/graphics/FontManager.cpp
				src/sp/graphics/ForwardRenderer.cpp
				src/sp/graphics/API/Framebuffer.cpp
				src/sp/graphics/Label.cpp
				src/sp/graphics/layers/Group.cpp
				src/sp/graphics/layers/Layer.cpp
				src/sp/graphics/layers/Layer2D.cpp
				src/sp/graphics/layers/Layer3D.cpp
				src/sp/graphics/Material.cpp
				src/sp/graphics/Mesh.cpp
				src/sp/graphics/MeshFactory.cpp
				src/sp/graphics/OBJModel.cpp
				src/sp/graphics/Scene.cpp
				src/sp/graphics/shaders/Shader.cpp
				src/sp/graphics/shaders/ShaderFactory.cpp
				src/sp/graphics/shaders/ShaderUniform.cpp
				src/sp/graphics/Sprite.cpp
				src/sp/graphics/API/Texture.cpp
				src/sp/graphics/TextureManager.cpp
				src/sp/app/Window.cpp
				src/sp/maths/AABB.cpp
				src/sp/maths/mat4.cpp
				src/sp/maths/Quaternion.cpp
				src/sp/maths/vec2.cpp
				src/sp/maths/vec3.cpp
				src/sp/maths/vec4.cpp
				src/sp/sp.cpp
				src/sp/String.cpp
				src/sp/system/Allocator.cpp
				src/sp/system/FileSystem.cpp
				src/sp/system/Memory.cpp
				src/sp/system/MemoryManager.cpp
				src/sp/system/System.cpp
				src/sp/system/VFS.cpp
				src/sp/utils/FileUtils.cpp
				src/sp/utils/ImageLoad.cpp)

IF (WIN32)
	set (SRC_LIST ${SRC_LIST}  	src/sp/platform/directx/DXVertexBuffer.cpp
								src/sp/platform/directx/DXContext.cpp
								src/sp/platform/directx/DXShader.cpp
								src/sp/platform/directx/DXVertexArray.cpp
								src/sp/platform/directx/DXFramebufferDepth.cpp
								src/sp/platform/directx/DXRenderer.cpp
								src/sp/platform/directx/DXShaderResource.cpp
								src/sp/platform/directx/DXShaderUniform.cpp
								src/sp/platform/directx/DXTexture2D.cpp
								src/sp/platform/directx/DXIndexBuffer.cpp
								src/sp/platform/directx/DXTextureCube.cpp
								src/sp/platform/directx/DXTextureDepth.cpp
								src/sp/platform/directx/DXFramebuffer2D.cpp
                                src/sp/platform/windows/Win32MemoryManager.cpp
                                src/sp/platform/windows/Win32Application.cpp
                                src/sp/platform/windows/Win32Log.cpp
                                src/sp/platform/windows/Win32Window.cpp
                                src/sp/platform/windows/Win32FileSystem.cpp
                                src/sp/platform/windows/Win32Input.cpp
                                src/sp/platform/windows/Win32Timer.cpp)
endif()


include_directories(src)
include_directories(../Dependencies/GLEW/include)
include_directories(../Dependencies/FreeImage/include)
include_directories(../Dependencies/glfw-3.1.2/include)
include_directories(../Dependencies/gorilla-audio/src)
include_directories(../Dependencies/FreeType)

add_definitions(-DSP_CORE_DLL -DFREEIMAGE_LIB -DOPJ_STATIC -DSP_DEBUG -DGLEW_STATIC -DSP_PLATFORM_UNIX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -w -Wl,--no-undefined")

add_library(Sparky-core SHARED ${SRC_LIST})

find_package(OpenGL)

target_link_libraries(Sparky-core ${OPENGL_gl_LIBRARY})
target_link_libraries(Sparky-core Box2D FreeImage FreeType gorilla-audio glfw)
target_link_libraries(Sparky-core "${CMAKE_CURRENT_SOURCE_DIR}/../Dependencies/GLEW/src/lib/libGLEW.a")

target_compile_features(Sparky-core PRIVATE cxx_nullptr)

set_target_properties(Sparky-core PROPERTIES PREFIX "")
