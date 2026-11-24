
int FUN_1000c540(int *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *in_ECX;
  undefined4 in_EDX;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100421bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170680,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  FUN_1000c730(&local_1c,param_1);
  if ((*(char *)(local_14 + 0xd) != '\0') || (*param_1 < *(int *)(local_14 + 0x10))) {
    if (in_ECX[1] == 0xaaaaaaa) {
      FUN_10002ad0();
      pcVar2 = (code *)swi(3);
      iVar4 = (*pcVar2)();
      return iVar4;
    }
    uVar1 = *in_ECX;
    local_8 = 0;
    puVar3 = (undefined4 *)FUN_1003ff62(0x18);
    puVar3[4] = *param_1;
    puVar3[5] = 0;
    *puVar3 = uVar1;
    puVar3[1] = uVar1;
    puVar3[2] = uVar1;
    *(undefined2 *)(puVar3 + 3) = 0;
    local_14 = FUN_10003d60(local_1c,local_18,puVar3);
  }
  ExceptionList = local_10;
  return local_14 + 0x14;
}

