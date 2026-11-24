
void FUN_005d4250(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int *in_ECX;
  uint uVar9;
  code *pcVar10;
  undefined4 *puVar11;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  uint local_2c;
  int *local_28;
  float local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00708b4d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(char *)(DAT_00772400 + 0x8a) != '\0') && (*(char *)(DAT_00772400 + 0xa098) != '\0')) {
    local_20 = in_ECX;
    if ((char)in_ECX[0x10f] != '\0') {
      iVar4 = in_ECX[0x10e];
      if (iVar4 == 0) {
        in_ECX[0x10e] = 1;
        iVar4 = 1;
      }
      if (iVar4 == 1) {
        bVar1 = false;
        iVar4 = 10;
        do {
          if (bVar1) goto LAB_005d4335;
          if (in_ECX[0x10b] + -1 < 0) {
            bVar1 = true;
          }
          else {
            FUN_005d8250(1,in_ECX[0x10b] + -1,1);
            FUN_005d9620(1);
          }
          iVar4 = iVar4 + -1;
        } while (0 < iVar4);
        if (bVar1) {
LAB_005d4335:
          in_ECX[0x10e] = 2;
        }
      }
      else if (iVar4 == 2) {
        if (in_ECX[0x109] + -1 < 0) {
          *(undefined1 *)(in_ECX + 0x10f) = 0;
          if (*(char *)((int)in_ECX + 0x43d) != '\0') {
            FUN_005d8330(uVar3);
          }
        }
        else {
          FUN_005d8250(0,in_ECX[0x109] + -1,0);
          FUN_005d9620(1);
        }
      }
    }
    FUN_0058a820();
    FUN_0058d370();
    pcVar10 = RaiseException_exref;
    uVar9 = 0xffffffff;
    local_1c = DAT_0077244c;
    uVar3 = DAT_0077244c;
    while( true ) {
      uVar9 = uVar9 + 1;
      if ((int)*(uint *)(uVar3 + 0x84b5) <= (int)uVar9) break;
      if (*(uint *)(uVar3 + 0x84b5) <= uVar9) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar3 = local_1c;
      }
      piVar6 = local_20 + 0x122;
      local_24 = *(float *)(*(int *)(uVar3 + 0x84b1) + uVar9 * 4);
      if ((uint)local_24 < 0x2000) {
        piVar6 = piVar6 + (int)local_24;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar3 = local_1c;
      }
      if (*piVar6 != 0) {
        if ((uint)local_24 < 0x2000) {
          FUN_005cbf70();
          uVar3 = local_1c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          FUN_005cbf70();
          uVar3 = local_1c;
        }
      }
    }
    FUN_005d4960();
    iVar4 = FUN_005b28d0();
    if (DAT_00772409 == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x14);
    }
    if (*(int *)(DAT_00772400 + 100) == iVar4) {
      iVar4 = FUN_00592d70();
      FUN_006b8fb0("Misc_Light");
      iVar5 = FUN_00601f90(&local_20);
      local_8 = 0;
      local_18 = iVar5;
      if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
        FUN_006ba940();
      }
      local_8 = 0xffffffff;
      if (iVar5 != 0) {
        local_24 = *(float *)(iVar4 + 0x12004);
        uVar3 = 0;
        if (0 < (int)local_24) {
          local_20 = (int *)0x0;
          do {
            if (*(uint *)(iVar4 + 0x12004) <= uVar3) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            uVar3 = uVar3 + 1;
            piVar6 = (int *)((int)local_20 + *(int *)(iVar4 + 0x12000) + 0xc);
            *piVar6 = *piVar6 + 1;
            local_20 = local_20 + 4;
          } while ((int)uVar3 < (int)local_24);
        }
        local_20 = *(int **)(iVar4 + 0x12004);
        local_1c = 0;
        if (0 < (int)local_20) {
          local_14 = 0;
          do {
            uVar9 = local_1c;
            uVar3 = *(uint *)(iVar4 + 0x12004);
            if (uVar3 <= local_1c) {
              (*pcVar10)(0xc000008c,1,0,0);
              uVar3 = *(uint *)(iVar4 + 0x12004);
            }
            iVar5 = *(int *)(iVar4 + 0x12000);
            if (((*(int *)(local_14 + 0xc + iVar5) == 3) && (PTR_0077241c != (CMap *)0x0)) &&
               ((char)PTR_0077241c->mapFlags != '\0')) {
              if (uVar3 <= uVar9) {
                (*pcVar10)(0xc000008c,1,0,0);
                iVar5 = *(int *)(iVar4 + 0x12000);
              }
              local_50 = *(float *)(local_14 + iVar5);
              local_4c = *(float *)(local_14 + 4 + iVar5);
              local_48 = *(float *)(local_14 + 8 + iVar5);
              local_28 = (int *)(int)ROUND(local_50 * 8.0);
              local_2c = (uint)ROUND(local_4c * 8.0);
              DAT_00772dd8 = (int)ROUND(local_48);
              local_38 = local_48;
              local_34 = local_4c;
              local_30 = local_50;
              local_24 = local_48;
              if (((PTR_0077241c->x0_8 + 1 <= (int)local_28) &&
                  ((int)local_28 < PTR_0077241c->x1_8 + -1)) &&
                 ((PTR_0077241c->y0_8 + 1 <= (int)local_2c &&
                  (((int)local_2c < PTR_0077241c->y1_8 + -1 &&
                   (cVar2 = FUN_00590e60(local_50,local_4c,local_48), cVar2 != '\0')))))) {
                piVar6 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
                *piVar6 = *piVar6 + 1;
                puVar11 = &local_44;
                local_8 = 1;
                local_44 = 0;
                local_40 = 0;
                local_3c = 0;
                local_28 = piVar6;
                if (*(uint *)(iVar4 + 0x12004) <= local_1c) {
                  (*pcVar10)(0xc000008c,1,0,0,puVar11);
                }
                iVar5 = *(int *)(iVar4 + 0x12000);
                *piVar6 = *piVar6 + 1;
                iVar5 = FUN_00601df0(0,DAT_0077244c,piVar6,iVar5 + local_14,puVar11);
                if (iVar5 != 0) {
                  *(uint *)(iVar5 + 0x3d0) = *(uint *)(iVar5 + 0x3d0) & 0xfffff96f;
                  if (*(int *)(iVar5 + 0x39c) == -1) {
                    if (*(int *)(local_18 + 0x1c) == 0) {
                      local_24 = -NAN;
                    }
                    else {
                      local_2c = *(int *)(iVar5 + 0x230) % *(int *)(local_18 + 0x1c);
                      if (*(uint *)(local_18 + 0x1c) <= local_2c) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      local_24 = *(float *)(*(int *)(local_18 + 0x18) + local_2c * 4);
                    }
                    if (*(int *)(local_18 + 0x14) == 0) {
                      uVar7 = 0xffffffff;
                    }
                    else {
                      local_2c = *(int *)(iVar5 + 0x230) % *(int *)(local_18 + 0x14);
                      if (*(uint *)(local_18 + 0x14) <= local_2c) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      uVar7 = *(undefined4 *)(*(int *)(local_18 + 0x10) + local_2c * 4);
                    }
                    FUN_005cdae0(uVar7,local_24,0,*(undefined4 *)(local_18 + 0x20));
                    if (*(int *)(local_18 + 0x14) == 0) {
                      uVar7 = 0xffffffff;
                    }
                    else {
                      local_2c = *(int *)(iVar5 + 0x230) % *(int *)(local_18 + 0x14);
                      if (*(uint *)(local_18 + 0x14) <= local_2c) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      uVar7 = *(undefined4 *)(*(int *)(local_18 + 0x10) + local_2c * 4);
                    }
                    *(undefined4 *)(iVar5 + 0x39c) = uVar7;
                    if (*(int *)(local_18 + 0x1c) == 0) {
                      uVar7 = 0xffffffff;
                    }
                    else {
                      local_2c = *(int *)(iVar5 + 0x230) % *(int *)(local_18 + 0x1c);
                      if (*(uint *)(local_18 + 0x1c) <= local_2c) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      uVar7 = *(undefined4 *)(*(int *)(local_18 + 0x18) + local_2c * 4);
                    }
                    *(undefined4 *)(iVar5 + 0x3a8) = uVar7;
                    *(undefined4 *)(iVar5 + 0x3a0) = 0;
                    FUN_004d9d10();
                  }
                  *(undefined4 *)(iVar5 + 0x36c) = 0xffffffff;
                  if ((((*(float *)(iVar5 + 0xc) != local_30) ||
                       (*(float *)(iVar5 + 0x10) != local_34)) ||
                      (*(float *)(iVar5 + 0x14) != local_38)) &&
                     (FUN_005cd8e0(&local_50), *(int *)(iVar5 + 0x238) == 0)) {
                    FUN_005ebc90(iVar5);
                    FUN_005eb470(iVar5);
                  }
                  piVar8 = (int *)FUN_005c9cc0();
                  if (((char)piVar8[1] != '\0') && (*piVar8 != 0)) {
                    LOCK();
                    DAT_00772dd4 = DAT_00772dd4 + -1;
                    UNLOCK();
                    Tcl_DeleteInterp(*piVar8);
                  }
                  *piVar8 = 0;
                }
                local_8 = 0xffffffff;
                *piVar6 = *piVar6 + -1;
                uVar9 = local_1c;
                pcVar10 = RaiseException_exref;
                if (*piVar6 < 1) {
                  TclFreeObj(piVar6);
                  uVar9 = local_1c;
                  pcVar10 = RaiseException_exref;
                }
              }
            }
            if (*(uint *)(iVar4 + 0x12004) <= uVar9) {
              (*pcVar10)(0xc000008c,1,0,0);
            }
            if (*(int *)(local_14 + 0xc + *(int *)(iVar4 + 0x12000)) == 6) {
              uVar3 = *(uint *)(iVar4 + 0x12004);
              if (uVar3 <= uVar9) {
                (*pcVar10)(0xc000008c,1,0,0);
                uVar3 = *(uint *)(iVar4 + 0x12004);
                if (uVar3 <= uVar9) {
                  (*pcVar10)(0xc000008c,1,0,0);
                  uVar3 = *(uint *)(iVar4 + 0x12004);
                }
              }
              if ((int)uVar9 < (int)(uVar3 - 1)) {
                iVar5 = local_14 + *(int *)(iVar4 + 0x12000);
                FUN_006d1b90(iVar5,iVar5 + 0x10,(uVar3 - uVar9) * 0x10 + -0x10);
                uVar3 = *(uint *)(iVar4 + 0x12004);
              }
              uVar9 = uVar9 - 1;
              local_14 = local_14 + -0x10;
              *(uint *)(iVar4 + 0x12004) = uVar3 - 1;
              local_20 = (int *)((int)local_20 + -1);
            }
            local_1c = uVar9 + 1;
            local_14 = local_14 + 0x10;
          } while ((int)local_1c < (int)local_20);
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

