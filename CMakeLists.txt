cmake_minimum_required(VERSION 3.15)

set()


project(imitation_game)

# 动态链接库目录
link_directories(${PROJECT_SOURCE_DIR}/SFML-2.6.1/bin)

# 动态链接库头文件
include_directories(${PROJECT_SOURCE_DIR}/SFML-2.6.1/include)
include_directories(${PROJECT_SOURCE_DIR}/)

# 源文件
file(GLOB src ${PROJECT_SOURCE_DIR}/*.cpp)

# 设置输出可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(app ${src})
target_link_libraries(app openal32.dll)
target_link_libraries(app sfml-graphics-2.dll)
target_link_libraries(app sfml-graphics-d-2.dll)
target_link_libraries(app sfml-system-2.dll)
target_link_libraries(app sfml-system-d-2.dll)
target_link_libraries(app sfml-window-2.dll)
target_link_libraries(app sfml-window-d-2.dll)