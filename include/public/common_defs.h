#pragma once
#ifndef C_CPP_PLAYGROUND_COMMON_DEFS_H
#define C_CPP_PLAYGROUND_COMMON_DEFS_H

#if defined(WIN32) || defined(_WIN32)
#define FUNC_EXPORT(SomeType) __declspec(dllexport) SomeType
#else
#define FUNC_EXPORT(SomeType) SomeType __attribute__((visibility("default")))
#endif
#define FUNC_LOCAL(SomeType) static SomeType

#endif
