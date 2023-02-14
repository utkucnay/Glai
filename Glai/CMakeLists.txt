

file( GLOB SRCS src/*.cpp src/*.h)

set(src
	src/EngineCore.h
	src/Engine.h
	src/Frame.h
	src/Engine.cpp
	src/Frame.cpp
	src/Window.h

	src/Thread/Job.h
	src/Thread/JobSystem.h
	src/Thread/ThreadSystem.h
	src/Thread/ThreadPool.h
	src/Thread/ThreadPool.cpp

	src/ECS/GameSystem.h
	src/ECS/Systembase.h

	src/Renderer/Texture2D.h
	src/Renderer/Vertex.h
	src/Renderer/Sprite.h
	src/Renderer/Sprite.cpp
	src/Renderer/Camera.h

	src/Renderer/Shader/Shader.h
	src/Renderer/Shader/Shader.cpp
	src/Renderer/Shader/Shaders/VertexShader.glsl
	src/Renderer/Shader/Shaders/InstancedVertexShader.glsl
	src/Renderer/Shader/Shaders/FragmentShader.glsl
	src/Renderer/Shader/Shaders/InstancedFragmentShader.glsl

	src/Renderer/Material/Material.h

	src/Asset/Texture2DAsset.h
)

add_library(Engine2D ${src})

target_include_directories(Engine2D PUBLIC src)
target_precompile_headers(Engine2D PUBLIC src/EngineCore.h)

add_subdirectory(vendor)

target_link_libraries(Engine2D PUBLIC EnTT::EnTT)
target_link_libraries(Engine2D PUBLIC GLAD)
target_link_libraries(Engine2D PUBLIC glfw)
target_link_libraries(Engine2D PUBLIC glm)
target_link_libraries(Engine2D PUBLIC spdlog)
target_link_libraries(Engine2D PUBLIC corona)

target_include_directories(Engine2D PUBLIC src)

source_group("Shader" 
	FILES 	
	src/Renderer/Shader/Shaders/VertexShader.glsl
	src/Renderer/Shader/Shaders/InstancedFragmentShader.glsl
	src/Renderer/Shader/Shaders/InstancedVertexShader.glsl
	src/Renderer/Shader/Shaders/FragmentShader.glsl)