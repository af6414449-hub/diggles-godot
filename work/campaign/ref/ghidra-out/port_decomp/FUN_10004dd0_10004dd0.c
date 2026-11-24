
void FUN_10004dd0(LPCSTR param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  OutputDebugStringA("Steam: GetStatValue (int) METHOD \n");
  OutputDebugStringA(param_1);
  OutputDebugStringA("\n");
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050054);
  (**(code **)(*(int *)*puVar1 + 8))(param_1,param_2);
  return;
}

