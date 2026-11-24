
undefined4 CTclGlobalMethods__GetTime(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  FILE *pFVar6;
  int iVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined **_Str1;
  bool bVar10;
  undefined8 uVar11;
  int local_34;
  int local_24;
  int local_20;
  int *local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cf7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  iVar4 = *ThreadLocalStoragePointer;
  if ((*(int *)(iVar4 + 4) < DAT_00ca6eb8) &&
     (FUN_006cebf4(&DAT_00ca6eb8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6eb8 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6ebc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::GetTime()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6eb8);
  }
  iVar7 = DAT_00ca6ebc;
  local_18 = &DAT_00ca6ebc;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ebc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar9;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 != 2) {
    FUN_006bc8f0(1);
    uVar9 = 1;
    goto LAB_0063412f;
  }
  piVar1 = *(int **)(param_4 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = piVar1;
  if (piVar1 == (int *)0x0) {
    _Str1 = &PTR_0071ce50;
  }
  else {
    _Str1 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  if ((*(int *)(iVar4 + 4) < DAT_00ca6a60) && (FUN_006cebf4(&DAT_00ca6a60), DAT_00ca6a60 == -1)) {
    __flushall();
    _atexit((_func_4879 *)&DAT_007145a0);
    FUN_006cebaa(&DAT_00ca6a60);
  }
  iVar4 = __stricmp((char *)_Str1,"enabled");
  pcVar8 = TclFreeObj_exref;
  if (iVar4 == 0) {
    bVar10 = DAT_007683a9 != '\0';
LAB_00633d24:
    piVar5 = (int *)Tcl_NewBooleanObj(bVar10);
    *piVar5 = *piVar5 + 1;
    iVar4 = *piVar5;
    if (local_34 != 0) {
      Tcl_SetObjResult(local_34,piVar5);
      iVar4 = *piVar5;
    }
    *piVar5 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar5);
      uVar9 = 0;
    }
    else {
LAB_006340fd:
      uVar9 = 0;
    }
  }
  else {
    iVar4 = __stricmp((char *)_Str1,"present");
    if (iVar4 == 0) {
      if ((DAT_007683a9 != '\0') &&
         (pFVar6 = _fopen("data/scripts/cache.bin","r"), pFVar6 != (FILE *)0x0)) {
        _fclose(pFVar6);
        pFVar6 = _fopen("data/scripts/flush_tclclasscache.tcl","r");
        if (pFVar6 == (FILE *)0x0) {
          bVar10 = true;
          goto LAB_00633d24;
        }
        _fclose(pFVar6);
        __chmod("data/scripts/flush_tclclasscache.tcl",0x180);
        FID_conflict___rmdir("data/scripts/flush_tclclasscache.tcl");
      }
      bVar10 = false;
      goto LAB_00633d24;
    }
    iVar4 = __stricmp((char *)_Str1,"write");
    if (iVar4 == 0) {
      local_8._0_1_ = 3;
      local_24 = iVar4;
      local_20 = iVar4;
      cVar2 = FUN_006bccf0("data/scripts/cache.bin",7);
      if (cVar2 == '\0') {
        local_8 = CONCAT31(local_8._1_3_,4);
        goto LAB_00633e1a;
      }
      FUN_00600b40(&local_24);
      local_14 = DAT_00772400 + 0x95dc;
      FUN_005bb800(&local_24);
      iVar4 = local_20;
      param_3 = 0x80;
      iVar3 = local_24;
      do {
        if (iVar3 == 1) {
          if (((iVar4 != 0) && (*(int *)(iVar4 + 0x10) == 0x1c4f)) &&
             ((*(int *)(iVar4 + 0x5c) == 0 || (iVar3 = local_24, *(int *)(iVar4 + 0x5c) == -5)))) {
            FUN_006c6da0(1);
            iVar3 = local_24;
          }
        }
        else if ((((iVar3 == 2) && (iVar4 != 0)) && (*(int *)(iVar4 + 0x10) == 0x79b1)) &&
                (*(int *)(iVar4 + 0x5c) == 0)) {
          FUN_006c76b0(1);
          iVar3 = local_24;
        }
        param_3 = param_3 + -1;
      } while (param_3 != 0);
      FUN_005bb490(&local_24);
      FUN_005da0f0();
      FUN_005f4a20();
      local_8 = CONCAT31(local_8._1_3_,5);
LAB_00633f5d:
      pcVar8 = TclFreeObj_exref;
      if (iVar4 != 0) {
        if (*(int *)(iVar4 + 0x10) == 0x1c4f) {
          if (*(int *)(iVar4 + 0x1c) != 0) {
            FUN_006c9e10();
            FUN_006df631(*(undefined4 *)(iVar4 + 0x28));
            FUN_006df631(*(undefined4 *)(iVar4 + 0x24));
          }
          if (*(int *)(iVar4 + 0x60) != 0) {
            if (*(int *)(iVar4 + 0x5c) != -4) {
              FUN_006df631(*(int *)(iVar4 + 0x60));
            }
            *(undefined4 *)(iVar4 + 0x60) = 0;
          }
          *(undefined4 *)(iVar4 + 0x5c) = 0;
          FUN_006df631(*(undefined4 *)(iVar4 + 0x18));
          __close(*(int *)(iVar4 + 0x14));
          FUN_006df631(iVar4);
          uVar9 = 0;
          pcVar8 = TclFreeObj_exref;
          goto LAB_0063411e;
        }
        FUN_006c77c0();
        pcVar8 = TclFreeObj_exref;
      }
      goto LAB_006340fd;
    }
    iVar4 = __stricmp((char *)_Str1,"load");
    if (iVar4 == 0) {
      local_8._0_1_ = 6;
      local_24 = iVar4;
      local_20 = iVar4;
      cVar2 = FUN_006bcc50("data/scripts/cache.bin");
      if (cVar2 != '\0') {
        FUN_00600b40(&local_24);
        local_14 = DAT_00772400 + 0x95dc;
        FUN_005bb800(&local_24);
        iVar4 = local_20;
        param_3 = 0x80;
        iVar3 = local_24;
        do {
          if (iVar3 == 1) {
            if (((iVar4 != 0) && (*(int *)(iVar4 + 0x10) == 0x1c4f)) &&
               ((*(int *)(iVar4 + 0x5c) == 0 || (iVar3 = local_24, *(int *)(iVar4 + 0x5c) == -5))))
            {
              FUN_006c6da0(1);
              iVar3 = local_24;
            }
          }
          else if (((iVar3 == 2) && (iVar4 != 0)) &&
                  ((*(int *)(iVar4 + 0x10) == 0x79b1 && (*(int *)(iVar4 + 0x5c) == 0)))) {
            FUN_006c76b0(1);
            iVar3 = local_24;
          }
          param_3 = param_3 + -1;
        } while (param_3 != 0);
        FUN_005bb490(&local_24);
        FUN_005da0f0();
        FUN_005f4a20();
        local_8 = CONCAT31(local_8._1_3_,8);
        goto LAB_00633f5d;
      }
      local_8 = CONCAT31(local_8._1_3_,7);
LAB_00633e1a:
      iVar4 = local_20;
      if (local_20 == 0) goto LAB_006340fd;
      if (*(int *)(local_20 + 0x10) == 0x1c4f) {
        if (*(int *)(local_20 + 0x1c) != 0) {
          FUN_006c9e10();
          FUN_006df631(*(undefined4 *)(iVar4 + 0x28));
          FUN_006df631(*(undefined4 *)(iVar4 + 0x24));
        }
        if (*(int *)(iVar4 + 0x60) != 0) {
          if (*(int *)(iVar4 + 0x5c) != -4) {
            FUN_006df631(*(int *)(iVar4 + 0x60));
          }
          *(undefined4 *)(iVar4 + 0x60) = 0;
        }
        *(undefined4 *)(iVar4 + 0x5c) = 0;
        FUN_006df631(*(undefined4 *)(iVar4 + 0x18));
        __close(*(int *)(iVar4 + 0x14));
        FUN_006df631(iVar4);
        uVar9 = 0;
      }
      else {
        FUN_006c77c0();
        uVar9 = 0;
      }
    }
    else {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("invalid subcommand",piVar1);
      uVar9 = 1;
    }
  }
LAB_0063411e:
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar8)(piVar1);
  }
LAB_0063412f:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

