
undefined4 __thiscall FUN_004082a0(CAct_Anim *this)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  int *piVar5;
  double in_XMM0_Qa;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  uint local_34;
  int *local_30;
  int *local_28;
  int *local_24;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f97ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  local_14 = 0xffffffff;
  local_18 = (int *)0xffffffff;
  if (in_stack_00000014 == (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar5 = (int *)0x0;
LAB_004084ac:
    local_34 = 0;
  }
  else {
    iVar2 = Tcl_ListObjLength(0);
    if ((iVar2 == 0) && (local_1c == (int *)0x1)) {
      iVar2 = Tcl_ListObjIndex(0,in_stack_00000014);
      if (iVar2 == 0) {
        local_28 = local_24;
        if (local_24 != (int *)0x0) {
          *local_24 = *local_24 + 1;
        }
      }
      else {
        local_28 = (int *)0x0;
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_28 != (int *)0x0) {
        Tcl_GetStringFromObj();
      }
      FUN_006b8fb0();
      if (*(int *)(*(int *)(in_stack_00000008 + 0xd4) + 0xcc4) == 0) {
        cVar1 = '\0';
      }
      else {
        cVar1 = FUN_004613d0();
      }
      local_8._0_1_ = 4;
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 3;
      if (cVar1 == '\0') {
        if (local_28 != (int *)0x0) {
          Tcl_GetStringFromObj();
        }
        FUN_006b8fb0();
        local_8._0_1_ = 5;
        FUN_00460fc0(&local_1c,&local_14);
        local_8._0_1_ = 6;
        local_34 = local_14;
        local_30 = local_18;
        if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
          FUN_006ba940();
          local_34 = local_14;
          local_30 = local_18;
        }
      }
      if ((*(uint *)(in_stack_00000008 + 0x3d0) & 0x2000) != 0) {
        local_34 = local_34 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      pcVar4 = TclFreeObj_exref;
      if ((local_28 != (int *)0x0) &&
         (*local_28 = *local_28 + -1, pcVar4 = TclFreeObj_exref, *local_28 < 1)) {
        TclFreeObj();
      }
      goto LAB_00408506;
    }
    iVar2 = Tcl_ListObjIndex(0,in_stack_00000014);
    if (iVar2 == 0) {
      piVar3 = local_28;
      if (local_28 != (int *)0x0) {
        *local_28 = *local_28 + 1;
      }
    }
    else {
      piVar3 = (int *)0x0;
    }
    iVar2 = Tcl_ListObjIndex(0,in_stack_00000014);
    if (iVar2 == 0) {
      piVar5 = local_28;
      if (local_28 != (int *)0x0) {
        *local_28 = *local_28 + 1;
      }
    }
    else {
      piVar5 = (int *)0x0;
    }
    if (piVar3 == (int *)0x0) goto LAB_004084ac;
    iVar2 = Tcl_GetIntFromObj(0);
    local_34 = -(uint)(iVar2 != 1) & (uint)local_28;
  }
  local_30 = piVar5;
  if (piVar5 != (int *)0x0) {
    iVar2 = Tcl_GetIntFromObj(0);
    *piVar5 = *piVar5 + -1;
    local_1c = (int *)(-(uint)(iVar2 != 1) & (uint)local_28);
    local_30 = local_1c;
    if (*piVar5 < 1) {
      TclFreeObj();
      local_30 = local_1c;
    }
  }
  pcVar4 = TclFreeObj_exref;
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar4 = TclFreeObj_exref, *piVar3 < 1)) {
    TclFreeObj();
  }
LAB_00408506:
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  FUN_00406630((CAct *)this);
  FUN_006b49b0(in_stack_00000008,local_34,local_30);
  this->d_20 = *(double *)(DAT_00772400 + 0xa088) + in_XMM0_Qa;
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    (*pcVar4)();
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    (*pcVar4)();
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    (*pcVar4)();
  }
  ExceptionList = local_10;
  return 1;
}

