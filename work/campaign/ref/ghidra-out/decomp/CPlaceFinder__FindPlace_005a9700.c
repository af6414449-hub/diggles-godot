
float * CPlaceFinder__FindPlace(float *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined8 uVar13;
  undefined4 in_stack_ffffff68;
  undefined4 in_stack_ffffff6c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 *local_60;
  float local_5c;
  int local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  uint local_40;
  int local_3c;
  int local_38;
  float local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  float local_1c;
  uint local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706e38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5550) &&
     (FUN_006cebf4(&DAT_00ca5550,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca5550 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca5554 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "CPlaceFinder::FindPlace()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5550);
  }
  iVar6 = DAT_00ca5554;
  local_60 = &DAT_00ca5554;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca5554 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar13 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar13;
  }
  piVar8 = local_20;
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  if (0.0 < (float)local_20[2]) {
    if ((char)local_20[5] == '\0') {
      bVar9 = 0.0 < (float)local_20[10];
    }
    else {
      if ((float)local_20[9] <= (float)local_20[7]) goto LAB_005a97c7;
      bVar9 = (float)local_20[6] < (float)local_20[8];
    }
    if (bVar9) {
      local_2c = 0;
      if (0 < local_20[1]) {
        bVar9 = local_20[1] != 0;
        local_28 = 0;
        do {
          if (!bVar9) {
            in_stack_ffffff6c = 0xc000008c;
            in_stack_ffffff68 = 0x5a9836;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(local_28 + *piVar8) = (float)piVar8[2] + *(float *)(local_28 + *piVar8);
          if ((uint)piVar8[1] <= local_2c) {
            in_stack_ffffff6c = 0xc000008c;
            in_stack_ffffff68 = 0x5a985f;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(local_28 + 4 + *piVar8) = *(float *)(local_28 + 4 + *piVar8) + (float)piVar8[2]
          ;
          if ((uint)piVar8[1] <= local_2c) {
            in_stack_ffffff6c = 0xc000008c;
            in_stack_ffffff68 = 0x5a988a;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(local_28 + 8 + *piVar8) = *(float *)(local_28 + 8 + *piVar8) + (float)piVar8[4]
          ;
          if ((uint)piVar8[1] <= local_2c) {
            in_stack_ffffff6c = 0xc000008c;
            in_stack_ffffff68 = 0x5a98b5;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(local_28 + 0xc + *piVar8) =
               *(float *)(local_28 + 0xc + *piVar8) + (float)piVar8[4];
          local_28 = local_28 + 0x10;
          local_2c = local_2c + 1;
          bVar9 = local_2c < (uint)piVar8[1];
        } while ((int)local_2c < piVar8[1]);
      }
      if ((((float)piVar8[0x10] == 0.0) && ((float)piVar8[0x11] == 0.0)) &&
         ((float)piVar8[0x12] == 0.0)) {
        piVar8[0x10] = piVar8[2];
        piVar8[0x11] = piVar8[3];
        piVar8[0x12] = piVar8[4];
      }
      piVar8[0x11] = piVar8[3];
      local_5c = (float)FUN_006ba810(0x151);
      local_8._0_1_ = 1;
      if (local_5c == 0.0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)FUN_0041bb10();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if ((char)piVar8[5] == '\0') {
        local_24 = (int)ROUND(((float)piVar8[4] - ((float)piVar8[10] + (float)piVar8[10])) * 8.0) /
                   2;
        local_2c = (int)ROUND(((float)piVar8[10] + (float)piVar8[10] + (float)piVar8[4]) * 8.0) / 2;
        local_54 = (float)local_20[2] * 8.0;
        DAT_00772dd8 = (int)ROUND(local_54);
        FUN_0041f7a0(DAT_00772dd8,(int)ROUND((float)local_20[3] * 8.0),in_stack_ffffff68,
                     in_stack_ffffff6c,(int)ROUND((float)local_20[10] * 8.0),
                     (int)ROUND((float)piVar8[10] * 8.0),(int)ROUND((float)local_20[10] * 8.0));
        local_1c = (float)local_20[10];
        piVar8 = local_20;
      }
      else {
        local_24 = (int)ROUND(((float)piVar8[7] + (float)piVar8[4]) * 8.0) / 2;
        local_2c = (int)ROUND(((float)piVar8[9] + (float)piVar8[4]) * 8.0) / 2;
        local_54 = (float)local_20[2] * 8.0;
        DAT_00772dd8 = (int)ROUND(local_54);
        FUN_0041f7a0(DAT_00772dd8,(int)ROUND((float)local_20[3] * 8.0),in_stack_ffffff68,
                     in_stack_ffffff6c,(int)ROUND(-(float)local_20[6] * 8.0),
                     (int)ROUND((float)piVar8[8] * 8.0),(int)ROUND(-(float)local_20[6] * 8.0));
        local_44 = (float)local_20[8] * (float)local_20[8];
        local_54 = (float)local_20[7] * (float)local_20[7] * 0.25;
        local_50 = (float)local_20[6] * (float)local_20[6];
        fVar10 = local_50 + local_54;
        local_48 = (float)local_20[9] * (float)local_20[9] * 0.25;
        FUN_0040b7e0();
        fVar11 = local_44 + local_54;
        local_1c = fVar10;
        FUN_0040b7e0();
        local_1c = local_1c + fVar11;
        fVar10 = local_48 + local_50;
        FUN_0040b7e0();
        local_1c = local_1c + fVar10;
        fVar10 = local_48 + local_44;
        FUN_0040b7e0();
        local_1c = (local_1c + fVar10) * 0.25;
        piVar8 = local_20;
      }
      if ((((float)piVar8[0x10] != (float)piVar8[2]) || ((float)piVar8[0x11] != (float)piVar8[3]))
         || ((float)piVar8[0x12] != (float)piVar8[4])) {
        local_4c = (float)piVar8[0x10] - (float)piVar8[2];
        local_50 = (float)piVar8[0x11] - (float)piVar8[3];
        local_54 = ((float)piVar8[0x12] - (float)piVar8[4]) * 0.5;
        fVar10 = local_50 * local_50 + local_4c * local_4c + local_54 * local_54;
        FUN_0040b7e0();
        fVar11 = 0.0;
        if (fVar10 <= 0.0) {
          local_54 = 0.0;
          fVar12 = 0.0;
        }
        else {
          local_54 = local_54 / fVar10;
          fVar12 = local_50 / fVar10;
          fVar11 = local_4c / fVar10;
        }
        piVar8[0x10] = (int)(fVar11 * local_1c + (float)piVar8[2]);
        piVar8[0x11] = (int)(fVar12 * local_1c + (float)piVar8[3]);
        piVar8[0x12] = (int)(local_54 * local_1c + local_54 * local_1c + (float)piVar8[4]);
      }
      if ((int)ROUND((float)piVar8[0xd] * 8.0) / 2 < 1) {
        local_30 = 0;
      }
      else {
        local_30 = (int)ROUND((float)piVar8[0xd] * 8.0) / 2;
      }
      local_54 = (float)piVar8[0xe] * 8.0;
      DAT_00772dd8 = (int)ROUND(local_54);
      if (DAT_00772dd8 / 2 < 1) {
        local_38 = 0;
      }
      else {
        local_54 = (float)piVar8[0xe] * 8.0;
        DAT_00772dd8 = (int)ROUND(local_54);
        local_38 = DAT_00772dd8 / 2;
      }
      FUN_0041c4b0();
      FUN_0041cac0(piVar8[0xf],0,(char)piVar8[0x14]);
      if ((int)local_24 < 0) {
        local_24 = 0;
      }
      local_6c = -1.0;
      uVar7 = 0x40;
      local_68 = -1.0;
      if (0x40 < (int)local_2c) {
        local_2c = 0x40;
      }
      local_64 = -1.0;
      local_34 = 3.4028235e+38;
      if (*(char *)((int)piVar8 + 0x59) == '\0') {
        local_1c = 0.0;
        if (0 < piVar3[3]) {
          local_48 = (float)-local_30;
          local_40 = 0;
          local_3c = 0;
          local_5c = 0.125;
          do {
            local_18 = local_24;
            fVar10 = local_1c;
            if ((int)local_24 < (int)local_2c) {
              local_44 = (float)(local_24 * 2);
              local_28 = local_24 - local_30;
              local_58 = local_30 + local_38;
              do {
                if (((-1 < local_3c) && ((int)fVar10 < piVar3[3])) && (local_30 + local_28 < 0x40))
                {
                  local_4c = (float)(local_18 + local_3c);
                  if (((int)local_4c < 0) || (piVar3[1] <= (int)local_4c)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar4 = (uint *)*piVar3;
                  }
                  else {
                    puVar4 = (uint *)(*piVar3 + (int)local_4c * 4);
                  }
                  fVar10 = local_1c;
                  if ((((*puVar4 & 0xff000000) == 0) &&
                      ((local_30 == 0 ||
                       ((((-1 < (int)local_28 && ((int)local_1c < piVar3[3])) && (local_28 < 0x40))
                        && (puVar4 = (uint *)FUN_00405920(local_18 + (int)local_48),
                           fVar10 = local_1c, (*puVar4 & 0x10000000) == 0)))))) &&
                     ((local_38 == 0 ||
                      (((fVar10 = local_1c, (int)(local_58 + local_28) < 0x40 &&
                        ((int)local_1c < piVar3[3])) &&
                       ((local_58 + local_28 < 0x40 &&
                        (puVar4 = (uint *)FUN_00405920((int)local_4c + local_38), fVar10 = local_1c,
                        (*puVar4 & 0x8000000) == 0)))))))) {
                    if (((int)local_1c < piVar3[3]) && (local_18 < 0x40)) {
                      fVar10 = (float)piVar3[3];
                      if ((uint)fVar10 <= (uint)local_1c) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        fVar10 = (float)piVar3[3];
                      }
                      iVar2 = piVar3[2];
                      local_50 = (float)(local_40 + iVar2);
                      if ((uint)fVar10 <= (uint)local_1c) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        iVar2 = piVar3[2];
                      }
                      local_74 = *(float *)((int)local_50 + 4);
                      fVar11 = (float)(int)local_44 * local_5c;
                      local_78 = *(float *)(iVar2 + local_40);
                    }
                    else {
                      local_78 = -1.0;
                      fVar11 = -1.0;
                      local_74 = -1.0;
                    }
                    local_70 = fVar11;
                    local_54 = fVar11;
                    local_50 = local_74;
                    local_4c = local_78;
                    FUN_005a9270(&local_78);
                    fVar10 = local_1c;
                    if (fVar11 < local_34) {
                      local_6c = local_4c;
                      local_68 = local_50;
                      local_64 = local_54;
                      local_34 = fVar11;
                    }
                  }
                }
                local_44 = (float)((int)local_44 + 4);
                local_18 = local_18 + 2;
                local_28 = local_28 + 2;
              } while ((int)local_18 < (int)local_2c);
            }
            local_48 = (float)((int)local_48 + 0x40);
            local_1c = (float)((int)fVar10 + 1);
            local_3c = local_3c + 0x40;
            uVar7 = local_40 + 0xc;
            local_40 = uVar7;
          } while ((int)local_1c < piVar3[3]);
        }
        FUN_0041a240(uVar7);
        pfVar5 = (float *)FUN_00424120();
        local_6c = *pfVar5;
        local_68 = pfVar5[1];
        local_64 = pfVar5[2];
        FUN_005aa900(&local_6c,0xffffffff,0x3f4ccccd);
        *param_1 = local_6c;
        param_1[1] = local_68;
        param_1[2] = local_64;
        goto LAB_005a97db;
      }
      local_11 = '\x01';
      local_28 = 0;
      if (0 < piVar3[3]) {
        local_38 = 0;
        local_3c = 0;
        do {
          local_40 = local_24;
          if ((int)local_24 < (int)local_2c) {
            local_30 = local_24 * 2;
            do {
              if (((local_3c < 0) || (piVar3[3] <= (int)local_28)) || (0x3f < local_40)) {
LAB_005aa242:
                local_11 = '\0';
              }
              else {
                iVar2 = local_3c + local_40;
                if ((iVar2 < 0) || (piVar3[1] <= iVar2)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar4 = (uint *)*piVar3;
                }
                else {
                  puVar4 = (uint *)(*piVar3 + iVar2 * 4);
                }
                fVar10 = -1.0;
                if ((*puVar4 & 0xff000000) != 0) goto LAB_005aa242;
                if ((int)local_28 < piVar3[3]) {
                  uVar7 = piVar3[3];
                  if (uVar7 <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    uVar7 = piVar3[3];
                  }
                  iVar2 = piVar3[2];
                  local_5c = (float)(local_38 + iVar2);
                  if (uVar7 <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar2 = piVar3[2];
                  }
                  local_74 = *(float *)((int)local_5c + 4);
                  fVar11 = (float)local_30 * 0.125;
                  fVar10 = *(float *)(iVar2 + local_38);
                }
                else {
                  fVar11 = -1.0;
                  local_74 = -1.0;
                }
                local_78 = fVar10;
                local_70 = fVar11;
                FUN_005a9270(&local_78);
                if (fVar11 == local_34) goto LAB_005aa242;
              }
              local_40 = local_40 + 2;
              local_30 = local_30 + 4;
            } while ((int)local_40 < (int)local_2c);
          }
          local_38 = local_38 + 0xc;
          local_28 = local_28 + 1;
          local_3c = local_3c + 0x40;
        } while ((int)local_28 < piVar3[3]);
      }
      FUN_0041a240(local_28);
      if (local_11 != '\0') {
        *param_1 = 0.0;
        param_1[1] = 0.0;
        param_1[2] = 0.0;
        goto LAB_005a97db;
      }
    }
  }
LAB_005a97c7:
  *param_1 = -1.0;
  param_1[1] = -1.0;
  param_1[2] = -1.0;
LAB_005a97db:
  FUN_0043fd30();
  ExceptionList = local_10;
  return param_1;
}

