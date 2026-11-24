
/* WARNING: Type propagation algorithm not settling */

void CTclObjMethods__AutoChooseWorkingTime
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  undefined8 uVar13;
  int local_bc;
  int local_b0;
  char local_ac;
  int *local_a8;
  int *local_a4;
  int local_88;
  uint local_84;
  int local_80;
  int local_7c [4];
  undefined4 uStack_6c;
  int iStack_68;
  int local_64;
  int iStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int local_44 [3];
  int iStack_38;
  int local_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710ba6;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74f8) &&
     (FUN_006cebf4(&DAT_00ca74f8,local_14), iVar3 = DAT_00783650, DAT_00ca74f8 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca74fc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclObjMethods::AutoChooseWorkingTime()";
    *(int *)(&DAT_00773650 + iVar10) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74f8);
  }
  iVar10 = DAT_00ca74fc;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74fc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,2,1);
  if (iVar3 != 0) {
    if ((*(int *)(iVar3 + 0xe8) == 1) || (*(int *)(iVar3 + 0xe8) == 0xb)) {
      piVar9 = (int *)(DAT_0077244c + 0x488);
      local_7c[0] = *(int *)(iVar3 + 0x36c);
      local_44[0] = 0;
      local_44[1] = 0;
      local_44[2] = 0;
      iStack_38 = 0;
      local_80 = 0;
      local_34 = 0;
      iStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      local_24 = 0;
      uStack_20 = 0;
      uStack_1c = 0;
      uStack_18 = 0;
      local_7c[1] = 8;
      local_84 = 2;
      do {
        if (local_84 < 0x2000) {
          piVar5 = (int *)(local_7c[1] + (int)piVar9);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar5 = piVar9;
        }
        if (*piVar5 != 0) {
          if (local_84 < 0x2000) {
            piVar5 = (int *)(local_7c[1] + (int)piVar9);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = piVar9;
          }
          piVar6 = (int *)(local_7c[1] + (int)piVar9);
          if (*(int *)(*piVar5 + 0x36c) == local_7c[0]) {
            piVar5 = piVar6;
            if (0x1fff < local_84) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar5 = piVar9;
            }
            if (*(int *)(*piVar5 + 0x3e4) != 0) {
              if (0x1fff < local_84) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = piVar9;
              }
              if (iVar3 != *piVar6) {
                if (0x1fff < local_84) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                fVar12 = (float10)FUN_006f52b0();
                iVar10 = (int)fVar12;
                if (0x1fff < local_84) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                fVar12 = (float10)FUN_006f52b0();
                iVar1 = (int)fVar12 + iVar10;
                if (iVar10 < iVar1) {
                  local_80 = local_80 + (int)fVar12;
                  do {
                    iVar11 = iVar10 + 1;
                    local_44[iVar10 % 0xc] = local_44[iVar10 % 0xc] + 1;
                    iVar10 = iVar11;
                  } while (iVar11 < iVar1);
                }
              }
            }
          }
        }
        local_84 = local_84 + 1;
        local_7c[1] = local_7c[1] + 4;
      } while ((int)local_84 < 0x2000);
      if (local_80 == 0) {
        *(undefined4 *)(iVar3 + 0x358) = 0x40c00000;
        *(undefined4 *)(iVar3 + 0x354) = 0;
      }
      else {
        if (0 < local_80) {
          iVar10 = 0;
          do {
            local_44[iVar10] = (local_44[iVar10] * 999) / local_80;
            iVar10 = iVar10 + 1;
          } while (iVar10 < 0xc);
        }
        local_84 = 3;
        local_7c[1] = 0xc;
        do {
          local_7c[2] = local_44[0];
          local_7c[3] = local_44[1];
          uStack_6c = local_44[2];
          iStack_68 = iStack_38;
          local_64 = local_34;
          iStack_60 = iStack_30;
          uStack_5c = uStack_2c;
          uStack_58 = uStack_28;
          local_54 = local_24;
          uStack_50 = uStack_20;
          uStack_4c = uStack_1c;
          uStack_48 = uStack_18;
          iVar10 = 0xe;
          piVar9 = local_44;
          do {
            *piVar9 = (local_7c[iVar10 + ((iVar10 - 2U) / 0xc) * -0xc] +
                       local_7c[(iVar10 + -4) % 0xc + 2] + local_7c[(iVar10 + -3) % 0xc + 2] +
                       local_7c[(iVar10 + -1) % 0xc + 2] + local_7c[iVar10 % 0xc + 2]) / 5;
            iVar1 = iVar10 + -1;
            iVar10 = iVar10 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar1 < 0x18);
          local_84 = local_84 + -1;
        } while (local_84 != 0);
        iVar10 = _rand();
        local_84 = iVar10 % 0xc;
        piVar9 = local_44 + 1;
        local_88 = 4;
        local_80 = 0;
        local_7c[1] = 2;
        iVar10 = local_84 * 4;
        do {
          iVar1 = local_7c[1];
          piVar5 = (int *)((int)local_44 + local_80 + 4U);
          iVar11 = iVar10;
          if (*(int *)((int)local_44 + local_80) < *(int *)((int)local_44 + iVar10)) {
            iVar11 = local_80;
          }
          uVar8 = local_7c[1] + -2;
          if (*(int *)((int)local_44 + iVar10) <= *(int *)((int)local_44 + local_80)) {
            uVar8 = local_84;
          }
          iVar10 = iVar11;
          if (*piVar5 < *(int *)((int)local_44 + iVar11)) {
            iVar10 = local_88;
          }
          local_7c[0] = local_7c[1] + -1;
          iVar7 = local_7c[1] + -1;
          if (*(int *)((int)local_44 + iVar11) <= *piVar5) {
            iVar7 = uVar8;
          }
          local_7c[0] = *(int *)((int)local_44 + iVar10);
          if (*(int *)((int)local_44 + local_80 + 8U) < local_7c[0]) {
            iVar10 = (8 - (int)piVar9) + (int)piVar5;
          }
          iVar11 = local_7c[1];
          if (local_7c[0] <= *(int *)((int)local_44 + local_80 + 8U)) {
            iVar11 = iVar7;
          }
          local_7c[0] = *(int *)((int)local_44 + iVar10);
          if (*(int *)((int)&iStack_38 + local_80) < local_7c[0]) {
            iVar10 = (0xc - (int)piVar9) + (int)piVar5;
          }
          iVar7 = local_7c[1] + 1;
          if (local_7c[0] <= *(int *)((int)&iStack_38 + local_80)) {
            iVar7 = iVar11;
          }
          local_7c[0] = *(int *)((int)local_44 + iVar10);
          if (*(int *)((int)&local_34 + local_80) < local_7c[0]) {
            iVar10 = (0x10 - (int)piVar9) + (int)piVar5;
          }
          iVar11 = local_7c[1] + 2;
          if (local_7c[0] <= *(int *)((int)&local_34 + local_80)) {
            iVar11 = iVar7;
          }
          local_7c[0] = *(int *)((int)local_44 + iVar10);
          if (*(int *)((int)&iStack_30 + local_80) < local_7c[0]) {
            iVar10 = (0x14 - (int)piVar9) + (int)piVar5;
          }
          local_84 = local_7c[1] + 3;
          if (local_7c[0] <= *(int *)((int)&iStack_30 + local_80)) {
            local_84 = iVar11;
          }
          local_88 = local_88 + 0x18;
          local_80 = local_80 + 0x18;
          local_7c[1] = local_7c[1] + 6;
        } while (iVar1 + 4 < 0xc);
        *(undefined4 *)(iVar3 + 0x358) = 0x40c00000;
        *(float *)(iVar3 + 0x354) = (float)((int)(local_84 + 10) % 0xc);
      }
    }
    else {
      puVar4 = (undefined4 *)FUN_004295e0(1);
      piVar9 = (int *)*puVar4;
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      FUN_006bc6a0("not a gnome or baby",piVar9);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_bc != 0) {
    FUN_006ba940();
  }
  if ((local_ac != '\0') && (local_b0 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_b0);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 5;
  if ((local_a4 != (int *)0x0) && (*local_a4 = *local_a4 + -1, *local_a4 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_a8 != (int *)0x0) && (*local_a8 = *local_a8 + -1, *local_a8 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

