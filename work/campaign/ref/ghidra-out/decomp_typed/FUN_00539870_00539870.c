
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00539870(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int this;
  undefined4 *puVar7;
  byte bVar8;
  uint uVar9;
  code *pcVar10;
  uint uVar11;
  bool bVar12;
  float fVar13;
  int *local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  float local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007032d3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = (int *)((*(int *)(this->i_34 + 0x18) -
                     *(int *)(this->i_34 + 0x10)) - this->i_c0);
  local_18 = this;
  FUN_00504a70(&local_2c);
  FUN_004fef30("data/gui/mnubg_map.tga");
  FUN_00504ba0(this + 0xbc);
  local_2c = 0x8a;
  local_28 = (int *)0x8a;
  FUN_004fee10(&local_2c);
  local_14 = (undefined4 *)0x0;
  if (this->i_e0 != 0) {
    FUN_004ff430(this + 0xe4,&local_14);
  }
  local_24 = 0x13;
  local_20 = (int *)&DAT_00000007;
  local_28 = (int *)FUN_006ba810(10);
  local_8 = 0;
  if (local_28 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/buttons/map_zoomout");
  FUN_00504a70(&local_24);
  FUN_00504ce0(uVar2);
  this->i_114 = uVar2;
  uVar2 = FUN_004435d0(&local_20,"Zoom out");
  piVar3 = (int *)FUN_00443730(uVar2);
  local_8 = 1;
  piVar4 = (int *)*piVar3;
  iVar5 = *(int *)(local_18 + 0x114);
  piVar1 = *(int **)(iVar5 + 0x30);
  *(int **)(iVar5 + 0x30) = piVar4;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x30) + 8) = *(undefined4 *)(*piVar3 + 8);
  local_8 = 2;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_24 = 0x16;
  local_20 = (int *)0x2a;
  local_28 = (int *)FUN_006ba810(10);
  local_8 = 3;
  if (local_28 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/buttons/map_zoomin");
  FUN_00504a70(&local_24);
  iVar5 = local_18;
  FUN_00504ce0(uVar2);
  *(undefined4 *)(iVar5 + 0x110) = uVar2;
  uVar2 = FUN_004435d0(&local_28,"Zoom in");
  piVar3 = (int *)FUN_00443730(uVar2);
  local_8 = 4;
  piVar4 = (int *)*piVar3;
  iVar5 = *(int *)(local_18 + 0x110);
  piVar1 = *(int **)(iVar5 + 0x30);
  *(int **)(iVar5 + 0x30) = piVar4;
  if (piVar4 != (int *)0x0) {
    *piVar4 = *piVar4 + 1;
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x30) + 8) = *(undefined4 *)(*piVar3 + 8);
  local_8 = 5;
  if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
    FUN_006ba940();
  }
  local_34 = (int *)0x0;
  local_30 = (undefined4 *)0x0;
  local_8 = 6;
  local_1c = 0.0;
  pcVar10 = RaiseException_exref;
  do {
    piVar4 = local_34;
    if (((uint)(local_30 + 0x40) & 0xffffff00) != ((int)local_30 + 0xffU & 0xffffff00)) {
      local_14 = (undefined4 *)(((uint)(local_30 + 0x40) & 0xffffff00) * 0xc);
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8._0_1_ = 7;
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)FUN_006ba810(0x9b);
        local_8 = CONCAT31(local_8._1_3_,6);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_34 = piVar4;
      }
      else if (local_14 == (undefined4 *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,8);
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        piVar1 = piVar4 + -7;
        iVar5 = FUN_006ba730();
        if (iVar5 == 0) {
          local_20 = (int *)piVar4[-2];
          local_14 = (undefined4 *)((int)(local_20 + 7) + (int)piVar1);
          iVar5 = FUN_006ba730();
          if (iVar5 != 0) goto LAB_00539bdd;
          if (piVar4[-5] != 0) {
            *(int *)(piVar4[-5] + 4) = piVar4[-6];
          }
          if (piVar4[-6] != 0) {
            *(int *)(piVar4[-6] + 8) = piVar4[-5];
          }
          if (piVar1 == DAT_00c3c81c) {
            DAT_00c3c81c = (int *)piVar4[-6];
          }
          _memset(piVar4,-0x20202021,(size_t)local_20);
          bVar12 = DAT_0077248f == '\0';
          *piVar1 = -0x20202021;
          piVar4[-1] = -0x20202021;
          *local_14 = 0xdfdfdfdf;
          if (((bVar12) || (DAT_00c1c788 == '\0')) ||
             ((piVar1 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar1)))) {
            FUN_006df631(piVar1);
            pcVar10 = RaiseException_exref;
          }
          else {
            FUN_006b8c20();
            pcVar10 = RaiseException_exref;
          }
        }
        else {
LAB_00539bdd:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar4,iVar5);
            _fflush(DAT_00c3c7d4);
          }
          pcVar10 = RaiseException_exref;
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,6);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_34 = (int *)0x0;
      }
      else {
        LOCK();
        _DAT_00c3c82c = _DAT_00c3c82c + 1;
        UNLOCK();
        piVar1 = piVar4 + -7;
        iVar5 = FUN_006ba730();
        if ((iVar5 != 0) || (iVar5 = FUN_006ba730(), iVar5 != 0)) {
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar4,iVar5);
            _fflush(DAT_00c3c7d4);
          }
          pcVar10 = RaiseException_exref;
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_34 = (int *)0x0;
          goto LAB_00539e2f;
        }
        local_20 = local_14 + 8;
        if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (piVar1 < DAT_00c3c7cc)) ||
           ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar1)) {
          piVar4 = (int *)FUN_006df8de(piVar1,local_20);
          if (piVar4 == (int *)0x0) {
            FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_20,piVar1);
            MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
            goto LAB_00539dcb;
          }
        }
        else {
          piVar4 = (int *)FUN_006b8a90();
LAB_00539dcb:
          if (piVar4 == (int *)0x0) {
            local_8 = CONCAT31(local_8._1_3_,6);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            pcVar10 = RaiseException_exref;
            local_34 = (int *)0x0;
            goto LAB_00539e2f;
          }
        }
        if (piVar1 == DAT_00c3c81c) {
          DAT_00c3c81c = piVar4;
        }
        piVar4[5] = (int)local_14;
        if (piVar4[1] != 0) {
          *(int **)(piVar4[1] + 8) = piVar4;
        }
        if (piVar4[2] != 0) {
          *(int **)(piVar4[2] + 4) = piVar4;
        }
        *(undefined4 *)((int)(piVar4 + 7) + (int)local_14) = 0xfab1ffcd;
        local_8 = CONCAT31(local_8._1_3_,6);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        pcVar10 = RaiseException_exref;
        local_34 = piVar4 + 7;
      }
    }
