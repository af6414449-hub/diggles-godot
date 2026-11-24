
void FUN_10004c50(LPCSTR param_1,char param_2)

{
  undefined4 *puVar1;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  OutputDebugStringA("Steam: SetAchievementUnlocked METHOD \n");
  OutputDebugStringA(param_1);
  OutputDebugStringA("\n");
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050054);
  if (param_2 == '\0') {
    (**(code **)(*(int *)*puVar1 + 0x20))(param_1);
  }
  else {
    (**(code **)(*(int *)*puVar1 + 0x1c))();
  }
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050054);
  (**(code **)(*(int *)*puVar1 + 0x28))();
  return;
}

