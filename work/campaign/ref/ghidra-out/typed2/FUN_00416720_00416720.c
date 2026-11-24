
uint __thiscall FUN_00416720(CAct_Move *this)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  uint in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  int local_2c;
  int local_28;
  float local_24;
  undefined4 local_20;
  int *piStack_1c;
  float local_18;
  float local_14;
  int *local_10;
  CAct_Move *local_c;
  int *local_8;
  
  local_c = this;
  if (((in_stack_00000014 == (int *)0x0) || (iVar1 = Tcl_ListObjLength(0), iVar1 != 0)) ||
     (local_8 != (int *)0x2)) {
    in_stack_00000008 = 0;
  }
  else {
    iVar1 = Tcl_ListObjIndex(0,in_stack_00000014,0,&local_10);
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
    iVar1 = Tcl_ListObjIndex(0,in_stack_00000014,1,&local_10);
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
    local_14 = *(float *)(in_stack_00000008 + 0xc);
    this->f_1c = local_14;
    local_18 = *(float *)(in_stack_00000008 + 0x10);
    this->f_20 = local_18;
    fVar2 = *(float *)(in_stack_00000008 + 0x14);
    this->i_28 = local_2c;
    this->i_2c = local_28;
    this->f_24 = fVar2;
    this->f_30 = local_24;
    local_14 = (float)this->i_28 - local_14;
    local_18 = (float)this->i_2c - local_18;
    piStack_1c = (int *)(local_24 - fVar2);
    fVar2 = local_18 * local_18 + local_14 * local_14 + (float)piStack_1c * (float)piStack_1c;
    FUN_0040b7e0();
    piVar4 = (int *)5.0;
    if ((float)local_8 <= 5.0) {
      piVar4 = local_8;
    }
    fVar3 = 0.01;
    if (0.01 <= (float)piVar4) {
      fVar3 = (float)piVar4;
    }
    local_10 = (int *)(float)(int)ROUND(fVar2 / fVar3 + 0.5);
    this->f_34 = local_14 / (float)local_10;
    this->f_38 = local_18 / (float)local_10;
    this->f_3c = (float)piStack_1c / (float)local_10;
    DAT_00772dd8 = (int)ROUND((float)local_10);
    this->i_40 = DAT_00772dd8;
    piStack_1c = in_stack_00000014;
    *in_stack_00000014 = *in_stack_00000014 + 1;
    if (in_stack_00000010 != (int *)0x0) {
      *in_stack_00000010 = *in_stack_00000010 + 1;
    }
    if (in_stack_0000000c != (int *)0x0) {
      *in_stack_0000000c = *in_stack_0000000c + 1;
    }
    piVar4 = *(int **)&local_c->field_0x8;
    *(int **)&local_c->field_0x8 = in_stack_00000014;
    *in_stack_00000014 = *in_stack_00000014 + 1;
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    local_c->i_0c = in_stack_00000008;
    piVar4 = *(int **)&local_c->field_0x10;
    *(int **)&local_c->field_0x10 = in_stack_0000000c;
    if (in_stack_0000000c != (int *)0x0) {
      *in_stack_0000000c = *in_stack_0000000c + 1;
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    piVar4 = *(int **)&local_c->field_0x14;
    *(int **)&local_c->field_0x14 = in_stack_00000010;
    if (in_stack_00000010 != (int *)0x0) {
      *in_stack_00000010 = *in_stack_00000010 + 1;
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    if ((in_stack_0000000c != (int *)0x0) &&
       (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
      TclFreeObj(in_stack_0000000c);
    }
    if ((in_stack_00000010 != (int *)0x0) &&
       (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
      TclFreeObj(in_stack_00000010);
    }
    *piStack_1c = *piStack_1c + -1;
    if (*piStack_1c < 1) {
      TclFreeObj(piStack_1c);
    }
    in_stack_00000008 = 0x1000000;
  }
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj(in_stack_0000000c);
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    TclFreeObj(in_stack_00000010);
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    TclFreeObj(in_stack_00000014);
  }
  return in_stack_00000008 >> 0x18;
}

