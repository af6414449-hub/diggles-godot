
void __thiscall FUN_00516810(ViWinLayoutCC_Attribbar *this)

{
  float fVar1;
  ViWinLayoutCC_Attribbar *pVVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 uStack00000004;
  undefined2 uStack00000005;
  undefined1 uStack00000007;
  int *local_3c [3];
  int local_30 [4];
  ViWinLayoutCC_Attribbar *local_20;
  int local_1c;
  undefined1 local_18;
  undefined2 local_17;
  undefined1 local_15;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701c55;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = this;
  if (this->i_4c == -1) {
    (**(code **)(*(int *)this + 0x38))(DAT_0076700c ^ (uint)&stack0xfffffffc);
  }
  fVar1 = 0.1;
  if (0.1 <= this->f_54) {
    fVar1 = this->f_54;
  }
  iVar6 = *(int *)&this->field_0x14 - *(int *)&this->field_0xc;
  iVar4 = *(int *)&this->field_0x18 - *(int *)&this->field_0x10;
  local_14 = 0xff009b00;
  local_17 = 0;
  local_18 = 0x96;
  local_15 = 0xff;
  iVar5 = (int)(((float)this->i_58 / fVar1) * (float)iVar6);
  local_1c = iVar4;
  puVar3 = (undefined4 *)FUN_004ec6a0(local_30 + 3,&local_18,(int)((float)this->i_58 * 255.0));
  local_14 = *puVar3;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = iVar5;
  local_30[3] = iVar4;
  FUN_004fdf00(local_30,&local_14);
  iVar4 = local_1c;
  local_30[0] = iVar5 + 1;
  uStack00000005 = 0;
  uStack00000004 = 0;
  uStack00000007 = 0xff;
  local_30[1] = 0;
  local_30[3] = local_1c;
  local_30[2] = iVar6;
  FUN_004fdf00(local_30,&stack0x00000004);
  uStack00000005 = 0x6464;
  uStack00000004 = 100;
  uStack00000007 = 0xff;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[3] = iVar4;
  local_30[2] = iVar6;
  FUN_004fdc40(local_30,&stack0x00000004);
  FUN_004ef860("standard");
  local_8 = 0;
  iVar4 = (int)((float)local_20->i_58 * 100.0 + 0.0);
  FUN_006b90d0(&local_20,&DAT_00726990,iVar4);
  pVVar2 = local_20;
  local_8._0_1_ = 1;
  uStack00000005 = 0xffff;
  uStack00000004 = 0xff;
  uStack00000007 = 0xff;
  local_30[2] = 2;
  local_30[3] = 10;
  FUN_004fdff0(local_30 + 2,&local_20->field_0xc,&stack0x00000004,local_3c,1,iVar4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((pVVar2 != (ViWinLayoutCC_Attribbar *)0x0) &&
     (*(int *)pVVar2 = *(int *)pVVar2 + -1, *(int *)pVVar2 == 0)) {
    FUN_006ba940();
  }
  local_8 = 3;
  if ((local_3c[0] != (int *)0x0) && (*local_3c[0] = *local_3c[0] + -1, *local_3c[0] == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

