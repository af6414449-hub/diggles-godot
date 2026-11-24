
undefined1 FUN_00519800(undefined4 *param_1)

{
  float *pfVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int this;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = DAT_00772378;
  puStack_c = &LAB_00701e55;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar5 = param_1[2];
  if (iVar5 == DAT_007723c8) {
    piVar7 = (int *)0x0;
    local_14 = (int *)0x0;
    local_8 = 1;
    uVar3 = this->i_80;
    if ((int)uVar3 < 0) {
      iVar5 = this->i_78;
      uVar3 = 0;
      if (0 < iVar5) {
        do {
          if (this->i_78 <= uVar3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_14 = (int *)FUN_00519e20(*(undefined4 *)(this->i_74 + uVar3 * 8));
          piVar8 = piVar7;
          if (local_14 != (int *)0x0) {
            if (this->i_78 <= uVar3) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar4 = this->i_7c;
            iVar10 = this->i_74;
            pfVar1 = (float *)(iVar10 + 4 + uVar3 * 8);
            if (*pfVar1 <= (float)iVar4 && (float)iVar4 != *pfVar1) {
              if (this->i_78 <= uVar3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar4 = this->i_7c;
                iVar10 = this->i_74;
              }
              if ((float)iVar4 < (float)local_14[3] + *(float *)(iVar10 + 4 + uVar3 * 8)) {
                piVar8 = (int *)local_14[10];
                if (piVar8 != (int *)0x0) {
                  *piVar8 = *piVar8 + 1;
                }
                if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
                  TclFreeObj(piVar7);
                }
              }
            }
          }
          uVar3 = uVar3 + 1;
          piVar7 = piVar8;
        } while ((int)uVar3 < iVar5);
LAB_0051996a:
        local_14 = piVar8;
        if (piVar8 != (int *)0x0) {
          FUN_0054eb50(&local_14);
          *piVar8 = *piVar8 + -1;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
            uVar2 = 1;
            goto LAB_00519b9c;
          }
        }
      }
    }
    else if ((int)uVar3 < (int)this->i_64) {
      if (this->i_64 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar8 = *(int **)(this->i_60 + 8 + uVar3 * 0x14);
      local_14 = piVar8;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
        goto LAB_0051996a;
      }
    }
  }
  else {
    if (iVar5 == DAT_007723d0) {
      iVar5 = this->i_80;
      if (iVar5 < 0) {
        local_14 = *(int **)(this + 0x78);
        uVar9 = 0;
        if (0 < (int)local_14) {
          do {
            if (this->i_78 <= uVar9) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar5 = FUN_00519e20(*(undefined4 *)(this->i_74 + uVar9 * 8));
            if (iVar5 != 0) {
              if (this->i_78 <= uVar9) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar4 = this->i_7c;
              iVar10 = this->i_74;
              pfVar1 = (float *)(iVar10 + 4 + uVar9 * 8);
              if (*pfVar1 <= (float)iVar4 && (float)iVar4 != *pfVar1) {
                if (this->i_78 <= uVar9) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar4 = this->i_7c;
                  iVar10 = this->i_74;
                }
                if ((float)iVar4 < (float)*(int *)(iVar5 + 0xc) + *(float *)(iVar10 + 4 + uVar9 * 8)
                   ) {
                  if (this->i_78 <= uVar9) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar10 = this->i_74;
                  }
                  FUN_0051a1c0(*(undefined4 *)(iVar10 + uVar9 * 8));
                  break;
                }
              }
            }
            uVar9 = uVar9 + 1;
          } while ((int)uVar9 < (int)local_14);
        }
      }
      else if (iVar5 < this->i_64) {
        FUN_0051bbd0(iVar5);
        FUN_00504ee0();
      }
      this->i_80 = 0xffffffff;
      this->i_7c = 0xffffffff;
      FUN_00504ee0(uVar3);
      uVar2 = 1;
      goto LAB_00519b9c;
    }
    if ((iVar5 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = *(int **)(iVar4 + 8);
    }
    else {
      piVar7 = (int *)(*(int *)(DAT_00772378 + 8) + iVar5 * 4);
    }
    if (*(int *)(*piVar7 + 8) != 0) {
      if (param_1[2] == DAT_007723e0) {
        this->i_7c = 0xffffffff;
        this->i_80 = 0xffffffff;
        FUN_00504ee0(uVar3);
      }
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        param_1[1] = param_1[1] + 1;
        UNLOCK();
      }
      uVar2 = FUN_00505d60(param_1);
      goto LAB_00519b9c;
    }
    iVar5 = this->i_7c;
    iVar4 = this->i_80;
    iVar10 = param_1[9];
    if (iVar10 < this->i_50 - this->i_54) {
      this->i_7c = iVar10;
      if (param_1[10] + -0x19 < 0) goto LAB_00519b40;
      iVar6 = (param_1[10] + -0x19) / 0x14;
      this->i_80 = iVar6;
      if ((iVar6 < 0) || (8 < iVar6)) goto LAB_00519b40;
    }
    else {
      this->i_7c = 0xffffffff;
      iVar10 = -1;
LAB_00519b40:
      iVar6 = -1;
      this->i_80 = 0xffffffff;
    }
    if ((iVar5 != iVar10) || (iVar4 != iVar6)) {
      FUN_00504ee0(uVar3);
    }
  }
  uVar2 = 1;
LAB_00519b9c:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = param_1[1] + -1;
    param_1[1] = iVar5;
    UNLOCK();
    if ((iVar5 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

