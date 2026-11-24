
undefined4
FUN_0040c300(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  int this;
  float fVar3;
  double local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f982d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  this->i_0c = param_2;
  FUN_0040c100();
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  FUN_00406630(param_1,param_2,param_3);
  if (param_5 == (int *)0x0) {
    fVar3 = 0.0;
  }
  else {
    iVar1 = Tcl_GetDoubleFromObj(0);
    if (iVar1 == 1) {
      fVar3 = 0.0;
    }
    else {
      fVar3 = (float)local_18;
    }
  }
  this->i_34 = (int)(fVar3 * 20.0);
  uVar2 = _rand();
  uVar2 = uVar2 & 0x80000003;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
  }
  this->f_38 = (float)(int)uVar2 * 1.5707964;
  FUN_006b49b0(param_2,this->i_28,this->i_2c);
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
  return 1;
}

