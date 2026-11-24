
void FUN_10004610(undefined4 *param_1)

{
  undefined4 uVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_1417010f);
  uVar1 = SteamAPI_GetHSteamUser("STEAMAPPS_INTERFACE_VERSION008");
  uVar1 = SteamInternal_FindOrCreateUserInterface(uVar1);
  *param_1 = uVar1;
  return;
}

