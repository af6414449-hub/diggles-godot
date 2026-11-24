
void FUN_00529570(void)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  int this;
  int iVar4;
  int *piVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined1 auStack_1c [24];
  
  if (*(int **)(this + 0xdc) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0xdc) + 0x28))();
  }
  FUN_0052f620(0);
  iVar6 = DAT_00772400;
  iVar1 = *(int *)(DAT_00772400 + 0x5a4);
  if ((this->f_90 == 0.0) && (this->f_94 == 0.0)) goto LAB_00529b72;
  fVar9 = *(float *)(iVar1 + 0x154);
  fVar10 = *(float *)(iVar1 + 0x158);
  uStack_28 = 0;
  fVar12 = (*(float *)(iVar1 + 0x15c) - 1.0) * *(float *)(DAT_00772400 + 0x198) * 0.2 + 1.0;
  fVar11 = *(float *)(DAT_0076a338 + 0x2770) * fVar10 + *(float *)(DAT_0076a338 + 0x2760) * fVar9 +
           *(float *)(DAT_0076a338 + 0x2780) * 0.0 + *(float *)(DAT_0076a338 + 0x2790);
  uStack_30 = CONCAT44(this->f_94 * 50.0 * fVar12 +
                       (*(float *)(DAT_0076a338 + 0x2768) * fVar10 +
                        *(float *)(DAT_0076a338 + 0x2758) * fVar9 +
                        *(float *)(DAT_0076a338 + 0x2778) * 0.0 + *(float *)(DAT_0076a338 + 0x2788))
                       / fVar11,this->f_90 * 50.0 * fVar12 +
                                (*(float *)(DAT_0076a338 + 0x2764) * fVar10 +
                                 fVar9 * *(float *)(DAT_0076a338 + 0x2754) +
                                 *(float *)(DAT_0076a338 + 0x2774) * 0.0 +
                                *(float *)(DAT_0076a338 + 0x2784)) / fVar11);
  pfVar3 = (float *)FUN_00479150(auStack_1c,&uStack_30);
  fVar10 = *pfVar3;
  fVar11 = pfVar3[1];
  iVar4 = iVar6 + 0xa328;
  if (this->i_44 < 8) {
    iVar4 = this->i_44 * 0x10 + iVar4;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    fVar9 = *(float *)(iVar1 + 0x154);
    iVar6 = DAT_00772400;
  }
  uStack_30 = 0x7fffffffffffffff;
  if ((float)(*(int *)(iVar4 + 8) + 1) <= fVar9) {
LAB_00529892:
    uVar2 = this->i_44;
    iVar4 = iVar6 + 0xa328;
    if (uVar2 < 8) {
      iVar4 = uVar2 * 0x10 + iVar4;
      piVar5 = (int *)(iVar6 + 0xa328 + uVar2 * 0x10);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar5 = (int *)(DAT_00772400 + 0xa328);
      if (this->i_44 < 8) {
        piVar5 = piVar5 + this->i_44 * 4;
        iVar6 = DAT_00772400;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = DAT_00772400;
      }
    }
    fVar9 = (float)((*(int *)(iVar4 + 8) + *piVar5) / 2);
    dVar8 = (double)(fVar9 - fVar10);
    dVar7 = (double)(fVar9 - *(float *)(iVar1 + 0x154));
    if ((double)CONCAT44((uint)((ulonglong)dVar8 >> 0x20) & uStack_30._4_4_,
                         SUB84(dVar8,0) & (uint)uStack_30) <
        (double)CONCAT44((uint)((ulonglong)dVar7 >> 0x20) & uStack_30._4_4_,
                         SUB84(dVar7,0) & (uint)uStack_30)) {
      *(float *)(iVar1 + 0x154) = fVar10;
    }
  }
  else {
    piVar5 = (int *)(iVar6 + 0xa328);
    if (this->i_44 < 8) {
      piVar5 = piVar5 + this->i_44 * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      fVar9 = *(float *)(iVar1 + 0x154);
      iVar6 = DAT_00772400;
    }
    if (fVar9 < (float)(*piVar5 + -1)) goto LAB_00529892;
    iVar4 = iVar6 + 0xa328;
    if (this->i_44 < 8) {
      iVar4 = this->i_44 * 0x10 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar6 = DAT_00772400;
    }
    if (fVar10 < (float)(*(int *)(iVar4 + 8) + 1)) {
      piVar5 = (int *)(iVar6 + 0xa328);
      if (this->i_44 < 8) {
        piVar5 = piVar5 + this->i_44 * 4;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = DAT_00772400;
      }
      if ((float)(*piVar5 + -1) <= fVar10) {
        *(float *)(iVar1 + 0x154) = fVar10;
      }
    }
  }
  iVar4 = iVar6 + 0xa328;
  if (this->i_44 < 8) {
    iVar4 = this->i_44 * 0x10 + iVar4;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar6 = DAT_00772400;
  }
  fVar10 = *(float *)(iVar1 + 0x158);
  if (fVar10 < (float)(*(int *)(iVar4 + 0xc) + 1)) {
    iVar4 = iVar6 + 0xa328;
    if (this->i_44 < 8) {
      iVar4 = this->i_44 * 0x10 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      fVar10 = *(float *)(iVar1 + 0x158);
      iVar6 = DAT_00772400;
    }
    if ((float)(*(int *)(iVar4 + 4) + -1) <= fVar10) {
      iVar4 = iVar6 + 0xa328;
      if (this->i_44 < 8) {
        iVar4 = this->i_44 * 0x10 + iVar4;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = DAT_00772400;
      }
      if (fVar11 < (float)(*(int *)(iVar4 + 0xc) + 1)) {
        iVar6 = iVar6 + 0xa328;
        if (this->i_44 < 8) {
          iVar6 = this->i_44 * 0x10 + iVar6;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((float)(*(int *)(iVar6 + 4) + -1) <= fVar11) {
          *(float *)(iVar1 + 0x158) = fVar11;
        }
      }
      goto LAB_00529b72;
    }
  }
  uVar2 = this->i_44;
  iVar4 = iVar6 + 0xa328;
  if (uVar2 < 8) {
    iVar4 = uVar2 * 0x10 + iVar4;
    iVar6 = iVar6 + 0xa328 + uVar2 * 0x10;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar6 = DAT_00772400 + 0xa328;
    if (this->i_44 < 8) {
      iVar6 = iVar6 + this->i_44 * 0x10;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  fVar10 = (float)((*(int *)(iVar6 + 0xc) + *(int *)(iVar4 + 4)) / 2);
  dVar8 = (double)(fVar10 - fVar11);
  dVar7 = (double)(fVar10 - *(float *)(iVar1 + 0x158));
  if ((double)CONCAT44((uint)((ulonglong)dVar8 >> 0x20) & uStack_30._4_4_,
                       SUB84(dVar8,0) & (uint)uStack_30) <
      (double)CONCAT44((uint)((ulonglong)dVar7 >> 0x20) & uStack_30._4_4_,
                       SUB84(dVar7,0) & (uint)uStack_30)) {
    *(float *)(iVar1 + 0x158) = fVar11;
  }
LAB_00529b72:
  fVar10 = this->f_9c;
  if ((fVar10 != 0.0) || (this->f_a0 != 0.0)) {
    *(float *)(iVar1 + 0x160) = *(float *)(iVar1 + 0x160) - this->f_a0 * 0.005;
    *(float *)(iVar1 + 0x164) = fVar10 * 0.005 + *(float *)(iVar1 + 0x164);
  }
  if (this->f_a8 != 1.0) {
    *(float *)(iVar1 + 0x15c) = *(float *)(iVar1 + 0x15c) * this->f_a8;
  }
  return;
}

