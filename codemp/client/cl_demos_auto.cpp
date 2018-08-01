// Copyright (C) 2015 ent (entdark)
//
// cl_demos_auto.cpp - autorecording demos routine
//
// credits: 
// - teh aka dumbledore aka teh_1337: autorecording demos
// - CaNaBiS: formatting with %

#include "client.h"
#include "cl_demos.h"

char *demoAutoFormat(const char* name) {	
	const	char *format;
	qboolean haveTag = qfalse;
	char	outBuf[512];
	int		outIndex = 0;
	int		outLeft = sizeof(outBuf) - 1;
	
	int t = 0;
	char timeStamps[MAX_QPATH] = "";
	qtime_t ct;

<<<<<<< HEAD
<<<<<<< HEAD
	char playerName[MAX_QPATH], *mapName = COM_SkipPath(Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO]), "mapname"));
	Q_strncpyz(playerName, Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_PLAYERS+cl.snap.ps.clientNum]), "n"), sizeof(playerName));
<<<<<<< HEAD
	Q_StripColor(playerName, cls.uag.newColors);
=======
	char playerName[MAX_QPATH], serverName[MAX_QPATH];
	char *mapName = COM_SkipPath(Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO]), "mapname"));
	Q_strncpyz(playerName, Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_PLAYERS+cl.snap.ps.clientNum]), "n"), sizeof(playerName));
	Q_StripColor(playerName, cls.uag.newColors);
	Q_StripColor(serverName, COM_SkipPath(Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO]), "sv_hostname")));
>>>>>>> parent of 9ffa3a2... Fixed compiling and changed default format
=======
	char playerName[MAX_QPATH], *mapName = COM_SkipPath(Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO]), "mapname"));
	Q_strncpyz(playerName, Info_ValueForKey((cl.gameState.stringData + cl.gameState.stringOffsets[CS_PLAYERS+cl.snap.ps.clientNum]), "n"), sizeof(playerName));
	Q_StripColor(playerName, cls.uag.newColors);
