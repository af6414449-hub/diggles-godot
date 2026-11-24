
int * FUN_10010da0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004246c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  piVar1 = DAT_10050c68;
  if (DAT_10050c68 == (int *)0x0) {
    piVar1 = (int *)FUN_1003ff62(0xc);
    local_8 = 0;
    piVar1[0] = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    *piVar1 = 0;
    piVar1[1] = 0;
    iVar2 = FUN_1003ff62(0x18);
    *(int *)iVar2 = iVar2;
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)(iVar2 + 8) = iVar2;
    *(undefined2 *)(iVar2 + 0xc) = 0x101;
    *piVar1 = iVar2;
    local_8 = CONCAT31(local_8._1_3_,1);
    puVar3 = (undefined4 *)FUN_1003ff62(0x24);
    DAT_10050c68 = piVar1;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[1] = 2;
    puVar3[2] = 6;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    *puVar3 = IndexBufferPool::vftable;
    piVar1[2] = (int)puVar3;
  }
  ExceptionList = local_10;
  return piVar1;
}

