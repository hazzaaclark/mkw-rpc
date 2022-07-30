#include <ctime>
#include <memory>
#include "pch.hpp"
#include "discord_rpc.hpp"
#include "discord_reg.hpp"
#include "courses.hpp"
#pragma warning(disable::4996)

namespace Discord
{
	static DiscordRichPresence DiscordRPC;
	char CurrentAreaName[128]{};

	void InitDiscord()
	{
		Discord_Initialise("993591242724212800", NULL, 1);
		memset(&DiscordRPC, 0, sizeof(DiscordRPC));
	}

	void Init()
	{

	}
}