>>>>>>> parent of 148b81a... Added new demo tokens from strftime (reference: pre C-99 rows from http://cplusplus.com/reference/ctime/strftime/). Renamed some tokens that conflicted with the new ones: date -> D, map -> N, player name -> P (demo name and timestamp are untouched). Also added current server, token: s
=======
	if (cls.uag.newColors)
		Q_StripColorUAG(playerName);
	else
		Q_StripColor(playerName);
>>>>>>> parent of 69606c3... Merge branch 'master' of https://github.com/entdark/jaMME
	Com_RealTime(&ct);
	
	format = cl_autoDemoFormat->string;
	if (!format || !format[0]) {
		if (!name || !name[0]) {
			format = "%t";
		} else {
			format = "%n_%t";
		}
	}

	while (*format && outLeft  > 0) {
		if (haveTag) {
			char ch = *format++;
			haveTag = qfalse;
			switch (ch) {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of eee1a36... Restored defaults for more important tokens (map, player name and date), and changed a few strftime tokens instead. Since the strftime reference is now wrong, I documented all new tokens for readme
			// let strftime handle its tokens, and ignore those with illegal characters
			case 'a':   case 'A':   case 'b':   case 'B': /*case 'c':*/ case 'd':
			case 'H':   case 'I':   case 'm':   case 'M':   case 'p':   case 'S':
			case 'u':   case 'w': /*case 'x':   case 'X':*/ case 'y':   case 'Y':
			case 'Z':
				// we can't just cast the struct because of undefined compiler behaviour
				tt.tm_sec = ct.tm_sec; tt.tm_min = ct.tm_min; tt.tm_hour = ct.tm_hour;
				tt.tm_mday = ct.tm_mday; tt.tm_mon = ct.tm_mon; tt.tm_year = ct.tm_year;
				tt.tm_wday = ct.tm_wday; tt.tm_yday = ct.tm_yday; tt.tm_isdst = ct.tm_isdst;
				strftime( outBuf + outIndex, outLeft, va( "%%%c", ch ), &tt );
				outIndex += strlen( outBuf + outIndex );
				break;
			case 'D':		//date
<<<<<<< HEAD
=======
			case 'd':		//date
>>>>>>> parent of b3ed3ba... Merge pull request #12 from Avygeil/demotokens
=======
>>>>>>> parent of eee1a36... Restored defaults for more important tokens (map, player name and date), and changed a few strftime tokens instead. Since the strftime reference is now wrong, I documented all new tokens for readme
=======
			case 'd':		//date
>>>>>>> parent of 148b81a... Added new demo tokens from strftime (reference: pre C-99 rows from http://cplusplus.com/reference/ctime/strftime/). Renamed some tokens that conflicted with the new ones: date -> D, map -> N, player name -> P (demo name and timestamp are untouched). Also added current server, token: s
				Com_sprintf( outBuf + outIndex, outLeft, "%d-%02d-%02d-%02d%02d%02d",
								1900+ct.tm_year, ct.tm_mon+1,ct.tm_mday,
								ct.tm_hour, ct.tm_min, ct.tm_sec);
				outIndex += strlen( outBuf + outIndex );
				break;
			case 'm':		//map
				Com_sprintf( outBuf + outIndex, outLeft, mapName);
				outIndex += strlen( outBuf + outIndex );
				break;
			case 'n':		//custom demo name
				Com_sprintf( outBuf + outIndex, outLeft, name);
				outIndex += strlen( outBuf + outIndex );
				break;
			case 'p':		//current player name
				Com_sprintf( outBuf + outIndex, outLeft, playerName);
				outIndex += strlen( outBuf + outIndex );
				break;
<<<<<<< HEAD
<<<<<<< HEAD
=======
			case 's':
				Com_sprintf( outBuf + outIndex, outLeft, serverName );
				outIndex += strlen( outBuf + outIndex );
				break;
>>>>>>> parent of 9ffa3a2... Fixed compiling and changed default format
=======
>>>>>>> parent of 148b81a... Added new demo tokens from strftime (reference: pre C-99 rows from http://cplusplus.com/reference/ctime/strftime/). Renamed some tokens that conflicted with the new ones: date -> D, map -> N, player name -> P (demo name and timestamp are untouched). Also added current server, token: s
			case 't':		//timestamp
				while (demo.record.timeStamps[t] && t < MAX_TIMESTAMPS) {
					int min = demo.record.timeStamps[t] / 60000;
					int sec = (demo.record.timeStamps[t] / 1000) % 60;
					if (t == 0) {
						Com_sprintf(timeStamps, sizeof(timeStamps), "%0.2d%0.2d", min, sec);
					} else {
						Com_sprintf(timeStamps, sizeof(timeStamps), "%s_%0.2d%0.2d", timeStamps, min, sec);
					}
					t++;
				}
				Com_sprintf( outBuf + outIndex, outLeft, timeStamps);
				outIndex += strlen( outBuf + outIndex );
				break;
			case '%':
				outBuf[outIndex++] = '%';
				break;
			default:
				continue;
			}
			outLeft = sizeof(outBuf) - outIndex - 1;
			continue;
		}
		if (*format == '%') {
			haveTag = qtrue;
			format++;
			continue;
		}
		outBuf[outIndex++] = *format++;
		outLeft = sizeof(outBuf) - outIndex - 1;
	}
	outBuf[ outIndex ] = 0;
	return va("%s", outBuf);
}

// Standard naming for screenshots/demos
static char *demoAutoGenerateDefaultFilename(void) {
	qtime_t ct;
	const char *pszServerInfo = cl.gameState.stringData + cl.gameState.stringOffsets[CS_SERVERINFO];
	
	Com_RealTime(&ct);
	return va("%d-%02d-%02d-%02d%02d%02d-%s",
								1900+ct.tm_year, ct.tm_mon+1,ct.tm_mday,
								ct.tm_hour, ct.tm_min, ct.tm_sec,
								COM_SkipPath(Info_ValueForKey(pszServerInfo, "mapname")));
}

void demoAutoSave_f(void) {
	int t = 0;
	if (strstr(cl_autoDemoFormat->string, "%t"))
		while (demo.record.timeStamps[t] && t < MAX_TIMESTAMPS)
			t++;
	demo.record.timeStamps[t] = cl.serverTime - atoi(cl.gameState.stringData + cl.gameState.stringOffsets[CS_LEVEL_START_TIME]);

	if (!(Cmd_Argc() < 2)) {
		Q_strncpyz(demo.record.customName, Cmd_Argv( 1 ), sizeof(demo.record.customName));
	}
	Com_sprintf(demo.record.demoName, sizeof(demo.record.demoName), demoAutoFormat(demo.record.customName));
	Com_Printf(S_COLOR_WHITE"Demo will be saved into "S_COLOR_GREEN"%s.dm_26\n", demo.record.demoName);
}

void demoAutoSaveLast_f(void) {
	if (Cmd_Argc() < 2 && FS_CopyFile(va("%s/demos/LastDemo/LastDemo.dm_26", demo.record.mod), va("%s/demos/%s.dm_26", demo.record.mod, demoAutoGenerateDefaultFilename()), NULL, 0)) {
		Com_Printf(S_COLOR_GREEN"LastDemo successfully saved\n");
	} else if (FS_CopyFile(va("%s/demos/LastDemo/LastDemo.dm_26", demo.record.mod), va("%s/demos/%s.dm_26", demo.record.mod, Cmd_Argv( 1 )), NULL, 0)) {
		Com_Printf(S_COLOR_GREEN"LastDemo successfully saved into %s.dm_26\n", Cmd_Argv( 1 ));
	} else {
		Com_Printf(S_COLOR_RED"LastDemo has failed to save\n");
	}
}

extern void CL_StopRecord_f( void );
void demoAutoComplete(void) {
	CL_StopRecord_f();
	char newName[MAX_QPATH];
	//if we are not manually saving, then temporarily store a demo in LastDemo folder
	if (!*demo.record.demoName && FS_CopyFile(va("%s/demos/%s.dm_26", demo.record.mod, demo.record.defaultName), va("%s/demos/LastDemo/LastDemo.dm_26", demo.record.mod), NULL, 0)) {
		Com_Printf(S_COLOR_GREEN"Demo temporarily saved into LastDemo/LastDemo.dm_26\n");
	} else if (FS_CopyFile(va("%s/demos/%s.dm_26", demo.record.mod, demo.record.defaultName), va("%s/demos/%s.dm_26", demo.record.mod, demo.record.demoName), newName, sizeof(newName))) {
		Com_Printf(S_COLOR_GREEN"Demo successfully saved into %s.dm_26\n", (Q_stricmp(newName, "")) ? newName : demo.record.demoName);
	} else {
		Com_Printf(S_COLOR_RED"Demo has failed to save\n");
	}
}

// Dynamically names a demo and sets up the recording
void demoAutoRecord(void) {
	//mod resetting allowed in init only
	memset(&demo.record, 0, sizeof(demo.record)-sizeof(demo.record.mod));
	Q_strncpyz(demo.record.defaultName, "LastDemo/LastDemo_recording", sizeof(demo.record.defaultName));
	Cbuf_AddText(va("record %s\n", demo.record.defaultName));
}

void demoAutoInit(void) {
	cvar_t *fs_game;
	memset(&demo.record, 0, sizeof(demo.record));
	fs_game = Cvar_FindVar ("fs_game" );
	if (fs_game && (Q_stricmp(fs_game->string, ""))) {
		Q_strncpyz(demo.record.mod, fs_game->string, sizeof(demo.record.mod));
	} else {
		Q_strncpyz(demo.record.mod, "base", sizeof(demo.record.mod));
	}
}
