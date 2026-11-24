
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473590(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int in_ECX;
  uint uVar11;
  int iVar12;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar13;
  code *pcVar14;
  int *piVar15;
  char *pcVar16;
  bool bVar17;
  float fVar18;
  int *piVar19;
  float fVar20;
  float fVar21;
  int *piVar22;
  int *piVar23;
  float fVar24;
  int iVar25;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  int local_48 [2];
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_006fd90d;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_00c3c988 = _DAT_00c3c988 + 1;
  local_34 = DAT_0077244c;
  local_48[0] = 0;
  local_48[1] = 0;
  local_8 = 0;
  fVar20 = *(float *)(in_ECX + 0x19c3c);
  fVar21 = *(float *)(in_ECX + 0x19c54);
  fVar24 = fVar20;
  if (fVar20 <= *(float *)(in_ECX + 0x19c48)) {
    fVar24 = *(float *)(in_ECX + 0x19c48);
  }
  fVar18 = fVar21;
  if (fVar21 <= *(float *)(in_ECX + 0x19c60)) {
    fVar18 = *(float *)(in_ECX + 0x19c60);
  }
  local_38 = DAT_00772400;
  if (fVar24 <= fVar18) {
    fVar24 = fVar18;
  }
  piVar15 = *(int **)(in_ECX + 0x19c38);
  piVar1 = *(int **)(in_ECX + 0x19c44);
  piVar23 = piVar1;
  if ((float)piVar1 < (float)piVar15) {
    piVar23 = piVar15;
  }
  piVar2 = *(int **)(in_ECX + 0x19c50);
  piVar19 = *(int **)(in_ECX + 0x19c5c);
  local_1c = piVar19;
  if ((float)piVar19 < (float)piVar2) {
    local_1c = piVar2;
  }
  if ((float)piVar23 <= (float)local_1c) {
    piVar23 = piVar19;
    if ((float)piVar19 < (float)piVar2) {
      piVar23 = piVar2;
    }
  }
  else {
    piVar23 = piVar1;
    if ((float)piVar1 < (float)piVar15) {
      piVar23 = piVar15;
    }
  }
  if (*(float *)(in_ECX + 0x19c48) <= fVar20) {
    fVar20 = *(float *)(in_ECX + 0x19c48);
  }
  if (*(float *)(in_ECX + 0x19c60) <= fVar21) {
    fVar21 = *(float *)(in_ECX + 0x19c60);
  }
  if (fVar21 <= fVar20) {
    fVar20 = fVar21;
  }
  local_1c = piVar1;
  if ((float)piVar15 < (float)piVar1) {
    local_1c = piVar15;
  }
  piVar22 = piVar19;
  if ((float)piVar2 < (float)piVar19) {
    piVar22 = piVar2;
  }
  if ((float)piVar22 <= (float)local_1c) {
    if ((float)piVar2 < (float)piVar19) {
      piVar19 = piVar2;
    }
  }
  else {
    piVar19 = piVar15;
    if ((float)piVar1 <= (float)piVar15) {
      piVar19 = piVar1;
    }
  }
  local_78 = (int)fVar20 - 8U & 0xfffffff8;
  local_70 = (int)fVar24 + 0xfU & 0xfffffff8;
  local_7c = (int)(float)piVar19 - 8U & 0xfffffff8;
  local_74 = (int)(float)piVar23 + 0xfU & 0xfffffff8;
  local_24 = in_ECX;
  FUN_0047e7b0(&local_7c,8);
  local_18 = local_78 + 7 & 0xfffffff8;
  uVar13 = local_70 & 0xfffffff8;
  uVar11 = local_7c + 7 & 0xfffffff8;
  uVar6 = local_74 & 0xfffffff8;
  pcVar14 = RaiseException_exref;
  local_3c = uVar11;
  local_2c = uVar13;
  local_28 = uVar6;
  if ((int)local_18 < (int)uVar13) {
    do {
      if ((int)uVar11 < (int)uVar6) {
        local_14 = uVar11 - local_18;
        do {
          uVar6 = *(uint *)(DAT_00772400 + 100);
          iVar7 = FUN_00592f10(PTR_0077241c);
          pcVar16 = (char *)(iVar7 + 0x34);
          if (uVar6 < 8) {
            pcVar16 = pcVar16 + uVar6;
          }
          else {
            (*pcVar14)(0xc000008c,1,0,0,uVar5);
          }
          if (*pcVar16 == '\0') {
            local_20 = 0;
            local_30 = local_18 - 2;
            local_1c = (int *)(local_18 + 8);
            do {
              iVar7 = FUN_00592f10(PTR_0077241c);
              pcVar16 = (char *)(iVar7 + 0x34);
              if (uVar6 < 8) {
                pcVar16 = pcVar16 + uVar6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              pcVar14 = RaiseException_exref;
              if (*pcVar16 != '\0') goto LAB_004738c6;
              iVar7 = FUN_00592f10(PTR_0077241c);
              pcVar16 = (char *)(iVar7 + 0x34);
              if (uVar6 < 8) {
                pcVar16 = pcVar16 + uVar6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              pcVar14 = RaiseException_exref;
              if (*pcVar16 != '\0') goto LAB_004738c6;
              iVar7 = FUN_00592f10(PTR_0077241c);
              pcVar16 = (char *)(iVar7 + 0x34);
              if (uVar6 < 8) {
                pcVar16 = pcVar16 + uVar6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              pcVar14 = RaiseException_exref;
              if (*pcVar16 != '\0') goto LAB_004738c6;
              iVar7 = FUN_00592f10(PTR_0077241c);
              pcVar16 = (char *)(iVar7 + 0x34);
              if (uVar6 < 8) {
                pcVar16 = pcVar16 + uVar6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              pcVar14 = RaiseException_exref;
              if (*pcVar16 != '\0') goto LAB_004738c6;
              local_1c = (int *)((int)local_1c + -2);
              local_20 = local_20 + 2;
            } while ((int)local_20 < 8);
          }
          else {
LAB_004738c6:
            local_30 = FUN_00564090(*(int *)(local_34 + 0x849c) *
                                    ((int)(local_18 + ((int)local_18 >> 0x1f & 7U)) >> 3) +
                                    ((int)(((int)(local_14 + local_18) >> 0x1f & 7U) +
                                          local_14 + local_18) >> 3));
            local_20 = 0;
            if (0 < *(int *)(local_30 + 0x1c)) {
              iVar7 = 0;
              local_1c = (int *)(local_38 + 0x5c8);
              bVar17 = *(int *)(local_30 + 0x1c) != 0;
              do {
                iVar25 = local_30;
                if (!bVar17) {
                  (*pcVar14)(0xc000008c,1,0,0);
                }
                iVar25 = *(int *)(iVar25 + 0x18);
                uVar6 = *(uint *)(iVar7 + 0x18 + iVar25);
                if (uVar6 < 0x100) {
                  piVar15 = local_1c + uVar6;
                }
                else {
                  (*pcVar14)(0xc000008c,1,0,0);
                  piVar15 = local_1c;
                }
                iVar8 = *(int *)(iVar7 + 0x1c + iVar25);
                iVar3 = *piVar15;
                if ((iVar8 < 0) || (*(int *)(iVar3 + 0x38) <= iVar8)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar12 = *(int *)(iVar3 + 0x34);
                  iVar8 = *(int *)(iVar7 + 0x1c + iVar25);
                  iVar9 = iVar12;
                }
                else {
                  iVar12 = iVar8 * 0xe8 + *(int *)(iVar3 + 0x34);
                  iVar9 = *(int *)(iVar3 + 0x34);
                }
                local_60 = *(undefined4 *)(iVar12 + 0x50);
                local_5c = *(undefined4 *)(iVar12 + 0x54);
                local_58 = *(undefined4 *)(iVar12 + 0x58);
                if ((iVar8 < 0) || (*(int *)(iVar3 + 0x38) <= iVar8)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar9 = *(int *)(iVar3 + 0x34);
                }
                else {
                  iVar9 = iVar8 * 0xe8 + iVar9;
                }
                local_6c = *(undefined4 *)(iVar9 + 0x44);
                local_68 = *(undefined4 *)(iVar9 + 0x48);
                local_64 = *(undefined4 *)(iVar9 + 0x4c);
                iVar8 = iVar7 + iVar25;
                local_54 = *(undefined4 *)(iVar7 + iVar25);
                local_50 = *(undefined4 *)(iVar7 + 4 + iVar25);
                local_4c = *(float *)(iVar7 + 8 + iVar25);
                local_78 = *(uint *)(iVar8 + 0xc);
                local_74 = *(uint *)(iVar8 + 0x10);
                local_70 = *(uint *)(iVar8 + 0x14);
                if ((*(char *)(iVar7 + 0x31 + iVar25) != '\0') &&
                   (cVar4 = FUN_00472e80(&local_54,&local_78,&local_6c,&local_60), cVar4 != '\0')) {
                  piVar15 = *(int **)(iVar7 + 0x20 + iVar25);
                  if (piVar15 == (int *)0x0) {
LAB_00473aab:
                    uVar6 = *(uint *)(iVar7 + 0x18 + iVar25);
                    piVar15 = (int *)(DAT_0076a324 + 0x2934);
                    if (uVar6 < 0x100) {
                      piVar15 = piVar15 + uVar6;
                    }
                    else {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    if (*piVar15 != 0) {
                      local_40 = (undefined4 *)FUN_006ba810(0x1265);
                      if (local_40 == (undefined4 *)0x0) {
                        puVar10 = (undefined4 *)0x0;
                      }
                      else {
                        *local_40 = 0;
                        local_40[1] = 0;
                        *(undefined1 *)(local_40 + 2) = 0;
                        puVar10 = local_40;
                      }
                      *(undefined4 **)(iVar7 + 0x20 + iVar25) = puVar10;
                      local_4c = local_4c * 0.5 + 7.0;
                      cVar4 = FUN_00486790(*(undefined4 *)(iVar7 + 0x20 + iVar25),
                                           *(undefined4 *)(iVar7 + 0x1c + iVar25),
                                           *(undefined4 *)(iVar7 + 0x24 + iVar25),&local_54,
                                           iVar25 + 0xc + iVar7,0,0,0,0xff,0xff,local_48,0,0,
                                           0xffffffff,0);
                      if (cVar4 == '\0') {
                        piVar15 = *(int **)(iVar7 + 0x20 + iVar25);
                        if (piVar15 != (int *)0x0) {
                          local_8 = CONCAT31(local_8._1_3_,6);
                          FUN_00453f00(extraout_ECX_00);
                          if (*piVar15 != 0) {
                            FUN_006ba940();
                          }
                          local_8 = local_8 & 0xffffff00;
                          FUN_006cecd8(piVar15,9);
                        }
                        *(undefined4 *)(iVar7 + 0x20 + iVar25) = 0;
                      }
                    }
                  }
                  else if (((char)piVar15[2] != '\0') && (*(char *)(local_24 + 0x19f18) != '\0')) {
                    local_8 = CONCAT31(local_8._1_3_,5);
                    FUN_00453f00(extraout_ECX);
                    if (*piVar15 != 0) {
                      FUN_006ba940();
                    }
                    local_8 = local_8 & 0xffffff00;
                    FUN_006cecd8(piVar15,9);
                    *(undefined4 *)(iVar7 + 0x20 + iVar25) = 0;
                    goto LAB_00473aab;
                  }
                  iVar25 = *(int *)(iVar7 + 0x20 + iVar25);
                  if (iVar25 != 0) {
                    FUN_0044d010(iVar25);
                    FUN_0044d760(iVar25);
                  }
                }
                iVar7 = iVar7 + 0x34;
                local_20 = local_20 + 1;
                bVar17 = local_20 < *(uint *)(local_30 + 0x1c);
                pcVar14 = RaiseException_exref;
              } while ((int)local_20 < (int)*(uint *)(local_30 + 0x1c));
            }
          }
          local_14 = local_14 + 8;
          uVar6 = local_28;
          uVar11 = local_3c;
          pcVar14 = RaiseException_exref;
          uVar13 = local_2c;
        } while ((int)(local_14 + local_18) < (int)local_28);
      }
      local_18 = local_18 + 8;
    } while ((int)local_18 < (int)uVar13);
  }
  local_8 = 7;
  FUN_0047e280(0);
  if (local_48[0] != 0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

