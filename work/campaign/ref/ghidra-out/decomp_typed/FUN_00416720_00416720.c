
uint FUN_00416720(undefined4 param_1,uint param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int this;
  float fVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  int *piStack_1c;
  float local_18;
  float local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  if (((param_5 == (int *)0x0) ||
      (local_c = this, iVar1 = Tcl_ListObjLength(0,param_5,&local_8), iVar1 != 0)) ||
     (local_8 != (int *)0x2)) {
    param_2 = 0;
  }
  else {
    iVar1 = Tcl_ListObjIndex(0,param_5,0,&local_10);
    if (iVar1 == 0) {
      local_8 = local_10;
      if (local_10 != (int *)0x0) {
        *local_10 = *local_10 + 1;
      }
    }
    else {
      local_8 = (int *)0x0;
    }
    piVar4 = local_8;
    FUN_006bafe0(&local_2c);
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    iVar1 = Tcl_ListObjIndex(0,param_5,1,&local_10);
    if ((iVar1 == 0) && (local_10 != (int *)0x0)) {
      *local_10 = *local_10 + 1;
      iVar1 = Tcl_GetDoubleFromObj(0,local_10,&local_20);
      if (iVar1 == 1) {
        local_8 = (int *)0x0;
      }
      else {
        local_8 = (int *)(float)(double)CONCAT44(piStack_1c,local_20);
      }
      *local_10 = *local_10 + -1;
      if (*local_10 < 1) {
        TclFreeObj(local_10);
      }
    }
    else {
      local_8 = (int *)0x0;
    }
    local_14 = *(float *)(param_2 + 0xc);
    this->f_1c = local_14;
    local_18 = *(float *)(param_2 + 0x10);
    this->f_20 = local_18;
    fVar2 = *(float *)(param_2 + 0x14);
    this->i_28 = local_2c;
    this->i_2c = local_28;
    this->f_24 = fVar2;
    this->f_30 = local_24;
    local_14 = this->i_28 - local_14;
    local_18 = this->i_2c - local_18;
    piStack_1c = (int *)(local_24 - fVar2);
    fVar2 = local_18 * local_18 + local_14 * local_14 + (float)piStack_1c * (float)piStack_1c;
    FUN_0040b7e0();
    piVar4 = (int *)0x40a00000;
    if ((float)local_8 <= 5.0) {
      piVar4 = local_8;
    }
    piVar3 = (int *)0x3c23d70a;
    if (0.01 <= (float)piVar4) {
      piVar3 = piVar4;
    }
    local_10 = (int *)(float)(int)ROUND(fVar2 / (float)piVar3 + 0.5);
    this->f_34 = local_14 / (float)local_10;
    this->f_38 = local_18 / (float)local_10;
    this->f_3c = (float)piStack_1c / (float)local_10;
    DAT_00772dd8 = (int)ROUND((float)local_10);
    this->i_40 = DAT_00772dd8;
    piStack_1c = param_5;
    *param_5 = *param_5 + 1;
    if (param_4 != (int *)0x0) {
      *param_4 = *param_4 + 1;
    }
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
    }
    piVar4 = *(int **)(local_c + 8);
    *(int **)(local_c + 8) = param_5;
    *param_5 = *param_5 + 1;
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    *(uint *)(local_c + 0xc) = param_2;
    piVar4 = *(int **)(local_c + 0x10);
    *(int **)(local_c + 0x10) = param_3;
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    piVar4 = *(int **)(local_c + 0x14);
    *(int **)(local_c + 0x14) = param_4;
    if (param_4 != (int *)0x0) {
      *param_4 = *param_4 + 1;
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
      TclFreeObj(param_3);
    }
    if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
      TclFreeObj(param_4);
    }
    *piStack_1c = *piStack_1c + -1;
    if (*piStack_1c < 1) {
      TclFreeObj(piStack_1c);
    }
    param_2 = 0x1000000;
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj(param_3);
  }
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
    TclFreeObj(param_4);
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj(param_5);
  }
  return param_2 >> 0x18;
}

