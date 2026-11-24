
void FUN_10034de0(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  int in_EDX;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint local_a4;
  uint local_a0;
  byte local_99;
  uint local_98;
  undefined4 local_94;
  byte local_8d;
  undefined1 local_8c [132];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  iVar3 = FUN_10034cd0();
  if (iVar3 == 0) {
switchD_10034e70_caseD_2:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  cVar1 = *(char *)(in_EDX + 0x12);
  uVar7 = (uint)*(byte *)(in_EDX + 0x13);
  if ((((cVar1 == '\b') || (cVar1 == '\n')) && (param_1 == 1)) ||
     ((cVar1 == '\t' && (param_1 == 0)))) {
    uVar7 = uVar7 + 1;
  }
  iVar3 = in_EDX + param_1 * 8;
  if (uVar7 <= *(byte *)(in_EDX + 0x1d + param_1 * 8)) goto switchD_10034e70_caseD_2;
  *(undefined4 **)(iVar3 + 0x20) = param_2;
  switch(*(undefined1 *)(iVar3 + 0x1c)) {
  case 0:
    local_98 = (uint)*(ushort *)(in_EDX + 0x10);
    iVar3 = FUN_1002d470(&local_94);
    if ((iVar3 != 0) && (uVar7 = local_98, local_98 != 0)) {
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *param_2 = local_94;
        param_2 = param_2 + 1;
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    goto LAB_100350c7;
  case 1:
    local_a0 = (uint)*(ushort *)(in_EDX + 0x10);
    uVar7 = 0;
    if (local_a0 != 0) {
      while (iVar3 = FUN_1002d470(&local_98), iVar3 != 0) {
        param_2[uVar7] = local_98;
        uVar7 = uVar7 + 1;
        if (local_a0 <= uVar7) {
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
    goto LAB_100350c7;
  default:
    goto switchD_10034e70_caseD_2;
  case 8:
    local_a4 = (uint)*(ushort *)(in_EDX + 0x10);
    uVar7 = 0;
    local_98 = (uint)*(byte *)(iVar3 + 0x1e);
    if (*(byte *)(iVar3 + 0x1e) != 0) {
      do {
        iVar3 = FUN_1002d470(&local_a0);
        if (iVar3 == 0) goto LAB_100350c7;
        param_2[uVar7] = local_a0;
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_98);
    }
    puVar4 = &DAT_100500c0 + local_98 * 0x10;
    iVar3 = 0;
    uVar6 = local_a4;
    uVar7 = local_98;
    break;
  case 0x20:
    local_99 = *(byte *)(iVar3 + 0x1e);
    local_98 = (uint)*(ushort *)(in_EDX + 0x10);
    uVar7 = (uint)local_99 << 8;
    if (local_99 != 0) {
      do {
        iVar3 = FUN_1002d470(&local_a4);
        if (iVar3 == 0) goto LAB_100350c7;
        bVar5 = (char)uVar7 + 1;
        param_2[uVar7 & 0xff] = local_a4;
        uVar6 = uVar7 >> 8;
        uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar5);
      } while (bVar5 < (byte)uVar6);
    }
    iVar3 = FUN_1002d650(&local_8d);
    if ((iVar3 == 0) || (local_8d == 0xf)) goto LAB_100350c7;
    local_8d = local_8d + 1;
    iVar3 = FUN_1002d470(&local_a0);
    if (iVar3 == 0) goto LAB_100350c7;
    memset(local_8c,0,0x80);
    uVar7 = (uint)local_99 << 8;
    if (local_99 != 0) {
      local_a4 = (uint)local_8d;
      uVar6 = uVar7;
      do {
        iVar3 = FUN_1002d470(local_8c + (uVar6 & 0xff) * 4);
        if (iVar3 == 0) goto LAB_100350c7;
        bVar5 = (char)uVar6 + 1;
        uVar7 = CONCAT31((int3)(uVar6 >> 8),bVar5);
        uVar2 = uVar6 >> 8;
        uVar6 = uVar7;
      } while (bVar5 < (byte)uVar2);
    }
    puVar4 = local_8c;
    iVar3 = (int)(char)local_a0;
    uVar6 = local_98;
    uVar7 = uVar7 >> 8;
  }
  FUN_10034590(uVar6,uVar7,iVar3,puVar4,param_2);
LAB_100350c7:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

