
void FUN_1001a7f0(uint param_1)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  uint *puVar4;
  int in_ECX;
  uint uVar5;
  uint *puVar6;
  undefined8 in_XMM2_Qa;
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
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  if (((((param_1 & 0xfffff000) != 0xfffff000) || (*(uint *)(in_ECX + 0x1bda0) <= (param_1 & 0xfff))
       ) || (iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (param_1 & 0xfff) * 4), iVar1 == 0)) ||
     (puVar6 = (uint *)(iVar1 + 4), puVar6 == (uint *)0x0)) {
    puVar6 = local_e0;
  }
  uVar5 = *puVar6;
  if (uVar5 != 0) {
    do {
      if ((((uVar5 & 0xfffff000) == 0xfffff000) && ((uVar5 & 0xfff) < *(uint *)(in_ECX + 0x1bda0)))
         && ((iVar1 = *(int *)(*(int *)(in_ECX + 0x1bd9c) + (uVar5 & 0xfff) * 4), iVar1 != 0 &&
             (puVar4 = (uint *)(iVar1 + 4), puVar4 != (uint *)0x0)))) {
        uVar5 = *puVar4;
      }
      if (uVar5 != 0) {
        piVar2 = *(int **)(in_ECX + 0x3c + (uVar5 & 0xfff) * 4);
        if (((piVar2 != (int *)0x0) && ((piVar2[2] & 0xfffffU) == uVar5 >> 0xc)) &&
           ((uVar5 & 0xfff) != 0)) {
          (**(code **)(*piVar2 + 0xc))
                    (in_XMM2_Qa,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x24));
        }
      }
      uVar5 = puVar6[1];
      puVar6 = puVar6 + 1;
    } while (uVar5 != 0);
    if (*(char *)(in_ECX + 8) == '\0') {
      FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                   "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894,
                   "mInsideAudioThreadMutex");
      OutputDebugStringA(local_d8);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
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

