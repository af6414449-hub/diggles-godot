
void FUN_1001fde0(void)

{
  void *_Dst;
  undefined4 in_ECX;
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042c57;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  _Dst = (void *)FUN_1003ff62(0x1e0);
  local_8 = 0;
  memset(_Dst,0,0x1e0);
  FUN_1001ecc0(in_ECX);
  ExceptionList = local_10;
  return;
}

