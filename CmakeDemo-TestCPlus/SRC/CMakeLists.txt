
MESSAGE(STATUS "Project-SRC: SRC")

ADD_EXECUTABLE(hellobin main.cpp)

#对应上面ADD_EXECUTABLE 指定 生成可执行文件的输出目录
#这里才是指定的最终可执行文件的输出目录
#但是这里有一个相对路径${PROJECT_BINARY_DIR} 
#这里的值是根据我们在CMake 软件configure 然后 generate 输出makefile文件后
#我们然后到指定的外部构建路径 make 命令
#因此这里的${PROJECT_BINARY_DIR} 相对make 命令执行的目录的

#指定目标二进制的位置
#无论前面的ADD_SUBDIRECTORY 指令(是否指定编译输出目录)，
#我们都可以通过 SET 指令重新定义 EXECUTABLE_OUTPUT_PATH 
#和 LIBRARY_OUTPUT_PATH 变量来指定最终的目标二进制的位置
#(这里指定的位置只会输出最终生成的 hello 或者最终的共享库，不包含编译生成的中间文件)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bindir)


MESSAGE(STATUS "EXE-Name: hellobin")