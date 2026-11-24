
void __thiscall FUN_00427610(int this)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  char in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fa9d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_stack_00000004 != '\0') {
    *(undefined4 *)(this + 0x34) = 0;
  }
  piVar3 = (int *)(this + 0xc);
  uVar5 = 0;
  _in_stack_00000004 = (int *)0x0;
  do {
    if (uVar5 < 2) {
      piVar2 = (int *)((int)_in_stack_00000004 + (int)piVar3);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = piVar3;
    }
    if (*piVar2 != -1) {
      if (uVar5 < 2) {
        uVar4 = *(undefined4 *)((int)_in_stack_00000004 + (int)piVar3);
        FUN_00492250();
        FUN_004957e0(uVar4);
        piVar2 = (int *)((int)_in_stack_00000004 + (int)piVar3);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar1 = *piVar3;
        FUN_00492250();
        FUN_004957e0(iVar1);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar2 = piVar3;
      }
      *piVar2 = -1;
    }
    uVar5 = uVar5 + 1;
    _in_stack_00000004 = (int *)((int)_in_stack_00000004 + 4);
  } while ((int)uVar5 < 2);
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0xffffffff;
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar3[1] = 0x14;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)(piVar3 + 3) = 0;
  piVar3[3] = 0x65666c65;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  _in_stack_00000004 = piVar3;
  uVar4 = FUN_00460f20(&stack0x00000004);
  *(undefined4 *)(this + 0x40) = uVar4;
  local_8 = 0;
  *piVar3 = *piVar3 + -1;
  if (*piVar3 == 0) {
    FUN_006ba940();
  }
  *(undefined4 *)(this + 0x44) = 0xffffffff;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x38) = 0xffffffff;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined2 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined1 *)(this + 0x7d) = 0;
  ExceptionList = local_10;
  return;
}

