
void FUN_1000afd0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 in_ECX;
  undefined4 in_EDX;
  int *local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_c = (int *)0x0;
  iVar1 = D3DCompileFromFile(in_ECX,0,1,in_EDX,param_1,0x800,0,param_2,&local_c);
  if (iVar1 < 0) {
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

