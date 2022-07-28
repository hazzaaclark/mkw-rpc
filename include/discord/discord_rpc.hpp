#pragma once
#include <Windows.h>
#include <stdint.h>

/** DEFINES **/

#if defined(DISCORD_SDK)
#define DLLEXPORT __declspec(dllexport)
#else 
#define DISCORD_EXPORT __declspec(dllimport)
#define DISCORD_EXPORT
#endif

#define DISCORD_REPLY_NO 0
#define DISCORD_REPLY_YES 1
#define DISCORD_REPLY_IGNORE 2

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

/** DLL DEPENDANCIES **/

DISCORD_EXPORT void Discord_Initialise(const char* APPID, DiscordEventHandlers* EVENTHANDLERS, int AUTOREG);
DISCORD_EXPORT void Discord_Shutdown(void);
DISCORD_EXPORT void Discord_Update(const DiscordRichPresence* RPC);
DISCORD_EXPORT void Discord_Clear(void);
DISCORD_EXPORT void Discord_Reponse(const char* USERID, int REPLY);

#ifdef __cplusplus 
#endif 
