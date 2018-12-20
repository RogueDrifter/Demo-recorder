//Demo recorder by RogueDrifter 2018/20/12
//Plug'n Play version

#if defined RDemo_included_
	#endinput
#endif

#define RDemo_included_

#if !defined FILTERSCRIPT

#include <a_samp>

#if defined RDemo_OnPlayerConnect
	forward RDemo_OnPlayerConnect(playerid);
#endif

#if defined RDemo_OnPlayerDisconnect
	forward RDemo_OnPlayerDisconnect(playerid, reason);
#endif

#if defined RDemo_OnPlayerStateChange
	forward RDemo_OnPlayerStateChange(playerid, newstate, oldstate);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	StopRecordingPlayerData(playerid);
	#if defined RDemo_OnPlayerDisconnect
		return RDemo_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}

public OnPlayerConnect(playerid)
{
	new RD_PName[MAX_PLAYER_NAME +1];
	GetPlayerName(playerid, RD_PName, sizeof(RD_PName));

	new RD_FootString[MAX_PLAYER_NAME +20];
	format(RD_FootString, sizeof(RD_FootString), "DEMO_%s_FOOT", RD_PName);
	StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE_ONFOOT, RD_FootString);
	#if defined RDemo_OnPlayerConnect
		return RDemo_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	new RD_PName[MAX_PLAYER_NAME +1];
	GetPlayerName(playerid, RD_PName, sizeof(RD_PName));
	new RD_TempString[MAX_PLAYER_NAME +20];

	if(oldstate == PLAYER_STATE_ONFOOT && (newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER) )
	{
		StopRecordingPlayerData(playerid);
		format(RD_TempString, sizeof(RD_TempString), "DEMO_%s_VEHICLE", RD_PName);
		StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE_DRIVER, RD_TempString);
	}
	else if(newstate == PLAYER_STATE_ONFOOT && (oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER) )
	{
		StopRecordingPlayerData(playerid);
		format(RD_TempString, sizeof(RD_TempString), "DEMO_%s_FOOT", RD_PName);
		StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE_ONFOOT, RD_TempString);
	}
	#if defined RDemo_OnPlayerStateChange
		return RDemo_OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
  #undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect RDemo_OnPlayerConnect

#if defined _ALS_OnPlayerDisconnect
  #undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect RDemo_OnPlayerDisconnect

#if defined _ALS_OnPlayerStateChange
  #undef OnPlayerStateChange
#else
	#define _ALS_OnPlayerStateChange
#endif

#define OnPlayerStateChange RDemo_OnPlayerStateChange

#endif