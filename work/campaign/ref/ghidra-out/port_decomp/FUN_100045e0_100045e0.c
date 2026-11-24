
void FUN_100045e0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_1417010e);
  uVar1 = SteamAPI_GetHSteamUser("STEAMUSERSTATS_INTERFACE_VERSION012");
  uVar1 = SteamInternal_FindOrCreateUserInterface(uVar1);
  *param_1 = uVar1;
  return;
}

