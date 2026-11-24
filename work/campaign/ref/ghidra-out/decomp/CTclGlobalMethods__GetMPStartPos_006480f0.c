
/* WARNING: Removing unreachable block (ram,0x00648e1a) */
/* WARNING: Removing unreachable block (ram,0x00648e3e) */
/* WARNING: Removing unreachable block (ram,0x00648e51) */
/* WARNING: Removing unreachable block (ram,0x00648e64) */
/* WARNING: Removing unreachable block (ram,0x00648e6f) */
/* WARNING: Removing unreachable block (ram,0x00648e23) */
/* WARNING: Removing unreachable block (ram,0x00648e7a) */
/* WARNING: Removing unreachable block (ram,0x00648e85) */
/* WARNING: Removing unreachable block (ram,0x00648e87) */
/* WARNING: Removing unreachable block (ram,0x00648c4e) */
/* WARNING: Removing unreachable block (ram,0x00648c6f) */
/* WARNING: Removing unreachable block (ram,0x00648c82) */
/* WARNING: Removing unreachable block (ram,0x00648c92) */
/* WARNING: Removing unreachable block (ram,0x00648c95) */
/* WARNING: Removing unreachable block (ram,0x00648c9d) */
/* WARNING: Removing unreachable block (ram,0x00648cad) */
/* WARNING: Removing unreachable block (ram,0x00648cb0) */
/* WARNING: Removing unreachable block (ram,0x00648cb8) */
/* WARNING: Removing unreachable block (ram,0x00648cc8) */
/* WARNING: Removing unreachable block (ram,0x00648ccb) */
/* WARNING: Removing unreachable block (ram,0x00648cd3) */
/* WARNING: Removing unreachable block (ram,0x00648c57) */
/* WARNING: Removing unreachable block (ram,0x00648cde) */
/* WARNING: Removing unreachable block (ram,0x00648b5d) */
/* WARNING: Removing unreachable block (ram,0x00648bcd) */
/* WARNING: Removing unreachable block (ram,0x00648bde) */
/* WARNING: Removing unreachable block (ram,0x00648bf0) */
/* WARNING: Removing unreachable block (ram,0x00648bfc) */
/* WARNING: Removing unreachable block (ram,0x00648c0a) */
/* WARNING: Removing unreachable block (ram,0x00648f28) */
/* WARNING: Removing unreachable block (ram,0x00648f38) */
/* WARNING: Removing unreachable block (ram,0x00648c19) */
/* WARNING: Removing unreachable block (ram,0x00648d17) */
/* WARNING: Removing unreachable block (ram,0x00648ded) */
/* WARNING: Removing unreachable block (ram,0x00648e91) */
/* WARNING: Removing unreachable block (ram,0x00648f12) */
/* WARNING: Removing unreachable block (ram,0x00648ea0) */
/* WARNING: Removing unreachable block (ram,0x00648ea8) */
/* WARNING: Removing unreachable block (ram,0x00648e00) */
/* WARNING: Removing unreachable block (ram,0x00648e08) */
/* WARNING: Removing unreachable block (ram,0x00648d2a) */
/* WARNING: Removing unreachable block (ram,0x00648d32) */
/* WARNING: Removing unreachable block (ram,0x00648c37) */
/* WARNING: Removing unreachable block (ram,0x00648c3c) */
/* WARNING: Removing unreachable block (ram,0x00648b74) */
/* WARNING: Removing unreachable block (ram,0x00648b7e) */
/* WARNING: Removing unreachable block (ram,0x00648b9c) */
/* WARNING: Removing unreachable block (ram,0x00648ba5) */
/* WARNING: Removing unreachable block (ram,0x00648d44) */
/* WARNING: Removing unreachable block (ram,0x00648d68) */
/* WARNING: Removing unreachable block (ram,0x00648d7b) */
/* WARNING: Removing unreachable block (ram,0x00648d8e) */
/* WARNING: Removing unreachable block (ram,0x00648d96) */
/* WARNING: Removing unreachable block (ram,0x00648da9) */
/* WARNING: Removing unreachable block (ram,0x00648db4) */
/* WARNING: Removing unreachable block (ram,0x00648d4d) */
/* WARNING: Removing unreachable block (ram,0x00648dbf) */
/* WARNING: Removing unreachable block (ram,0x00648dca) */
/* WARNING: Removing unreachable block (ram,0x00648dcc) */
/* WARNING: Removing unreachable block (ram,0x00648dd1) */
/* WARNING: Removing unreachable block (ram,0x00648eba) */
/* WARNING: Removing unreachable block (ram,0x00648edb) */
/* WARNING: Removing unreachable block (ram,0x00648ec3) */
/* WARNING: Removing unreachable block (ram,0x00648ef9) */
/* WARNING: Removing unreachable block (ram,0x00648d01) */
/* WARNING: Removing unreachable block (ram,0x00648f61) */
/* WARNING: Removing unreachable block (ram,0x00648f69) */
/* WARNING: Removing unreachable block (ram,0x00648f73) */
/* WARNING: Removing unreachable block (ram,0x00648f76) */
/* WARNING: Removing unreachable block (ram,0x00648f85) */
/* WARNING: Removing unreachable block (ram,0x00648f88) */
/* WARNING: Removing unreachable block (ram,0x00648f8f) */
/* WARNING: Removing unreachable block (ram,0x00648f92) */
/* WARNING: Removing unreachable block (ram,0x00648bb6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclGlobalMethods__GetMPStartPos
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  size_t _Size;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  bool bVar10;
  undefined8 uVar11;
  int local_64;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  undefined4 *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  uint local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070de90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7100) &&
     (FUN_006cebf4(&DAT_00ca7100,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7100 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7104 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GetMPStartPos()";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7100);
  }
  iVar4 = DAT_00ca7104;
  local_40 = &DAT_00ca7104;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7104 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar11 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8._0_1_ = 2;
  if (param_3 != (undefined4 *)0x4) {
    FUN_006bc8f0(3);
    uVar5 = 1;
    goto LAB_00648fd3;
  }
  if (local_4c < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_54;
    if (local_50 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_50 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_54 + 3;
  }
  local_20 = (int *)*puVar7;
  if (local_20 != (int *)0x0) {
    *local_20 = *local_20 + 1;
  }
  puVar7 = (undefined4 *)0x0;
  param_3 = (undefined4 *)0x0;
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  iVar1 = 0;
  local_18 = local_20;
  while( true ) {
    local_24 = iVar1;
    if (local_20 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar2 = Tcl_ListObjLength(0,local_20,&local_28);
      iVar4 = local_28;
      if (iVar2 != 0) {
        iVar4 = 0;
      }
    }
    if (iVar4 <= iVar1) break;
    if ((local_20 == (int *)0x0) ||
       (iVar1 = Tcl_ListObjIndex(0,local_20,iVar1,&local_2c), iVar1 != 0)) {
      local_30 = (int *)0x0;
    }
    else {
      local_30 = local_2c;
      if (local_2c != (int *)0x0) {
        *local_2c = *local_2c + 1;
      }
    }
    piVar9 = local_30;
    if (local_30 == (int *)0x0) {
      local_1c = (int *)0x0;
    }
    else {
      iVar1 = Tcl_GetIntFromObj(0,local_30,&local_34);
      local_1c = (int *)(-(uint)(iVar1 != 1) & (uint)local_34);
    }
    local_3c = (undefined4 *)((int)local_44 + 1);
    if (((uint)(local_44 + 2) & 0xfffffff8) != ((int)local_44 + 7U & 0xfffffff8)) {
      local_14 = (undefined4 *)(((uint)(local_44 + 2) & 0xfffffff8) * 0xc);
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8._0_1_ = 6;
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)FUN_006ba810(0x9b);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        param_3 = puVar7;
        local_48 = puVar7;
      }
      else if (local_14 == (undefined4 *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 7;
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        puVar8 = puVar7 + -7;
        iVar1 = FUN_006ba730();
        if (iVar1 == 0) {
          local_14 = (undefined4 *)puVar7[-2];
          local_38 = (undefined4 *)((int)(local_14 + 7) + (int)puVar8);
          iVar1 = FUN_006ba730();
          if (iVar1 != 0) goto LAB_0064839b;
          if (puVar7[-5] != 0) {
            *(undefined4 *)(puVar7[-5] + 4) = puVar7[-6];
          }
          if (puVar7[-6] != 0) {
            *(undefined4 *)(puVar7[-6] + 8) = puVar7[-5];
          }
          if (puVar8 == DAT_00c3c81c) {
            DAT_00c3c81c = (undefined4 *)puVar7[-6];
          }
          _memset(param_3,-0x20202021,(size_t)local_14);
          bVar10 = DAT_0077248f == '\0';
          *puVar8 = 0xdfdfdfdf;
          puVar7[-1] = 0xdfdfdfdf;
          *local_38 = 0xdfdfdfdf;
          if (((bVar10) || (DAT_00c1c788 == '\0')) ||
             ((puVar8 < DAT_00c3c7cc || ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar8)
              ))) {
            FUN_006df631(puVar8);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_0064839b:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",param_3,iVar1);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        puVar7 = (undefined4 *)0x0;
        param_3 = puVar7;
        local_48 = puVar7;
      }
      else {
        LOCK();
        _DAT_00c3c82c = _DAT_00c3c82c + 1;
        UNLOCK();
        puVar8 = puVar7 + -7;
        iVar1 = FUN_006ba730();
        if ((iVar1 == 0) && (iVar1 = FUN_006ba730(), iVar1 == 0)) {
          local_38 = local_14 + 8;
          if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (puVar8 < DAT_00c3c7cc)) ||
             ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar8)) {
            puVar7 = (undefined4 *)FUN_006df8de(puVar8,local_38);
            if (puVar7 == (undefined4 *)0x0) {
              FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_38,puVar8)
              ;
              MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
              goto LAB_0064857f;
            }
          }
          else {
            puVar7 = (undefined4 *)FUN_006b8a90();
LAB_0064857f:
            if (puVar7 == (undefined4 *)0x0) goto LAB_006484e7;
          }
          if (puVar8 == DAT_00c3c81c) {
            DAT_00c3c81c = puVar7;
          }
          puVar7[5] = local_14;
          if (puVar7[1] != 0) {
            *(undefined4 **)(puVar7[1] + 8) = puVar7;
          }
          if (puVar7[2] != 0) {
            *(undefined4 **)(puVar7[2] + 4) = puVar7;
          }
          *(undefined4 *)((int)(puVar7 + 7) + (int)local_14) = 0xfab1ffcd;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          puVar7 = puVar7 + 7;
          param_3 = puVar7;
          local_48 = puVar7;
        }
        else {
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",puVar7,iVar1);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
LAB_006484e7:
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          puVar7 = (undefined4 *)0x0;
          param_3 = puVar7;
          local_48 = puVar7;
        }
      }
    }
    local_44 = local_3c;
    puVar7[(int)local_3c * 3 + -3] = local_1c;
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      TclFreeObj(piVar9);
    }
    iVar1 = local_24 + 1;
  }
  if (local_4c < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_54;
    if (local_50 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_50 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_54 + 2;
  }
  piVar9 = (int *)*puVar7;
  if (piVar9 != (int *)0x0) {
    *piVar9 = *piVar9 + 1;
  }
  local_34 = piVar9;
  if (local_4c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_54;
    if (local_50 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_50 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_54 + 1;
  }
  piVar3 = (int *)*puVar7;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,9);
  local_30 = piVar3;
  if (piVar9 == (int *)0x0) {
    local_24 = 0;
  }
  else {
    iVar1 = Tcl_GetIntFromObj(0,piVar9,&local_3c);
    local_24 = -(uint)(iVar1 != 1) & (uint)local_3c;
  }
  if (piVar3 == (int *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    iVar1 = Tcl_GetIntFromObj(0,piVar3,&local_38);
    if (iVar1 == 1) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = local_38;
    }
  }
  local_1c = piVar3;
  if (DAT_00772414 == 0) {
    local_2c = (int *)FUN_006ba810(0xd03);
    local_8._0_1_ = 10;
    if (local_2c == (int *)0x0) {
      DAT_00772414 = 0;
    }
    else {
      DAT_00772414 = FUN_00581470();
    }
    local_8 = CONCAT31(local_8._1_3_,9);
  }
  FUN_0058e120(&local_48,local_14,local_24);
  pcVar6 = TclFreeObj_exref;
  if ((local_1c != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar6 = TclFreeObj_exref, *piVar3 < 1))
  {
    TclFreeObj(piVar3);
  }
  if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
    (*pcVar6)(piVar9);
  }
  piVar9 = (int *)0x0;
  local_18 = (int *)0x0;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 < 1)) {
    (*pcVar6)(local_20);
  }
  local_20 = (undefined4 *)0x0;
  if (0 < (int)local_44) {
    piVar3 = param_3 + 2;
    bVar10 = local_44 != (undefined4 *)0x0;
    do {
      local_1c = piVar3;
      if (!bVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar9 = (int *)Tcl_NewIntObj(piVar3[-1]);
      *piVar9 = *piVar9 + 1;
      piVar3 = (int *)Tcl_NewListObj(0,0);
      if (piVar3 != (int *)0x0) {
        iVar1 = *piVar3;
        *piVar3 = iVar1 + 1;
        if (1 < iVar1 + 1) {
          *piVar3 = iVar1;
          if (iVar1 < 1) {
            TclFreeObj(piVar3);
          }
          piVar3 = (int *)Tcl_DuplicateObj(piVar3);
          *piVar3 = *piVar3 + 1;
        }
        if (*piVar9 < 2) {
          Tcl_ListObjAppendElement(0,piVar3,piVar9);
        }
        else {
          uVar5 = Tcl_DuplicateObj();
          Tcl_ListObjAppendElement(0,piVar3,uVar5);
        }
      }
      *piVar9 = *piVar9 + -1;
      if (*piVar9 < 1) {
        TclFreeObj(piVar9);
      }
      if (local_44 <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar9 = (int *)Tcl_NewIntObj(*local_1c);
      *piVar9 = *piVar9 + 1;
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)Tcl_NewListObj(0,0);
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
          goto LAB_00648887;
        }
      }
      else {
LAB_00648887:
        if (1 < *piVar3) {
          *piVar3 = *piVar3 + -1;
          piVar3 = (int *)Tcl_DuplicateObj(piVar3);
          *piVar3 = *piVar3 + 1;
        }
        if (*piVar9 < 2) {
          Tcl_ListObjAppendElement(0,piVar3,piVar9);
        }
        else {
          uVar5 = Tcl_DuplicateObj();
          Tcl_ListObjAppendElement(0,piVar3,uVar5);
        }
      }
      *piVar9 = *piVar9 + -1;
      if (*piVar9 < 1) {
        TclFreeObj(piVar9);
      }
      if (local_18 == (int *)0x0) {
        piVar9 = (int *)Tcl_NewListObj(0,0);
        local_18 = piVar9;
        if (piVar9 != (int *)0x0) {
          *piVar9 = *piVar9 + 1;
          goto LAB_006488f4;
        }
LAB_0064893a:
        if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
          TclFreeObj(piVar3);
        }
      }
      else {
LAB_006488f4:
        if (1 < *local_18) {
          *local_18 = *local_18 + -1;
          local_18 = (int *)Tcl_DuplicateObj(local_18);
          *local_18 = *local_18 + 1;
        }
        piVar9 = local_18;
        if (piVar3 != (int *)0x0) {
          if (*piVar3 < 2) {
            Tcl_ListObjAppendElement(0,local_18,piVar3);
          }
          else {
            uVar5 = Tcl_DuplicateObj();
            Tcl_ListObjAppendElement(0,piVar9,uVar5);
          }
          goto LAB_0064893a;
        }
      }
      local_20 = (int *)((int)local_20 + 1);
      piVar3 = local_1c + 3;
      bVar10 = local_20 < local_44;
      local_1c = piVar3;
    } while ((int)local_20 < (int)local_44);
  }
  if (local_64 != 0) {
    if (piVar9 == (int *)0x0) {
      Tcl_ResetResult(local_64);
    }
    else {
      Tcl_SetObjResult(local_64,piVar9);
    }
  }
  local_8._0_1_ = 0xb;
  if (((int)local_44 < 0) && (((int)local_44 + 7U & 0xfffffff8) != 0)) {
    local_3c = (undefined4 *)0x0;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    if (param_3 == (undefined4 *)0x0) {
      param_3 = (undefined4 *)FUN_006ba810(0x9b);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    else {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      LOCK();
      _DAT_00c3c818 = _DAT_00c3c818 + 1;
      UNLOCK();
      puVar7 = param_3 + -7;
      iVar1 = FUN_006ba730();
      if (iVar1 == 0) {
        _Size = param_3[-2];
        local_3c = (undefined4 *)(_Size + 0x1c + (int)puVar7);
        iVar1 = FUN_006ba730();
        if (iVar1 != 0) goto LAB_00648a6b;
        if (param_3[-5] != 0) {
          *(undefined4 *)(param_3[-5] + 4) = param_3[-6];
        }
        if (param_3[-6] != 0) {
          *(undefined4 *)(param_3[-6] + 8) = param_3[-5];
        }
        if (puVar7 == DAT_00c3c81c) {
          DAT_00c3c81c = (undefined4 *)param_3[-6];
        }
        _memset(param_3,-0x20202021,_Size);
        bVar10 = DAT_0077248f == '\0';
        *puVar7 = 0xdfdfdfdf;
        param_3[-1] = 0xdfdfdfdf;
        *local_3c = 0xdfdfdfdf;
        if ((((bVar10) || (DAT_00c1c788 == '\0')) || (puVar7 < DAT_00c3c7cc)) ||
           ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar7)) {
          FUN_006df631(puVar7);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_00648a6b:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",param_3,iVar1);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      param_3 = (undefined4 *)0x0;
    }
  }
  uVar5 = 0;
  if (param_3 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
    TclFreeObj(local_18);
  }
LAB_00648fd3:
  FUN_006bc0d0();
  local_8._0_1_ = 0xc;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_004297b0(0);
  if (local_54 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

