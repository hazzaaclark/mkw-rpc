#include <ctime>
#include <memory>
#include "pch.hpp"
#include "discord_rpc.hpp"
#pragma warning(disable::4996)

static DiscordRichPresence DiscordRPC;
char CurrentAreaName[128]{};

static void init()
{
	Discord_Initialise("", NULL, 1, NULL);
}
