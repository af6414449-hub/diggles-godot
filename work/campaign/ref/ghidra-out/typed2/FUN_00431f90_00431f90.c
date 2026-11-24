
void FUN_00431f90(float *param_1,float *param_2,int param_3)

{
  int iVar1;
  undefined4 *in_ECX;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined8 local_28;
  float local_20;
  float local_1c;
  float fStack_18;
  float local_14;
  float local_c;
  
  *in_ECX = 0;
  in_ECX[9] = 0;
  in_ECX[0xc] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  in_ECX[6] = 0;
  in_ECX[5] = 0;
  in_ECX[4] = 0;
  in_ECX[10] = 0;
  fVar5 = *param_2;
  local_c = param_2[1];
  local_14 = param_2[2];
  param_2 = (float *)fVar5;
  if ((param_3 != 0) && ((*(uint *)(param_3 + 0x3d0) & 0x4000000) != 0)) {
    uVar2 = (uint)ROUND(local_c * 8.0);
    iVar3 = 0;
    DAT_00772dd8 = uVar2;
    do {
      iVar1 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)(((uVar2 & 7) << 3 | (int)ROUND(fVar5 * 8.0) & 7U) + 0x3c + iVar1) & 2) != 0)
      break;
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 + 1;
    } while (iVar3 < 0x20);
    FUN_00595770(PTR_0077241c);
    fStack_18 = (float)((ulonglong)local_28 >> 0x20);
    local_1c = (float)local_28;
    local_14 = local_20;
    local_c = fStack_18;
    param_2 = (float *)local_1c;
  }
  fVar5 = 14.0;
  if (local_14 + 4.0 <= 14.0) {
    fVar5 = local_14 + 4.0;
  }
  fVar4 = (local_c - param_1[1]) * (local_c - param_1[1]) +
          ((float)param_2 - *param_1) * ((float)param_2 - *param_1);
  FUN_0040b7e0();
  if (3.0 < fVar4) {
    in_ECX[4] = param_2;
    in_ECX[5] = local_c;
    *in_ECX = 2;
    in_ECX[6] = fVar5;
    if (param_3 == 0) {
      in_ECX[9] = 0xffffffff;
      return;
    }
    in_ECX[9] = *(undefined4 *)(param_3 + 0xdc);
  }
  return;
}

