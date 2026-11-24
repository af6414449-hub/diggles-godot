
void __thiscall FUN_0050f990(ViWinFinder *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 local_10;
  int local_c;
  
  uVar6 = **(uint **)&this->field_0x50;
  if ((uVar6 & 3) != 0) {
    FUN_0050f2d0();
    uVar6 = **(uint **)&this->field_0x50;
  }
  if (uVar6 != 0) {
    FUN_00504ee0();
    **(undefined4 **)&this->field_0x50 = 0;
  }
  uVar6 = 0;
  iVar1 = *(int *)(this->i_44 + 0x50);
  if (0 < iVar1) {
    do {
      iVar2 = this->i_44;
      if (*(uint *)(iVar2 + 0x50) <= uVar6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar2 = *(int *)(*(int *)(iVar2 + 0x4c) + uVar6 * 4);
      if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
        iVar3 = 0;
      }
      else {
        piVar7 = (int *)(DAT_0077244c + 0x488);
        if (**(uint **)(DAT_00772400 + 0xa0c4) < 0x2000) {
          piVar7 = piVar7 + **(uint **)(DAT_00772400 + 0xa0c4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar3 = *piVar7;
      }
      if ((*(int *)(iVar2 + 0x48) == iVar3) && (this->i_58 != uVar6)) {
        if ((this->c_54 == '\0') || (this->c_4c != '\0')) {
          iVar2 = uVar6 - 4;
          iVar3 = *(int *)(this->i_44 + 0x48);
          local_10 = *(undefined4 *)(iVar3 + 100);
          iVar4 = 0;
          if (-1 < iVar2) {
            iVar4 = iVar2;
          }
          iVar5 = iVar1 + -4;
          if ((iVar4 <= iVar1 + -4) && (iVar5 = iVar2, iVar2 < 0)) {
            iVar5 = 0;
          }
          local_c = (int)(((float)*(int *)(iVar3 + 0x78) / (float)(iVar1 + -9)) * (float)iVar5);
          FUN_00538b40(&local_10,1);
        }
        this->c_54 = '\0';
        this->i_58 = uVar6;
        return;
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < iVar1);
  }
  return;
}

