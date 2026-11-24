
uint FUN_00417010(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int this;
  float fVar7;
  float local_8;
  
  iVar1 = this->i_0c;
  local_8 = *(float *)(iVar1 + 0x44);
  iVar3 = __isnan((double)local_8);
  if (iVar3 == 0) {
    for (; 3.1415927 < local_8; local_8 = local_8 - 6.2831855) {
    }
    for (; local_8 < -3.1415927; local_8 = local_8 + 6.2831855) {
    }
  }
  else {
    local_8 = 0.0;
  }
  fVar7 = local_8 - this->f_218;
  uVar4 = __isnan((double)fVar7);
  if (uVar4 == 0) {
    for (; 3.1415927 < fVar7; fVar7 = fVar7 - 6.2831855) {
    }
    for (; fVar7 < -3.1415927; fVar7 = fVar7 + 6.2831855) {
    }
  }
  if (this->i_50 == -1) {
LAB_00417271:
    return uVar4 & 0xffffff00;
  }
  local_8 = (float)this->i_1c * this->f_208 + local_8;
  FUN_005cd840();
  FUN_00423a90();
  if ((local_8 < this->f_208 * 0.5 + 0.001) || (this->f_208 < 0.001))
  {
    if ((this->i_28 != -1) && (this->i_2c != -1)) {
      FUN_006b49b0(iVar1,this->i_28,this->i_2c,0,2);
    }
    uVar4 = FUN_005cd840();
    goto LAB_00417271;
  }
  iVar3 = this->i_1c;
  if (this->i_20 == iVar3) goto LAB_00417220;
  if (iVar3 == -1) {
    piVar5 = (int *)FUN_00417770();
    if ((*piVar5 != -1) && (iVar3 = FUN_00417770(), *(int *)(iVar3 + 4) != -1)) {
      iVar3 = FUN_00417770();
LAB_00417202:
      uVar2 = *(undefined4 *)(iVar3 + 4);
      puVar6 = (undefined4 *)FUN_00417770();
      FUN_006b49b0(iVar1,*puVar6,uVar2,0,2);
    }
  }
  else {
    piVar5 = (int *)FUN_00417770();
    if ((*piVar5 != -1) && (iVar3 = FUN_00417770(), *(int *)(iVar3 + 4) != -1)) {
      iVar3 = FUN_00417770();
      goto LAB_00417202;
    }
  }
  iVar3 = this->i_1c;
  this->i_20 = iVar3;
LAB_00417220:
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}

