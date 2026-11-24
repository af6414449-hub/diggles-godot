
void FUN_10004580(undefined4 *param_1)

{
  undefined4 uVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170108);
  uVar1 = SteamAPI_GetHSteamUser("SteamUser021");
  uVar1 = SteamInternal_FindOrCreateUserInterface(uVar1);
  *param_1 = uVar1;
  return;
}

