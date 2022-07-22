#pragma once

#if defined(DISCORD_LIB)
#if defined(_WIN32)
#if defined(DISCORD_SDK)
#define DISCORD_EXPORT __declspec(dllexport)
#else 
#define DISCORD_EXPORT __declspec(dllimport)
#endif

#else 
#define DISCORD_EXPORT __attribute__((visibility("default")))
#endif
#else
#define DISCORD_EXPORT
#endif