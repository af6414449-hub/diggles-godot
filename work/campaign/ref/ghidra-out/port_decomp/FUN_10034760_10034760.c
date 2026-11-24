
undefined4 FUN_10034760(undefined4 *param_1)

{
  short *psVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  int in_ECX;
  uint uVar7;
  char in_DL;
  char cVar8;
  int local_60 [14];
  char local_28 [8];
  undefined4 local_20;
  int local_1c;
  char local_11;
  char local_10;
  byte local_f;
  char local_e;
  char local_d;
  char local_c;
  byte local_b;
  byte local_a;
  char local_9 [5];
  
  local_11 = in_DL;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_60[0] = 0;
  local_60[1] = 0x15888;
  local_60[2] = 0x2b110;
  local_60[3] = 0x2ee00;
  local_60[4] = 8000;
  local_60[5] = 16000;
  local_60[6] = 0x5622;
  local_60[7] = 24000;
  local_60[8] = 32000;
  local_60[9] = 0xac44;
  local_60[10] = 48000;
  local_60[0xb] = 96000;
  local_28[0] = '\0';
  local_28[1] = '\b';
  local_28[2] = '\f';
  local_28[3] = -1;
  local_28[4] = '\x10';
  local_28[5] = '\x14';
  local_28[6] = '\x18';
  local_28[7] = -1;
LAB_100347e0:
  local_9[0] = '\0';
  local_e = '\0';
  local_d = '\0';
  local_f = 0;
  local_a = 0;
  local_b = 0;
  iVar4 = FUN_1002d730();
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = FUN_1002d650(&local_c);
  if (iVar4 == 0) {
    return 0;
  }
  do {
    if (local_c == -1) {
      iVar4 = FUN_1002d650(&local_10);
      if (iVar4 == 0) {
        return 0;
      }
      if (local_10 == '>') break;
      iVar4 = FUN_1002d730();
      if (iVar4 == 0) {
        return 0;
      }
    }
    iVar4 = FUN_1002d650(&local_c);
    if (iVar4 == 0) {
      return 0;
    }
  } while( true );
  iVar4 = FUN_1002d650(local_9);
  if (iVar4 == 0) {
    return 0;
  }
  if (local_9[0] == '\x01') goto LAB_100347e0;
  iVar4 = FUN_1002d650(&local_e);
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = FUN_1002d650(&local_d);
  cVar8 = local_d;
  if (iVar4 == 0) {
    return 0;
  }
  if (local_d == '\0') goto LAB_100347e0;
  iVar4 = FUN_1002d650(&local_f);
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = FUN_1002d650(&local_a);
  if (iVar4 == 0) {
    return 0;
  }
  if (10 < local_a) goto LAB_100347e0;
  iVar4 = FUN_1002d650(&local_b);
  if (iVar4 == 0) {
    return 0;
  }
  if ((local_b == 3) || (local_b == 7)) goto LAB_100347e0;
  iVar4 = FUN_1002d650(local_9);
  if (iVar4 == 0) {
    return 0;
  }
  if (local_9[0] == '\x01') goto LAB_100347e0;
  local_d = '\0';
  if (local_e == '\x01') {
    iVar4 = FUN_1002d960(&local_d);
    if (iVar4 != 0) {
LAB_1003497e:
      if (iVar4 == -0x80) {
        return 0;
      }
      goto LAB_100347e0;
    }
    param_1[2] = 0;
    *param_1 = local_20;
    param_1[1] = local_1c;
  }
  else {
    local_60[0xc] = 0;
    local_60[0xd] = 0;
    iVar4 = FUN_1002d960(&local_d);
    if (iVar4 != 0) goto LAB_1003497e;
    param_1[2] = local_60[0xc];
    *param_1 = 0;
    param_1[1] = 0;
  }
  psVar1 = (short *)(param_1 + 4);
  if (cVar8 == '\x01') {
    *psVar1 = 0xc0;
  }
  else if ((byte)(cVar8 - 2U) < 4) {
    sVar3 = 0x240;
    bVar6 = cVar8 - 2;
LAB_10034a4e:
    *psVar1 = (1 << (bVar6 & 0x1f)) * sVar3;
  }
  else if (cVar8 == '\x06') {
    iVar4 = FUN_1002d570(psVar1);
    if (iVar4 == 0) {
      return 0;
    }
    *psVar1 = *psVar1 + 1;
  }
  else {
    if (cVar8 != '\a') {
      sVar3 = 0x100;
      bVar6 = cVar8 - 8;
      goto LAB_10034a4e;
    }
    iVar4 = FUN_1002d570(psVar1);
    if (iVar4 == 0) {
      return 0;
    }
    *psVar1 = *psVar1 + 1;
  }
  if (local_f < 0xc) {
    iVar4 = local_60[local_f];
  }
  else if (local_f == 0xc) {
    if ((*(int *)(in_ECX + 0x18) == 0x20) && (iVar4 = FUN_1002d310(), iVar4 == 0)) {
      return 0;
    }
    iVar4 = *(int *)(in_ECX + 0x18);
    uVar7 = 0x20 - iVar4;
    if (uVar7 < 8) {
      local_1c = 8 - uVar7;
      uVar2 = *(uint *)(in_ECX + 0x101c);
      iVar5 = FUN_1002d310();
      if (iVar5 == 0) {
        return 0;
      }
      bVar6 = (byte)local_1c;
      param_1[3] = (~(0xffffffffU >> (bVar6 & 0x1f)) & *(uint *)(in_ECX + 0x101c)) >>
                   (0x20 - bVar6 & 0x1f) |
                   ((~(0xffffffffU >> ((byte)uVar7 & 0x1f)) & uVar2) >> ((byte)iVar4 & 0x1f)) <<
                   (bVar6 & 0x1f);
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + local_1c;
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << (bVar6 & 0x1f);
      iVar4 = param_1[3] * 1000;
    }
    else {
      param_1[3] = (uint)*(byte *)(in_ECX + 0x101f);
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 8;
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << 8;
      iVar4 = param_1[3] * 1000;
    }
  }
  else {
    if (local_f == 0xd) {
      if ((*(int *)(in_ECX + 0x18) == 0x20) && (iVar4 = FUN_1002d310(), iVar4 == 0)) {
        return 0;
      }
      iVar4 = *(int *)(in_ECX + 0x18);
      uVar7 = 0x20 - iVar4;
      if (uVar7 < 0x10) {
        local_1c = 0x10 - uVar7;
        uVar2 = *(uint *)(in_ECX + 0x101c);
        iVar5 = FUN_1002d310();
        if (iVar5 == 0) {
          return 0;
        }
        bVar6 = (byte)local_1c;
        param_1[3] = (~(0xffffffffU >> (bVar6 & 0x1f)) & *(uint *)(in_ECX + 0x101c)) >>
                     (0x20 - bVar6 & 0x1f) |
                     ((~(0xffffffffU >> ((byte)uVar7 & 0x1f)) & uVar2) >> ((byte)iVar4 & 0x1f)) <<
                     (bVar6 & 0x1f);
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + local_1c;
        *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << (bVar6 & 0x1f);
      }
      else {
        param_1[3] = (uint)*(ushort *)(in_ECX + 0x101e);
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 0x10;
        *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << 0x10;
      }
      goto LAB_10034c7f;
    }
    if (local_f != 0xe) goto LAB_100347e0;
    if ((*(int *)(in_ECX + 0x18) == 0x20) && (iVar4 = FUN_1002d310(), iVar4 == 0)) {
      return 0;
    }
    iVar4 = *(int *)(in_ECX + 0x18);
    uVar7 = 0x20 - iVar4;
    if (uVar7 < 0x10) {
      local_1c = 0x10 - uVar7;
      uVar2 = *(uint *)(in_ECX + 0x101c);
      iVar5 = FUN_1002d310();
      if (iVar5 == 0) {
        return 0;
      }
      bVar6 = (byte)local_1c;
      param_1[3] = (~(0xffffffffU >> (bVar6 & 0x1f)) & *(uint *)(in_ECX + 0x101c)) >>
                   (0x20 - bVar6 & 0x1f) |
                   ((~(0xffffffffU >> ((byte)uVar7 & 0x1f)) & uVar2) >> ((byte)iVar4 & 0x1f)) <<
                   (bVar6 & 0x1f);
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + local_1c;
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << (bVar6 & 0x1f);
      iVar4 = param_1[3] * 10;
    }
    else {
      param_1[3] = (uint)*(ushort *)(in_ECX + 0x101e);
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 0x10;
      *(int *)(in_ECX + 0x101c) = *(int *)(in_ECX + 0x101c) << 0x10;
      iVar4 = param_1[3] * 10;
    }
  }
  param_1[3] = iVar4;
LAB_10034c7f:
  *(byte *)((int)param_1 + 0x12) = local_a;
  cVar8 = local_28[local_b];
  *(char *)((int)param_1 + 0x13) = cVar8;
  if (cVar8 == '\0') {
    cVar8 = local_11;
  }
  *(char *)((int)param_1 + 0x13) = cVar8;
  iVar4 = FUN_1002d650(param_1 + 5);
  if (iVar4 == 0) {
    return 0;
  }
  return 1;
}

