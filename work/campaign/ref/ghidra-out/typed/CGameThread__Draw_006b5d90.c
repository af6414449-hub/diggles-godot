
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameThread__Draw(CGameThread *this)

{
  undefined1 *puVar1;
  char *pcVar2;
  uint *puVar3;
  HANDLE pvVar4;
  char cVar5;
  bool bVar6;
  uint uVar7;
  LPCRITICAL_SECTION p_Var8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int iVar12;
  DWORD DVar13;
  ULONG_PTR UVar14;
  int *piVar15;
  PRTL_CRITICAL_SECTION_DEBUG p_Var16;
  code *pcVar17;
  int *piVar18;
  float fVar19;
  double dVar20;
  undefined1 auVar21 [16];
  float fVar22;
  float fVar23;
  undefined8 uVar24;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  int *local_38;
  float local_34;
  float local_30;
  LPCRITICAL_SECTION local_2c;
  int *local_28;
  CGameThread *local_24;
  int *local_20;
  float local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  fVar22 = DAT_00772400;
  p_Var8 = DAT_0076a274;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712f43;
  local_10 = ExceptionList;
  uVar7 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)((int)DAT_00772400 + 0x78) = 0;
  *(undefined4 *)((int)fVar22 + 0x7c) = 0;
  *(undefined4 *)((int)fVar22 + 0x84) = 0;
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
  fVar22 = DAT_00772400;
  pcVar17 = RaiseException_exref;
  *(undefined8 *)((int)DAT_00772400 + 0xa0b8) = *(undefined8 *)((int)DAT_00772400 + 0xa088);
  auVar21 = ZEXT816(0);
  local_20 = (int *)0x0;
  if (*(float *)&this->field_0x134 <= -1000.0) {
    if (-1 < *(int *)((int)fVar22 + 0xa0d4)) {
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
    fVar22 = *(float *)&this->field_0x134;
    auVar21 = ZEXT416((uint)fVar22);
    if (fVar22 == -1.0) {
      uVar7 = 0;
      piVar18 = *(int **)((int)DAT_00772400 + 100);
      local_20 = (int *)(DAT_0077244c + 0x488);
      local_28 = piVar18;
      do {
        if (uVar7 < 0x2000) {
          piVar15 = local_20 + uVar7;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar15 = local_20;
          piVar18 = local_28;
        }
        iVar9 = *piVar15;
        if ((((iVar9 != 0) && (*(int **)(iVar9 + 0x36c) == piVar18)) &&
            (*(int *)(iVar9 + 0xd4) != 0)) && (*(int *)(*(int *)(iVar9 + 0xd4) + 0x54) == 1)) {
          auVar21 = ZEXT416(*(uint *)(iVar9 + 0xc));
          uVar7 = 0x2000;
          *(uint *)&this->field_0x154 = *(uint *)(iVar9 + 0xc);
          *(undefined4 *)&this->field_0x158 = *(undefined4 *)(iVar9 + 0x10);
          *(undefined4 *)&this->field_0x134 = 0xc47a0000;
          *(undefined4 *)&this->field_0x138 = 0xc47a0000;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 0x2000);
    }
    else if (this->field_0x140 == '\0') {
      *(undefined4 *)&this->field_0x15c = *(undefined4 *)&this->field_0x13c;
      *(undefined4 *)&this->field_0x160 = *(undefined4 *)&this->field_0x14c;
      *(undefined4 *)&this->field_0x164 = *(undefined4 *)&this->field_0x150;
      *(float *)&this->field_0x154 = fVar22;
      *(undefined4 *)&this->field_0x158 = *(undefined4 *)&this->field_0x138;
      *(undefined4 *)&this->field_0x134 = 0xc47a0000;
      *(undefined4 *)&this->field_0x138 = 0xc47a0000;
    }
    else {
      piVar18 = *(int **)&this->field_0xf0;
      puVar1 = &this->field_0xec;
      if (piVar18 != (int *)0x0) {
        local_28 = (int *)((int)piVar18 - 1);
        if (piVar18 <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_20 = *(int **)(*(int *)puVar1 + 8 + (int)local_28 * 0xc);
      }
      fVar22 = DAT_00772400;
      local_1c = ((float)*(double *)((int)DAT_00772400 + 0xa088) - *(float *)&this->field_0x130) *
                 *(float *)&this->field_0x144;
      auVar21 = ZEXT416((uint)local_1c);
      if ((float)local_20 <= local_1c) {
        *(undefined4 *)&this->field_0x134 = 0xc47a0000;
        *(undefined4 *)&this->field_0x138 = 0xc47a0000;
        this->field_0x140 = 0;
        if ((this->field_0x148 != '\0') &&
           (*(undefined1 *)((int)fVar22 + 0x8b) = 0, *(char *)((int)fVar22 + 0xa098) == '\0')) {
          *(undefined1 *)((int)fVar22 + 0xa098) = 1;
        }
      }
      else {
        local_28 = (int *)(*(uint *)&this->field_0xf0 - 1);
        if (*(uint *)&this->field_0xf0 <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_28 = *(int **)(*(int *)puVar1 + 4 + (int)local_28 * 0xc);
        fVar22 = (float)local_28;
        FUN_00463750();
        fVar22 = fVar22 / (float)local_28;
        local_28 = (int *)(*(uint *)&this->field_0xf0 - 1);
        fVar19 = 1.0 - fVar22;
        local_20 = (int *)(fVar19 * *(float *)&this->field_0xf4 +
                          fVar22 * *(float *)&this->field_0x100);
        local_18 = *(float *)&this->field_0xf8 * fVar19 + *(float *)&this->field_0x104 * fVar22;
        local_14 = *(float *)&this->field_0xfc * fVar19 + *(float *)&this->field_0x108 * fVar22;
        if (*(uint *)&this->field_0xf0 <= local_28) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_28 = *(int **)(*(int *)puVar1 + 4 + (int)local_28 * 0xc);
        piVar18 = local_28;
        FUN_00463750();
        fVar22 = (float)piVar18 / (float)local_28;
        *(int **)&this->field_0x154 = local_20;
        fVar19 = *(float *)&this->field_0x110 * (1.0 - fVar22) +
                 *(float *)&this->field_0x11c * fVar22;
        auVar21 = ZEXT416((uint)fVar19);
        *(float *)&this->field_0x158 = local_18;
        *(float *)&this->field_0x15c = local_14;
        *(float *)&this->field_0x160 =
             (1.0 - fVar22) * *(float *)&this->field_0x10c + fVar22 * *(float *)&this->field_0x118;
        *(float *)&this->field_0x164 = fVar19;
      }
    }
    FUN_0043fd30();
  }
  GetTickCount();
  if (((*(char *)((int)DAT_00772400 + 0x5c0) == '\0') ||
      (*(char *)((int)DAT_00772400 + 0x59d) == '\0')) || (DAT_0076a338->field_0x2839 != '\0')) {
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
      uVar24 = FUN_006bd180();
      iVar9 = (&DAT_00773654)[iVar12 * 0x10];
      *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar24;
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
  fVar22 = *ThreadLocalStoragePointer;
  local_14 = fVar22;
  if ((*(int *)((int)fVar22 + 4) < DAT_00ca7ec4) &&
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
  if ((*(int *)((int)fVar22 + 4) < DAT_00ca7ecc) &&
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
  dVar20 = auVar21._0_8_;
  if (*(int *)((int)local_18 + 0xa0e0) == *(int *)((int)local_18 + 0xa0c8)) {
    if (*(int *)((int)local_18 + 0xa0e0) != 0) {
      uVar7 = 0;
      do {
        dVar20 = auVar21._0_8_;
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
    dVar20 = auVar21._0_8_;
    uVar7 = 0;
    local_28 = (int *)p_Var8->LockCount;
    local_2c = p_Var8;
    if (0 < (int)local_28) {
      do {
        if ((uint)p_Var8->LockCount <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        dVar20 = auVar21._0_8_;
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
  fVar22 = local_14;
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
      if ((*(int *)((int)fVar22 + 4) < DAT_00ca7ef8) &&
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
      local_20 = *(int **)&this->field_0x15c;
      local_28 = *(int **)&this->field_0x158;
      local_2c = *(LPCRITICAL_SECTION *)&this->field_0x154;
      puVar11 = (undefined4 *)FUN_004d1090();
      *puVar11 = local_2c;
      puVar11[1] = local_28;
      dVar20 = (double)ZEXT48(local_20);
      puVar11[2] = local_20;
      FUN_004d1090();
      FUN_004d1570();
      local_2c = (LPCRITICAL_SECTION)FUN_004cfea0();
      if (*(int *)((int)fVar22 + 4) < DAT_00c8aeb4) {
                    /* WARNING: Read-only address (ram,0x00737900) is written */
        FUN_006cebf4(&DAT_00c8aeb4);
        if (DAT_00c8aeb4 == -1) {
          local_8._0_1_ = 8;
          DAT_00768890 = 0;
          _DAT_00768880 = _DAT_00737900;
          dVar20 = _DAT_00737900;
          if (DAT_00772400 != 0.0) {
            FUN_00565700(&DAT_00768880);
            iVar9 = _rand();
            dVar20 = (double)iVar9 * _DAT_00768888 * 3.0517578125e-05;
            _DAT_00768880 = dVar20;
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
  fVar22 = DAT_00772400;
  if (bVar6) {
    if (*(char *)((int)DAT_00772400 + 0x93) == '\0') {
      pcVar2 = (char *)((int)DAT_00772400 + 0x90);
      *(undefined1 *)((int)DAT_00772400 + 0x93) = 1;
      if ((*pcVar2 == '\0') || (*(char *)((int)fVar22 + 0x8f) == '\0')) {
        bVar6 = true;
      }
      else {
        bVar6 = false;
      }
      if (((*(char *)((int)fVar22 + 0x8b) == '\0') && (bVar6)) &&
         (*(char *)((int)fVar22 + 0xa098) == '\0')) {
        *(undefined1 *)((int)fVar22 + 0xa098) = 1;
      }
      FUN_0044d010();
      FUN_0044d1a0();
      SetCursorPos(*(int *)&DAT_0076a338->field_0x2830 / 2,*(int *)&DAT_0076a338->field_0x2834 / 2);
    }
  }
  else if (*(char *)((int)DAT_00772400 + 0x93) != '\0') {
    FUN_00501450();
    FUN_00502050();
    fVar22 = DAT_00772400;
    *(undefined1 *)((int)DAT_00772400 + 0x93) = 0;
    if ((DAT_007683d5 != '\0') && (*(char *)((int)fVar22 + 0xa098) != '\0')) {
      *(undefined1 *)((int)fVar22 + 0xa098) = 0;
    }
    iVar9 = FUN_0044d010();
    (**(code **)(**(int **)(iVar9 + 0xb8) + 0x10))();
  }
  bVar6 = CSdlWindow::GetActive(*(CSdlWindow **)&this->field_0x30);
  if (bVar6) {
    FUN_00440cf0();
    *(float *)((int)DAT_00772400 + 0x1a0) = (float)dVar20;
    EnterCriticalSection((LPCRITICAL_SECTION)&this->field_0x10);
    bVar6 = *(int *)&this->field_0x2c != 0;
    if (bVar6) {
      if (!bVar6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_20 = (int *)**(undefined4 **)&this->field_0x28;
    }
    else {
      local_20 = (int *)0x0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&this->field_0x10);
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
        EnterCriticalSection((LPCRITICAL_SECTION)&this->field_0x10);
        if (*(int *)&this->field_0x2c == 0) {
          piVar18 = (int *)0x0;
          local_20 = (int *)0x0;
        }
        else {
          if (*(int *)&this->field_0x2c == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar18 = (int *)**(undefined4 **)&this->field_0x28;
          local_20 = piVar18;
          FUN_00445250(&this->field_0x28);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&this->field_0x10);
        if (piVar18 == (int *)0x0) break;
        if (*piVar18 == *(int *)((int)DAT_00772400 + 0x1bc)) {
          uVar7 = piVar18[1];
          FUN_00464d60(uVar7 >> 0xe & 0x3fff,uVar7 & 0x3fff,(byte)(uVar7 >> 0x1e) & 1);
          iVar9 = *(int *)this;
          iVar12 = FUN_0044d010();
          (**(code **)(iVar9 + 0x34))(iVar12 + 0x10);
          piVar18 = local_20;
        }
        thunk_FUN_0060fc30(piVar18[3]);
        FUN_006cecd8(piVar18,0x10);
      }
      local_8 = 0xffffffff;
      FUN_0043fd30();
    }
    piVar18 = (int *)FUN_004e4550();
    DVar13 = GetTickCount();
    if (*(char *)((int)DAT_00772400 + 0x590) == '\0') {
      if (0 < *piVar18) {
        *piVar18 = *piVar18 + -1;
        goto LAB_006b6795;
      }
      if (99 < (int)(DVar13 - piVar18[1])) goto LAB_006b6795;
      if (0x27 < (int)(DVar13 - piVar18[1])) {
        FUN_00501450();
        FUN_00501ab0();
      }
    }
    else {
LAB_006b6795:
      piVar18[1] = DVar13;
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
        uVar24 = FUN_006bd180();
        UVar14 = p_Var8[0x4f798].SpinCount;
        p_Var8[0x4f799].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)(int)uVar24;
        p_Var8[0x4f799].LockCount = (int)((ulonglong)uVar24 >> 0x20);
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
    local_38 = *(int **)&this->field_0x160;
    local_34 = *(float *)&this->field_0x164;
    fVar22 = *(float *)&this->field_0x15c;
    local_30 = 0.0;
    local_20 = local_38;
    local_1c = local_34;
    if (*(char *)((int)DAT_00772400 + 0x598) == '\0') {
      fVar19 = 1.0;
      if (1.0 <= fVar22) {
        fVar19 = fVar22;
      }
      local_18 = 2.5;
      if (fVar19 <= 2.5) {
        local_18 = fVar19;
      }
      fVar23 = local_34 * local_34 + (float)local_38 * (float)local_38;
      *(float *)&this->field_0x15c = local_18;
      fVar19 = local_18 * local_18 - 2.0;
      fVar22 = 1.0;
      if (1.0 <= fVar19) {
        fVar22 = fVar19;
      }
      local_28 = (int *)(0.7 / fVar22);
      FUN_0040b7e0();
      piVar18 = local_20;
      fVar22 = local_1c;
      if ((float)local_28 < fVar23) {
        FUN_00410a20();
        piVar18 = (int *)((float)local_38 * (float)local_28);
        fVar22 = local_34 * (float)local_28;
        goto LAB_006b692b;
      }
    }
    else {
      fVar19 = 0.5;
      if (0.5 <= fVar22) {
        fVar19 = fVar22;
      }
      local_18 = 6.0;
      if (fVar19 <= 6.0) {
        local_18 = fVar19;
      }
      *(float *)&this->field_0x15c = local_18;
      fVar19 = (float)local_38 * (float)local_38 + local_34 * local_34;
      FUN_0040b7e0();
      piVar18 = local_20;
      fVar22 = local_1c;
      if (1.9 < fVar19) {
        FUN_00410a20();
        piVar18 = (int *)((float)local_38 * 1.9);
        fVar22 = local_34 * 1.9;
LAB_006b692b:
        *(int **)&this->field_0x160 = piVar18;
        *(float *)&this->field_0x164 = fVar22;
      }
    }
    fVar19 = *(float *)&this->field_0x158;
    fVar23 = *(float *)&this->field_0x188;
    if (*(float *)&this->field_0x188 <= fVar19) {
      fVar23 = fVar19;
    }
    *(float *)&this->field_0x158 = fVar23;
  }
  else {
    fVar22 = *(float *)&this->field_0x164;
    piVar18 = *(int **)&this->field_0x160;
  }
  FUN_00475ee0(&this->field_0x154,&this->field_0x158,piVar18,fVar22);
  p_Var8 = DAT_0077241c;
  fVar22 = DAT_00772400;
  *(undefined4 *)((int)DAT_00772400 + 0x35c) = 0xf;
  if (((p_Var8 != (LPCRITICAL_SECTION)0x0) && (0 < *(int *)((int)fVar22 + 0x6c))) &&
     (*(char *)((int)&p_Var8[1].LockSemaphore + 1) != '\0')) {
    iVar9 = 0;
    do {
      local_38 = (int *)(float)*(int *)((int)fVar22 + 0x1c8);
      local_34 = (float)*(int *)((int)fVar22 + 0x1cc);
      local_30 = (float)iVar9 * 0.5 + 7.0;
      FUN_00479150(&local_44,&local_38);
      local_3c = (local_3c - 7.0) + (local_3c - 7.0);
      FUN_0055a6a0(&local_44,iVar9);
      this = local_24;
      fVar22 = DAT_00772400;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x10);
    iVar9 = 0x10;
    *(undefined4 *)((int)DAT_00772400 + 0x35c) = 0x10;
    do {
      uVar7 = iVar9 - 1;
      *(uint *)((int)fVar22 + 0x35c) = uVar7;
      if (uVar7 == 0xffffffff) {
        fVar22 = *(float *)((int)fVar22 + 0x350);
      }
      else {
        if ((int)uVar7 < 0) {
          uVar7 = 0;
        }
        if (0xf < (int)uVar7) {
          uVar7 = 0xf;
        }
        if (uVar7 < 0x20) {
          fVar22 = (float)((int)fVar22 + uVar7 * 0xc);
        }
        else {
          (*pcVar17)(0xc000008c,1,0,0);
        }
        fVar22 = *(float *)((int)fVar22 + 0x1d0);
      }
      fVar19 = DAT_00772400;
      local_2c = (LPCRITICAL_SECTION)(fVar22 * 8.0);
      DAT_00772dd8 = (undefined4 *)(int)ROUND((float)local_2c);
      uVar7 = *(uint *)((int)DAT_00772400 + 0x35c);
      local_28 = DAT_00772dd8;
      if (uVar7 == 0xffffffff) {
        fVar22 = *(float *)((int)DAT_00772400 + 0x354);
      }
      else {
        if ((int)uVar7 < 0) {
          uVar7 = 0;
        }
        if (0xf < (int)uVar7) {
          uVar7 = 0xf;
        }
        if (uVar7 < 0x20) {
          fVar19 = (float)((int)DAT_00772400 + uVar7 * 0xc);
        }
        else {
          (*pcVar17)(0xc000008c,1,0,0);
        }
        fVar22 = *(float *)((int)fVar19 + 0x1d4);
      }
      piVar18 = local_28;
      puVar11 = (undefined4 *)(int)ROUND(fVar22 * 8.0);
      local_2c = DAT_0077241c;
      uVar7 = *(uint *)((int)DAT_00772400 + 0x35c);
      DAT_00772dd8 = puVar11;
      if (((DAT_0077241c[6].LockCount <= (int)local_28) &&
          ((int)local_28 < (int)DAT_0077241c[6].OwningThread)) &&
         ((DAT_0077241c[6].RecursionCount <= (int)puVar11 &&
          ((int)puVar11 < (int)DAT_0077241c[6].LockSemaphore)))) {
        piVar15 = (int *)FUN_00592f10((int)local_28 >> 3,(int)puVar11 >> 3);
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
        uVar7 = (uint)*(byte *)((int)&p_Var16->Type + (((uint)puVar11 & 7) << 3 | (uint)piVar18 & 7)
                               );
      }
      iVar9 = *(int *)((int)DAT_00772400 + 0x35c);
      pcVar17 = RaiseException_exref;
      fVar22 = DAT_00772400;
    } while ((int)uVar7 < iVar9);
  }
  if ((*(char *)((int)fVar22 + 0x590) != '\0') && (this->field_0xe9 != '\0')) {
    FUN_0040b980(0);
    fVar22 = DAT_00772400;
  }
  dVar20 = (double)*(float *)&this->field_0x15c;
  if (dVar20 < 0.0) {
    __libm_sse2_sqrt_precise();
  }
  else {
    dVar20 = SQRT(dVar20);
  }
  *(float *)((int)fVar22 + 0x360) = (float)dVar20 + (float)dVar20;
  *(undefined4 *)((int)fVar22 + 0x360) = *(undefined4 *)&this->field_0x15c;
  uVar7 = *(uint *)((int)fVar22 + 0x35c);
  if (uVar7 == 0xffffffff) {
    local_3c = *(float *)((int)fVar22 + 0x358);
    local_40 = *(undefined4 *)((int)fVar22 + 0x354);
    local_44 = *(undefined4 *)((int)fVar22 + 0x350);
  }
  else {
    if ((int)uVar7 < 0) {
      uVar7 = 0;
    }
    if (0xf < (int)uVar7) {
      uVar7 = 0xf;
    }
    if (uVar7 < 0x20) {
      fVar22 = (float)((int)fVar22 + uVar7 * 0xc);
    }
    else {
      (*pcVar17)(0xc000008c,1,0,0);
    }
    local_3c = *(float *)((int)fVar22 + 0x1d8);
    local_40 = *(undefined4 *)((int)fVar22 + 0x1d4);
    local_44 = *(undefined4 *)((int)fVar22 + 0x1d0);
  }
  FUN_0055a6a0(&local_44,0xffffffff);
  fVar22 = local_14;
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
    CDisplay__Draw(DAT_0076a338);
    local_8 = 0xffffffff;
    FUN_0043fd30();
  }
  if (this->field_0xa4 != '\0') {
    if ((*(int *)((int)fVar22 + 4) < DAT_00ca7f10) &&
       (FUN_006cebf4(&DAT_00ca7f10), iVar9 = DAT_00783650, DAT_00ca7f10 == -1)) {
      iVar12 = DAT_00783650 * 0x40;
      _DAT_00ca7f14 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar12) = "CGameThread::Draw() Render Sync 1";
      *(int *)(&DAT_00773650 + iVar12) = iVar9;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7f10);
    }
    FUN_00405af0(&DAT_00ca7f14);
    *(undefined4 *)&this->field_0x98 = 0;
    FUN_0043fd30();
  }
  p_Var8 = DAT_0077241c;
  if ((*(char *)((int)DAT_00772400 + 0x590) != '\0') && (800 < *(int *)((int)DAT_00772400 + 0x7c)))
  {
    DAT_00c3c9d8 = DAT_00c3c9d8 + 1 & 0x1ff;
  }
  *(undefined4 *)((int)DAT_00772400 + 0x74) = 0;
  if (*(char *)((int)&p_Var8[1].LockSemaphore + 1) != '\0') {
    if ((*(int *)((int)fVar22 + 4) < DAT_00ca7f18) &&
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
    puVar11 = *(undefined4 **)(iVar9 + 0x22dc);
    if (*(int *)(iVar9 + 0x22e4) == 0) {
      *(undefined4 **)(iVar9 + 0x22e4) = puVar11;
    }
    else if (puVar11 != (undefined4 *)0x0) {
      (**(code **)*puVar11)(1);
    }
    *(undefined4 *)(iVar9 + 0x22dc) = *(undefined4 *)(iVar9 + 0x22d8);
    *(undefined4 *)(iVar9 + 0x22d8) = 0;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    *(undefined1 *)(iVar9 + 0x22d4) = 0;
    LeaveCriticalSection(p_Var8);
    if (this->field_0xa4 == '\0') {
      CGameThread__Draw(*(CGameThread **)((int)DAT_00772400 + 0x5a0));
    }
    else {
      if ((*(int *)((int)fVar22 + 4) < DAT_00ca7f20) &&
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
  if ((*(int *)((int)fVar22 + 4) < DAT_00ca7f28) &&
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

