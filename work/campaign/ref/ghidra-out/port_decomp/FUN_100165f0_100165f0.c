
undefined4 FUN_100165f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *_Memory;
  undefined4 *puVar4;
  int iVar5;
  undefined4 in_EDX;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  void *local_28;
  undefined4 *local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_10042877;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffff0);
  puVar4 = (undefined4 *)FUN_1003ff62(0x1c);
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  *(undefined8 *)(puVar4 + 4) = 0;
  puVar4[6] = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  *puVar4 = Direct3DVertexBuffer7Port::vftable;
  puVar4[6] = 0;
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  puVar4[1] = *param_1;
  puVar4[2] = uVar1;
  puVar4[3] = uVar2;
  puVar4[4] = uVar3;
  local_24 = puVar4;
  iVar5 = FUN_10017ed0(puVar4,&DAT_10043460,param_2);
  if (iVar5 < 0) {
    FUN_100402ac(puVar4,0x1c);
    FUN_100053a0(iVar5);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_38,(ThrowInfo *)&DAT_1004a24c);
  }
  iVar5 = FUN_10009340();
  local_24 = (undefined4 *)FUN_100402f0(puVar4[4] * iVar5);
  if (DAT_10050c64 == 0) {
    local_28 = (void *)FUN_1003ff62(0xcbc);
    local_14 = 0;
    memset(local_28,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_14 = 0xffffffff;
  }
  _Memory = local_24;
  iVar5 = FUN_1000ef40(puVar4[3],local_24,puVar4[4],puVar4 + 5);
  if (-1 < iVar5) {
    free(_Memory);
    ExceptionList = local_1c;
    return 0;
  }
  FUN_100053a0(iVar5);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_48,(ThrowInfo *)&DAT_1004a24c);
}

