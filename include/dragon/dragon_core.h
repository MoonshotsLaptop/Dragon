#pragma once
#ifdef _cplusplus
extern "C" {
#endif

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx-creative.h>
#include <AL/efx-presets.h>
#include <AL/efx.h>

#ifndef DRAGON_BUS_SIZE
    #if INTPTR_MAX == INT32_MAX
        #define DRAGON_BUS_SIZE 32
    #elif INTPTR_MAX == INT64_MAX
        #define DRAGON_BUS_SIZE 64
    #else
        #error "Environment bus size unknown."
    #endif
#endif

#ifdef VK_MAKE_API_VERSION
	#define DRAGON_VERSION VK_MAKE_API_VERSION(1, 0, 1, 0)
#else
	#define DRAGON_VERSION VK_MAKE_VERSION(1, 0, 1)
#endif


#ifdef _cplusplus
	#include <vulkan/vulkan.hpp>
#else
	#include <vulkan/vulkan.h>
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <openxr/openxr.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	//define something for Windows (32-bit and 64-bit, this part is common)
	#ifndef APIENTRY
		#include <Windows.h>
	#endif
	#define DRAGON_PLAT_WINDOWS
	#ifdef _WIN64
		//define something for Windows (64-bit only)
		#define DRAGON_PLAT_WIN64
	#else
		//define something for Windows (32-bit only)
		#define DRAGON_PLAT_WIN32
	#endif
#elif __APPLE__
	#include <TargetConditionals.h>
	#import <Cocoa/Cocoa.h>
	#define DRAGON_PLAT_APPLE
	#if TARGET_IPHONE_SIMULATOR
		// iOS, tvOS, or watchOS Simulator
		#define DRAGON_PLAT_IOS
	#elif TARGET_OS_MACCATALYST
		// Mac's Catalyst (ports iOS API into Mac, like UIKit).
		#define DRAGON_PLAT_CATALYST
	#elif TARGET_OS_IPHONE
		// iOS, tvOS, or watchOS device
		#define DRAGON_PLAT_IOS
	#elif TARGET_OS_MAC
		// Other kinds of Apple platforms
		#define DRAGON_PLAT_MAC
	#else
		#error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	// Below __linux__ check should be enough to handle Android,
	// but something may be unique to Android.
	#define DRAGON_PLAT_ANDROID
#elif __linux__
	// linux
	#define DRAGON_PLAT_LINUX
#elif __unix__ // all unices not caught above
	// Unix
	#define DRAGON_PLAT_UNIX
#elif defined(_POSIX_VERSION)
	// POSIX
	#define DRAGON_PLAT_POSIX
#else
	#error "Unknown compiler"
#endif

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#if !defined(DRAGON_PLAT_WINDOWS)
	#include <pthread.h>
#endif
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>

typedef VkBool32 DgBool32;
#define DG_TRUE GLFW_TRUE
#define DG_FALSE GLFW_FALSE
typedef uint_fast64_t DgUInt64;
typedef int_fast64_t DgInt64;
typedef uint32_t DgUInt32;
typedef int32_t DgInt32;

#ifndef DRAGON_MESSAGE_ENABLED
	#define DRAGON_MESSAGE_ENABLED DG_TRUE
#endif
#ifndef DRAGON_SEND_DEPRECIATED
	#if DRAGON_MESSAGE_ENABLED
		#define DRAGON_SEND_DEPRECIATED DG_TRUE
	#else
		#define DRAGON_SEND_DEPRECIATED DG_FALSE
	#endif
#endif
#ifndef DRAGON_SEND_EXCEPTIONS
	#if DRAGON_MESSAGE_ENABLED
		#define DRAGON_SEND_EXCEPTIONS DG_TRUE
	#else
		#define DRAGON_SEND_EXCEPTIONS DG_FALSE
	#endif
#endif

#ifdef _cplusplus
	#if defined(_WIN32) && defined(DRAGON_BUILD_DLL)
		#define DGAPI extern "C" __declspec(dllexport)
	#elif defined(_WIN32) && defined(DRAGON_DLL)
		#define DGAPI extern "C" __declspec(dllimport)
	#elif defined(__GNUC__) && defined(DRAGON_BUILD_DLL)
		#define DGAPI extern "C" __attribute__((visibility("default")))
	#else
		#define DGAPI extern "C"
	#endif
#else
	#if defined(_WIN32) && defined(DRAGON_BUILD_DLL)
		#define DGAPI __declspec(dllexport)
	#elif defined(_WIN32) && defined(DRAGON_DLL)
		#define DGAPI __declspec(dllimport)
	#elif defined(__GNUC__) && defined(DRAGON_BUILD_DLL)
		#define DGAPI __attribute__((visibility("default")))
	#else
		#define DGAPI
	#endif
#endif

#define DRAGON_AUDIO_BUFFER_COUNT 16

#define DRAGON_AUDIO_ENABLED    0x00000000
#define DRAGON_GRAPHICS_ENABLED 0x00000002
#define DRAGON_PARTICLE_ENABLED 0x00000004
#define DRAGON_PHYSICS_ENABLED  0x00000005
#ifdef DRAGON_XR_ENABLED
#define DRAGON_XR_ENABLED       0x00000006
#endif
#define DRAGON_TERMINATE_ALL	0x00000007
#define DRAGON_TERMINATE_FEW	0x00000008

#ifdef _cplusplus
} // dragon/dragon_core.h
#endif
