
undefined4
FUN_00406630(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int this;
  
  piVar1 = *(int **)(this + 8);
  *(int **)(this + 8) = param_5;
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  this->i_0c = param_2;
  piVar1 = *(int **)(this + 0x10);
  *(int **)(this + 0x10) = param_3;
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  piVar1 = *(int **)(this + 0x14);
  *(int **)(this + 0x14) = param_4;
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + -1;
    if (*param_3 < 1) {
      TclFreeObj(param_3);
    }
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + -1;
    if (*param_4 < 1) {
      TclFreeObj(param_4);
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + -1;
    if (*param_5 < 1) {
      TclFreeObj(param_5);
    }
  }
  return 1;
}

