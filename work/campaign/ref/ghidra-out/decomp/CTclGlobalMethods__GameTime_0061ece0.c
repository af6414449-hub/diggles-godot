
undefined4
CTclGlobalMethods__GameTime(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined **_Str1;
  float in_XMM0_Da;
  undefined8 uVar7;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b745;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c10) &&
     (FUN_006cebf4(&DAT_00ca6c10,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6c10 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6c14 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GameTime()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c10);
  }
  iVar4 = DAT_00ca6c14;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c14 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
    goto LAB_0061efce;
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_24 + 1;
  }
  piVar1 = (int *)*puVar5;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar1 == (int *)0x0) {
    _Str1 = &PTR_0071ce50;
  }
  else {
    _Str1 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  iVar4 = __stricmp((char *)_Str1,"start");
  iVar3 = DAT_00772400;
  if (iVar4 == 0) {
    *(undefined1 *)(DAT_00772400 + 0x8b) = 0;
    if (*(char *)(iVar3 + 0xa098) == '\0') {
      *(undefined1 *)(iVar3 + 0xa098) = 1;
      uVar6 = 0;
    }
    else {
LAB_0061ef20:
      uVar6 = 0;
    }
  }
  else {
    iVar4 = __stricmp((char *)_Str1,"stop");
    iVar3 = DAT_00772400;
    if (iVar4 == 0) {
      *(undefined1 *)(DAT_00772400 + 0x8b) = 1;
      if (*(char *)(iVar3 + 0xa098) == '\0') goto LAB_0061ef20;
      *(undefined1 *)(iVar3 + 0xa098) = 0;
      uVar6 = 0;
    }
    else {
      iVar4 = __stricmp((char *)_Str1,"reset");
      iVar3 = DAT_00772400;
      if (iVar4 == 0) {
        uVar7 = 0;
        *(undefined8 *)(DAT_00772400 + 0xa088) = 0;
        FUN_00565850();
        FUN_0043e3c0();
        *(undefined8 *)(iVar3 + 0xa080) = uVar7;
        uVar6 = 0;
      }
      else {
        iVar3 = __stricmp((char *)_Str1,"factor");
        if (iVar3 == 0) {
          if (param_3 == 2) {
            uVar6 = FUN_006bad90();
            FUN_006bc670(uVar6);
            FUN_006bad60();
            goto LAB_0061ef20;
          }
          puVar5 = (undefined4 *)FUN_004295e0(2);
          piVar2 = (int *)*puVar5;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          FUN_006baf80();
          iVar3 = DAT_00772400;
          if (((double)in_XMM0_Da != *(double *)(DAT_00772400 + 0xa090)) &&
             (*(double *)(DAT_00772400 + 0xa090) = (double)in_XMM0_Da,
             *(char *)(iVar3 + 0xa098) != '\0')) {
            *(undefined1 *)(iVar3 + 0xa098) = 1;
          }
          uVar6 = FUN_006bad90();
          FUN_006bc670(uVar6);
          FUN_006bad60();
          FUN_006bad60();
          uVar6 = 0;
        }
        else {
          if (piVar1 != (int *)0x0) {
            *piVar1 = *piVar1 + 1;
          }
          FUN_006bc6a0("unknown option",piVar1);
          uVar6 = 1;
        }
      }
    }
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0061efce:
  FUN_006bc0d0();
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

