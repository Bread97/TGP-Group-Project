#include "Vector.h"

class Aplayer_cpp;

enum PlayerStatus
{
	Alive = 1,
	Dead = 0
};

#pragma once
class PlayerInstance
{
public:
	PlayerInstance(Aplayer_cpp* player);
	~PlayerInstance();

	/// <summary> Respawns the player at the target position, with a specified delay. </summary>
	/// <param name="location"> Target location to respawn player at </param>
	/// <param name="respawnTime"> Total amount of time before the player is respawned </summary>
	void Respawn(FVector location, float respawnTime);

	/// <summary> Not intended to be modified, just reads the value of the player </summary>
	PlayerStatus GetPlayerStatus();

private:
	/// <summary> Assigned in constructor, a player 
	Aplayer_cpp* pPlayer;
	PlayerStatus playerStatus;
};

