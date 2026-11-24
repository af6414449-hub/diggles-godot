
undefined1 __thiscall FUN_0051cc30(ViWinObjJoin *this)

{
  float fVar1;
  bool bVar2;
  ViWinObjJoin *pVVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  undefined1 uVar10;
  bool bVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  ViWinObjJoin *pVVar16;
  int *piVar17;
  undefined4 *in_stack_00000004;
  int **ppiVar18;
  int *piVar19;
  int *local_44;
  int *local_40;
  int *local_3c;
  uint local_38;
  uint local_34;
  float local_30;
  int *local_2c;
  int *local_28;
  ViWinObjJoin *local_24;
  ViWinObjJoin *local_20;
  float local_1c;
  ViWinObjJoin *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00702025;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar2 = false;
  bVar11 = false;
  local_8 = 0;
  local_20 = this;
  if (in_stack_00000004[2] == DAT_00772388) {
    iVar5 = in_stack_00000004[6];
    local_8._1_3_ = 0;
    if (iVar5 == this->i_50) {
      local_20 = *(ViWinObjJoin **)(this->i_60 + 0x20);
      if (local_20 != (ViWinObjJoin *)0x0) {
        *(int *)local_20 = *(int *)local_20 + 1;
      }
      local_8._0_1_ = 1;
      FUN_0051d570(&local_20);
      local_8 = CONCAT31(local_8._1_3_,2);
      if ((local_20 != (ViWinObjJoin *)0x0) &&
         (*(int *)local_20 = *(int *)local_20 + -1, *(int *)local_20 == 0)) {
        FUN_006ba940();
        uVar10 = 1;
        goto LAB_0051d53c;
      }
    }
    else {
      if (iVar5 != this->i_54) {
        if (iVar5 == this->i_58) {
          FUN_0051e100();
          uVar10 = 1;
          goto LAB_0051d53c;
        }
        if (iVar5 == this->i_44) {
          FUN_0051e830(in_stack_00000004);
          FUN_0051c8e0();
          uVar10 = 1;
          goto LAB_0051d53c;
        }
        if (iVar5 == this->i_48) {
          if (0 < *(int *)(DAT_00772400 + 0xa0c8)) {
            if (*(int *)&this[1].field_0x4 == 0) {
              iVar5 = FUN_005e3690(0);
              FUN_0051e8f0(1);
              iVar6 = *(int *)(iVar5 + 0xd4) + 0xc;
              iVar13 = *(int *)&this[1].field_0x4 + -1;
              FUN_0043d740(iVar13);
              FUN_006b91c0(iVar6);
              iVar6 = FUN_0043d740(iVar13);
              *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(iVar5 + 0xc);
              *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar5 + 0x10);
              *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar5 + 0x14);
              iVar6 = FUN_0043d740(iVar13);
              *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar5 + 0x40);
              *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(iVar5 + 0x44);
              *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar5 + 0x48);
              uVar7 = FUN_006b95d0(*(int *)(iVar5 + 0xd4) + 0xc);
              local_8._0_1_ = 5;
              FUN_00504910(uVar7);
              local_8 = CONCAT31(local_8._1_3_,6);
              piVar12 = local_2c;
LAB_0051d056:
              if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
                FUN_006ba940();
              }
              local_8 = local_8 & 0xffffff00;
              FUN_0051c8e0();
              uVar10 = 1;
              goto LAB_0051d53c;
            }
            local_2c = (int *)FUN_005e3690(0);
            piVar12 = *(int **)(local_2c[0x35] + 0xc);
            if (piVar12 != (int *)0x0) {
              *piVar12 = *piVar12 + 1;
            }
            local_24 = this + 1;
            local_8 = CONCAT31(local_8._1_3_,7);
            local_3c = piVar12;
            local_28 = piVar12;
            iVar5 = FUN_0043d740(0);
            pVVar3 = local_24;
            local_40 = (int *)local_2c[0x10];
            pVVar16 = (ViWinObjJoin *)((float)local_2c[3] - *(float *)(iVar5 + 4));
            local_1c = (float)local_2c[4] - *(float *)(iVar5 + 8);
            local_14 = (int *)((float)local_2c[5] - *(float *)(iVar5 + 0xc));
            local_38 = *(uint *)&this[1].field_0x4;
            uVar14 = 0;
            local_44 = (int *)local_2c[0x11];
            iVar5 = local_2c[0x12];
            local_18 = pVVar16;
            if (0 < (int)local_38) {
              local_34 = local_38 + 1;
              local_30 = 0.0;
              do {
                if (*(uint *)&pVVar3->field_0x4 <= uVar14) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pVVar16 = local_18;
                }
                local_2c = (int *)(uVar14 * 0x1c);
                cVar4 = FUN_006b97f0(&local_28);
                if (cVar4 == '\0') {
LAB_0051cf5b:
                  bVar2 = false;
                }
                else {
                  if (*(uint *)&pVVar3->field_0x4 <= uVar14) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pVVar16 = local_18;
                  }
                  iVar6 = *(int *)pVVar3;
                  if ((((*(float *)((int)local_2c + iVar6 + 4) != (float)pVVar16) ||
                       (*(float *)((int)local_2c + iVar6 + 8) != local_1c)) ||
                      (*(float *)((int)local_2c + iVar6 + 0xc) != (float)local_14)) &&
                     (((bVar11 = true, (float)pVVar16 != local_30 || (local_1c != local_30)) ||
                      ((float)local_14 != local_30)))) goto LAB_0051cf5b;
                  bVar2 = true;
                }
                if (bVar11) {
                  bVar11 = false;
                }
                uVar8 = local_34;
                if (!bVar2) {
                  uVar8 = uVar14;
                }
                uVar14 = uVar8 + 1;
                piVar12 = local_3c;
              } while ((int)uVar14 < (int)local_38);
            }
            pVVar3 = local_24;
            if (uVar14 == local_38) {
              FUN_0051e8f0(1);
              ppiVar18 = &local_28;
              iVar13 = *(int *)&pVVar3->field_0x4 + -1;
              FUN_0043d740(iVar13);
              FUN_006b91c0(ppiVar18);
              iVar6 = FUN_0043d740(iVar13);
              *(ViWinObjJoin **)(iVar6 + 4) = local_18;
              *(float *)(iVar6 + 8) = local_1c;
              *(int **)(iVar6 + 0xc) = local_14;
              iVar6 = FUN_0043d740(iVar13);
              *(int **)(iVar6 + 0x10) = local_40;
              *(int **)(iVar6 + 0x14) = local_44;
              *(int *)(iVar6 + 0x18) = iVar5;
            }
            local_8 = CONCAT31(local_8._1_3_,8);
            goto LAB_0051d2e8;
          }
        }
        else {
          if (iVar5 != this->i_4c) goto LAB_0051d30d;
          if ((*(int *)(DAT_00772400 + 0xa0c8) < 1) ||
             (local_14 = *(int **)&this[1].field_0x4, local_14 == (int *)0x0)) goto LAB_0051d2ff;
          if (local_14 == (int *)0x1) {
            FUN_0051e830(this + 1);
            FUN_006b8fb0(&PTR_0071ce50);
            local_8._0_1_ = 9;
            FUN_00504910(&local_28);
            local_8 = CONCAT31(local_8._1_3_,10);
            piVar12 = local_28;
            goto LAB_0051d056;
          }
          iVar5 = FUN_005e3690(0);
          piVar12 = *(int **)(*(int *)(iVar5 + 0xd4) + 0xc);
          if (piVar12 != (int *)0x0) {
            *piVar12 = *piVar12 + 1;
          }
          local_18 = this + 1;
          local_8 = CONCAT31(local_8._1_3_,0xb);
          local_44 = piVar12;
          local_3c = piVar12;
          iVar6 = FUN_0043d740(0);
          pVVar3 = local_18;
          piVar15 = (int *)0x0;
          local_2c = (int *)0xffffffff;
          piVar17 = (int *)(*(float *)(iVar5 + 0xc) - *(float *)(iVar6 + 4));
          local_24 = (ViWinObjJoin *)(*(float *)(iVar5 + 0x10) - *(float *)(iVar6 + 8));
          local_1c = *(float *)(iVar5 + 0x14) - *(float *)(iVar6 + 0xc);
          local_28 = piVar17;
          if (0 < (int)local_14) {
            local_40 = (int *)((int)local_14 + 1);
            do {
              if (*(int **)&pVVar3->field_0x4 <= piVar15) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar17 = local_28;
              }
              iVar5 = (int)piVar15 * 0x1c;
              cVar4 = FUN_006b97f0(&local_44);
              if (cVar4 == '\0') {
LAB_0051d1bf:
                bVar11 = false;
              }
              else {
                if (*(int **)&pVVar3->field_0x4 <= piVar15) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar17 = local_28;
                }
                iVar6 = *(int *)pVVar3;
                if ((((*(float *)(iVar5 + 4 + iVar6) != (float)piVar17) ||
                     (*(float *)(iVar5 + 8 + iVar6) != (float)local_24)) ||
                    (*(float *)(iVar5 + 0xc + iVar6) != local_1c)) &&
                   (((piVar15 != (int *)0x0 || (bVar2 = true, (float)piVar17 != 0.0)) ||
                    (((float)local_24 != 0.0 || (local_1c != 0.0)))))) goto LAB_0051d1bf;
                bVar11 = true;
              }
              pVVar16 = local_18;
              piVar12 = local_3c;
              if (bVar2) {
                bVar2 = false;
              }
              piVar9 = local_40;
              piVar19 = piVar15;
              if (!bVar11) {
                piVar9 = piVar15;
                piVar19 = local_2c;
              }
              piVar15 = (int *)((int)piVar9 + 1);
              local_2c = piVar19;
            } while ((int)piVar15 < (int)local_14);
            if (piVar19 == (int *)0x0) {
              iVar5 = FUN_0043d740(1);
              local_2c = *(int **)(iVar5 + 4);
              fVar1 = *(float *)(iVar5 + 8);
              local_40 = *(int **)(iVar5 + 0xc);
              iVar5 = FUN_0043d740(0);
              iVar6 = FUN_0043d740(1);
              *(float *)(iVar6 + 4) = *(float *)(iVar6 + 4) + *(float *)(iVar5 + 4);
              *(float *)(iVar6 + 8) = *(float *)(iVar5 + 8) + *(float *)(iVar6 + 8);
              *(float *)(iVar6 + 0xc) = *(float *)(iVar5 + 0xc) + *(float *)(iVar6 + 0xc);
              local_28 = (int *)0x2;
              if (2 < (int)local_14) {
                iVar5 = 0x38;
                piVar15 = local_14;
                piVar17 = local_2c;
                do {
                  if (*(int **)&pVVar16->field_0x4 <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar15 = local_14;
                    piVar17 = local_2c;
                  }
                  iVar6 = *(int *)pVVar16;
                  *(float *)(iVar5 + 4 + iVar6) = *(float *)(iVar5 + 4 + iVar6) + (float)piVar17;
                  *(float *)(iVar5 + 8 + iVar6) = fVar1 + *(float *)(iVar5 + 8 + iVar6);
                  *(float *)(iVar5 + 0xc + iVar6) =
                       (float)local_40 + *(float *)(iVar5 + 0xc + iVar6);
                  iVar5 = iVar5 + 0x1c;
                  local_28 = (int *)((int)local_28 + 1);
                } while ((int)local_28 < (int)piVar15);
              }
              piVar19 = (int *)0x0;
            }
            else if ((int)piVar19 < 1) goto LAB_0051d2e4;
            FUN_0051e6f0(piVar19);
          }
