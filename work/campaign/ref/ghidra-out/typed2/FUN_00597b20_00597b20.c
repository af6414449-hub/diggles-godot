
undefined4 * FUN_00597b20(undefined4 *param_1,float *param_2,int param_3,int param_4,char param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  float fVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  float fVar13;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 *local_58;
  int local_54;
  undefined4 *local_50;
  float *local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  CMap *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00706ad5;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_18 = PTR_0077241c;
  if (param_4 != 0) {
    local_54 = 0;
    local_50 = (undefined4 *)0x0;
    local_24 = *(undefined4 **)(param_3 + 0x36c);
    iVar4 = (int)param_2[1] + 0xf;
    iVar5 = (int)param_2[1] + -0x11;
    iVar7 = (int)*param_2 + -0x10;
    iVar9 = (int)*param_2 + 0x10;
    local_3c = PTR_0077241c->cellX0 + 2;
    if (local_3c <= iVar7) {
      local_3c = iVar7;
    }
    local_14 = PTR_0077241c->cellY0 + 2;
    if (local_14 <= iVar5) {
      local_14 = iVar5;
    }
    local_34 = PTR_0077241c->cellX1 + -2;
    if (iVar9 <= local_34) {
      local_34 = iVar9;
    }
    local_38 = PTR_0077241c->cellY1 + -2;
    if (iVar4 <= local_38) {
      local_38 = iVar4;
    }
    local_8 = 0;
    ExceptionList = &local_10;
    FUN_0042f870(param_4);
    puVar12 = local_50;
    pcVar6 = RaiseException_exref;
    local_2c = (undefined4 *)0x0;
    local_20 = local_50;
    if (0 < param_4) {
      local_28 = (undefined4 *)(local_54 + 8);
      do {
        if (puVar12 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_2c = (undefined4 *)((int)local_2c + 1);
        local_28[-2] = 0xbf800000;
        local_28[-1] = 0xbf800000;
        *local_28 = 0xbf800000;
        local_28 = local_28 + 3;
      } while ((int)local_2c < param_4);
    }
    FUN_0040ba00(uVar3);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0040b980(param_4);
    puVar11 = local_58;
    local_2c = (undefined4 *)0x0;
    local_1c = local_58;
    iVar4 = local_5c;
    if (0 < param_4) {
      do {
        if (puVar11 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = local_5c;
        }
        *(undefined4 *)(iVar4 + (int)local_2c * 4) = 0x4b189680;
        local_2c = (undefined4 *)((int)local_2c + 1);
      } while ((int)local_2c < param_4);
    }
    local_30 = *(uint *)(param_3 + 0x250);
    local_44 = (int)local_24 * 4;
    local_40 = 0xb << ((byte)local_44 & 0x1f);
    iVar4 = local_34;
    iVar5 = local_38;
    if (local_14 < local_38) {
      do {
        iVar7 = local_3c;
        iVar9 = local_14;
        if (local_3c < iVar4) {
          do {
            iVar4 = FUN_00592f10(local_18);
            if (((((*(uint *)(iVar4 + 8) & local_40) != 0) &&
                 (iVar4 = FUN_00592f10(local_18), (*(byte *)(iVar4 + 0x18) & 3) != 0)) &&
                (iVar4 = FUN_00592f10(local_18), (*(byte *)(iVar4 + 0x18) & 3) != 3)) &&
               (local_64 = iVar7, local_60 = iVar9, iVar4 = FUN_005968b0(&local_64), iVar4 != -1)) {
              iVar4 = FUN_00592f10(local_18);
              uVar3 = *(uint *)(iVar4 + 0xc) >> ((byte)local_44 & 0x1f) & 0xf;
              if ((param_5 == '\0') || (iVar9 = local_14, uVar3 == local_30)) {
                local_68 = local_14;
                local_6c = iVar7;
                iVar4 = FUN_005968b0(&local_6c);
                fVar13 = (float)local_14 - (param_2[1] - 0.75);
                fVar10 = (float)(iVar4 + 4) - (param_2[2] + 6.0);
                puVar12 = (undefined4 *)
                          (((float)iVar7 - *param_2) * ((float)iVar7 - *param_2) + fVar13 * fVar13 +
                          fVar10 * fVar10 * 0.25);
                FUN_0040b7e0();
                local_2c = puVar12;
                if (local_30 != uVar3) {
                  local_2c = (undefined4 *)((float)puVar12 + 8.0);
                }
                local_24 = (undefined4 *)(param_4 + -1);
                if (local_1c <= local_24) {
                  (*pcVar6)(0xc000008c,1,0,0);
                }
                local_48 = local_5c + param_4 * 4;
                local_4c = (float *)(local_48 + -4);
                iVar9 = local_14;
                if ((float)local_2c < *local_4c) {
                  puVar8 = (undefined4 *)0x0;
                  puVar12 = local_1c;
                  iVar5 = local_5c;
                  puVar11 = local_2c;
                  if (0 < param_4) {
                    do {
                      if (puVar12 <= puVar8) {
                        (*pcVar6)(0xc000008c,1,0,0);
                        puVar12 = local_1c;
                        iVar5 = local_5c;
                        puVar11 = local_2c;
                      }
                    } while ((*(float *)(iVar5 + (int)puVar8 * 4) <= (float)puVar11) &&
                            (puVar8 = (undefined4 *)((int)puVar8 + 1), (int)puVar8 < param_4));
                  }
                  if (puVar12 <= local_24) {
                    (*pcVar6)(0xc000008c,1,0,0);
                    (*pcVar6)(0xc000008c,1,0,0);
                    puVar12 = local_1c;
                  }
                  puVar11 = (undefined4 *)((int)puVar12 + -1);
                  local_28 = puVar11;
                  if ((int)local_24 < (int)puVar11) {
                    FUN_006d1b90(local_4c,local_48,((int)puVar12 - param_4) * 4);
                  }
                  local_58 = puVar11;
                  if (local_20 <= local_24) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  puVar11 = local_20;
                  puVar12 = (undefined4 *)((int)local_20 + -1);
                  if ((int)local_24 < (int)puVar12) {
                    iVar5 = local_54 + param_4 * 0xc;
                    FUN_006d1b90(iVar5 + -0xc,iVar5,((int)local_20 - param_4) * 0xc);
                  }
                  local_50 = puVar12;
                  if (local_28 < puVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_1c = (undefined4 *)((int)local_28 + 1);
                  if (((uint)(local_28 + 4) & 0xfffffff0) != ((int)local_28 + 0xfU & 0xfffffff0)) {
                    local_5c = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                            ,0x9b);
                  }
                  if ((int)puVar8 < (int)local_28) {
                    iVar5 = local_5c + (int)puVar8 * 4;
                    FUN_006d1b90(iVar5 + 4,iVar5,((int)local_28 - (int)puVar8) * 4);
                  }
                  local_58 = local_1c;
                  if (local_1c <= puVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(undefined4 **)(local_5c + (int)puVar8 * 4) = local_2c;
                  if (puVar12 < puVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_20 = puVar11;
                  if (((int)puVar11 + 0xfU & 0xfffffff0) != ((int)puVar11 + 0xeU & 0xfffffff0)) {
                    local_54 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                            ,0x9b);
                  }
                  if ((int)puVar8 < (int)puVar12) {
                    iVar5 = local_54 + (int)puVar8 * 0xc;
                    FUN_006d1b90(iVar5 + 0xc,iVar5,((int)puVar12 - (int)puVar8) * 0xc);
                  }
                  puVar12 = local_20;
                  local_50 = local_20;
                  FUN_0042fc90(puVar8);
                  pcVar6 = RaiseException_exref;
                  if (puVar12 <= puVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(float *)(local_54 + (int)puVar8 * 0xc) = (float)iVar7;
                  *(float *)(local_54 + 4 + (int)puVar8 * 0xc) = (float)local_14;
                  *(float *)(local_54 + 8 + (int)puVar8 * 0xc) = (float)(iVar4 + 4);
                  iVar9 = local_14;
                }
              }
            }
            iVar7 = iVar7 + 1;
            iVar4 = local_34;
            iVar5 = local_38;
          } while (iVar7 < local_34);
        }
        local_14 = iVar9 + 1;
        puVar12 = local_20;
      } while (local_14 < iVar5);
    }
    puVar11 = (undefined4 *)(param_4 + -1);
    if (puVar12 <= puVar11) {
      (*pcVar6)(0xc000008c,1,0,0);
    }
    uVar1 = *(undefined4 *)(local_54 + (int)puVar11 * 0xc);
    uVar2 = *(undefined4 *)(local_54 + 4 + (int)puVar11 * 0xc);
    _param_5 = *(float *)(local_54 + 8 + (int)puVar11 * 0xc) + 2.0;
    fVar10 = 1.0;
    if ((_param_5 <= 1.0) || (fVar10 = 14.0, 14.0 <= _param_5)) {
      _param_5 = fVar10;
    }
    if (puVar12 <= puVar11) {
      (*pcVar6)(0xc000008c,1,0,0);
      (*pcVar6)(0xc000008c,1,0,0);
    }
    *param_1 = uVar1;
    param_1[1] = uVar2;
    param_1[2] = _param_5;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0040b980(0);
    if (local_5c != 0) {
      FUN_006ba940();
    }
    local_8 = 3;
    FUN_0042f870(0);
    if (local_54 != 0) {
      FUN_006ba940();
    }
    ExceptionList = local_10;
    return param_1;
  }
  *param_1 = 0xbf800000;
  param_1[1] = 0xbf800000;
  param_1[2] = 0xbf800000;
  return param_1;
}

