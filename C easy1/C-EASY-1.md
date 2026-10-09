# C-EASY-1

## part1

1. GCC是一套编辑语言编译器，将代码翻译为机器码

   MinGW是Windows系统下的一个工具集，把 GCC 编译器移植到了 Windows 上。因为 Windows 原生不支持 GCC，所以需要通过 MinGW 来在 Windows 上使用 GCC 来编译代码。

2.  c_cpp_properties.json：用于配置 VS Code 的 C/C++ 智能感知，告诉编辑器去哪里找头文件和编译器路径。

    tasks.json：用于配置编译任务，告诉 VS Code 如何调用 GCC 编译器来编译代码。

    launch.json：用于配置调试任务，告诉 VS Code 用哪个调试器、启动哪个程序、以及调试时的参数。

3. 在编辑器内下载 C 语言的插件作用：因为 VS Code 本质上只是一个文本编辑器，不是专门写 IDE。下载 C/C++ 插件后，编辑器才能拥有代码高亮、智能补全、语法检查、跳转定义等功能，并配合三个 .json 文件实现编译和调试。

**注释**

```c
{
    // 使用 IntelliSense 了解相关属性。
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe - 生成和调试活动文件", // 该调试任务的名字，启动调试时会在待选列表中显示
            "type": "cppdbg", // 配置类型，cppdbg 表示使用 C/C++ 调试器
            "request": "launch", // 请求配置类型，launch 表示启动程序进行调试
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe", // 要调试的可执行文件的完整路径
            "args": [], // 程序调试时传递给程序的命令行参数，这里为空
            "stopAtEntry": false, // 是否在程序入口处暂停（false 表示直接运行，不暂停）
            "cwd": "${workspaceFolder}", // 调试程序时的工作目录，这里指当前工作区文件夹
            "environment": [], // 程序调试时添加到环境变量中的设置，这里为空
            "externalConsole": false, // 是否使用外置终端（false 表示使用 VS Code 内置终端，true 表示弹出外部黑框）
            "MIMode": "gdb", // 指定连接的调试器类型，这里使用 gdb
            "miDebuggerPath": "C:\\mingw64\\bin\\gdb.exe", // 指定调试器 gdb.exe 的绝对路径
            "setupCommands": [ // 调试器启动时需要执行的额外命令
                {
                    "description": "为 gdb 启用整齐打印", // 命令描述
                    "text": "-enable-pretty-printing", // 实际传递给调试器的文本命令
                    "ignoreFailures": true // 如果执行该命令失败，是否忽略错误继续调试
                }
            ],
            "preLaunchTask": "C/C++: gcc.exe build active file" // 调试前的预执行任务，这里的值是 tasks.json 文件中对应的编译任务，也就是调试前需要先编译
        }
    ]
}
```



![内置终端](D:\glimmer\images\内置终端.png)

![外置终端](D:\glimmer\images\外置终端.png)

## part2

1.变量类型决定了计算机在内存中为该变量分配多少字节的空间，以及如何解释这些存储的二进制数据
。选择合适的类型可以节省内存，并确保程序能正确处理数据，避免数据截断或精度丢失

存储年龄18应该选择整数类型 int

存储单词apple不能用char 类型。char 只能存一个字符。存储字符串需要使用字符数组 char str[]

char fruit[] = "apple"



2.起始下标从 0 开始的

访问超出其有效范围会导致数组越界

问题：程序会读取到该数组之外的内存区域或修改其他变量的内存数据。这会导致程序崩溃产生不可预知的错误结果，甚至可能被恶意利用来执行危险代码

常见且危险：C语言不自动检查数组边界，编译器不会报错，指针操作又非常灵活，因此极其容易犯错，且这类错误往往难以排查



3.结构：用于让一段代码在满足特定条件时重复执行，直到条件不再满足为止

 for 循环三部分的作用：  ·

 初始化：在循环开始前执行一次，通常用于定义和初始化循环计数变量

 条件判断：每次循环开始前检查，如果为真则执行循环体，为假则结束循环

迭代部分：每次循环体执行结束后执行，通常用于更新循环计数变量

while 和 do...while 的区别：while 循环先判断条件，再执行循环体。条件不满足时，循环体可能一次都不执行。do...while 循环先执行一次循环体，再判断条件，无论条件是否满足，循环体至少执行一次。

```c
#include <stdio.h>
int main(){
    int sum = 0;
    for(int i = 1; i <= 10; i++) {
        sum += i;
    }
    return 0;
}
```

```c
#include <stdio.h>
int main(){
    int sum = 0;
    int i = 1;
    while(i <= 10) {
        sum += i;
        i++;
    }
    return 0;
}
```

4. 逻辑表达式与算术表达式的本质区别

   算术表达式的运算对象是数值,结果也是数值

   逻辑表达式的运算对象是布尔值,结果也是布尔值

   逻辑运算符的含义

   && (与):当且仅当两边都为真时,结果才为真

   || (或):只要有一边为真,结果即为真

    ! (非):取反,真变假,假变真

   

   预测代码

```c
#include <stdio.h>
  int main() {
      int a = 20;
      int b = 75;
      if (a > 18 && b >= 60) {
          printf("条件成立\n");
      } else {
          printf("条件不成立\n");
      }
      return 0;
  }
```

预测: 输出条件成立

a>18 为真,b>= 60 也为真,结果为真

## part3

a,b没有交换

a,b是值的传递，实参的值复制给形参，原值没变。

应该用指针

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10, b = 20;
    swap(&a, &b);
    return 0;
}
```

