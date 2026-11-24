
undefined4
CTclObjMethods__Action(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  AchievementManager *this;
  int iVar9;
  code *pcVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  int *local_64;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  int *local_3c;
  int *local_38;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071075d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7480) &&
     (FUN_006cebf4(), iVar6 = DAT_00783650, DAT_00ca7480 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca7484 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclObjMethods::Action()";
    *(int *)(&DAT_00773650 + iVar9) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar9 = DAT_00ca7484;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7484 * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar11;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar6 == 0) {
    uVar12 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  piVar7 = (int *)FUN_005c71c0(param_4);
  local_2c = piVar7;
  if (piVar7 != (int *)0x0) {
    if ((char)piVar7[0x100] == '\0') {
      if (local_4c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_54;
        if (local_50 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_50 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_54 + 2;
      }
      piVar1 = (int *)*puVar8;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8._0_1_ = 3;
      if (piVar1 != (int *)0x0) {
        Tcl_GetStringFromObj();
      }
      FUN_006b8fb0();
      local_8._0_1_ = 4;
      FUN_00405e10();
      local_8._0_1_ = 7;
      if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
        FUN_006ba940();
      }
      pcVar10 = TclFreeObj_exref;
      local_8._0_1_ = 6;
      if (local_20 == (int *)0x0) {
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        FUN_006bc6a0();
        uVar11 = 1;
      }
      else {
        puVar8 = (undefined4 *)FUN_004295e0();
        piVar2 = (int *)*puVar8;
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + 1;
        }
        local_18 = (int *)0x0;
        local_1c = (int *)0x0;
        local_8._0_1_ = 10;
        if (4 < param_3) {
          FUN_004295e0();
          FUN_006baea0();
        }
        if (param_3 == 6) {
          FUN_004295e0();
          FUN_006baea0();
        }
        if ((int *)piVar7[0xfe] != (int *)0x0) {
          (**(code **)(*(int *)piVar7[0xfe] + 4))();
          FUN_006b8fb0();
          local_8._0_1_ = 0xb;
          iVar6 = FUN_006b9f40();
          if (iVar6 != -1) {
            FUN_006b8fb0();
            iVar6 = FUN_006bcb50();
            local_8._0_1_ = 0xc;
            if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 0xb;
            FUN_006b8fb0();
            local_8._0_1_ = 0xd;
            if (iVar6 != 0) {
              FUN_006b91c0();
            }
            local_8._0_1_ = 0xe;
            if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 0xb;
          }
          FUN_006b8fb0();
          if (local_64 == (int *)0x0) {
            local_14 = local_64;
          }
          else {
            local_14 = (int *)Tcl_GetAssocData(local_64);
          }
          local_8._0_1_ = 0xf;
          if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 0xb;
          FUN_006b8fb0();
          local_8._0_1_ = 0x10;
          if (local_14 != (int *)0x0) {
            this = AchievementManager::GetInstance();
            FUN_006b91c0();
            AchievementManager::CheckTriggerName(this,(char *)(local_24 + 3));
            piVar7 = local_2c;
          }
          local_8._0_1_ = 0x11;
          if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 0xb;
          (**(code **)(*(int *)piVar7[0xfe] + 0x10))();
          piVar3 = *(int **)(piVar7[0xfe] + 0x14);
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + 1;
          }
          local_8._0_1_ = 0x12;
          uVar4 = (undefined1)local_8;
          local_8._0_1_ = 0x12;
          if (piVar3 != (int *)0x0) {
            FUN_006b95d0();
            local_8._0_1_ = 0x13;
            FUN_006b9500();
            local_8._0_1_ = 0x14;
            FUN_006bafc0();
            FUN_006b9500();
            local_8._0_1_ = 0x17;
            if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 0x19;
            if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
              FUN_006ba940();
            }
            piVar7 = local_2c;
            local_8._0_1_ = 0x18;
            FUN_006b90d0(&local_2c);
            local_8._0_1_ = 0x1a;
            FUN_006b9290();
            local_8._0_1_ = 0x1b;
            if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
              FUN_006ba940();
            }
            local_8 = CONCAT31(local_8._1_3_,0x18);
            if (piVar7[0x80] != -1) {
              FUN_0045f6d0();
              FUN_006bafc0();
              FUN_006b9390();
            }
            if (piVar2 != (int *)0x0) {
              FUN_006b9390();
              FUN_006bafc0();
              FUN_006b9390();
            }
            if (local_18 != (int *)0x0) {
              FUN_006b9390();
              Tcl_GetStringFromObj();
              FUN_006b9390();
            }
            if (local_1c != (int *)0x0) {
              FUN_006b9390();
              Tcl_GetStringFromObj();
              FUN_006b9390();
            }
            if (local_14 == (int *)0xfffffff4) {
              local_24 = (int *)0x0;
              pcVar10 = Tcl_NewStringObj_exref;
            }
            else {
              local_24 = (int *)Tcl_NewStringObj();
              pcVar10 = Tcl_NewStringObj_exref;
              *local_24 = *local_24 + 1;
            }
            local_2c = (int *)(*pcVar10)();
            *local_2c = *local_2c + 1;
            local_8 = CONCAT31(local_8._1_3_,0x1d);
            FUN_005c9cc0();
            FUN_006bc9c0();
            *local_2c = *local_2c + -1;
            if (*local_2c < 1) {
              TclFreeObj();
            }
            local_8._0_1_ = 0x18;
            if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 < 1)) {
              TclFreeObj();
            }
            FUN_005c9cc0();
            FUN_00555a00();
            local_8._0_1_ = 0x1e;
            uVar4 = (undefined1)local_8;
            if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
              FUN_006ba940();
              uVar4 = (undefined1)local_8;
            }
          }
          local_8._0_1_ = uVar4;
          FUN_006bad60();
          local_8._0_1_ = 0x1f;
          if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 10;
        }
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + 1;
        }
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
        if (local_18 != (int *)0x0) {
          *local_18 = *local_18 + 1;
        }
        cVar5 = (**(code **)(*local_20 + 8))(param_2,piVar7,local_18);
        if (cVar5 == '\0') {
          if (local_18 != (int *)0x0) {
            FUN_00555a00();
          }
          uVar11 = 1;
        }
        else {
          FUN_00409280();
          uVar11 = 0;
        }
        if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c < 1)) {
          TclFreeObj();
        }
        if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
          TclFreeObj();
        }
        pcVar10 = TclFreeObj_exref;
        if ((piVar2 != (int *)0x0) &&
           (*piVar2 = *piVar2 + -1, pcVar10 = TclFreeObj_exref, *piVar2 < 1)) {
          TclFreeObj();
        }
      }
      if (local_20 != (int *)0x0) {
        LOCK();
        iVar6 = local_20[1] + -1;
        local_20[1] = iVar6;
        UNLOCK();
        if ((iVar6 == 0) && (local_20 != (int *)0x0)) {
          (**(code **)*local_20)();
        }
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        (*pcVar10)();
      }
      goto LAB_006720ed;
    }
    if (piVar7[0x36] + 0xc != 0) {
      piVar7 = (int *)Tcl_NewStringObj(piVar7[0x36] + 0xc);
      *piVar7 = *piVar7 + 1;
    }
    FUN_006bc6a0();
  }
  uVar11 = 1;
LAB_006720ed:
  local_8._0_1_ = 0x20;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0x21);
  FUN_004297b0();
  if (local_54 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

