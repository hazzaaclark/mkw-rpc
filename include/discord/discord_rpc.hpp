#pragma once
#include <stdint.h>

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

#ifdef  __cplusplus
extern "C"
{

}
#endif //  __cplusplus


typedef struct DiscordRichPresence
{
	const char* STATE;
	const char* DETAILS;
	const char* LARGE_IMAGE_KEY;
	const char* LARGE_IMAGE_TEXT;
	const char* SMAll_IMAGE_KEY;
	const char* SMALL_IMAGE_TEXT;
	uint8_t INSTANCE;
	uint64_t START_TIME;
	uint64_t END_TIME;

} DiscordRichPresence;

typedef struct DiscordUser
{
	const char* USERID;
	const char* USERNAME;
} DiscordUser;

typedef struct DiscordEventHandlers
{
	void (*ready)(const DiscordUser* request);
	void (*disconnected)(int errorCode, const char* message);
} DiscordEventHandlers;

DISCORD_EXPORT void Discord_Initialise(const char* APPID, DiscordEventHandlers* EVENTHANDLERS, int AUTOREG);
DISCORD_EXPORT void Discord_Shutdown(void);

#ifdef __cplusplus 
#endif 



