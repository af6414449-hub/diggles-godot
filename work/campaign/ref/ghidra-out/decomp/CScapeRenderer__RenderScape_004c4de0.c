
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CScapeRenderer__RenderScape(int *param_1,int *param_2,int *param_3,int *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  bool bVar10;
  undefined8 uVar11;
  float local_64;
  float local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  int local_34;
  uint local_30;
  int *local_2c;
  uint local_28;
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fe9fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c8aeac) &&
     (FUN_006cebf4(&DAT_00c8aeac,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00c8aeac == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00c8aeb0 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "CScapeRenderer::RenderScape";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c8aeac);
  }
  local_18 = (undefined4 *)(DAT_00c8aeb0 * 0x40);
  local_24 = &DAT_00c8aeb0;
  uVar6 = local_18[0x1dcd94];
  iVar4 = FUN_0043fcc0();
  puVar2 = local_18;
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar6;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = local_18[0x1dcd95];
  if (iVar4 == 0) {
    uVar11 = FUN_006bd180();
    iVar4 = puVar2[0x1dcd95];
    *(undefined8 *)(puVar2 + 0x1dcd96) = uVar11;
  }
  puVar1 = local_1c;
  puVar2[0x1dcd95] = iVar4 + 1;
  iVar4 = DAT_00772400;
  local_8 = 0;
  local_1c[0x40f] = 0x7f7fffff;
  local_1c[0x40e] = 0xff7fffff;
  *(undefined1 *)(local_1c + 0x410) = 0;
  local_1c[0x4c1] = 0;
  local_1c[0x4c2] = 0;
  local_1c[0x4c4] = 0;
  local_1c[0x4c3] = 0;
  local_1c[0x4be] = 0;
  local_1c[0x4c0] = *(undefined4 *)(iVar4 + 0x68);
  FUN_004ce630(0);
  FUN_004ce760(0);
  FUN_004ce630(0);
  FUN_004ce760(0);
  *puVar1 = *(undefined4 *)(DAT_00772400 + 100);
  local_2c = (int *)0x0;
  local_28 = 0;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8._0_1_ = 2;
  piVar5 = (int *)FUN_006ba810(0x9b);
  local_8 = CONCAT31(local_8._1_3_,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_28 = local_28 + 1;
  local_2c = piVar5;
  if (local_28 == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar5 = local_2c;
  *local_2c = *param_1;
  local_2c[1] = param_1[1];
  local_2c[2] = param_1[2];
  uVar8 = local_28 + 0x100 & 0xffffff00;
  if (uVar8 != (local_28 + 0xff & 0xffffff00)) {
    local_18 = (undefined4 *)(uVar8 * 0xc);
    local_14 = local_2c;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 4;
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)FUN_006ba810(0x9b);
    }
    else {
      if (local_18 == (undefined4 *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,5);
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        piVar9 = piVar5 + -7;
        iVar4 = FUN_006ba730();
        if (iVar4 == 0) {
          local_18 = (undefined4 *)piVar5[-2];
          local_20 = (int *)((int)(local_18 + 7) + (int)piVar9);
          iVar4 = FUN_006ba730();
          if (iVar4 != 0) goto LAB_004c5098;
          if (piVar5[-5] != 0) {
            *(int *)(piVar5[-5] + 4) = piVar5[-6];
          }
          if (piVar5[-6] != 0) {
            *(int *)(piVar5[-6] + 8) = piVar5[-5];
          }
          if (piVar9 == DAT_00c3c81c) {
            DAT_00c3c81c = (int *)piVar5[-6];
          }
          _memset(local_14,-0x20202021,(size_t)local_18);
          bVar10 = DAT_0077248f == '\0';
          *piVar9 = -0x20202021;
          piVar5[-1] = -0x20202021;
          *local_20 = -0x20202021;
          if (((bVar10) || (DAT_00c1c788 == '\0')) ||
             ((piVar9 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar9)))) {
            FUN_006df631(piVar9);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_004c5098:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_14,iVar4);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,1);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_2c = (int *)0x0;
        goto LAB_004c52e4;
      }
      LOCK();
      _DAT_00c3c82c = _DAT_00c3c82c + 1;
      UNLOCK();
      piVar5 = piVar5 + -7;
      iVar4 = FUN_006ba730();
      if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), iVar4 != 0)) {
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_14,iVar4);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
LAB_004c51e7:
        local_8 = CONCAT31(local_8._1_3_,1);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_2c = (int *)0x0;
        goto LAB_004c52e4;
      }
      local_20 = local_18 + 8;
      if ((DAT_0077248f == '\0') ||
         (((DAT_00c1c788 == '\0' || (piVar5 < DAT_00c3c7cc)) ||
          ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar5)))) {
        piVar5 = (int *)FUN_006df8de(piVar5,local_20);
        if (piVar5 == (int *)0x0) {
          FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_20,
                       local_14 + -7);
          MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
          goto LAB_004c5289;
        }
      }
      else {
        piVar5 = (int *)FUN_006b8a90();
LAB_004c5289:
        if (piVar5 == (int *)0x0) goto LAB_004c51e7;
      }
      piVar5[5] = (int)local_18;
      if (local_14 + -7 == DAT_00c3c81c) {
        DAT_00c3c81c = piVar5;
      }
      if (piVar5[1] != 0) {
        *(int **)(piVar5[1] + 8) = piVar5;
      }
      if (piVar5[2] != 0) {
        *(int **)(piVar5[2] + 4) = piVar5;
      }
      *(undefined4 *)((int)(piVar5 + 7) + (int)local_18) = 0xfab1ffcd;
      piVar5 = piVar5 + 7;
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_2c = piVar5;
  }
