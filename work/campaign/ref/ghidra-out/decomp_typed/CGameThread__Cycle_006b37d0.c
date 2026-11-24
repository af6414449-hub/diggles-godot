
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGameThread__Cycle(void)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  AchievementManager *this;
  HANDLE hThread;
  DWORD DVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int this;
  byte bVar11;
  int iVar12;
  float10 fVar13;
  float fVar14;
  double in_XMM0_Qa;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  undefined8 uVar20;
  undefined2 uVar21;
  undefined2 uVar22;
  undefined8 local_30;
  undefined1 local_25;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712d61;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  iVar12 = *ThreadLocalStoragePointer;
  local_30 = (double)CONCAT44(iVar12,(undefined4)local_30);
  local_14 = uVar5;
  if ((*(int *)(iVar12 + 4) < DAT_00ca7de8) &&
     (FUN_006cebf4(0x7de8), iVar6 = DAT_00783650, DAT_00ca7de8 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7dec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "CGameThread::Cycle()";
    *(int *)(&DAT_00773650 + iVar8) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(0x7de8);
  }
  iVar8 = DAT_00ca7dec;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7dec * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar9;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar6 == 0) {
    uVar20 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar6 + 1;
  local_8 = 0;
  if (*(int **)g_pServiceManager_exref != (int *)0x0) {
    (**(code **)(**(int **)g_pServiceManager_exref + 8))();
    if ((*(int *)(iVar12 + 4) < DAT_00ca7df0) && (FUN_006cebf4(0x7df0), DAT_00ca7df0 == -1)) {
      local_8._0_1_ = 1;
      DAT_00ca7df4 = TimeManager::GetInstance();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_006cebaa(0x7df0);
    }
    if ((*(int *)(iVar12 + 4) < DAT_00ca7df8) && (FUN_006cebf4(0x7df8), DAT_00ca7df8 == -1)) {
      local_8._0_1_ = 2;
      DAT_00ca7dfc = TimeManager::GetFreeTimerIndex(DAT_00ca7df4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_006cebaa(0x7df8);
    }
    if (DAT_00c3ca10 == '\0') {
      DAT_00c3ca10 = '\x01';
      TimeManager::SetTimer(DAT_00ca7df4,DAT_00ca7dfc,(ulonglong)uVar5 << 0x20);
    }
    bVar3 = TimeManager::IsAllowed(DAT_00ca7df4,DAT_00ca7dfc,(__int64 *)0x0);
    if (bVar3) {
      this = AchievementManager::GetInstance();
      AchievementManager::Store(this,9,0);
    }
  }
  FUN_005653f0();
  if (DAT_007683c8 == 0) {
    hThread = (LPVOID)0x0;
    if (DAT_00767964 != 0xffffffff) {
      hThread = TlsGetValue(DAT_00767964);
    }
    uVar21 = 0xffff;
    uVar22 = 0xffff;
  }
  else if ((DAT_007683c8 == 1) || (DAT_007683c8 != 2)) {
    hThread = (LPVOID)0x0;
    if (DAT_00767964 != 0xffffffff) {
      hThread = TlsGetValue(DAT_00767964);
    }
    uVar21 = 0;
    uVar22 = 0;
  }
  else {
    hThread = (LPVOID)0x0;
    if (DAT_00767964 != 0xffffffff) {
      hThread = TlsGetValue(DAT_00767964);
    }
    uVar21 = 2;
    uVar22 = 0;
  }
  SetThreadPriority(hThread,CONCAT22(uVar22,uVar21));
  GetTickCount();
  if (*(char *)(DAT_00772400 + 0x59a) != '\0') {
    uVar21 = (undefined2)this->i_34;
    FUN_0043ffe0(&DAT_00ca7e00,&DAT_007219c0,uVar21);
    FUN_004602b0(0x12,&DAT_00ca7e00,uVar21);
  }
  if ((DAT_007724b8 != (FILE *)0x0) &&
     (DVar7 = GetTickCount(), (int)(DAT_007724b0 + 30000) < (int)DVar7)) {
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    iVar12 = 0;
    iVar6 = 0;
    for (piVar1 = DAT_00c3c81c; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      if (10000000 < iVar6) {
LAB_006b3a9c:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        iVar12 = -1;
        goto LAB_006b3ab7;
      }
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      bVar3 = piVar1[6] != -0x10324e01 || *piVar1 != -0x4e005433;
      bVar11 = bVar3 | 2;
      if (*piVar1 != -0x20202021) {
        bVar11 = bVar3;
      }
      if (bVar11 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        goto LAB_006b3a9c;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      iVar8 = FUN_006ba730();
      if (iVar8 != 0) goto LAB_006b3a9c;
      iVar12 = iVar12 + piVar1[5];
      iVar6 = iVar6 + 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
LAB_006b3ab7:
    FUN_00405ab0(DAT_007724b8,"Heap check %d.%03d secs: %9d %8d\n",(int)DVar7 / 1000,
                 (int)DVar7 % 1000,iVar12,(short)((int)(iVar12 + (iVar12 >> 0x1f & 0x3ffU)) >> 10));
    DAT_007724b0 = DVar7;
    _fflush(DAT_007724b8);
    iVar12 = (int)local_30._4_4_;
  }
  if (this->c_39 == '\0') {
    DVar7 = GetTickCount();
    local_30 = (double)CONCAT44(DVar7,(undefined4)local_30);
    if (this->i_9c < (int)DVar7) {
      this->i_9c = this->i_9c + 1000;
      FUN_006b75e0();
    }
    if (this->i_a0 < (int)local_30._4_4_) {
      this->i_a0 = this->i_a0 + 0x19;
      FUN_0054df60();
    }
    if ((*(int *)(iVar12 + 4) < DAT_00ca7e10) && (FUN_006cebf4(0x7e10), DAT_00ca7e10 == -1)) {
      local_8._0_1_ = 3;
      if (DAT_00772400 != 0) {
        FUN_00565700(0x8958);
        iVar6 = _rand();
        in_XMM0_Qa = (double)iVar6 * _DAT_00768960 * 3.0517578125e-05;
        _DAT_00768958 = in_XMM0_Qa;
      }
      _atexit(FUN_007146e0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_006cebaa(&DAT_00ca7e10);
    }
    cVar4 = FUN_00565940();
    if (cVar4 != '\0') {
      if (DAT_00772408 == '\0') {
        if (DAT_00c1bf54 != '\0') {
          FUN_006c4310();
          DAT_00c1bf54 = '\0';
        }
      }
      else {
        if (DAT_00c1bf54 == '\0') {
          _DAT_00c1c768 = 0;
          local_24._0_2_ = 2;
          local_24[4] = '\0';
          local_24[5] = '\0';
          local_24[6] = '\0';
          local_24[7] = '\0';
          local_24._2_2_ = htons(0x1f92);
          DAT_00c1bf5c = socket(2,1,0);
          if (DAT_00c1bf5c != 0xffffffff) {
            bind(DAT_00c1bf5c,(sockaddr *)local_24,0x10);
            listen(DAT_00c1bf5c,5);
            DAT_00c1bf58 = WSACreateEvent();
            WSAEventSelect(DAT_00c1bf5c,DAT_00c1bf58,8);
            DAT_00c1c764 = 0;
            DAT_00c1bf60 = 0;
          }
          DAT_00c1bf54 = '\x01';
        }
        FUN_00564d40();
      }
    }
    if ((*(int *)(iVar12 + 4) < DAT_00ca7e14) &&
       (FUN_006cebf4(0x7e14), iVar6 = DAT_00783650, DAT_00ca7e14 == -1)) {
      iVar8 = DAT_00783650 * 0x40;
      _DAT_00ca7e18 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar8) = "CNetMgr::Get().Tick();";
      *(int *)(&DAT_00773650 + iVar8) = iVar6;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(0x7e14);
    }
    FUN_00405af0(0x7e18);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_005b28d0();
    FUN_005b2ee0();
    FUN_0043fd30();
    if ((*(int *)(iVar12 + 4) < DAT_00ca7e1c) &&
       (FUN_006cebf4(0x7e1c), iVar6 = DAT_00783650, DAT_00ca7e1c == -1)) {
      iVar8 = DAT_00783650 * 0x40;
      _DAT_00ca7e20 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar8) = "CGameThread::Cycle() SrvDoThink";
      *(int *)(&DAT_00773650 + iVar8) = iVar6;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(0x7e1c);
    }
    FUN_00405af0(0x7e20);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_0043e3c0();
    CGameThread__SrvDoThink();
    FUN_0043e3c0();
    FUN_0043fd30();
    if ((*(int *)(iVar12 + 4) < DAT_00ca7e24) &&
       (FUN_006cebf4(0x7e24), iVar6 = DAT_00783650, DAT_00ca7e24 == -1)) {
      iVar8 = DAT_00783650 * 0x40;
      _DAT_00ca7e28 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar8) = "CGameThread::Cycle() DoRenderTick";
      *(int *)(&DAT_00773650 + iVar8) = iVar6;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(0x7e24);
    }
    FUN_00405af0(0x7e28);
    FUN_0043fd30();
    if ((*(int *)(iVar12 + 4) < DAT_00ca7e2c) &&
       (FUN_006cebf4(0x7e2c), iVar6 = DAT_00783650, DAT_00ca7e2c == -1)) {
      iVar8 = DAT_00783650 * 0x40;
      _DAT_00ca7e30 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar8) = "CGameThread::Cycle() Draw";
      *(int *)(&DAT_00773650 + iVar8) = iVar6;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(0x7e2c);
    }
    FUN_00405af0(0x7e30);
    local_8 = CONCAT31(local_8._1_3_,6);
    CGameThread__Draw();
    FUN_0043fd30();
    if (*(char *)(DAT_00772400 + 0x93) == '\0') {
      Sleep(400);
      local_25 = 1;
    }
    else {
      if ((*(int *)(iVar12 + 4) < DAT_00ca7e34) &&
         (FUN_006cebf4(0x7e34), iVar12 = DAT_00783650, DAT_00ca7e34 == -1)) {
        iVar6 = DAT_00783650 * 0x40;
        _DAT_00ca7e38 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar6) = "CGameThread::Cycle() Sleep";
        *(int *)(&DAT_00773650 + iVar6) = iVar12;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(0x7e34);
      }
      FUN_00405af0(0x7e38);
      FUN_0043e3c0();
      if (DAT_00c3ca08 == 0.0) {
        DAT_00c3ca08 = in_XMM0_Qa - 0.01;
      }
      if (DAT_00c3ca00 == 0.0) {
        DAT_00c3ca00 = in_XMM0_Qa - 0.01;
      }
      dVar15 = (in_XMM0_Qa - DAT_00c3ca00) * 1000.0;
      dVar19 = (in_XMM0_Qa - DAT_00c3ca08) * 1000.0;
      dVar17 = 1.0;
      if (1.0 <= dVar15) {
        dVar17 = dVar15;
      }
      fVar14 = DAT_0076837c;
      if (DAT_0076837c <= 1.0) {
        fVar14 = 1.0;
      }
      dVar15 = (double)(1000.0 / fVar14);
      dVar16 = (dVar15 - dVar19) * 0.99 - 2.0;
      local_24._8_8_ = in_XMM0_Qa;
      if (1.0 <= DAT_00c3c9f8) {
        fVar13 = (float10)FUN_006f6da0(SUB84(DAT_00c3c9f8,0),
                                       (short)((ulonglong)DAT_00c3c9f8 >> 0x20));
        local_30 = (double)fVar13;
        DAT_00c3c9f8 = DAT_00c3c9f8 - local_30;
      }
      dVar18 = (double)DAT_007683cc;
      if ((double)DAT_007683cc <= dVar16) {
        dVar18 = dVar16;
      }
      DAT_007687e0 = DAT_007687e0 * 0.9 + dVar18 * 0.1;
      DAT_00c3c9f8 = (dVar18 - dVar18) + DAT_00c3c9f8;
      DAT_007687d8 = (1000.0 / dVar17) * 0.002 + DAT_007687d8 * 0.998;
      *(float *)(DAT_00772400 + 0x1ac) =
           (float)((dVar19 / dVar15) * 0.05000000074505806 +
                  (double)(*(float *)(DAT_00772400 + 0x1ac) * 0.95));
      dVar16 = 1.0 - dVar18 / dVar15;
      dVar19 = 0.0;
      if (0.0 <= dVar16) {
        dVar19 = dVar16;
      }
      dVar16 = 1.0;
      if (dVar19 <= 1.0) {
        dVar16 = dVar19;
      }
      DAT_007687d0 = dVar16 * 0.1 + DAT_007687d0 * 0.9;
      FUN_0043e3c0();
      fVar14 = (float)dVar18;
      dVar16 = (double)(ulonglong)(uint)fVar14;
      local_30 = (double)CONCAT44(fVar14,(undefined4)local_30);
      DAT_00772dd8 = (DWORD)ROUND(fVar14);
      Sleep(DAT_00772dd8);
      FUN_0043e3c0();
      dVar19 = dVar16;
      FUN_0043e3c0();
      dVar19 = (dVar19 - dVar16) * 1000.0 * 0.1;
      DAT_00c3c9e8 = DAT_00c3c9e8 * 0.9 + dVar19;
      FUN_0043e3c0();
      _DAT_00c3c9f0 = dVar19;
      FUN_0043e3c0();
      _DAT_007687c8 = dVar17 - dVar15;
      DAT_00c3ca00 = (double)local_24._8_8_;
      dVar17 = 0.0;
      if ((_DAT_007687c8 < 0.0) || (dVar17 = 20.0, 20.0 < _DAT_007687c8)) {
        _DAT_007687c8 = dVar17;
      }
      DAT_00c3ca08 = dVar19;
      FUN_0043fd30();
      local_25 = 1;
    }
  }
  else {
    uVar9 = FUN_004435d0((int)&local_30 + 4,0x5f50);
    piVar10 = (int *)FUN_00443730(uVar9);
    iVar12 = DAT_00772400;
    local_8._0_1_ = 7;
    piVar1 = (int *)*piVar10;
    piVar2 = *(int **)(DAT_00772400 + 0x5b4);
    *(int **)(DAT_00772400 + 0x5b4) = piVar1;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar12 + 0x5b4) + 8) = *(undefined4 *)(*piVar10 + 8);
    local_8._0_1_ = 8;
    if ((local_30._4_4_ != (int *)0x0) &&
       (*local_30._4_4_ = *local_30._4_4_ + -1, *local_30._4_4_ == 0)) {
      FUN_006ba940();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_006b9200(0xce50);
    FUN_00479c10(0,1);
    local_25 = 0;
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

