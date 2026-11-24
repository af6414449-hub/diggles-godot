
void FUN_1000f0a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 *puVar5;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = *(int **)(*in_ECX + 8);
  FUN_1000c480(param_2);
  piVar2 = *(int **)(*in_ECX + 8);
  (**(code **)(*piVar2 + 0x1c))(piVar2,0,1,in_ECX + 3);
  (**(code **)(*piVar2 + 0x40))(piVar2,0,1,in_ECX + 3);
  (**(code **)(*piVar2 + 0x1c))(piVar2,2,1,in_ECX + 4);
  (**(code **)(*piVar2 + 0x40))(piVar2,2,1,in_ECX + 4);
  local_14 = 0;
  local_18 = 0;
  FUN_1000ef40(param_2,param_3,param_4,&local_14);
  uVar3 = *(undefined4 *)(*in_ECX + 4);
  uVar4 = *(undefined4 *)(*in_ECX + 8);
  FUN_10010da0();
  FUN_100109d0(param_6,param_5,uVar3,uVar4,&local_18);
  local_10 = FUN_10009340();
  local_c = 0;
  (**(code **)(*piVar1 + 0x48))(piVar1,0,1,&local_14,&local_10,&local_c);
  (**(code **)(*piVar1 + 0x4c))(piVar1,local_18,0x39,0);
  (**(code **)(*piVar1 + 0x60))(piVar1,param_1);
  (**(code **)(*piVar1 + 0x30))(piVar1,param_6,0,0);
  puVar5 = &local_14;
  FUN_10010da0(param_2,param_4,puVar5);
  FUN_10010eb0(param_2,param_4,puVar5);
  FUN_10010da0();
  FUN_10010c60(param_6,&local_18);
  *(undefined1 *)((int)in_ECX + 0xcb9) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

