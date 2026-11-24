
int FUN_004796d0(int param_1,int param_2,int param_3,undefined1 *param_4)

{
  int iVar1;
  char cVar2;
  float *pfVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 local_90 [12];
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  float local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fdb30;
  local_10 = ExceptionList;
  local_2c = DAT_0076a338;
  if (*(char *)(DAT_0076a338 + 0x2839) == '\0') {
    ExceptionList = &local_10;
    local_18 = FUN_005b78b0(DAT_0076700c ^ (uint)&stack0xfffffffc);
    local_60 = (float)param_1;
    local_58 = -100.0;
    local_30 = *(int *)(DAT_00772400 + 100);
    local_5c = (float)param_2;
    FUN_00479150(&local_84,&local_60);
    local_58 = 100.0;
    local_7c = (local_7c - 7.0) + (local_7c - 7.0);
    local_60 = (float)param_1;
    local_5c = (float)param_2;
    FUN_00479150(&local_78,&local_60);
    pcVar5 = RaiseException_exref;
    local_70 = (local_70 - 7.0) + (local_70 - 7.0);
    *param_4 = 0;
    local_58 = 0.0;
    local_1c = 0xffffffff;
    local_5c = 0.0;
    local_60 = 0.0;
    local_4c = 0.0;
    local_28 = 30.0;
    local_50 = 0.0;
    local_54 = 0.0;
    local_20 = -1;
    local_14 = 0.5;
    local_24 = -1;
    iVar4 = local_18;
    while( true ) {
      local_1c = local_1c + 1;
      local_44 = local_14;
      if ((int)*(uint *)(iVar4 + 0xc015) <= (int)local_1c) break;
      if (*(uint *)(iVar4 + 0xc015) <= local_1c) {
        (*pcVar5)(0xc000008c,1,0,0);
        iVar4 = local_18;
        pcVar5 = RaiseException_exref;
      }
      iVar1 = *(int *)(*(int *)(iVar4 + 0xc011) + local_1c * 4);
      if ((iVar1 < 0) || (*(int *)(iVar4 + 0xc00c) <= iVar1)) {
        (*pcVar5)(0xc000008c,1,0,0);
        iVar6 = *(int *)(local_18 + 0xc008);
        iVar4 = local_18;
      }
      else {
        iVar6 = iVar1 * 0xd8 + *(int *)(iVar4 + 0xc008);
      }
      if (*(int *)(iVar6 + 0x6c) == 0) {
        if (DAT_00772444 == 0) {
          local_48 = FUN_006ba810(0xa9);
          local_8 = 0;
          if (local_48 == 0) {
            DAT_00772444 = 0;
          }
          else {
            DAT_00772444 = FUN_005b79e0();
          }
          local_8 = 0xffffffff;
        }
        FUN_005b7e30(iVar1);
        iVar4 = local_18;
        pcVar5 = RaiseException_exref;
      }
      else {
        pcVar5 = RaiseException_exref;
        if ((((*(int *)(iVar6 + 0x74) == local_30) &&
             ((*(char *)(iVar6 + 0xb4) != '\0' || (*(char *)(iVar6 + 0xb5) != '\0')))) ||
            (*(char *)(DAT_00772400 + 0x590) != '\0')) && (*(char *)(iVar6 + 0xd4) != '\0')) {
          local_58 = *(float *)(iVar6 + 0xd0) * 0.01;
          local_4c = *(float *)(iVar6 + 0xc4) * 0.01;
          local_60 = *(float *)(iVar6 + 200) * 0.005;
          local_6c = (float)param_1;
          local_5c = *(float *)(iVar6 + 0xcc) * 0.005;
          local_68 = (float)param_2;
          local_64 = *(float *)(iVar6 + 0x48) * 0.5 + 7.0;
          local_54 = *(float *)(iVar6 + 0xbc) * 0.005;
          local_50 = *(float *)(iVar6 + 0xc0) * 0.005;
          local_40 = local_50;
          local_3c = local_5c;
          local_38 = local_54;
          local_34 = local_60;
          pfVar3 = (float *)FUN_00479150(local_90,&local_6c);
          fVar8 = ABS(((local_34 + local_38) * 0.5 + *(float *)(iVar6 + 0x40)) - *pfVar3);
          fVar7 = ABS(((local_3c + local_40) * 0.5 + *(float *)(iVar6 + 0x44)) - pfVar3[1]);
          fVar9 = fVar8;
          if (fVar7 <= fVar8) {
            fVar9 = fVar7;
          }
          local_40 = (fVar8 + fVar7) - fVar9 * 0.5;
          if (local_40 < local_14) {
            local_14 = local_40;
          }
          iVar6 = iVar1;
          if (local_44 <= local_40) {
            iVar6 = local_24;
          }
          iVar4 = local_18;
          pcVar5 = RaiseException_exref;
          local_24 = iVar6;
          if ((local_40 < local_28) &&
             (cVar2 = FUN_005e5920(&local_60,&local_54,&local_84,&local_78),
             pcVar5 = RaiseException_exref, iVar4 = local_18, cVar2 != '\0')) {
            if (iVar1 == param_3) {
              *param_4 = 1;
            }
            else {
              local_28 = local_40;
              local_20 = iVar1;
            }
          }
        }
      }
    }
    iVar4 = local_24;
    if (local_20 != -1) {
      iVar4 = local_20;
    }
    if (iVar4 == -1) {
      local_84 = (float)param_1;
      local_7c = 15.0;
      local_80 = (float)param_2;
      FUN_00479150(&local_78,&local_84);
      DAT_00772dd8 = (int)ROUND(local_74 + 0.5);
      if (((((int)ROUND(local_78 + 0.5) < PTR_0077241c->cellX0) ||
           (PTR_0077241c->cellX1 <= (int)ROUND(local_78 + 0.5))) ||
          (DAT_00772dd8 < PTR_0077241c->cellY0)) ||
         ((PTR_0077241c->cellY1 <= DAT_00772dd8 ||
          (iVar4 = FUN_00592f10(PTR_0077241c),
          (*(uint *)(iVar4 + 8) & 0xf << ((byte)(*(int *)(DAT_00772400 + 100) << 2) & 0x1f)) == 0)))
         ) {
        iVar4 = -1;
      }
      else {
        iVar4 = 0x7890;
      }
    }
    ExceptionList = local_10;
    return iVar4;
  }
  return -1;
}

