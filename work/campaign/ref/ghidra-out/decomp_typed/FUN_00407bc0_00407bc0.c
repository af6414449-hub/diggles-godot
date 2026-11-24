
void FUN_00407bc0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f96f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xa4 < DAT_007723fc) {
    FUN_00407d10(DAT_0076700c ^ (uint)&stack0xfffffffc);
    FUN_00555d70();
    FUN_00407d10();
    FUN_00407d10();
    FUN_00406f60(this + 0x18);
    if (*param_1 == 1) {
      iVar3 = FUN_006ba810(0x10d);
      local_8 = 0;
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00420520();
      }
      local_8 = 0xffffffff;
      puVar1 = *(undefined4 **)(this + 0x1c);
      this->i_1c = iVar3;
      if (iVar3 != 0) {
        LOCK();
        *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
        UNLOCK();
      }
      if (puVar1 != (undefined4 *)0x0) {
        LOCK();
        iVar3 = puVar1[1] + -1;
        puVar1[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*puVar1)(1);
        }
      }
    }
    FUN_004234d0(param_1);
    if (*param_1 == 1) {
      if (*(int *)(this->i_1c + 0x7b4) != 0) {
        *(undefined4 *)(this->i_1c + 0x7b4) = 1;
        iVar3 = this->i_0c;
        iVar2 = this->i_1c;
        *(undefined4 *)(iVar2 + 0x7a4) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar2 + 0x7a8) = *(undefined4 *)(iVar3 + 0x10);
        *(undefined4 *)(iVar2 + 0x7ac) = *(undefined4 *)(iVar3 + 0x14);
      }
      this->i_24 = 2;
      *(undefined4 *)(this->i_0c + 0x248) = 2;
      *(undefined1 *)(this->i_0c + 0x2b4) = 1;
    }
  }
  ExceptionList = local_10;
  return;
}

