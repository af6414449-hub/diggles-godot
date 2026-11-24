
void __thiscall FUN_00524170(ViWinProduction *this)

{
  uint uVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  int iVar3;
  undefined1 uStack00000004;
  undefined2 uStack00000005;
  undefined1 uStack00000007;
  int *local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 local_14;
  undefined2 local_13;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701d9d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->i_2036c == 0) {
    return;
  }
  ExceptionList = &local_10;
  FUN_004ef860(&DAT_00725a00);
  local_8 = 0;
  piVar2 = (int *)FUN_004ef240(uVar1);
  if (local_20 == *piVar2) {
    if (local_24 != 0) goto LAB_005241ef;
  }
  else {
    local_24 = 0;
    local_20 = *piVar2;
  }
  local_24 = FUN_004ef660(local_28 + 3);
LAB_005241ef:
  local_13 = 0;
  local_14 = 0;
  iVar3 = -(*(int *)(local_24 + 0x200) / 2);
  local_11 = 0xff;
  local_1c = 0x11;
  local_18 = iVar3 + 0x47;
  FUN_004fdff0(&local_1c,this->i_2035c + 0xc,&local_14,&local_28,1,local_18);
  local_18 = iVar3 + 0x45;
  uStack00000005 = 0xc8c8;
  uStack00000004 = 200;
  uStack00000007 = 0xff;
  local_1c = 0xf;
  FUN_004fdff0(&local_1c,this->i_2035c + 0xc,&stack0x00000004,&local_28,1,extraout_ECX);
  local_8 = 1;
  if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

