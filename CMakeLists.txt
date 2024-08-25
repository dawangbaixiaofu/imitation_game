cmake_minimum_required(VERSION 3.15)



project(imitation_game)

# 动态链接库目录
# link_directories(${PROJECT_SOURCE_DIR}/SFML-2.6.1/bin)

# 动态库文件 RELATIVE ${PROJECT_SOURCE_DIR}/bin
file(GLOB sfml_dll ${PROJECT_SOURCE_DIR}/bin/*.dll)

# 动态链接库头文件
include_directories(${PROJECT_SOURCE_DIR}/SFML-2.6.1/include)
# 自己写的代码头文件
include_directories(${PROJECT_SOURCE_DIR}/)

# 源文件
file(GLOB src ${PROJECT_SOURCE_DIR}/*.cpp)

# 设置输出可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(app ${src})
target_link_libraries(app ${sfml_dll})
