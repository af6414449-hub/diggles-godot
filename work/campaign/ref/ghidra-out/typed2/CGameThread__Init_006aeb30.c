
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameThread__Init(CGameThread *this)

{
  float fVar1;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  code *pcVar4;
  CGameThread *pCVar5;
  CDisplay *pCVar6;
  char cVar7;
  int iVar8;
  DWORD DVar9;
  int *piVar10;
  AchievementManager *this_00;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar11;
  undefined4 uVar12;
  int iVar13;
  errno_t eVar14;
  uint uVar15;
  DisplayModeManager *this_01;
  DisplayIndexManager *this_02;
  BOOL BVar16;
  HANDLE hThread;
  LPCSTR lpCaption;
  int iVar17;
  undefined1 uVar18;
  char *pcVar19;
  int *piVar20;
  undefined4 extraout_ECX;
  undefined1 *puVar21;
  CDisplay *pCVar22;
  CDisplay *pCVar23;
  double dVar24;
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  tagRECT tVar39;
  undefined1 auVar40 [16];
  undefined8 uVar41;
  longlong lVar42;
  UINT uType;
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  tagPOINT local_1a4;
  double local_19c;
  undefined8 local_194;
  undefined8 local_18c;
  CDisplay *local_184;
  CDisplay *local_180;
  CGameThread *local_17c;
  int local_178;
  undefined8 local_174;
  char local_16a;
  char local_169;
  undefined1 *local_168;
  CDisplay *local_164;
  CDisplay *local_160;
  CDisplay *local_15c;
  CDisplay *local_158;
  CDisplay *local_154;
  CDisplay *local_150;
  CDisplay *local_14c;
  undefined4 local_148;
  undefined2 local_144 [2];
  undefined2 local_140 [2];
  undefined1 local_13c [4];
  undefined1 local_138 [4];
  undefined1 local_134 [4];
  undefined1 local_130 [4];
  undefined1 local_12c [4];
  undefined1 local_128 [16];
  char local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712c11;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_169 = '\0';
  local_16a = '\0';
                    /* WARNING: Load size is inaccurate */
  local_178 = *ThreadLocalStoragePointer;
  local_17c = this;
  if ((*(int *)(local_178 + 4) < DAT_00ca7d40) &&
     (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7d40 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    DAT_00ca7d44 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init()";
    *(int *)(&DAT_00773650 + iVar13) = iVar8;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar13 = DAT_00ca7d44;
  uVar12 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d44 * 0x40);
  iVar8 = FUN_0043fcc0();
  *(undefined4 *)(iVar8 + *(int *)(iVar8 + 0x8000) * 4) = uVar12;
  *(int *)(iVar8 + 0x8000) = *(int *)(iVar8 + 0x8000) + 1;
  iVar8 = (&DAT_00773654)[iVar13 * 0x10];
  if (iVar8 == 0) {
    uVar41 = FUN_006bd180();
    iVar8 = (&DAT_00773654)[iVar13 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar13 * 0x10) = uVar41;
  }
  (&DAT_00773654)[iVar13 * 0x10] = iVar8 + 1;
  local_8 = 0;
  DVar9 = GetFileAttributesW(L"data/Gamesave");
  if ((DVar9 == 0xffffffff) || ((DVar9 & 0x10) == 0)) {
    CreateDirectoryW(L"data/Gamesave",(LPSECURITY_ATTRIBUTES)0x0);
  }
  FUN_006be780();
  __getcwd(local_118,0x104);
  pcVar19 = local_118;
  do {
    cVar7 = *pcVar19;
    pcVar19 = pcVar19 + 1;
  } while (cVar7 != '\0');
  local_14c = (CDisplay *)(pcVar19 + -(int)(local_118 + 1));
  iVar8 = (int)local_14c + 1;
  if (iVar8 < 4) {
    iVar8 = 4;
  }
  local_164 = (CDisplay *)FUN_006ba810();
  *(uint *)&local_164->field_0x4 = (iVar8 + 0xbU & 0xfffffff0) + 4;
  *(undefined4 *)&local_164->field_0x8 = 0xffffffff;
  *(int *)local_164 = 0;
  local_164->field_0xc = 0;
  local_174._4_4_ = local_164;
  FUN_006d2250();
  pCVar23 = local_174._4_4_;
  *(CDisplay **)&(local_174._4_4_)->field_0x8 = local_14c;
  *(int *)local_174._4_4_ = *(int *)local_174._4_4_ + 1;
  local_8._0_1_ = 1;
  piVar10 = (int *)FUN_006ba810();
  piVar10[1] = 0x14;
  piVar10[2] = -1;
  *piVar10 = 0;
  *(undefined1 *)(piVar10 + 3) = 0;
  piVar10[3] = 0x6b726f57;
  piVar10[4] = 0x44676e69;
  *(undefined2 *)(piVar10 + 5) = 0x7269;
  *(undefined1 *)((int)piVar10 + 0x16) = 0;
  piVar10[2] = 10;
  if (piVar10 != (int *)0x0) {
    *piVar10 = *piVar10 + 1;
  }
  iVar8 = FUN_006bfc00();
  local_8._0_1_ = 2;
  piVar10 = *(int **)(iVar8 + 0xc);
  *(CDisplay **)(iVar8 + 0xc) = pCVar23;
  *(int *)pCVar23 = *(int *)pCVar23 + 1;
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar8 + 0xc) + 8) = *(undefined4 *)&pCVar23->field_0x8;
  local_8._0_1_ = 3;
  *(int *)pCVar23 = *(int *)pCVar23 + -1;
  if (*(int *)pCVar23 == 0) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  this_00 = AchievementManager::GetInstance();
  AchievementManager::Store(this_00,9,0);
  pcVar4 = g_SteamManager_exref;
  *(code **)g_pServiceManager_exref = g_SteamManager_exref;
  if (pcVar4 != (code *)0x0) {
    (*(code *)**(undefined4 **)pcVar4)();
  }
  if ((*(int *)(local_178 + 4) < DAT_00ca7d48) &&
     (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7d48 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    DAT_00ca7d4c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() TclInit";
    *(int *)(&DAT_00773650 + iVar13) = iVar8;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar13 = DAT_00ca7d4c;
  local_164 = (CDisplay *)&DAT_00ca7d4c;
  uVar12 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d4c * 0x40);
  iVar8 = FUN_0043fcc0();
  *(undefined4 *)(iVar8 + *(int *)(iVar8 + 0x8000) * 4) = uVar12;
  *(int *)(iVar8 + 0x8000) = *(int *)(iVar8 + 0x8000) + 1;
  iVar8 = (&DAT_00773654)[iVar13 * 0x10];
  if (iVar8 == 0) {
    uVar41 = FUN_006bd180();
    iVar8 = (&DAT_00773654)[iVar13 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar13 * 0x10) = uVar41;
  }
  (&DAT_00773654)[iVar13 * 0x10] = iVar8 + 1;
  local_8._0_1_ = 4;
  if (DAT_00772dd0 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_006ba810();
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    else {
      InitializeCriticalSection(lpCriticalSection);
      *(undefined1 *)&lpCriticalSection[1].DebugInfo = 0;
      lpCriticalSection[1].LockCount = 0;
      lpCriticalSection[1].RecursionCount = 0;
    }
    DAT_00772dd0 = lpCriticalSection;
    lpCriticalSection[1].OwningThread = (HANDLE)0x0;
    lpCriticalSection[1].LockSemaphore = (HANDLE)0x0;
  }
  piVar10 = (int *)FUN_006ba810();
  piVar10[1] = 0x14;
  piVar10[2] = -1;
  *piVar10 = 0;
  *(undefined1 *)(piVar10 + 3) = 0;
  piVar10[3] = 0x446c6354;
  piVar10[4] = 0x6e696665;
  *(undefined2 *)(piVar10 + 5) = 0x7365;
  *(undefined1 *)((int)piVar10 + 0x16) = 0;
  piVar10[2] = 10;
  if (piVar10 != (int *)0x0) {
    *piVar10 = *piVar10 + 1;
  }
  puVar11 = (undefined4 *)FUN_006bfec0();
  local_15c = (CDisplay *)*puVar11;
  if (local_15c != (CDisplay *)0x0) {
    *(int *)local_15c = *(int *)local_15c + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_160 = *(CDisplay **)((int)local_15c + 8);
  if (local_160 == (CDisplay *)0xffffffff) {
    piVar10 = (int *)((int)local_15c + 0xc);
    do {
      iVar8 = *piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
    } while ((char)iVar8 != '\0');
    local_160 = (CDisplay *)((int)piVar10 - ((int)local_15c + 0xd));
    *(CDisplay **)((int)local_15c + 8) = local_160;
  }
  piVar10 = (int *)((int)local_15c + 0xc);
  local_154 = local_160;
  if (local_160 == (CDisplay *)0xffffffff) {
    do {
      iVar8 = *piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
    } while ((char)iVar8 != '\0');
    local_154 = (CDisplay *)((int)piVar10 - ((int)local_15c + 0xd));
    *(CDisplay **)((int)local_15c + 8) = local_154;
  }
  puVar21 = &local_154->field_0x1;
  piVar10 = (int *)FUN_006b8df0();
  *(undefined2 *)(&local_154->field_0xc + (int)piVar10) = 0x20;
  piVar10[2] = (int)puVar21;
  local_15c = (CDisplay *)piVar10;
  if (0 < (int)local_160) {
    puVar21 = (undefined1 *)0x0;
    pCVar23 = local_160;
    do {
      iVar8 = piVar10[2];
      if (iVar8 == -1) {
        piVar20 = piVar10 + 3;
        local_14c = (CDisplay *)((int)piVar10 + 0xd);
        do {
          iVar8 = *piVar20;
          piVar20 = (int *)((int)piVar20 + 1);
        } while ((char)iVar8 != '\0');
        iVar8 = (int)piVar20 - (int)local_14c;
        piVar10[2] = iVar8;
        pCVar23 = local_160;
      }
      if ((int)puVar21 < iVar8) {
        iVar8 = FUN_006d0190();
        pCVar23 = local_160;
        if (iVar8 == 0) {
          pCVar22 = (CDisplay *)0xffffffff;
        }
        else {
          local_174._4_4_ = (CDisplay *)((iVar8 - (int)piVar10) + -0xc);
          pCVar22 = local_174._4_4_;
          if (local_174._4_4_ != (CDisplay *)0xffffffff) {
            FUN_006b9b20();
            local_8 = CONCAT31(local_8._1_3_,6);
            FUN_006b9cb0();
            FUN_006b9d80();
            pCVar23 = local_154;
            iVar8 = *(int *)&local_154->field_0x8;
            if (iVar8 == -1) {
              pcVar19 = &local_154->field_0xc;
              do {
                cVar7 = *pcVar19;
                pcVar19 = pcVar19 + 1;
              } while (cVar7 != '\0');
              iVar8 = (int)pcVar19 - (int)&local_154->field_0xd;
              *(int *)&local_154->field_0x8 = iVar8;
            }
            if ((0 < iVar8) && (cVar7 = FUN_006bacf0(), cVar7 == '\0')) {
              FUN_00444ca0();
              local_14c = (CDisplay *)(DAT_00c3c7a8 - 1);
              if (DAT_00c3c7a8 <= local_14c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              FUN_006b9200();
            }
            local_8._0_1_ = 7;
            *(int *)pCVar23 = *(int *)pCVar23 + -1;
            if (*(int *)pCVar23 == 0) {
              FUN_006ba940();
            }
            local_8 = CONCAT31(local_8._1_3_,5);
            pCVar23 = local_160;
            pCVar22 = local_174._4_4_;
          }
        }
      }
      else {
        pCVar22 = (CDisplay *)0xffffffff;
      }
      puVar21 = &pCVar22->field_0x1;
    } while ((int)puVar21 < (int)pCVar23);
  }
  cVar7 = FUN_006bacf0();
  if (cVar7 == '\0') {
    FUN_00444ca0();
    if (DAT_00c3c7a8 <= DAT_00c3c7a8 - 1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_006b9200();
  }
  local_8._0_1_ = 8;
  *piVar10 = *piVar10 + -1;
  if (*piVar10 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 4;
  FUN_005c7410();
  puVar11 = (undefined4 *)FUN_005d9170();
  local_8._0_1_ = 9;
  local_150 = (CDisplay *)puVar11;
  if (puVar11 != (undefined4 *)0x0) {
    FUN_005c83f0();
    local_8 = CONCAT31(local_8._1_3_,10);
    *puVar11 = CObj_World::vftable;
    FUN_006b9200();
    piVar10 = (int *)FUN_006ba810();
    piVar10[1] = 0x14;
    piVar10[2] = -1;
    *piVar10 = 0;
    *(undefined1 *)(piVar10 + 3) = 0;
    piVar10[3] = 0x6a624f43;
    piVar10[4] = 0x726f575f;
    *(undefined2 *)(piVar10 + 5) = 0x646c;
    *(undefined1 *)((int)piVar10 + 0x16) = 0;
    piVar10[2] = 10;
    local_154 = DAT_00772478;
    *piVar10 = 1;
    local_14c = (CDisplay *)piVar10;
    cVar7 = FUN_006037d0();
    if (cVar7 == '\0') {
      uVar12 = 0;
    }
    else {
      if (*(int **)&local_154->field_0x801c <= local_15c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar12 = *(undefined4 *)(*(int *)&local_154->field_0x8018 + (int)local_15c * 4);
    }
    puVar11[0x35] = uVar12;
    local_8._0_1_ = 0xb;
    *piVar10 = *piVar10 + -1;
    if (*piVar10 == 0) {
      FUN_006ba940();
    }
    puVar11[0xde] = 0;
    puVar11[0xdb] = 0xffffffff;
  }
  local_8._0_1_ = 4;
  FUN_005d2370();
  puVar11 = (undefined4 *)FUN_005d9170();
  local_8._0_1_ = 0xc;
  local_150 = (CDisplay *)puVar11;
  if (puVar11 != (undefined4 *)0x0) {
    FUN_005c83f0();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    *puVar11 = CObj_DigTask::vftable;
    FUN_006b9200();
    piVar10 = (int *)FUN_006ba810();
    piVar10[1] = 0x14;
    piVar10[2] = -1;
    *piVar10 = 0;
    *(undefined1 *)(piVar10 + 3) = 0;
    piVar10[3] = 0x6a624f43;
    piVar10[4] = 0x6769445f;
    piVar10[5] = 0x6b736154;
    *(undefined1 *)(piVar10 + 6) = 0;
    piVar10[2] = 0xc;
    local_154 = DAT_00772478;
    *piVar10 = 1;
    local_14c = (CDisplay *)piVar10;
    cVar7 = FUN_006037d0();
    if (cVar7 == '\0') {
      uVar12 = 0;
    }
    else {
      if (*(int **)&local_154->field_0x801c <= local_15c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar12 = *(undefined4 *)(*(int *)&local_154->field_0x8018 + (int)local_15c * 4);
    }
    puVar11[0x35] = uVar12;
    local_8._0_1_ = 0xe;
    *piVar10 = *piVar10 + -1;
    if (*piVar10 == 0) {
      FUN_006ba940();
    }
    puVar11[0xde] = 0;
    puVar11[0xdb] = 0xffffffff;
    puVar11[0xf4] = 0x401;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005d2370();
  FUN_0043fd30();
  iVar8 = local_178;
  if ((*(int *)(local_178 + 4) < DAT_00ca7d50) &&
     (FUN_006cebf4(), iVar13 = DAT_00783650, DAT_00ca7d50 == -1)) {
    iVar17 = DAT_00783650 * 0x40;
    DAT_00ca7d54 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar17) = "CGameThread::Init() Map";
    *(int *)(&DAT_00773650 + iVar17) = iVar13;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  local_14c = (CDisplay *)(DAT_00ca7d54 * 0x40);
  local_164 = (CDisplay *)&DAT_00ca7d54;
  uVar12 = *(undefined4 *)(&DAT_00773650 + (int)local_14c);
  iVar13 = FUN_0043fcc0();
  pCVar23 = local_14c;
  *(undefined4 *)(iVar13 + *(int *)(iVar13 + 0x8000) * 4) = uVar12;
  *(int *)(iVar13 + 0x8000) = *(int *)(iVar13 + 0x8000) + 1;
  iVar13 = *(int *)((int)&DAT_00773654 + (int)local_14c);
  if (iVar13 == 0) {
    uVar41 = FUN_006bd180();
    iVar13 = *(int *)((int)&DAT_00773654 + (int)pCVar23);
    *(undefined8 *)((int)&DAT_00773658 + (int)pCVar23) = uVar41;
  }
  *(int *)((int)&DAT_00773654 + (int)pCVar23) = iVar13 + 1;
  local_8._0_1_ = 0xf;
  local_150 = (CDisplay *)FUN_006ba810();
  local_8 = CONCAT31(local_8._1_3_,0x10);
  if (local_150 == (CDisplay *)0x0) {
    PTR_0077241c = (CMap *)0x0;
  }
  else {
    PTR_0077241c = (CMap *)FUN_005939b0((CMap *)local_150);
  }
  FUN_0043fd30();
  if ((*(int *)(iVar8 + 4) < DAT_00ca7d58) &&
     (FUN_006cebf4(), iVar13 = DAT_00783650, DAT_00ca7d58 == -1)) {
    iVar17 = DAT_00783650 * 0x40;
    DAT_00ca7d5c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar17) = "CGameThread::Init() Options";
    *(int *)(&DAT_00773650 + iVar17) = iVar13;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  local_14c = (CDisplay *)(DAT_00ca7d5c * 0x40);
  local_164 = (CDisplay *)&DAT_00ca7d5c;
  uVar12 = *(undefined4 *)(&DAT_00773650 + (int)local_14c);
  iVar13 = FUN_0043fcc0();
  pCVar23 = local_14c;
  *(undefined4 *)(iVar13 + *(int *)(iVar13 + 0x8000) * 4) = uVar12;
  *(int *)(iVar13 + 0x8000) = *(int *)(iVar13 + 0x8000) + 1;
  iVar13 = *(int *)((int)&DAT_00773654 + (int)local_14c);
  if (iVar13 == 0) {
    uVar41 = FUN_006bd180();
    iVar13 = *(int *)((int)&DAT_00773654 + (int)pCVar23);
    *(undefined8 *)((int)&DAT_00773658 + (int)pCVar23) = uVar41;
  }
  *(int *)((int)&DAT_00773654 + (int)pCVar23) = iVar13 + 1;
  local_8._0_1_ = 0x11;
  eVar14 = __wfopen_s(&DAT_00c3ca14,L"data/ldat",L"r");
  if ((eVar14 == 0) && (DAT_00c3ca14 != (FILE *)0x0)) {
    _fseek(DAT_00c3ca14,0,2);
    uVar15 = FUN_006de91d();
    _fseek(DAT_00c3ca14,0,0);
    if (uVar15 < 4) goto LAB_006af608;
    local_154 = (CDisplay *)0xffffffff;
    _fread(&local_154,4,1,DAT_00c3ca14);
    _fclose(DAT_00c3ca14);
    DAT_00c3ca14 = (FILE *)0x0;
    switch(local_154) {
    case (CDisplay *)0x0:
      break;
    case (CDisplay *)0x1:
      break;
    case (CDisplay *)0x2:
      break;
    case (CDisplay *)0x3:
      break;
    default:
      goto LAB_006af608;
    }
    local_14c = (CDisplay *)FUN_006b8fb0();
    iVar13 = DAT_00772400;
    local_8._0_1_ = 0x12;
    piVar10 = *(int **)local_14c;
    piVar20 = *(int **)(DAT_00772400 + 0xc);
    *(int **)(DAT_00772400 + 0xc) = piVar10;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    if ((piVar20 != (int *)0x0) && (*piVar20 = *piVar20 + -1, *piVar20 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar13 + 0xc) + 8) = *(undefined4 *)(*(int *)local_14c + 8);
    local_8 = CONCAT31(local_8._1_3_,0x13);
    pCVar23 = local_174._4_4_;
LAB_006af5f1:
    if ((pCVar23 != (CDisplay *)0x0) &&
       (*(int *)pCVar23 = *(int *)pCVar23 + -1, *(int *)pCVar23 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x11;
  }
  else {
LAB_006af608:
    if ((*(int **)g_pServiceManager_exref != (int *)0x0) &&
       (iVar13 = (**(code **)(**(int **)g_pServiceManager_exref + 0x54))(), iVar13 != 0)) {
      local_14c = (CDisplay *)FUN_006b8fb0();
      iVar13 = DAT_00772400;
      local_8._0_1_ = 0x14;
      piVar10 = *(int **)local_14c;
      piVar20 = *(int **)(DAT_00772400 + 0xc);
      *(int **)(DAT_00772400 + 0xc) = piVar10;
      if (piVar10 != (int *)0x0) {
        *piVar10 = *piVar10 + 1;
      }
      if ((piVar20 != (int *)0x0) && (*piVar20 = *piVar20 + -1, *piVar20 == 0)) {
        FUN_006ba940();
      }
      *(undefined4 *)(*(int *)(iVar13 + 0xc) + 8) = *(undefined4 *)(*(int *)local_14c + 8);
      local_8 = CONCAT31(local_8._1_3_,0x15);
      pCVar23 = local_154;
      goto LAB_006af5f1;
    }
    FUN_006b8fb0();
    local_14c = (CDisplay *)FUN_006bfec0();
    iVar13 = DAT_00772400;
    piVar10 = *(int **)local_14c;
    piVar20 = *(int **)(DAT_00772400 + 0xc);
    *(int **)(DAT_00772400 + 0xc) = piVar10;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    if ((piVar20 != (int *)0x0) && (*piVar20 = *piVar20 + -1, *piVar20 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar13 + 0xc) + 8) = *(undefined4 *)(*(int *)local_14c + 8);
  }
  iVar17 = DAT_00772400;
  iVar13 = *(int *)(DAT_00772400 + 0xc);
  if (*(int *)(iVar13 + 8) == -1) {
    pcVar19 = (char *)(iVar13 + 0xc);
    local_14c = (CDisplay *)(iVar13 + 0xd);
    do {
      cVar7 = *pcVar19;
      pcVar19 = pcVar19 + 1;
    } while (cVar7 != '\0');
    *(int *)(iVar13 + 8) = (int)pcVar19 - (int)local_14c;
    iVar13 = *(int *)(iVar17 + 0xc);
  }
  if (*(int *)(iVar13 + 8) == 0) {
    FUN_006b9200();
  }
  FUN_006b8fb0();
  local_8._0_1_ = 0x16;
  piVar10 = (int *)FUN_006ba810();
  piVar10[1] = 0x14;
  piVar10[2] = -1;
  *piVar10 = 0;
  *(undefined1 *)(piVar10 + 3) = 0;
  piVar10[3] = 0x676e614c;
  piVar10[4] = 0x65676175;
  *(undefined1 *)(piVar10 + 5) = 0;
  piVar10[2] = 8;
  if (piVar10 != (int *)0x0) {
    *piVar10 = *piVar10 + 1;
  }
  iVar13 = FUN_006bfc00();
  local_8._0_1_ = 0x17;
  piVar10 = *(int **)(iVar13 + 0xc);
  *(CDisplay **)(iVar13 + 0xc) = local_160;
  if (local_160 != (CDisplay *)0x0) {
    *(int *)local_160 = *(int *)local_160 + 1;
  }
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar13 + 0xc) + 8) = *(undefined4 *)&local_160->field_0x8;
  local_8._0_1_ = 0x18;
  if ((local_160 != (CDisplay *)0x0) &&
     (*(int *)local_160 = *(int *)local_160 + -1, *(int *)local_160 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_00558770();
  iVar13 = DAT_00772400;
  local_19c = 0.0;
  *(undefined1 *)(DAT_00772400 + 0x8a) = 0;
  *(undefined4 *)(iVar13 + 0xa0b0) = 0;
  *(undefined4 *)(iVar13 + 0xa0b4) = 0;
  *(undefined4 *)(iVar13 + 0xa0b8) = 0;
  *(undefined4 *)(iVar13 + 0xa0bc) = 0;
  *(undefined4 *)(iVar13 + 0x150) = 0;
  *(undefined4 *)(iVar13 + 0x154) = 0;
  *(undefined4 *)(iVar13 + 0x158) = 0;
  *(undefined4 *)(iVar13 + 0x15c) = 0;
  *(undefined4 *)(iVar13 + 0x160) = 0;
  *(undefined4 *)(iVar13 + 0x164) = 0;
  *(undefined4 *)(iVar13 + 0x168) = 0;
  *(undefined4 *)(iVar13 + 0x16c) = 0;
  iVar13 = FUN_006d02c0();
  if (iVar13 == 0) {
    FUN_0055c760();
  }
  else {
    DAT_0076837c = 0x43480000;
    DAT_00768384 = 4;
    DAT_00768388 = 2;
    DAT_0076838c = 2;
  }
  dVar24 = 1.0;
  local_18c = 0x3ff0000000000000;
  iVar13 = DAT_00772400;
  if (*(char *)(DAT_00772400 + 0x599) != '\0') {
    local_150 = (CDisplay *)&stack0xfffffe38;
    dVar24 = 1.0;
    FUN_006b8fb0();
    local_8._0_1_ = 0x19;
    FUN_006b8fb0();
    FUN_006bfc00();
    local_8 = CONCAT31(local_8._1_3_,0x11);
    FUN_006bee00();
    iVar13 = DAT_00772400;
    *(bool *)(DAT_00772400 + 0x599) = local_19c != dVar24;
  }
  if (*(char *)(iVar13 + 0x59a) != '\0') {
    local_150 = (CDisplay *)&stack0xfffffe38;
    FUN_006b8fb0();
    local_8._0_1_ = 0x1a;
    FUN_006b8fb0();
    FUN_006bfc00();
    local_8 = CONCAT31(local_8._1_3_,0x11);
    FUN_006bee00();
    *(bool *)(DAT_00772400 + 0x59a) = local_19c != dVar24;
  }
  dVar24 = 17500.0;
  local_150 = (CDisplay *)&stack0xfffffe38;
  FUN_006b8fb0();
  local_8._0_1_ = 0x1b;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  local_14c = (CDisplay *)(float)dVar24;
  DAT_00772dd8 = (CDisplay *)(int)ROUND((float)local_14c);
  dVar24 = 800.0;
  local_174 = 0x4089000000000000;
  *(CDisplay **)(DAT_00772400 + 0x5bc) = DAT_00772dd8;
  local_150 = (CDisplay *)&stack0xfffffe34;
  FUN_006b8fb0();
  local_8._0_1_ = 0x1c;
  FUN_006b8fb0("Screen");
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bef50();
  local_14c = (CDisplay *)(float)dVar24;
  DAT_00772dd8 = (CDisplay *)(int)ROUND((float)local_14c);
  auVar25 = ZEXT816(0x4082c00000000000);
  *(CDisplay **)(DAT_00772400 + 0x170) = DAT_00772dd8;
  local_150 = (CDisplay *)&stack0xfffffe34;
  FUN_006b8fb0();
  local_8._0_1_ = 0x1d;
  FUN_006b8fb0("Screen");
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bef50();
  auVar25._0_4_ = (float)auVar25._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar25._0_4_);
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(CDisplay **)(DAT_00772400 + 0x174) = DAT_00772dd8;
  local_14c = (CDisplay *)auVar25._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x1e;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(bool *)(DAT_00772400 + 0x178) = local_19c != auVar25._0_8_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x1f;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  auVar26._4_12_ = auVar25._4_12_;
  auVar26._0_4_ = (float)auVar25._0_8_;
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(float *)(DAT_00772400 + 0x18c) = auVar26._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x20;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  auVar27._4_12_ = auVar26._4_12_;
  auVar27._0_4_ = (float)auVar26._0_8_;
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(float *)(DAT_00772400 + 400) = auVar27._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x21;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  auVar28._4_12_ = auVar27._4_12_;
  auVar28._0_4_ = (float)auVar27._0_8_;
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(float *)(DAT_00772400 + 0x194) = auVar28._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x22;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  auVar29._4_12_ = auVar28._4_12_;
  auVar29._0_4_ = (float)auVar28._0_8_;
  dVar24 = auVar29._0_8_;
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(float *)(DAT_00772400 + 0x19c) = auVar29._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x23;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(float *)(DAT_00772400 + 0x198) = (float)dVar24;
  auVar25 = ZEXT816(0x4049000000000000);
  local_194 = 0x4049000000000000;
  FUN_006b8fb0();
  local_8._0_1_ = 0x24;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  iVar13 = DAT_00772400;
  auVar30._4_12_ = auVar25._4_12_;
  auVar30._0_4_ = (float)auVar25._0_8_;
  dVar24 = auVar30._0_8_;
  *(float *)(DAT_00772400 + 0x17c) = auVar30._0_4_;
  if (auVar30._0_4_ < 2.0) {
    *(undefined4 *)(iVar13 + 0x17c) = 0x42480000;
  }
  local_150 = (CDisplay *)&stack0xfffffe38;
  FUN_006b8fb0();
  local_8._0_1_ = 0x25;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  iVar13 = DAT_00772400;
  *(float *)(DAT_00772400 + 0x180) = (float)dVar24;
  if ((float)dVar24 < 3.0) {
    *(undefined4 *)(iVar13 + 0x180) = 0x42480000;
  }
  auVar25 = ZEXT816(0x4059000000000000);
  local_150 = (CDisplay *)&stack0xfffffe38;
  local_194 = 0x4059000000000000;
  FUN_006b8fb0();
  local_8._0_1_ = 0x26;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  auVar31._4_12_ = auVar25._4_12_;
  auVar31._0_4_ = (float)auVar25._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar31._0_4_);
  local_150 = (CDisplay *)&stack0xfffffe38;
  *(CDisplay **)(DAT_00772400 + 0x188) = DAT_00772dd8;
  local_14c = (CDisplay *)auVar31._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x27;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x11;
  FUN_006bee00();
  auVar32._4_12_ = auVar31._4_12_;
  auVar32._0_4_ = (float)auVar31._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar32._0_4_);
  *(CDisplay **)(DAT_00772400 + 0x184) = DAT_00772dd8;
  local_14c = (CDisplay *)auVar32._0_4_;
  local_154 = (CDisplay *)FUN_006ba810();
  *(undefined4 *)&local_154->field_0x4 = 0x14;
  *(undefined4 *)&local_154->field_0x8 = 0xffffffff;
  local_154->field_0xc = 0;
  *(int *)local_154 = 1;
  local_8._0_1_ = 0x28;
  local_150 = (CDisplay *)&stack0xfffffe34;
  FUN_006b8fb0();
  local_8._0_1_ = 0x29;
  FUN_006b8fb0("Screen");
  FUN_006bfc00();
  local_8 = CONCAT31(local_8._1_3_,0x28);
  cVar7 = FUN_006bf0a0();
  if (cVar7 != '\0') {
    FUN_00443460(&local_154->field_0xc,
                 "%08lx %04lx %04lx %02lx %02lx %02lx %02lx %02lx %02lx %02lx %02lx",&local_148,
                 local_144,local_140,local_13c,local_138,local_134,local_130,local_12c,local_128);
    iVar13 = DAT_00772400;
    *(undefined4 *)(DAT_00772400 + 0x160) = local_148;
    *(undefined2 *)(iVar13 + 0x164) = local_144[0];
    *(undefined2 *)(iVar13 + 0x166) = local_140[0];
    *(undefined1 *)(iVar13 + 0x168) = local_13c[0];
    *(undefined1 *)(iVar13 + 0x169) = local_138[0];
    *(undefined1 *)(iVar13 + 0x16a) = local_134[0];
    *(undefined1 *)(iVar13 + 0x16b) = local_130[0];
    *(undefined1 *)(iVar13 + 0x16c) = local_12c[0];
    *(undefined1 *)(iVar13 + 0x16d) = local_128[0];
    *(undefined1 *)(iVar13 + 0x16e) = local_128[4];
    *(undefined1 *)(iVar13 + 0x16f) = local_128[8];
  }
  local_150 = (CDisplay *)&stack0xfffffe34;
  FUN_006b8fb0();
  local_8._0_1_ = 0x2a;
  FUN_006b8fb0("Screen");
  FUN_006bfc00();
  local_8 = CONCAT31(local_8._1_3_,0x28);
  cVar7 = FUN_006bf0a0();
  pCVar23 = local_154;
  iVar13 = DAT_00772400;
  if (cVar7 != '\0') {
    FUN_00443460(&local_154->field_0xc,
                 "%08lx %04lx %04lx %02lx %02lx %02lx %02lx %02lx %02lx %02lx %02lx",&local_148,
                 local_144,local_140,local_13c,local_138,local_134,local_130,local_12c);
    iVar13 = DAT_00772400;
    *(undefined4 *)(DAT_00772400 + 0x150) = local_148;
    *(undefined2 *)(iVar13 + 0x154) = local_144[0];
    *(undefined2 *)(iVar13 + 0x156) = local_140[0];
    *(undefined1 *)(iVar13 + 0x158) = local_13c[0];
    *(undefined1 *)(iVar13 + 0x159) = local_138[0];
    *(undefined1 *)(iVar13 + 0x15a) = local_134[0];
    *(undefined1 *)(iVar13 + 0x15b) = local_130[0];
    *(undefined1 *)(iVar13 + 0x15c) = local_12c[0];
    *(undefined1 *)(iVar13 + 0x15d) = local_128[0];
    *(undefined1 *)(iVar13 + 0x15e) = local_128[4];
    *(undefined1 *)(iVar13 + 0x15f) = local_128[8];
  }
  *(undefined1 *)(iVar13 + 0x59d) = 0;
  local_158 = (CDisplay *)FUN_006ba810();
  if (local_158 == (CDisplay *)0x0) {
    DAT_0076a29c = (CDisplay *)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)local_158);
    local_158->field_0x18 = 0;
    local_15c = (CDisplay *)&local_158->field_0x1c;
    *(undefined4 *)local_15c = 0;
    *(undefined4 *)&local_158->field_0x20 = 0;
    local_8 = CONCAT31(local_8._1_3_,0x2d);
    FUN_004452c0();
    FUN_004453b0();
    if (*(int *)((int)local_15c + 4) == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_006b9200();
    DAT_0076a29c = local_158;
  }
  local_8 = CONCAT31(local_8._1_3_,0x28);
  local_14c = (CDisplay *)FUN_006ba810();
  if (local_14c == (CDisplay *)0x0) {
    DAT_00772404 = (CDisplay *)0x0;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)local_14c);
    local_14c->field_0x18 = 0;
    *(undefined4 *)&local_14c->field_0x1c = 0;
    *(undefined4 *)&local_14c->field_0x20 = 0;
    DAT_00772404 = local_14c;
  }
  local_168 = &local_17c->field_0xc;
  FUN_006b8fb0();
  FUN_0055c350();
  FUN_006b8fb0();
  uVar12 = FUN_00444fc0();
  *(undefined4 *)(DAT_00772400 + 0x1b4) = uVar12;
  FUN_006b8fb0();
  uVar12 = FUN_00444fc0();
  *(undefined4 *)(DAT_00772400 + 0x1b8) = uVar12;
  FUN_006b8fb0();
  uVar12 = FUN_00444fc0();
  iVar13 = DAT_00772400;
  *(undefined4 *)(DAT_00772400 + 0x1bc) = uVar12;
  *(undefined1 *)(iVar13 + 0x59d) = 1;
  *(undefined1 *)(iVar13 + 0x5c1) = 0;
  local_8 = CONCAT31(local_8._1_3_,0x2e);
  if ((pCVar23 != (CDisplay *)0x0) && (*(int *)pCVar23 = *(int *)pCVar23 + -1, *(int *)pCVar23 == 0)
     ) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  if ((*(int *)(iVar8 + 4) < DAT_00ca7d60) &&
     (FUN_006cebf4(), iVar13 = DAT_00783650, DAT_00ca7d60 == -1)) {
    iVar17 = DAT_00783650 * 0x40;
    _DAT_00ca7d64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar17) = "CGameThread::Init() Init SDL";
    *(int *)(&DAT_00773650 + iVar17) = iVar13;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = CONCAT31(local_8._1_3_,0x2f);
  CSdlManager::Init();
  FUN_0043fd30();
  Sleep(2000);
  if ((*(int *)(iVar8 + 4) < DAT_00ca7d68) &&
     (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7d68 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    _DAT_00ca7d6c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() Rendering";
    *(int *)(&DAT_00773650 + iVar13) = iVar8;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = CONCAT31(local_8._1_3_,0x30);
  piVar10 = (int *)FUN_006ba810();
  local_164 = (CDisplay *)piVar10;
  if (piVar10 == (int *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    FUN_00440000();
    *piVar10 = (int)Threads::CGameRenderThread::vftable;
    InitializeCriticalSection((LPCRITICAL_SECTION)(piVar10 + 0x24));
    *(undefined1 *)(piVar10 + 0x2a) = 0;
    piVar10[0x2b] = 0;
    *(undefined1 *)(piVar10 + 0x2c) = 0;
    *(undefined1 *)(piVar10 + 0x20) = 0;
    piVar10[0x23] = 0;
    piVar10[0x21] = 0;
    piVar10[0x22] = -1;
  }
  *(int **)(DAT_00772400 + 0x5a0) = piVar10;
  if (local_17c->field_0xa4 != '\0') {
    (**(code **)(*piVar10 + 8))();
  }
  local_164 = (CDisplay *)FUN_006ba810();
  local_8._0_1_ = 0x31;
  if (local_164 == (CDisplay *)0x0) {
    DAT_0076a338 = 0;
  }
  else {
    DAT_0076a338 = FUN_00464780(local_164);
  }
  local_164 = (CDisplay *)&stack0xfffffe38;
  local_8._0_1_ = 0x30;
  FUN_006b8fb0();
  local_8._0_1_ = 0x32;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  pCVar23 = (CDisplay *)(int)auVar32._0_8_;
  local_194._4_1_ = pCVar23 == (CDisplay *)0x1;
  this_01 = DisplayModeManager::GetInstance();
  if (pCVar23 == (CDisplay *)0x0) {
    pCVar23 = (CDisplay *)0x2;
  }
  local_158 = pCVar23;
  DisplayModeManager::SetMode(this_01,(int)pCVar23);
  DisplayModeManager::Update(this_01);
  DisplayModeManager::Resolve(this_01);
  local_154 = (CDisplay *)ScreenResolutionManager::GetInstance();
  local_164 = (CDisplay *)&stack0xfffffe38;
  FUN_006b8fb0();
  local_8._0_1_ = 0x33;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar33._4_12_ = auVar32._4_12_;
  auVar33._0_4_ = (float)auVar32._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar33._0_4_);
  local_164 = (CDisplay *)&stack0xfffffe38;
  local_184 = DAT_00772dd8;
  local_14c = (CDisplay *)auVar33._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x34;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar34._4_12_ = auVar33._4_12_;
  auVar34._0_4_ = (float)auVar33._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar34._0_4_);
  local_164 = (CDisplay *)&stack0xfffffe38;
  local_180 = DAT_00772dd8;
  local_14c = (CDisplay *)auVar34._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x35;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar35._4_12_ = auVar34._4_12_;
  auVar35._0_4_ = (float)auVar34._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar35._0_4_);
  local_164 = (CDisplay *)&stack0xfffffe38;
  local_15c = DAT_00772dd8;
  local_14c = (CDisplay *)auVar35._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x36;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar36._4_12_ = auVar35._4_12_;
  auVar36._0_4_ = (float)auVar35._0_8_;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar36._0_4_);
  local_164 = (CDisplay *)&stack0xfffffe38;
  local_14c = (CDisplay *)auVar36._0_4_;
  local_174._4_4_ = DAT_00772dd8;
  FUN_006b8fb0();
  local_8._0_1_ = 0x37;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar37._4_12_ = auVar36._4_12_;
  auVar37._0_4_ = (float)auVar36._0_8_;
  pCVar23 = (CDisplay *)(int)ROUND(auVar37._0_4_);
  local_164 = (CDisplay *)&stack0xfffffe38;
  DAT_00772dd8 = pCVar23;
  local_14c = (CDisplay *)auVar37._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x38;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar38._4_12_ = auVar37._4_12_;
  auVar38._0_4_ = (float)auVar37._0_8_;
  dVar24 = auVar38._0_8_;
  local_164 = (CDisplay *)&stack0xfffffe38;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar38._0_4_);
  local_14c = (CDisplay *)auVar38._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x39;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8 = CONCAT31(local_8._1_3_,0x30);
  FUN_006bee00();
  pCVar6 = local_15c;
  pCVar22 = local_174._4_4_;
  local_14c = (CDisplay *)(float)dVar24;
  DAT_00772dd8 = (CDisplay *)(int)ROUND((float)local_14c);
  piVar10 = (int *)&(local_174._4_4_)->field_0x0;
  puVar21 = &DAT_00772dd8->field_0x0;
  FUN_0047eda0(&DAT_00ca7d70);
  GaLogger::WriteLogLineToFileA(&DAT_00ca7d70);
  tVar39.top = (LONG)pCVar23;
  tVar39.left = (LONG)pCVar22;
  tVar39.right = (LONG)(&((CDisplay *)(int)ROUND(auVar38._0_4_))->field_0x0 + (int)piVar10);
  tVar39.bottom = (LONG)(&pCVar23->field_0x0 + (int)puVar21);
  iVar8 = CSdlInformWindowHandle::ValidateDisplayIndex((int)pCVar6,tVar39);
  FUN_0047eda0(&DAT_00ca7d70,0x40,"Validating. Display : %d \n",iVar8);
  GaLogger::WriteLogLineToFileA(&DAT_00ca7d70);
  this_02 = DisplayIndexManager::GetInstance();
  local_1a4 = CSdlInformWindowHandle::GetCurrentDisplayPoint(iVar8);
  FUN_0047eda0(&DAT_00ca7d70,0x40,"Display center : (%d, %d)  \n",local_1a4);
  GaLogger::WriteLogLineToFileA(&DAT_00ca7d70);
  DisplayIndexManager::SetDisplayIndex(this_02,iVar8,local_1a4.x,local_1a4.y);
  DisplayIndexManager::Update(this_02);
  DisplayIndexManager::Resolve(this_02);
  FUN_0047eda0();
  GaLogger::WriteLogLineToFileA(&DAT_00ca7d70);
  pCVar23 = local_154;
  if ((local_169 != '\0') || (local_16a != '\0')) {
    ScreenResolutionManager::GetDisplayDefaultResolution
              ((ScreenResolutionManager *)local_154,iVar8,(uint *)&local_184,(uint *)&local_180);
  }
  FUN_0047eda0(&DAT_00ca7d70,0x40);
  GaLogger::WriteLogLineToFileA(&DAT_00ca7d70);
  ScreenResolutionManager::ValidateDesiredResolution
            ((ScreenResolutionManager *)pCVar23,iVar8,(uint *)&local_184,(uint *)&local_180,
             (int)local_158);
  ScreenResolutionManager::SetDesiredResolution
            ((ScreenResolutionManager *)pCVar23,(uint)local_184,(uint)local_180);
  FUN_0047eda0(&DAT_00ca7d70,0x40);
  GaLogger::WriteLogLineToFileA(&DAT_00ca7d70);
  local_15c = (CDisplay *)PostProcessOptionManager::GetInstance();
  local_164 = (CDisplay *)&stack0xfffffe38;
  FUN_006b8fb0();
  local_8._0_1_ = 0x3a;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  auVar40._4_12_ = tVar39._4_12_;
  auVar40._0_4_ = (float)tVar39._0_8_;
  dVar24 = auVar40._0_8_;
  local_164 = (CDisplay *)&stack0xfffffe38;
  DAT_00772dd8 = (CDisplay *)(int)ROUND(auVar40._0_4_);
  local_14c = (CDisplay *)auVar40._0_4_;
  FUN_006b8fb0();
  local_8._0_1_ = 0x3b;
  FUN_006b8fb0();
  FUN_006bfc00();
  local_8._0_1_ = 0x30;
  FUN_006bee00();
  local_14c = (CDisplay *)(float)dVar24;
  fVar1 = ROUND((float)local_14c);
  DAT_00772dd8 = (CDisplay *)(int)fVar1;
  PostProcessOptionManager::SetModeValue
            ((PostProcessOptionManager *)local_15c,0,(int)ROUND(auVar40._0_4_));
  PostProcessOptionManager::SetModeValue((PostProcessOptionManager *)local_15c,1,(int)fVar1);
  PostProcessOptionManager::Update((PostProcessOptionManager *)local_15c,0);
  PostProcessOptionManager::Resolve((PostProcessOptionManager *)local_15c,0);
  PostProcessOptionManager::Update((PostProcessOptionManager *)local_15c,1);
  PostProcessOptionManager::Resolve((PostProcessOptionManager *)local_15c,1);
  local_8._0_1_ = 0;
  FUN_0043fd30();
  DAT_0077248e = '\0';
  DAT_0077248d = '\0';
  lVar42 = 0;
  BVar16 = EnumWindows(FUN_006aeb10,0);
  if (BVar16 == 0) goto LAB_006b0d15;
  pCVar23 = (CDisplay *)FUN_006ba810();
  *(undefined4 *)&pCVar23->field_0x4 = 0x14;
  *(undefined4 *)&pCVar23->field_0x8 = 0xffffffff;
  pCVar23->field_0xc = 0;
  *(int *)pCVar23 = 1;
  local_8._0_1_ = 0x3c;
  uVar18 = (undefined1)local_8;
  local_8._0_1_ = 0x3c;
  local_154 = pCVar23;
  if (DAT_0077248e == '\0') {
    local_8._0_1_ = uVar18;
    if (DAT_0077248d != '\0') {
      auVar47._8_4_ = (int)&local_174 + 4;
      auVar47._0_8_ = lVar42;
      auVar47._12_4_ = "WinAmp_Found";
      uVar41 = auVar47._8_8_;
      uVar12 = FUN_004435d0();
      auVar48._8_8_ = uVar41;
      auVar48._4_4_ = uVar12;
      auVar48._0_4_ = 0x6b0c88;
      lVar42 = auVar48._0_8_;
      local_14c = (CDisplay *)FUN_00443730();
      local_8._0_1_ = 0x3f;
      pCVar22 = *(CDisplay **)local_14c;
      if (pCVar22 != (CDisplay *)0x0) {
        *(int *)pCVar22 = *(int *)pCVar22 + 1;
      }
      *(int *)pCVar23 = *(int *)pCVar23 + -1;
      local_154 = pCVar22;
      if (*(int *)pCVar23 == 0) {
        FUN_006ba940();
      }
      *(undefined4 *)&pCVar22->field_0x8 = *(undefined4 *)(*(int *)local_14c + 8);
      local_8._0_1_ = 0x40;
      goto LAB_006b0cc1;
    }
  }
  else {
    if (DAT_0077248d == '\0') {
      auVar43._8_4_ = (int)&local_174 + 4;
      auVar43._0_8_ = lVar42;
      auVar43._12_4_ = "ICQ_Found";
      uVar41 = auVar43._8_8_;
      uVar12 = FUN_004435d0();
      auVar44._8_8_ = uVar41;
      auVar44._4_4_ = uVar12;
      auVar44._0_4_ = 0x6b0bde;
      lVar42 = auVar44._0_8_;
      local_14c = (CDisplay *)FUN_00443730();
      local_8._0_1_ = 0x3d;
      pCVar22 = *(CDisplay **)local_14c;
      if (pCVar22 != (CDisplay *)0x0) {
        *(int *)pCVar22 = *(int *)pCVar22 + 1;
      }
      *(int *)pCVar23 = *(int *)pCVar23 + -1;
      local_154 = pCVar22;
      if (*(int *)pCVar23 == 0) {
        FUN_006ba940();
      }
      *(undefined4 *)&pCVar22->field_0x8 = *(undefined4 *)(*(int *)local_14c + 8);
      local_8._0_1_ = 0x3e;
    }
    else {
      auVar45._8_4_ = (int)&local_174 + 4;
      auVar45._0_8_ = lVar42;
      auVar45._12_4_ = "ICQ_WinAmp_Found";
      uVar41 = auVar45._8_8_;
      local_8._0_1_ = uVar18;
      uVar12 = FUN_004435d0();
      auVar46._8_8_ = uVar41;
      auVar46._4_4_ = uVar12;
      auVar46._0_4_ = 0x6b0c2d;
      lVar42 = auVar46._0_8_;
      local_14c = (CDisplay *)FUN_00443730();
      local_8._0_1_ = 0x41;
      pCVar22 = *(CDisplay **)local_14c;
      if (pCVar22 != (CDisplay *)0x0) {
        *(int *)pCVar22 = *(int *)pCVar22 + 1;
      }
      *(int *)pCVar23 = *(int *)pCVar23 + -1;
      local_154 = pCVar22;
      if (*(int *)pCVar23 == 0) {
        FUN_006ba940();
      }
      *(undefined4 *)&pCVar22->field_0x8 = *(undefined4 *)(*(int *)local_14c + 8);
      local_8._0_1_ = 0x42;
    }
LAB_006b0cc1:
    pCVar23 = pCVar22;
    if ((local_174._4_4_ != (CDisplay *)0x0) &&
       (*(int *)local_174._4_4_ = *(int *)local_174._4_4_ + -1, *(int *)local_174._4_4_ == 0)) {
      FUN_006ba940();
    }
  }
  iVar8 = *(int *)&pCVar23->field_0x8;
  puVar21 = &pCVar23->field_0xc;
  if (iVar8 == -1) {
    pcVar19 = puVar21;
    do {
      cVar7 = *pcVar19;
      pcVar19 = pcVar19 + 1;
    } while (cVar7 != '\0');
    iVar8 = (int)pcVar19 - (int)&pCVar23->field_0xd;
    *(int *)&pCVar23->field_0x8 = iVar8;
  }
  if (0 < iVar8) {
    auVar49._8_4_ = "Diggles";
    auVar49._0_8_ = lVar42;
    auVar49._12_4_ = 0x40;
    auVar2._4_8_ = auVar49._8_8_;
    auVar2._0_4_ = puVar21;
    lVar42 = auVar2._0_8_ << 0x20;
    MessageBoxA((HWND)0x0,puVar21,"Diggles",0x40);
  }
  local_8._0_1_ = 0x43;
  *(int *)pCVar23 = *(int *)pCVar23 + -1;
  if (*(int *)pCVar23 == 0) {
    FUN_006ba940();
  }
LAB_006b0d15:
  iVar8 = local_178;
  local_154 = (CDisplay *)((uint)local_154 & 0xffffff00);
  local_15c = (CDisplay *)0x0;
  if ((*(int *)(local_178 + 4) < DAT_00ca7db0) &&
     (FUN_006cebf4(), iVar13 = DAT_00783650, DAT_00ca7db0 == -1)) {
    iVar17 = DAT_00783650 * 0x40;
    _DAT_00ca7db4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar17) = "CGameThread::Init() TclScript 1";
    *(int *)(&DAT_00773650 + iVar17) = iVar13;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = CONCAT31(local_8._1_3_,0x45);
  if (DAT_00772dd0 == (LPCRITICAL_SECTION)0x0) {
    uVar41 = 0;
    FUN_006bb140();
  }
  else {
    auVar50._8_4_ = "data/scripts/misc/genattribs.tcl";
    auVar50._0_8_ = lVar42;
    auVar50._12_4_ = extraout_ECX;
    auVar51._8_8_ = auVar50._8_8_;
    auVar51._4_4_ = &local_158;
    auVar51._0_4_ = 0x6b0d6c;
    uVar41 = auVar51._0_8_;
    FUN_006bbb00();
  }
  local_150 = local_158;
  local_15c = local_158;
  if (local_158 != (CDisplay *)0x0) {
    *(int *)local_158 = *(int *)local_158 + 1;
    if (local_158 != (CDisplay *)0x0) {
      *(int *)local_158 = *(int *)local_158 + -1;
      if (*(int *)local_158 < 1) {
        TclFreeObj();
      }
      local_158 = (CDisplay *)0x0;
    }
    FUN_005c9cc0();
    cVar7 = FUN_00555a00();
    local_154 = (CDisplay *)((uint)local_154 & 0xff);
    if (cVar7 == '\0') {
      local_154 = (CDisplay *)0x1;
    }
  }
  FUN_0043fd30();
  if ((*(int *)(iVar8 + 4) < DAT_00ca7db8) &&
     (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7db8 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    _DAT_00ca7dbc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() Init Display";
    *(int *)(&DAT_00773650 + iVar13) = iVar8;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = CONCAT31(local_8._1_3_,0x46);
  auVar52._8_4_ = local_194._4_4_;
  auVar52._0_8_ = uVar41;
  auVar52._12_4_ = &local_1a4;
  auVar3._4_8_ = auVar52._8_8_;
  auVar3._0_4_ = local_180;
  FUN_00464fb0(local_184,auVar3);
  if (*(char *)(DAT_00772400 + 0x59a) != '\0') {
    iVar8 = FUN_004cfea0();
    FUN_004d0160();
    if (*(char *)(iVar8 + 0x1c) != '\0') {
      *(undefined4 *)(iVar8 + 0x44) = *(undefined4 *)(iVar8 + 0x18);
      *(undefined4 *)(iVar8 + 0x40) = 1;
    }
    FUN_004d02f0();
    FUN_004d03e0();
    FUN_004d03e0();
    FUN_004d03e0();
    FUN_004d03e0();
    FUN_004d03e0();
  }
  FUN_004653d0();
  FUN_00479c10();
  local_8._0_1_ = 0x44;
  FUN_0043fd30();
  FUN_006b8fb0();
  local_8._0_1_ = 0x47;
  FUN_006b90d0();
  local_8._0_1_ = 0x48;
  FUN_006b9290();
  local_8._0_1_ = 0x49;
  if ((local_158 != (CDisplay *)0x0) &&
     (*(int *)local_158 = *(int *)local_158 + -1, *(int *)local_158 == 0)) {
    FUN_006ba940();
  }
  pCVar23 = local_174._4_4_;
  pCVar5 = local_17c;
  local_8 = CONCAT31(local_8._1_3_,0x47);
  SetWindowTextA((HWND)local_17c->i_34,&(local_174._4_4_)->field_0xc);
  DVar9 = GetTickCount();
  if (DAT_007687c0 == 0xffffffff) {
    DAT_007687c0 = DVar9;
  }
  if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar9) {
    DAT_007687c0 = DVar9;
    FUN_00479c10();
    Sleep(1);
  }
  iVar8 = *(int *)pCVar5;
  FUN_0044d010();
  (**(code **)(iVar8 + 0x34))();
  DVar9 = GetTickCount();
  if (DAT_007687c0 == 0xffffffff) {
    DAT_007687c0 = DVar9;
  }
  if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar9) {
    DAT_007687c0 = DVar9;
    FUN_00479c10();
    Sleep(1);
  }
  FUN_0054d800();
  if (DAT_007683c8 == 0) {
    hThread = (LPVOID)0x0;
    if (DAT_00767964 != 0xffffffff) {
      hThread = TlsGetValue(DAT_00767964);
    }
    iVar8 = -1;
  }
  else if ((DAT_007683c8 == 1) || (DAT_007683c8 != 2)) {
    hThread = (LPVOID)0x0;
    if (DAT_00767964 != 0xffffffff) {
      hThread = TlsGetValue(DAT_00767964);
    }
    iVar8 = 0;
  }
  else {
    hThread = (LPVOID)0x0;
    if (DAT_00767964 != 0xffffffff) {
      hThread = TlsGetValue(DAT_00767964);
    }
    iVar8 = 2;
  }
  SetThreadPriority(hThread,iVar8);
  FUN_006b8fb0("Display");
  FUN_0055c350();
  GetTickCount();
  iVar8 = local_178;
  if ((*(int *)(local_178 + 4) < DAT_00ca7dc0) &&
     (FUN_006cebf4(), iVar13 = DAT_00783650, DAT_00ca7dc0 == -1)) {
    iVar17 = DAT_00783650 * 0x40;
    _DAT_00ca7dc4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar17) = "CGameThread::Init() TclInit2";
    *(int *)(&DAT_00773650 + iVar17) = iVar13;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8 = CONCAT31(local_8._1_3_,0x4a);
  DVar9 = GetTickCount();
  if (DAT_007687c0 == 0xffffffff) {
    DAT_007687c0 = DVar9;
  }
  if ((int)(DAT_007687c0 + 0xfa) <= (int)DVar9) {
    DAT_007687c0 = DVar9;
    FUN_00479c10();
    Sleep(1);
  }
  if (DAT_00772dd0 == (LPCRITICAL_SECTION)0x0) {
    FUN_006bb140();
  }
  else {
    FUN_006bbb00(&local_160);
  }
  local_14c = local_160;
  local_15c = local_160;
  if (local_160 != (CDisplay *)0x0) {
    *(int *)local_160 = *(int *)local_160 + 1;
  }
  if ((local_150 != (CDisplay *)0x0) &&
     (*(int *)local_150 = *(int *)local_150 + -1, *(int *)local_150 < 1)) {
    TclFreeObj();
  }
  if (local_160 != (CDisplay *)0x0) {
    *(int *)local_160 = *(int *)local_160 + -1;
    if (*(int *)local_160 < 1) {
      TclFreeObj();
    }
    local_160 = (CDisplay *)0x0;
  }
  if (local_14c != (CDisplay *)0x0) {
    if ((*(int *)(iVar8 + 4) < DAT_00ca7dc8) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7dc8 == -1)) {
      iVar13 = DAT_00783650 * 0x40;
      _DAT_00ca7dcc = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() TclInit2 user";
      *(int *)(&DAT_00773650 + iVar13) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8._0_1_ = 0x4b;
    FUN_005c9cc0();
    cVar7 = FUN_00555a00();
    uVar18 = SUB41(local_154,0);
    if (cVar7 == '\0') {
      uVar18 = 1;
    }
    local_8 = CONCAT31(local_8._1_3_,0x4a);
    local_154 = (CDisplay *)CONCAT31(local_154._1_3_,uVar18);
    FUN_0043fd30();
  }
  if (DAT_00772dd0 == (LPCRITICAL_SECTION)0x0) {
    FUN_006bb140();
  }
  else {
    FUN_006bbb00(&local_158);
  }
  pCVar22 = local_158;
  local_15c = local_158;
  if (local_158 != (CDisplay *)0x0) {
    *(int *)local_158 = *(int *)local_158 + 1;
  }
  if ((local_14c != (CDisplay *)0x0) &&
     (*(int *)local_14c = *(int *)local_14c + -1, *(int *)local_14c < 1)) {
    TclFreeObj();
  }
  if ((local_158 != (CDisplay *)0x0) &&
     (*(int *)local_158 = *(int *)local_158 + -1, *(int *)local_158 < 1)) {
    TclFreeObj();
  }
  if (pCVar22 == (CDisplay *)0x0) {
    local_154 = (CDisplay *)CONCAT31(local_154._1_3_,1);
  }
  else {
    if ((*(int *)(local_178 + 4) < DAT_00ca7dd0) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7dd0 == -1)) {
      iVar13 = DAT_00783650 * 0x40;
      _DAT_00ca7dd4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() TclInit2 system";
      *(int *)(&DAT_00773650 + iVar13) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = CONCAT31(local_8._1_3_,0x4c);
    local_150 = (CDisplay *)FUN_005c9cc0();
    if ((*(int *)(local_178 + 4) < DAT_00ca7dd8) &&
       (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7dd8 == -1)) {
      iVar13 = DAT_00783650 * 0x40;
      _DAT_00ca7ddc = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() TclInit2 system eval";
      *(int *)(&DAT_00773650 + iVar13) = iVar8;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa();
    }
    FUN_00405af0();
    local_8 = CONCAT31(local_8._1_3_,0x4d);
    cVar7 = FUN_00555a00();
    local_154 = (CDisplay *)((uint)local_154 & 0xff);
    if (cVar7 == '\0') {
      local_154 = (CDisplay *)0x1;
    }
    FUN_0043fd30();
    FUN_0043fd30();
  }
  GetTickCount();
  local_8._0_1_ = 0x47;
  FUN_0043fd30();
  *(undefined1 *)(DAT_00772400 + 0x8a) = 1;
  DVar9 = GetTickCount();
  local_17c->i_9c = DVar9 + 1000;
  DVar9 = GetTickCount();
  local_17c->i_a0 = DVar9 + 0x32;
  FUN_006b8fb0();
  local_8._0_1_ = 0x4e;
  FUN_005ba430();
  local_8._0_1_ = 0x4f;
  if ((local_14c != (CDisplay *)0x0) &&
     (*(int *)local_14c = *(int *)local_14c + -1, *(int *)local_14c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x47);
  FUN_0055a800();
  if ((*(int *)(local_178 + 4) < DAT_00ca7de0) &&
     (FUN_006cebf4(), iVar8 = DAT_00783650, DAT_00ca7de0 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    _DAT_00ca7de4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "CGameThread::Init() AI Init";
    *(int *)(&DAT_00773650 + iVar13) = iVar8;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  FUN_00405af0();
  local_8._0_1_ = 0x50;
  if (DAT_0076a274 == (CDisplay *)0x0) {
    local_164 = (CDisplay *)FUN_006ba810();
    local_8._0_1_ = 0x51;
    if (local_164 == (CDisplay *)0x0) {
      DAT_0076a274 = (CDisplay *)0x0;
    }
    else {
      FUN_00424cc0((CMap *)local_164);
      DAT_0076a274 = local_164;
    }
  }
  local_8._0_1_ = 0x50;
  local_158 = (CDisplay *)FUN_00432390();
  FUN_00432470();
  FUN_00432470();
  FUN_00432470();
  FUN_00432470();
  FUN_00432470();
  FUN_00432470();
  FUN_00432470();
  local_8._0_1_ = 0x47;
  FUN_0043fd30();
  FUN_00445c60();
  *(undefined4 *)&local_17c->field_0x188 = 0xc2c80000;
  if ((char)local_154 != '\0') {
    (**(code **)(*(int *)local_17c + 0x20))();
    FUN_006b8fb0();
    local_8._0_1_ = 0x52;
    FUN_004495a0();
    local_8._0_1_ = 0x53;
    FUN_006b9290();
    local_8 = CONCAT31(local_8._1_3_,0x52);
    FUN_006b8ed0();
    uType = 0x10;
    lpCaption = (LPCSTR)FUN_006b91b0();
    MessageBoxA((HWND)0x0,"Fatal init error.\nSee tclerrors.txt for details.",lpCaption,uType);
    cVar7 = FUN_006b7a40();
    if ((cVar7 != '\0') && (iVar8 = FUN_004cfea0(), *(int *)(iVar8 + 0x34) != 0)) {
      FUN_004498b0();
      FUN_004cfe80();
      iVar8 = FUN_004cfea0();
      *(undefined4 *)(iVar8 + 0x34) = 0;
    }
                    /* WARNING: Subroutine does not return */
    ExitProcess(0);
  }
  iVar8 = FUN_006d02c0();
  if (iVar8 == 0) {
    *(undefined1 *)(DAT_00772400 + 0x19) = 1;
  }
  else {
    *(undefined1 *)(DAT_00772400 + 0x19) = 0;
    FUN_005c9cc0();
    Tcl_MakeSafe();
  }
  iVar8 = FUN_006d02c0();
  DAT_00767975 = iVar8 != 0;
  local_8 = CONCAT31(local_8._1_3_,0x54);
  if ((pCVar23 != (CDisplay *)0x0) && (*(int *)pCVar23 = *(int *)pCVar23 + -1, *(int *)pCVar23 == 0)
     ) {
    FUN_006ba940();
  }
  if ((pCVar22 != (CDisplay *)0x0) && (*(int *)pCVar22 = *(int *)pCVar22 + -1, *(int *)pCVar22 < 1))
  {
    TclFreeObj();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

