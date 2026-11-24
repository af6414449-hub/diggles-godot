
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclObjMethods__ObjFindList(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

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
  code *pcVar12;
  bool bVar13;
  float fVar14;
  float fVar15;
  undefined8 uVar16;
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
  int *local_40;
  undefined4 *local_3c;
  int *local_38;
  int *local_34;
  float local_30;
  float local_2c;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c70) &&
     (FUN_006cebf4(&DAT_00ca7c70,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7c70 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7c74 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::ObjFindList()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c70);
  }
  iVar8 = DAT_00ca7c74;
  local_44 = &DAT_00ca7c74;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c74 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar16 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_34 = (int *)FUN_005c71c0(param_4,3,1);
  if (local_34 == (int *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_006a5de6:
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
  local_24 = piVar9;
  if (piVar9 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
  }
  FUN_006b8fb0(ppuVar5);
  local_30 = DAT_00772478;
  cVar3 = FUN_006037d0(&local_20,&local_2c);
  if (cVar3 == '\0') {
    local_28 = (int *)0x0;
  }
  else {
    if ((uint)*(float *)((int)local_30 + 0x801c) <= (uint)local_2c) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_28 = *(int **)(*(int *)((int)local_30 + 0x8018) + (int)local_2c * 4);
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
    goto LAB_006a5de6;
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
        fVar14 = 0.0;
      }
      else {
        fVar14 = (float)local_60;
      }
      *piVar9 = *piVar9 + -1;
      local_58 = (double)fVar14;
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
  local_8 = CONCAT31(local_8._1_3_,9);
  local_18 = (int *)0x0;
  local_2c = (float)local_34[3];
  local_30 = (float)local_34[4];
  local_3c = (undefined4 *)local_34[0xdb];
  do {
    local_38 = (int *)(DAT_0077244c + 0x488);
    if (local_18 < 0x2000) {
      local_38 = local_38 + (int)local_18;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar9 = local_4c;
    }
    local_38 = (int *)*local_38;
    if ((((local_38 != (int *)0x0) && (local_38 != local_34)) && ((int *)local_38[0x35] == local_28)
        ) && (((*(byte *)(local_38 + 0xf4) & 1) != 0 &&
              (iVar4 = FUN_005cb3a0(local_3c), piVar9 = local_4c, 0 < iVar4)))) {
      fVar14 = ((float)local_38[4] - local_30) * ((float)local_38[4] - local_30) +
               ((float)local_38[3] - local_2c) * ((float)local_38[3] - local_2c);
      FUN_0040b7e0();
      piVar9 = local_4c;
      if ((double)fVar14 <= local_58) {
        local_40 = (int *)((int)local_4c + 1);
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
              local_8 = CONCAT31(local_8._1_3_,0xb);
              LOCK();
              _DAT_00c3c818 = _DAT_00c3c818 + 1;
              UNLOCK();
              iVar4 = FUN_006ba730();
              if (iVar4 == 0) {
                local_20 = (int *)piVar10[-2];
                local_1c = (int *)((int)local_20 + (int)piVar10);
                iVar4 = FUN_006ba730();
                if (iVar4 != 0) goto LAB_006a61e6;
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
                bVar13 = DAT_0077248f == '\0';
                piVar10[-1] = -0x20202021;
                *local_1c = -0x20202021;
                if (((bVar13) || (DAT_00c1c788 == '\0')) ||
                   ((piVar9 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar9))
                   )) {
                  FUN_006df631(piVar9);
                }
                else {
                  FUN_006b8c20();
                }
              }
              else {
LAB_006a61e6:
                if (DAT_00c3c7d4 != (FILE *)0x0) {
                  FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar10,iVar4);
                  _fflush(DAT_00c3c7d4);
                }
                if (DAT_00c3c828 != '\0') {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              local_8 = CONCAT31(local_8._1_3_,9);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              piVar10 = (int *)0x0;
              local_50 = piVar10;
              goto LAB_006a6426;
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
LAB_006a6334:
              local_8 = CONCAT31(local_8._1_3_,9);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              piVar10 = (int *)0x0;
              local_50 = piVar10;
              goto LAB_006a6426;
            }
            if ((DAT_0077248f == '\0') ||
               (((DAT_00c1c788 == '\0' || (local_1c < DAT_00c3c7cc)) ||
                ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_1c)))) {
              piVar10 = (int *)FUN_006df8de(local_1c,local_20 + 8);
              if (piVar10 == (int *)0x0) {
                FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_20 + 8,
                             local_1c);
                MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
                goto LAB_006a63d4;
              }
            }
            else {
              piVar10 = (int *)FUN_006b8a90();
LAB_006a63d4:
              if (piVar10 == (int *)0x0) goto LAB_006a6334;
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
          local_8 = CONCAT31(local_8._1_3_,9);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_50 = piVar10;
        }
LAB_006a6426:
        local_4c = local_40;
        if (local_40 <= (int *)((int)local_40 + -1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10[(int)local_4c + -1] = (int)local_38;
        piVar9 = local_4c;
      }
    }
    local_18 = (int *)((int)local_18 + 1);
  } while ((int)local_18 < 0x2000);
  puVar6 = (undefined4 *)((int)piVar9 + -1);
  local_3c = puVar6;
  local_1c = piVar10;
  do {
    local_11 = '\0';
    piVar11 = (int *)0x0;
    if ((int)puVar6 < 1) break;
    do {
      if (piVar9 <= piVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar14 = *(float *)(piVar10[(int)piVar11] + 0xc) - local_2c;
      fVar15 = *(float *)(piVar10[(int)piVar11] + 0x10) - local_30;
      piVar9 = (int *)(fVar14 * fVar14 + fVar15 * fVar15);
      FUN_0040b7e0();
      local_28 = (int *)((int)piVar11 + 1);
      local_40 = piVar9;
      if (local_4c <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar14 = *(float *)(piVar10[(int)piVar11 + 1] + 0xc) - local_2c;
      fVar15 = *(float *)(piVar10[(int)piVar11 + 1] + 0x10) - local_30;
      fVar14 = fVar14 * fVar14 + fVar15 * fVar15;
      FUN_0040b7e0();
      if (fVar14 < (float)local_40) {
        if (local_4c <= piVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_40 = (int *)piVar10[(int)piVar11];
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
    puVar6 = (undefined4 *)((int)local_4c + -1);
  } while (local_11 != '\0');
  piVar10 = local_24;
  piVar11 = (int *)0x0;
  local_18 = (int *)0x0;
  if (piVar9 == (int *)0x0) {
    piVar11 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
    iVar4 = *piVar11;
    *piVar11 = iVar4 + 1;
    piVar9 = local_4c;
    local_18 = piVar11;
    if (iVar4 + 1 < 1) {
      TclFreeObj(piVar11);
      piVar9 = local_4c;
    }
  }
  local_20 = (int *)0x0;
  if (0 < (int)piVar9) {
    bVar13 = piVar9 != (int *)0x0;
    do {
      if (!bVar13) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar9 = local_1c;
      local_40 = (int *)local_1c[(int)local_20];
      if (((local_40 == (int *)0x0) || (BVar7 = IsBadReadPtr(local_40,0x10), BVar7 != 0)) ||
         ((local_40[2] != 0x616e4f62 || ((DAT_00768398 != '\0' && (local_40[0x37] == 0)))))) {
        if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
          TclFreeObj(local_18);
        }
        local_8 = CONCAT31(local_8._1_3_,0xc);
        if (-1 < (int)local_4c) goto LAB_006a6e03;
        local_34 = (int *)-(int)local_4c;
        local_38 = (int *)0x0;
        if (((int)local_4c + 0xfU & 0xfffffff0) == 0) goto LAB_006a6ddd;
        local_28 = (int *)0x0;
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        if (piVar9 == (int *)0x0) {
          piVar9 = (int *)FUN_006ba810(0x9b);
          goto LAB_006a6dcf;
        }
        if (local_28 == (int *)0x0) {
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
            local_40 = (int *)piVar9[-2];
            local_3c = (undefined4 *)((int)local_40 + (int)piVar9);
            iVar4 = FUN_006ba730();
            if (iVar4 != 0) goto LAB_006a687e;
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
            piVar11 = piVar9 + -7;
            *piVar11 = -0x20202021;
            bVar13 = DAT_0077248f == '\0';
            piVar9[-1] = -0x20202021;
            *local_3c = 0xdfdfdfdf;
            if ((((bVar13) || (DAT_00c1c788 == '\0')) || (piVar11 < DAT_00c3c7cc)) ||
               ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar11)) {
              FUN_006df631(piVar11);
            }
            else {
              FUN_006b8c20();
            }
          }
          else {
LAB_006a687e:
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
          if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), piVar11 = local_1c, iVar4 != 0)) {
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar9,iVar4);
              _fflush(DAT_00c3c7d4);
            }
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            goto LAB_006a69c8;
          }
          local_18 = local_28 + 8;
          if (((DAT_0077248f == '\0') || ((DAT_00c1c788 == '\0' || (local_1c < DAT_00c3c7cc)))) ||
             ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_1c)) {
            piVar11 = (int *)FUN_006df8de(local_1c,local_18);
            if (piVar11 != (int *)0x0) goto LAB_006a6d9a;
            FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_18,local_1c)
            ;
            MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
            goto LAB_006a6d92;
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          cVar3 = FUN_006c4d20(piVar11);
          if (cVar3 != '\0') {
            if (&DAT_00000040 < local_18) {
              if (DAT_00c1c788 == '\0') {
                piVar11 = (int *)FUN_006ba810(0x1fd);
              }
              else {
                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                if (((((int *)0x100 < local_18) ||
                     (piVar11 = (int *)FUN_006c4b80(), piVar11 == (int *)0x0)) &&
                    (((int *)0x400 < local_18 ||
                     (piVar11 = (int *)FUN_006c4b80(), piVar11 == (int *)0x0)))) &&
                   (((int *)0x1000 < local_18 ||
                    (piVar11 = (int *)FUN_006c4b80(), piVar11 == (int *)0x0)))) {
                  piVar11 = (int *)FUN_006c4530(local_18);
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              iVar4 = local_1c[1];
              iVar8 = local_1c[2];
              iVar2 = local_1c[3];
              *piVar11 = *local_1c;
              piVar11[1] = iVar4;
              piVar11[2] = iVar8;
              piVar11[3] = iVar2;
              iVar4 = local_1c[5];
              iVar8 = local_1c[6];
              iVar2 = local_1c[7];
              piVar11[4] = local_1c[4];
              piVar11[5] = iVar4;
              piVar11[6] = iVar8;
              piVar11[7] = iVar2;
              iVar4 = local_1c[9];
              iVar8 = local_1c[10];
              iVar2 = local_1c[0xb];
              piVar11[8] = local_1c[8];
              piVar11[9] = iVar4;
              piVar11[10] = iVar8;
              piVar11[0xb] = iVar2;
              iVar4 = local_1c[0xd];
              iVar8 = local_1c[0xe];
              iVar2 = local_1c[0xf];
              piVar11[0xc] = local_1c[0xc];
              piVar11[0xd] = iVar4;
              piVar11[0xe] = iVar8;
              piVar11[0xf] = iVar2;
LAB_006a6b1a:
              FUN_006c4d70(local_1c);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            else {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            goto LAB_006a6d92;
          }
          cVar3 = FUN_006c4d20(piVar11);
          if (cVar3 == '\0') {
            cVar3 = FUN_006c4d20(piVar11);
            if (cVar3 == '\0') {
              cVar3 = FUN_006c4d20(piVar11);
              if (cVar3 == '\0') {
                piVar11 = (int *)FUN_006c4620(piVar11,local_18);
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              else {
                if ((int *)0x1000 < local_18) {
                  if (DAT_00c1c788 == '\0') {
                    piVar11 = (int *)FUN_006ba810(0x1fd);
                  }
                  else {
                    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                    piVar11 = (int *)FUN_006c4530(local_18);
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  }
                  FUN_006d2250(piVar11,local_1c,0x1000);
                  goto LAB_006a6b1a;
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              goto LAB_006a6d92;
            }
            if (local_18 < (int *)0x401) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              goto LAB_006a6d92;
            }
            if (DAT_00c1c788 == '\0') {
              local_20 = (int *)FUN_006ba810(0x1fd);
              piVar9 = local_20;
              for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                *piVar9 = *piVar11;
                piVar11 = piVar11 + 1;
                piVar9 = piVar9 + 1;
              }
            }
            else {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              if (local_18 < (int *)0x1001) {
                piVar9 = (int *)FUN_006c4b80();
                if (piVar9 == (int *)0x0) {
                  local_20 = (int *)0x0;
                  goto LAB_006a6c90;
                }
              }
              else {
LAB_006a6c90:
                piVar9 = (int *)FUN_006c4530(local_18);
              }
              local_20 = piVar9;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                *piVar9 = *piVar11;
                piVar11 = piVar11 + 1;
                piVar9 = piVar9 + 1;
              }
            }
          }
          else {
            if (local_18 < (int *)0x101) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              goto LAB_006a6d92;
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
                  goto LAB_006a6bab;
                }
              }
              else {
LAB_006a6bab:
                if (local_18 < (int *)0x1001) {
                  local_20 = (int *)FUN_006c4b80();
                  if (local_20 != (int *)0x0) goto LAB_006a6bd3;
                  local_20 = (int *)0x0;
                }
                local_20 = (int *)FUN_006c4530(local_18);
              }
LAB_006a6bd3:
              piVar9 = local_20;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
              *piVar9 = *piVar11;
              piVar11 = piVar11 + 1;
              piVar9 = piVar9 + 1;
            }
          }
          FUN_006c4d70(local_1c);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          piVar11 = local_20;
          piVar10 = local_24;
LAB_006a6d92:
          if (piVar11 == (int *)0x0) {
LAB_006a69c8:
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            piVar9 = (int *)0x0;
          }
          else {
LAB_006a6d9a:
            if (local_1c == DAT_00c3c81c) {
              DAT_00c3c81c = piVar11;
            }
            piVar11[5] = (int)local_28;
            if (piVar11[1] != 0) {
              *(int **)(piVar11[1] + 8) = piVar11;
            }
            if (piVar11[2] != 0) {
              *(int **)(piVar11[2] + 4) = piVar11;
            }
            *(undefined4 *)((int)(piVar11 + 7) + (int)local_28) = 0xfab1ffcd;
            piVar9 = piVar11 + 7;
LAB_006a6dcf:
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          }
        }
LAB_006a6ddd:
        if (local_34 == (int *)0x1) {
          if (local_38 <= (int *)((int)local_38 - 1U)) {
LAB_006a6df2:
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else if ((int)local_38 - (int)local_34 < 0) goto LAB_006a6df2;
LAB_006a6e03:
        if (piVar9 != (int *)0x0) {
          FUN_006ba940();
        }
        if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
          TclFreeObj(piVar10);
        }
        local_8._0_1_ = 0xd;
        FUN_004297b0(0);
        local_8 = CONCAT31(local_8._1_3_,0xe);
        goto LAB_006a5de6;
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
      local_38 = piVar9;
      FUN_006bb930(&local_38);
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
      local_20 = (int *)((int)local_20 + 1);
      bVar13 = local_20 < local_4c;
      piVar11 = local_18;
    } while ((int)local_20 < (int)local_4c);
  }
  if (local_7c != 0) {
    if (piVar11 == (int *)0x0) {
      Tcl_ResetResult(local_7c);
      pcVar12 = TclFreeObj_exref;
      goto LAB_006a66fb;
    }
    Tcl_SetObjResult(local_7c,piVar11);
  }
  pcVar12 = TclFreeObj_exref;
  if ((piVar11 != (int *)0x0) &&
     (*piVar11 = *piVar11 + -1, pcVar12 = TclFreeObj_exref, *piVar11 < 1)) {
    TclFreeObj(piVar11);
  }
LAB_006a66fb:
  local_8 = CONCAT31(local_8._1_3_,0xf);
  FUN_0042fbb0(0);
  if (local_50 != (int *)0x0) {
    FUN_006ba940();
  }
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    (*pcVar12)(piVar10);
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

