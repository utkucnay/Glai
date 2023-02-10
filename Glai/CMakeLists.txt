

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

	src/Renderer/Sprite.h

	src/Asset/SpriteAsset.h
)

add_library(Engine2D ${src})

target_include_directories(Engine2D PUBLIC src)
target_precompile_headers(Engine2D PUBLIC src/EngineCore.h)

add_subdirectory(vendor)

target_link_libraries(Engine2D PUBLIC EnTT::EnTT)
target_link_libraries(Engine2D PUBLIC GLAD)
target_link_libraries(Engine2D PUBLIC glfw)
target_link_libraries(Engine2D PUBLIC spdlog)
target_link_libraries(Engine2D PUBLIC corona)

target_include_directories(Engine2D PUBLIC src)