LAB_0051d2e4:
          local_8 = CONCAT31(local_8._1_3_,0xc);
LAB_0051d2e8:
          if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
            FUN_006ba940();
          }
          local_8 = local_8 & 0xffffff00;
        }
LAB_0051d2ff:
        FUN_0051c8e0();
        uVar10 = 1;
        goto LAB_0051d53c;
      }
      piVar12 = *(int **)(this->i_60 + 0x20);
      if (piVar12 != (int *)0x0) {
        *piVar12 = *piVar12 + 1;
      }
      local_8._0_1_ = 3;
      local_2c = piVar12;
      FUN_0051d970(&local_2c);
      local_8 = CONCAT31(local_8._1_3_,4);
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
        FUN_006ba940();
        uVar10 = 1;
        goto LAB_0051d53c;
      }
    }
  }
  else {
LAB_0051d30d:
    if (((in_stack_00000004[2] == DAT_0077237c) && (in_stack_00000004[6] == this->i_5c)) &&
       (iVar5 = in_stack_00000004[0x10], iVar5 != -1)) {
      iVar6 = *(int *)&this[1].field_0x4;
      FUN_006b8f50(DAT_0076700c ^ (uint)&stack0xfffffffc);
      local_8 = CONCAT31(local_8._1_3_,0xd);
      if (iVar6 < 1) {
LAB_0051d3fd:
        local_18 = (ViWinObjJoin *)0x0;
        local_1c = 0.0;
        local_20 = (ViWinObjJoin *)0x0;
      }
      else if (iVar5 == 0) {
        iVar5 = FUN_0043d740(0);
        local_20 = *(ViWinObjJoin **)(iVar5 + 4);
        local_1c = *(float *)(iVar5 + 8);
        local_18 = *(ViWinObjJoin **)(iVar5 + 0xc);
        uVar7 = FUN_0043d740(0);
        FUN_006b91c0(uVar7);
      }
      else {
        if ((iVar6 <= iVar5) || (iVar5 < 1)) goto LAB_0051d3fd;
        iVar6 = FUN_0043d740(iVar5);
        iVar13 = FUN_0043d740(0);
        local_20 = (ViWinObjJoin *)(*(float *)(iVar13 + 4) + *(float *)(iVar6 + 4));
        local_1c = *(float *)(iVar6 + 8) + *(float *)(iVar13 + 8);
        local_18 = (ViWinObjJoin *)(*(float *)(iVar6 + 0xc) + *(float *)(iVar13 + 0xc));
        uVar7 = FUN_0043d740(iVar5);
        FUN_006b91c0(uVar7);
      }
      uVar14 = 0;
      piVar12 = (int *)(DAT_0077244c + 0x488);
      do {
        if (uVar14 < 0x2000) {
          piVar15 = piVar12 + uVar14;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar15 = piVar12;
        }
        iVar5 = *piVar15;
        if (((iVar5 != 0) && (*(int *)(iVar5 + 0xd4) != 0)) &&
           ((*(float *)(iVar5 + 0xc) == (float)local_20 &&
            (((*(float *)(iVar5 + 0x10) == local_1c && (*(float *)(iVar5 + 0x14) == (float)local_18)
              ) && (cVar4 = FUN_006b97f0(&local_14), cVar4 != '\0')))))) {
          FUN_005e3520(*(undefined4 *)(iVar5 + 0xdc));
        }
        uVar14 = uVar14 + 1;
      } while ((int)uVar14 < 0x2000);
      local_8 = CONCAT31(local_8._1_3_,0xe);
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    if (in_stack_00000004[2] == DAT_007723ec) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar5 = in_stack_00000004[1] + -1;
          in_stack_00000004[1] = iVar5;
          UNLOCK();
          if (iVar5 == 0) {
            (**(code **)*in_stack_00000004)(1);
          }
        }
        uVar10 = 0;
        goto LAB_0051d53c;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar5 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar10 = 1;
          goto LAB_0051d53c;
        }
      }
    }
  }
  uVar10 = 1;
LAB_0051d53c:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar12 = in_stack_00000004 + 1;
    iVar5 = *piVar12;
    *piVar12 = *piVar12 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar10;
}

