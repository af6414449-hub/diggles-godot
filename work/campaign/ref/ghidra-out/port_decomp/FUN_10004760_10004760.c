
void FUN_10004760(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)SteamInternal_ContextInit(&PTR_FUN_10050030);
  iVar2 = (**(code **)(*(int *)*puVar1 + 0x24))();
  if ((iVar2 == *param_1) && (param_1[1] == 0)) {
    OutputDebugStringA("Steam: OnAchievementStored CALLBACK \n");
    OutputDebugStringA((LPCSTR)((int)param_1 + 9));
    OutputDebugStringA("\n");
  }
  return;
}

