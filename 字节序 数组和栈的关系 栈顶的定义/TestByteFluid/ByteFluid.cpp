//
//  ByteFluid.cpp
//  TestByteFluid
//
//  Created by admindyn on 2017/12/23.
//  Copyright © 2017年 admindyn. All rights reserved.
//
#include <iostream>
#include "ByteFluid.hpp"

using namespace std;

union {
    uint32_t i;
    char a[4];
}u;

union {
    uint16_t i;
    char a[2];
}up;

ByteFluid::ByteFluid()
{
    
    u.a[0]=0x01;
    u.a[1]=0x00;
    u.a[2]=0x00;
    u.a[3]=0x93;
    
    up.a[0]=0x57;
    up.a[1]=0x7e;
    //8721
    /*
     计算机电路先处理低8位字节 效率比较高 因为计算机都是从低位开始的
     
     所以计算机的内部处理都是小端字节序
     
     但是人类 在数学上 写法 处理 加减乘除 都是大端字节序 对于一千零八十
     
     我们人类 都是先写 高8位一千 依次进行 阅读 处理 计算
     
     沿着内存的增长方向，先存低8位是的小端；先存高8位的是大端
     */
    // 小端字节序    0x2211 才是8721
    //我们这里 编程端 高8位 0x11 低8位 0x22 ->0x1122
    //我们人类读写数学 都是按照大端字节序
    // 在mac端 输出 发现原来程序端的 高8位 跑到了 高地址->0x2211 因此是小端字序 因此
    //我们并没有输出想要的0x1122 的值 而是 0x2211 的值 因此
    //字节序的读取 需要注意
    cout<<u.i<<endl;
    cout<<up.i<<endl;

    //但是在编程软件开发中  我们为变量 存取值 不用考虑 是什么 就是什么
    
    // 只是在传输时要考虑字节序
    //这里程序 将字节流 传给终端 让终端输出 因此要考虑
    
//     但是 如果我们cout 字符串却按照不会考虑字节序
//    啧啧啧啧
    
}


ByteFluid::~ByteFluid()
{


}
