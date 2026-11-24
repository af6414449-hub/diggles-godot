
void FUN_1000ef40(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 in_EDX;
  undefined1 local_48 [8];
  int local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_10042344;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_38 = param_2;
  local_2c = param_4;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  local_34 = *(undefined4 *)(*in_ECX + 4);
  local_30 = *(undefined4 *)(*in_ECX + 8);
  local_28 = param_1;
  piVar1 = (int *)FUN_10010da0();
  FUN_10011410(local_48,&local_28);
  if (((*(char *)(local_40 + 0xd) != '\0') || (local_28 < *(uint *)(local_40 + 0x10))) ||
     (local_40 == *piVar1)) {
    puVar2 = (undefined4 *)FUN_1003ff62(0x24);
    local_14 = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    local_3c = puVar2;
    uVar3 = FUN_10009340();
    puVar2[1] = uVar3;
    puVar2[2] = 8;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[8] = 0;
    *puVar2 = VertexBufferPool::vftable;
    local_14 = 0xffffffff;
    puVar4 = (undefined4 *)FUN_10011000(&local_28);
    *puVar4 = puVar2;
  }
  FUN_10011000(&local_28);
  FUN_100109d0(param_3,local_38,local_34,local_30,local_2c);
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
  return;
}

