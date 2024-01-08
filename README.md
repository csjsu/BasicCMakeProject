# BasicCMakeProject
## 项目简介
本项目使用CMake组织\编译一个简单的C/CPP语言工程.
项目目录:
```
|-README.md
|-CMakeLists.txt    //CMkae指令文件
|-src               //源文件文件夹
|   |-main.c        //项目程序入口,main函数文件
|-components        //项目组件/各功能模块
|   |-cJSON         //cJSON功能模块,使用C语言实现的JSON解析等
|       |-cJSON.h
|       |-cJSON.c
|   |-Function1     //其他功能模块(测试使用)
|       |-Function1.h
|       |-Function1.c

```
## 使用方法
### 项目编译
打开终端,首先执行`cmake -B build`,在源码目录直接创建build文件并将编译文件写入其中;其次执行`cmake --build build`,编译整个项目,并将编译结果写入build文件夹中.
### 执行项目
使用`cd`指令到build文件夹:`cd ./build`,执行`./BasicCMakeProject`即可.


