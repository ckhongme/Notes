完成[[CMake]]的所有操作

### 内置变量

```bash
PROJECT_SOURCE_DIR   # 工程的根目录
PROJECT_BINARY_DIR   # 运行cmake命令的目录，通常为${PROJECT_SOURCE_DIR}/build
PROJECT_NAME         # 返回通过 project 命令定义的项目名称

CMAKE_CURRENT_SOURCE_DIR   # 当前 CMakeLists.txt 所在的路径
CMAKE_CURRENT_BINARY_DIR   # target 编译目录
CMAKE_CURRENT_LIST_DIR     # CMakeLists.txt 的完整路径

EXECUTABLE_OUTPUT_PATH   # 重新定义目标二进制可执行文件的存放位置
LIBRARY_OUTPUT_PATH      # 重新定义目标链接库文件的存放位置
```

### 格式规则
```bash
cmake_minimum_required(VERSION 3.4.1)        # 指定最低版本 
project(demo)                                # 设置项目名称为demo

# 指定编译包含的源文件: 收集c/c++文件并赋值给变量SRC_LIST 
file(GLOB SRC_LIST "./*.cpp" "./*.h") 

# 指定头文件目录 
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR} 
	${CMAKE_CURRENT_BINARY_DIR} 
	${CMAKE_CURRENT_SOURCE_DIR}/include 
) 

# 指定生成库文件的目录 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

# 设置变量FLAG为ON状态
set(FLAG ON) 

# 生成 libdemo动态库（默认是静态库，通过 SHARED 指定为动态库） 
add_library( 
	${OUT_NAME} SHARED 
	${SRC_LIST}
)

# 设置引用库地址的变量
SET(3RD_PARTY_DIR "" CACHE PATH "Set to base lib install path")
SET(OSG_DIR "" CACHE PATH "Set to base OpenSceneGraph install path")
# 判断地址是否为空
IF("${3RD_PARTY_DIR}" STREQUAL "" OR "${OSG_DIR}" STREQUAL "")
    message(FATAL_ERROR "3RD_PARTY_DIR and OSG_DIR need to set!!!")
ENDIF("${3RD_PARTY_DIR}" STREQUAL "")

include_directories("${OSG_DIR}/include")
include_directories("${3RD_PARTY_DIR}/include")
link_directories("${OSG_DIR}/lib")
link_directories("${3RD_PARTY_DIR}/lib")

# 增加要编译的子目录app
add_subdirectory(app);
```

每个子目录都要有自己的CMakeList.txt
```bash
# 链接库 ${log-lib}
target_link_libraries(
        ${PROJECT_NAME}
        ${log-lib}
)

# 链接多个库
IF(WIN32)
    target_link_libraries(
            ${PROJECT_NAME}
            opengl32
            glew32
    )
ELSEIF(UNIX)
    target_link_libraries(
            ${PROJECT_NAME}
            GL
            GLEW
    )
ENDIF()

# 添加编译的对象
add_executable(
        ${PROJECT_NAME}
        main.cpp
)
```