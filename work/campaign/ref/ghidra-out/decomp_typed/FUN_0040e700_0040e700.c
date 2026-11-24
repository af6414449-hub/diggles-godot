
undefined4 FUN_0040e700(void)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int this;
  int extraout_ECX;
  uint uVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  float fVar14;
  undefined8 uVar15;
  
  if (this->c_40 == '\0') {
    iVar7 = this->i_28;
    if (((iVar7 == 0) || (*(int *)(iVar7 + 0x3ec) == 0)) ||
       (*(int *)(*(int *)(iVar7 + 0x3ec) + 4) == 0)) {
      this->c_40 = 1;
    }
    else if (((*(uint *)(iVar7 + 0x3d0) & 0x4002) != 0) ||
            ((*(uint *)(iVar7 + 0x3d0) & 0x400000) == 0)) {
      this->c_40 = 1;
      FUN_0060abd0(*(undefined4 *)(this->i_04 + 0xdc));
    }
  }
  iVar7 = this->i_54;
  if (iVar7 == -1) {
    if ((this->c_40 == '\0') &&
       (uVar10 = this->i_2c, (int)uVar10 < this->i_30)) {
      do {
        iVar7 = this->i_10;
        piVar1 = (int *)(iVar7 + 8);
        if (*(uint *)(iVar7 + 0xc) <= uVar10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar7 = this->i_10;
        }
        iVar3 = *piVar1;
        if (*(uint *)(iVar7 + 0xc) <= uVar10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar4 = *(uint *)(iVar3 + uVar10 * 8 + 4);
        uVar5 = *(uint *)(uVar10 * 8 + *(int *)(iVar7 + 8));
        iVar7 = FUN_00592f10((int)uVar5 >> 3,(int)uVar4 >> 3);
        if ((*(byte *)(((uVar4 & 7) << 3 | uVar5 & 7) + 0x3c + iVar7) & 2) == 0) {
          if ((this->i_2c != 0) &&
             (this->i_30 != *(int *)(this->i_10 + 0xc))) {
            fVar14 = this->f_38;
            uVar15 = 0x7fffffffffffffff;
            fVar12 = *(float *)(this->i_04 + 0x10);
            if (((2.0 < ABS(fVar14 - fVar12)) || (*(char *)(this->i_0c + 0x7b0) == '\0')
                ) || ((iVar7 = FUN_0060acd0(this->i_04 + 0xc,this + 0x34), iVar7 < 1 &&
                      (dVar13 = (double)(fVar12 - *(float *)(*(int *)(extraout_ECX + 0x214) + 0x10))
                      , (double)CONCAT44((uint)((ulonglong)dVar13 >> 0x20) &
                                         (uint)((ulonglong)uVar15 >> 0x20),
                                         SUB84(dVar13,0) & (uint)uVar15) <= 0.25)))) {
              iVar7 = *(int *)(*(int *)(this->i_28 + 0x3ec) + 4);
              fVar2 = *(float *)(*(int *)(iVar7 + 0x20c) + 0x10);
              if (((fVar2 <= fVar12) &&
                  ((((fVar11 = *(float *)(iVar7 + 0x230) + fVar2 + 0.5, fVar12 <= fVar11 &&
                     (fVar2 <= fVar14)) && (fVar14 <= fVar11)) &&
                   (((*(uint *)(*(int *)(iVar7 + 0x20c) + 0x3d0) & 0x404001) == 0x400001 &&
                    (*(int *)(iVar7 + 0x24) < 8)))))) ||
                 (*(char *)(this->i_0c + 0x7b0) == '\0')) {
                iVar7 = 0;
                goto LAB_0040e83a;
              }
            }
          }
          break;
        }
        uVar10 = uVar10 + 1;
      } while ((int)uVar10 < this->i_30);
    }
    iVar7 = 1;
LAB_0040e83a:
    this->i_54 = iVar7;
  }
  if (iVar7 != 0) {
    if (iVar7 != 1) {
      return 0;
    }
    uVar8 = FUN_0040e530();
    return uVar8;
  }
  if (this->c_40 == '\0') {
    iVar7 = this->i_04;
    iVar3 = *(int *)(*(int *)(this->i_28 + 0x3ec) + 4);
    fVar14 = *(float *)(*(int *)(iVar3 + 0x20c) + 0x10);
    if (((fVar14 <= *(float *)(iVar7 + 0x10)) &&
        (fVar12 = *(float *)(iVar3 + 0x230) + fVar14 + 0.5, *(float *)(iVar7 + 0x10) <= fVar12)) &&
       ((fVar14 <= this->f_38 &&
        (((this->f_38 <= fVar12 &&
          ((*(uint *)(*(int *)(iVar3 + 0x20c) + 0x3d0) & 0x404001) == 0x400001)) &&
         (*(int *)(iVar3 + 0x24) != 0x7fffffff)))))) {
      switch(this->i_50) {
      case 0:
        FUN_0040d970();
        return 1;
      case 1:
        cVar6 = (**(code **)(**(int **)(this + 0x48) + 0xc))();
        if (cVar6 == '\0') {
          if (this->i_44 != 0) {
            FUN_0040baf0(this->i_44);
          }
          this->i_44 = 0;
          if (*(undefined4 **)(this + 0x48) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(this + 0x48))(1);
          }
          this->i_48 = 0;
          this->i_50 = 2;
          return 1;
        }
        return 1;
      case 2:
        cVar6 = FUN_00608140(*(undefined4 *)(iVar7 + 0xdc),iVar7 + 0xc,this + 0x34,iVar7);
        if (cVar6 != '\0') {
          FUN_0040dc60();
          return 1;
        }
        return 1;
      case 3:
        cVar6 = (**(code **)(**(int **)(this + 0x48) + 0xc))();
        if (cVar6 != '\0') {
          return 1;
        }
        if (this->i_44 != 0) {
          FUN_0040baf0(this->i_44);
        }
        this->i_44 = 0;
        if (*(undefined4 **)(this + 0x48) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(this + 0x48))(1);
        }
        this->i_48 = 0;
        piVar1 = *(int **)(*(int *)(this->i_28 + 0x3ec) + 4);
        uVar10 = FUN_006080d0(*(undefined4 *)(this->i_04 + 0xdc));
        if ((uVar10 != 0xffffffff) && (*piVar1 == 1)) {
          if (uVar10 < 0x10) {
            piVar9 = piVar1 + uVar10 * 4 + 0x3d;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar9 = piVar1 + 0x3d;
          }
          *(undefined1 *)(piVar9 + 3) = 1;
          cVar6 = FUN_00608820();
          if ((cVar6 != '\0') && (cVar6 = FUN_006088b0(), cVar6 != '\0')) {
            *piVar1 = 2;
            piVar1[0x7e] = 10;
          }
        }
        iVar7 = *(int *)(*(int *)(this->i_28 + 0x3ec) + 4);
        uVar10 = FUN_006080d0(*(undefined4 *)(this->i_04 + 0xdc));
        if (uVar10 != 0xffffffff) {
          if (uVar10 < 0x10) {
            *(undefined1 *)(uVar10 * 0x10 + iVar7 + 0x102) = 1;
            this->i_50 = 4;
            return 1;
          }
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          *(undefined1 *)(iVar7 + 0x102) = 1;
        }
        this->i_50 = 4;
        return 1;
      case 4:
        goto switchD_0040e9f2_caseD_4;
      case 5:
        cVar6 = (**(code **)(**(int **)(this + 0x48) + 0xc))();
        if (cVar6 == '\0') {
          if (this->i_44 != 0) {
            FUN_0040baf0(this->i_44);
          }
          this->i_44 = 0;
          if (*(undefined4 **)(this + 0x48) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(this + 0x48))(1);
          }
          this->i_48 = 0;
          FUN_0040e1f0();
          return 1;
        }
        return 1;
      case 6:
        if (this->c_58 == '\0') {
          cVar6 = (**(code **)(**(int **)(this + 0x48) + 0xc))();
          if (cVar6 != '\0') {
            return 1;
          }
          if (this->i_44 != 0) {
            FUN_0040baf0(this->i_44);
          }
          this->i_44 = 0;
          if (*(undefined4 **)(this + 0x48) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(this + 0x48))(1);
          }
          this->i_48 = 0;
        }
        this->i_50 = 7;
        FUN_0060abd0(*(undefined4 *)(this->i_04 + 0xdc));
        this->i_08 = 4;
        return 0;
      default:
        return 0;
      }
    }
    FUN_0060abd0(*(undefined4 *)(iVar7 + 0xdc));
    this->c_40 = 1;
  }
  this->i_54 = 1;
  return 1;
switchD_0040e9f2_caseD_4:
  uVar10 = FUN_006080d0(*(undefined4 *)(iVar7 + 0xdc));
  if (uVar10 == 0xffffffff) {
    return 1;
  }
  if (uVar10 < 0x10) {
    iVar7 = uVar10 * 0x10 + iVar3 + 0xf4;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar7 = iVar3 + 0xf4;
  }
  if (*(float *)(iVar7 + 8) == *(float *)(iVar3 + 0x14)) {
    if (*(float *)(iVar3 + 0x22c) == 0.0) {
      FUN_0040df10();
      return 1;
    }
    return 1;
  }
  return 1;
}

