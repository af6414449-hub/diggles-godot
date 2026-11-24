
undefined4 __thiscall FUN_00412150(CAct_Ladder *this)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int local_14;
  
  if (this->c_4c == '\0') {
    iVar6 = this->i_5c;
    if (((iVar6 == 0) || (*(int *)(iVar6 + 0x3ec) == 0)) ||
       (*(int *)(*(int *)(iVar6 + 0x3ec) + 8) == 0)) {
      this->c_4c = '\x01';
    }
    else if (((*(uint *)(iVar6 + 0x3d0) & 0x4002) != 0) ||
            ((*(uint *)(iVar6 + 0x3d0) & 0x400000) == 0)) {
      this->c_4c = '\x01';
      FUN_0060c2b0(*(undefined4 *)(this->i_04 + 0xdc));
    }
  }
  iVar6 = this->i_3c;
  pcVar8 = RaiseException_exref;
  if (iVar6 == -1) {
    if (this->c_4c == '\0') {
      uVar10 = this->i_54;
      if ((((int)(uVar10 + 2) < this->i_58) &&
          (iVar6 = this->i_04, 1.0 <= ABS(*(float *)(iVar6 + 0x10) - this->f_34))) &&
         ((fVar14 = *(float *)(iVar6 + 0x10) - this->f_34,
          fVar13 = *(float *)(iVar6 + 0xc) - this->f_30,
          fVar12 = *(float *)(iVar6 + 0x14) - this->f_38,
          1.0 <= fVar14 * fVar14 + fVar13 * fVar13 + fVar12 * fVar12 && ((int)uVar10 < this->i_58)))
         ) {
        do {
          iVar6 = this->i_10;
          piVar1 = (int *)(iVar6 + 8);
          if (*(uint *)(iVar6 + 0xc) <= uVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = this->i_10;
          }
          iVar2 = *piVar1;
          if (*(uint *)(iVar6 + 0xc) <= uVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar3 = *(uint *)(iVar2 + uVar10 * 8 + 4);
          uVar4 = *(uint *)(uVar10 * 8 + *(int *)(iVar6 + 8));
          iVar6 = FUN_00592f10((int)uVar4 >> 3,(int)uVar3 >> 3);
          if ((*(byte *)(((uVar3 & 7) << 3 | uVar4 & 7) + 0x3c + iVar6) & 2) == 0) {
            iVar6 = 0;
            goto LAB_00412314;
          }
          uVar10 = uVar10 + 1;
        } while ((int)uVar10 < this->i_58);
      }
    }
    iVar6 = 1;
LAB_00412314:
    pcVar8 = RaiseException_exref;
    this->i_3c = iVar6;
  }
  if (iVar6 != 0) {
    if (iVar6 != 1) {
      return 0;
    }
    uVar7 = FUN_00411f70();
    return uVar7;
  }
  if (this->c_4c == '\0') {
    switch(this->i_50) {
    case 0:
      FUN_004111b0();
      return 1;
    case 1:
      cVar5 = (**(code **)(*(int *)this->i_48 + 0xc))();
      if (cVar5 == '\0') {
        if (this->i_40 != 0) {
          FUN_0040baf0(this->i_40);
        }
        this->i_40 = 0;
        if ((undefined4 *)this->i_48 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)this->i_48)(1);
        }
        this->i_50 = 2;
        this->i_48 = 0;
        return 1;
      }
      break;
    case 2:
      FUN_00411590();
      return 1;
    case 3:
      cVar5 = (**(code **)(*(int *)this->i_48 + 0xc))();
      if (cVar5 == '\0') {
        if (this->i_40 != 0) {
          FUN_0040baf0(this->i_40);
        }
        this->i_40 = 0;
        if ((undefined4 *)this->i_48 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)this->i_48)(1);
        }
        iVar6 = this->i_0c;
        this->i_48 = 0;
        if (iVar6 != 0) {
          LOCK();
          *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + 1;
          UNLOCK();
        }
        FUN_0060c3c0(*(undefined4 *)(this->i_04 + 0xdc),iVar6);
        this->i_50 = 4;
        return 1;
      }
      break;
    case 4:
      uVar10 = 0;
      fVar12 = this->f_34;
      iVar6 = *(int *)(this->i_04 + 0xdc);
      iVar2 = *(int *)(*(int *)(this->i_5c + 0x3ec) + 8);
      if (0 < *(int *)(iVar2 + 0x14)) {
        bVar11 = *(int *)(iVar2 + 0x14) != 0;
        local_14 = 0;
        while( true ) {
          if (!bVar11) {
            (*pcVar8)(0xc000008c,1,0,0);
          }
          iVar9 = *(int *)(iVar2 + 0x10);
          if (*(int *)(iVar9 + local_14) == iVar6) break;
          uVar10 = uVar10 + 1;
          local_14 = local_14 + 0x14;
          bVar11 = uVar10 < *(uint *)(iVar2 + 0x14);
          pcVar8 = RaiseException_exref;
          if ((int)*(uint *)(iVar2 + 0x14) <= (int)uVar10) {
            return 1;
          }
        }
        if (*(uint *)(iVar2 + 0x14) <= uVar10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar9 = *(int *)(iVar2 + 0x10);
        }
        if (fVar12 == *(float *)(iVar9 + 4 + uVar10 * 0x14)) {
          FUN_00411870();
          return 1;
        }
      }
      break;
    case 5:
      cVar5 = (**(code **)(*(int *)this->i_48 + 0xc))();
      if (cVar5 == '\0') {
        if (this->i_40 != 0) {
          FUN_0040baf0(this->i_40);
        }
        this->i_40 = 0;
        if ((undefined4 *)this->i_48 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)this->i_48)(1);
        }
        this->i_48 = 0;
        FUN_00411c90();
        return 1;
      }
      break;
    case 6:
      cVar5 = (**(code **)(*(int *)this->i_48 + 0xc))();
      if (cVar5 == '\0') {
        if (this->i_40 != 0) {
          FUN_0040baf0(this->i_40);
        }
        this->i_40 = 0;
        if ((undefined4 *)this->i_48 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)this->i_48)(1);
        }
        this->i_48 = 0;
        FUN_0060c2b0(*(undefined4 *)(this->i_04 + 0xdc));
        this->i_08 = 4;
        return 0;
      }
      break;
    default:
      return 0;
    }
  }
  else {
    this->i_3c = 1;
    if ((undefined4 *)this->i_48 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)this->i_48)(1);
      this->i_48 = 0;
    }
  }
  return 1;
}

