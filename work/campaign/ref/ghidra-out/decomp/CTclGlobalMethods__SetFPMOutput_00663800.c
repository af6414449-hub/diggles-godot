
undefined4
CTclGlobalMethods__SetFPMOutput
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f48d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7410) &&
     (FUN_006cebf4(&DAT_00ca7410,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7410 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7414 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SetFPMOutput()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7410);
  }
  iVar4 = DAT_00ca7414;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7414 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar3;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  uVar6 = 1;
  if (1 < param_3) {
    do {
      if ((int)uVar6 < local_1c) {
        if (local_20 <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar1 = (int *)*puVar5;
      puVar8 = &DAT_0073140c;
      if (piVar1 == (int *)0x0) {
        iVar2 = FUN_006d02c0(&PTR_0071ce50,&DAT_0073140c);
      }
      else {
        *piVar1 = *piVar1 + 1;
        uVar3 = Tcl_GetStringFromObj(piVar1,0);
        iVar2 = FUN_006d02c0(uVar3,puVar8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (iVar2 != 0) {
        *(uint *)(DAT_00772400 + 0x594) = *(uint *)(DAT_00772400 + 0x594) | 1;
      }
      if ((int)uVar6 < local_1c) {
        if (local_20 <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar1 = (int *)*puVar5;
      puVar8 = &DAT_00731410;
      if (piVar1 == (int *)0x0) {
        iVar2 = FUN_006d02c0(&PTR_0071ce50,&DAT_00731410);
      }
      else {
        *piVar1 = *piVar1 + 1;
        uVar3 = Tcl_GetStringFromObj(piVar1,0);
        iVar2 = FUN_006d02c0(uVar3,puVar8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (iVar2 != 0) {
        *(uint *)(DAT_00772400 + 0x594) = *(uint *)(DAT_00772400 + 0x594) & 0xfffffffe;
      }
      if ((int)uVar6 < local_1c) {
        if (local_20 <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar1 = (int *)*puVar5;
      puVar8 = &DAT_00731414;
      if (piVar1 == (int *)0x0) {
        iVar2 = FUN_006d02c0(&PTR_0071ce50,&DAT_00731414);
      }
      else {
        *piVar1 = *piVar1 + 1;
        uVar3 = Tcl_GetStringFromObj(piVar1,0);
        iVar2 = FUN_006d02c0(uVar3,puVar8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (iVar2 != 0) {
        *(uint *)(DAT_00772400 + 0x594) = *(uint *)(DAT_00772400 + 0x594) | 2;
      }
      if ((int)uVar6 < local_1c) {
        if (local_20 <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar1 = (int *)*puVar5;
      puVar8 = &DAT_00731418;
      if (piVar1 == (int *)0x0) {
        iVar2 = FUN_006d02c0(&PTR_0071ce50,&DAT_00731418);
      }
      else {
        *piVar1 = *piVar1 + 1;
        uVar3 = Tcl_GetStringFromObj(piVar1,0);
        iVar2 = FUN_006d02c0(uVar3,puVar8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (iVar2 != 0) {
        *(uint *)(DAT_00772400 + 0x594) = *(uint *)(DAT_00772400 + 0x594) & 0xfffffffd;
      }
      if ((int)uVar6 < local_1c) {
        if (local_20 <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar1 = (int *)*puVar5;
      puVar8 = &DAT_0073141c;
      if (piVar1 == (int *)0x0) {
        iVar2 = FUN_006d02c0(&PTR_0071ce50,&DAT_0073141c);
      }
      else {
        *piVar1 = *piVar1 + 1;
        uVar3 = Tcl_GetStringFromObj(piVar1,0);
        iVar2 = FUN_006d02c0(uVar3,puVar8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (iVar2 != 0) {
        *(uint *)(DAT_00772400 + 0x594) = *(uint *)(DAT_00772400 + 0x594) | 4;
      }
      if ((int)uVar6 < local_1c) {
        if (local_20 <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_24 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar1 = (int *)*puVar5;
      puVar8 = &DAT_00731420;
      if (piVar1 == (int *)0x0) {
        iVar2 = FUN_006d02c0(&PTR_0071ce50,&DAT_00731420);
      }
      else {
        *piVar1 = *piVar1 + 1;
        uVar3 = Tcl_GetStringFromObj(piVar1,0);
        iVar2 = FUN_006d02c0(uVar3,puVar8);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
      if (iVar2 != 0) {
        *(uint *)(DAT_00772400 + 0x594) = *(uint *)(DAT_00772400 + 0x594) & 0xfffffffb;
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < param_3);
  }
  local_8._0_1_ = 1;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

