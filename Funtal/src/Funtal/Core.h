//
// Created by 陈奕锟 on 2022/10/23.
//

#ifndef FUNTAL_CORE_H
#define FUNTAL_CORE_H

#endif //FUNTAL_CORE_H
#pragma once

#ifdef PROJ_DEBUG
    #define FT_ENABLE_ASSERTS
#endif

#ifdef FT_PLATFORM_MACOS

    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __attribute(( visibility("default") ))
    #else
        #define FUNTAL_API __attribute(( visibility("default") ))
    #endif

#elif FT_PLATFORM_WINDOWS
    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __declspec(dllimport)
    #else
        #define FUNTAL_API __declspec(dllexport)
    #endif

#elif FT_PLATFORM_LINUX
    #ifdef FT_BUILD_DLL
        #define FUNTAL_API __attribute(( visibility("default") ))
    #else
        #define FUNTAL_API __attribute(( visibility("default") ))
    #endif
#else
    #error Funtal UNSUPPORTED Platform, sorry!
#endif

#ifdef FT_DEBUG
    #define FT_ENABLE_ASSERTS
#endif

#ifdef FT_ENABLE_ASSERTS
    #define FT_ASSERT(x, ...) { if( !(x) ) { FT_ERROR( "Assertion Failed: {0}", __VA_ARGS__ );  __debugbreak(); } }
    #define FT_CORE_ASSERT(x, ...) { if( !(x) ) { FT_ERROR( "Assertion Failed: {0}", __VA_ARGS__ );  __debugbreak(); } }
#else
    #define FT_ASSERT(x, ...)
    #define FT_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define FT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// * 用于实现 MSVC 的 __debugbreak()
#if defined(__APPLE__) && defined(__aarch64__)
#define __debugbreak() __asm__ __volatile__(
    "   mov    x0, %x0;
" /* pid                */
    "   mov    x1, #0x11;
" /* SIGSTOP            */
    "   mov    x16, #0x25;
" /* syscall 37 = kill  */
    "   svc    #0x80
" /* software interrupt */
    "   mov    x0, x0
" /* nop                */
    ::  "r"(getpid())
    :   "x0", "x1", "x16", "memory")
#elif defined(__APPLE__) && defined(__arm__)
#define __debugbreak() __asm__ __volatile__(
    "   mov    r0, %0;
" /* pid                */
    "   mov    r1, #0x11;
" /* SIGSTOP            */
    "   mov    r12, #0x25;
" /* syscall 37 = kill  */
    "   svc    #0x80
" /* software interrupt */
    "   mov    r0, r0
" /* nop                */
    ::  "r"(getpid())
    :   "r0", "r1", "r12", "memory")
#elif defined(__APPLE__) && ( defined(__i386__) || defined(__x86_64__) )
#define __debugbreak() __asm__ __volatile__("int $3; mov %eax, %eax")
#endif
