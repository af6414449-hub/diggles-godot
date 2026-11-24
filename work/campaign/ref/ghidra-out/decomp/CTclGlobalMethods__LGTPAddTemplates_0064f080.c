
undefined4
CTclGlobalMethods__LGTPAddTemplates
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  bool bVar11;
  undefined8 uVar12;
  int local_50;
  char local_4c;
  int *local_48;
  int *local_44;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int *local_2c;
  int *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e515;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71c8) &&
     (FUN_006cebf4(&DAT_00ca71c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca71c8 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca71cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::LGTPAddTemplates()";
    *(int *)(&DAT_00773650 + iVar10) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71c8);
  }
  iVar10 = DAT_00ca71cc;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71cc * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar9;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar1 == 0) {
    uVar12 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_38 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 1;
    }
    piVar8 = (int *)*puVar7;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_1c = piVar8;
    iVar1 = FUN_0058a820();
    iVar10 = 0;
    local_14 = iVar1;
    do {
      local_18 = iVar10;
      if (piVar8 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar2 = Tcl_ListObjLength(0,piVar8,&local_20);
        iVar5 = local_20;
        if (iVar2 != 0) {
          iVar5 = 0;
        }
      }
      if (iVar5 <= iVar10) {
        uVar9 = 0;
        goto LAB_0064f39d;
      }
      if ((piVar8 == (int *)0x0) ||
         (iVar10 = Tcl_ListObjIndex(0,piVar8,iVar10,&local_24), iVar10 != 0)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = local_24;
        if (local_24 != (int *)0x0) {
          *local_24 = *local_24 + 1;
        }
      }
      local_8._0_1_ = 4;
      if (piVar8 == (int *)0x0) {
        ppuVar3 = &PTR_0071ce50;
      }
      else {
        ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
      }
      FUN_006b8fb0(ppuVar3);
      local_8 = CONCAT31(local_8._1_3_,5);
      if (local_2c != (int *)0x0) {
        *local_2c = *local_2c + 1;
      }
      uVar4 = FUN_00582fc0(local_2c);
      if (uVar4 == 0xffffffff) {
        bVar11 = true;
      }
      else {
        if (*(uint *)(iVar1 + 0x1a8) <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (0 < *(int *)(uVar4 * 0x54 + 0x1c + *(int *)(iVar1 + 0x1a4))) {
          uVar6 = 0;
          iVar10 = local_14;
          if (0 < *(int *)(local_14 + 0x44)) {
            bVar11 = *(int *)(local_14 + 0x44) != 0;
            do {
              if (!bVar11) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar10 = local_14;
              }
              iVar1 = local_14;
              if (*(uint *)(*(int *)(iVar10 + 0x40) + uVar6 * 4) == uVar4) goto LAB_0064f338;
              uVar6 = uVar6 + 1;
              bVar11 = uVar6 < *(uint *)(iVar10 + 0x44);
            } while ((int)uVar6 < (int)*(uint *)(iVar10 + 0x44));
          }
          uVar6 = *(uint *)(iVar10 + 0x44);
          if ((uVar6 + 0x10 & 0xfffffff0) != (uVar6 + 0xf & 0xfffffff0)) {
            uVar9 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                 ,0x9b);
            uVar6 = *(uint *)(local_14 + 0x44);
            *(undefined4 *)(local_14 + 0x40) = uVar9;
            iVar10 = local_14;
          }
          *(uint *)(iVar10 + 0x44) = uVar6 + 1;
          if (uVar6 + 1 <= uVar6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar10 = local_14;
          }
          *(uint *)(*(int *)(iVar10 + 0x40) + uVar6 * 4) = uVar4;
          iVar1 = local_14;
        }
LAB_0064f338:
        bVar11 = false;
      }
      local_8._0_1_ = 6;
      if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
        TclFreeObj(piVar8);
      }
      if (bVar11) goto LAB_0064f37b;
      iVar10 = local_18 + 1;
      piVar8 = local_1c;
    } while( true );
  }
  FUN_006bc8f0(1);
  uVar9 = 1;
LAB_0064f3b2:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_4c != '\0') && (local_50 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_50);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 9;
  if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
LAB_0064f37b:
  FUN_006bc6a0("invalid Template",0);
  uVar9 = 1;
  piVar8 = local_1c;
LAB_0064f39d:
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    TclFreeObj(piVar8);
  }
  goto LAB_0064f3b2;
}

