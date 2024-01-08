# 指定CMake的最小版本
cmake_minimum_required(VERSION 3.15)

# 指定项目名称,最终编译的可执行文件将为此名称
PROJECT(BasicCMakeProject)

# CMake的函数,其作用是遍历文件夹中所有的.h文件
# FIND_INCLUDE_DIR -> 函数名称
# result -> 函数的第一个参数,文件遍历结果
# curdir -> 函数的第二个参数,文件遍历的路径
macro(FIND_INCLUDE_DIR result curdir)  
    file(GLOB_RECURSE children "${curdir}/*.h" )	
    message(STATUS "children= ${children}")								
    set(dirlist "")														
    foreach(child ${children})											
        string(REGEX REPLACE "(.*)/.*" "\\1" LIB_NAME ${child})			
        if(IS_DIRECTORY ${LIB_NAME})									
            LIST(APPEND dirlist ${LIB_NAME})					
        endif()															
    endforeach()														
    set(${result} ${dirlist})											
endmacro()																

# 调用FIND_INCLUDE_DIR函数,遍历的路径为:${PROJECT_SOURCE_DIR}/components即当前项目文件夹下的components文件夹及其子文件夹,
# 文件遍历的结果存贮在INCLUDE_DIR_LIST变量中
FIND_INCLUDE_DIR(INCLUDE_DIR_LIST ${PROJECT_SOURCE_DIR}/components)	

# 将下列文件添加到引用目录中,即所有#include "xxx.h"的文件从下面的文件中查找
INCLUDE_DIRECTORIES(
 ${INCLUDE_DIR_LIST}
)

# 查找所有匹配./components/*/*.c和./components/*/*.h规则的文件(例如./components/fun1/fun1.c符合规则./components/*/*.c,*为通配符)并抢七保存到变量SRC_DIR_LIST中
# GLOB_RECURSE意为全局资源,代表整个项目所有的文件
file(GLOB_RECURSE SRC_DIR_LIST "./components/*/*.c" "./components/*/*.h")

# 组合变量并取别名为 COMPONENTS_FILES
set(COMPONENTS_FILES 
${SRC_DIR_LIST}
)

# 设置编译flag,使用-g表示Debug模式,编译器不会优化你写的程序,编译出来的程序与你的代码具有一一对应的关系
set(CMAKE_C_FLAGS   "-g")

# 将${COMPONENTS_FILES}与src/main.c进行编译,并生成可执行文件
add_executable(BasicCMakeProject ${COMPONENTS_FILES} src/main.c )

