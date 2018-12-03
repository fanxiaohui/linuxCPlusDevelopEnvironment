
MESSAGE(STATUS "Project-LIB: LIB")

SET(LIBHELLO_SRC hello.cpp)




#构建动态库和静态库命令
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})

ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})

#对应上面的ADD_LIBRARY设置 对应的动态库 静态库的输出目录

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libsdir)

#设置共享库的头文件安装路径
#但是这里的设置 生效查看 
#需要在执行cmake make 后 再执行make install 才会看到这里的设置生效

INSTALL(FILES hello.h DESTINATION ${PROJECT_BINARY_DIR}/include/hello)

#可以用来设置输出的名称，对于动态库，还可以用来指定动态库版本和 API 版本
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT
1)

SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")

# cmake 在构建一个新的 target 时，会尝试清理掉其他使用这个名字的库，因为，在构建 libhello.a 时，
# 就会清理掉 libhello.so，下面的属性设置解决此问题
SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 把libhello_static.a 修改为libhello.a
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")


GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)

MESSAGE(STATUS "This is the hello_static OUTPUT_NAME:" ${OUTPUT_VALUE})




