
/* WARNING: Removing unreachable block (ram,0x0062913b) */

undefined4
CTclGlobalMethods__CameraSets(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined **ppuVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  bool bVar15;
  float fVar16;
  undefined8 uVar17;
  int local_7c;
  char local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  uint local_68;
  int local_64;
  double local_60;
  double local_58;
  undefined4 local_50;
  int *piStack_4c;
  undefined4 *local_48;
  int *local_44;
  uint local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c395;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d30) &&
     (FUN_006cebf4(&DAT_00ca6d30,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6d30 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6d34 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::CameraSets()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d30);
  }
  iVar6 = DAT_00ca6d34;
  local_48 = &DAT_00ca6d34;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d34 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar14;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar17 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 3) {
    iVar4 = *(int *)(DAT_00772400 + 0x5a4);
    if (local_64 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar5 = local_6c;
      if (local_68 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_68 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar5 = local_6c + 1;
    }
    fVar16 = 0.0;
    if (*piVar5 != 0) {
      iVar6 = Tcl_GetDoubleFromObj(0,*piVar5,&local_50);
      if (iVar6 == 1) {
        fVar16 = 0.0;
      }
      else {
        fVar16 = (float)(double)CONCAT44(piStack_4c,local_50);
      }
    }
    if (local_64 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar5 = local_6c;
      if (local_68 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_68 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar5 = local_6c + 2;
    }
    piVar5 = (int *)*piVar5;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    piVar1 = (int *)(iVar4 + 0x128);
    local_8 = CONCAT31(local_8._1_3_,3);
    *(float *)(iVar4 + 0x124) = fVar16;
    iVar6 = *(int *)(iVar4 + 300);
    piStack_4c = piVar5;
    local_44 = piVar5;
    if (iVar6 < 0) {
      FUN_00431cd0(-iVar6);
    }
    else if (0 < iVar6) {
      if (iVar6 == 1) {
        *(int *)(iVar4 + 300) = *(int *)(iVar4 + 300) + -1;
      }
      else {
        *(int *)(iVar4 + 300) = *(int *)(iVar4 + 300) - iVar6;
      }
    }
    iVar6 = 0;
    while( true ) {
      local_20 = iVar6;
      if (piVar5 == (int *)0x0) {
        iVar12 = 0;
      }
      else {
        iVar7 = Tcl_ListObjLength(0,piVar5,&local_24);
        iVar12 = local_24;
        if (iVar7 != 0) {
          iVar12 = 0;
        }
      }
      if (iVar12 <= iVar6) break;
      if ((piVar5 == (int *)0x0) || (iVar6 = Tcl_ListObjIndex(0,piVar5,iVar6,&local_28), iVar6 != 0)
         ) {
        local_2c = (int *)0x0;
      }
      else {
        local_2c = local_28;
        if (local_28 != (int *)0x0) {
          *local_28 = *local_28 + 1;
        }
      }
      piVar5 = local_2c;
      if ((local_2c == (int *)0x0) || (iVar6 = Tcl_ListObjIndex(0,local_2c,0,&local_30), iVar6 != 0)
         ) {
        local_18 = (int *)0x0;
      }
      else {
        local_18 = local_30;
        if (local_30 != (int *)0x0) {
          *local_30 = *local_30 + 1;
        }
      }
      piVar3 = local_18;
      local_8._0_1_ = 5;
      if (local_18 == (int *)0x0) {
        ppuVar8 = &PTR_0071ce50;
      }
      else {
        ppuVar8 = (undefined **)Tcl_GetStringFromObj(local_18,0);
      }
      FUN_006b8fb0(ppuVar8);
      local_8._0_1_ = 6;
      FUN_006b9970(&local_1c);
      local_8._0_1_ = 9;
      if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,10);
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
      pbVar13 = &DAT_0072b3d8;
      pbVar9 = (byte *)(local_1c + 3);
      do {
        bVar2 = *pbVar9;
        bVar15 = bVar2 < *pbVar13;
        if (bVar2 != *pbVar13) {
LAB_00629272:
          uVar10 = -(uint)bVar15 | 1;
          goto LAB_00629277;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar9[1];
        bVar15 = bVar2 < pbVar13[1];
        if (bVar2 != pbVar13[1]) goto LAB_00629272;
        pbVar9 = pbVar9 + 2;
        pbVar13 = pbVar13 + 2;
      } while (bVar2 != 0);
      uVar10 = 0;
LAB_00629277:
      local_40 = (uint)(uVar10 == 0);
      if (((piVar5 == (int *)0x0) ||
          (iVar6 = Tcl_ListObjIndex(0,piVar5,1,&local_38), piVar3 = local_38, iVar6 != 0)) ||
         (local_38 == (int *)0x0)) {
        local_14 = 0.0;
      }
      else {
        *local_38 = *local_38 + 1;
        iVar6 = Tcl_GetDoubleFromObj(0,local_38,&local_58);
        if (iVar6 == 1) {
          local_14 = 0.0;
        }
        else {
          local_14 = (float)local_58;
        }
        *piVar3 = *piVar3 + -1;
        if (*piVar3 < 1) {
          TclFreeObj(piVar3);
        }
      }
      if (((piVar5 == (int *)0x0) ||
          (iVar6 = Tcl_ListObjIndex(0,piVar5,2,&local_3c), piVar3 = local_3c, iVar6 != 0)) ||
         (local_3c == (int *)0x0)) {
        local_18 = (int *)0x0;
      }
      else {
        *local_3c = *local_3c + 1;
        iVar6 = Tcl_GetDoubleFromObj(0,local_3c,&local_60);
        if (iVar6 == 1) {
          local_18 = (int *)0x0;
        }
        else {
          local_18 = (int *)(float)local_60;
        }
        *piVar3 = *piVar3 + -1;
        if (*piVar3 < 1) {
          TclFreeObj(piVar3);
        }
      }
      uVar10 = *(uint *)(iVar4 + 300);
      if ((uVar10 + 0x10 & 0xfffffff0) != (uVar10 + 0xf & 0xfffffff0)) {
        iVar6 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        uVar10 = *(uint *)(iVar4 + 300);
        *piVar1 = iVar6;
      }
      uVar11 = uVar10 + 1;
      *(uint *)(iVar4 + 300) = uVar11;
      if (uVar11 <= uVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar11 = *(uint *)(iVar4 + 300);
      }
      uVar10 = uVar11 - 1;
      if (uVar11 <= uVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(uint *)(*piVar1 + uVar10 * 0xc) = local_40;
      if (*(uint *)(iVar4 + 300) <= uVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)(*piVar1 + 4 + uVar10 * 0xc) = local_14;
      if (*(uint *)(iVar4 + 300) <= uVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(int **)(*piVar1 + 8 + uVar10 * 0xc) = local_18;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
        FUN_006ba940();
      }
      if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
        TclFreeObj(piVar5);
      }
      iVar6 = local_20 + 1;
      piVar5 = local_44;
    }
    uVar14 = 0;
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar14 = 1;
  }
  local_8._0_1_ = 0xc;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_004297b0(0);
  if (local_6c != (int *)0x0) {
    FUN_006ba940();
  }
  if ((local_78 != '\0') && (local_7c != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_7c);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 0xe;
  if ((local_70 != (int *)0x0) && (*local_70 = *local_70 + -1, *local_70 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xf);
  if ((local_74 != (int *)0x0) && (*local_74 = *local_74 + -1, *local_74 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar14;
}

