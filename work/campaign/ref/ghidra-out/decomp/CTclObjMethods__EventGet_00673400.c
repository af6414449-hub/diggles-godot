
undefined4
CTclObjMethods__EventGet
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **_Str1;
  undefined4 *puVar4;
  int **ppiVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined8 uVar10;
  int *local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710825;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7490) &&
     (FUN_006cebf4(&DAT_00ca7490,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7490 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7494 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::EventGet()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7490);
  }
  iVar6 = DAT_00ca7494;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7494 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    uVar8 = 1;
    goto LAB_006738c0;
  }
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar1 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar1 = 0;
  piVar3[1] = 0x14;
  *piVar1 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_3c == (int *)0x0) {
    local_1c = local_3c;
    iVar6 = 1;
  }
  else {
    local_1c = (int *)Tcl_GetAssocData(local_3c,piVar1,0);
    iVar6 = *piVar3;
  }
  local_8._0_1_ = 3;
  *piVar3 = iVar6 + -1;
  if (iVar6 + -1 == 0) {
    FUN_006ba940();
  }
  piVar1 = *(int **)(iVar2 + 0x1fc);
  if (piVar1 != (int *)0x0) {
    LOCK();
    piVar1[1] = piVar1[1] + 1;
    UNLOCK();
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  local_18 = piVar1;
  if (piVar1 == (int *)0x0) {
    FUN_006bc6a0("no event",0);
    uVar8 = 1;
    goto LAB_006738c0;
  }
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_2c + 2;
  }
  piVar3 = (int *)*puVar4;
  local_14 = (int *)0x0;
  local_18 = piVar3;
  if (piVar3 == (int *)0x0) {
    _Str1 = &PTR_0071ce50;
  }
  else {
    *piVar3 = *piVar3 + 1;
    _Str1 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
  }
  iVar2 = __stricmp((char *)_Str1,"timestamp");
  if (iVar2 == 0) {
    puVar4 = (undefined4 *)FUN_006bad90();
    local_14 = (int *)*puVar4;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    pcVar7 = TclFreeObj_exref;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
LAB_0067364c:
    if ((local_14 != (int *)0x0) && (local_3c != (int *)0x0)) {
      Tcl_SetObjResult(local_3c,local_14);
    }
  }
  else {
    iVar2 = __stricmp((char *)_Str1,"-target");
    if (iVar2 == 0) {
      iVar2 = FUN_005caf90();
      if (iVar2 != 0) goto LAB_00673761;
      piVar9 = (int *)0x0;
      goto LAB_00673771;
    }
    iVar2 = __stricmp((char *)_Str1,"-origin");
    if (iVar2 == 0) {
      iVar2 = piVar1[3];
LAB_006736b0:
      if (iVar2 == 0) {
        local_1c = (int *)Tcl_NewIntObj(0);
        *local_1c = *local_1c + 1;
        ppiVar5 = &local_1c;
LAB_0067384e:
        FUN_006baea0(ppiVar5);
        FUN_006bad60();
        pcVar7 = TclFreeObj_exref;
      }
      else {
        iVar2 = FUN_005caf90();
        if (iVar2 == 0) {
          piVar9 = (int *)0x0;
        }
        else {
LAB_00673761:
          piVar9 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
          *piVar9 = *piVar9 + 1;
        }
LAB_00673771:
        local_1c = piVar9;
        FUN_006baea0(&local_1c);
        pcVar7 = TclFreeObj_exref;
        piVar3 = local_18;
        if ((piVar9 != (int *)0x0) &&
           (*piVar9 = *piVar9 + -1, pcVar7 = TclFreeObj_exref, *piVar9 < 1)) {
          TclFreeObj(piVar9);
          piVar3 = local_18;
        }
      }
      goto LAB_0067364c;
    }
    iVar2 = __stricmp((char *)_Str1,"-subject1");
    if (iVar2 == 0) {
      iVar2 = piVar1[4];
      goto LAB_006736b0;
    }
    iVar2 = __stricmp((char *)_Str1,"-subject2");
    if (iVar2 == 0) {
      iVar2 = piVar1[5];
      goto LAB_006736b0;
    }
    iVar2 = __stricmp((char *)_Str1,"-subject3");
    if (iVar2 == 0) {
      iVar2 = piVar1[6];
      goto LAB_006736b0;
    }
    iVar2 = __stricmp((char *)_Str1,"-text1");
    if (iVar2 == 0) {
      iVar2 = piVar1[0x13] + 0xc;
      if (iVar2 == 0) {
        piVar9 = (int *)0x0;
        goto LAB_00673771;
      }
      goto LAB_00673761;
    }
    iVar2 = __stricmp((char *)_Str1,"-text2");
    if (iVar2 == 0) {
      iVar2 = piVar1[0x14] + 0xc;
      if (iVar2 != 0) goto LAB_00673761;
      piVar9 = (int *)0x0;
      goto LAB_00673771;
    }
    iVar2 = __stricmp((char *)_Str1,"-num1");
    if (iVar2 == 0) {
      ppiVar5 = (int **)FUN_006bad90();
      goto LAB_0067384e;
    }
    iVar2 = __stricmp((char *)_Str1,"-num2");
    if (iVar2 == 0) {
      ppiVar5 = (int **)FUN_006bad90();
      goto LAB_0067384e;
    }
    iVar2 = __stricmp((char *)_Str1,"-num3");
    if (iVar2 == 0) {
      ppiVar5 = (int **)FUN_006bad90();
      goto LAB_0067384e;
    }
    iVar2 = __stricmp((char *)_Str1,"-pos1");
    if (iVar2 == 0) {
      piVar9 = piVar1 + 10;
LAB_00673845:
      ppiVar5 = (int **)FUN_006badc0(piVar9);
      goto LAB_0067384e;
    }
    iVar2 = __stricmp((char *)_Str1,"-pos2");
    if (iVar2 == 0) {
      piVar9 = piVar1 + 0xd;
      goto LAB_00673845;
    }
    iVar2 = __stricmp((char *)_Str1,"-pos3");
    pcVar7 = TclFreeObj_exref;
    if (iVar2 == 0) {
      piVar9 = piVar1 + 0x10;
      goto LAB_00673845;
    }
  }
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
    (*pcVar7)(local_14);
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    (*pcVar7)(piVar3);
  }
  LOCK();
  iVar2 = piVar1[1] + -1;
  piVar1[1] = iVar2;
  UNLOCK();
  if (iVar2 == 0) {
    (**(code **)*piVar1)(1);
  }
  uVar8 = 0;
LAB_006738c0:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

