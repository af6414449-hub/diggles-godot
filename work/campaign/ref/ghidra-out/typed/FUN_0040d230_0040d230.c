
undefined4 __thiscall FUN_0040d230(CAct_Door *this)

{
  float fVar1;
  float fVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  
  if (this->c_28 == '\0') {
    iVar6 = this->i_30;
    if (((iVar6 == 0) || (*(int *)(iVar6 + 0x3ec) == 0)) ||
       (*(int *)(*(int *)(iVar6 + 0x3ec) + 0xc) == 0)) {
      this->c_28 = '\x01';
    }
    else if (((*(uint *)(iVar6 + 0x3d0) & 0x4002) != 0) ||
            ((*(uint *)(iVar6 + 0x3d0) & 0x400000) == 0)) {
      this->c_28 = '\x01';
      FUN_0060d470(*(undefined4 *)(this->i_04 + 0xdc));
    }
  }
  uVar4 = this->i_40;
  if (uVar4 == 0xffffffff) {
    if (this->c_28 == '\0') {
      iVar6 = this->i_10;
      fVar1 = *(float *)(this->i_04 + 0xc);
      uVar4 = this->i_3c;
      uVar8 = uVar4 - 1;
      if (uVar4 != *(uint *)(iVar6 + 0xc)) {
        uVar8 = uVar4;
      }
      if (*(uint *)(iVar6 + 0xc) <= uVar8) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = this->i_10;
        if (*(uint *)(iVar6 + 0xc) <= uVar8) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      fVar2 = *(float *)(this->i_30 + 0xc);
      uVar4 = (uint)(0.0 < ((float)*(int *)(*(int *)(iVar6 + 8) + uVar8 * 8) * 0.125 - fVar2) *
                           (fVar1 - fVar2));
    }
    else {
      uVar4 = 1;
    }
    this->i_40 = uVar4;
  }
  if (uVar4 == 0) {
    iVar6 = this->i_2c;
    if (iVar6 == 0) {
      this->i_2c = 1;
      return 1;
    }
    if (iVar6 == 1) {
      if (this->c_28 != '\0') {
        return 1;
      }
      iVar6 = FUN_0060d220(this->i_04);
      if (iVar6 == 0) {
        this->i_08 = 3;
      }
      else if ((iVar6 != 1) && (iVar6 = iVar6 + -2, iVar6 == 0)) {
        iVar9 = iVar6;
        uVar5 = FUN_00422fe0(0);
        uVar7 = FUN_00422ee0(0);
        FUN_005cdae0(uVar7,uVar5,iVar6,iVar9);
        return 1;
      }
      if (this->i_08 != 3) {
        FUN_0040cf60();
        return 1;
      }
    }
    else {
      if (iVar6 != 2) {
        return 0;
      }
      cVar3 = (**(code **)(*(int *)this->i_34 + 0xc))();
      if (cVar3 != '\0') {
        return 1;
      }
      this->i_08 = *(int *)(this->i_34 + 8);
    }
    if (this->c_28 == '\0') {
      FUN_0060d470(*(undefined4 *)(this->i_04 + 0xdc));
      return 0;
    }
  }
  else {
    if (uVar4 == 1) {
      uVar5 = FUN_0040d0a0();
      return uVar5;
    }
    if (uVar4 == 2) {
      this->i_08 = 3;
    }
  }
  return 0;
}

