
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x1002a01e) */

void FUN_10029e20(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  uint local_101c;
  uint uStack_1018;
  uint local_1010;
  
  uVar2 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((in_ECX == 0) || (*(int *)(in_ECX + 8) == 0)) || (*(int *)(in_ECX + 4) != 0)) {
LAB_1002a0ae:
    __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)(in_ECX + 0x58) != 0 || *(int *)(in_ECX + 0x5c) != 0) {
    if ((*(int *)(in_ECX + 0x5c) == 0) && (*(int *)(in_ECX + 0x58) == 0)) {
      local_101c = 0xffffffff;
      uStack_1018 = 0xffffffff;
    }
    else {
      uStack_1018 = 0;
      local_101c = 0;
    }
    if ((*(short *)(in_ECX + 0x54) == 2) || (*(short *)(in_ECX + 0x54) == 0x11)) {
      if ((*(uint *)(in_ECX + 0xe4) < uStack_1018) ||
         (((*(uint *)(in_ECX + 0xe4) <= uStack_1018 && (*(uint *)(in_ECX + 0xe0) <= local_101c)) ||
          (iVar7 = FUN_10029dc0(), iVar7 != 0)))) {
        uVar4 = *(uint *)(in_ECX + 0xe4);
        uVar5 = *(uint *)(in_ECX + 0xe0);
        if ((uStack_1018 < uVar4) || ((uStack_1018 <= uVar4 && (local_101c <= uVar5))))
        goto LAB_1002a098;
        uVar6 = local_101c - uVar5;
        iVar7 = (uStack_1018 - uVar4) - (uint)(local_101c < uVar5);
        while( true ) {
          if ((iVar7 == 0) && (uVar6 == 0)) goto LAB_1002a098;
          uVar4 = (uint)(0x800 / (ulonglong)*(ushort *)(in_ECX + 0x50));
          if ((iVar7 == 0) && (uVar6 <= uVar4)) {
            uVar4 = uVar6;
          }
          if (*(short *)(in_ECX + 0x54) == 2) {
            uVar10 = FUN_1002a0d0(uVar4,0);
          }
          else if (*(short *)(in_ECX + 0x54) == 0x11) {
            uVar10 = FUN_1002a660(uVar4,0);
          }
          else {
            uVar10 = 0;
          }
          uVar5 = (uint)uVar10;
          if ((uVar5 != uVar4) || ((int)((ulonglong)uVar10 >> 0x20) != 0)) break;
          bVar9 = uVar6 < uVar5;
          uVar6 = uVar6 - uVar5;
          iVar7 = iVar7 - (uint)bVar9;
        }
      }
      goto LAB_1002a0ae;
    }
    uVar3 = FUN_10028d70();
    uVar10 = __allmul(*(undefined4 *)(in_ECX + 0x58),*(undefined4 *)(in_ECX + 0x5c),uVar3,0);
    uVar4 = (uint)uVar10 - *(uint *)(in_ECX + 0x70);
    uVar8 = ((int)((ulonglong)uVar10 >> 0x20) - *(int *)(in_ECX + 0x74)) -
            (uint)((uint)uVar10 < *(uint *)(in_ECX + 0x70));
    uVar5 = FUN_10028d70();
    uVar6 = (uint)((ulonglong)local_101c * (ulonglong)uVar5);
    uVar5 = uStack_1018 * uVar5 + (int)((ulonglong)local_101c * (ulonglong)uVar5 >> 0x20);
    if ((uVar5 < uVar8) || ((uVar5 <= uVar8 && (uVar6 <= uVar4)))) {
      iVar7 = FUN_10029dc0();
      if (iVar7 == 0) goto LAB_1002a0ae;
    }
    else {
      bVar9 = uVar6 < uVar4;
      uVar6 = uVar6 - uVar4;
      uVar5 = (uVar5 - uVar8) - (uint)bVar9;
    }
    if (uVar5 != 0) goto LAB_10029f3c;
    if (uVar6 != 0) {
      do {
        if (uVar5 != 0) goto LAB_10029f3c;
        local_1010 = uVar6;
        if (0x7fffffff < uVar6) goto LAB_10029f3c;
        while( true ) {
          iVar7 = (**(code **)(in_ECX + 8))(*(undefined4 *)(in_ECX + 0xc),local_1010,1);
          if (iVar7 == 0) goto LAB_1002a0ae;
          puVar1 = (uint *)(in_ECX + 0x70);
          uVar4 = *puVar1;
          *puVar1 = *puVar1 - local_1010;
          *(int *)(in_ECX + 0x74) =
               (*(int *)(in_ECX + 0x74) - ((int)local_1010 >> 0x1f)) - (uint)(uVar4 < local_1010);
          bVar9 = uVar6 < local_1010;
          uVar6 = uVar6 - local_1010;
          uVar5 = (uVar5 - ((int)local_1010 >> 0x1f)) - (uint)bVar9;
          if (uVar5 == 0) break;
LAB_10029f3c:
          local_1010 = 0x7fffffff;
        }
        if (uVar6 == 0) {
          __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
          return;
        }
      } while( true );
    }
  }
LAB_1002a098:
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

