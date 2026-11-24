
undefined1 FUN_00408d00(undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  double dVar1;
  int iVar2;
  char cVar3;
  int this;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f982d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  cVar3 = FUN_00406630(param_1,param_2,param_3);
  if (((cVar3 == '\0') || (iVar2 = this->i_0c, iVar2 == 0)) ||
     (this->c_51 != '\0')) {
    uVar4 = 0;
  }
  else {
    if ((*(uint *)(iVar2 + 0x3d0) & 0x2000) != 0) {
      this->i_2c = this->i_2c + 1;
      this->i_34 = this->i_34 + 1;
    }
    uVar5 = 0;
    uVar6 = 0;
    if (this->i_30 != -1) {
      FUN_006b49b0(iVar2,this->i_2c,this->i_30);
    }
    uVar4 = 1;
    dVar1 = *(double *)(DAT_00772400 + 0xa088);
    this->i_4c = 0;
    this->d_40 = dVar1 + (double)CONCAT44(uVar6,uVar5);
    *(bool *)(param_2 + 0x2b5) = this->c_4a == '\0';
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj();
  }
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
    TclFreeObj();
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj();
  }
  ExceptionList = local_10;
  return uVar4;
}

