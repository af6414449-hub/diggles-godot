
/* WARNING: Removing unreachable block (ram,0x00691924) */
/* WARNING: Removing unreachable block (ram,0x00691991) */
/* WARNING: Removing unreachable block (ram,0x006919a2) */
/* WARNING: Removing unreachable block (ram,0x006919b7) */
/* WARNING: Removing unreachable block (ram,0x006919c3) */
/* WARNING: Removing unreachable block (ram,0x006919d1) */
/* WARNING: Removing unreachable block (ram,0x00691cef) */
/* WARNING: Removing unreachable block (ram,0x00691cff) */
/* WARNING: Removing unreachable block (ram,0x006919e0) */
/* WARNING: Removing unreachable block (ram,0x00691ade) */
/* WARNING: Removing unreachable block (ram,0x00691bb4) */
/* WARNING: Removing unreachable block (ram,0x00691c58) */
/* WARNING: Removing unreachable block (ram,0x00691cd9) */
/* WARNING: Removing unreachable block (ram,0x00691c67) */
/* WARNING: Removing unreachable block (ram,0x00691c81) */
/* WARNING: Removing unreachable block (ram,0x00691ca2) */
/* WARNING: Removing unreachable block (ram,0x00691c8a) */
/* WARNING: Removing unreachable block (ram,0x00691cc0) */
/* WARNING: Removing unreachable block (ram,0x00691c6f) */
/* WARNING: Removing unreachable block (ram,0x00691bc7) */
/* WARNING: Removing unreachable block (ram,0x00691bcf) */
/* WARNING: Removing unreachable block (ram,0x00691be1) */
/* WARNING: Removing unreachable block (ram,0x00691c05) */
/* WARNING: Removing unreachable block (ram,0x00691c18) */
/* WARNING: Removing unreachable block (ram,0x00691c2b) */
/* WARNING: Removing unreachable block (ram,0x00691c36) */
/* WARNING: Removing unreachable block (ram,0x00691bea) */
/* WARNING: Removing unreachable block (ram,0x00691c41) */
/* WARNING: Removing unreachable block (ram,0x00691c4c) */
/* WARNING: Removing unreachable block (ram,0x00691c4e) */
/* WARNING: Removing unreachable block (ram,0x00691af1) */
/* WARNING: Removing unreachable block (ram,0x00691af9) */
/* WARNING: Removing unreachable block (ram,0x00691b0b) */
/* WARNING: Removing unreachable block (ram,0x00691b2f) */
/* WARNING: Removing unreachable block (ram,0x00691b42) */
/* WARNING: Removing unreachable block (ram,0x00691b55) */
/* WARNING: Removing unreachable block (ram,0x00691b5d) */
/* WARNING: Removing unreachable block (ram,0x00691b70) */
/* WARNING: Removing unreachable block (ram,0x00691b7b) */
/* WARNING: Removing unreachable block (ram,0x00691b14) */
/* WARNING: Removing unreachable block (ram,0x00691b86) */
/* WARNING: Removing unreachable block (ram,0x00691b91) */
/* WARNING: Removing unreachable block (ram,0x00691b93) */
/* WARNING: Removing unreachable block (ram,0x00691b98) */
/* WARNING: Removing unreachable block (ram,0x006919fe) */
/* WARNING: Removing unreachable block (ram,0x00691a03) */
/* WARNING: Removing unreachable block (ram,0x00691a15) */
/* WARNING: Removing unreachable block (ram,0x00691a36) */
/* WARNING: Removing unreachable block (ram,0x00691a49) */
/* WARNING: Removing unreachable block (ram,0x00691a59) */
/* WARNING: Removing unreachable block (ram,0x00691a5c) */
/* WARNING: Removing unreachable block (ram,0x00691a64) */
/* WARNING: Removing unreachable block (ram,0x00691a74) */
/* WARNING: Removing unreachable block (ram,0x00691a77) */
/* WARNING: Removing unreachable block (ram,0x00691a7f) */
/* WARNING: Removing unreachable block (ram,0x00691a8f) */
/* WARNING: Removing unreachable block (ram,0x00691a92) */
/* WARNING: Removing unreachable block (ram,0x00691a9a) */
/* WARNING: Removing unreachable block (ram,0x00691a1e) */
/* WARNING: Removing unreachable block (ram,0x00691aa5) */
/* WARNING: Removing unreachable block (ram,0x00691ac8) */
/* WARNING: Removing unreachable block (ram,0x00691d28) */
/* WARNING: Removing unreachable block (ram,0x00691d30) */
/* WARNING: Removing unreachable block (ram,0x00691d3a) */
/* WARNING: Removing unreachable block (ram,0x00691d3d) */
/* WARNING: Removing unreachable block (ram,0x00691d4c) */
/* WARNING: Removing unreachable block (ram,0x00691d4f) */
/* WARNING: Removing unreachable block (ram,0x00691d56) */
/* WARNING: Removing unreachable block (ram,0x00691d59) */
/* WARNING: Removing unreachable block (ram,0x0069193b) */
/* WARNING: Removing unreachable block (ram,0x00691945) */
/* WARNING: Removing unreachable block (ram,0x00691960) */
/* WARNING: Removing unreachable block (ram,0x00691969) */
/* WARNING: Removing unreachable block (ram,0x0069197a) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclObjMethods__SetTextureAnimation
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  int *piVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  undefined4 *local_4c;
  uint local_48;
  int *local_44;
  undefined4 *local_40;
  undefined4 *local_3c;
  int *local_38;
  uint local_34;
  int local_30;
  int *local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711aad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7950) &&
     (FUN_006cebf4(&DAT_00ca7950,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7950 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7954 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::SetTextureAnimation()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7950);
  }
  iVar6 = DAT_00ca7954;
  local_40 = &DAT_00ca7954;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7954 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar10;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar13 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar10 = param_4;
  local_8._0_1_ = 1;
  if (2 < param_3 - 4) {
    FUN_006bc8f0(4);
    uVar10 = 1;
    goto LAB_00691dbb;
  }
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_28 = FUN_005c71c0(uVar10,2,1);
  if (local_28 == 0) {
    uVar10 = 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_004295e0(2);
    piVar11 = (int *)*puVar5;
    if (piVar11 == (int *)0x0) {
      local_24 = 0;
    }
    else {
      *piVar11 = *piVar11 + 1;
      iVar4 = Tcl_GetIntFromObj(0,piVar11,&local_2c);
      *piVar11 = *piVar11 + -1;
      local_24 = -(uint)(iVar4 != 1) & (uint)local_2c;
      if (*piVar11 < 1) {
        TclFreeObj(piVar11);
      }
    }
    local_14 = (undefined4 *)0x0;
    local_4c = (undefined4 *)0x0;
    local_48 = 0;
    puVar5 = (undefined4 *)FUN_004295e0(3);
    piVar11 = (int *)*puVar5;
    if (piVar11 != (int *)0x0) {
      *piVar11 = *piVar11 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    local_20 = 0;
    puVar5 = (undefined4 *)0x0;
    local_44 = piVar11;
    local_2c = piVar11;
    while( true ) {
      if (piVar11 == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar6 = Tcl_ListObjLength(0,piVar11,&local_30);
        iVar4 = local_30;
        if (iVar6 != 0) {
          iVar4 = 0;
        }
      }
      if (iVar4 <= (int)local_20) break;
      local_34 = local_48 + 1;
      uVar8 = local_48 + 4 & 0xfffffffc;
      if (uVar8 != (local_48 + 3 & 0xfffffffc)) {
        local_1c = uVar8 * 4;
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 5;
        if (puVar5 == (undefined4 *)0x0) {
          puVar7 = (undefined4 *)FUN_006ba810(0x9b);
        }
        else {
          if (local_1c == 0) {
            if (DAT_00c3c824 == 0) {
              DAT_00c3c824 = 1;
              InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_8 = CONCAT31(local_8._1_3_,6);
            LOCK();
            _DAT_00c3c818 = _DAT_00c3c818 + 1;
            UNLOCK();
            iVar4 = FUN_006ba730();
            if (iVar4 == 0) {
              local_1c = puVar5[-2];
              local_18 = (undefined4 *)(local_1c + (int)puVar5);
              iVar4 = FUN_006ba730();
              if (iVar4 != 0) goto LAB_00690fae;
              if (puVar5[-5] != 0) {
                *(undefined4 *)(puVar5[-5] + 4) = puVar5[-6];
              }
              if (puVar5[-6] != 0) {
                *(undefined4 *)(puVar5[-6] + 8) = puVar5[-5];
              }
              if (puVar5 + -7 == DAT_00c3c81c) {
                DAT_00c3c81c = (undefined4 *)puVar5[-6];
              }
              _memset(puVar5,-0x20202021,local_1c);
              puVar7 = puVar5 + -7;
              *puVar7 = 0xdfdfdfdf;
              bVar12 = DAT_0077248f == '\0';
              puVar5[-1] = 0xdfdfdfdf;
              *local_18 = 0xdfdfdfdf;
              if ((((bVar12) || (DAT_00c1c788 == '\0')) || (puVar7 < DAT_00c3c7cc)) ||
                 ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar7)) {
                FUN_006df631(puVar7);
              }
              else {
                FUN_006b8c20();
              }
            }
            else {
LAB_00690fae:
              if (DAT_00c3c7d4 != (FILE *)0x0) {
                FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",puVar5,iVar4);
                _fflush(DAT_00c3c7d4);
              }
              if (DAT_00c3c828 != '\0') {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_8 = CONCAT31(local_8._1_3_,4);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_4c = (undefined4 *)0x0;
            local_14 = (undefined4 *)0x0;
            goto LAB_00691520;
          }
          LOCK();
          _DAT_00c3c82c = _DAT_00c3c82c + 1;
          UNLOCK();
          local_14 = puVar5 + -7;
          iVar4 = FUN_006ba730();
          if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), iVar4 != 0)) {
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",puVar5,iVar4);
              _fflush(DAT_00c3c7d4);
            }
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
LAB_006910ff:
            local_8 = CONCAT31(local_8._1_3_,4);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_4c = (undefined4 *)0x0;
            local_14 = (undefined4 *)0x0;
            goto LAB_00691520;
          }
          puVar5 = (undefined4 *)(local_1c + 0x20);
          local_18 = puVar5;
          if (((DAT_0077248f == '\0') || ((DAT_00c1c788 == '\0' || (local_14 < DAT_00c3c7cc)))) ||
             ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_14)) {
            puVar7 = (undefined4 *)FUN_006df8de(local_14,puVar5);
            if (puVar7 == (undefined4 *)0x0) {
              FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_18,
                           local_14);
              MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
              goto LAB_006914cb;
            }
          }
          else {
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            cVar3 = FUN_006c4d20(local_14);
            if (cVar3 == '\0') {
              cVar3 = FUN_006c4d20(local_14);
              if (cVar3 == '\0') {
                cVar3 = FUN_006c4d20(local_14);
                if (cVar3 == '\0') {
                  cVar3 = FUN_006c4d20(local_14);
                  if (cVar3 == '\0') {
                    puVar7 = (undefined4 *)FUN_006c4620(local_14,puVar5);
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  }
                  else {
                    if ((undefined4 *)0x1000 < puVar5) {
                      if (DAT_00c1c788 == '\0') {
                        puVar7 = (undefined4 *)FUN_006ba810(0x1fd);
                      }
                      else {
                        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                        puVar7 = (undefined4 *)FUN_006c4530(puVar5);
                        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                      }
                      FUN_006d2250(puVar7,local_14,0x1000);
                      goto LAB_0069125c;
                    }
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                    puVar7 = local_14;
                  }
                }
                else {
                  if ((undefined4 *)0x400 < puVar5) {
                    if (DAT_00c1c788 == '\0') {
                      puVar7 = (undefined4 *)FUN_006ba810(0x1fd);
                      local_18 = puVar7;
                    }
                    else {
                      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                      if (((undefined4 *)0x1000 < puVar5) ||
                         (puVar7 = (undefined4 *)FUN_006c4b80(), local_18 = puVar7,
                         puVar7 == (undefined4 *)0x0)) {
                        puVar7 = (undefined4 *)FUN_006c4530(puVar5);
                      }
                      local_18 = puVar7;
                      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                    }
                    puVar5 = local_14;
                    for (iVar4 = 0x100; iVar4 != 0; iVar4 = iVar4 + -1) {
                      *puVar7 = *puVar5;
                      puVar5 = puVar5 + 1;
                      puVar7 = puVar7 + 1;
                    }
                    goto LAB_0069132d;
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  puVar7 = local_14;
                }
              }
              else if (puVar5 < (undefined4 *)0x101) {
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                puVar7 = local_14;
              }
              else {
                if (DAT_00c1c788 == '\0') {
                  puVar5 = (undefined4 *)FUN_006ba810(0x1fd);
                  local_18 = puVar5;
                }
                else {
                  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                  if ((((undefined4 *)0x400 < puVar5) ||
                      (local_18 = (undefined4 *)FUN_006c4b80(), local_18 == (undefined4 *)0x0)) &&
                     (((undefined4 *)0x1000 < puVar5 ||
                      (local_18 = (undefined4 *)FUN_006c4b80(), local_18 == (undefined4 *)0x0)))) {
                    local_18 = (undefined4 *)FUN_006c4530(puVar5);
                  }
                  puVar5 = local_18;
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                }
                puVar7 = local_14;
                for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *puVar5 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar5 = puVar5 + 1;
                }
LAB_0069132d:
                FUN_006c4d70(local_14);
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                puVar7 = local_18;
                piVar11 = local_2c;
              }
            }
            else if (puVar5 < &DAT_00000041) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              puVar7 = local_14;
            }
            else {
              if (DAT_00c1c788 == '\0') {
                puVar7 = (undefined4 *)FUN_006ba810(0x1fd);
              }
              else {
                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
                if ((((undefined4 *)0x100 < puVar5) ||
                    (puVar7 = (undefined4 *)FUN_006c4b80(), puVar5 = local_18,
                    puVar7 == (undefined4 *)0x0)) &&
                   ((((undefined4 *)0x400 < puVar5 ||
                     (puVar7 = (undefined4 *)FUN_006c4b80(), puVar5 = local_18,
                     puVar7 == (undefined4 *)0x0)) &&
                    (((undefined4 *)0x1000 < puVar5 ||
                     (puVar7 = (undefined4 *)FUN_006c4b80(), puVar5 = local_18,
                     puVar7 == (undefined4 *)0x0)))))) {
                  puVar7 = (undefined4 *)FUN_006c4530(puVar5);
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
              }
              uVar10 = local_14[1];
              uVar1 = local_14[2];
              uVar2 = local_14[3];
              *puVar7 = *local_14;
              puVar7[1] = uVar10;
              puVar7[2] = uVar1;
              puVar7[3] = uVar2;
              uVar10 = local_14[5];
              uVar1 = local_14[6];
              uVar2 = local_14[7];
              puVar7[4] = local_14[4];
              puVar7[5] = uVar10;
              puVar7[6] = uVar1;
              puVar7[7] = uVar2;
              uVar10 = local_14[9];
              uVar1 = local_14[10];
              uVar2 = local_14[0xb];
              puVar7[8] = local_14[8];
              puVar7[9] = uVar10;
              puVar7[10] = uVar1;
              puVar7[0xb] = uVar2;
              uVar10 = local_14[0xd];
              uVar1 = local_14[0xe];
              uVar2 = local_14[0xf];
              puVar7[0xc] = local_14[0xc];
              puVar7[0xd] = uVar10;
              puVar7[0xe] = uVar1;
              puVar7[0xf] = uVar2;
LAB_0069125c:
              FUN_006c4d70(local_14);
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c1c770);
            }
LAB_006914cb:
            if (puVar7 == (undefined4 *)0x0) goto LAB_006910ff;
          }
          if (local_14 == DAT_00c3c81c) {
            DAT_00c3c81c = puVar7;
          }
          puVar7[5] = local_1c;
          if (puVar7[1] != 0) {
            *(undefined4 **)(puVar7[1] + 8) = puVar7;
          }
          if (puVar7[2] != 0) {
            *(undefined4 **)(puVar7[2] + 4) = puVar7;
          }
          *(undefined4 *)((int)puVar7 + local_1c + 0x1c) = 0xfab1ffcd;
          puVar7 = puVar7 + 7;
        }
        local_8 = CONCAT31(local_8._1_3_,4);
        local_14 = puVar7;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_4c = puVar7;
      }
LAB_00691520:
      local_48 = local_34;
      local_34 = local_34 - 1;
      if ((piVar11 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar11,local_20,&local_38), piVar9 = local_38, iVar4 != 0)) {
        piVar9 = (int *)0x0;
LAB_0069156b:
        local_1c = 0;
      }
      else {
        if (local_38 == (int *)0x0) goto LAB_0069156b;
        *local_38 = *local_38 + 1;
        iVar4 = Tcl_GetIntFromObj(0,local_38,&local_3c);
        local_1c = -(uint)(iVar4 != 1) & (uint)local_3c;
      }
      if (local_48 <= local_48 - 1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_14[local_34] = local_1c;
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
      local_20 = local_20 + 1;
      puVar5 = local_14;
    }
    local_20 = 0;
    if (4 < (int)param_3) {
      if (local_50 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_58;
        if (local_54 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_54 < 5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_58 + 4;
      }
      piVar9 = (int *)*puVar5;
      if (piVar9 == (int *)0x0) {
        local_20 = 0;
      }
      else {
        *piVar9 = *piVar9 + 1;
        iVar4 = Tcl_GetIntFromObj(0,piVar9,&local_3c);
        *piVar9 = *piVar9 + -1;
        local_20 = -(uint)(iVar4 != 1) & (uint)local_3c;
        if (*piVar9 < 1) {
          TclFreeObj(piVar9);
        }
      }
    }
    uVar8 = 2;
    if (5 < (int)param_3) {
      if (local_50 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_58;
        if (local_54 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_54 < 6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_58 + 5;
      }
      piVar9 = (int *)*puVar5;
      if (piVar9 == (int *)0x0) {
        uVar8 = 0;
      }
      else {
        *piVar9 = *piVar9 + 1;
        iVar4 = Tcl_GetIntFromObj(0,piVar9,&param_3);
        *piVar9 = *piVar9 + -1;
        param_3 = param_3 & -(uint)(iVar4 != 1);
        uVar8 = param_3;
        if (*piVar9 < 1) {
          TclFreeObj(piVar9);
          uVar8 = param_3;
        }
      }
    }
    if ((local_24 == 3) && (*(int *)(*(int *)(local_28 + 0xd4) + 0x54) == 1)) {
      FUN_004d2000();
      iVar4 = FUN_004d30c0(*(undefined4 *)(local_28 + 0xdc));
      if (iVar4 == -1) goto LAB_00691722;
    }
    else {
LAB_00691722:
      FUN_004d9ca0(&local_4c,local_20,uVar8);
    }
    if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
      TclFreeObj(piVar11);
    }
    local_8 = CONCAT31(local_8._1_3_,7);
    if (((int)local_48 < 0) && ((local_48 + 3 & 0xfffffffc) != 0)) {
      local_2c = (int *)0x0;
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      puVar5 = local_14;
      if (local_14 == (undefined4 *)0x0) {
        local_14 = (undefined4 *)FUN_006ba810(0x9b);
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
        puVar7 = puVar5 + -7;
        iVar4 = FUN_006ba730();
        if (iVar4 == 0) {
          param_3 = puVar5[-2];
          local_3c = (undefined4 *)(param_3 + 0x1c + (int)puVar7);
          iVar4 = FUN_006ba730();
          if (iVar4 != 0) goto LAB_00691832;
          if (puVar5[-5] != 0) {
            *(undefined4 *)(puVar5[-5] + 4) = puVar5[-6];
          }
          if (puVar5[-6] != 0) {
            *(undefined4 *)(puVar5[-6] + 8) = puVar5[-5];
          }
          if (puVar7 == DAT_00c3c81c) {
            DAT_00c3c81c = (undefined4 *)puVar5[-6];
          }
          _memset(puVar5,-0x20202021,param_3);
          bVar12 = DAT_0077248f == '\0';
          *puVar7 = 0xdfdfdfdf;
          puVar5[-1] = 0xdfdfdfdf;
          *local_3c = 0xdfdfdfdf;
          if ((((bVar12) || (DAT_00c1c788 == '\0')) || (puVar7 < DAT_00c3c7cc)) ||
             ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar7)) {
            FUN_006df631(puVar7);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_00691832:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",puVar5,iVar4);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_14 = (undefined4 *)0x0;
      }
    }
    uVar10 = 0;
    if (local_14 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_00691dbb:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

