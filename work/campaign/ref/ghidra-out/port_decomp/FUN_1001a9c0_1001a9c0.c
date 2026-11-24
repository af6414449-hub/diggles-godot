
void FUN_1001a9c0(uint param_1)

{
  int iVar1;
  code *pcVar2;
  uint *puVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint local_e0 [2];
  CHAR local_d8 [204];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_e0[0] = param_1;
  local_e0[1] = 0;
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  if (*(char *)(in_ECX + 8) != '\0') {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x88e,
                 "!mInsideAudioThreadMutex");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  if (((((param_1 & 0xfffff000) != 0xfffff000) || (*(uint *)(in_ECX + 0x1bda0) <= (param_1 & 0xfff))
       ) || (iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (param_1 & 0xfff) * 4), iVar1 == 0)) ||
     (puVar6 = (uint *)(iVar1 + 4), puVar6 == (uint *)0x0)) {
    puVar6 = local_e0;
  }
  uVar4 = *puVar6;
  if (uVar4 != 0) {
    do {
      if ((((uVar4 & 0xfffff000) == 0xfffff000) && ((uVar4 & 0xfff) < *(uint *)(in_ECX + 0x1bda0)))
         && ((iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (uVar4 & 0xfff) * 4), iVar1 != 0 &&
             (puVar3 = (uint *)(iVar1 + 4), puVar3 != (uint *)0x0)))) {
        uVar4 = *puVar3;
      }
      if (uVar4 != 0) {
        iVar5 = (uVar4 & 0xfff) - 1;
        iVar1 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
        if (((iVar1 != 0) && ((*(uint *)(iVar1 + 8) & 0xfffff) == uVar4 >> 0xc)) && (iVar5 != -1)) {
          FUN_100205c0(iVar5);
        }
      }
      uVar4 = puVar6[1];
      puVar6 = puVar6 + 1;
    } while (uVar4 != 0);
    if (*(char *)(in_ECX + 8) == '\0') {
      FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                   "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894,
                   "mInsideAudioThreadMutex");
      OutputDebugStringA(local_d8);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  *(undefined1 *)(in_ECX + 8) = 0;
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

