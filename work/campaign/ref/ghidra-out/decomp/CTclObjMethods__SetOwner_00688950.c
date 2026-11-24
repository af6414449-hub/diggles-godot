
undefined4
CTclObjMethods__SetOwner(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  bool bVar11;
  undefined8 uVar12;
  int *piVar13;
  int local_24;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711675;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77f0) &&
     (FUN_006cebf4(&DAT_00ca77f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca77f0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca77f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::SetOwner()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77f0);
  }
  iVar7 = DAT_00ca77f4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77f4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 - 3U < 3) {
    if (*(char *)(DAT_00772400 + 0x91) == '\0') {
      iVar4 = *(int *)(DAT_00772400 + 0xa3f8);
      if (-1 < iVar4) {
        iVar7 = DAT_00768388;
        if (*(char *)(DAT_00772400 + 0x590) != '\0') {
          iVar7 = 2;
        }
        if (iVar7 < 2 - iVar4) {
          if (iVar4 == 0) {
            puVar5 = (undefined4 *)FUN_004295e0(2);
            local_14 = (int *)*puVar5;
            if (local_14 != (int *)0x0) {
              *local_14 = *local_14 + 1;
            }
            puVar5 = (undefined4 *)FUN_004295e0(1);
            param_3 = (int *)*puVar5;
            if (param_3 != (int *)0x0) {
              *param_3 = *param_3 + 1;
            }
            uVar9 = FUN_006baee0();
            uVar6 = FUN_006baee0(uVar9);
LAB_00688bf0:
            cVar3 = FUN_005d76f0(uVar6,uVar9);
            FUN_006bad60();
            FUN_006bad60();
            if (cVar3 != '\0') goto LAB_00688dc1;
          }
          else if (iVar4 == 1) {
            puVar5 = (undefined4 *)FUN_004295e0(2);
            local_14 = (int *)*puVar5;
            if (local_14 != (int *)0x0) {
              *local_14 = *local_14 + 1;
            }
            puVar5 = (undefined4 *)FUN_004295e0(1);
            param_3 = (int *)*puVar5;
            if (param_3 != (int *)0x0) {
              *param_3 = *param_3 + 1;
            }
            uVar9 = FUN_006baee0();
            uVar6 = FUN_006baee0(uVar9);
            goto LAB_00688bf0;
          }
          puVar5 = (undefined4 *)FUN_004295e0(1);
          piVar1 = (int *)*puVar5;
          if (piVar1 != (int *)0x0) {
            *piVar1 = *piVar1 + 1;
          }
          FUN_006bc6a0("invalid object",piVar1);
          goto LAB_00688dcf;
        }
      }
      iVar4 = FUN_005c71c0(param_4,3,1);
      if (iVar4 == 0) goto LAB_00688dcf;
      puVar5 = (undefined4 *)FUN_004295e0(2);
      param_3 = (int *)*puVar5;
      if (param_3 != (int *)0x0) {
        *param_3 = *param_3 + 1;
      }
      iVar7 = FUN_006baee0();
      FUN_006bad60();
      if (((*(int *)(iVar4 + 0x36c) == *(int *)(DAT_00772400 + 100)) &&
          (*(int *)(iVar4 + 0x36c) != iVar7)) && ((*(uint *)(iVar4 + 0x3d0) & 0x4002) != 0)) {
        FUN_0046a960(*(undefined4 *)(iVar4 + 0xdc));
      }
      *(int *)(iVar4 + 0x36c) = iVar7;
      local_14 = (int *)FUN_005c6f30();
      if ((local_14 != (int *)0x0) && (3 < (int)piVar1)) {
        if ((*(int *)(iVar4 + 0x378) != *(int *)(DAT_00772400 + 100)) &&
           ((*(char *)(iVar4 + 0x2b7) == '\0' &&
            (iVar7 = FUN_005b28d0(), *(char *)(iVar7 + 5) != '\0')))) {
          FUN_005d9df0(1);
          iVar7 = *(int *)(iVar4 + 0x370) + *(int *)(iVar4 + 0x374) * 0x10;
          puVar5 = (undefined4 *)FUN_004295e0(3);
          param_3 = (int *)*puVar5;
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + 1;
          }
          FUN_006baea0(&param_3);
          FUN_006bad60();
          if (4 < (int)piVar1) {
            puVar5 = (undefined4 *)FUN_004295e0(4);
            param_3 = (int *)*puVar5;
            if (param_3 != (int *)0x0) {
              *param_3 = *param_3 + 1;
            }
            FUN_006baea0(&param_3);
            FUN_006bad60();
          }
          *(int *)(iVar7 + -8) = local_14[0x37];
          *(undefined4 *)(iVar7 + -4) = *(undefined4 *)(iVar4 + 0x36c);
          uVar9 = 0;
          goto LAB_00688dd4;
        }
        if (4 < (int)piVar1) {
          puVar5 = (undefined4 *)FUN_004295e0(4);
          param_3 = (int *)*puVar5;
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + 1;
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00555a00(&param_3);
          FUN_006bad60();
        }
      }
    }
    else {
      puVar5 = (undefined4 *)FUN_004295e0(2);
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      puVar5 = (undefined4 *)FUN_004295e0(1);
      piVar2 = (int *)*puVar5;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      if (piVar1 == (int *)0x0) {
        uVar8 = 0;
      }
      else {
        iVar4 = Tcl_GetIntFromObj(0,piVar1,&param_3);
        uVar8 = -(uint)(iVar4 != 1) & (uint)param_3;
      }
      if (piVar2 == (int *)0x0) {
        cVar3 = FUN_005d76f0(0,uVar8);
        bVar11 = cVar3 == '\0';
        pcVar10 = TclFreeObj_exref;
      }
      else {
        iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_14);
        piVar13 = local_14;
        if (iVar4 == 1) {
          piVar13 = (int *)0x0;
        }
        cVar3 = FUN_005d76f0(piVar13,uVar8);
        bVar11 = cVar3 == '\0';
        *piVar2 = *piVar2 + -1;
        pcVar10 = TclFreeObj_exref;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        (*pcVar10)(piVar1);
      }
      if (bVar11) {
        puVar5 = (undefined4 *)FUN_004295e0(1);
        piVar1 = (int *)*puVar5;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        FUN_006bc6a0("invalid object",piVar1);
        goto LAB_00688dcf;
      }
    }
LAB_00688dc1:
    uVar9 = 0;
  }
  else {
    FUN_006bc8f0(2);
LAB_00688dcf:
    uVar9 = 1;
  }
LAB_00688dd4:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_24 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

