#include "PlayerInstance.h"

PlayerInstance::PlayerInstance(Aplayer_cpp * player)
{
	pPlayer = player;
}

PlayerInstance::~PlayerInstance()
{
}

PlayerStatus PlayerInstance::GetPlayerStatus()
{
	return playerStatus;
}

