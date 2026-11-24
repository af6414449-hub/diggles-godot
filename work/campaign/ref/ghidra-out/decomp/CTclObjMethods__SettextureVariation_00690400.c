
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclObjMethods__SettextureVariation
          (undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4)

{
  int *piVar1;
  size_t _Size;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint *puVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  uint *local_34;
  int local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711a45;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7948) &&
     (FUN_006cebf4(&DAT_00ca7948,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7948 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca794c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::SettextureVariation()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7948);
  }
  iVar8 = DAT_00ca794c;
  local_28 = &DAT_00ca794c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca794c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar9;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar13 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar9 = 1;
    goto LAB_00690cb1;
  }
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_20 = FUN_005c71c0(param_4,2,1);
  if (local_20 == 0) {
    uVar9 = 1;
  }
  else {
    puVar7 = (undefined4 *)((int)param_3 + -2);
    local_24 = puVar7;
    FUN_0047e280(puVar7);
    local_34 = (uint *)0x0;
    local_30 = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004629b0();
    local_14 = 0;
    param_3 = local_34;
    if (0 < (int)puVar7) {
      local_18 = 8;
      do {
        iVar5 = local_18;
        uVar6 = local_14 + 2;
        if (((int)uVar6 < 0) || (local_38 <= (int)uVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar7 = local_40;
          if (local_3c == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_3c <= uVar6) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar7 = (undefined4 *)((int)local_40 + iVar5);
        }
        piVar1 = (int *)*puVar7;
        if (piVar1 == (int *)0x0) {
          uVar6 = 0;
        }
        else {
          *piVar1 = *piVar1 + 1;
          iVar5 = Tcl_GetIntFromObj(0,piVar1,&local_1c);
          uVar6 = -(uint)(iVar5 != 1) & local_1c;
        }
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *local_34 = uVar6;
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
          TclFreeObj(piVar1);
        }
        iVar5 = local_20;
        if (*(int *)(local_20 + 0x244) == 0) {
          local_2c = (undefined4 *)FUN_006ba810(0xb8);
          if (local_2c == (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            *local_2c = 0;
            local_2c[1] = 0;
            puVar7 = local_2c;
          }
          *(undefined4 **)(iVar5 + 0x244) = puVar7;
        }
        FUN_004d9be0(local_14,&local_34,0,0);
        local_14 = local_14 + 1;
        local_18 = local_18 + 4;
      } while ((int)local_14 < (int)local_24);
    }
    puVar10 = local_34;
    local_8._0_1_ = 4;
    if ((local_30 < 0) && ((local_30 + 3U & 0xfffffffc) != 0)) {
      local_14 = 0;
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      if (puVar10 == (uint *)0x0) {
        param_3 = (uint *)FUN_006ba810(0x9b);
      }
      else {
        if (local_14 == 0) {
          if (DAT_00c3c824 == 0) {
            DAT_00c3c824 = 1;
            InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          LOCK();
          _DAT_00c3c818 = _DAT_00c3c818 + 1;
          UNLOCK();
          puVar11 = puVar10 + -7;
          iVar5 = FUN_006ba730();
          if (iVar5 == 0) {
            _Size = puVar10[-2];
            local_24 = (undefined4 *)(_Size + 0x1c + (int)puVar11);
            iVar5 = FUN_006ba730();
            if (iVar5 != 0) goto LAB_00690735;
            if (puVar10[-5] != 0) {
              *(uint *)(puVar10[-5] + 4) = puVar10[-6];
            }
            if (puVar10[-6] != 0) {
              *(uint *)(puVar10[-6] + 8) = puVar10[-5];
            }
            if (puVar11 == DAT_00c3c81c) {
              DAT_00c3c81c = (uint *)puVar10[-6];
            }
            _memset(puVar10,-0x20202021,_Size);
            bVar12 = DAT_0077248f == '\0';
            *puVar11 = 0xdfdfdfdf;
            puVar10[-1] = 0xdfdfdfdf;
            *local_24 = 0xdfdfdfdf;
            if ((((bVar12) || (DAT_00c1c788 == '\0')) || (puVar11 < DAT_00c3c7cc)) ||
               ((uint *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar11)) {
              FUN_006df631(puVar11);
            }
            else {
              FUN_006b8c20();
            }
          }
          else {
LAB_00690735:
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",puVar10,iVar5);
              _fflush(DAT_00c3c7d4);
            }
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          param_3 = (uint *)0x0;
          goto LAB_00690c79;
        }
        LOCK();
        _DAT_00c3c82c = _DAT_00c3c82c + 1;
        UNLOCK();
        puVar11 = puVar10 + -7;
        iVar5 = FUN_006ba730();
        if ((iVar5 != 0) || (iVar5 = FUN_006ba730(), iVar5 != 0)) {
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_34,iVar5);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
LAB_0069087c:
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          param_3 = (uint *)0x0;
          goto LAB_00690c79;
        }
        uVar6 = local_14 + 0x20;
        if ((DAT_0077248f == '\0') ||
           (((DAT_00c1c788 == '\0' || (puVar11 < DAT_00c3c7cc)) ||
            ((uint *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar11)))) {
          param_3 = (uint *)FUN_006df8de(puVar11,uVar6);
          if (param_3 == (uint *)0x0) {
            FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",uVar6,puVar11);
            MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
            goto LAB_00690c2f;
          }
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          cVar4 = FUN_006c4d20(puVar11);
          param_3 = puVar11;
          if (cVar4 == '\0') {
            cVar4 = FUN_006c4d20(puVar11);
            if (cVar4 == '\0') {
              cVar4 = FUN_006c4d20(puVar11);
              if (cVar4 == '\0') {
                cVar4 = FUN_006c4d20(puVar11);
                if (cVar4 == '\0') {
                  param_3 = (uint *)FUN_006c4620(puVar11,uVar6);
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                }
                else {
                  if (0x1000 < uVar6) {
                    if (DAT_00c1c788 == '\0') {
                      param_3 = (uint *)FUN_006ba810(0x1fd);
                    }
                    else {
                      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                      param_3 = (uint *)FUN_006c4530(uVar6);
                      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                    }
                    FUN_006d2250(param_3,puVar11,0x1000);
                    goto LAB_006909cf;
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                }
              }
              else {
                if (0x400 < uVar6) {
                  if (DAT_00c1c788 == '\0') {
                    param_3 = (uint *)FUN_006ba810(0x1fd);
                  }
                  else {
                    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                    if ((0x1000 < uVar6) ||
                       (param_3 = (uint *)FUN_006c4b80(), param_3 == (uint *)0x0)) {
                      param_3 = (uint *)FUN_006c4530(uVar6);
                    }
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  }
                  puVar10 = local_34 + -7;
                  puVar11 = param_3;
                  for (iVar5 = 0x100; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *puVar11 = *puVar10;
                    puVar10 = puVar10 + 1;
                    puVar11 = puVar11 + 1;
                  }
                  goto LAB_00690a9f;
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
            }
            else if (uVar6 < 0x101) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            else {
              if (DAT_00c1c788 == '\0') {
                param_3 = (uint *)FUN_006ba810(0x1fd);
              }
              else {
                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                if (((0x400 < uVar6) || (param_3 = (uint *)FUN_006c4b80(), param_3 == (uint *)0x0))
                   && ((0x1000 < uVar6 || (param_3 = (uint *)FUN_006c4b80(), param_3 == (uint *)0x0)
                       ))) {
                  param_3 = (uint *)FUN_006c4530(uVar6);
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              puVar10 = local_34 + -7;
              puVar11 = param_3;
              for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
              }
LAB_00690a9f:
              puVar11 = local_34 + -7;
              FUN_006c4d70(puVar11);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
          }
          else if (uVar6 < 0x41) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          }
          else {
            if (DAT_00c1c788 == '\0') {
              param_3 = (uint *)FUN_006ba810(0x1fd);
            }
            else {
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              if ((((0x100 < uVar6) || (param_3 = (uint *)FUN_006c4b80(), param_3 == (uint *)0x0))
                  && ((0x400 < uVar6 || (param_3 = (uint *)FUN_006c4b80(), param_3 == (uint *)0x0)))
                  ) && ((0x1000 < uVar6 ||
                        (param_3 = (uint *)FUN_006c4b80(), param_3 == (uint *)0x0)))) {
                param_3 = (uint *)FUN_006c4530(uVar6);
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
            uVar6 = puVar10[-6];
            uVar2 = puVar10[-5];
            uVar3 = puVar10[-4];
            *param_3 = *puVar11;
            param_3[1] = uVar6;
            param_3[2] = uVar2;
            param_3[3] = uVar3;
            uVar6 = puVar10[-2];
            uVar2 = puVar10[-1];
            uVar3 = *puVar10;
            param_3[4] = puVar10[-3];
            param_3[5] = uVar6;
            param_3[6] = uVar2;
            param_3[7] = uVar3;
            uVar6 = puVar10[2];
            uVar2 = puVar10[3];
            uVar3 = puVar10[4];
            param_3[8] = puVar10[1];
            param_3[9] = uVar6;
            param_3[10] = uVar2;
            param_3[0xb] = uVar3;
            uVar6 = puVar10[6];
            uVar2 = puVar10[7];
            uVar3 = puVar10[8];
            param_3[0xc] = puVar10[5];
            param_3[0xd] = uVar6;
            param_3[0xe] = uVar2;
            param_3[0xf] = uVar3;
LAB_006909cf:
            FUN_006c4d70(puVar11);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
          }
LAB_00690c2f:
          if (param_3 == (uint *)0x0) goto LAB_0069087c;
        }
        if (puVar11 == DAT_00c3c81c) {
          DAT_00c3c81c = param_3;
        }
        param_3[5] = local_14;
        if (param_3[1] != 0) {
          *(uint **)(param_3[1] + 8) = param_3;
        }
        if (param_3[2] != 0) {
          *(uint **)(param_3[2] + 4) = param_3;
        }
        *(undefined4 *)((int)param_3 + local_14 + 0x1c) = 0xfab1ffcd;
        param_3 = param_3 + 7;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
LAB_00690c79:
    if (param_3 != (uint *)0x0) {
      FUN_006ba940();
    }
    uVar9 = 0;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_00690cb1:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

