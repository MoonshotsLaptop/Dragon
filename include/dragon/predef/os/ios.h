#pragma once
/*
Copyright Franz Detro 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include "../version_number.h"
#include "../make.h"

/* tag::reference[]
= `BOOST_OS_IOS`

http://en.wikipedia.org/wiki/iOS[iOS] operating system.

[options="header"]
|===
| {predef_symbol} | {predef_version}

| `+__APPLE__+` | {predef_detection}
| `+__MACH__+` | {predef_detection}
| `+__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__+` | {predef_detection}

| `+__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__+` | +__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__+*1000
|===
*/ // end::reference[]

#define BOOST_OS_IOS BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__APPLE__) && defined(__MACH__) && \
    defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) \
    )
#   undef BOOST_OS_IOS
#   define BOOST_OS_IOS (__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__*1000)
#endif

#if BOOST_OS_IOS
#   define BOOST_OS_IOS_AVAILABLE
    #include "../detail/os_detected.h"
#endif