
void FUN_10020020(void)

{
  int iVar1;
  code *pcVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  CHAR local_d4 [204];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(in_ECX + 0x50);
  if ((iVar1 != 0) && (*(int *)(in_ECX + 0x18) != 0)) {
    FUN_1001eb20();
    iVar4 = 0;
    if (0 < *(int *)(iVar1 + 0x14)) {
      piVar3 = (int *)(iVar1 + 0x40);
      do {
        if ((*piVar3 != 0) && (*(int *)(*piVar3 + 0x17c) == *(int *)(in_ECX + 0x18))) {
          FUN_100205c0(iVar4);
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < *(int *)(iVar1 + 0x14));
    }
    if (*(char *)(iVar1 + 8) == '\0') {
      FUN_1001ec20(local_d4,"%s(%d): assert(%s) failed.\n",
                   "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894,
                   "mInsideAudioThreadMutex");
      OutputDebugStringA(local_d4);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    *(undefined1 *)(iVar1 + 8) = 0;
    if (*(LPCRITICAL_SECTION *)(iVar1 + 4) != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(*(LPCRITICAL_SECTION *)(iVar1 + 4));
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

