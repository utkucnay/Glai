
file(GLOB_RECURSE src src/*.cpp src/*.h)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/zlib-1.1.4)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/libpng-1.2.1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/jpeg-6b)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/libungif-4.1.0)

add_library(corona STATIC
	${src}
)

target_include_directories(corona PUBLIC src)