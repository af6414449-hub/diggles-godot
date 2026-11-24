
void FUN_10028a30(undefined4 param_1,int param_2,uint *param_3,short *param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  code *in_ECX;
  code *in_EDX;
  char local_54 [16];
  uint local_44;
  int local_40;
  uint local_3c;
  short local_34 [2];
  short local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined4 local_2a;
  undefined4 uStack_26;
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined1 local_18;
  undefined1 local_17;
  byte local_16;
  uint local_15;
  uint local_11;
  undefined4 local_d;
  undefined1 local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  iVar3 = FUN_10028780(param_2,param_3,local_54);
  while (iVar3 == 0) {
    if (param_2 == 0) {
      if ((((local_54[0] == 'f') && (local_54[1] == 'm')) && (local_54[2] == 't')) &&
         (local_54[3] == ' ')) goto LAB_10028b36;
    }
    else {
      if (param_2 != 1) {
LAB_10028b22:
        iVar3 = 0;
        goto LAB_10028b24;
      }
      iVar3 = 0;
      while (local_54[iVar3] == (&DAT_10043b40)[iVar3]) {
        iVar3 = iVar3 + 1;
        if (0xf < iVar3) goto LAB_10028b22;
      }
    }
    iVar3 = FUN_10028900(local_3c + local_44,local_40 + (uint)CARRY4(local_3c,local_44));
    if (iVar3 == 0) break;
    uVar4 = *param_3;
    *param_3 = *param_3 + local_3c + local_44;
    param_3[1] = param_3[1] + local_40 + (uint)CARRY4(local_3c,local_44) +
                 (uint)CARRY4(uVar4,local_3c + local_44);
    iVar3 = FUN_10028780(param_2,param_3,local_54);
  }
  goto LAB_10028aec;
  while (iVar3 = iVar3 + 1, iVar3 < 0x10) {
LAB_10028b24:
    if (local_54[iVar3] != (&DAT_10043b40)[iVar3]) goto LAB_10028aec;
  }
LAB_10028b36:
  iVar3 = (*in_ECX)(param_1,&local_18,0x10);
  if (iVar3 == 0x10) {
    uVar4 = *param_3;
    *param_3 = *param_3 + 0x10;
    param_3[1] = param_3[1] + (uint)(0xffffffef < uVar4);
    *param_4 = CONCAT11(local_17,local_18);
    param_4[1] = (short)local_15 << 8 | (ushort)local_16;
    *(uint *)(param_4 + 2) =
         (((local_11 & 0xff) << 8 | local_15 >> 0x18) << 8 | local_15 >> 0x10 & 0xff) << 8 |
         local_15 >> 8 & 0xff;
    *(uint *)(param_4 + 4) =
         (((local_d & 0xff) << 8 | local_11 >> 0x18) << 8 | local_11 >> 0x10 & 0xff) << 8 |
         local_11 >> 8 & 0xff;
    param_4[6] = (ushort)local_d._2_1_ << 8 | (ushort)(local_d >> 8) & 0xff;
    param_4[7] = CONCAT11(local_9,local_d._3_1_);
    param_4[8] = 0;
    param_4[9] = 0;
    param_4[10] = 0;
    param_4[0xb] = 0;
    param_4[0xc] = 0;
    param_4[0xd] = 0;
    param_4[0xe] = 0;
    param_4[0xf] = 0;
    param_4[0x10] = 0;
    param_4[0x11] = 0;
    param_4[0x12] = 0;
    param_4[0x13] = 0;
    if ((local_40 != 0) || (0x10 < local_44)) {
      iVar3 = (*in_ECX)(param_1,local_34,2);
      if (iVar3 != 2) goto LAB_10028aec;
      uVar1 = *param_3;
      *param_3 = *param_3 + 2;
      uVar4 = 0x12;
      param_3[1] = param_3[1] + (uint)(0xfffffffd < uVar1);
      param_4[8] = local_34[0];
      if (local_34[0] != 0) {
        if ((*param_4 == -2) && (local_34[0] != 0x16)) goto LAB_10028aec;
        if (*param_4 == -2) {
          uVar4 = (*in_ECX)(param_1,&local_30,local_34[0]);
          if (uVar4 != (ushort)param_4[8]) goto LAB_10028aec;
          param_4[9] = local_30;
          *(uint *)(param_4 + 10) =
               CONCAT31(CONCAT21(CONCAT11(local_2b,local_2c),local_2d),local_2e);
          *(undefined4 *)(param_4 + 0xc) = local_2a;
          *(undefined4 *)(param_4 + 0xe) = uStack_26;
          *(undefined4 *)(param_4 + 0x10) = uStack_22;
          *(undefined4 *)(param_4 + 0x12) = uStack_1e;
        }
        else {
          iVar3 = (*in_EDX)(param_1,local_34[0],1);
          if (iVar3 == 0) goto LAB_10028aec;
        }
        uVar2 = param_4[8];
        uVar4 = *param_3;
        *param_3 = *param_3 + (uint)uVar2;
        param_3[1] = param_3[1] + (uint)CARRY4(uVar4,(uint)uVar2);
        uVar4 = (ushort)param_4[8] + 0x12;
      }
      iVar3 = (*in_EDX)(param_1,local_44 - uVar4,1);
      if (iVar3 == 0) goto LAB_10028aec;
      uVar1 = *param_3;
      *param_3 = *param_3 + (local_44 - uVar4);
      param_3[1] = param_3[1] + (local_40 - (uint)(local_44 < uVar4)) +
                   (uint)CARRY4(uVar1,local_44 - uVar4);
    }
    if (local_3c != 0) {
      iVar3 = (*in_EDX)(param_1,local_3c,1);
      if (iVar3 == 0) goto LAB_10028aec;
      uVar4 = *param_3;
      *param_3 = *param_3 + local_3c;
      param_3[1] = param_3[1] + (uint)CARRY4(uVar4,local_3c);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_10028aec:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

