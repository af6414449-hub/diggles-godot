
void FUN_1001d3b0(undefined4 *param_1,uint param_2,int param_3,void *param_4,undefined4 param_5,
                 float param_6,int param_7)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  void *_Dst;
  int iVar12;
  int *piVar13;
  float fVar14;
  double dVar15;
  int local_2c;
  uint local_28;
  float *local_24;
  uint local_20;
  uint local_18;
  uint local_14;
  uint local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar11 = param_2;
  if (param_2 != 0) {
    do {
      puVar3 = param_1;
      iVar6 = param_7;
      if (param_7 != 0) {
        do {
          *puVar3 = 0;
          iVar6 = iVar6 + -1;
          puVar3 = puVar3 + param_3;
        } while (iVar6 != 0);
      }
      param_1 = param_1 + 1;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  local_14 = 0;
  if (*(int *)(in_ECX + 0x1cda4) != 0) {
    piVar4 = (int *)(in_ECX + 0x1bda4);
    do {
      piVar1 = *(int **)(in_ECX + 0x40 + *piVar4 * 4);
      if ((piVar1 != (int *)0x0) && (piVar1[0x60] == 0)) {
        if ((*(byte *)(piVar1 + 4) & 0x24) == 0) {
          fVar14 = (float)piVar1[0x11] / param_6;
          if (4096.0 < fVar14) {
            fVar14 = 0.0;
          }
          dVar15 = floor((double)(fVar14 * 1048576.0));
          uVar11 = piVar1[0x6d];
          uVar9 = (uint)dVar15;
          local_c = 0;
          if (uVar11 != 0) {
            local_c = uVar11;
            if (param_2 < uVar11) {
              local_c = param_2;
            }
            uVar10 = 0;
            piVar1[0x6d] = -(uint)(param_2 < uVar11) & uVar11 - param_2;
            if (piVar1[0x12] != 0) {
              _Dst = param_4;
              do {
                memset(_Dst,0,local_c * 4);
                uVar10 = uVar10 + 1;
                _Dst = (void *)((int)_Dst + param_3 * 4);
              } while (uVar10 < (uint)piVar1[0x12]);
            }
          }
          if (uVar9 != 0) {
            while (local_c < param_2) {
              if (piVar1[0x6c] == 0) {
                iVar6 = piVar1[0x69];
                iVar12 = 0;
                piVar1[0x69] = piVar1[0x6a];
                piVar1[0x6a] = iVar6;
                cVar2 = (**(code **)(*piVar1 + 8))();
                if ((cVar2 == '\0') || ((*(byte *)(piVar1 + 4) & 1) != 0)) {
                  iVar12 = (**(code **)(*piVar1 + 4))();
                  if (iVar12 < 0x200) {
                    if ((*(byte *)(piVar1 + 4) & 1) == 0) goto LAB_1001d603;
                    do {
                      iVar6 = (**(code **)(*piVar1 + 0xc))();
                      if (iVar6 != 0) goto LAB_1001d603;
                      piVar1[3] = piVar1[3] + 1;
                      iVar6 = (**(code **)(*piVar1 + 4))();
                      iVar12 = iVar12 + iVar6;
                      if (iVar6 == 0) {
                        if (iVar12 < 0x200) goto LAB_1001d603;
                        break;
                      }
                    } while (iVar12 < 0x200);
                  }
                }
                else {
LAB_1001d603:
                  uVar11 = 0;
                  if (piVar1[0x12] != 0) {
                    iVar6 = iVar12 * 4;
                    do {
                      memset((void *)(*(int *)piVar1[0x69] + iVar6),0,iVar12 * -4 + 0x800);
                      uVar11 = uVar11 + 1;
                      iVar6 = iVar6 + 0x800;
                    } while (uVar11 < (uint)piVar1[0x12]);
                  }
                }
                if ((uint)piVar1[0x6b] < 0x20000000) {
                  iVar6 = 0;
                }
                else {
                  iVar6 = piVar1[0x6b] + 0xe0000000;
                }
                piVar1[0x6b] = iVar6;
                piVar13 = piVar1 + 0x61;
                iVar6 = 8;
                do {
                  if ((int *)*piVar13 != (int *)0x0) {
                    (**(code **)(*(int *)*piVar13 + 8))(*(undefined4 *)piVar1[0x69],0x200);
                  }
                  piVar13 = piVar13 + 1;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
              else {
                piVar1[0x6c] = 0;
              }
              uVar11 = piVar1[0x6b];
              local_20 = 0;
              if (uVar11 < 0x20000000) {
                uVar10 = (0x20000000 - uVar11) / uVar9;
                local_20 = uVar10 + 1;
                if (0x1fffffff < (local_20 * uVar9 + uVar11 & 0xfff00000)) {
                  local_20 = uVar10;
                }
              }
              if (param_2 < local_20 + local_c) {
                piVar1[0x6c] = (local_20 - param_2) + local_c;
                local_20 = param_2 - local_c;
              }
              if ((local_20 != 0) && (local_28 = 0, piVar1[0x12] != 0)) {
                local_2c = 0;
                local_24 = (float *)((int)param_4 + local_c * 4);
                do {
                  uVar11 = piVar1[0x6b];
                  iVar6 = *(int *)piVar1[0x69];
                  iVar12 = *(int *)piVar1[0x6a];
                  pfVar7 = local_24;
                  uVar10 = local_20;
                  if (0 < (int)local_20) {
                    do {
                      iVar5 = (int)uVar11 >> 0x14;
                      uVar8 = uVar11 & 0xfffff;
                      fVar14 = *(float *)(iVar12 + local_2c + 0x7fc);
                      if (iVar5 != 0) {
                        fVar14 = *(float *)(iVar6 + local_2c + -4 + iVar5 * 4);
                      }
                      uVar11 = uVar11 + uVar9;
                      *pfVar7 = (*(float *)(iVar6 + local_2c + iVar5 * 4) - fVar14) * (float)uVar8 *
                                9.536743e-07 + fVar14;
                      uVar10 = uVar10 - 1;
                      pfVar7 = pfVar7 + 1;
                    } while (uVar10 != 0);
                    uVar11 = piVar1[0x6b];
                  }
                  local_2c = local_2c + 0x800;
                  local_28 = local_28 + 1;
                  local_24 = local_24 + param_3;
                } while (local_28 < (uint)piVar1[0x12]);
              }
              local_c = local_c + local_20;
              piVar1[0x6b] = local_20 * uVar9 + uVar11;
            }
          }
          FUN_1001b970(param_2,param_3,param_4,param_7);
        }
        else {
          if (((piVar1[4] & 4U) != 0) || (((byte)piVar1[4] & 0xa0) != 0xa0)) goto LAB_1001da4d;
          dVar15 = floor((double)(((float)piVar1[0x11] / param_6) * 1048576.0));
          uVar11 = piVar1[0x6d];
          local_18 = 0;
          if (uVar11 != 0) {
            if (param_2 < uVar11) {
              piVar1[0x6d] = uVar11 - param_2;
              local_18 = param_2;
            }
            else {
              piVar1[0x6d] = 0;
              local_18 = uVar11;
            }
          }
          if ((int)dVar15 != 0) {
            while (local_18 < param_2) {
              if (piVar1[0x6c] == 0) {
                iVar6 = piVar1[0x69];
                piVar1[0x69] = piVar1[0x6a];
                piVar1[0x6a] = iVar6;
                cVar2 = (**(code **)(*piVar1 + 8))();
                if ((((cVar2 == '\0') || ((*(byte *)(piVar1 + 4) & 1) != 0)) &&
                    (iVar6 = (**(code **)(*piVar1 + 4))(), iVar6 < 0x200)) &&
                   ((*(byte *)(piVar1 + 4) & 1) != 0)) {
                  do {
                    iVar12 = (**(code **)(*piVar1 + 0xc))
                                       (*(undefined8 *)(piVar1 + 0x6e),
                                        *(undefined4 *)(in_ECX + 0x18),
                                        *(undefined4 *)(in_ECX + 0x24));
                    if (iVar12 != 0) break;
                    piVar1[3] = piVar1[3] + 1;
                    iVar12 = (**(code **)(*piVar1 + 4))();
                    iVar6 = iVar6 + iVar12;
                  } while (iVar6 < 0x200);
                }
                uVar11 = 0;
                if (0x1fffffff < (uint)piVar1[0x6b]) {
                  uVar11 = piVar1[0x6b] + 0xe0000000;
                }
              }
              else {
                piVar1[0x6c] = 0;
                uVar11 = piVar1[0x6b];
              }
              uVar9 = 0;
              if (uVar11 < 0x20000000) {
                uVar10 = (0x20000000 - uVar11) / (uint)(int)dVar15;
                uVar9 = uVar10 + 1;
                if (0x1fffffff < (uVar9 * (int)dVar15 + uVar11 & 0xfff00000)) {
                  uVar9 = uVar10;
                }
              }
              if (param_2 < uVar9 + local_18) {
                piVar1[0x6c] = (uVar9 - param_2) + local_18;
                uVar9 = param_2 - local_18;
              }
              local_18 = local_18 + uVar9;
              piVar1[0x6b] = uVar9 * (int)dVar15 + uVar11;
            }
          }
        }
        if (((*(byte *)(piVar1 + 4) & 1) == 0) &&
           (cVar2 = (**(code **)(*piVar1 + 8))(), cVar2 != '\0')) {
          FUN_100205c0();
        }
      }
LAB_1001da4d:
      local_14 = local_14 + 1;
      piVar4 = piVar4 + 1;
    } while (local_14 < *(uint *)(in_ECX + 0x1cda4));
  }
  return;
}

