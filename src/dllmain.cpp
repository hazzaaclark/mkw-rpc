#include <ctime>
#include <memory>
#include "pch.hpp"
#include "discord_rpc.hpp"
#include "discord_reg.hpp"
#pragma warning(disable::4996)

static DiscordRichPresence DiscordRPC;
char CurrentAreaName[128]{};

void init()
{
	Discord_Initialise("993591242724212800", NULL, 1);
	memset(&DiscordRPC, 0, sizeof(DiscordRPC));
}
