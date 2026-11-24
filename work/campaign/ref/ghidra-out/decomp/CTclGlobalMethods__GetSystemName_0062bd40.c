
void CTclGlobalMethods__GetSystemName
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined **_Str1;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined8 uVar6;
  int local_234;
  DWORD local_224;
  undefined4 *local_220;
  uint local_21c;
  int local_218;
  CHAR local_214 [512];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c646;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d90) &&
     (FUN_006cebf4(&DAT_00ca6d90,local_14), iVar2 = DAT_00783650, DAT_00ca6d90 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6d94 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GetSystemName()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d90);
  }
  iVar5 = DAT_00ca6d94;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d94 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_218 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_220;
      if (local_21c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_220;
      }
    }
    else {
      if (local_21c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_220 + 1;
    }
    piVar3 = (int *)*puVar4;
    if (piVar3 == (int *)0x0) {
      _Str1 = &PTR_0071ce50;
    }
    else {
      *piVar3 = *piVar3 + 1;
      _Str1 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
      *piVar3 = *piVar3 + -1;
      if (*piVar3 < 1) {
        TclFreeObj(piVar3);
      }
    }
    local_224 = 0x200;
    iVar2 = __stricmp((char *)_Str1,"computer");
    if (iVar2 == 0) {
      GetComputerNameA(local_214,&local_224);
    }
    else {
      iVar2 = __stricmp((char *)_Str1,"user");
      if (iVar2 != 0) {
        puVar4 = (undefined4 *)FUN_004295e0(1);
        piVar3 = (int *)*puVar4;
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
        }
        FUN_006bc6a0("invalid option",piVar3);
        goto LAB_0062bf76;
      }
      GetUserNameA(local_214,&local_224);
    }
    piVar3 = (int *)Tcl_NewStringObj(local_214,0xffffffff);
    *piVar3 = *piVar3 + 1;
    iVar2 = *piVar3;
    if (local_234 != 0) {
      Tcl_SetObjResult(local_234,piVar3);
      iVar2 = *piVar3;
    }
    *piVar3 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar3);
    }
  }
  else {
    FUN_006bc8f0(1);
  }
LAB_0062bf76:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_220 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

