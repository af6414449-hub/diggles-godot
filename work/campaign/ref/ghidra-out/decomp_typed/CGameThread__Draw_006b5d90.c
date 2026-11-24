
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGameThread__Draw(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint *puVar3;
  HANDLE pvVar4;
  char cVar5;
  bool bVar6;
  uint uVar7;
  LPCRITICAL_SECTION p_Var8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  DWORD DVar13;
  ULONG_PTR UVar14;
  int *piVar15;
  int *this;
  PRTL_CRITICAL_SECTION_DEBUG p_Var16;
  code *pcVar17;
  float fVar18;
  double dVar19;
  undefined1 auVar20 [16];
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  int *local_38;
  float local_34;
  float local_30;
  LPCRITICAL_SECTION local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  fVar21 = DAT_00772400;
  p_Var8 = DAT_0076a274;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712f43;
  local_10 = ExceptionList;
  uVar7 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)DAT_00772400 + 0x78) = 0;
  *(undefined4 *)((int)fVar21 + 0x7c) = 0;
  *(undefined4 *)((int)fVar21 + 0x84) = 0;
  local_24 = this;
  if (p_Var8 == (LPCRITICAL_SECTION)0x0) {
    p_Var8 = (LPCRITICAL_SECTION)FUN_006ba810(0x26,uVar7);
    local_8 = 0;
    local_2c = p_Var8;
    if (p_Var8 == (LPCRITICAL_SECTION)0x0) {
      DAT_0076a274 = (LPCRITICAL_SECTION)0x0;
    }
    else {
      FUN_00424cc0();
      DAT_0076a274 = p_Var8;
    }
  }
  local_8 = 0xffffffff;
  FUN_00424560();
  fVar21 = DAT_00772400;
  pcVar17 = RaiseException_exref;
  *(undefined8 *)((int)DAT_00772400 + 0xa0b8) = *(undefined8 *)((int)DAT_00772400 + 0xa088);
  auVar20 = ZEXT816(0);
  local_20 = (int *)0x0;
  if ((float)this[0x4d] <= -1000.0) {
    if (-1 < *(int *)((int)fVar21 + 0xa0d4)) {
      FUN_006b5ab0();
    }
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7eb4) &&
       (FUN_006cebf4(&DAT_00ca7eb4), iVar9 = DAT_00783650, DAT_00ca7eb4 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00ca7eb8 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() if(m_fViewMoveToX>-1000.0f)";
      *(int *)(&DAT_00773650 + iVar12) = iVar9;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7eb4);
    }
    FUN_00405af0(&DAT_00ca7eb8);
    fVar21 = (float)this[0x4d];
    auVar20 = ZEXT416((uint)fVar21);
    if (fVar21 == -1.0) {
      uVar7 = 0;
      piVar11 = *(int **)((int)DAT_00772400 + 100);
      local_20 = (int *)(DAT_0077244c + 0x488);
      local_28 = piVar11;
      do {
        if (uVar7 < 0x2000) {
          piVar15 = local_20 + uVar7;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar15 = local_20;
          piVar11 = local_28;
        }
        iVar9 = *piVar15;
        if ((((iVar9 != 0) && (*(int **)(iVar9 + 0x36c) == piVar11)) &&
            (*(int *)(iVar9 + 0xd4) != 0)) && (*(int *)(*(int *)(iVar9 + 0xd4) + 0x54) == 1)) {
          auVar20 = ZEXT416(*(uint *)(iVar9 + 0xc));
          uVar7 = 0x2000;
          this[0x55] = *(uint *)(iVar9 + 0xc);
          this[0x56] = *(int *)(iVar9 + 0x10);
          this[0x4d] = -0x3b860000;
          this[0x4e] = -0x3b860000;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 0x2000);
    }
    else if ((char)this[0x50] == '\0') {
      this[0x57] = this[0x4f];
      this[0x58] = this[0x53];
      this[0x59] = this[0x54];
      this[0x55] = (int)fVar21;
      this[0x56] = this[0x4e];
      this[0x4d] = -0x3b860000;
      this[0x4e] = -0x3b860000;
    }
    else {
      piVar15 = (int *)this[0x3c];
      piVar11 = this + 0x3b;
      if (piVar15 != (int *)0x0) {
        local_28 = (int *)((int)piVar15 - 1);
        if (piVar15 <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_20 = *(int **)(*piVar11 + 8 + (int)local_28 * 0xc);
      }
      fVar21 = DAT_00772400;
      local_1c = ((float)*(double *)((int)DAT_00772400 + 0xa088) - (float)this[0x4c]) *
                 (float)this[0x51];
      auVar20 = ZEXT416((uint)local_1c);
      if ((float)local_20 <= local_1c) {
        this[0x4d] = -0x3b860000;
        this[0x4e] = -0x3b860000;
        this->c_50 = 0;
        if (((char)this[0x52] != '\0') &&
           (*(undefined1 *)((int)fVar21 + 0x8b) = 0, *(char *)((int)fVar21 + 0xa098) == '\0')) {
          *(undefined1 *)((int)fVar21 + 0xa098) = 1;
        }
      }
      else {
        local_28 = (int *)(this[0x3c] - 1);
        if ((uint)this[0x3c] <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_28 = *(int **)(*piVar11 + 4 + (int)local_28 * 0xc);
        fVar21 = (float)local_28;
        FUN_00463750();
        fVar21 = fVar21 / (float)local_28;
        local_28 = (int *)(this[0x3c] - 1);
        fVar18 = 1.0 - fVar21;
        local_20 = (int *)(fVar18 * (float)this[0x3d] + fVar21 * (float)this[0x40]);
        local_18 = (float)this[0x3e] * fVar18 + (float)this[0x41] * fVar21;
        local_14 = (float)this[0x3f] * fVar18 + (float)this[0x42] * fVar21;
        if ((uint)this[0x3c] <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_28 = *(int **)(*piVar11 + 4 + (int)local_28 * 0xc);
        piVar11 = local_28;
        FUN_00463750();
        fVar21 = (float)piVar11 / (float)local_28;
        this[0x55] = (int)local_20;
        fVar18 = (float)this[0x44] * (1.0 - fVar21) + (float)this[0x47] * fVar21;
        auVar20 = ZEXT416((uint)fVar18);
        this[0x56] = (int)local_18;
        this[0x57] = (int)local_14;
        this[0x58] = (int)((1.0 - fVar21) * (float)this[0x43] + fVar21 * (float)this[0x46]);
        this[0x59] = (int)fVar18;
      }
    }
    FUN_0043fd30();
  }
  GetTickCount();
  if (((*(char *)((int)DAT_00772400 + 0x5c0) == '\0') ||
      (*(char *)((int)DAT_00772400 + 0x59d) == '\0')) || (*(char *)(DAT_0076a338 + 0x2839) != '\0'))
  {
                    /* WARNING: Load size is inaccurate */
    if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7ebc) &&
       (FUN_006cebf4(&DAT_00ca7ebc), iVar9 = DAT_00783650, DAT_00ca7ebc == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      DAT_00ca7ec0 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() Pre-Loading";
      *(int *)(&DAT_00773650 + iVar12) = iVar9;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7ebc);
    }
    iVar12 = DAT_00ca7ec0;
    local_2c = (LPCRITICAL_SECTION)&DAT_00ca7ec0;
    uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7ec0 * 0x40);
    iVar9 = FUN_0043fcc0();
    *(undefined4 *)(iVar9 + *(int *)(iVar9 + 0x8000) * 4) = uVar10;
    *(int *)(iVar9 + 0x8000) = *(int *)(iVar9 + 0x8000) + 1;
    iVar9 = (&DAT_00773654)[iVar12 * 0x10];
    if (iVar9 == 0) {
      uVar23 = FUN_006bd180();
      iVar9 = (&DAT_00773654)[iVar12 * 0x10];
      *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar23;
    }
    (&DAT_00773654)[iVar12 * 0x10] = iVar9 + 1;
    local_8 = 1;
    if (DAT_00772444 == 0) {
      local_28 = (int *)FUN_006ba810(0xa9);
      local_8._0_1_ = 2;
      if (local_28 == (int *)0x0) {
        DAT_00772444 = 0;
      }
      else {
        DAT_00772444 = FUN_005b79e0();
      }
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_00479c10(0,1);
    goto LAB_006b7090;
  }
  if ((DAT_0077241c == (LPCRITICAL_SECTION)0x0) ||
     (*(char *)((int)&DAT_0077241c[1].LockSemaphore + 1) == '\0')) {
    FUN_00479c10(0,1);
    ExceptionList = local_10;
    return;
  }
                    /* WARNING: Load size is inaccurate */
  fVar21 = *ThreadLocalStoragePointer;
  local_14 = fVar21;
  if ((*(int *)((int)fVar21 + 4) < DAT_00ca7ec4) &&
     (FUN_006cebf4(&DAT_00ca7ec4), iVar9 = DAT_00783650, DAT_00ca7ec4 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    _DAT_00ca7ec8 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() DoLinkUpdates";
    *(int *)(&DAT_00773650 + iVar12) = iVar9;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7ec4);
  }
  FUN_00405af0(&DAT_00ca7ec8);
  local_8 = 3;
  FUN_005f5000();
  FUN_005f5340();
  FUN_0043fd30();
  *(undefined4 *)((int)DAT_00772400 + 0x70) = DAT_00c3c9e0;
  GetTickCount();
  *(int *)((int)DAT_00772400 + 0x68) = *(int *)((int)DAT_00772400 + 0x68) + 1;
  if ((*(int *)((int)fVar21 + 4) < DAT_00ca7ecc) &&
     (FUN_006cebf4(&DAT_00ca7ecc), iVar9 = DAT_00783650, DAT_00ca7ecc == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    _DAT_00ca7ed0 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() BeginBuildFrame";
    *(int *)(&DAT_00773650 + iVar12) = iVar9;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7ecc);
  }
  FUN_00405af0(&DAT_00ca7ed0);
  local_8 = 4;
  iVar9 = FUN_0044d010();
  uVar10 = FUN_00450400();
  *(undefined4 *)(iVar9 + 0x22e8) = uVar10;
  FUN_0043fd30();
  if ((*(int *)((int)local_14 + 4) < DAT_00ca7ed4) &&
     (FUN_006cebf4(&DAT_00ca7ed4), iVar9 = DAT_00783650, DAT_00ca7ed4 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    _DAT_00ca7ed8 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() Sel/Hover Change";
    *(int *)(&DAT_00773650 + iVar12) = iVar9;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7ed4);
  }
  FUN_00405af0(&DAT_00ca7ed8);
  local_8 = 5;
  local_18 = DAT_00772400;
  if (*(int *)((int)DAT_00772400 + 0xa0e4) != *(int *)((int)DAT_00772400 + 0xa0cc)) {
    p_Var8 = (LPCRITICAL_SECTION)FUN_005db550();
    uVar7 = 0;
    local_28 = (int *)p_Var8->LockCount;
    local_2c = p_Var8;
    if (0 < (int)local_28) {
      do {
        if ((uint)p_Var8->LockCount <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar3 = *(uint **)(&p_Var8->DebugInfo->Type + uVar7 * 2);
        uVar7 = uVar7 + 1;
        *puVar3 = *puVar3 | 8;
        this = local_24;
      } while ((int)uVar7 < (int)local_28);
    }
    local_18 = DAT_00772400;
    *(undefined4 *)((int)DAT_00772400 + 0xa0e4) = *(undefined4 *)((int)DAT_00772400 + 0xa0cc);
  }
  dVar19 = auVar20._0_8_;
  if (*(int *)((int)local_18 + 0xa0e0) == *(int *)((int)local_18 + 0xa0c8)) {
    if (*(int *)((int)local_18 + 0xa0e0) != 0) {
      uVar7 = 0;
      do {
        dVar19 = auVar20._0_8_;
        if ((int)*(uint *)((int)local_18 + 0xa0e0) <= (int)uVar7) goto LAB_006b63fe;
        if (*(uint *)((int)local_18 + 0xa0e0) <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar9 = uVar7 * 4;
        uVar7 = uVar7 + 1;
        cVar5 = FUN_005e35a0(*(undefined4 *)(*(int *)((int)local_18 + 0xa0dc) + iVar9));
      } while (cVar5 != '\0');
      goto LAB_006b63ac;
    }
  }
  else {
LAB_006b63ac:
    p_Var8 = (LPCRITICAL_SECTION)FUN_005db550();
    dVar19 = auVar20._0_8_;
    uVar7 = 0;
    local_28 = (int *)p_Var8->LockCount;
    local_2c = p_Var8;
    if (0 < (int)local_28) {
      do {
        if ((uint)p_Var8->LockCount <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        dVar19 = auVar20._0_8_;
        puVar3 = *(uint **)(&p_Var8->DebugInfo->Type + uVar7 * 2);
        uVar7 = uVar7 + 1;
        *puVar3 = *puVar3 | 4;
        this = local_24;
      } while ((int)uVar7 < (int)local_28);
    }
    FUN_005e3760((int)DAT_00772400 + 0xa0c4);
  }
LAB_006b63fe:
  local_8 = 0xffffffff;
  FUN_0043fd30();
  FUN_0043e3c0();
  fVar21 = local_14;
  if (*(char *)((int)DAT_00772400 + 0x599) != '\0') {
    if ((*(int *)((int)local_14 + 4) < DAT_00ca7edc) &&
       (FUN_006cebf4(&DAT_00ca7edc), DAT_00ca7edc == -1)) {
      local_8 = 6;
      FUN_005658e0(0);
      _atexit(FUN_00714740);
      local_8 = 0xffffffff;
      FUN_006cebaa(&DAT_00ca7edc);
    }
    cVar5 = FUN_00565940();
    if (cVar5 != '\0') {
      if ((*(int *)((int)fVar21 + 4) < DAT_00ca7ef8) &&
         (FUN_006cebf4(&DAT_00ca7ef8), iVar9 = DAT_00783650, DAT_00ca7ef8 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7efc = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() Sound";
        *(int *)(&DAT_00773650 + iVar12) = iVar9;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7ef8);
      }
      FUN_00405af0(&DAT_00ca7efc);
      local_8 = 7;
      FUN_004d1090();
      local_20 = (int *)this[0x57];
      local_28 = (int *)this[0x56];
      local_2c = (LPCRITICAL_SECTION)this[0x55];
      piVar11 = (int *)FUN_004d1090();
      *piVar11 = (int)local_2c;
      piVar11[1] = (int)local_28;
      dVar19 = (double)ZEXT48(local_20);
      piVar11[2] = (int)local_20;
      FUN_004d1090();
      FUN_004d1570();
      local_2c = (LPCRITICAL_SECTION)FUN_004cfea0();
      if (*(int *)((int)fVar21 + 4) < DAT_00c8aeb4) {
                    /* WARNING: Read-only address (ram,0x00737900) is written */
        FUN_006cebf4(&DAT_00c8aeb4);
        if (DAT_00c8aeb4 == -1) {
          local_8._0_1_ = 8;
          DAT_00768890 = 0;
          _DAT_00768880 = _DAT_00737900;
          dVar19 = _DAT_00737900;
          if (DAT_00772400 != 0.0) {
            FUN_00565700(&DAT_00768880);
            iVar9 = _rand();
            dVar19 = (double)iVar9 * _DAT_00768888 * 3.0517578125e-05;
            _DAT_00768880 = dVar19;
          }
          _atexit(FUN_00713e70);
          local_8 = CONCAT31(local_8._1_3_,7);
          FUN_006cebaa(&DAT_00c8aeb4);
        }
      }
      cVar5 = FUN_00565940();
      if (cVar5 != '\0') {
        FUN_004d03e0();
      }
      FUN_004d1090();
      local_8 = 0xffffffff;
      FUN_0043fd30();
    }
  }
  bVar6 = CSdlWindow::GetActive(*(CSdlWindow **)((int)DAT_00772400 + 0x13c));
  fVar21 = DAT_00772400;
  if (bVar6) {
    if (*(char *)((int)DAT_00772400 + 0x93) == '\0') {
      pcVar1 = (char *)((int)DAT_00772400 + 0x90);
      *(undefined1 *)((int)DAT_00772400 + 0x93) = 1;
      if ((*pcVar1 == '\0') || (*(char *)((int)fVar21 + 0x8f) == '\0')) {
        bVar6 = true;
      }
      else {
        bVar6 = false;
      }
      if (((*(char *)((int)fVar21 + 0x8b) == '\0') && (bVar6)) &&
         (*(char *)((int)fVar21 + 0xa098) == '\0')) {
        *(undefined1 *)((int)fVar21 + 0xa098) = 1;
      }
      FUN_0044d010();
      FUN_0044d1a0();
      SetCursorPos(*(int *)(DAT_0076a338 + 0x2830) / 2,*(int *)(DAT_0076a338 + 0x2834) / 2);
    }
  }
  else if (*(char *)((int)DAT_00772400 + 0x93) != '\0') {
    FUN_00501450();
    FUN_00502050();
    fVar21 = DAT_00772400;
    *(undefined1 *)((int)DAT_00772400 + 0x93) = 0;
    if ((DAT_007683d5 != '\0') && (*(char *)((int)fVar21 + 0xa098) != '\0')) {
      *(undefined1 *)((int)fVar21 + 0xa098) = 0;
    }
    iVar9 = FUN_0044d010();
    (**(code **)(**(int **)(iVar9 + 0xb8) + 0x10))();
  }
  bVar6 = CSdlWindow::GetActive((CSdlWindow *)this[0xc]);
  if (bVar6) {
    FUN_00440cf0();
    *(float *)((int)DAT_00772400 + 0x1a0) = (float)dVar19;
    EnterCriticalSection((LPCRITICAL_SECTION)(this + 4));
    if (this[0xb] != 0) {
      if (this[0xb] == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_20 = *(int **)this[10];
    }
    else {
      local_20 = (int *)0x0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(this + 4));
    if (local_20 != (int *)0x0) {
      if ((*(int *)((int)local_14 + 4) < DAT_00ca7f00) &&
         (FUN_006cebf4(&DAT_00ca7f00), iVar9 = DAT_00783650, DAT_00ca7f00 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7f04 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() MsgPump";
        *(int *)(&DAT_00773650 + iVar12) = iVar9;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7f00);
      }
      FUN_00405af0(&DAT_00ca7f04);
      local_8 = 9;
      while( true ) {
        EnterCriticalSection((LPCRITICAL_SECTION)(this + 4));
        if (this[0xb] == 0) {
          piVar11 = (int *)0x0;
          local_20 = (int *)0x0;
        }
        else {
          if (this[0xb] == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar11 = *(int **)this[10];
          local_20 = piVar11;
          FUN_00445250(this + 10);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(this + 4));
        if (piVar11 == (int *)0x0) break;
        if (*piVar11 == *(int *)((int)DAT_00772400 + 0x1bc)) {
          uVar7 = piVar11[1];
          FUN_00464d60(uVar7 >> 0xe & 0x3fff,uVar7 & 0x3fff,(byte)(uVar7 >> 0x1e) & 1);
          iVar9 = *this;
          iVar12 = FUN_0044d010();
          (**(code **)(iVar9 + 0x34))(iVar12 + 0x10);
          piVar11 = local_20;
        }
        thunk_FUN_0060fc30(piVar11[3]);
        FUN_006cecd8(piVar11,0x10);
      }
      local_8 = 0xffffffff;
      FUN_0043fd30();
    }
    piVar11 = (int *)FUN_004e4550();
    DVar13 = GetTickCount();
    if (*(char *)((int)DAT_00772400 + 0x590) == '\0') {
      if (0 < *piVar11) {
        *piVar11 = *piVar11 + -1;
        goto LAB_006b6795;
      }
      if (99 < (int)(DVar13 - piVar11[1])) goto LAB_006b6795;
      if (0x27 < (int)(DVar13 - piVar11[1])) {
        FUN_00501450();
        FUN_00501ab0();
      }
    }
    else {
LAB_006b6795:
      piVar11[1] = DVar13;
      if ((*(int *)((int)local_14 + 4) < DAT_00c930e0) &&
         (FUN_006cebf4(&DAT_00c930e0), iVar9 = DAT_00783650, DAT_00c930e0 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        DAT_00c930e4 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "void CDesktop::Tick()";
        *(int *)(&DAT_00773650 + iVar12) = iVar9;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00c930e0);
      }
      local_2c = (LPCRITICAL_SECTION)(DAT_00c930e4 * 0x40);
      local_28 = &DAT_00c930e4;
      pvVar4 = local_2c[0x4f798].LockSemaphore;
      iVar9 = FUN_0043fcc0();
      p_Var8 = local_2c;
      *(HANDLE *)(iVar9 + *(int *)(iVar9 + 0x8000) * 4) = pvVar4;
      *(int *)(iVar9 + 0x8000) = *(int *)(iVar9 + 0x8000) + 1;
      UVar14 = local_2c[0x4f798].SpinCount;
      if (UVar14 == 0) {
        uVar23 = FUN_006bd180();
        UVar14 = p_Var8[0x4f798].SpinCount;
        p_Var8[0x4f799].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)(int)uVar23;
        p_Var8[0x4f799].LockCount = (int)((ulonglong)uVar23 >> 0x20);
      }
      p_Var8[0x4f798].SpinCount = UVar14 + 1;
      local_8 = 10;
      local_20 = (int *)((int)DAT_00772400 + 0xa078);
      uVar7 = FUN_0055bfb0("ShowUI");
      if (uVar7 != 0xffffffff) {
        if ((uint)local_20[1] <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*(int *)(*local_20 + 8 + uVar7 * 0x1c) == 1) {
          FUN_00501450();
          FUN_00501b50();
        }
      }
      local_8 = 0xffffffff;
      FUN_0043fd30();
    }
    local_38 = (int *)this[0x58];
    local_34 = (float)this[0x59];
    fVar21 = (float)this[0x57];
    local_30 = 0.0;
    local_20 = local_38;
    local_1c = local_34;
    if (*(char *)((int)DAT_00772400 + 0x598) == '\0') {
      fVar18 = 1.0;
      if (1.0 <= fVar21) {
        fVar18 = fVar21;
      }
      local_18 = 2.5;
      if (fVar18 <= 2.5) {
        local_18 = fVar18;
      }
      fVar22 = local_34 * local_34 + (float)local_38 * (float)local_38;
      this[0x57] = (int)local_18;
      fVar18 = local_18 * local_18 - 2.0;
      fVar21 = 1.0;
      if (1.0 <= fVar18) {
        fVar21 = fVar18;
      }
      local_28 = (int *)(0.7 / fVar21);
      FUN_0040b7e0();
      piVar11 = local_20;
      fVar21 = local_1c;
      if ((float)local_28 < fVar22) {
        FUN_00410a20();
        piVar11 = (int *)((float)local_38 * (float)local_28);
        fVar21 = local_34 * (float)local_28;
        goto LAB_006b692b;
      }
    }
    else {
      fVar18 = 0.5;
      if (0.5 <= fVar21) {
        fVar18 = fVar21;
      }
      local_18 = 6.0;
      if (fVar18 <= 6.0) {
        local_18 = fVar18;
      }
      this[0x57] = (int)local_18;
      fVar18 = (float)local_38 * (float)local_38 + local_34 * local_34;
      FUN_0040b7e0();
      piVar11 = local_20;
      fVar21 = local_1c;
      if (1.9 < fVar18) {
        FUN_00410a20();
        piVar11 = (int *)((float)local_38 * 1.9);
        fVar21 = local_34 * 1.9;
LAB_006b692b:
        this[0x58] = (int)piVar11;
        this[0x59] = (int)fVar21;
      }
    }
    fVar18 = (float)this[0x56];
    fVar22 = (float)this[0x62];
    if ((float)this[0x62] <= fVar18) {
      fVar22 = fVar18;
    }
    this[0x56] = (int)fVar22;
  }
  else {
    fVar21 = (float)this[0x59];
    piVar11 = (int *)this[0x58];
  }
  FUN_00475ee0(this + 0x55,this + 0x56,piVar11,fVar21);
  p_Var8 = DAT_0077241c;
  fVar21 = DAT_00772400;
  *(undefined4 *)((int)DAT_00772400 + 0x35c) = 0xf;
  if (((p_Var8 != (LPCRITICAL_SECTION)0x0) && (0 < *(int *)((int)fVar21 + 0x6c))) &&
     (*(char *)((int)&p_Var8[1].LockSemaphore + 1) != '\0')) {
    iVar9 = 0;
    do {
      local_38 = (int *)(float)*(int *)((int)fVar21 + 0x1c8);
      local_34 = (float)*(int *)((int)fVar21 + 0x1cc);
      local_30 = (float)iVar9 * 0.5 + 7.0;
      FUN_00479150(&local_44,&local_38);
      local_3c = (local_3c - 7.0) + (local_3c - 7.0);
      FUN_0055a6a0(&local_44,iVar9);
      fVar21 = DAT_00772400;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x10);
    iVar9 = 0x10;
    *(undefined4 *)((int)DAT_00772400 + 0x35c) = 0x10;
    do {
      uVar7 = iVar9 - 1;
      *(uint *)((int)fVar21 + 0x35c) = uVar7;
      if (uVar7 == 0xffffffff) {
        fVar21 = *(float *)((int)fVar21 + 0x350);
      }
      else {
        if ((int)uVar7 < 0) {
          uVar7 = 0;
        }
        if (0xf < (int)uVar7) {
          uVar7 = 0xf;
        }
        if (uVar7 < 0x20) {
          fVar21 = (float)((int)fVar21 + uVar7 * 0xc);
        }
        else {
          (*pcVar17)(0xc000008c,1,0,0);
        }
        fVar21 = *(float *)((int)fVar21 + 0x1d0);
      }
      fVar18 = DAT_00772400;
      local_2c = (LPCRITICAL_SECTION)(fVar21 * 8.0);
      DAT_00772dd8 = (undefined4 *)(int)ROUND((float)local_2c);
      uVar7 = *(uint *)((int)DAT_00772400 + 0x35c);
      local_28 = DAT_00772dd8;
      if (uVar7 == 0xffffffff) {
        fVar21 = *(float *)((int)DAT_00772400 + 0x354);
      }
      else {
        if ((int)uVar7 < 0) {
          uVar7 = 0;
        }
        if (0xf < (int)uVar7) {
          uVar7 = 0xf;
        }
        if (uVar7 < 0x20) {
          fVar18 = (float)((int)DAT_00772400 + uVar7 * 0xc);
        }
        else {
          (*pcVar17)(0xc000008c,1,0,0);
        }
        fVar21 = *(float *)((int)fVar18 + 0x1d4);
      }
      piVar11 = local_28;
      puVar2 = (undefined4 *)(int)ROUND(fVar21 * 8.0);
      local_2c = DAT_0077241c;
      uVar7 = *(uint *)((int)DAT_00772400 + 0x35c);
      DAT_00772dd8 = puVar2;
      if (((DAT_0077241c[6].LockCount <= (int)local_28) &&
          ((int)local_28 < (int)DAT_0077241c[6].OwningThread)) &&
         ((DAT_0077241c[6].RecursionCount <= (int)puVar2 &&
          ((int)puVar2 < (int)DAT_0077241c[6].LockSemaphore)))) {
        piVar15 = (int *)FUN_00592f10((int)local_28 >> 3,(int)puVar2 >> 3);
        iVar9 = *piVar15;
        p_Var8 = local_2c + 1;
        local_2c = (LPCRITICAL_SECTION)((int)p_Var8->OwningThread + 0x10);
        if ((iVar9 < 0) || (*(int *)((int)p_Var8->OwningThread + 0x14) <= iVar9)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          p_Var16 = local_2c->DebugInfo;
        }
        else {
          p_Var16 = (PRTL_CRITICAL_SECTION_DEBUG)(iVar9 * 0x59 + (int)local_2c->DebugInfo);
        }
        uVar7 = (uint)*(byte *)((int)&p_Var16->Type + (((uint)puVar2 & 7) << 3 | (uint)piVar11 & 7))
        ;
      }
      iVar9 = *(int *)((int)DAT_00772400 + 0x35c);
      pcVar17 = RaiseException_exref;
      fVar21 = DAT_00772400;
      this = local_24;
    } while ((int)uVar7 < iVar9);
  }
  if ((*(char *)((int)fVar21 + 0x590) != '\0') && (*(char *)((int)this + 0xe9) != '\0')) {
    FUN_0040b980(0);
    fVar21 = DAT_00772400;
  }
  dVar19 = (double)(float)this[0x57];
  if (dVar19 < 0.0) {
    __libm_sse2_sqrt_precise();
  }
  else {
    dVar19 = SQRT(dVar19);
  }
  *(float *)((int)fVar21 + 0x360) = (float)dVar19 + (float)dVar19;
  *(int *)((int)fVar21 + 0x360) = this[0x57];
  uVar7 = *(uint *)((int)fVar21 + 0x35c);
  if (uVar7 == 0xffffffff) {
    local_3c = *(float *)((int)fVar21 + 0x358);
    local_40 = *(undefined4 *)((int)fVar21 + 0x354);
    local_44 = *(undefined4 *)((int)fVar21 + 0x350);
  }
  else {
    if ((int)uVar7 < 0) {
      uVar7 = 0;
    }
    if (0xf < (int)uVar7) {
      uVar7 = 0xf;
    }
    if (uVar7 < 0x20) {
      fVar21 = (float)((int)fVar21 + uVar7 * 0xc);
    }
    else {
      (*pcVar17)(0xc000008c,1,0,0);
    }
    local_3c = *(float *)((int)fVar21 + 0x1d8);
    local_40 = *(undefined4 *)((int)fVar21 + 0x1d4);
    local_44 = *(undefined4 *)((int)fVar21 + 0x1d0);
  }
  FUN_0055a6a0(&local_44,0xffffffff);
  fVar21 = local_14;
  if (((*(char *)((int)&DAT_0077241c[1].LockSemaphore + 1) != '\0') && (DAT_00767974 != '\0')) &&
     (DAT_00c3c9dc == 0)) {
    if ((*(int *)((int)local_14 + 4) < DAT_00ca7f08) &&
       (FUN_006cebf4(&DAT_00ca7f08), iVar9 = DAT_00783650, DAT_00ca7f08 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00ca7f0c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() CDisplay::Draw()";
      *(int *)(&DAT_00773650 + iVar12) = iVar9;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7f08);
    }
    FUN_00405af0(&DAT_00ca7f0c);
    local_8 = 0xb;
    CDisplay__Draw();
    local_8 = 0xffffffff;
    FUN_0043fd30();
  }
  if ((char)this[0x29] != '\0') {
    if ((*(int *)((int)fVar21 + 4) < DAT_00ca7f10) &&
       (FUN_006cebf4(&DAT_00ca7f10), iVar9 = DAT_00783650, DAT_00ca7f10 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00ca7f14 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() Render Sync 1";
      *(int *)(&DAT_00773650 + iVar12) = iVar9;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7f10);
    }
    FUN_00405af0(&DAT_00ca7f14);
    this[0x26] = 0;
    FUN_0043fd30();
  }
  p_Var8 = DAT_0077241c;
  if ((*(char *)((int)DAT_00772400 + 0x590) != '\0') && (800 < *(int *)((int)DAT_00772400 + 0x7c)))
  {
    DAT_00c3c9d8 = DAT_00c3c9d8 + 1 & 0x1ff;
  }
  *(undefined4 *)((int)DAT_00772400 + 0x74) = 0;
  if (*(char *)((int)&p_Var8[1].LockSemaphore + 1) != '\0') {
    if ((*(int *)((int)fVar21 + 4) < DAT_00ca7f18) &&
       (FUN_006cebf4(&DAT_00ca7f18), iVar9 = DAT_00783650, DAT_00ca7f18 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00ca7f1c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() EndBuildFrame";
      *(int *)(&DAT_00773650 + iVar12) = iVar9;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7f18);
    }
    FUN_00405af0(&DAT_00ca7f1c);
    local_8 = 0xc;
    iVar9 = FUN_0044d010();
    p_Var8 = (LPCRITICAL_SECTION)(iVar9 + 0x22bc);
    local_2c = p_Var8;
    EnterCriticalSection(p_Var8);
    *(undefined1 *)(iVar9 + 0x22d4) = 1;
    local_8 = CONCAT31(local_8._1_3_,0xd);
    FUN_00450850();
    puVar2 = *(undefined4 **)(iVar9 + 0x22dc);
    if (*(int *)(iVar9 + 0x22e4) == 0) {
      *(undefined4 **)(iVar9 + 0x22e4) = puVar2;
    }
    else if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(iVar9 + 0x22dc) = *(undefined4 *)(iVar9 + 0x22d8);
    *(undefined4 *)(iVar9 + 0x22d8) = 0;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    *(undefined1 *)(iVar9 + 0x22d4) = 0;
    LeaveCriticalSection(p_Var8);
    if ((char)this[0x29] == '\0') {
      CGameThread__Draw();
    }
    else {
      if ((*(int *)((int)fVar21 + 4) < DAT_00ca7f20) &&
         (FUN_006cebf4(&DAT_00ca7f20), iVar9 = DAT_00783650, DAT_00ca7f20 == -1)) {
        iVar12 = DAT_00783650 * 0x40;
        _DAT_00ca7f24 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() Render Sync 2";
        *(int *)(&DAT_00773650 + iVar12) = iVar9;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca7f20);
      }
      FUN_00405af0(&DAT_00ca7f24);
      *(undefined4 *)(*(int *)((int)DAT_00772400 + 0x5a0) + 0xac) = 1;
      FUN_0043fd30();
    }
    FUN_0043fd30();
  }
  FUN_0043e3c0();
  GetTickCount();
  if ((*(int *)((int)fVar21 + 4) < DAT_00ca7f28) &&
     (FUN_006cebf4(&DAT_00ca7f28), iVar9 = DAT_00783650, DAT_00ca7f28 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    _DAT_00ca7f2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() StatusUpdate";
    *(int *)(&DAT_00773650 + iVar12) = iVar9;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7f28);
  }
  FUN_00405af0(&DAT_00ca7f2c);
LAB_006b7090:
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