LAB_004c52e4:
  local_28 = local_28 + 1;
  if (local_28 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar5 = local_2c;
  local_2c[3] = *param_2;
  local_2c[4] = param_2[1];
  local_2c[5] = param_2[2];
  uVar8 = local_28 + 0x100 & 0xffffff00;
  if (uVar8 != (local_28 + 0xff & 0xffffff00)) {
    local_18 = (undefined4 *)(uVar8 * 0xc);
    local_14 = local_2c;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 6;
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)FUN_006ba810(0x9b);
    }
    else {
      if (local_18 == (undefined4 *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,7);
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        piVar9 = piVar5 + -7;
        iVar4 = FUN_006ba730();
        if (iVar4 == 0) {
          local_20 = (int *)piVar5[-2];
          local_18 = (undefined4 *)((int)(local_20 + 7) + (int)piVar9);
          iVar4 = FUN_006ba730();
          if (iVar4 != 0) goto LAB_004c53fc;
          if (piVar5[-5] != 0) {
            *(int *)(piVar5[-5] + 4) = piVar5[-6];
          }
          if (piVar5[-6] != 0) {
            *(int *)(piVar5[-6] + 8) = piVar5[-5];
          }
          if (piVar9 == DAT_00c3c81c) {
            DAT_00c3c81c = (int *)piVar5[-6];
          }
          _memset(local_14,-0x20202021,(size_t)local_20);
          bVar10 = DAT_0077248f == '\0';
          *piVar9 = -0x20202021;
          piVar5[-1] = -0x20202021;
          *local_18 = 0xdfdfdfdf;
          if (((bVar10) || (DAT_00c1c788 == '\0')) ||
             ((piVar9 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar9)))) {
            FUN_006df631(piVar9);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_004c53fc:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_14,iVar4);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8 = CONCAT31(local_8._1_3_,1);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_2c = (int *)0x0;
        goto LAB_004c5644;
      }
      LOCK();
      _DAT_00c3c82c = _DAT_00c3c82c + 1;
      UNLOCK();
      piVar5 = piVar5 + -7;
      iVar4 = FUN_006ba730();
      if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), iVar4 != 0)) {
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_14,iVar4);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
LAB_004c5549:
        local_8 = CONCAT31(local_8._1_3_,1);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_2c = (int *)0x0;
        goto LAB_004c5644;
      }
      local_20 = local_18 + 8;
      if ((DAT_0077248f == '\0') ||
         (((DAT_00c1c788 == '\0' || (piVar5 < DAT_00c3c7cc)) ||
          ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar5)))) {
        piVar5 = (int *)FUN_006df8de(piVar5,local_20);
        if (piVar5 == (int *)0x0) {
          FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_20,
                       local_14 + -7);
          MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
          goto LAB_004c55ea;
        }
      }
      else {
        piVar5 = (int *)FUN_006b8a90();
LAB_004c55ea:
        if (piVar5 == (int *)0x0) goto LAB_004c5549;
      }
      piVar5[5] = (int)local_18;
      if (local_14 + -7 == DAT_00c3c81c) {
        DAT_00c3c81c = piVar5;
      }
      if (piVar5[1] != 0) {
        *(int **)(piVar5[1] + 8) = piVar5;
      }
      if (piVar5[2] != 0) {
        *(int **)(piVar5[2] + 4) = piVar5;
      }
      *(undefined4 *)((int)(piVar5 + 7) + (int)local_18) = 0xfab1ffcd;
      piVar5 = piVar5 + 7;
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_2c = piVar5;
  }
