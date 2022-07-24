#pragma once
#include <map>

typedef enum : int32_t
{
	MODE_GRAND_PRIX,
	MODE_TIME_TRIALS,
	MODE_VS_RACE

} GameMode;

typedef struct
{
	uint32_t courseID;

} Settings;
