
undefined1 __thiscall FUN_00534d80(ViWinSimpleFinder *this)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined1 uVar9;
  undefined4 *in_stack_00000004;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  iVar7 = DAT_00772378;
  puStack_c = &LAB_00702f6d;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  bVar2 = false;
  iVar5 = in_stack_00000004[2];
  if ((iVar5 < 0) || (*(int *)(DAT_00772378 + 0xc) <= iVar5)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = *(int **)(iVar7 + 8);
  }
  else {
    piVar6 = (int *)(*(int *)(DAT_00772378 + 8) + iVar5 * 4);
  }
  if (*(int *)(*piVar6 + 8) == 0) {
    iVar5 = this->i_80;
    if (in_stack_00000004[10] + -6 < 0) {
      iVar7 = -1;
    }
    else {
      iVar7 = (in_stack_00000004[10] + -6) / 0x12;
    }
    this->i_80 = iVar7;
    if (((((int)in_stack_00000004[9] < 0) || (200 < (int)in_stack_00000004[9])) || (iVar7 < 0)) ||
       (this->i_78 <= iVar7)) {
LAB_00534e4e:
      this->i_80 = -1;
      iVar7 = -1;
    }
    else {
      iVar7 = FUN_0041a0a0(iVar7);
      if (*(int *)(iVar7 + 0xc) == -1) goto LAB_00534e4e;
      iVar7 = this->i_80;
    }
    if (iVar5 != iVar7) {
      bVar2 = true;
    }
  }
  if (in_stack_00000004[2] == DAT_007723b8) {
    if (this->i_60 == 0) {
      FUN_006b8fb0("Grenzstein");
      iVar5 = FUN_00601f90(&local_14);
      local_8._0_1_ = 1;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0;
      if (iVar5 != 0) {
        FUN_00491db0(iVar5 + 8);
      }
      FUN_006b8fb0("Grabstein");
      iVar5 = FUN_00601f90(&local_14);
      local_8._0_1_ = 2;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0;
      if (iVar5 != 0) {
        FUN_00491db0(iVar5 + 8);
      }
      FUN_006b8fb0("Abfluss");
      iVar5 = FUN_00601f90(&local_14);
      local_8._0_1_ = 3;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0;
      if (iVar5 != 0) {
        FUN_00491db0(iVar5 + 8);
      }
      FUN_006b8fb0("Plattmachfalle");
      iVar5 = FUN_00601f90(&local_14);
      local_8._0_1_ = 4;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0;
      if (iVar5 != 0) {
        FUN_00491db0(iVar5 + 8);
      }
      FUN_006b8fb0("SteinfalleMedusa");
      iVar5 = FUN_00601f90(&local_14);
      local_8._0_1_ = 5;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (iVar5 != 0) {
        FUN_00491db0(iVar5 + 8);
      }
    }
    bVar2 = true;
  }
  iVar7 = DAT_00772388;
  iVar5 = in_stack_00000004[2];
  if (iVar5 == DAT_00772388) {
    if (in_stack_00000004[6] == this->i_64) {
      iVar8 = this->i_50 + -5;
      bVar2 = true;
      iVar5 = 0;
      if (-1 < iVar8) {
        iVar5 = iVar8;
      }
      this->i_50 = iVar5;
      iVar5 = in_stack_00000004[2];
    }
    if ((iVar5 == iVar7) && (in_stack_00000004[6] == this->i_68)) {
      bVar2 = true;
      iVar7 = this->i_50 + 5;
      iVar5 = this->i_78 + 10;
      if (iVar7 <= iVar5) {
        iVar5 = iVar7;
      }
      this->i_50 = iVar5;
      iVar5 = in_stack_00000004[2];
    }
  }
  if (iVar5 == DAT_007723c4) {
    uVar4 = this->i_80;
    if ((-1 < (int)uVar4) && ((int)uVar4 < this->i_78)) {
      if ((uint)this->i_78 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(this->i_74 + (uVar4 * 10 + 3) * 4);
      if (iVar5 != -1) {
        piVar6 = (int *)FUN_00407340(iVar5);
        iVar7 = *piVar6;
        if (iVar7 != 0) {
          iVar8 = FUN_004ecd40();
          if (*(char *)(iVar8 + 0x11b) == '\0') {
            cVar3 = FUN_005e35a0(iVar5);
            if (cVar3 != '\0') {
              uVar9 = 1;
              fVar1 = *(float *)(iVar7 + 0x10);
              *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) = *(undefined4 *)(iVar7 + 0xc)
              ;
              *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158) =
                   fVar1 - *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) * 1.5;
              goto LAB_005351d4;
            }
          }
          iVar7 = FUN_004ecd40();
          if (*(char *)(iVar7 + 0x123) == '\0') {
            iVar7 = FUN_004ecd40();
            if (*(char *)(iVar7 + 0x11b) == '\0') {
              FUN_0040b980(0);
            }
          }
          FUN_005e3520(iVar5);
          uVar9 = 1;
          goto LAB_005351d4;
        }
      }
    }
  }
  else {
    if (iVar5 == DAT_007723c8) {
      uVar9 = 1;
      goto LAB_005351d4;
    }
    if (bVar2) {
      FUN_00536190(uVar4);
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    if (in_stack_00000004[2] == DAT_007723ec) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar5 = in_stack_00000004[1] + -1;
          in_stack_00000004[1] = iVar5;
          UNLOCK();
          if (iVar5 == 0) {
            (**(code **)*in_stack_00000004)(1);
          }
        }
        uVar9 = 0;
        goto LAB_005351d4;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar9 = 1;
          goto LAB_005351d4;
        }
      }
    }
  }
  uVar9 = 1;
LAB_005351d4:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar6 = in_stack_00000004 + 1;
    iVar5 = *piVar6;
    *piVar6 = *piVar6 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar9;
}

