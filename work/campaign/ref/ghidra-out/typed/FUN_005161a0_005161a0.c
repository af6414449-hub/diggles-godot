
void __thiscall FUN_005161a0(ViWinLayoutCC_Healthbar *this)

{
  ViWinLayoutCC_Healthbar *pVVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uStack00000004;
  undefined2 uStack00000005;
  undefined1 uStack00000007;
  int *local_38 [3];
  int local_2c [4];
  ViWinLayoutCC_Healthbar *local_1c;
  undefined1 local_18;
  undefined2 local_17;
  undefined1 local_15;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701c15;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_1c = this;
  if (this->i_4c == -1) {
    (**(code **)(*(int *)this + 0x38))(DAT_0076700c ^ (uint)&stack0xfffffffc);
  }
  iVar5 = *(int *)&this->field_0x14 - *(int *)&this->field_0xc;
  iVar3 = *(int *)&this->field_0x18 - *(int *)&this->field_0x10;
  local_14 = 0xff009b00;
  local_17 = 0x9b00;
  local_18 = 0;
  local_15 = 0xff;
  iVar4 = (int)((float)iVar5 * (float)this->i_54);
  puVar2 = (undefined4 *)FUN_004ec6a0(local_2c + 3,&local_18,(int)((float)this->i_54 * 255.0));
  local_14 = *puVar2;
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_2c[2] = iVar4;
  local_2c[3] = iVar3;
  FUN_004fdf00(local_2c,&local_14);
  local_2c[0] = iVar4 + 1;
  local_17 = 0;
  local_18 = 0;
  local_15 = 0xff;
  local_2c[1] = 0;
  local_2c[2] = iVar5;
  local_2c[3] = iVar3;
  FUN_004fdf00(local_2c,&local_18);
  local_17 = 0x6464;
  local_18 = 100;
  local_15 = 0xff;
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_2c[2] = iVar5;
  local_2c[3] = iVar3;
  FUN_004fdc40(local_2c,&local_18);
  FUN_004ef860("standard");
  local_8 = 0;
  iVar3 = (int)((float)local_1c->i_54 * 100.0 + 0.5);
  FUN_006b90d0(&local_1c,&DAT_00726990,iVar3);
  pVVar1 = local_1c;
  local_8._0_1_ = 1;
  uStack00000005 = 0xffff;
  uStack00000004 = 0xff;
  uStack00000007 = 0xff;
  local_2c[2] = 2;
  local_2c[3] = 10;
  FUN_004fdff0(local_2c + 2,&local_1c->field_0xc,&stack0x00000004,local_38,1,iVar3);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((pVVar1 != (ViWinLayoutCC_Healthbar *)0x0) &&
     (*(int *)pVVar1 = *(int *)pVVar1 + -1, *(int *)pVVar1 == 0)) {
    FUN_006ba940();
  }
  local_8 = 3;
  if ((local_38[0] != (int *)0x0) && (*local_38[0] = *local_38[0] + -1, *local_38[0] == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

