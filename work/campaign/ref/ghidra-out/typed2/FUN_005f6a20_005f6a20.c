
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6a20(void)

{
  CMap *pCVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined1 local_4c [20];
  int local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pCVar1 = PTR_0077241c;
  iVar3 = DAT_00772400;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070992d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(DAT_00772400 + 0x80) = 0;
  if ((pCVar1 != (CMap *)0x0) && ((char)pCVar1->mapFlags != '\0')) {
    local_1c = *(uint *)(iVar3 + 100);
    _DAT_00c3c9c8 = _DAT_00c3c9c8 + 1;
    iVar3 = FUN_005b78b0(uVar2);
    local_38 = DAT_0077244c;
    local_14 = iVar3;
    FUN_006b90d0(&local_34,"Free Dummies:%d / %d",*(undefined4 *)(iVar3 + 0xc004),0x3000);
    local_8 = 0;
    if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
      FUN_006ba940();
    }
                    /* WARNING: Load size is inaccurate */
    local_34 = *ThreadLocalStoragePointer;
    if ((local_34[1] < DAT_00ca6a64) &&
       (FUN_006cebf4(&DAT_00ca6a64), iVar5 = DAT_00783650, DAT_00ca6a64 == -1)) {
      iVar6 = DAT_00783650 * 0x40;
      _DAT_00ca6a68 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar6) = "CSrvObjUpdateMgr Pass1";
      *(int *)(&DAT_00773650 + iVar6) = iVar5;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6a64);
    }
    FUN_00405af0(&DAT_00ca6a68);
    local_8 = 1;
    local_24 = (int *)0xffffffff;
    while( true ) {
      local_24 = (int *)((int)local_24 + 1);
      if ((int)*(int **)(iVar3 + 0xc015) <= (int)local_24) break;
      if (*(int **)(iVar3 + 0xc015) <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(*(int *)(iVar3 + 0xc011) + (int)local_24 * 4);
      if ((iVar5 < 0) || (*(int *)(iVar3 + 0xc00c) <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = *(int **)(iVar3 + 0xc008);
        piVar7 = extraout_ECX;
      }
      else {
        piVar10 = (int *)(iVar5 * 0xd8 + *(int *)(iVar3 + 0xc008));
        piVar7 = local_24;
      }
      iVar5 = piVar10[0x1d];
      iVar3 = local_14;
      if (iVar5 != -1) {
        if (iVar5 < 0) {
          local_28 = (int *)0xff;
        }
        else {
          if (iVar5 < 0x10) {
            piVar4 = piVar10 + iVar5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar4 = piVar10;
            piVar7 = extraout_ECX_00;
          }
          if (*piVar4 < 0) {
            FUN_005b7550(local_4c);
            if (iVar5 < 0x10) {
              local_28 = piVar10 + iVar5;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_28 = piVar10;
            }
            iVar3 = FUN_00580ea0();
            *local_28 = iVar3;
            piVar7 = local_28;
          }
          if (iVar5 < 0x10) {
            local_28 = piVar10 + iVar5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = piVar10;
            piVar7 = extraout_ECX_01;
          }
          local_28 = (int *)*local_28;
        }
        if (((char)piVar10[0x21] != '\0') || (*(char *)((int)piVar10 + 0x85) != '\0')) {
          *(undefined1 *)((int)piVar10 + 0x55) = 1;
          FUN_00453f00(piVar7);
          *(undefined2 *)(piVar10 + 0x21) = 0;
          piVar10[0x26] = 0;
          piVar10[0x25] = 0;
          piVar10[0x24] = 0;
          if (((uint)piVar10[0x1e] < 0x100) &&
             ((iVar3 = *(int *)(DAT_00772400 + 0x5c8 + piVar10[0x1e] * 4), iVar3 != 0 &&
              (iVar5 = piVar10[0x1f], iVar5 != -1)))) {
            if ((iVar5 < 0) || (*(int *)(iVar3 + 0x38) <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(iVar3 + 0x34);
            }
            else {
              iVar3 = iVar5 * 0xe8 + *(int *)(iVar3 + 0x34);
            }
            piVar10[0x1f] = *(int *)(iVar3 + 0xdc);
          }
        }
        iVar3 = local_14;
        if ((0x7f < (int)local_28) || (*(char *)((int)piVar10 + 0xb6) == '\0')) {
          *(undefined1 *)(piVar10 + 0x1c) = 1;
        }
      }
    }
    FUN_0043fd30();
    if ((local_34[1] < DAT_00ca6a6c) &&
       (FUN_006cebf4(&DAT_00ca6a6c), iVar5 = DAT_00783650, DAT_00ca6a6c == -1)) {
      iVar6 = DAT_00783650 * 0x40;
      _DAT_00ca6a70 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar6) = "CSrvObjUpdateMgr Pass2";
      *(int *)(&DAT_00773650 + iVar6) = iVar5;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6a6c);
    }
    FUN_00405af0(&DAT_00ca6a70);
    local_8 = 2;
    local_20 = 0xffffffff;
LAB_005f6ce6:
    iVar5 = local_38;
    local_20 = local_20 + 1;
    if ((int)local_20 < (int)*(uint *)(local_38 + 0x84b5)) {
      if (*(uint *)(local_38 + 0x84b5) <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = (undefined4 *)(iVar5 + 0x488);
      uVar2 = *(uint *)(*(int *)(iVar5 + 0x84b1) + local_20 * 4);
      if (uVar2 < 0x2000) {
        puVar11 = puVar11 + uVar2;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar10 = (int *)*puVar11;
      iVar3 = local_14;
      local_28 = piVar10;
      if ((1 < (int)uVar2) && (piVar10 != (int *)0x0)) {
        if ((*(byte *)(piVar10 + 0xf4) & 1) == 0) {
          piVar7 = piVar10 + 0xdf;
          local_18 = 0;
          if (local_1c < 8) {
            piVar4 = piVar7 + local_1c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar4 = piVar7;
          }
          if (*piVar4 == -1) goto LAB_005f6d5e;
          if (local_1c < 8) {
            piVar7 = piVar7 + local_1c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar3 = local_14;
          iVar5 = *piVar7;
          if ((iVar5 < 0) || (*(int *)(local_14 + 0xc00c) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(iVar3 + 0xc008);
          }
          else {
            iVar5 = iVar5 * 0xd8 + *(int *)(local_14 + 0xc008);
          }
          *(undefined4 *)(iVar5 + 0xac) = 0;
        }
        else {
          local_18 = FUN_005cb3a0(local_1c);
LAB_005f6d5e:
          piVar7 = piVar10 + 0xdf;
          iVar3 = local_14;
          local_30 = piVar7;
          if (0x7f < local_18) {
            if (local_1c < 8) {
              piVar7 = piVar7 + local_1c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar5 = local_14;
            iVar3 = *piVar7;
            piVar10 = (int *)(local_14 + 0xc008);
            if (iVar3 == -1) {
              *(int *)(DAT_00772400 + 0x80) = *(int *)(DAT_00772400 + 0x80) + 1;
              iVar3 = FUN_005b7c30(local_1c);
              if ((iVar3 < 0) || (*(int *)(iVar5 + 0xc00c) <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *piVar10;
              }
              else {
                iVar6 = *piVar10 + iVar3 * 0xd8;
              }
              local_24 = (int *)(iVar3 * 0xd8);
              FUN_005f5ef0(local_28,iVar6,1);
              if (local_1c < 8) {
                piVar7 = local_30 + local_1c;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar7 = local_30;
              }
              *piVar7 = iVar3;
              if ((iVar3 < 0) || (*(int *)(iVar5 + 0xc00c) <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *piVar10;
                iVar8 = iVar6;
              }
              else {
                iVar6 = (int)local_24 + *piVar10;
                iVar8 = *piVar10;
              }
              if (*(int *)(iVar6 + 0xac) + 0x20 <= local_18) {
                if ((iVar3 < 0) || (*(int *)(iVar5 + 0xc00c) <= iVar3)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *piVar10;
                  iVar8 = iVar6;
                }
                else {
                  iVar6 = (int)local_24 + iVar8;
                }
                local_18 = *(int *)(iVar6 + 0xac) + 0x20;
              }
              if ((iVar3 < 0) || (*(int *)(iVar5 + 0xc00c) <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(int *)(*piVar10 + 0xac) = local_18;
                if (-1 < iVar3) goto LAB_005f704e;
              }
              else {
                *(int *)((int)local_24 + iVar8 + 0xac) = local_18;
LAB_005f704e:
                if (iVar3 < *(int *)(iVar5 + 0xc00c)) {
                  *(undefined1 *)((int)local_24 + *piVar10 + 0x70) = 0;
                  iVar3 = local_14;
                  goto LAB_005f6ce6;
                }
              }
            }
            else {
              if ((iVar3 < 0) || (*(int *)(local_14 + 0xc00c) <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_24 = (int *)(iVar3 * 0xd8);
                FUN_005f5ef0(local_28,*piVar10,0);
                if (-1 < iVar3) goto LAB_005f6e94;
LAB_005f6ea2:
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar6 = *piVar10;
                iVar8 = iVar6;
              }
              else {
                local_24 = (int *)(iVar3 * 0xd8);
                FUN_005f5ef0(local_28,*piVar10 + (int)local_24,0);
LAB_005f6e94:
                if (*(int *)(iVar5 + 0xc00c) <= iVar3) goto LAB_005f6ea2;
                iVar6 = (int)local_24 + *piVar10;
                iVar8 = *piVar10;
              }
              if (*(int *)(iVar6 + 0xac) + 0x20 <= local_18) {
                if ((iVar3 < 0) || (*(int *)(iVar5 + 0xc00c) <= iVar3)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *piVar10;
                  iVar8 = iVar6;
                }
                else {
                  iVar6 = (int)local_24 + iVar8;
                }
                local_18 = *(int *)(iVar6 + 0xac) + 0x20;
              }
              if ((iVar3 < 0) || (*(int *)(iVar5 + 0xc00c) <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                *(int *)(*piVar10 + 0xac) = local_18;
                if (iVar3 < 0) goto LAB_005f7066;
              }
              else {
                *(int *)((int)local_24 + iVar8 + 0xac) = local_18;
              }
              if (iVar3 < *(int *)(iVar5 + 0xc00c)) {
                *(undefined1 *)((int)local_24 + *piVar10 + 0x70) = 0;
                iVar3 = local_14;
                goto LAB_005f6ce6;
              }
            }
LAB_005f7066:
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(undefined1 *)(*piVar10 + 0x70) = 0;
            iVar3 = local_14;
            goto LAB_005f6ce6;
          }
        }
        if (local_1c < 8) {
          (piVar10 + 0xdf)[local_1c] = -1;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10[0xdf] = -1;
        }
      }
      goto LAB_005f6ce6;
    }
    FUN_0043fd30();
    if ((local_34[1] < DAT_00ca6a74) &&
       (FUN_006cebf4(&DAT_00ca6a74), iVar5 = DAT_00783650, DAT_00ca6a74 == -1)) {
      iVar6 = DAT_00783650 * 0x40;
      _DAT_00ca6a78 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar6) = "CSrvObjUpdateMgr Pass3";
      *(int *)(&DAT_00773650 + iVar6) = iVar5;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6a74);
    }
    FUN_00405af0(&DAT_00ca6a78);
    local_8 = 3;
    local_24 = (int *)0xffffffff;
    while( true ) {
      local_24 = (int *)((int)local_24 + 1);
      if ((int)*(uint *)(iVar3 + 0xc015) <= (int)local_24) break;
      if (*(uint *)(iVar3 + 0xc015) <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = local_14;
      piVar10 = (int *)(local_14 + 0xc008);
      iVar5 = *(int *)(*(int *)(iVar3 + 0xc011) + (int)local_24 * 4);
      if ((iVar5 < 0) || (*(int *)(local_14 + 0xc00c) <= iVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = *piVar10;
        iVar9 = iVar8;
      }
      else {
        iVar8 = *piVar10 + iVar5 * 0xd8;
        iVar9 = *piVar10;
      }
      local_2c = iVar5 * 0xd8;
      iVar3 = local_14;
      if (*(int *)(iVar8 + 0x74) != -1) {
        if ((iVar5 < 0) || (*(int *)(iVar6 + 0xc00c) <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *piVar10;
          iVar9 = iVar8;
        }
        else {
          iVar8 = local_2c + iVar9;
        }
        iVar3 = local_14;
        if (*(char *)(iVar8 + 0x70) != '\0') {
          if ((iVar5 < 0) || (*(int *)(iVar6 + 0xc00c) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(int *)(*piVar10 + 0xac) = *(int *)(*piVar10 + 0xac) + -0x20;
            if (-1 < iVar5) goto LAB_005f71c7;
LAB_005f71d2:
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *piVar10;
          }
          else {
            piVar7 = (int *)(local_2c + 0xac + iVar9);
            *piVar7 = *piVar7 + -0x20;
LAB_005f71c7:
            if (*(int *)(iVar6 + 0xc00c) <= iVar5) goto LAB_005f71d2;
            iVar6 = *piVar10 + local_2c;
          }
          iVar3 = local_14;
          if (*(int *)(iVar6 + 0xac) < 1) {
            FUN_005b7e30(iVar5);
          }
        }
      }
    }
    FUN_0043fd30();
  }
  ExceptionList = local_10;
  return;
}