LAB_00539e2f:
    puVar7 = (undefined4 *)((int)local_30 + 1);
    local_14 = local_30;
    if (puVar7 <= local_30) {
      local_30 = puVar7;
      (*pcVar10)(0xc000008c,1,0,0);
      puVar7 = local_30;
    }
    local_30 = puVar7;
    piVar4 = local_34;
    local_20 = (int *)((int)local_14 * 0xc);
    fVar13 = local_1c;
    FUN_004089f0();
    *(float *)((int)local_20 + (int)piVar4) = fVar13 * 74.0 + 60.0;
    if (local_30 <= local_14) {
      (*pcVar10)(0xc000008c,1,0,0);
    }
    fVar13 = local_1c;
    FUN_004089d0();
    *(float *)((int)(local_20 + 1) + (int)local_34) = fVar13 * 74.0 + 168.0;
    local_1c = local_1c + 0.09817477;
  } while (local_1c < 6.2831855);
  if (DAT_0076a2a0 == (undefined4 *)0x0) {
    DAT_0076a2a0 = (undefined4 *)FUN_006ba810(0x12);
    if (DAT_0076a2a0 == (undefined4 *)0x0) {
      DAT_0076a2a0 = (undefined4 *)0x0;
    }
    else {
      *DAT_0076a2a0 = CPolyFill::vftable;
    }
  }
  iVar5 = local_18;
  piVar4 = (int *)(local_18 + 0x5c);
  local_20 = piVar4;
  FUN_00445e40(piVar4,&local_34);
  uVar11 = *(int *)(iVar5 + 0x60) - 1;
  if (-1 < (int)uVar11) {
    local_14 = (undefined4 *)(uVar11 * 0xc);
    do {
      if ((uint)piVar4[1] <= uVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *piVar4;
      if (*(int *)(iVar5 + 4 + (int)local_14) < 0xe2) {
        if ((uint)piVar4[1] <= uVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *piVar4;
        }
        if (*(int *)((int)local_14 + iVar5) < 0) {
          uVar9 = piVar4[1];
          if (uVar9 <= uVar11) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *piVar4;
            uVar9 = *(uint *)(local_18 + 0x60);
          }
          piVar4 = local_20;
          local_28 = (int *)(iVar5 + 8 + (int)local_14);
          if (uVar9 <= uVar11) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *piVar4;
          }
          *local_28 = *local_28 + *(int *)((int)local_14 + iVar5);
          if ((uint)piVar4[1] <= uVar11) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(undefined4 *)((int)local_14 + *piVar4) = 0;
        }
      }
      else {
        uVar9 = piVar4[1];
        if (uVar9 <= uVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar9 = piVar4[1];
          if (uVar9 <= uVar11) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar9 = piVar4[1];
          }
        }
        if ((int)uVar11 < (int)(uVar9 - 1)) {
          FUN_006d1b90((int)local_14 + *piVar4,(int)local_14 + *piVar4 + 0xc,
                       (uVar9 - uVar11) * 0xc + -0xc);
          uVar9 = piVar4[1];
        }
        piVar4[1] = uVar9 - 1;
      }
      local_14 = local_14 + -3;
      uVar11 = uVar11 - 1;
    } while (-1 < (int)uVar11);
  }
  local_8 = 9;
  if ((int)local_30 < 0) {
    FUN_00448980(-(int)local_30);
  }
  else if (0 < (int)local_30) {
    local_30 = (undefined4 *)0x0;
  }
  piVar4 = local_34;
  if (local_34 == (int *)0x0) {
    ExceptionList = local_10;
    return;
  }
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  if (piVar4 != (int *)0x0) {
    LOCK();
    _DAT_00c3c818 = _DAT_00c3c818 + 1;
    UNLOCK();
    piVar1 = piVar4 + -7;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    bVar12 = piVar4[-1] != -0x10324e01 || *piVar1 != -0x4e005433;
    bVar8 = bVar12 | 2;
    if (*piVar1 != -0x20202021) {
      bVar8 = bVar12;
    }
    if (bVar8 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_28 = (int *)piVar4[-2];
      local_20 = (int *)((int)(local_28 + 7) + (int)piVar1);
      pcVar6 = (char *)FUN_006ba730();
      if (pcVar6 == (char *)0x0) {
        if (piVar4[-5] != 0) {
          *(int *)(piVar4[-5] + 4) = piVar4[-6];
        }
        if (piVar4[-6] != 0) {
          *(int *)(piVar4[-6] + 8) = piVar4[-5];
        }
        if (piVar1 == DAT_00c3c81c) {
          DAT_00c3c81c = (int *)piVar4[-6];
        }
        _memset(piVar4,-0x20202021,(size_t)local_28);
        bVar12 = DAT_0077248f == '\0';
        *piVar1 = -0x20202021;
        piVar4[-1] = -0x20202021;
        *local_20 = -0x20202021;
        if (((bVar12) || (DAT_00c1c788 == '\0')) ||
           ((piVar1 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar1)))) {
          FUN_006df631(piVar1);
        }
        else {
          FUN_006b8c20();
        }
        goto LAB_0053a24f;
      }
    }
    else if (bVar8 == 3) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      pcVar6 = "already freed";
    }
    else if (bVar8 == 1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      pcVar6 = "corrupted";
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      pcVar6 = "corrupted freed";
    }
    if (DAT_00c3c7d4 != (FILE *)0x0) {
      FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar4,pcVar6);
      _fflush(DAT_00c3c7d4);
    }
    if (DAT_00c3c828 != '\0') {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
LAB_0053a24f:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  ExceptionList = local_10;
  return;
}

