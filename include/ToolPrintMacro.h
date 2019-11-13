#ifndef __TOOL_PRINT_MACRO_H__
#define __TOOL_PRINT_MACRO_H__



/*
Sends a string literal to the standard output without terminating the compilation. 
#pragma message( messagestring )

The messagestring parameter can be a macro that expands to a string literal, and you can concatenate such macros with string literals in any combination. 

If you use a predefined macro in the message pragma, the macro should return a string, else you will have to convert the output of the macro to a string. 

简单的说，就是 messagestring 必须是使用引号 "" 引起来的字符串。
在输出时，引号 "" 不会输出。
*/

#define TOOL_PRINT_MACRO_HELPER(x)   #x                          // "x"
#define TOOL_PRINT_MACRO(x)   #x"="MY_PRINT_MACRO_HELPER(x)      // "x""="MY_PRINT_MACRO_HELPER(abc) --> "x""=""abc"



// #define MY_MACRO_TEST "my macro test"
// #pragma message(MY_MACRO_TEST)      // #pragma message("my macro test")

// #define MY_PI 3.1415926
// #define MY_MAX(a,b) (a)>(b) ? (a) :(b)



// #pragma message(TOOL_PRINT_MACRO_HELPER(MY_MACRO_TEST))          // #pragma message("MY_MACRO_TEST") 
// #pragma message(TOOL_PRINT_MACRO_HELPER(MY_PI))                  // #pragma message("MY_PI") 
// #pragma message(TOOL_PRINT_MACRO_HELPER(MY_MAX(a,b)))            // #pragma message("MY_MAX(a,b)") 

// #pragma message(TOOL_PRINT_MACRO(MY_MACRO_TEST))                 // #pragma message("MY_MACRO_TEST""=""\"my macro test\"")
// #pragma message(TOOL_PRINT_MACRO(MY_PI))                         // #pragma message("MY_PI""=""3.1415926")
// #pragma message(TOOL_PRINT_MACRO(MY_MAX(a,b)))                   // #pragma message("MY_MAX(a,b)""=""(a)>(b) ? (a) :(b)")



// #define TOOL_ERROR_PRINT_MACRO(x)   #x"="x

// #pragma message(TOOL_ERROR_PRINT_MACRO(MY_MACRO_TEST))           // #pragma message("MY_MACRO_TEST""=""my macro test") 
// #pragma message(TOOL_ERROR_PRINT_MACRO(MY_PI))                   // #pragma message("MY_PI""="3.1415926)                    // warning C4081: 应输入“)”；找到“常量”
// #pragma message(TOOL_ERROR_PRINT_MACRO(MY_MAX(a,b)))             // #pragma message("MY_MAX(a,b)""="(a)>(b) ? (a) :(b))     // warning C4081: 应输入“)”；找到“(”    



#endif /*__TOOL_PRINT_MACRO_H__*/