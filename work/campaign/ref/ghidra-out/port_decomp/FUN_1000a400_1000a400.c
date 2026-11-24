
void FUN_1000a400(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  undefined4 in_EDX;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  undefined1 local_40 [16];
  int *local_30;
  float local_2c;
  int local_28;
  float local_24;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041d97;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    local_30 = (int *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_30,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
    in_ECX = local_28;
  }
  piVar5 = *(int **)(*DAT_10050c64 + 8);
  local_30 = piVar5;
  (**(code **)(*piVar5 + 0xbc))
            (piVar5,*(undefined4 *)(in_ECX + 0x80),*(undefined4 *)(in_ECX + 0x78));
  iVar7 = (**(code **)(*piVar5 + 0x38))(piVar5,*(undefined4 *)(in_ECX + 0x80),0,1,0,&fStack_20);
  if (iVar7 < 0) {
    FUN_100053a0(iVar7);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_40,(ThrowInfo *)&DAT_1004a24c);
  }
  fVar11 = 0.0;
  iVar10 = *(int *)(in_ECX + 0x10) * *(int *)(in_ECX + 0xc);
  iVar7 = 0;
  local_2c = 0.0;
  iVar6 = in_ECX;
  if (3 < iVar10) {
    pbVar8 = (byte *)((int)fStack_20 + 2);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar7 = iVar9 * 4;
    do {
      pbVar1 = pbVar8 + -2;
      pbVar2 = pbVar8 + -1;
      bVar4 = *pbVar8;
      pbVar3 = pbVar8 + 1;
      pbVar8 = pbVar8 + 4;
      fVar11 = (float)*pbVar1 + fVar11 + (float)*pbVar2 + (float)bVar4 + (float)*pbVar3;
      iVar9 = iVar9 + -1;
      iVar6 = local_28;
      local_2c = fVar11;
    } while (iVar9 != 0);
  }
  for (; iVar7 < iVar10; iVar7 = iVar7 + 1) {
    pbVar8 = (byte *)(iVar7 + (int)fStack_20);
    iVar6 = local_28;
    local_2c = local_2c + (float)*pbVar8;
  }
  (**(code **)(*local_30 + 0x3c))(local_30,*(undefined4 *)(iVar6 + 0x80),0);
  uStack_18 = 0x3f4ccccd;
  local_24 = local_2c / (float)(iVar10 * 0xff);
  fStack_20 = 1.0 / (float)((double)*(int *)(iVar6 + 0x18) +
                           *(double *)(&DAT_10047c80 + (*(int *)(iVar6 + 0x18) >> 0x1f) * -8));
  fStack_1c = 1.0 / (float)((double)*(int *)(iVar6 + 0x14) +
                           *(double *)(&DAT_10047c80 + (*(int *)(iVar6 + 0x14) >> 0x1f) * -8));
  *(float *)(iVar6 + 0x1c) = local_24;
  *(float *)(iVar6 + 0x20) = fStack_20;
  *(float *)(iVar6 + 0x24) = fStack_1c;
  *(undefined4 *)(iVar6 + 0x28) = 0x3f4ccccd;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

