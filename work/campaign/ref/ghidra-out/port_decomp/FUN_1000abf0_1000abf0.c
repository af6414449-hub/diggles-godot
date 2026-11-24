
void FUN_1000abf0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  void *_Dst;
  int in_ECX;
  undefined4 in_EDX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041eb7;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = param_2;
  local_20 = param_3;
  local_24 = param_4;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar2 = *(int **)(*DAT_10050c64 + 8);
  (**(code **)(*piVar2 + 0x84))(piVar2,1,&local_1c,0);
  (**(code **)(*piVar2 + 0xb0))(piVar2,1,param_1 + 0x30);
  (**(code **)(*piVar2 + 200))(piVar2,local_1c,&DAT_1416e810);
  (**(code **)(*piVar2 + 0x20))(piVar2,0,1,&local_20);
  (**(code **)(*piVar2 + 0x20))(piVar2,1,1,&local_24);
  FUN_1000b5d0();
  (**(code **)(*piVar2 + 0x28))(piVar2,0,1,in_ECX + 0x5c);
  (**(code **)(*piVar2 + 0x28))(piVar2,1,1,in_ECX + 0x5c);
  puVar1 = (undefined4 *)(in_ECX + 0xa8);
  (**(code **)(*piVar2 + 0xc0))(piVar2,*puVar1,0,0,in_ECX + 0x1c,0,0);
  (**(code **)(*piVar2 + 0x1c))(piVar2,0,1,puVar1);
  (**(code **)(*piVar2 + 0x40))(piVar2,0,1,puVar1);
  local_18 = FUN_10009340();
  (**(code **)(*piVar2 + 0x48))(piVar2,0,1,param_1 + 0x2c,&local_18,&DAT_1416e848);
  (**(code **)(*piVar2 + 0x4c))(piVar2,*(undefined4 *)(param_1 + 0x28),0x39,0);
  (**(code **)(*piVar2 + 0x60))(piVar2,4);
  (**(code **)(*piVar2 + 0x30))(piVar2,6,0,0);
  (**(code **)(*piVar2 + 0x20))(piVar2,0,1,&DAT_10043854);
  (**(code **)(*piVar2 + 0x20))(piVar2,1,1,&DAT_10043854);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