LAB_004c5644:
  local_28 = local_28 + 1;
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar5 = local_2c;
  local_2c[6] = *param_4;
  local_2c[7] = param_4[1];
  local_2c[8] = param_4[2];
  uVar8 = local_28 + 0x100 & 0xffffff00;
  if (uVar8 == (local_28 + 0xff & 0xffffff00)) goto LAB_004c59a4;
  local_18 = (undefined4 *)(uVar8 * 0xc);
  local_14 = local_2c;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8._0_1_ = 8;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)FUN_006ba810(0x9b);
  }
  else {
    if (local_18 == (undefined4 *)0x0) {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8 = CONCAT31(local_8._1_3_,9);
      LOCK();
      _DAT_00c3c818 = _DAT_00c3c818 + 1;
      UNLOCK();
      piVar9 = piVar5 + -7;
      iVar4 = FUN_006ba730();
      if (iVar4 == 0) {
        local_20 = (int *)piVar5[-2];
        local_18 = (undefined4 *)((int)(local_20 + 7) + (int)piVar9);
        iVar4 = FUN_006ba730();
        if (iVar4 != 0) goto LAB_004c575c;
        if (piVar5[-5] != 0) {
          *(int *)(piVar5[-5] + 4) = piVar5[-6];
        }
        if (piVar5[-6] != 0) {
          *(int *)(piVar5[-6] + 8) = piVar5[-5];
        }
        if (piVar9 == DAT_00c3c81c) {
          DAT_00c3c81c = (int *)piVar5[-6];
        }
        _memset(local_14,-0x20202021,(size_t)local_20);
        bVar10 = DAT_0077248f == '\0';
        *piVar9 = -0x20202021;
        piVar5[-1] = -0x20202021;
        *local_18 = 0xdfdfdfdf;
        if (((bVar10) || (DAT_00c1c788 == '\0')) ||
           ((piVar9 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar9)))) {
          FUN_006df631(piVar9);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_004c575c:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_14,iVar4);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8 = CONCAT31(local_8._1_3_,1);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_2c = (int *)0x0;
      goto LAB_004c59a4;
    }
    LOCK();
    _DAT_00c3c82c = _DAT_00c3c82c + 1;
    UNLOCK();
    piVar5 = piVar5 + -7;
    iVar4 = FUN_006ba730();
    if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), iVar4 != 0)) {
      if (DAT_00c3c7d4 != (FILE *)0x0) {
        FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_14,iVar4);
        _fflush(DAT_00c3c7d4);
      }
      if (DAT_00c3c828 != '\0') {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
LAB_004c58a9:
      local_8 = CONCAT31(local_8._1_3_,1);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_2c = (int *)0x0;
      goto LAB_004c59a4;
    }
    local_20 = local_18 + 8;
    if ((DAT_0077248f == '\0') ||
       (((DAT_00c1c788 == '\0' || (piVar5 < DAT_00c3c7cc)) ||
        ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar5)))) {
      piVar5 = (int *)FUN_006df8de(piVar5,local_20);
      if (piVar5 == (int *)0x0) {
        FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_20,local_14 + -7
                    );
        MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
        goto LAB_004c594a;
      }
    }
    else {
      piVar5 = (int *)FUN_006b8a90();
LAB_004c594a:
      if (piVar5 == (int *)0x0) goto LAB_004c58a9;
    }
    piVar5[5] = (int)local_18;
    if (local_14 + -7 == DAT_00c3c81c) {
      DAT_00c3c81c = piVar5;
    }
    if (piVar5[1] != 0) {
      *(int **)(piVar5[1] + 8) = piVar5;
    }
    if (piVar5[2] != 0) {
      *(int **)(piVar5[2] + 4) = piVar5;
    }
    *(undefined4 *)((int)(piVar5 + 7) + (int)local_18) = 0xfab1ffcd;
    piVar5 = piVar5 + 7;
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_2c = piVar5;
LAB_004c59a4:
  local_28 = local_28 + 1;
  if (local_28 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_2c[9] = *param_3;
  local_2c[10] = param_3[1];
  local_2c[0xb] = param_3[2];
  FUN_006b8fb0(&DAT_00724868);
  local_8._0_1_ = 10;
  uVar6 = FUN_0042fd30(&local_20);
  local_8._0_1_ = 0xb;
  FUN_006b9290(uVar6);
  local_8._0_1_ = 0xc;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 10;
  uVar6 = FUN_0042fd30(&param_1);
  local_8._0_1_ = 0xd;
  FUN_006b9290(uVar6);
  local_8._0_1_ = 0xe;
  if ((param_1 != (int *)0x0) && (*param_1 = *param_1 + -1, *param_1 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 10;
  uVar6 = FUN_0042fd30(&param_1);
  local_8._0_1_ = 0xf;
  FUN_006b9290(uVar6);
  local_8._0_1_ = 0x10;
  if ((param_1 != (int *)0x0) && (*param_1 = *param_1 + -1, *param_1 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 10;
  uVar6 = FUN_0042fd30(&param_1);
  local_8._0_1_ = 0x11;
  FUN_006b9290(uVar6);
  local_8._0_1_ = 0x12;
  if ((param_1 != (int *)0x0) && (*param_1 = *param_1 + -1, *param_1 == 0)) {
    FUN_006ba940();
  }
  local_34 = 0;
  local_30 = 0;
  local_8 = CONCAT31(local_8._1_3_,0x13);
  FUN_00445dd0(&local_34,&local_2c);
  FUN_00445e40();
  local_5c = 0;
  local_60 = 0.0;
  local_64 = 0.0;
  local_50 = 0;
  local_54 = 0.0;
  local_58 = 0.0;
  local_44 = 0;
  local_48 = 0.0;
  local_4c = 0.0;
  local_38 = 0;
  local_3c = 0.0;
  local_40 = 0.0;
  param_2 = (int *)0x0;
  if (0 < (int)local_30) {
    bVar10 = local_30 != 0;
    local_18 = (undefined4 *)0x0;
    do {
      puVar2 = local_18;
      if (!bVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)(local_34 + (int)puVar2);
      if (local_30 <= param_2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      param_1 = (int *)0x0;
      iVar7 = *(int *)(local_34 + 4 + (int)puVar2);
      if ((*(int *)(DAT_0077241c + 0x88) + 2 < iVar7) &&
         (iVar7 < *(int *)(DAT_0077241c + 0x90) + -2)) {
        param_4 = (int *)0x0;
        while( true ) {
          if (local_30 <= param_2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*(int *)(local_34 + 8 + (int)local_18) <= (int)param_4) break;
          if (((*(int *)(DAT_0077241c + 0x84) + 2 < iVar4) &&
              (iVar4 < *(int *)(DAT_0077241c + 0x8c) + -2)) &&
             (piVar5 = (int *)FUN_00592f10(iVar4,iVar7), *piVar5 != -1)) {
            cVar3 = FUN_004c8480(iVar4,iVar7);
            if (cVar3 == '\0') {
              if (0 < (int)param_1) {
                FUN_004cca20(&local_64,&local_58,&local_4c,&local_40);
                param_1 = (int *)0x0;
              }
              goto LAB_004c5c9d;
            }
            local_54 = (float)iVar7;
            if (param_1 == (int *)0x0) {
              local_64 = (float)iVar4;
              local_48 = (float)(iVar7 + 1);
              local_60 = local_54;
              local_4c = local_64;
            }
            param_1 = (int *)((int)param_1 + 1);
            local_58 = (float)(iVar4 + 1);
            iVar4 = iVar4 + 1;
            param_4 = (int *)((int)param_4 + 1);
            local_3c = (float)(iVar7 + 1);
            local_40 = local_58;
          }
          else {
LAB_004c5c9d:
            iVar4 = iVar4 + 1;
            param_4 = (int *)((int)param_4 + 1);
          }
        }
        if (0 < (int)param_1) {
          FUN_004cca20(&local_64,&local_58,&local_4c,&local_40);
        }
      }
      param_2 = (int *)((int)param_2 + 1);
      local_18 = local_18 + 3;
      bVar10 = param_2 < local_30;
    } while ((int)param_2 < (int)local_30);
  }
  FUN_004c5e20();
  FUN_004c6030();
  if (*(char *)(local_1c + 0x410) == '\0') {
    uVar6 = local_1c[0x40f];
  }
  else {
    uVar6 = 0xff7fffff;
  }
  local_1c[0x40e] = uVar6;
  _DAT_00772350 = _DAT_00772350 + 1;
  local_8 = CONCAT31(local_8._1_3_,0x14);
  if ((int)local_30 < 0) {
    FUN_00448980(-local_30);
  }
  else if (0 < (int)local_30) {
    local_30 = 0;
    FUN_00448a90(0);
  }
  if (local_34 != 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x15;
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x16);
  if ((int)local_28 < 0) {
    FUN_00448980(-local_28);
  }
  else if (0 < (int)local_28) {
    local_28 = 0;
    FUN_00448a90(0);
  }
  if (local_2c != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

