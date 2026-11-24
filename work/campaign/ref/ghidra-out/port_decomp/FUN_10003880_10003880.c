
int FUN_10003880(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_EDX;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004178d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170680,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  FUN_10004070(&local_1c,param_1);
  uVar2 = DAT_10050cc8;
  if ((*(char *)(local_14 + 0xd) != '\0') || (*param_1 < *(int *)(local_14 + 0x10))) {
    if (DAT_10050ccc == 0xaaaaaaa) {
      FUN_10002ad0();
      pcVar1 = (code *)swi(3);
      iVar4 = (*pcVar1)();
      return iVar4;
    }
    local_8 = 0;
    puVar3 = (undefined4 *)FUN_1003ff62(0x18);
    puVar3[4] = *param_1;
    puVar3[5] = 0;
    *puVar3 = uVar2;
    puVar3[1] = uVar2;
    puVar3[2] = uVar2;
    *(undefined2 *)(puVar3 + 3) = 0;
    local_14 = FUN_10003d60(local_1c,local_18,puVar3);
  }
  ExceptionList = local_10;
  return local_14 + 0x14;
}

