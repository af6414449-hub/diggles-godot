
void FUN_10035be0(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *in_ECX;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint local_138;
  uint local_134;
  uint local_130;
  undefined4 local_12c [4];
  int local_11c;
  byte local_110;
  byte abStack_10f [263];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_130 = 0;
  iVar4 = FUN_100359f0(local_12c,&local_138,&local_130);
  do {
    if (iVar4 != 0) {
LAB_10035d0e:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar6 = 0;
    local_130 = (uint)local_110;
    iVar7 = 0;
    puVar1 = in_ECX + 4;
    uVar9 = *puVar1;
    *puVar1 = *puVar1 + local_138;
    in_ECX[5] = in_ECX[5] + (uint)CARRY4(uVar9,local_138);
    iVar4 = 0;
    if (1 < local_130) {
      do {
        iVar6 = iVar6 + (uint)abStack_10f[iVar4];
        iVar3 = iVar4 + 1;
        iVar4 = iVar4 + 2;
        iVar7 = iVar7 + (uint)abStack_10f[iVar3];
      } while (iVar4 < (int)(local_130 - 1));
    }
    uVar9 = 0;
    if (iVar4 < (int)local_130) {
      uVar9 = (uint)abStack_10f[iVar4];
    }
    uVar9 = iVar7 + iVar6 + uVar9;
    local_134 = uVar9;
    if (uVar9 < 0xff1c) {
      if (local_11c == in_ECX[8]) {
        uVar5 = (*(code *)*in_ECX)(in_ECX[2],in_ECX + 0x9c,uVar9);
        puVar1 = in_ECX + 4;
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + uVar5;
        in_ECX[5] = in_ECX[5] + (uint)CARRY4(uVar2,uVar5);
        if (uVar5 == uVar9) {
          in_ECX[0x9b] = uVar9;
          puVar8 = local_12c;
          puVar10 = in_ECX + 0x52;
          for (iVar4 = 0x48; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar10 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar10 = puVar10 + 1;
          }
          in_ECX[0x9a] = local_134;
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        goto LAB_10035d0e;
      }
      if ((uVar9 != 0) && (iVar4 = FUN_10035ae0(uVar9,0), iVar4 == 0)) goto LAB_10035d0e;
    }
    local_130 = 0;
    iVar4 = FUN_100359f0(local_12c,&local_138,&local_130);
  } while( true );
}

