
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameThread__SrvDoThink(CGameThread *this)

{
  uint *puVar1;
  int *piVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  LPVOID pvVar7;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  bool bVar13;
  double dVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  int local_28;
  int local_24;
  uint local_1c;
  int *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712e9e;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  iVar4 = *ThreadLocalStoragePointer;
  if ((*(int *)(iVar4 + 4) < DAT_00ca7e44) &&
     (FUN_006cebf4(&DAT_00ca7e44,uVar5), iVar6 = DAT_00783650, DAT_00ca7e44 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00ca7e48 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink()";
    *(int *)(&DAT_00773650 + iVar12) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7e44);
  }
  iVar12 = DAT_00ca7e48;
  uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7e48 * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar6 == 0) {
    uVar15 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
  local_8 = 0;
  dVar14 = *(double *)(DAT_00772400 + 0xa088);
  if (*(char *)(DAT_00772400 + 0x8a) != '\0') {
    dVar3 = *(double *)&this->field_0x80;
    if (dVar3 <= dVar14) {
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e4c) &&
         (FUN_006cebf4(&DAT_00ca7e4c,uVar5), iVar6 = DAT_00783650, DAT_00ca7e4c == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7e50 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() 1st";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e4c);
      }
      FUN_00405af0(&DAT_00ca7e50);
      local_8 = CONCAT31(local_8._1_3_,1);
      *(undefined8 *)(DAT_00772400 + 0xa0b0) = *(undefined8 *)&this->field_0x80;
      FUN_0054df60();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e54) &&
         (FUN_006cebf4(&DAT_00ca7e54), iVar6 = DAT_00783650, DAT_00ca7e54 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7e58 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() UpdateLightMap";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e54);
      }
      FUN_00405af0(&DAT_00ca7e58);
      FUN_0043fd30();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e5c) &&
         (FUN_006cebf4(&DAT_00ca7e5c), iVar6 = DAT_00783650, DAT_00ca7e5c == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7e60 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) =
             "CGameThread::SrvDoThink() GetObjMgr().DoMaintenanceTick();";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e5c);
      }
      FUN_00405af0(&DAT_00ca7e60);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_005d4250();
      FUN_0043fd30();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e64) &&
         (FUN_006cebf4(&DAT_00ca7e64), iVar6 = DAT_00783650, DAT_00ca7e64 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7e68 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() CAiCentral";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e64);
      }
      FUN_00405af0(&DAT_00ca7e68);
      local_8._0_1_ = 3;
      FUN_004244e0();
      FUN_00424680();
      FUN_004244e0();
      FUN_00424560();
      FUN_0043fd30();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0043fd30();
      dVar3 = *(double *)&this->field_0x80;
    }
    local_24 = 10;
    iVar6 = DAT_00772400;
    while ((DAT_00772400 = iVar6, dVar3 <= dVar14 && (0 < local_24))) {
      iVar12 = *(int *)(iVar6 + 0x38);
      if (iVar12 != 0) {
        iVar10 = *(int *)(iVar6 + 0x4c) + 1;
        puVar1 = (uint *)(iVar6 + 0x40);
        uVar5 = *puVar1;
        *puVar1 = *puVar1 + 1;
        *(int *)(iVar6 + 0x4c) = iVar10;
        *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + (uint)(0xfffffffe < uVar5);
        if (*(int *)(iVar6 + 0x48) <= iVar10) {
          *(undefined4 *)(iVar6 + 0x4c) = 0;
          iVar10 = 0;
        }
        uVar15 = FUN_006bd180();
        iVar6 = DAT_00772400;
        *(int *)(iVar12 + 4 + iVar10 * 8) = (int)((ulonglong)uVar15 >> 0x20);
        *(int *)(iVar12 + iVar10 * 8) = (int)uVar15;
      }
      *(int *)(iVar6 + 0x6c) = *(int *)(iVar6 + 0x6c) + 1;
      local_24 = local_24 + -1;
      *(undefined8 *)(iVar6 + 0xa0b0) = *(undefined8 *)&this->field_0x80;
      *(double *)&this->field_0x80 = *(double *)&this->field_0x80 + 0.1;
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e6c) &&
         (FUN_006cebf4(&DAT_00ca7e6c), iVar6 = DAT_00783650, DAT_00ca7e6c == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7e70 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() ProdControlMgr";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e6c);
      }
      iVar6 = DAT_00ca7e70;
      iVar12 = DAT_00ca7e70 * 0x40;
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      pvVar7 = TlsGetValue(DAT_00767960);
      if (pvVar7 == (LPVOID)0x0) {
        pvVar7 = (LPVOID)FUN_006ba810(0x18);
        if (pvVar7 == (LPVOID)0x0) {
          pvVar7 = (LPVOID)0x0;
        }
        else {
          *(undefined4 *)((int)pvVar7 + 0x8000) = 0;
        }
        TlsSetValue(DAT_00767960,pvVar7);
      }
      *(undefined4 *)((int)pvVar7 + *(int *)((int)pvVar7 + 0x8000) * 4) =
           *(undefined4 *)(&DAT_00773650 + iVar12);
      *(int *)((int)pvVar7 + 0x8000) = *(int *)((int)pvVar7 + 0x8000) + 1;
      iVar12 = (&DAT_00773654)[iVar6 * 0x10];
      if (iVar12 == 0) {
        uVar15 = FUN_006bd180();
        iVar12 = (&DAT_00773654)[iVar6 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar6 * 0x10] = iVar12 + 1;
      local_8._0_1_ = 7;
      FUN_005ee9d0();
      FUN_005eed70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0043fd30();
      local_18 = DAT_00772448;
      if (DAT_00772448 == (int *)0x0) {
        local_18 = (int *)FUN_006ba810(0x1e);
        if (local_18 == (int *)0x0) {
          local_18 = (int *)0x0;
        }
        else {
          *local_18 = 0;
          local_18[1] = 0;
        }
      }
      local_1c = 0;
      DAT_00772448 = local_18;
      if (0 < local_18[1]) {
        bVar13 = local_18[1] != 0;
        local_28 = 0;
        do {
          if (!bVar13) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar11 = (int *)(*local_18 + local_28);
          local_14 = 0.0;
          uVar5 = 0;
          if (0 < piVar11[4]) {
            iVar6 = 0;
            bVar13 = piVar11[4] != 0;
            do {
              if (!bVar13) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              piVar2 = (int *)(piVar11[3] + 8 + iVar6);
              *piVar2 = *piVar2 + -1;
              if (*piVar2 == 0) {
                uVar9 = piVar11[4];
                if (uVar9 <= uVar5) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  uVar9 = piVar11[4];
                  if (uVar9 <= uVar5) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    uVar9 = piVar11[4];
                  }
                }
                if ((int)uVar5 < (int)(uVar9 - 1)) {
                  iVar12 = piVar11[3];
                  *(undefined8 *)(iVar12 + iVar6) = *(undefined8 *)(iVar12 + -0xc + uVar9 * 0xc);
                  *(undefined4 *)(iVar12 + 8 + iVar6) = *(undefined4 *)(iVar12 + -4 + uVar9 * 0xc);
                  uVar9 = piVar11[4];
                }
                uVar5 = uVar5 - 1;
                piVar11[4] = uVar9 - 1;
                iVar6 = iVar6 + -0xc;
              }
              else {
                if ((uint)piVar11[4] <= uVar5) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_14 = *(float *)(piVar11[3] + 4 + iVar6) + local_14;
              }
              uVar5 = uVar5 + 1;
              iVar6 = iVar6 + 0xc;
              bVar13 = uVar5 < (uint)piVar11[4];
            } while ((int)uVar5 < piVar11[4]);
          }
          local_1c = local_1c + 1;
          local_28 = local_28 + 0x14;
          *(float *)(*(int *)(*piVar11 + 0x3e0) + 0x13c) = local_14;
          bVar13 = local_1c < (uint)local_18[1];
        } while ((int)local_1c < local_18[1]);
      }
      if (DAT_0077241c != 0) {
        if ((*(int *)(iVar4 + 4) < DAT_00ca7e74) &&
           (FUN_006cebf4(&DAT_00ca7e74), iVar6 = DAT_00783650, DAT_00ca7e74 == -1)) {
          iVar12 = DAT_00783650 * 0x40;
          DAT_00ca7e78 = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() World::g_pMap->Tick();";
          *(int *)(&DAT_00773650 + iVar12) = iVar6;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca7e74);
        }
        iVar12 = DAT_00ca7e78;
        uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7e78 * 0x40);
        iVar6 = FUN_0043fcc0();
        *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
        *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
        iVar6 = (&DAT_00773654)[iVar12 * 0x10];
        if (iVar6 == 0) {
          uVar15 = FUN_006bd180();
          iVar6 = (&DAT_00773654)[iVar12 * 0x10];
          *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
        }
        (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
        local_8._0_1_ = 8;
        FUN_00598920();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0043fd30();
      }
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e7c) &&
         (FUN_006cebf4(&DAT_00ca7e7c), iVar6 = DAT_00783650, DAT_00ca7e7c == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7e80 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() Physics";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e7c);
      }
      iVar6 = DAT_00ca7e80;
      iVar12 = DAT_00ca7e80 * 0x40;
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      pvVar7 = TlsGetValue(DAT_00767960);
      if (pvVar7 == (LPVOID)0x0) {
        pvVar7 = (LPVOID)FUN_006ba810(0x18);
        if (pvVar7 == (LPVOID)0x0) {
          pvVar7 = (LPVOID)0x0;
        }
        else {
          *(undefined4 *)((int)pvVar7 + 0x8000) = 0;
        }
        TlsSetValue(DAT_00767960,pvVar7);
      }
      *(undefined4 *)((int)pvVar7 + *(int *)((int)pvVar7 + 0x8000) * 4) =
           *(undefined4 *)(&DAT_00773650 + iVar12);
      *(int *)((int)pvVar7 + 0x8000) = *(int *)((int)pvVar7 + 0x8000) + 1;
      iVar12 = (&DAT_00773654)[iVar6 * 0x10];
      if (iVar12 == 0) {
        uVar15 = FUN_006bd180();
        iVar12 = (&DAT_00773654)[iVar6 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar6 * 0x10] = iVar12 + 1;
      local_8._0_1_ = 9;
      if (DAT_00772468 == (undefined1 *)0x0) {
        puVar8 = (undefined1 *)FUN_006ba810(0x2f6);
        if (puVar8 == (undefined1 *)0x0) {
          DAT_00772468 = (undefined1 *)0x0;
        }
        else {
          *(undefined4 *)(puVar8 + 1) = 0;
          *(undefined4 *)(puVar8 + 5) = 0;
          local_8._0_1_ = 0xb;
          *puVar8 = 1;
          FUN_005ebb00();
          DAT_00772468 = puVar8;
        }
      }
      local_8._0_1_ = 9;
      FUN_005eafd0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0043fd30();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e84) &&
         (FUN_006cebf4(&DAT_00ca7e84), iVar6 = DAT_00783650, DAT_00ca7e84 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7e88 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() TriggerMgr";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e84);
      }
      iVar6 = DAT_00ca7e88;
      iVar12 = DAT_00ca7e88 * 0x40;
      if (DAT_00767960 == 0xffffffff) {
        DAT_00767960 = TlsAlloc();
      }
      pvVar7 = TlsGetValue(DAT_00767960);
      if (pvVar7 == (LPVOID)0x0) {
        pvVar7 = (LPVOID)FUN_006ba810(0x18);
        if (pvVar7 == (LPVOID)0x0) {
          pvVar7 = (LPVOID)0x0;
        }
        else {
          *(undefined4 *)((int)pvVar7 + 0x8000) = 0;
        }
        TlsSetValue(DAT_00767960,pvVar7);
      }
      *(undefined4 *)((int)pvVar7 + *(int *)((int)pvVar7 + 0x8000) * 4) =
           *(undefined4 *)(&DAT_00773650 + iVar12);
      *(int *)((int)pvVar7 + 0x8000) = *(int *)((int)pvVar7 + 0x8000) + 1;
      iVar12 = (&DAT_00773654)[iVar6 * 0x10];
      if (iVar12 == 0) {
        uVar15 = FUN_006bd180();
        iVar12 = (&DAT_00773654)[iVar6 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar6 * 0x10] = iVar12 + 1;
      local_8._0_1_ = 0xc;
      if (DAT_00772484 == (undefined4 *)0x0) {
        DAT_00772484 = (undefined4 *)FUN_006ba810(0x6d);
        if (DAT_00772484 == (undefined4 *)0x0) {
          DAT_00772484 = (undefined4 *)0x0;
        }
        else {
          *DAT_00772484 = 0;
          DAT_00772484[1] = 0;
        }
      }
      local_8._0_1_ = 0xc;
      FUN_0060df40();
      FUN_0043fd30();
      uVar5 = *(uint *)(DAT_00772400 + 0x6c) & 0x80000003;
      if ((int)uVar5 < 0) {
        uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
      }
      if (uVar5 == 3) {
        if ((*(int *)(iVar4 + 4) < DAT_00ca7e8c) &&
           (FUN_006cebf4(&DAT_00ca7e8c), iVar6 = DAT_00783650, DAT_00ca7e8c == -1)) {
          iVar12 = DAT_00783650 * 0x40;
          DAT_00ca7e90 = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() FOW";
          *(int *)(&DAT_00773650 + iVar12) = iVar6;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca7e8c);
        }
        iVar12 = DAT_00ca7e90;
        uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7e90 * 0x40);
        iVar6 = FUN_0043fcc0();
        *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
        *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
        iVar6 = (&DAT_00773654)[iVar12 * 0x10];
        if (iVar6 == 0) {
          uVar15 = FUN_006bd180();
          iVar6 = (&DAT_00773654)[iVar12 * 0x10];
          *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
        }
        (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
        local_8._0_1_ = 0x13;
        if ((DAT_0077241c != 0) && (*(char *)(DAT_0077241c + 0x29) != '\0')) {
          FUN_0057f5c0();
        }
        FUN_0043fd30();
      }
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e94) &&
         (FUN_006cebf4(&DAT_00ca7e94), iVar6 = DAT_00783650, DAT_00ca7e94 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7e98 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) =
             "CGameThread::SrvDoThink() World::GetMapValidator().Service()";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e94);
      }
      iVar12 = DAT_00ca7e98;
      uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7e98 * 0x40);
      iVar6 = FUN_0043fcc0();
      *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
      *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
      iVar6 = (&DAT_00773654)[iVar12 * 0x10];
      if (iVar6 == 0) {
        uVar15 = FUN_006bd180();
        iVar6 = (&DAT_00773654)[iVar12 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
      uVar16 = 0x7ff;
      local_8 = CONCAT31(local_8._1_3_,0x14);
      FUN_005a3dd0(0x7ff);
      FUN_005a46d0(uVar16);
      FUN_0043fd30();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7e9c) &&
         (FUN_006cebf4(&DAT_00ca7e9c), iVar6 = DAT_00783650, DAT_00ca7e9c == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7ea0 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() GetObjMgr().HandleEvents();"
        ;
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7e9c);
      }
      iVar12 = DAT_00ca7ea0;
      uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7ea0 * 0x40);
      iVar6 = FUN_0043fcc0();
      *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
      *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
      iVar6 = (&DAT_00773654)[iVar12 * 0x10];
      if (iVar6 == 0) {
        uVar15 = FUN_006bd180();
        iVar6 = (&DAT_00773654)[iVar12 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
      local_8 = CONCAT31(local_8._1_3_,0x15);
      _DAT_00c3c9e4 = _DAT_00c3c9e4 + 1;
      CGameThread__SrvDoThink(DAT_0077244c);
      _DAT_00c3c9e4 = 0;
      FUN_0043fd30();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7ea4) &&
         (FUN_006cebf4(&DAT_00ca7ea4), iVar6 = DAT_00783650, DAT_00ca7ea4 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7ea8 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() GetObjMgr().DoTrans();";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7ea4);
      }
      iVar12 = DAT_00ca7ea8;
      uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7ea8 * 0x40);
      iVar6 = FUN_0043fcc0();
      *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
      *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
      iVar6 = (&DAT_00773654)[iVar12 * 0x10];
      if (iVar6 == 0) {
        uVar15 = FUN_006bd180();
        iVar6 = (&DAT_00773654)[iVar12 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
      FUN_005d2720();
      FUN_0043fd30();
      if ((*(int *)(iVar4 + 4) < DAT_00ca7eac) &&
         (FUN_006cebf4(&DAT_00ca7eac), iVar6 = DAT_00783650, DAT_00ca7eac == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00ca7eb0 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::SrvDoThink() DoObjUpdates();";
        *(int *)(&DAT_00773650 + iVar12) = iVar6;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7eac);
      }
      iVar12 = DAT_00ca7eb0;
      uVar16 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7eb0 * 0x40);
      iVar6 = FUN_0043fcc0();
      *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar16;
      *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
      iVar6 = (&DAT_00773654)[iVar12 * 0x10];
      if (iVar6 == 0) {
        uVar15 = FUN_006bd180();
        iVar6 = (&DAT_00773654)[iVar12 * 0x10];
        *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
      }
      (&DAT_00773654)[iVar12 * 0x10] = iVar6 + 1;
      local_8._0_1_ = 0x16;
      if (DAT_00772470 == 0) {
        DAT_00772470 = FUN_006ba810(0x17);
      }
      FUN_005f6a20();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0043fd30();
      FUN_005653f0();
      dVar3 = *(double *)&this->field_0x80;
      iVar6 = DAT_00772400;
    }
    dVar14 = *(double *)(iVar6 + 0xa088) + 0.0001;
    if (dVar3 <= dVar14) {
      *(double *)&this->field_0x80 = dVar14;
    }
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

