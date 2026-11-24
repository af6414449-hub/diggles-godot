
uint __thiscall FUN_005af930(KNetSessionMgr *this)

{
  uint uVar1;
  void **ppvVar2;
  int *in_stack_00000008;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9950;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ppvVar2 = &local_10;
  local_8 = 0;
  if ((in_stack_00000008 != (int *)0x0) &&
     (ExceptionList = ppvVar2, *in_stack_00000008 = *in_stack_00000008 + -1, *in_stack_00000008 == 0
     )) {
    ppvVar2 = (void **)FUN_006ba940(uVar1);
  }
  ExceptionList = local_10;
  return (uint)ppvVar2 & 0xffffff00;
}

