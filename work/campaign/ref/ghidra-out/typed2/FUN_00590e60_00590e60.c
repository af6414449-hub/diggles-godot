
undefined4 FUN_00590e60(float param_1,float param_2,float param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  uint extraout_EDX;
  float *pfVar7;
  code *pcVar8;
  bool bVar9;
  float fVar10;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  float local_20;
  float local_1c;
  int local_18;
  float *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706805;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((((param_1 < PTR_0077241c->x0f + 2.0) || (PTR_0077241c->x1f - 2.0 <= param_1)) ||
      (param_2 < PTR_0077241c->y0f + 2.0)) ||
     (((PTR_0077241c->y1f - 2.0 <= param_2 || (param_2 < (float)DAT_007683d8)) ||
      ((iVar4 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar4 + 0x18) & 3) == 3 &&
       (cVar2 = FUN_004753f0(&param_1), cVar2 != '\0')))))) {
    ExceptionList = local_10;
    return 0;
  }
  param_3 = 0.0;
  pfVar5 = (float *)FUN_00592d70(uVar3);
  local_14 = pfVar5;
  FUN_0040ba00();
  local_8 = 0;
  fVar10 = ROUND(param_1);
  local_1c = param_2;
  DAT_00772dd8 = (int)ROUND(param_2);
  FUN_0040ba00();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_40 = (float)(((int)fVar10 & 0xfffffff8U) - 8);
  local_34 = (extraout_EDX & 0xfffffff8) + 0x10;
  local_3c = (extraout_EDX & 0xfffffff8) - 8;
  local_38 = ((int)fVar10 & 0xfffffff8U) + 0x10;
  FUN_0047e7b0(&local_40,0);
  local_18 = local_3c;
  iVar4 = local_38;
  pcVar8 = RaiseException_exref;
  if (local_3c < local_34) {
    do {
      local_1c = local_40;
      if ((int)local_40 < iVar4) {
        do {
          FUN_005645f0(&local_30,local_1c,local_18);
          uVar3 = 0;
          if (0 < (int)local_2c) {
            bVar9 = local_2c != 0;
            do {
              if (!bVar9) {
                (*pcVar8)(0xc000008c,1,0,0);
              }
              uVar1 = *(uint *)(local_30 + uVar3 * 4);
              if (uVar1 < 0x800) {
                pfVar6 = local_14 + uVar1 * 9;
                pfVar5 = pfVar6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pfVar6 = local_14 + uVar1 * 9;
                pfVar5 = local_14;
              }
              local_20 = pfVar5[6];
              if (0.0 < local_20) {
                if (0x7ff < uVar1) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pfVar6 = local_14;
                }
                if ((pfVar6[1] - param_2) * (pfVar6[1] - param_2) +
                    (*pfVar6 - param_1) * (*pfVar6 - param_1) < local_20 * local_20) {
                  if (local_2c <= uVar3) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  FUN_0040b930(1);
                  *(undefined4 *)(local_28 + -4 + local_24 * 4) =
                       *(undefined4 *)(local_30 + uVar3 * 4);
                }
              }
              uVar3 = uVar3 + 1;
              bVar9 = uVar3 < local_2c;
              pcVar8 = RaiseException_exref;
            } while ((int)uVar3 < (int)local_2c);
          }
          local_1c = (float)((int)local_1c + 8);
          iVar4 = local_38;
        } while ((int)local_1c < local_38);
      }
      local_18 = local_18 + 8;
      pfVar5 = local_14;
    } while (local_18 < local_34);
  }
  uVar3 = 0;
  if (0 < (int)local_24) {
    bVar9 = local_24 != 0;
    do {
      if (!bVar9) {
        (*pcVar8)(0xc000008c,1,0,0);
      }
      local_1c = *(float *)(local_28 + uVar3 * 4);
      local_20 = (float)((int)local_1c * 0x24);
      if ((uint)local_1c < 0x800) {
        pfVar6 = pfVar5 + (int)local_1c * 9;
        pfVar7 = pfVar6;
      }
      else {
        (*pcVar8)(0xc000008c,1,0,0);
        pfVar6 = (float *)((int)local_20 + (int)pfVar5);
        pfVar7 = pfVar5;
      }
      local_20 = pfVar7[6];
      if (0.0 < local_20) {
        if (0x7ff < (uint)local_1c) {
          (*pcVar8)(0xc000008c,1,0,0);
          pfVar6 = pfVar5;
        }
        fVar10 = (*pfVar6 - param_1) * (*pfVar6 - param_1) +
                 (pfVar6[1] - param_2) * (pfVar6[1] - param_2) + (0.0 - param_3) * (0.0 - param_3);
        FUN_0040b7e0();
        if (fVar10 < local_20 + 4.0) {
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_0040b980(0);
          if (local_28 != 0) {
            FUN_006ba940();
          }
          local_8 = 3;
          FUN_0040b980(0);
          if (local_30 == 0) {
            ExceptionList = local_10;
            return 0;
          }
          FUN_006ba940();
          ExceptionList = local_10;
          return 0;
        }
      }
      uVar3 = uVar3 + 1;
      bVar9 = uVar3 < local_24;
    } while ((int)uVar3 < (int)local_24);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_0040b980(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  local_8 = 5;
  FUN_0040b980(0);
  if (local_30 != 0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return 1;
}

