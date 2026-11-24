
void FUN_100046f0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050030);
  iVar2 = (**(code **)(*(int *)*puVar1 + 0x24))();
  if ((iVar2 == *param_1) && (param_1[1] == 0)) {
    OutputDebugStringA("Steam: OnUserStatsStored CALLBACK \n");
    if (param_1[2] == 8) {
      OutputDebugStringA("Steam: One or more stats rejected. Should reiterate their sending \n");
      return;
    }
    if (param_1[2] == 1) {
      OutputDebugStringA("Steam: Stats/achievements are stored \n");
    }
  }
  return;
}

