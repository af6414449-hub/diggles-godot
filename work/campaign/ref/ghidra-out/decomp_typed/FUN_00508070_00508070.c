
void FUN_00508070(void)

{
  uint uVar1;
  int iVar2;
  int this;
  undefined4 uVar3;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00700f2d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->i_58 == 5) {
    return;
  }
  if (this->c_2c != '\0') {
    ExceptionList = &local_10;
    iVar2 = FUN_00501450(uVar1);
    if ((*(int *)(iVar2 + 0x8198) == this) &&
       (((iVar2 = FUN_00501450(uVar1), *(int *)(iVar2 + 0x81a4) == 0 ||
         (iVar2 = FUN_00501450(uVar1), *(int *)(iVar2 + 0x81a4) == this)) &&
        (this->i_58 == 0)))) {
      FUN_00507fe0(1);
    }
    iVar2 = FUN_00501450(uVar1);
    if ((*(int *)(iVar2 + 0x819c) != this) && (this->i_58 == 1)) {
      FUN_00507fe0(0);
    }
    iVar2 = FUN_00501450(uVar1);
    if (((*(int *)(iVar2 + 0x819c) != this) && (this->i_58 == 2)) &&
       (this->c_5f != '\0')) {
      uVar3 = 0;
      FUN_00501450(0);
      FUN_00501f80(uVar3);
      FUN_004ed780(DAT_0077239c);
      local_8 = 0;
      if (local_14 != 0) {
        LOCK();
        *(int *)(local_14 + 4) = *(int *)(local_14 + 4) + 1;
        UNLOCK();
      }
      FUN_00501450(local_14);
      FUN_005016e0(local_14);
      FUN_00507fe0(0);
      FUN_00406f00();
    }
    ExceptionList = local_10;
    return;
  }
  return;
}

