#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#endif
