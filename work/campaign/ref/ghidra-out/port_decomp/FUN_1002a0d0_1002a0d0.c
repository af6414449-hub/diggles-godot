
void FUN_1002a0d0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  int iVar4;
  int in_EDX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  uint local_48;
  int local_40;
  int local_38;
  int local_34;
  byte local_25;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  byte local_1c;
  byte local_1b;
  byte local_1a;
  byte local_19;
  byte local_18;
  byte local_17;
  undefined8 local_14;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  local_14 = 0;
  local_34 = param_2;
  local_38 = param_1;
  local_40 = in_EDX;
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  do {
    if (((uint)in_ECX[0x17] < (uint)in_ECX[0x39]) ||
       (((uint)in_ECX[0x17] <= (uint)in_ECX[0x39] && ((uint)in_ECX[0x16] <= (uint)in_ECX[0x38]))))
    goto LAB_1002a63c;
    iVar1 = in_ECX[0x42];
    if ((iVar1 == 0) && (in_ECX[0x3a] == 0)) {
      if (*(short *)(in_ECX + 0x14) == 1) {
        iVar1 = (*(code *)*in_ECX)(in_ECX[3],&local_14,7);
        if (iVar1 != 7) goto LAB_1002a63c;
        in_ECX[0x3a] = *(ushort *)(in_ECX + 0xc) - 7;
        *(ushort *)(in_ECX + 0x3b) = (ushort)(byte)local_14;
        uVar5 = (int)(short)((ushort)local_14._4_1_ << 8) | (uint)local_14._3_1_;
        in_ECX[0x3c] = (int)(short)((ushort)local_14._2_1_ << 8) | (uint)local_14._1_1_;
        uVar3 = (int)(short)((ushort)local_14._6_1_ << 8) | (uint)local_14._5_1_;
        in_ECX[0x44] = uVar5;
        in_ECX[0x43] = uVar3;
        in_ECX[0x40] = uVar3;
        in_ECX[0x41] = uVar5;
      }
      else {
        iVar1 = (*(code *)*in_ECX)(in_ECX[3],&local_24,0xe);
        if (iVar1 != 0xe) {
LAB_1002a63c:
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        in_ECX[0x3a] = *(ushort *)(in_ECX + 0xc) - 0xe;
        *(ushort *)(in_ECX + 0x3b) = (ushort)local_24;
        *(ushort *)((int)in_ECX + 0xee) = (ushort)local_23;
        in_ECX[0x3c] = (int)(short)((ushort)local_21 << 8) | (uint)local_22;
        uVar2 = (int)(short)((ushort)local_1d << 8) | (uint)local_1e;
        in_ECX[0x3d] = (int)(short)((ushort)local_1f << 8) | (uint)local_20;
        uVar6 = (int)(short)((ushort)local_1b << 8) | (uint)local_1c;
        in_ECX[0x44] = uVar2;
        uVar5 = (int)(short)((ushort)local_19 << 8) | (uint)local_1a;
        in_ECX[0x46] = uVar6;
        in_ECX[0x43] = uVar5;
        uVar3 = (int)(short)((ushort)local_17 << 8) | (uint)local_18;
        in_ECX[0x45] = uVar3;
        in_ECX[0x3e] = uVar5;
        in_ECX[0x3f] = uVar3;
        in_ECX[0x40] = uVar2;
        in_ECX[0x41] = uVar6;
      }
      iVar1 = 2;
      in_ECX[0x42] = 2;
    }
    while( true ) {
      if ((local_34 == 0) && (local_38 == 0)) goto LAB_1002a63c;
      if (iVar1 == 0) break;
      uVar3 = in_ECX[0x39];
      uVar5 = in_ECX[0x38];
      if (((uint)in_ECX[0x17] < uVar3) ||
         (((uint)in_ECX[0x17] <= uVar3 && ((uint)in_ECX[0x16] <= uVar5)))) goto LAB_1002a627;
      uVar2 = (uint)*(ushort *)(in_ECX + 0x14);
      uVar6 = 0;
      if (*(ushort *)(in_ECX + 0x14) != 0) {
        do {
          *(undefined2 *)(local_40 + uVar6 * 2) =
               *(undefined2 *)
                (in_ECX + (uVar6 - (uint)*(ushort *)(in_ECX + 0x14) * in_ECX[0x42]) + 0x42);
          uVar6 = uVar6 + 1;
          uVar2 = (uint)*(ushort *)(in_ECX + 0x14);
        } while (uVar6 < uVar2);
        uVar3 = in_ECX[0x39];
        uVar5 = in_ECX[0x38];
        iVar1 = in_ECX[0x42];
      }
      local_40 = local_40 + uVar2 * 2;
      bVar8 = local_38 != 0;
      local_38 = local_38 + -1;
      local_34 = local_34 + -1 + (uint)bVar8;
      in_ECX[0x38] = uVar5 + 1;
      iVar1 = iVar1 + -1;
      in_ECX[0x42] = iVar1;
      in_ECX[0x39] = uVar3 + (0xfffffffe < uVar5);
    }
    if (in_ECX[0x3a] != 0) {
      iVar1 = (*(code *)*in_ECX)(in_ECX[3],&local_25,1);
      if (iVar1 != 1) goto LAB_1002a63c;
      in_ECX[0x3a] = in_ECX[0x3a] + -1;
      uVar5 = (uint)(local_25 >> 4);
      uVar3 = uVar5;
      if ((char)local_25 < '\0') {
        uVar3 = uVar5 | 0xfffffff0;
      }
      uVar2 = local_25 & 0xf;
      local_48 = uVar2;
      if ((local_25 & 8) != 0) {
        local_48 = uVar2 | 0xfffffff0;
      }
      iVar1 = in_ECX[0x44];
      iVar7 = (in_ECX[0x43] * *(int *)(&DAT_10047070 + (uint)*(ushort *)(in_ECX + 0x3b) * 4) +
               *(int *)(&DAT_10045a90 + (uint)*(ushort *)(in_ECX + 0x3b) * 4) * iVar1 >> 8) +
              uVar3 * in_ECX[0x3c];
      if (*(short *)(in_ECX + 0x14) == 1) {
        if (0x7fff < iVar7) {
          iVar7 = 0x7fff;
        }
        if (iVar7 < -0x8000) {
          iVar7 = -0x8000;
        }
        iVar4 = *(int *)(&DAT_100476b0 + uVar5 * 4) * in_ECX[0x3c] >> 8;
        if (iVar4 < 0x10) {
          iVar4 = 0x10;
        }
        iVar1 = (*(int *)(&DAT_10045a90 + (uint)*(ushort *)(in_ECX + 0x3b) * 4) * iVar7 +
                 iVar1 * *(int *)(&DAT_10047070 + (uint)*(ushort *)(in_ECX + 0x3b) * 4) >> 8) +
                iVar4 * local_48;
        if (0x7fff < iVar1) {
          iVar1 = 0x7fff;
        }
        if (iVar1 < -0x8000) {
          iVar1 = -0x8000;
        }
        iVar4 = *(int *)(&DAT_100476b0 + uVar2 * 4) * iVar4 >> 8;
        if (iVar4 < 0x10) {
          iVar4 = 0x10;
        }
        in_ECX[0x3c] = iVar4;
        in_ECX[0x43] = iVar7;
        in_ECX[0x44] = iVar1;
        in_ECX[0x41] = iVar1;
        in_ECX[0x42] = 2;
      }
      else {
        if (0x7fff < iVar7) {
          iVar7 = 0x7fff;
        }
        if (iVar7 < -0x8000) {
          iVar7 = -0x8000;
        }
        iVar4 = *(int *)(&DAT_100476b0 + uVar5 * 4) * in_ECX[0x3c] >> 8;
        if (iVar4 < 0x10) {
          iVar4 = 0x10;
        }
        in_ECX[0x3c] = iVar4;
        in_ECX[0x43] = iVar1;
        in_ECX[0x44] = iVar7;
        iVar1 = (*(int *)(&DAT_10045a90 + (uint)*(ushort *)((int)in_ECX + 0xee) * 4) * in_ECX[0x46]
                 + *(int *)(&DAT_10047070 + (uint)*(ushort *)((int)in_ECX + 0xee) * 4) *
                   in_ECX[0x45] >> 8) + in_ECX[0x3d] * local_48;
        if (0x7fff < iVar1) {
          iVar1 = 0x7fff;
        }
        if (iVar1 < -0x8000) {
          iVar1 = -0x8000;
        }
        in_ECX[0x41] = iVar1;
        iVar4 = *(int *)(&DAT_100476b0 + uVar2 * 4) * in_ECX[0x3d] >> 8;
        if (iVar4 < 0x10) {
          iVar4 = 0x10;
        }
        in_ECX[0x3d] = iVar4;
        in_ECX[0x45] = in_ECX[0x46];
        in_ECX[0x46] = iVar1;
        in_ECX[0x42] = 1;
      }
      in_ECX[0x40] = iVar7;
    }
LAB_1002a627:
    if ((local_34 == 0) && (local_38 == 0)) goto LAB_1002a63c;
  } while( true );
}

