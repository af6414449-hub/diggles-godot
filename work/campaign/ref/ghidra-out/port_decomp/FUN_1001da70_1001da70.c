
void FUN_1001da70(void)

{
  int iVar1;
  undefined4 *puVar2;
  code *pcVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  CHAR local_1d4 [200];
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar5 = *(uint *)(in_ECX + 0x10);
  if (0xff < uVar5) {
    FUN_1001ec20(local_1d4,"%s(%d): assert(%s) failed.\n",
                 "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x69d,
                 "mMaxActiveVoices < 256");
    OutputDebugStringA(local_1d4);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  memset(local_10c,0,uVar5);
  uVar8 = *(uint *)(in_ECX + 0x10);
  uVar7 = 0;
  uVar4 = uVar8;
  if (uVar8 != 0) {
    do {
      uVar4 = 0;
      if (uVar5 != 0) {
        piVar6 = (int *)(in_ECX + 0x1bda4);
        iVar1 = *(int *)(*(int *)(in_ECX + 0x3c) + uVar7 * 4);
        do {
          if ((iVar1 != 0) && (iVar1 == *(int *)(in_ECX + 0x40 + *piVar6 * 4))) {
            local_10c[uVar7] = local_10c[uVar7] | 1;
            local_10c[uVar4] = local_10c[uVar4] | 2;
          }
          uVar4 = uVar4 + 1;
          piVar6 = piVar6 + 1;
        } while (uVar4 < uVar5);
        uVar8 = *(uint *)(in_ECX + 0x10);
      }
      uVar7 = uVar7 + 1;
      uVar4 = uVar5;
    } while (uVar7 < uVar8);
  }
  uVar5 = 0;
  if (uVar4 != 0) {
    do {
      if (((local_10c[uVar5] & 1) == 0) &&
         (iVar1 = *(int *)(*(int *)(in_ECX + 0x3c) + uVar5 * 4), iVar1 != 0)) {
        *(undefined4 *)(iVar1 + 0x1a4) = 0;
        *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x3c) + uVar5 * 4) + 0x1a8) = 0;
        *(undefined4 *)(*(int *)(in_ECX + 0x3c) + uVar5 * 4) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(in_ECX + 0x10));
  }
  uVar5 = 0;
  uVar8 = 0;
  if (*(int *)(in_ECX + 0x1cda4) != 0) {
    piVar6 = (int *)(in_ECX + 0x1bda4);
    do {
      if (((local_10c[uVar8] & 2) == 0) && (*(int *)(in_ECX + 0x40 + *piVar6 * 4) != 0)) {
        uVar4 = 0xffffffff;
        do {
          if (*(uint *)(in_ECX + 0x10) <= uVar5) break;
          if (*(int *)(*(int *)(in_ECX + 0x3c) + uVar5 * 4) == 0) {
            uVar4 = uVar5;
          }
          uVar5 = uVar5 + 1;
        } while (uVar4 == 0xffffffff);
        if (uVar4 == 0xffffffff) {
          FUN_1001ec20(local_1d4,"%s(%d): assert(%s) failed.\n",
                       "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x6c4,
                       "found != -1");
          OutputDebugStringA(local_1d4);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *(undefined4 *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) =
             *(undefined4 *)(in_ECX + 0x40 + *piVar6 * 4);
        *(uint *)(*(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) + 0x1a4) =
             *(int *)(in_ECX + 0x38) + uVar4 * 0x18;
        *(uint *)(*(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) + 0x1a8) =
             *(int *)(in_ECX + 0x38) + 0xc + uVar4 * 0x18;
        puVar2 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) + 0x1a4);
        memset((void *)*puVar2,0,puVar2[2] << 2);
        puVar2 = *(undefined4 **)(*(int *)(*(int *)(in_ECX + 0x3c) + uVar4 * 4) + 0x1a8);
        memset((void *)*puVar2,0,puVar2[2] << 2);
        uVar5 = uVar4 + 1;
      }
      uVar8 = uVar8 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar8 < *(uint *)(in_ECX + 0x1cda4));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

