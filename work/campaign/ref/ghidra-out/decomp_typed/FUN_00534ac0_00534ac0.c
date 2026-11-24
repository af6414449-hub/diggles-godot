
void FUN_00534ac0(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  ushort uVar5;
  SHORT SVar6;
  int iVar7;
  int this;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint local_8;
  
  if (*(char *)(DAT_00772400 + 0x3c9) == '\0') {
    uVar5 = GetAsyncKeyState(0x24);
    iVar7 = DAT_00772400;
    if (((uVar5 & 1) != 0) && (0 < *(int *)(DAT_00772400 + 0xa0c8))) {
      if (*(int *)(DAT_00772400 + 0xa0c8) == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar8 = (int *)(DAT_0077244c + 0x488);
      if (**(uint **)(iVar7 + 0xa0c4) < 0x2000) {
        piVar8 = piVar8 + **(uint **)(iVar7 + 0xa0c4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = DAT_00772400;
      iVar7 = *piVar8;
      if (iVar7 != 0) {
        fVar1 = *(float *)(iVar7 + 0x10);
        *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) = *(undefined4 *)(iVar7 + 0xc);
        *(float *)(*(int *)(iVar3 + 0x5a4) + 0x158) =
             fVar1 - *(float *)(*(int *)(iVar3 + 0x5a4) + 0x15c) * 1.5;
      }
    }
    uVar5 = GetAsyncKeyState(0x23);
    if ((uVar5 & 1) != 0) {
      this->i_50 = 0xffffffff;
      this->i_c4 = 1 - this->i_c4;
      FUN_00536190();
    }
    uVar5 = GetAsyncKeyState(9);
    if ((((uVar5 & 1) != 0) && (SVar6 = GetAsyncKeyState(0x12), -1 < SVar6)) &&
       (this->i_78 != 1 && -1 < this->i_78 + -1)) {
      uVar2 = this->i_70;
      uVar9 = 0;
      local_8 = 0;
      if (0 < (int)uVar2) {
        do {
          if (this->i_70 <= uVar9) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar4 = FUN_005e35a0(*(undefined4 *)(this->i_6c + uVar9 * 4));
          uVar10 = uVar9;
          if (cVar4 != '\0') {
            uVar10 = uVar2;
            local_8 = uVar9;
          }
          uVar9 = uVar10 + 1;
        } while ((int)uVar9 < (int)uVar2);
      }
      SVar6 = GetAsyncKeyState(0x10);
      local_8 = (uint)(-1 < SVar6) * 2 + -1 + local_8;
      uVar9 = uVar2 - 1;
      if (-1 < (int)local_8) {
        uVar9 = local_8;
      }
      uVar10 = 0;
      if ((int)uVar9 < (int)uVar2) {
        uVar10 = uVar9;
      }
      FUN_00501450();
      FUN_00531280();
      FUN_0040b980(0);
      if (this->i_70 <= uVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_005e3350(*(undefined4 *)(this->i_6c + uVar10 * 4));
    }
    if (this->i_80 == -1) {
      iVar7 = FUN_00501450();
      if (*(int *)(iVar7 + 0x8198) != this) {
        return;
      }
      iVar7 = FUN_00501450();
      if ((*(int *)(iVar7 + 0x81a4) != 0) &&
         (iVar7 = FUN_00501450(), *(int *)(iVar7 + 0x81a4) != this)) {
        return;
      }
    }
    else {
      iVar7 = FUN_00501450();
      if ((*(int *)(iVar7 + 0x8198) != this) ||
         ((iVar7 = FUN_00501450(), *(int *)(iVar7 + 0x81a4) != 0 &&
          (iVar7 = FUN_00501450(), *(int *)(iVar7 + 0x81a4) != this)))) {
        this->i_80 = 0xffffffff;
        FUN_00536190();
        return;
      }
      iVar7 = this->i_80;
      if ((-1 < iVar7) && (iVar7 < this->i_78)) {
        iVar7 = FUN_0041a0a0(iVar7);
        *(undefined4 *)(DAT_00772400 + 0xa0d0) = *(undefined4 *)(iVar7 + 0xc);
        return;
      }
    }
    *(undefined4 *)(DAT_00772400 + 0xa0d0) = 0xfffffffe;
  }
  return;
}

