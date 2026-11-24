
void FUN_1001a020(uint param_1,char param_2)

{
  int iVar1;
  code *pcVar2;
  uint *puVar3;
  int in_ECX;
  uint uVar4;
  uint *puVar5;
  uint local_d8 [2];
  CHAR local_d0 [200];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_d8[0] = param_1;
  local_d8[1] = 0;
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  if (*(char *)(in_ECX + 8) != '\0') {
    FUN_1001ec20(local_d0,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x88e,
                 "!mInsideAudioThreadMutex");
    OutputDebugStringA(local_d0);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  if (((((param_1 & 0xfffff000) != 0xfffff000) || (*(uint *)(in_ECX + 0x1bda0) <= (param_1 & 0xfff))
       ) || (iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (param_1 & 0xfff) * 4), iVar1 == 0)) ||
     (puVar5 = (uint *)(iVar1 + 4), puVar5 == (uint *)0x0)) {
    puVar5 = local_d8;
  }
  uVar4 = *puVar5;
  if (uVar4 != 0) {
    do {
      if ((((uVar4 & 0xfffff000) == 0xfffff000) && ((uVar4 & 0xfff) < *(uint *)(in_ECX + 0x1bda0)))
         && ((iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (uVar4 & 0xfff) * 4), iVar1 != 0 &&
             (puVar3 = (uint *)(iVar1 + 4), puVar3 != (uint *)0x0)))) {
        uVar4 = *puVar3;
      }
      if (uVar4 != 0) {
        iVar1 = *(int *)(in_ECX + 0x3c + (uVar4 & 0xfff) * 4);
        if (((iVar1 != 0) && ((*(uint *)(iVar1 + 8) & 0xfffff) == uVar4 >> 0xc)) &&
           ((uVar4 & 0xfff) != 0)) {
          if (param_2 == '\0') {
            *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xfffffffe;
          }
          else {
            *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
          }
        }
      }
      uVar4 = puVar5[1];
      puVar5 = puVar5 + 1;
    } while (uVar4 != 0);
    if (*(char *)(in_ECX + 8) == '\0') {
      FUN_1001ec20(local_d0,"%s(%d): assert(%s) failed.\n",
                   "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894,
                   "mInsideAudioThreadMutex");
      OutputDebugStringA(local_d0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  *(undefined1 *)(in_ECX + 8) = 0;
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

