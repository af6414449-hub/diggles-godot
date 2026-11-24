
undefined4 __thiscall FUN_0040afe0(CAct_AttackBallistic *this)

{
  double dVar1;
  void *lp;
  char cVar2;
  BOOL BVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  lp = (void *)this->i_1c;
  if (((((lp != (void *)0x0) && (BVar3 = IsBadReadPtr(lp,0x10), BVar3 == 0)) &&
       (*(int *)((int)lp + 8) == 0x616e4f62)) &&
      ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) &&
     ((dVar1 = *(double *)(DAT_00772400 + 0xa088), dVar1 < this->d_60 || dVar1 == this->d_60 ||
      (this->i_38 != 0)))) {
    this->i_3c = this->i_3c + 1;
    uVar8 = 0;
    if (0 < this->i_28) {
      bVar9 = this->i_28 != 0;
      do {
        if (!bVar9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar6 = this->i_24;
        if (0 < *(int *)(iVar6 + uVar8 * 4)) {
          if ((uint)this->i_28 <= uVar8) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = this->i_24;
          }
          if ((double)*(int *)(iVar6 + uVar8 * 4) <= dVar1 * 10.0) {
            iVar6 = this->i_1c;
            iVar4 = this->i_0c;
            FUN_00409830(*(float *)(iVar4 + 0xc) + 0.0,*(float *)(iVar4 + 0x10) - 0.5,
                         *(float *)(iVar4 + 0x14) + 0.0,*(float *)(iVar6 + 0xc) + 0.0,
                         *(float *)(iVar6 + 0x10) + this->f_58,*(float *)(iVar6 + 0x14) + 0.0);
            iVar6 = this->i_1c;
            this->i_48 = *(int *)(iVar6 + 0xc);
            this->i_4c = *(int *)(iVar6 + 0x10);
            this->i_50 = *(int *)(iVar6 + 0x14);
            if ((uint)this->i_28 <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(this->i_24 + uVar8 * 4) = 0xffffffff;
          }
        }
        uVar8 = uVar8 + 1;
        bVar9 = uVar8 < (uint)this->i_28;
      } while ((int)uVar8 < this->i_28);
    }
    uVar8 = 0;
    if (0 < this->i_38) {
      bVar9 = this->i_38 != 0;
      do {
        if (!bVar9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar6 = this->i_34;
        if (-1 < *(int *)(iVar6 + uVar8 * 4)) {
          if ((uint)this->i_38 <= uVar8) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = this->i_34;
          }
          iVar6 = *(int *)(uVar8 * 4 + iVar6);
          iVar4 = FUN_00492250();
          if ((iVar6 < 0) || (*(int *)(iVar4 + 0xa64) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar2 = FUN_0049dc20();
          if (cVar2 == '\0') {
            iVar6 = this->i_1c;
            fVar12 = *(float *)(iVar6 + 0x10) - (float)this->i_4c;
            fVar11 = *(float *)(iVar6 + 0xc) - (float)this->i_48;
            fVar10 = *(float *)(iVar6 + 0x14) - (float)this->i_50;
            if ((fVar12 * fVar12 + fVar11 * fVar11 + fVar10 * fVar10 < 0.25) && (this->c_54 != '\0')
               ) {
              if ((*(uint *)(iVar6 + 0x3d0) & 0x10000000) == 0) {
                if (*(int *)(iVar6 + 0x21c) == 0) {
                  iVar4 = FUN_006ba810(0x14a);
                  local_8 = 0;
                  if (iVar4 == 0) {
                    uVar5 = 0;
                  }
                  else {
                    uVar5 = FUN_005da770();
                  }
                  local_8 = 0xffffffff;
                  *(undefined4 *)(iVar6 + 0x21c) = uVar5;
                }
                FUN_005dac00("atr_Hitpoints");
              }
              FUN_005dae40("atr_Hitpoints");
              if (this->c_44 != '\0') {
                FUN_005d8660(1,5);
              }
              *(undefined4 *)(this->i_0c + 0x24c) = 1;
            }
            if ((uint)this->i_38 <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            uVar5 = *(undefined4 *)(this->i_34 + uVar8 * 4);
            FUN_00492250(uVar5);
            FUN_00495750(uVar5);
            uVar7 = this->i_38;
            if (uVar7 <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar7 = this->i_38;
              if (uVar7 <= uVar8) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar7 = this->i_38;
              }
            }
            if ((int)uVar8 < (int)(uVar7 - 1)) {
              iVar6 = uVar8 * 4 + this->i_34;
              FUN_006d1b90(iVar6,iVar6 + 4,(uVar7 - uVar8) * 4 + -4);
              uVar7 = this->i_38;
            }
            uVar8 = uVar8 - 1;
            this->i_38 = uVar7 - 1;
          }
        }
        uVar8 = uVar8 + 1;
        bVar9 = uVar8 < (uint)this->i_38;
      } while ((int)uVar8 < this->i_38);
    }
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

