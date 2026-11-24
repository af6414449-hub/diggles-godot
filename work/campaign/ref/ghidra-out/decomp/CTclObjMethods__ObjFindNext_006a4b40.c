
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclObjMethods__ObjFindNext(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  BOOL BVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  code *pcVar13;
  bool bVar14;
  float fVar15;
  void *pvVar16;
  float fVar17;
  undefined8 uVar18;
  int local_7c;
  undefined4 *local_6c;
  uint local_68;
  int local_64;
  double local_60;
  double local_58;
  int *local_50;
  int *local_4c;
  int *local_48;
  undefined4 *local_44;
  void *local_40;
  int *local_3c;
  uint local_38;
  int *local_34;
  void *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007123ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c68) &&
     (FUN_006cebf4(&DAT_00ca7c68,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7c68 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7c6c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::ObjFindNext()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c68);
  }
  iVar8 = DAT_00ca7c6c;
  local_44 = &DAT_00ca7c6c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c6c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar18 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar18;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_30 = (void *)FUN_005c71c0(param_4,3,1);
  if (local_30 == (void *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_006a4c26:
    FUN_004297b0(0);
    if (local_6c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_64 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_6c;
    if (local_68 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_68 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_6c + 2;
  }
  piVar9 = (int *)*puVar6;
  if (piVar9 != (int *)0x0) {
    *piVar9 = *piVar9 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_48 = piVar9;
  local_2c = piVar9;
  if (piVar9 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
  }
  FUN_006b8fb0(ppuVar5);
  local_28 = (int *)DAT_00772478;
  cVar3 = FUN_006037d0(&local_20,&local_24);
  if (cVar3 == '\0') {
    local_28 = (int *)0x0;
  }
  else {
    if (*(int **)((int)local_28 + 0x801c) <= local_24) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_28 = *(int **)(*(int *)((int)local_28 + 0x8018) + (int)local_24 * 4);
  }
  local_8._0_1_ = 6;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 5;
  if (local_28 == (int *)0x0) {
    if (local_64 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_6c;
      if (local_68 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_68 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_6c + 2;
    }
    piVar10 = (int *)*puVar6;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    FUN_006bc6a0("unknown class",piVar10);
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      TclFreeObj(piVar9);
    }
    local_8._0_1_ = 7;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,8);
    goto LAB_006a4c26;
  }
  local_58 = 1.7976931348623157e+308;
  if (param_3 == 4) {
    puVar6 = (undefined4 *)FUN_004295e0(3);
    piVar9 = (int *)*puVar6;
    if (piVar9 == (int *)0x0) {
      local_58 = 0.0;
    }
    else {
      *piVar9 = *piVar9 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar9,&local_60);
      if (iVar4 == 1) {
        fVar15 = 0.0;
      }
      else {
        fVar15 = (float)local_60;
      }
      *piVar9 = *piVar9 + -1;
      local_58 = (double)fVar15;
      if (*piVar9 < 1) {
        TclFreeObj(piVar9);
      }
    }
  }
  piVar10 = (int *)0x0;
  piVar9 = (int *)0x0;
  local_1c = (int *)0x0;
  local_50 = (int *)0x0;
  local_4c = (int *)0x0;
  local_18 = *(int **)((int)local_30 + 0xc);
  local_24 = *(int **)((int)local_30 + 0x10);
  local_38 = *(uint *)((int)local_30 + 0x36c);
  local_34 = (int *)0x0;
  do {
    local_20 = (int *)(DAT_0077244c + 0x488);
    if (local_34 < (int *)0x2000) {
      piVar12 = local_20 + (int)local_34;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar12 = local_20;
      piVar9 = local_4c;
    }
    local_40 = (void *)*piVar12;
    if ((((local_40 != (void *)0x0) && (local_40 != local_30)) &&
        (*(int **)((int)local_40 + 0xd4) == local_28)) &&
       ((((byte)*(undefined4 *)((int)local_40 + 0x3d0) & 5) == 1 &&
        (*(uint *)((int)local_40 + 0x36c) == local_38)))) {
      fVar17 = *(float *)((int)local_40 + 0xc) - (float)local_18;
      fVar15 = *(float *)((int)local_40 + 0x10) - (float)local_24;
      fVar15 = fVar15 * fVar15 + fVar17 * fVar17;
      FUN_0040b7e0();
      piVar9 = local_4c;
      if ((double)fVar15 < local_58) {
        local_3c = (int *)((int)local_4c + 1);
        if (((uint)(local_4c + 4) & 0xfffffff0) != ((int)local_4c + 0xfU & 0xfffffff0)) {
          local_20 = (int *)(((uint)(local_4c + 4) & 0xfffffff0) * 4);
          if (DAT_00c3c824 == 0) {
            DAT_00c3c824 = 1;
            InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_8._0_1_ = 10;
          if (piVar10 == (int *)0x0) {
            piVar10 = (int *)FUN_006ba810(0x9b);
          }
          else {
            if (local_20 == (int *)0x0) {
              if (DAT_00c3c824 == 0) {
                DAT_00c3c824 = 1;
                InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              }
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              local_8._0_1_ = 0xb;
              LOCK();
              _DAT_00c3c818 = _DAT_00c3c818 + 1;
              UNLOCK();
              iVar4 = FUN_006ba730();
              if (iVar4 == 0) {
                local_20 = (int *)piVar10[-2];
                local_1c = (int *)((int)local_20 + (int)piVar10);
                iVar4 = FUN_006ba730();
                if (iVar4 != 0) goto LAB_006a5023;
                if (piVar10[-5] != 0) {
                  *(int *)(piVar10[-5] + 4) = piVar10[-6];
                }
                if (piVar10[-6] != 0) {
                  *(int *)(piVar10[-6] + 8) = piVar10[-5];
                }
                if (piVar10 + -7 == DAT_00c3c81c) {
                  DAT_00c3c81c = (int *)piVar10[-6];
                }
                _memset(piVar10,-0x20202021,(size_t)local_20);
                piVar9 = piVar10 + -7;
                *piVar9 = -0x20202021;
                bVar14 = DAT_0077248f == '\0';
                piVar10[-1] = -0x20202021;
                *local_1c = -0x20202021;
                if (((bVar14) || (DAT_00c1c788 == '\0')) ||
                   ((piVar9 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar9))
                   )) {
                  FUN_006df631(piVar9);
                }
                else {
                  FUN_006b8c20();
                }
              }
              else {
LAB_006a5023:
                if (DAT_00c3c7d4 != (FILE *)0x0) {
                  FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar10,iVar4);
                  _fflush(DAT_00c3c7d4);
                }
                if (DAT_00c3c828 != '\0') {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              piVar10 = (int *)0x0;
              local_50 = piVar10;
              goto LAB_006a5257;
            }
            LOCK();
            _DAT_00c3c82c = _DAT_00c3c82c + 1;
            UNLOCK();
            local_1c = piVar10 + -7;
            iVar4 = FUN_006ba730();
            if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), iVar4 != 0)) {
              if (DAT_00c3c7d4 != (FILE *)0x0) {
                FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar10,iVar4);
                _fflush(DAT_00c3c7d4);
              }
              if (DAT_00c3c828 != '\0') {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
LAB_006a516d:
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              piVar10 = (int *)0x0;
              local_50 = piVar10;
              goto LAB_006a5257;
            }
            if ((DAT_0077248f == '\0') ||
               (((DAT_00c1c788 == '\0' || (local_1c < DAT_00c3c7cc)) ||
                ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_1c)))) {
              piVar10 = (int *)FUN_006df8de(local_1c,local_20 + 8);
              if (piVar10 == (int *)0x0) {
                FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_20 + 8,
                             local_1c);
                MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
                goto LAB_006a5209;
              }
            }
            else {
              piVar10 = (int *)FUN_006b8a90();
LAB_006a5209:
              if (piVar10 == (int *)0x0) goto LAB_006a516d;
            }
            if (local_1c == DAT_00c3c81c) {
              DAT_00c3c81c = piVar10;
            }
            piVar10[5] = (int)local_20;
            if (piVar10[1] != 0) {
              *(int **)(piVar10[1] + 8) = piVar10;
            }
            if (piVar10[2] != 0) {
              *(int **)(piVar10[2] + 4) = piVar10;
            }
            *(undefined4 *)((int)(piVar10 + 7) + (int)local_20) = 0xfab1ffcd;
            piVar10 = piVar10 + 7;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_50 = piVar10;
        }
LAB_006a5257:
        local_4c = local_3c;
        if (local_3c <= (int *)((int)local_3c + -1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10[(int)local_4c + -1] = (int)local_40;
        piVar9 = local_4c;
      }
    }
    local_34 = (int *)((int)local_34 + 1);
  } while ((int)local_34 < 0x2000);
  piVar12 = (int *)((int)piVar9 + -1);
  local_3c = piVar12;
  local_1c = piVar10;
  do {
    local_11 = '\0';
    piVar11 = (int *)0x0;
    if ((int)piVar12 < 1) break;
    do {
      if (piVar9 <= piVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar15 = *(float *)(piVar10[(int)piVar11] + 0xc) - (float)local_18;
      fVar17 = *(float *)(piVar10[(int)piVar11] + 0x10) - (float)local_24;
      pvVar16 = (void *)(fVar15 * fVar15 + fVar17 * fVar17);
      FUN_0040b7e0();
      local_28 = (int *)((int)piVar11 + 1);
      local_40 = pvVar16;
      if (local_4c <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar15 = *(float *)(piVar10[(int)piVar11 + 1] + 0xc) - (float)local_18;
      fVar17 = *(float *)(piVar10[(int)piVar11 + 1] + 0x10) - (float)local_24;
      fVar15 = fVar15 * fVar15 + fVar17 * fVar17;
      FUN_0040b7e0();
      if (fVar15 < (float)local_40) {
        if (local_4c <= piVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_40 = (void *)piVar10[(int)piVar11];
        if (local_4c <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (local_4c <= piVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10[(int)piVar11] = piVar10[(int)piVar11 + 1];
        if (local_4c <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10[(int)piVar11 + 1] = (int)local_40;
        local_11 = '\x01';
      }
      piVar9 = local_4c;
      piVar11 = local_28;
    } while ((int)local_28 < (int)local_3c);
    piVar12 = (int *)((int)local_4c + -1);
  } while (local_11 != '\0');
  piVar10 = local_2c;
  piVar12 = (int *)0x0;
  local_24 = (int *)0x0;
  if (piVar9 == (int *)0x0) {
    piVar12 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
    iVar4 = *piVar12;
    *piVar12 = iVar4 + 1;
    piVar9 = local_4c;
    local_24 = piVar12;
    if (iVar4 + 1 < 1) {
      TclFreeObj(piVar12);
      piVar9 = local_4c;
    }
  }
  local_20 = (int *)0x0;
  if (0 < (int)piVar9) {
    bVar14 = piVar9 != (int *)0x0;
    do {
      if (!bVar14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar9 = local_1c;
      local_40 = (void *)local_1c[(int)local_20];
      if (((local_40 == (void *)0x0) || (BVar7 = IsBadReadPtr(local_40,0x10), BVar7 != 0)) ||
         ((*(int *)((int)local_40 + 8) != 0x616e4f62 ||
          ((DAT_00768398 != '\0' && (*(int *)((int)local_40 + 0xdc) == 0)))))) {
        if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 < 1)) {
          TclFreeObj(local_24);
        }
        local_8 = CONCAT31(local_8._1_3_,0xc);
        if (-1 < (int)local_4c) goto LAB_006a5c3f;
        local_34 = (int *)-(int)local_4c;
        local_38 = 0;
        if (((int)local_4c + 0xfU & 0xfffffff0) == 0) goto LAB_006a5c19;
        local_24 = (int *)0x0;
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        if (piVar9 == (int *)0x0) {
          piVar9 = (int *)FUN_006ba810(0x9b);
          goto LAB_006a5c0b;
        }
        if (local_24 == (int *)0x0) {
          if (DAT_00c3c824 == 0) {
            DAT_00c3c824 = 1;
            InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          LOCK();
          _DAT_00c3c818 = _DAT_00c3c818 + 1;
          UNLOCK();
          iVar4 = FUN_006ba730();
          if (iVar4 == 0) {
            local_40 = (void *)piVar9[-2];
            local_3c = (int *)((int)local_40 + (int)piVar9);
            iVar4 = FUN_006ba730();
            if (iVar4 != 0) goto LAB_006a56ba;
            if (piVar9[-5] != 0) {
              *(int *)(piVar9[-5] + 4) = piVar9[-6];
            }
            if (piVar9[-6] != 0) {
              *(int *)(piVar9[-6] + 8) = piVar9[-5];
            }
            if (piVar9 + -7 == DAT_00c3c81c) {
              DAT_00c3c81c = (int *)piVar9[-6];
            }
            _memset(piVar9,-0x20202021,(size_t)local_40);
            piVar12 = piVar9 + -7;
            *piVar12 = -0x20202021;
            bVar14 = DAT_0077248f == '\0';
            piVar9[-1] = -0x20202021;
            *local_3c = -0x20202021;
            if ((((bVar14) || (DAT_00c1c788 == '\0')) || (piVar12 < DAT_00c3c7cc)) ||
               ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar12)) {
              FUN_006df631(piVar12);
            }
            else {
              FUN_006b8c20();
            }
          }
          else {
LAB_006a56ba:
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar9,iVar4);
              _fflush(DAT_00c3c7d4);
            }
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          piVar9 = (int *)0x0;
        }
        else {
          LOCK();
          _DAT_00c3c82c = _DAT_00c3c82c + 1;
          UNLOCK();
          local_1c = piVar9 + -7;
          iVar4 = FUN_006ba730();
          if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), piVar12 = local_1c, iVar4 != 0)) {
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar9,iVar4);
              _fflush(DAT_00c3c7d4);
            }
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            goto LAB_006a5804;
          }
          local_18 = local_24 + 8;
          if (((DAT_0077248f == '\0') || ((DAT_00c1c788 == '\0' || (local_1c < DAT_00c3c7cc)))) ||
             ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_1c)) {
            piVar12 = (int *)FUN_006df8de(local_1c,local_18);
            if (piVar12 != (int *)0x0) goto LAB_006a5bd6;
            FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_18,local_1c)
            ;
            MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
            goto LAB_006a5bce;
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          cVar3 = FUN_006c4d20(piVar12);
          if (cVar3 != '\0') {
            if (&DAT_00000040 < local_18) {
              if (DAT_00c1c788 == '\0') {
                piVar12 = (int *)FUN_006ba810(0x1fd);
              }
              else {
                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                if (((((int *)0x100 < local_18) ||
                     (piVar12 = (int *)FUN_006c4b80(), piVar12 == (int *)0x0)) &&
                    (((int *)0x400 < local_18 ||
                     (piVar12 = (int *)FUN_006c4b80(), piVar12 == (int *)0x0)))) &&
                   (((int *)0x1000 < local_18 ||
                    (piVar12 = (int *)FUN_006c4b80(), piVar12 == (int *)0x0)))) {
                  piVar12 = (int *)FUN_006c4530(local_18);
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              iVar4 = local_1c[1];
              iVar8 = local_1c[2];
              iVar2 = local_1c[3];
              *piVar12 = *local_1c;
              piVar12[1] = iVar4;
              piVar12[2] = iVar8;
              piVar12[3] = iVar2;
              iVar4 = local_1c[5];
              iVar8 = local_1c[6];
              iVar2 = local_1c[7];
              piVar12[4] = local_1c[4];
              piVar12[5] = iVar4;
              piVar12[6] = iVar8;
              piVar12[7] = iVar2;
              iVar4 = local_1c[9];
              iVar8 = local_1c[10];
              iVar2 = local_1c[0xb];
              piVar12[8] = local_1c[8];
              piVar12[9] = iVar4;
              piVar12[10] = iVar8;
              piVar12[0xb] = iVar2;
              iVar4 = local_1c[0xd];
              iVar8 = local_1c[0xe];
              iVar2 = local_1c[0xf];
              piVar12[0xc] = local_1c[0xc];
              piVar12[0xd] = iVar4;
              piVar12[0xe] = iVar8;
              piVar12[0xf] = iVar2;
LAB_006a5956:
              FUN_006c4d70(local_1c);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            else {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            goto LAB_006a5bce;
          }
          cVar3 = FUN_006c4d20(piVar12);
          if (cVar3 == '\0') {
            cVar3 = FUN_006c4d20(piVar12);
            if (cVar3 == '\0') {
              cVar3 = FUN_006c4d20(piVar12);
              if (cVar3 == '\0') {
                piVar12 = (int *)FUN_006c4620(piVar12,local_18);
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              else {
                if ((int *)0x1000 < local_18) {
                  if (DAT_00c1c788 == '\0') {
                    piVar12 = (int *)FUN_006ba810(0x1fd);
                  }
                  else {
                    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                    piVar12 = (int *)FUN_006c4530(local_18);
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  }
                  FUN_006d2250(piVar12,local_1c,0x1000);
                  goto LAB_006a5956;
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              goto LAB_006a5bce;
            }
            if (local_18 < (int *)0x401) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              goto LAB_006a5bce;
            }
            if (DAT_00c1c788 == '\0') {
              local_20 = (int *)FUN_006ba810(0x1fd);
              piVar9 = local_20;
              for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                *piVar9 = *piVar12;
                piVar12 = piVar12 + 1;
                piVar9 = piVar9 + 1;
              }
            }
            else {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              if (local_18 < (int *)0x1001) {
                piVar9 = (int *)FUN_006c4b80();
                if (piVar9 == (int *)0x0) {
                  local_20 = (int *)0x0;
                  goto LAB_006a5acc;
                }
              }
              else {
LAB_006a5acc:
                piVar9 = (int *)FUN_006c4530(local_18);
              }
              local_20 = piVar9;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                *piVar9 = *piVar12;
                piVar12 = piVar12 + 1;
                piVar9 = piVar9 + 1;
              }
            }
          }
          else {
            if (local_18 < (int *)0x101) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              goto LAB_006a5bce;
            }
            if (DAT_00c1c788 == '\0') {
              piVar9 = (int *)FUN_006ba810(0x1fd);
              local_20 = piVar9;
            }
            else {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              if (local_18 < (int *)0x401) {
                local_20 = (int *)FUN_006c4b80();
                if (local_20 == (int *)0x0) {
                  local_20 = (int *)0x0;
                  goto LAB_006a59e7;
                }
              }
              else {
LAB_006a59e7:
                if (local_18 < (int *)0x1001) {
                  local_20 = (int *)FUN_006c4b80();
                  if (local_20 != (int *)0x0) goto LAB_006a5a0f;
                  local_20 = (int *)0x0;
                }
                local_20 = (int *)FUN_006c4530(local_18);
              }
LAB_006a5a0f:
              piVar9 = local_20;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
              *piVar9 = *piVar12;
              piVar12 = piVar12 + 1;
              piVar9 = piVar9 + 1;
            }
          }
          FUN_006c4d70(local_1c);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          piVar12 = local_20;
          piVar10 = local_2c;
LAB_006a5bce:
          if (piVar12 == (int *)0x0) {
LAB_006a5804:
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            piVar9 = (int *)0x0;
          }
          else {
LAB_006a5bd6:
            if (local_1c == DAT_00c3c81c) {
              DAT_00c3c81c = piVar12;
            }
            piVar12[5] = (int)local_24;
            if (piVar12[1] != 0) {
              *(int **)(piVar12[1] + 8) = piVar12;
            }
            if (piVar12[2] != 0) {
              *(int **)(piVar12[2] + 4) = piVar12;
            }
            *(undefined4 *)((int)(piVar12 + 7) + (int)local_24) = 0xfab1ffcd;
            piVar9 = piVar12 + 7;
LAB_006a5c0b:
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          }
        }
LAB_006a5c19:
        if (local_34 == (int *)0x1) {
          if (local_38 <= local_38 - 1) {
LAB_006a5c2e:
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else if ((int)(local_38 - (int)local_34) < 0) goto LAB_006a5c2e;
LAB_006a5c3f:
        if (piVar9 != (int *)0x0) {
          FUN_006ba940();
        }
        if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
          TclFreeObj(piVar10);
        }
        local_8._0_1_ = 0xd;
        FUN_004297b0(0);
        local_8 = CONCAT31(local_8._1_3_,0xe);
        goto LAB_006a4c26;
      }
      if (local_4c <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = FUN_005caf90();
      if (iVar4 == 0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
        *piVar9 = *piVar9 + 1;
      }
      local_34 = piVar9;
      FUN_006bb930(&local_34);
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
      local_20 = (int *)((int)local_20 + 1);
      bVar14 = local_20 < local_4c;
      piVar12 = local_24;
    } while ((int)local_20 < (int)local_4c);
  }
  if (local_7c != 0) {
    if (piVar12 == (int *)0x0) {
      Tcl_ResetResult(local_7c);
      pcVar13 = TclFreeObj_exref;
      goto LAB_006a5537;
    }
    Tcl_SetObjResult(local_7c,piVar12);
  }
  pcVar13 = TclFreeObj_exref;
  if ((piVar12 != (int *)0x0) &&
     (*piVar12 = *piVar12 + -1, pcVar13 = TclFreeObj_exref, *piVar12 < 1)) {
    TclFreeObj(piVar12);
  }
LAB_006a5537:
  local_8 = CONCAT31(local_8._1_3_,0xf);
  FUN_0042fbb0(0);
  if (local_50 != (int *)0x0) {
    FUN_006ba940();
  }
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    (*pcVar13)(piVar10);
  }
  local_8._0_1_ = 0x10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_004297b0(0);
  if (local_6c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

