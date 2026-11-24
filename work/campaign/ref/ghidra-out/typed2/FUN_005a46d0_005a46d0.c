
void FUN_005a46d0(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  int *in_ECX;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  int local_d0;
  undefined4 *local_c4;
  int local_c0;
  int local_84;
  int local_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 *local_48;
  void *local_44;
  int *local_40;
  int *local_3c;
  uint local_38;
  char *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706d6f;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_30 = in_ECX;
  local_14 = uVar1;
  GetTickCount();
  local_38 = 0;
  uVar11 = 0;
  local_28 = (int *)0x1;
  do {
    if (((uint)local_28 & 0x7ff) != 0) {
      local_3c = in_ECX + 0x27;
      if (0xc < local_38) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_006c2d00(uVar1);
      if (((int)local_38 < 0) || (0xc < (int)local_38)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_44 = (void *)0x0;
      local_34 = (char *)0x0;
      while( true ) {
        if (uVar11 < 0x91) {
          piVar2 = (int *)(uVar11 + (int)local_3c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar2 = local_3c;
        }
        if (piVar2[1] <= (int)local_44) break;
        local_44 = (void *)((int)local_44 + 1);
        piVar2 = (int *)(local_34 + *piVar2);
        local_58 = *piVar2;
        iStack_54 = piVar2[1];
        iStack_50 = piVar2[2];
        iStack_4c = piVar2[3];
        local_34 = local_34 + 0x10;
        if (0x90 < uVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006c2340(local_58,iStack_54,iStack_50,iStack_4c);
      }
      if (0xc < local_38) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_0049c5f0(0);
    }
    local_38 = local_38 + 1;
    local_28 = (int *)((int)local_28 << 1 | (uint)((int)local_28 < 0));
    uVar11 = uVar11 + 0xc;
  } while ((int)uVar11 < 0x9c);
  iStack_18 = 0;
  iStack_1c = 0;
  iStack_20 = 0;
                    /* WARNING: Load size is inaccurate */
  local_38 = *ThreadLocalStoragePointer;
  local_24 = 0;
  if ((*(int *)(local_38 + 4) < DAT_00ca54f8) &&
     (FUN_006cebf4(&DAT_00ca54f8), iVar3 = DAT_00783650, DAT_00ca54f8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca54fc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:EFFPASSWALK";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54f8);
  }
  local_28 = (int *)(DAT_00ca54fc * 0x40);
  local_2c = &DAT_00ca54fc;
  uVar14 = *(undefined4 *)(&DAT_00773650 + (int)local_28);
  iVar3 = FUN_0043fcc0();
  piVar2 = local_28;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)&DAT_00773654 + (int)local_28);
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = *(int *)((int)&DAT_00773654 + (int)piVar2);
    *(undefined8 *)((int)&DAT_00773658 + (int)piVar2) = uVar13;
  }
  *(int *)((int)&DAT_00773654 + (int)piVar2) = iVar3 + 1;
  local_8 = 2;
  FUN_006c2d00();
  piVar2 = (int *)0;
  pcVar5 = (char *)0x0;
  while (piVar9 = local_30, (int)piVar2 < in_ECX[1]) {
    local_28 = (int *)((int)piVar2 + 1);
    piVar2 = (int *)(pcVar5 + *in_ECX);
    local_34 = pcVar5 + 0x10;
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x68] = local_30[0x68] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    FUN_005a6b40(&local_24);
    piVar2 = local_28;
    pcVar5 = local_34;
    in_ECX = piVar9;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if ((*(int *)(local_38 + 4) < DAT_00ca5500) &&
     (FUN_006cebf4(&DAT_00ca5500), iVar3 = DAT_00783650, DAT_00ca5500 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca5504 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:EFFOBJPF";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5500);
  }
  local_28 = (int *)(DAT_00ca5504 * 0x40);
  local_2c = &DAT_00ca5504;
  uVar14 = *(undefined4 *)(&DAT_00773650 + (int)local_28);
  iVar3 = FUN_0043fcc0();
  piVar2 = local_28;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)&DAT_00773654 + (int)local_28);
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = *(int *)((int)&DAT_00773654 + (int)piVar2);
    *(undefined8 *)((int)&DAT_00773658 + (int)piVar2) = uVar13;
  }
  *(int *)((int)&DAT_00773654 + (int)piVar2) = iVar3 + 1;
  local_8 = 3;
  FUN_006c2d00();
  piVar2 = (int *)0;
  pcVar5 = (char *)0x0;
  while (piVar9 = local_30, (int)piVar2 < in_ECX[4]) {
    local_28 = (int *)((int)piVar2 + 1);
    piVar2 = (int *)(pcVar5 + in_ECX[3]);
    local_34 = pcVar5 + 0x10;
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x69] = local_30[0x69] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    FUN_005a5da0(&local_24);
    piVar2 = local_28;
    pcVar5 = local_34;
    in_ECX = piVar9;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if ((*(int *)(local_38 + 4) < DAT_00ca5508) &&
     (FUN_006cebf4(&DAT_00ca5508), iVar3 = DAT_00783650, DAT_00ca5508 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca550c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:EFFBLOCK";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5508);
  }
  local_28 = (int *)(DAT_00ca550c * 0x40);
  local_2c = &DAT_00ca550c;
  uVar14 = *(undefined4 *)(&DAT_00773650 + (int)local_28);
  iVar3 = FUN_0043fcc0();
  piVar2 = local_28;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)&DAT_00773654 + (int)local_28);
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = *(int *)((int)&DAT_00773654 + (int)piVar2);
    *(undefined8 *)((int)&DAT_00773658 + (int)piVar2) = uVar13;
  }
  *(int *)((int)&DAT_00773654 + (int)piVar2) = iVar3 + 1;
  local_8 = 4;
  FUN_006c2d00();
  piVar2 = (int *)0;
  pcVar5 = (char *)0x0;
  while (piVar9 = local_30, (int)piVar2 < in_ECX[7]) {
    local_28 = (int *)((int)piVar2 + 1);
    piVar2 = (int *)(pcVar5 + in_ECX[6]);
    local_34 = pcVar5 + 0x10;
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x6a] = local_30[0x6a] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    FUN_005a6350(&local_24);
    piVar2 = local_28;
    pcVar5 = local_34;
    in_ECX = piVar9;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if ((*(int *)(local_38 + 4) < DAT_00ca5510) &&
     (FUN_006cebf4(&DAT_00ca5510), iVar3 = DAT_00783650, DAT_00ca5510 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca5514 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:BASELIGHT";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5510);
  }
  local_28 = (int *)(DAT_00ca5514 * 0x40);
  local_2c = &DAT_00ca5514;
  iVar3 = local_28[0x1dcd94];
  iVar4 = FUN_0043fcc0();
  piVar2 = local_28;
  *(int *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = iVar3;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar3 = local_28[0x1dcd95];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = piVar2[0x1dcd95];
    *(undefined8 *)(piVar2 + 0x1dcd96) = uVar13;
  }
  piVar2[0x1dcd95] = iVar3 + 1;
  local_8 = 5;
  FUN_006c2d00();
  piVar2 = (int *)0x0;
  pcVar5 = (char *)0x0;
  while (piVar9 = local_30, (int)piVar2 < in_ECX[10]) {
    local_28 = (int *)((int)piVar2 + 1);
    piVar2 = (int *)(pcVar5 + in_ECX[9]);
    local_34 = pcVar5 + 0x10;
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x6b] = local_30[0x6b] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    FUN_005906a0(&local_24);
    piVar2 = local_28;
    pcVar5 = local_34;
    in_ECX = piVar9;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if (DAT_0076a338 != 0) {
    if ((*(int *)(local_38 + 4) < DAT_00ca5518) &&
       (FUN_006cebf4(&DAT_00ca5518), iVar3 = DAT_00783650, DAT_00ca5518 == -1)) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca551c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "MapValidator:RENDERJOBS";
      *(int *)(&DAT_00773650 + iVar4) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca5518);
    }
    local_28 = (int *)(DAT_00ca551c * 0x40);
    local_48 = &DAT_00ca551c;
    iVar3 = local_28[0x1dcd94];
    iVar4 = FUN_0043fcc0();
    piVar2 = local_28;
    *(int *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = iVar3;
    *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
    iVar3 = local_28[0x1dcd95];
    if (iVar3 == 0) {
      uVar13 = FUN_006bd180();
      iVar3 = piVar2[0x1dcd95];
      *(undefined8 *)(piVar2 + 0x1dcd96) = uVar13;
    }
    piVar2[0x1dcd95] = iVar3 + 1;
    local_8 = 6;
    local_3c = in_ECX + 0xc;
    FUN_006c2d00();
    local_44 = (void *)FUN_005b78b0();
    piVar2 = (undefined4 *)0x0;
    piVar9 = in_ECX + 0xc;
    piVar10 = (int *)0;
    while ((int)piVar10 < piVar9[1]) {
      local_40 = (int *)((int)piVar10 + 1);
      piVar9 = (int *)(*piVar9 + (int)piVar2);
      local_2c = piVar2 + 4;
      local_24 = *piVar9;
      if (*piVar9 < PTR_0077241c->x0_8) {
        local_24 = PTR_0077241c->x0_8;
      }
      iStack_20 = piVar9[1];
      if (piVar9[1] < PTR_0077241c->y0_8) {
        iStack_20 = PTR_0077241c->y0_8;
      }
      iStack_1c = piVar9[2];
      if (PTR_0077241c->x1_8 < piVar9[2]) {
        iStack_1c = PTR_0077241c->x1_8;
      }
      iStack_18 = piVar9[3];
      if (PTR_0077241c->y1_8 < piVar9[3]) {
        iStack_18 = PTR_0077241c->y1_8;
      }
      local_30[0x6c] = local_30[0x6c] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
      iVar3 = DAT_0076a338;
      local_58 = (int)(local_24 + (local_24 >> 0x1f & 7U)) >> 3;
      local_28 = (int *)(DAT_0076a338 + 0x5c);
      iStack_4c = (int)(iStack_18 + 7 + (iStack_18 + 7 >> 0x1f & 7U)) >> 3;
      iStack_54 = (int)(iStack_20 + (iStack_20 >> 0x1f & 7U)) >> 3;
      iStack_50 = (int)(iStack_1c + 7 + (iStack_1c + 7 >> 0x1f & 7U)) >> 3;
      FUN_0047e190(1);
      local_34 = *(char **)(iVar3 + 0x60) + -1;
      if (*(char **)(iVar3 + 0x60) <= local_34) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      pcVar5 = local_34;
      *(undefined4 *)(*local_28 + (int)local_34 * 0x14) = 1;
      if ((char *)local_28[1] <= local_34) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = (int *)(*local_28 + 4 + (int)pcVar5 * 0x14);
      *piVar2 = local_58;
      piVar2[1] = iStack_54;
      piVar2[2] = iStack_50;
      piVar2[3] = iStack_4c;
      CDummyObjMgr__FlushRenderJobs(&local_24);
      piVar2 = local_2c;
      piVar9 = local_3c;
      piVar10 = local_40;
    }
    FUN_0049c5f0(0);
    FUN_0043fd30();
    in_ECX = local_30;
  }
  if ((*(int *)(local_38 + 4) < DAT_00ca5520) &&
     (FUN_006cebf4(&DAT_00ca5520), iVar3 = DAT_00783650, DAT_00ca5520 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca5524 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:FlUIDOBJS";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5520);
  }
  local_2c = (int *)(DAT_00ca5524 * 0x40);
  local_48 = &DAT_00ca5524;
  uVar14 = *(undefined4 *)(&DAT_00773650 + (int)local_2c);
  iVar3 = FUN_0043fcc0();
  piVar2 = local_2c;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)&DAT_00773654 + (int)local_2c);
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = *(int *)((int)&DAT_00773654 + (int)piVar2);
    *(undefined8 *)((int)&DAT_00773658 + (int)piVar2) = uVar13;
  }
  *(int *)((int)&DAT_00773654 + (int)piVar2) = iVar3 + 1;
  local_8 = 7;
  local_2c = in_ECX + 0xf;
  FUN_006c2d00();
  piVar2 = (int *)0;
  piVar9 = (int *)0x0;
  piVar10 = in_ECX + 0xf;
  while ((int)piVar2 < piVar10[1]) {
    local_40 = (int *)((int)piVar2 + 1);
    piVar2 = (int *)(*piVar10 + (int)piVar9);
    local_28 = piVar9 + 4;
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x6d] = local_30[0x6d] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    local_58 = (int)(local_24 + (local_24 >> 0x1f & 7U)) >> 3;
    iStack_4c = (int)(iStack_18 + 7 + (iStack_18 + 7 >> 0x1f & 7U)) >> 3;
    iStack_54 = (int)(iStack_20 + (iStack_20 >> 0x1f & 7U)) >> 3;
    iStack_50 = (int)(iStack_1c + 7 + (iStack_1c + 7 >> 0x1f & 7U)) >> 3;
    piVar2 = &local_58;
    FUN_0057d980(piVar2);
    FUN_0057b990(piVar2);
    piVar2 = local_40;
    piVar9 = local_28;
    piVar10 = local_2c;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if ((*(int *)(local_38 + 4) < DAT_00ca5528) &&
     (FUN_006cebf4(&DAT_00ca5528), iVar3 = DAT_00783650, DAT_00ca5528 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca552c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:MINIMAP";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5528);
  }
  iVar4 = DAT_00ca552c;
  local_48 = &DAT_00ca552c;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca552c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  piVar10 = local_30 + 0x12;
  local_8 = 8;
  local_2c = piVar10;
  FUN_006c2d00();
  piVar2 = (int *)0;
  piVar9 = (int *)0x0;
  while ((int)piVar2 < piVar10[1]) {
    local_40 = (int *)((int)piVar2 + 1);
    piVar2 = (int *)(*piVar10 + (int)piVar9);
    local_28 = piVar9 + 4;
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x6e] = local_30[0x6e] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    local_58 = (int)(local_24 + (local_24 >> 0x1f & 7U)) >> 3;
    iStack_4c = (int)(iStack_18 + 7 + (iStack_18 + 7 >> 0x1f & 7U)) >> 3;
    iStack_54 = (int)(iStack_20 + (iStack_20 >> 0x1f & 7U)) >> 3;
    iStack_50 = (int)(iStack_1c + 7 + (iStack_1c + 7 >> 0x1f & 7U)) >> 3;
    FUN_005a9090();
    FUN_006c2340(local_58,iStack_54,iStack_50,iStack_4c);
    piVar2 = local_40;
    piVar9 = local_28;
    piVar10 = local_2c;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if ((*(int *)(local_38 + 4) < DAT_00ca5530) &&
     (FUN_006cebf4(&DAT_00ca5530), iVar3 = DAT_00783650, DAT_00ca5530 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca5534 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:IDIOBJ";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5530);
  }
  iVar4 = DAT_00ca5534;
  local_48 = &DAT_00ca5534;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca5534 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar13;
  }
  piVar2 = local_30;
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 9;
  FUN_006c2d00();
  piVar9 = (int *)0x0;
  piVar10 = (int *)0;
  while (piVar12 = local_30, (int)piVar9 < piVar2[0x16]) {
    local_2c = (int *)((int)piVar9 + 1);
    piVar2 = (int *)(piVar2[0x15] + (int)piVar10);
    local_40 = (int *)((int)piVar10 + 0x10);
    local_24 = *piVar2;
    if (*piVar2 < PTR_0077241c->x0_8) {
      local_24 = PTR_0077241c->x0_8;
    }
    iStack_20 = piVar2[1];
    if (piVar2[1] < PTR_0077241c->y0_8) {
      iStack_20 = PTR_0077241c->y0_8;
    }
    iStack_1c = piVar2[2];
    if (PTR_0077241c->x1_8 < piVar2[2]) {
      iStack_1c = PTR_0077241c->x1_8;
    }
    iStack_18 = piVar2[3];
    if (PTR_0077241c->y1_8 < piVar2[3]) {
      iStack_18 = PTR_0077241c->y1_8;
    }
    local_30[0x6f] = local_30[0x6f] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
    FUN_005d5570(local_24,iStack_20,iStack_1c,iStack_18);
    piVar9 = local_2c;
    piVar10 = local_40;
    piVar2 = piVar12;
  }
  FUN_0049c5f0(0);
  FUN_0043fd30();
  if ((*(int *)(local_38 + 4) < DAT_00ca5538) &&
     (FUN_006cebf4(&DAT_00ca5538), iVar3 = DAT_00783650, DAT_00ca5538 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca553c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "MapValidator:OBJPHYSIC";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5538);
  }
  local_2c = (int *)(DAT_00ca553c * 0x40);
  local_48 = &DAT_00ca553c;
  uVar14 = *(undefined4 *)((int)local_2c + 0x773650);
  iVar3 = FUN_0043fcc0();
  piVar9 = local_2c;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)local_2c + 0x773654);
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = *(int *)((int)piVar9 + 0x773654);
    *(undefined8 *)((int)piVar9 + 0x773658) = uVar13;
  }
  *(int *)((int)piVar9 + 0x773654) = iVar3 + 1;
  local_8._0_1_ = 10;
  local_8._1_3_ = 0;
  FUN_006c2d00();
  piVar9 = (int *)0x0;
  pcVar5 = (char *)0x0;
  do {
    local_3c = (int *)DAT_00772468;
    do {
      piVar10 = local_30;
      if (piVar2[0x19] <= (int)piVar9) {
        FUN_0049c5f0(0);
        FUN_0043fd30();
        if ((*(int *)(local_38 + 4) < DAT_00ca5540) &&
           (FUN_006cebf4(&DAT_00ca5540), iVar3 = DAT_00783650, DAT_00ca5540 == -1)) {
          iVar4 = DAT_00783650 * 0x40;
          DAT_00ca5544 = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar4) = "MapValidator:DUMMYDES";
          *(int *)(&DAT_00773650 + iVar4) = iVar3;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca5540);
        }
        local_2c = (int *)(DAT_00ca5544 * 0x40);
        local_48 = &DAT_00ca5544;
        uVar14 = *(undefined4 *)(&DAT_00773650 + (int)local_2c);
        iVar3 = FUN_0043fcc0();
        piVar9 = local_2c;
        *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
        *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
        iVar3 = *(int *)((int)&DAT_00773654 + (int)local_2c);
        if (iVar3 == 0) {
          uVar13 = FUN_006bd180();
          iVar3 = *(int *)((int)&DAT_00773654 + (int)piVar9);
          *(undefined8 *)((int)&DAT_00773658 + (int)piVar9) = uVar13;
        }
        *(int *)((int)&DAT_00773654 + (int)piVar9) = iVar3 + 1;
        local_8._0_1_ = 0x10;
        local_8._1_3_ = 0;
        local_40 = piVar2 + 0x1b;
        FUN_006c2d00();
        piVar9 = (int *)0;
        piVar10 = (int *)0x0;
        piVar2 = piVar2 + 0x1b;
        while (pcVar5 = DAT_00772468, (int)piVar9 < piVar2[1]) {
          local_2c = (int *)((int)piVar9 + 1);
          piVar2 = (int *)(*piVar2 + (int)piVar10);
          local_28 = piVar10 + 4;
          local_24 = *piVar2;
          if (*piVar2 < PTR_0077241c->x0_8) {
            local_24 = PTR_0077241c->x0_8;
          }
          iStack_20 = piVar2[1];
          if (piVar2[1] < PTR_0077241c->y0_8) {
            iStack_20 = PTR_0077241c->y0_8;
          }
          iStack_1c = piVar2[2];
          if (PTR_0077241c->x1_8 < piVar2[2]) {
            iStack_1c = PTR_0077241c->x1_8;
          }
          iStack_18 = piVar2[3];
          if (PTR_0077241c->y1_8 < piVar2[3]) {
            iStack_18 = PTR_0077241c->y1_8;
          }
          local_30[0x71] = local_30[0x71] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
          if (pcVar5 == (char *)0x0) {
            pcVar5 = (char *)FUN_006ba810(0x2f6);
            local_34 = pcVar5;
            if (pcVar5 == (char *)0x0) {
              DAT_00772468 = (char *)0x0;
            }
            else {
              pcVar5[1] = '\0';
              pcVar5[2] = '\0';
              pcVar5[3] = '\0';
              pcVar5[4] = '\0';
              pcVar5[5] = '\0';
              pcVar5[6] = '\0';
              pcVar5[7] = '\0';
              pcVar5[8] = '\0';
              local_8._0_1_ = 0x12;
              *pcVar5 = '\x01';
              FUN_005ebb00();
              DAT_00772468 = pcVar5;
            }
            local_8._0_1_ = 0x10;
          }
          FUN_005eb7b0(&local_24);
          iStack_4c = (int)((iStack_18 + 7 >> 0x1f & 7U) + iStack_18 + 7) >> 3;
          iStack_50 = (int)((iStack_1c + 7 >> 0x1f & 7U) + iStack_1c + 7) >> 3;
          iStack_54 = (int)((iStack_20 >> 0x1f & 7U) + iStack_20) >> 3;
          local_58 = (int)(local_24 + (local_24 >> 0x1f & 7U)) >> 3;
          if (DAT_00772418 == (void *)0x0) {
            pvVar6 = (void *)FUN_006ba810(0x166);
            local_8._0_1_ = 0x13;
            local_44 = pvVar6;
            if (pvVar6 == (void *)0x0) {
              DAT_00772418 = (void *)0x0;
            }
            else {
              _eh_vector_constructor_iterator_(pvVar6,0x24,0x800,FUN_00592ee0,guard_check_icall);
              *(undefined4 *)((int)pvVar6 + 0x12000) = 0;
              *(undefined4 *)((int)pvVar6 + 0x12004) = 0;
              DAT_00772418 = pvVar6;
            }
            local_8._0_1_ = 0x10;
          }
          FUN_00592840(1,local_58,iStack_54,iStack_50,iStack_4c);
          uVar14 = 1;
          iVar3 = local_58;
          iVar4 = iStack_54;
          iVar7 = iStack_50;
          iVar8 = iStack_4c;
          FUN_00492250(1,local_58,iStack_54,iStack_50,iStack_4c);
          FUN_0049bb70(uVar14,iVar3,iVar4,iVar7,iVar8);
          piVar9 = local_2c;
          piVar10 = local_28;
          piVar2 = local_40;
        }
        FUN_0049c5f0(0);
        FUN_0043fd30();
        if ((*(int *)(local_38 + 4) < DAT_00ca5548) &&
           (FUN_006cebf4(&DAT_00ca5548), iVar3 = DAT_00783650, DAT_00ca5548 == -1)) {
          iVar4 = DAT_00783650 * 0x40;
          DAT_00ca554c = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar4) = "MapValidator:FLUIDALIST";
          *(int *)(&DAT_00773650 + iVar4) = iVar3;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca5548);
        }
        iVar4 = DAT_00ca554c;
        local_48 = &DAT_00ca554c;
        uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca554c * 0x40);
        iVar3 = FUN_0043fcc0();
        *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar14;
        *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
        iVar3 = (&DAT_00773654)[iVar4 * 0x10];
        if (iVar3 == 0) {
          uVar13 = FUN_006bd180();
          iVar3 = (&DAT_00773654)[iVar4 * 0x10];
          *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar13;
        }
        (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
        piVar10 = local_30 + 0x1e;
        local_8 = 0x14;
        local_2c = piVar10;
        FUN_006c2d00();
        piVar2 = (int *)0x0;
        piVar9 = (int *)0x0;
        while ((int)piVar2 < piVar10[1]) {
          local_40 = (int *)((int)piVar2 + 1);
          piVar2 = (int *)(*piVar10 + (int)piVar9);
          local_28 = piVar9 + 4;
          local_24 = *piVar2;
          if (*piVar2 < PTR_0077241c->x0_8) {
            local_24 = PTR_0077241c->x0_8;
          }
          iStack_20 = piVar2[1];
          if (piVar2[1] < PTR_0077241c->y0_8) {
            iStack_20 = PTR_0077241c->y0_8;
          }
          iStack_1c = piVar2[2];
          if (PTR_0077241c->x1_8 < piVar2[2]) {
            iStack_1c = PTR_0077241c->x1_8;
          }
          iStack_18 = piVar2[3];
          if (PTR_0077241c->y1_8 < piVar2[3]) {
            iStack_18 = PTR_0077241c->y1_8;
          }
          local_30[0x72] = local_30[0x72] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
          iVar3 = (int)(local_24 + (local_24 >> 0x1f & 7U)) >> 3;
          iVar4 = (int)(iStack_18 + 7 + (iStack_18 + 7 >> 0x1f & 7U)) >> 3;
          iVar7 = (int)(iStack_20 + (iStack_20 >> 0x1f & 7U)) >> 3;
          iVar8 = (int)(iStack_1c + 7 + (iStack_1c + 7 >> 0x1f & 7U)) >> 3;
          local_58 = iVar3;
          iStack_54 = iVar7;
          iStack_50 = iVar8;
          iStack_4c = iVar4;
          FUN_0057d980(iVar3,iVar7,iVar8,iVar4);
          FUN_0057cd50(iVar3,iVar7,iVar8,iVar4);
          piVar2 = local_40;
          piVar9 = local_28;
          piVar10 = local_2c;
        }
        FUN_0049c5f0(0);
        FUN_0043fd30();
        GetTickCount();
        *(undefined1 *)(DAT_00772400 + 0x97) = 0;
        ExceptionList = local_10;
        __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
        return;
      }
      local_28 = (int *)((int)piVar9 + 1);
      piVar2 = (int *)(pcVar5 + piVar2[0x18]);
      local_34 = pcVar5 + 0x10;
      local_24 = *piVar2;
      if (*piVar2 < PTR_0077241c->x0_8) {
        local_24 = PTR_0077241c->x0_8;
      }
      iStack_20 = piVar2[1];
      if (piVar2[1] < PTR_0077241c->y0_8) {
        iStack_20 = PTR_0077241c->y0_8;
      }
      iStack_1c = piVar2[2];
      if (PTR_0077241c->x1_8 < piVar2[2]) {
        iStack_1c = PTR_0077241c->x1_8;
      }
      iStack_18 = piVar2[3];
      if (PTR_0077241c->y1_8 < piVar2[3]) {
        iStack_18 = PTR_0077241c->y1_8;
      }
      local_30[0x70] = local_30[0x70] + (iStack_1c - local_24) * (iStack_18 - iStack_20);
      piVar12 = local_3c;
      if (local_3c == (int *)0x0) {
        pcVar5 = (char *)FUN_006ba810(0x2f6);
        local_2c = (int *)pcVar5;
        if (pcVar5 == (char *)0x0) {
          piVar12 = (int *)0x0;
          local_3c = (int *)0x0;
        }
        else {
          pcVar5[1] = '\0';
          pcVar5[2] = '\0';
          pcVar5[3] = '\0';
          pcVar5[4] = '\0';
          pcVar5[5] = '\0';
          pcVar5[6] = '\0';
          pcVar5[7] = '\0';
          pcVar5[8] = '\0';
          local_8._0_1_ = 0xc;
          *pcVar5 = '\x01';
          local_3c = (int *)pcVar5;
          FUN_005ebb00();
          piVar12 = (int *)pcVar5;
        }
        local_8._0_1_ = 10;
        DAT_00772468 = (char *)piVar12;
      }
      piVar9 = local_28;
      pcVar5 = local_34;
      piVar2 = piVar10;
    } while (*(char *)piVar12 == '\0');
    FUN_005ddd60();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    while( true ) {
      if (local_d0 == -2) {
        FUN_005e12a0();
      }
      local_d0 = local_d0 + 1;
      if (local_c0 <= local_d0) break;
      if ((local_d0 < 0) || (local_c0 <= local_d0)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        FUN_005eb470(*local_c4);
      }
      else {
        FUN_005eb470(local_c4[local_d0]);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,0xe);
    FUN_0040b980(0);
    piVar2 = local_30;
    if (local_84 != 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0xf;
    FUN_006ba940();
    local_8._0_1_ = 10;
    thunk_FUN_0060fc30(local_c4);
    piVar9 = local_28;
    pcVar5 = local_34;
  } while( true );
}

