
int * FUN_10008500(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041a1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  piVar3 = (int *)*in_ECX;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    local_8 = 0;
    piVar1 = (int *)FUN_1003ff62(0x2c);
    FUN_10008a90(param_1 + 4);
    piVar1[10] = param_1[10];
    *piVar1 = (int)piVar3;
    piVar1[2] = (int)piVar3;
    *(undefined2 *)(piVar1 + 3) = 0;
    piVar1[1] = param_2;
    *(undefined1 *)(piVar1 + 3) = *(undefined1 *)(param_1 + 3);
    local_8 = 1;
    if (*(char *)((int)piVar3 + 0xd) != '\0') {
      piVar3 = piVar1;
    }
    iVar2 = FUN_10008500(*param_1,piVar1,param_3);
    *piVar1 = iVar2;
    iVar2 = FUN_10008500(param_1[2],piVar1,param_3);
    piVar1[2] = iVar2;
  }
  ExceptionList = local_10;
  return piVar3;
}

