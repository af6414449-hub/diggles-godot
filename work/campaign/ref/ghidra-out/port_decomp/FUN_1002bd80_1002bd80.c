
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1002bd80(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *in_ECX;
  uint uVar4;
  float *in_EDX;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  uint uVar9;
  bool bVar10;
  double dVar11;
  uint local_1050;
  int local_1020;
  float *local_101c;
  undefined1 local_100c;
  undefined2 local_100b [2049];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
    uVar4 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52)) >>
            3;
  }
  else {
    uVar4 = (uint)*(ushort *)(in_ECX + 0xc);
  }
  if (uVar4 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_1020 = param_2;
  local_1050 = param_1;
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  uVar2 = (uint)(0x1000 / (ulonglong)uVar4);
  local_101c = in_EDX;
  while( true ) {
    uVar3 = uVar2;
    if ((local_1020 == 0) && (local_1050 < uVar2)) {
      uVar3 = local_1050;
    }
    if (((uVar3 == 0) || (*(short *)(in_ECX + 0x15) == 2)) || (*(short *)(in_ECX + 0x15) == 0x11))
    break;
    if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
      uVar7 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52))
              >> 3;
    }
    else {
      uVar7 = (uint)*(ushort *)(in_ECX + 0xc);
    }
    if (uVar7 == 0) break;
    if ((int)((ulonglong)uVar3 * (ulonglong)uVar7 >> 0x20) != 0) {
      uVar3 = (uint)(0xffffffff / (ulonglong)uVar7);
    }
    uVar3 = uVar3 * uVar7;
    if (uVar3 == 0) {
      uVar3 = 0;
    }
    else {
      uVar9 = in_ECX[0x1c];
      if ((in_ECX[0x1d] == 0) && (uVar9 <= uVar3 && uVar3 - uVar9 != 0)) {
        uVar3 = uVar9;
      }
      uVar3 = (*(code *)*in_ECX)(in_ECX[3],&local_100c,uVar3);
      puVar1 = in_ECX + 0x1c;
      uVar9 = *puVar1;
      *puVar1 = *puVar1 - uVar3;
      in_ECX[0x1d] = in_ECX[0x1d] - (uint)(uVar9 < uVar3);
    }
    uVar3 = uVar3 / uVar7;
    if (uVar3 == 0) break;
    uVar7 = uVar4 / *(ushort *)(in_ECX + 0x14);
    iVar6 = *(ushort *)(in_ECX + 0x14) * uVar3;
    if (uVar7 == 1) {
      FUN_1002ce10(iVar6);
    }
    else if (uVar7 == 2) {
      FUN_1002cfe0(iVar6);
    }
    else if (uVar7 == 3) {
      if ((local_101c != (float *)0x0) && (iVar6 != 0)) {
        puVar5 = local_100b;
        pfVar8 = local_101c;
        do {
          *pfVar8 = (float)((int)((uint)CONCAT21(*puVar5,*(undefined1 *)((int)puVar5 + -1)) << 8) >>
                           8) * 1.1920929e-07;
          iVar6 = iVar6 + -1;
          puVar5 = (undefined2 *)((int)puVar5 + 3);
          pfVar8 = pfVar8 + 1;
        } while (iVar6 != 0);
      }
    }
    else if (uVar7 == 4) {
      FUN_1002d180(iVar6);
    }
    else {
      pfVar8 = local_101c;
      if (uVar7 < 9) {
        for (; iVar6 != 0; iVar6 = iVar6 + -1) {
          dVar11 = 0.0;
          uVar9 = 0;
          if (uVar7 != 0) {
            do {
              __allshl();
              uVar9 = uVar9 + 1;
            } while (uVar9 < uVar7);
          }
          FUN_100415c0();
          *pfVar8 = (float)(dVar11 * 1.0842021724855044e-19);
          pfVar8 = pfVar8 + 1;
        }
      }
      else {
        memset(local_101c,0,iVar6 * 4);
      }
    }
    bVar10 = local_1050 < uVar3;
    local_1050 = local_1050 - uVar3;
    local_101c = local_101c + *(ushort *)(in_ECX + 0x14) * uVar3;
    local_1020 = local_1020 - (uint)bVar10;
    if ((local_1020 == 0) && (local_1050 == 0)) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

