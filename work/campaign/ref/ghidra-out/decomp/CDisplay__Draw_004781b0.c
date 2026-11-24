
/* WARNING: Removing unreachable block (ram,0x00478374) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CDisplay__Draw(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  DWORD DVar7;
  DWORD DVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  ushort *puVar14;
  undefined8 uVar15;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  uint local_20;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = DAT_0076a338;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fdacd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00773648 != (HWND)0x0) {
    iStack_58 = 0x4781f9;
    PostMessageA(DAT_00773648,0x400,0,0);
  }
                    /* WARNING: Load size is inaccurate */
  iVar10 = *ThreadLocalStoragePointer;
  if ((*(int *)(iVar10 + 4) < DAT_00c8ad58) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad58 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00c8ad5c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 1";
    *(int *)(&DAT_00773650 + iVar12) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar12 = DAT_00c8ad5c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c8ad5c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar3 == 0) {
    uVar15 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar3 + 1;
  local_8 = 0;
  if ((DAT_0076a324 != 0) && (uVar13 = 0, 0 < *(int *)(iVar2 + 0x60))) {
    local_18 = 0;
    do {
      uVar4 = *(uint *)(iVar2 + 0x60);
      if (uVar4 <= uVar13) {
        iStack_58 = 0x4782b4;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar4 = *(uint *)(iVar2 + 0x60);
      }
      iVar3 = *(int *)(local_18 + *(int *)(iVar2 + 0x5c));
      if (uVar4 <= uVar13) {
        iStack_58 = 0x4782dc;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (iVar3 == 0) {
        FUN_004c6240();
      }
      else if (iVar3 == 1) {
        iStack_58 = 0x478349;
        FUN_004c6430();
      }
      else if (iVar3 == 2) {
        FUN_004c6710();
      }
      uVar13 = uVar13 + 1;
      local_18 = local_18 + 0x14;
    } while ((int)uVar13 < *(int *)(iVar2 + 0x60));
  }
  iVar3 = *(int *)(iVar2 + 0x60);
  if (iVar3 < 0) {
    FUN_0047e190();
  }
  else if (0 < iVar3) {
    *(int *)(iVar2 + 0x60) = *(int *)(iVar2 + 0x60) - iVar3;
  }
  local_8 = 0xffffffff;
  FUN_0043fd30();
  if (((*(char *)(DAT_00772400 + 0x590) != '\0') &&
      (FUN_00477970(), *(char *)(DAT_00772374 + 0x1cc) != '\0')) &&
     (*(char *)(DAT_00772374 + 0x1bc) != '\0')) {
    uStack_64 = *(undefined4 *)(DAT_00772374 + 0x1dc);
    iStack_58 = 0xff;
    uStack_60 = *(undefined4 *)(DAT_00772374 + 0x1e0);
    uStack_5c = *(undefined4 *)(DAT_00772374 + 0x1e4);
    uStack_70 = *(undefined4 *)(DAT_00772374 + 0x1d0);
    uStack_6c = *(undefined4 *)(DAT_00772374 + 0x1d4);
    uStack_68 = *(undefined4 *)(DAT_00772374 + 0x1d8);
    FUN_00466870(*(undefined4 *)(DAT_00772374 + 0x1c0),*(undefined4 *)(DAT_00772374 + 0x1c8),
                 &uStack_70);
  }
  *(undefined4 *)(DAT_00772400 + 0x1b0) = 0;
  iVar5 = FUN_0044d010();
  *(undefined4 *)(iVar2 + 0x281c) = 0;
  *(undefined4 *)(iVar2 + 0x2820) = 0;
  iVar12 = DAT_0077241c;
  iVar3 = DAT_00772400;
  DAT_00c3c97c = DAT_00c3c97c + 0.5;
  if (20.0 < DAT_00c3c97c) {
    DAT_00c3c97c = DAT_00c3c97c - 19.0;
  }
  *(undefined4 *)(DAT_00772400 + 0xa31c) = 0;
  *(undefined4 *)(iVar3 + 0xa320) = 0;
  if ((*(char *)(iVar12 + 0x29) != '\0') && (*(char *)(iVar2 + 0x2839) == '\0')) {
    iVar3 = *(int *)(iVar2 + 0x283c) + -1;
    if (iVar3 < 1) {
      iVar3 = 0;
    }
    *(int *)(iVar2 + 0x283c) = iVar3;
    if (*(char *)(iVar12 + 0x29) != '\0') {
      if (*(char *)(iVar12 + 0x2a) != '\0') {
        *(undefined1 *)(iVar12 + 0x2a) = 0;
      }
      if (DAT_0076a329 != '\0') {
        if ((*(int *)(iVar10 + 4) < DAT_00c8ad60) &&
           (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad60 == -1)) {
          iVar12 = DAT_00783650 * 0x40;
          _DAT_00c8ad64 = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 3";
          *(int *)(&DAT_00773650 + iVar12) = iVar3;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa();
        }
        FUN_00405af0();
        local_8 = 1;
        GetTickCount();
        *(int *)(iVar2 + 0x3b90) = iVar5 + 0x7c;
        *(undefined4 *)(iVar2 + 0x3bc4) = 0;
        *(undefined4 *)(iVar2 + 0x3bb4) = 0;
        if (*(int *)(iVar2 + 0x38f5) == 0) {
          FUN_004cde30();
        }
        iStack_58 = 0x47858d;
        CScapeRenderer__RenderScape();
        if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
          if ((*(int *)(iVar10 + 4) < DAT_00c8ad68) &&
             (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad68 == -1)) {
            iVar12 = DAT_00783650 * 0x40;
            _DAT_00c8ad6c = DAT_00783650;
            *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 4";
            *(int *)(&DAT_00773650 + iVar12) = iVar3;
            DAT_00783650 = DAT_00783650 + 1;
            FUN_006cebaa();
          }
          FUN_00405af0();
          local_8 = CONCAT31(local_8._1_3_,2);
          iStack_58 = 0x4785e1;
          FUN_00566460();
          iStack_58 = 0x4785e8;
          FUN_0056af90();
          FUN_0043fd30();
        }
        *(int *)(iVar2 + 0x2828) = *(int *)(iVar2 + 0x3bbc);
        *(int *)(iVar2 + 0x282c) = *(int *)(iVar2 + 0x3bc0);
        *(int *)(iVar2 + 0x2824) = *(int *)(iVar2 + 0x3bbc) + *(int *)(iVar2 + 0x3bc0);
        GetTickCount();
        FUN_0043fd30();
      }
    }
    if ((*(int *)(iVar10 + 4) < DAT_00c8ad70) &&
       (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad70 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00c8ad74 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 2";
      *(int *)(&DAT_00773650 + iVar12) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = 3;
    if ((*(char *)(iVar2 + 0x38f0) != '\0') && (iVar3 = FUN_005f8080(), *(int *)(iVar3 + 0x84) == 0)
       ) {
      FUN_00480ee0();
    }
    local_8 = 0xffffffff;
    FUN_0043fd30();
  }
  FUN_004750b0();
  if (0 < *(int *)(iVar2 + 0xa8)) {
    if ((*(int *)(iVar10 + 4) < DAT_00c8ad78) &&
       (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad78 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00c8ad7c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 5";
      *(int *)(&DAT_00773650 + iVar12) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = 4;
    iStack_58 = 0x4786f9;
    FUN_0057d980();
    iStack_58 = 0x478700;
    CFluid__Draw();
    FUN_0043fd30();
  }
  if ((*(int *)(iVar10 + 4) < DAT_00c8ad80) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad80 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00c8ad84 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 6";
    *(int *)(&DAT_00773650 + iVar12) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar12 = DAT_00c8ad84;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c8ad84 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar3 == 0) {
    uVar15 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar3 + 1;
  local_8 = 5;
  FUN_00464180();
  FUN_0043fd30();
  if ((*(char *)(iVar2 + 0x2839) == '\0') && (0 < *(int *)(iVar2 + 0xa8))) {
    if ((*(int *)(iVar10 + 4) < DAT_00c8ad88) &&
       (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad88 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00c8ad8c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 7";
      *(int *)(&DAT_00773650 + iVar12) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = 6;
    CDisplay__DrawObjects();
    if (DAT_00768390 != '\0') {
      FUN_00473590();
    }
    FUN_0043fd30();
  }
  if ((*(int *)(iVar10 + 4) < DAT_00c8ad90) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad90 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    _DAT_00c8ad94 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 8";
    *(int *)(&DAT_00773650 + iVar12) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = 7;
  FUN_0044d010();
  FUN_004e4550();
  FUN_004e45d0();
  local_8 = 0xffffffff;
  FUN_0043fd30();
  FUN_0044d010();
  FUN_004d8f20();
  if ((0 < *(int *)(iVar2 + 0xa8)) && (*(char *)(DAT_00772400 + 0x8c) == '\0')) {
    if ((*(int *)(iVar10 + 4) < DAT_00c8ad98) &&
       (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ad98 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00c8ad9c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 9";
      *(int *)(&DAT_00773650 + iVar12) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = 8;
    FUN_004c2b50();
    CScapeIconMgr__Draw();
    FUN_0043fd30();
  }
  if (DAT_0076a32b != '\0') {
    if ((*(int *)(iVar10 + 4) < DAT_00c8ada0) &&
       (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ada0 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00c8ada4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 10";
      *(int *)(&DAT_00773650 + iVar12) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    iVar3 = DAT_00772400;
    local_8 = 9;
    piVar6 = (int *)(DAT_00772400 + 0xa078);
    uVar13 = FUN_0055bfb0();
    if (uVar13 != 0xffffffff) {
      if (*(uint *)(iVar3 + 0xa07c) <= uVar13) {
        iStack_58 = 0x478934;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*(int *)(*piVar6 + 8 + uVar13 * 0x1c) == 1) {
        iStack_58 = 0x47895f;
        iStack_58 = FUN_0044d010();
        iStack_58 = iStack_58 + 0x7c;
        uStack_5c = 0x478968;
        FUN_004e4550();
        uStack_5c = 0x478970;
        FUN_004dd9d0();
      }
    }
    iVar3 = DAT_0076a324;
    if (*(char *)(DAT_0076a324 + 0x460c) == '\0') {
      iVar5 = *(int *)(DAT_0076a324 + 0x4610) + -0x20;
      *(undefined1 *)(DAT_0076a324 + 0x443c) = 0;
      iVar12 = 0;
      if (-1 < iVar5) {
        iVar12 = iVar5;
      }
    }
    else {
      iVar12 = *(int *)(DAT_0076a324 + 0x4610) + 0x20;
      *(undefined1 *)(DAT_0076a324 + 0x443c) = 1;
      if (0xff < iVar12) {
        iVar12 = 0xff;
      }
    }
    *(int *)(iVar3 + 0x4610) = iVar12;
    if (0 < iVar12) {
      FUN_00467ad0();
      iVar3 = DAT_0076a324;
    }
    if (*(char *)(iVar3 + 0x461c) != '\0') {
      FUN_00468370();
    }
    FUN_0043fd30();
  }
  if ((*(int *)(iVar10 + 4) < DAT_00c8ada8) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c8ada8 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    _DAT_00c8adac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CDisplay::Draw() 11";
    *(int *)(&DAT_00773650 + iVar12) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = 10;
  FUN_0047d000();
  local_8 = 0xffffffff;
  FUN_0043fd30();
  if (0 < *(int *)(DAT_00772400 + 0xa0e8)) {
    FUN_00467570();
    iVar12 = *(int *)(DAT_00772400 + 0xa0e8) + -2;
    iVar3 = 0;
    if (-1 < iVar12) {
      iVar3 = iVar12;
    }
    *(int *)(DAT_00772400 + 0xa0e8) = iVar3;
  }
  DVar7 = timeGetTime();
  iVar3 = DAT_00772400;
  DVar8 = timeGetTime();
  *(int *)(iVar3 + 0x1b0) = *(int *)(iVar3 + 0x1b0) + (DVar8 - DVar7);
  if (DAT_0076a2b6 != '\0') {
    FUN_0044d010();
    FUN_0044f440();
    iVar3 = FUN_0044d010();
    if (*(int *)(iVar3 + 0x30) != 0) {
      FUN_0044f440();
    }
    local_20 = 1;
    iVar12 = DAT_0076a31c;
    iVar3 = DAT_0076a314;
    do {
      if (0x5a < local_20) {
        iVar5 = 0x5b;
        puVar14 = (ushort *)(iVar3 + 0x3d8);
        do {
          iVar9 = (uint)puVar14[-800] +
                  (uint)puVar14[-0x322] + (uint)puVar14[-0x191] * -8 + (uint)puVar14[-0x321] +
                  (uint)puVar14[-0x192] + (uint)puVar14[-400] + (uint)puVar14[-2] +
                  (uint)puVar14[-1] + (uint)*puVar14;
          uVar13 = (uint)((int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3) >> 0xb & 0x1f;
          uVar11 = (ushort)uVar13 | (ushort)((uVar13 << 5 | uVar13) << 6);
          if (1000 < uVar11) {
            *(ushort *)(iVar12 + iVar5 * 2) = uVar11;
          }
          iVar5 = iVar5 + 1;
          puVar14 = puVar14 + 1;
        } while (iVar5 < 0x135);
      }
      iVar5 = DAT_0076a310;
      if (DAT_0076a310 < 0) {
        iVar5 = DAT_0076a310 + 1;
      }
      iVar3 = iVar3 + (iVar5 >> 1) * 2;
      iVar5 = DAT_0076a318;
      if (DAT_0076a318 < 0) {
        iVar5 = DAT_0076a318 + 1;
      }
      iVar12 = iVar12 + (iVar5 >> 1) * 2;
      local_20 = local_20 + 1;
    } while ((int)local_20 < 0xd2);
    iVar3 = FUN_0044d010();
    if ((*(int *)(iVar3 + 0x30) != 0) &&
       (piVar6 = *(int **)(*(int *)(iVar3 + 0x30) + 0x80), piVar6 != (int *)0x0)) {
      (**(code **)(*piVar6 + 0x44))();
    }
    iVar3 = FUN_0044d010();
    piVar6 = *(int **)(*(int *)(iVar3 + 0xbc) + 0x80);
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x44))();
    }
  }
  *(undefined4 *)(iVar2 + 0x2818) = *(undefined4 *)(iVar2 + 0x3bc4);
  *(undefined4 *)(iVar2 + 0x2824) = *(undefined4 *)(iVar2 + 0x3bb4);
  if ((*(int *)(iVar10 + 4) < DAT_00c8adb0) &&
     (FUN_006cebf4(), iVar2 = DAT_00783650, DAT_00c8adb0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    _DAT_00c8adb4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "CDisplay::Draw() 12";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = 0xb;
  FUN_00468eb0();
  FUN_00468900();
  local_8 = 0xffffffff;
  FUN_0043fd30();
  if (*(char *)(DAT_0076a324 + 0x12) != '\0') {
    if ((*(int *)(iVar10 + 4) < DAT_00c8adb8) &&
       (FUN_006cebf4(), iVar2 = DAT_00783650, DAT_00c8adb8 == -1)) {
      iVar10 = DAT_00783650 * 0x40;
      _DAT_00c8adbc = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar10) = "CDisplay::Draw() 13";
      *(int *)(&DAT_00773650 + iVar10) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = 0xc;
    FUN_0044d010();
    FUN_004ceff0();
    local_8 = 0xffffffff;
    FUN_0043fd30();
  }
  if (DAT_0076a33c == (undefined4 *)0x0) {
    DAT_0076a33c = (undefined4 *)FUN_006ba810();
    if (DAT_0076a33c == (undefined4 *)0x0) {
      DAT_0076a33c = (undefined4 *)0x0;
    }
    else {
      *DAT_0076a33c = 0;
      DAT_0076a33c[1] = 0;
    }
  }
  FUN_00484550();
  ExceptionList = local_10;
  return;
}

