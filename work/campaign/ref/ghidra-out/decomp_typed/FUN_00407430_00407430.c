
undefined4 FUN_00407430(undefined4 param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9678;
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
  FUN_00406630(param_1,param_2,param_3);
  iVar2 = FUN_006ba810();
  local_8._0_1_ = 3;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00420520();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  puVar1 = *(undefined4 **)(this + 0x1c);
  this->i_1c = iVar2;
  if (iVar2 != 0) {
    LOCK();
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
    UNLOCK();
  }
  if (puVar1 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = puVar1[1] + -1;
    puVar1[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*puVar1)();
    }
  }
  FUN_00420840(param_1);
  iVar2 = this->i_1c;
  if (*(int *)(iVar2 + 0x7b4) != 0) {
    *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(iVar2 + 0x7a8) = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)(iVar2 + 0x7ac) = *(undefined4 *)(param_2 + 0x14);
  }
  this->i_24 = 2;
  *(undefined4 *)(param_2 + 0x248) = 2;
  *(undefined1 *)(param_2 + 0x2b4) = 1;
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
    TclFreeObj(param_4);
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj(param_5);
  }
  ExceptionList = local_10;
  return 1;
}

