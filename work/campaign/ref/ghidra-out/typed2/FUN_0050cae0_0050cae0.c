
void __thiscall FUN_0050cae0(ViWinClock *this)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  char cVar7;
  float10 fVar8;
  float fVar9;
  double dVar10;
  float fVar11;
  double dVar12;
  char cStack_41;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  undefined8 local_28;
  float local_1c;
  undefined8 local_18;
  undefined4 local_10;
  
  if (*(char *)(DAT_00772400 + 0x8a) == '\0') {
    return;
  }
  if (*(char *)(DAT_00772400 + 0x5c0) == '\0') {
    return;
  }
  iVar3 = FUN_00501450();
  if (((*(ViWinClock **)(iVar3 + 0x8198) != this) ||
      ((iVar3 = FUN_00501450(), *(int *)(iVar3 + 0x81a4) != 0 &&
       (iVar3 = FUN_00501450(), *(ViWinClock **)(iVar3 + 0x81a4) != this)))) && (this->c_6c != '\0')
     ) {
    this->c_6c = '\0';
    FUN_00504ee0();
  }
  iVar3 = DAT_00772400;
  local_1c = (float)*(double *)(DAT_00772400 + 0xa088) / 150.0;
  if (this->c_54 != '\0') {
    local_10 = 0;
    fVar9 = (float)this->i_10 + this->f_5c;
    local_18 = (double)CONCAT44((float)*(int *)(DAT_00772400 + 0x1c4) - fVar9,
                                (float)*(int *)(DAT_00772400 + 0x1c0) -
                                ((float)this->i_0c + this->f_58));
    FUN_0040b700();
    fVar9 = ((fVar9 + 1.5707964) * 0.5) / 3.1415927;
    if (fVar9 < 0.0) {
      fVar9 = fVar9 + 1.0;
    }
    fVar9 = (float)(int)(fVar9 * 12.0 - 0.49) / 12.0;
    local_34 = this->f_4c - fVar9;
    local_28 = (double)CONCAT44(local_28._4_4_,fVar9);
    if (local_34 < 0.0) {
      local_34 = local_34 + 1.0;
    }
    if (0 < *(int *)(iVar3 + 0xa0c8)) {
      iVar3 = 0;
      do {
        iVar4 = FUN_005e3690(iVar3);
        if ((iVar4 != 0) && ((*(int *)(iVar4 + 0xe8) == 1 || (*(int *)(iVar4 + 0xe8) == 0xb)))) {
          *(float *)(iVar4 + 0x354) = (float)(int *)local_28 * 12.0;
          *(float *)(iVar4 + 0x358) = local_34 * 12.0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(DAT_00772400 + 0xa0c8));
    }
    FUN_00504ee0();
  }
  iVar3 = DAT_00772400;
  if (this->c_55 != '\0') {
    local_10 = 0;
    fVar9 = this->f_48;
    local_18 = (double)CONCAT44((float)*(int *)(DAT_00772400 + 0x1c4) -
                                ((float)this->i_10 + this->f_5c),
                                (float)*(int *)(DAT_00772400 + 0x1c0) -
                                ((float)this->i_0c + this->f_58));
    fVar11 = fVar9;
    FUN_0040b700();
    fVar11 = ((fVar11 + 1.5707964) * 0.5) / 3.1415927 - fVar9;
    if (fVar11 < 0.0) {
      fVar11 = fVar11 + 1.0;
    }
    local_28 = (double)CONCAT44(local_28._4_4_,(float)(int)(fVar11 * 24.0 - 0.49) / 24.0);
    if (0 < *(int *)(iVar3 + 0xa0c8)) {
      iVar3 = 0;
      do {
        iVar4 = FUN_005e3690(iVar3);
        if ((iVar4 != 0) && ((*(int *)(iVar4 + 0xe8) == 1 || (*(int *)(iVar4 + 0xe8) == 0xb)))) {
          *(float *)(iVar4 + 0x358) = (float)(int *)local_28 * 12.0;
          *(float *)(iVar4 + 0x354) = fVar9 * 12.0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(DAT_00772400 + 0xa0c8));
    }
    FUN_00504ee0();
  }
  if (0.05 < ABS(local_1c - this->f_50)) {
    this->f_50 = local_1c;
    FUN_00504ee0();
  }
  local_38 = 0;
  bVar2 = 0 < *(int *)(DAT_00772400 + 0xa0c8);
  iVar3 = DAT_00772400;
  if (0 < *(int *)(DAT_00772400 + 0xa0c8)) {
    local_28 = (double)CONCAT44(local_28._4_4_,(undefined4 *)(DAT_00772400 + 0xa0c4));
    if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
      local_38 = 0;
LAB_0050ce6c:
      fVar9 = -1.0;
      local_40 = -1.0;
      iVar3 = DAT_00772400;
    }
    else {
      uVar1 = **(uint **)(DAT_00772400 + 0xa0c4);
      local_28 = (double)CONCAT44(local_28._4_4_,DAT_0077244c + 0x488);
      if (uVar1 < 0x2000) {
        piVar5 = (int *)(DAT_0077244c + 0x488 + uVar1 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar5 = (int *)local_28;
      }
      iVar3 = DAT_00772400;
      local_38 = *piVar5;
      if (local_38 == 0) goto LAB_0050ce6c;
      local_18 = (double)*(float *)(local_38 + 0x354);
      fVar8 = (float10)FUN_006f52b0();
      local_40 = (float)fVar8 / 12.0;
      local_18 = (double)*(float *)(local_38 + 0x358);
      fVar8 = (float10)FUN_006f52b0();
      local_18 = (double)fVar8;
      fVar9 = (float)fVar8 / 12.0;
    }
    local_3c = 0.0;
    if (0 < *(int *)(iVar3 + 0xa0c8)) {
      do {
        local_28 = (double)CONCAT44(local_28._4_4_,iVar3 + 0xa0c4);
        if (((int)local_3c < 0) || ((int)*(uint *)(iVar3 + 0xa0c8) <= (int)local_3c)) {
LAB_0050d0e0:
          local_3c = 0.0;
          bVar2 = false;
          local_40 = 0.0;
          goto LAB_0050d0ee;
        }
        if (*(uint *)(iVar3 + 0xa0c8) <= (uint)local_3c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = DAT_00772400;
        }
        uVar1 = *(uint *)(*(int *)local_28 + (int)local_3c * 4);
        piVar5 = (int *)(DAT_0077244c + 0x488);
        if (uVar1 < 0x2000) {
          piVar5 = piVar5 + uVar1;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = DAT_00772400;
        }
        iVar4 = *piVar5;
        if ((iVar4 == 0) || ((*(int *)(iVar4 + 0xe8) != 1 && (*(int *)(iVar4 + 0xe8) != 0xb))))
        goto LAB_0050d0e0;
        local_18 = (double)*(float *)(iVar4 + 0x354);
        fVar8 = (float10)FUN_006f52b0();
        local_18 = (double)fVar8;
        if (0.01 < ABS((float)fVar8 / 12.0 - local_40)) goto LAB_0050d0e0;
        local_18 = (double)*(float *)(*piVar5 + 0x358);
        fVar8 = (float10)FUN_006f52b0();
        local_18 = (double)fVar8;
        if (0.01 < ABS((float)fVar8 / 12.0 - fVar9)) goto LAB_0050d0e0;
        local_3c = (float)((int)local_3c + 1);
      } while ((int)local_3c < *(int *)(iVar3 + 0xa0c8));
    }
  }
  local_3c = 0.0;
  local_40 = 0.0;
  if (bVar2) {
    local_28 = (double)CONCAT44(local_28._4_4_,(undefined4 *)(iVar3 + 0xa0c4));
    if (*(int *)(iVar3 + 0xa0c8) < 1) {
      iVar4 = 0;
    }
    else {
      uVar1 = **(uint **)(iVar3 + 0xa0c4);
      local_28 = (double)CONCAT44(local_28._4_4_,DAT_0077244c + 0x488);
      if (uVar1 < 0x2000) {
        piVar5 = (int *)(DAT_0077244c + 0x488 + uVar1 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar5 = (int *)local_28;
        iVar3 = DAT_00772400;
      }
      iVar4 = *piVar5;
    }
    local_18 = (double)*(float *)(iVar4 + 0x354);
    fVar8 = (float10)FUN_006f52b0();
    local_40 = (float)fVar8 / 12.0;
    local_18 = (double)*(float *)(iVar4 + 0x358);
    fVar8 = (float10)FUN_006f52b0();
    local_18 = (double)fVar8;
    iVar6 = this->i_44;
    iVar4 = iVar6 + 0x20;
    if (0x60 < iVar4) {
      iVar4 = 0x60;
    }
    this->i_44 = iVar4;
    local_3c = (float)fVar8 / 12.0 + local_40;
    if (iVar6 != iVar4) {
      FUN_00504ee0();
      iVar3 = DAT_00772400;
    }
    if ((local_40 == -1.0) && (local_3c == -1.0)) goto LAB_0050d0ee;
    if (*(char *)(this->i_70 + 0x1c) != '\x01') {
      *(undefined1 *)(this->i_70 + 0x1c) = 1;
      FUN_00504ee0();
    }
    if (*(char *)(this->i_74 + 0x1c) != '\x01') {
      *(undefined1 *)(this->i_74 + 0x1c) = 1;
      FUN_00504ee0();
    }
LAB_0050d524:
    if (local_40 != -1.0) {
      for (; local_40 < 0.0; local_40 = local_40 + 1.0) {
      }
    }
    for (; 1.0 <= local_40; local_40 = local_40 - 1.0) {
    }
    if (local_3c != -1.0) {
      for (; local_3c < 0.0; local_3c = local_3c + 1.0) {
      }
    }
    for (; 1.0 <= local_3c; local_3c = local_3c - 1.0) {
    }
  }
  else {
LAB_0050d0ee:
    iVar4 = this->i_70;
    local_28 = (double)CONCAT44(local_28._4_4_,local_40);
    if (*(char *)(iVar4 + 0x1c) != '\0') {
      FUN_00504ee0();
      iVar3 = DAT_00772400;
      *(undefined1 *)(iVar4 + 0x1c) = 0;
    }
    iVar4 = this->i_74;
    if (*(char *)(iVar4 + 0x1c) != '\0') {
      FUN_00504ee0();
      iVar3 = DAT_00772400;
      *(undefined1 *)(iVar4 + 0x1c) = 0;
    }
    local_18 = (double)CONCAT44(local_18._4_4_,&this->i_70);
    local_40 = (float)(int *)local_28;
    if (bVar2) goto LAB_0050d524;
    uVar1 = *(uint *)(iVar3 + 0xa0cc);
    if (0 < (int)uVar1) {
      iVar4 = this->i_44;
      piVar5 = (int *)(DAT_0077244c + 0x488);
      local_18 = (double)CONCAT44(local_18._4_4_,iVar4);
      if (uVar1 < 0x2000) {
        piVar5 = piVar5 + uVar1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar4 = this->i_44;
        iVar3 = DAT_00772400;
      }
      local_38 = *piVar5;
      local_40 = (float)(int *)local_28;
      iVar6 = 0;
      if (-1 < iVar4 + -0x20) {
        iVar6 = iVar4 + -0x20;
      }
      this->i_44 = iVar6;
      if (local_38 != 0) {
        local_28 = (double)CONCAT44(local_28._4_4_,iVar6);
        if ((*(int *)(local_38 + 0x36c) == *(int *)(iVar3 + 100)) &&
           ((*(int *)(local_38 + 0xe8) == 1 || (*(int *)(local_38 + 0xe8) == 0xb)))) {
          local_28 = (double)*(float *)(local_38 + 0x354);
          fVar8 = (float10)FUN_006f52b0();
          local_40 = (float)fVar8 / 12.0;
          local_28 = (double)*(float *)(local_38 + 0x358);
          fVar8 = (float10)FUN_006f52b0();
          local_28 = (double)fVar8;
          iVar6 = iVar6 + 0x20;
          bVar2 = true;
          if (0x60 < iVar6) {
            iVar6 = 0x60;
          }
          iVar6 = iVar6 + 0x20;
          this->i_44 = iVar6;
          local_3c = (float)fVar8 / 12.0 + local_40;
        }
      }
      if ((int)local_18 != iVar6) {
        FUN_00504ee0();
      }
      if (bVar2) goto LAB_0050d524;
    }
    iVar3 = this->i_44;
    local_18 = (double)CONCAT44(local_18._4_4_,iVar3);
    if (iVar3 != 0) {
      local_40 = this->f_48;
      local_3c = this->f_4c;
      iVar4 = 0;
      if (-1 < iVar3 + -0x20) {
        iVar4 = iVar3 + -0x20;
      }
      this->i_44 = iVar4;
      if (iVar3 != iVar4) {
        FUN_00504ee0();
      }
      goto LAB_0050d524;
    }
    local_40 = -1.0;
    local_3c = -1.0;
    this->c_54 = '\0';
    this->c_55 = '\0';
  }
  if ((this->f_4c != local_3c) || (this->f_48 != local_40)) {
    dVar12 = (double)((local_40 + local_40) * 3.1415927 - 1.5707964);
    local_18 = (double)(this->f_60 + 10.0);
    dVar10 = dVar12;
    FUN_006f5ae0();
    local_28 = (double)CONCAT44(local_28._4_4_,(int)this->f_58 + (int)(dVar10 * local_18) + -0xe);
    FUN_006f6ad0();
    local_28._4_4_ = (int)this->f_5c + (int)(dVar12 * local_18) + -0xe;
    FUN_00504a70(&local_28);
    dVar12 = (double)((local_3c + local_3c) * 3.1415927 - 1.5707964);
    local_18 = (double)(this->f_60 + 10.0);
    dVar10 = dVar12;
    FUN_006f5ae0();
    local_28 = (double)CONCAT44(local_28._4_4_,(int)this->f_58 + (int)(dVar10 * local_18) + -0xe);
    FUN_006f6ad0();
    local_28 = (double)CONCAT44((int)this->f_5c + (int)(dVar12 * local_18) + -0xe,(int *)local_28);
    FUN_00504a70(&local_28);
    this->f_50 = local_1c;
    FUN_00504ee0();
  }
  cVar7 = '\0';
  bVar2 = false;
  this->f_48 = local_40;
  this->f_4c = local_3c;
  cStack_41 = '\0';
  if ((local_38 != 0) && ((*(int *)(local_38 + 0x3e4) != 0 || (*(int *)(local_38 + 0x3e0) != 0)))) {
    bVar2 = true;
    cVar7 = '\x01';
    cStack_41 = '\x01';
    if ((*(uint *)(local_38 + 0x3d0) & 0x800000) != 0) {
      iVar3 = this->i_e8;
      cVar7 = '\0';
      cStack_41 = '\0';
      goto LAB_0050d74e;
    }
  }
  iVar3 = this->i_e8;
  if (!bVar2) {
    if (*(char *)(iVar3 + 0x1c) == '\0') {
      return;
    }
    FUN_00504ee0();
    *(undefined1 *)(iVar3 + 0x1c) = 0;
    return;
  }
LAB_0050d74e:
  if (*(char *)(iVar3 + 0x1c) != '\x01') {
    *(undefined1 *)(iVar3 + 0x1c) = 1;
    FUN_00504ee0();
    cVar7 = cStack_41;
  }
  if (cVar7 == this->c_a8) {
    return;
  }
  this->c_a8 = cVar7;
  if (cVar7 != '\0') {
    FUN_00507d40("data/gui/icons/AutoProd_On");
    return;
  }
  FUN_00507d40("data/gui/icons/AutoProd_Off");
  return;
}

