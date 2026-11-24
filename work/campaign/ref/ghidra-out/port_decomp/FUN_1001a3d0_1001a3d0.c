
void FUN_1001a3d0(int *param_1)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar7;
  int in_ECX;
  int *piVar8;
  int iVar9;
  uint local_e0;
  int local_dc;
  CHAR local_d8 [204];
  uint local_c;
  uint uVar6;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    FUN_10020020();
  }
  param_1[0x14] = in_ECX;
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 8))();
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
  iVar5 = *(int *)(in_ECX + 0x14);
  iVar9 = -1;
  *(undefined1 *)(in_ECX + 8) = 1;
  local_e0 = 0xffffffff;
  local_dc = -1;
  if ((iVar5 != 0) && (*(int *)(in_ECX + 0x3c + iVar5 * 4) == 0)) {
    *(int *)(in_ECX + 0x14) = iVar5 + -1;
  }
  iVar5 = 0;
  piVar8 = (int *)(in_ECX + 0x40);
  do {
    iVar1 = *piVar8;
    if (iVar1 == 0) {
      local_dc = iVar5;
      if (*(int *)(in_ECX + 0x14) < iVar5 + 1) {
        *(int *)(in_ECX + 0x14) = iVar5 + 1;
      }
      goto LAB_1001a513;
    }
    if (((*(byte *)(iVar1 + 0x10) & 2) == 0) && (*(uint *)(iVar1 + 8) < local_e0)) {
      iVar9 = iVar5;
      local_e0 = *(uint *)(iVar1 + 8);
      local_dc = iVar5;
    }
    iVar5 = iVar5 + 1;
    piVar8 = piVar8 + 1;
  } while (iVar5 < 0x400);
  FUN_100205c0(iVar9);
  iVar5 = iVar9;
  if (iVar9 < 0) {
    FUN_1001eba0();
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_1001a513:
  if (param_1[6] == 0) {
    param_1[6] = *(int *)(in_ECX + 0x1064);
    *(int *)(in_ECX + 0x1064) = *(int *)(in_ECX + 0x1064) + 1;
  }
  *(undefined4 **)(in_ECX + 0x40 + iVar5 * 4) = puVar4;
  puVar4[0x5f] = param_1[6];
  *(undefined4 *)(*(int *)(in_ECX + 0x40 + iVar5 * 4) + 0x180) = 0;
  iVar1 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(in_ECX + 0x1060);
  iVar9 = param_1[3];
  *(int *)(iVar1 + 0x40) = iVar9;
  *(int *)(iVar1 + 0x44) = iVar9;
  *(int *)(iVar1 + 0x48) = param_1[5];
  *(undefined4 *)(iVar1 + 0x58) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 100) = 0;
  *(undefined8 *)(iVar1 + 0x1b8) = *(undefined8 *)(param_1 + 0x18);
  uVar6 = param_1[2];
  if ((uVar6 & 1) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 1;
    uVar6 = param_1[2];
  }
  if ((uVar6 & 8) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 8;
    uVar6 = param_1[2];
  }
  if ((uVar6 & 0x10) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x10;
    uVar6 = param_1[2];
  }
  cVar3 = (char)uVar6;
  if ((uVar6 & 0x40) != 0) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
    cVar3 = (char)param_1[2];
  }
  if (cVar3 < '\0') {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x80;
  }
  iVar9 = iVar5 * 0x68;
  *(int *)(iVar9 + 0x1dc0 + in_ECX) = param_1[10];
  *(int *)(iVar9 + 0x1dbc + in_ECX) = param_1[9];
  *(int *)(iVar9 + 0x1dc4 + in_ECX) = param_1[0xb];
  *(int *)(iVar9 + 0x1db8 + in_ECX) = param_1[8];
  *(int *)(iVar9 + 0x1db4 + in_ECX) = param_1[7];
  *(int *)(iVar9 + 0x1dc8 + in_ECX) = param_1[0x15];
  *(int *)(iVar9 + 0x1dd0 + in_ECX) = param_1[0x17];
  *(int *)(iVar9 + 0x1dcc + in_ECX) = param_1[0x16];
  *(undefined4 *)(iVar9 + 0x1dd8 + in_ECX) = 0x3f800000;
  *(undefined4 *)(iVar9 + 0x1dd4 + in_ECX) = 0x3f800000;
  *(int *)(in_ECX + 0x1060) = *(int *)(in_ECX + 0x1060) + 1;
  iVar9 = *(int *)(in_ECX + 0x1060);
  if (iVar9 == 0xfffff) {
    iVar9 = 0;
  }
  *(int *)(in_ECX + 0x1060) = iVar9;
  FUN_100202d0(iVar5);
  FUN_100204f0(iVar5);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x15c) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x18);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x160) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x1c);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x164) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x20);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x168) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x24);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x16c) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x28);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x170) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x2c);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x174) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x30);
  iVar9 = *(int *)(in_ECX + 0x40 + iVar5 * 4);
  *(float *)(iVar9 + 0x178) = *(float *)(iVar9 + 0x3c) * *(float *)(iVar9 + 0x34);
  FUN_10020110(iVar5);
  iVar5 = 0x184;
  do {
    piVar8 = *(int **)((int)param_1 + iVar5 + -0x154);
    if (piVar8 != (int *)0x0) {
      uVar7 = (**(code **)(*piVar8 + 0x14))();
      *(undefined4 *)(iVar5 + *(int *)(in_ECX + 0x40 + local_dc * 4)) = uVar7;
    }
    iVar5 = iVar5 + 4;
  } while (iVar5 < 0x1a4);
  *(undefined1 *)(in_ECX + 0x1cda8) = 1;
  if (*(char *)(in_ECX + 8) == '\0') {
    FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x894,
                 "mInsideAudioThreadMutex");
    OutputDebugStringA(local_d8);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *(undefined1 *)(in_ECX + 8) = 0;
  if (*(LPCRITICAL_SECTION *)(in_ECX + 4) != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(in_ECX + 4));
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

