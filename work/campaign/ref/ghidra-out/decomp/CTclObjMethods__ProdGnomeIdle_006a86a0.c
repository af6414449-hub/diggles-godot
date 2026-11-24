
undefined4
CTclObjMethods__ProdGnomeIdle(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar6;
  bool bVar7;
  undefined8 uVar8;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7cb0) &&
     (FUN_006cebf4(&DAT_00ca7cb0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7cb0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7cb4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::ProdGnomeIdle()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7cb0);
  }
  iVar5 = DAT_00ca7cb4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7cb4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,2,1);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x3e4) != 0) {
      uVar6 = extraout_ECX;
      if (2 < param_3) {
        puVar4 = (undefined4 *)FUN_004295e0(2);
        piVar1 = (int *)*puVar4;
        if (piVar1 == (int *)0x0) {
          cVar2 = FUN_006baf10();
          bVar7 = cVar2 == '\0';
          uVar6 = extraout_ECX_02;
        }
        else {
          *piVar1 = *piVar1 + 1;
          cVar2 = FUN_006baf10();
          bVar7 = cVar2 == '\0';
          *piVar1 = *piVar1 + -1;
          uVar6 = extraout_ECX_00;
          if (*piVar1 < 1) {
            TclFreeObj(piVar1);
            uVar6 = extraout_ECX_01;
          }
        }
        if (bVar7) {
          uVar6 = 0;
          *(undefined4 *)(*(int *)(iVar3 + 0x3e4) + 0x34) = 0;
          goto LAB_006a87ef;
        }
      }
      iVar3 = *(int *)(iVar3 + 0x3e4);
      FUN_005dc6a0(uVar6);
      *(undefined4 *)(iVar3 + 0x34) = 1;
      uVar6 = 0;
      goto LAB_006a87ef;
    }
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_24 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("no gnome",piVar1);
  }
  uVar6 = 1;
LAB_006a87ef:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

