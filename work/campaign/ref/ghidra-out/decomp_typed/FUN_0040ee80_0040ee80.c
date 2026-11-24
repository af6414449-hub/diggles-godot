
undefined4
FUN_0040ee80(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9b0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  this->i_0c = param_2;
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
  piVar1 = (int *)FUN_006ba810();
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  piVar1[2] = 0;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  FUN_0040efc0();
  if ((this->i_1c != -1) && (this->i_20 != -1)) {
    FUN_006b49b0(this->i_0c,this->i_1c,this->i_20);
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
  return 1;
}

