
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CFluid__Draw(CFluid *this)

{
  float fVar1;
  CMap *pCVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float *in_stack_00000004;
  float *in_stack_00000008;
  float *in_stack_0000000c;
  float *in_stack_00000010;
  float **ppfVar19;
  int iStack_3c;
  uint uStack_38;
  int iStack_34;
  int local_30;
  uint local_2c;
  float *local_28;
  uint local_24;
  float *local_20;
  float *local_18;
  float *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706035;
  local_10 = ExceptionList;
  if (*(char *)(DAT_00772400 + 0x98) == '\0') {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  ExceptionList = &local_10;
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5468) &&
     (FUN_006cebf4(&DAT_00ca5468,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca5468 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    _DAT_00ca546c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "CFluid::Draw";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5468);
  }
  FUN_00405af0(&DAT_00ca546c);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (this->c_cb5 != '\0') {
    FUN_0056f5e0();
    FUN_0056fb00();
    FUN_00570000();
  }
  pCVar2 = PTR_0077241c;
  fVar16 = *in_stack_00000004;
  fVar14 = *in_stack_00000008;
  fVar15 = fVar16;
  if (fVar14 < fVar16) {
    fVar15 = fVar14;
  }
  fVar17 = *in_stack_0000000c;
  if (fVar17 < fVar15) {
    fVar15 = fVar17;
  }
  fVar1 = *in_stack_00000010;
  if (fVar1 < fVar15) {
    fVar15 = fVar1;
  }
  fVar18 = in_stack_00000008[1];
  fVar12 = fVar18;
  if (in_stack_00000004[1] <= fVar18) {
    fVar12 = in_stack_00000004[1];
  }
  fVar13 = in_stack_0000000c[1];
  if (fVar12 <= in_stack_0000000c[1]) {
    fVar13 = fVar12;
  }
  fVar12 = in_stack_00000010[1];
  if (fVar13 <= in_stack_00000010[1]) {
    fVar12 = fVar13;
  }
  if (fVar16 < fVar14) {
    fVar16 = fVar14;
  }
  if (fVar16 < fVar17) {
    fVar16 = fVar17;
  }
  if (fVar16 < fVar1) {
    fVar16 = fVar1;
  }
  if (fVar18 <= in_stack_00000004[1]) {
    fVar18 = in_stack_00000004[1];
  }
  fVar14 = in_stack_0000000c[1];
  if (in_stack_0000000c[1] <= fVar18) {
    fVar14 = fVar18;
  }
  fVar17 = in_stack_00000010[1];
  if (in_stack_00000010[1] <= fVar14) {
    fVar17 = fVar14;
  }
  iStack_34 = (int)fVar17 + 4;
  iStack_3c = (int)fVar12 + -4;
  uStack_38 = (int)fVar16 + 4;
  this->i_14 = (int)fVar15 + -4;
  this->i_18 = iStack_3c;
  this->i_1c = uStack_38;
  this->i_20 = iStack_34;
  iVar3 = pCVar2->cellX0;
  if (pCVar2->cellX0 <= this->i_14) {
    iVar3 = this->i_14;
  }
  this->i_14 = iVar3;
  iVar7 = pCVar2->cellY0;
  if (pCVar2->cellY0 <= this->i_18) {
    iVar7 = this->i_18;
  }
  this->i_18 = iVar7;
  iVar7 = pCVar2->cellX1;
  if (this->i_1c <= pCVar2->cellX1) {
    iVar7 = this->i_1c;
  }
  this->i_1c = iVar7;
  iVar8 = pCVar2->cellY1;
  if (this->i_20 <= pCVar2->cellY1) {
    iVar8 = this->i_20;
  }
  this->i_20 = iVar8;
  if (((iVar7 == iVar3 || iVar7 - iVar3 < 0) || (iVar8 == this->i_18 || iVar8 - this->i_18 < 0)) ||
     (FUN_005763e0(this), this->c_cac != '\0')) goto LAB_00577a8a;
  if (this->i_c98 == 0) {
    FUN_006b8fb0("alpha.tga");
    ppfVar19 = &local_18;
    local_8._0_1_ = 1;
    FUN_0044d010(ppfVar19);
    iVar3 = FUN_0044bf20(ppfVar19);
    this->i_c98 = iVar3;
    local_8._0_1_ = 2;
    if ((local_18 != (float *)0x0) && (*local_18 = (float)((int)*local_18 + -1), *local_18 == 0.0))
    {
      FUN_006ba940();
    }
    local_8._0_1_ = 0;
  }
  if (this->i_c94 == 0) {
    FUN_006b8fb0("wasser_env.tga");
    ppfVar19 = &local_18;
    local_8._0_1_ = 3;
    FUN_0044d010(ppfVar19);
    iVar3 = FUN_0044bf20(ppfVar19);
    this->i_c94 = iVar3;
    local_8._0_1_ = 4;
    if ((local_18 != (float *)0x0) && (*local_18 = (float)((int)*local_18 + -1), *local_18 == 0.0))
    {
      FUN_006ba940();
    }
    local_8._0_1_ = 0;
  }
  if (this->i_ca0 == 0) {
    FUN_006b8fb0("alpha.tga");
    ppfVar19 = &local_18;
    local_8._0_1_ = 5;
    FUN_0044d010(ppfVar19);
    iVar3 = FUN_0044bf20(ppfVar19);
    this->i_ca0 = iVar3;
    local_8._0_1_ = 6;
    if ((local_18 != (float *)0x0) && (*local_18 = (float)((int)*local_18 + -1), *local_18 == 0.0))
    {
      FUN_006ba940();
    }
    local_8._0_1_ = 0;
  }
  if (this->i_c9c == 0) {
    FUN_006b8fb0("schwef_nahtlos.tga");
    ppfVar19 = &local_18;
    local_8._0_1_ = 7;
    FUN_0044d010(ppfVar19);
    iVar3 = FUN_0044bf20(ppfVar19);
    this->i_c9c = iVar3;
    local_8._0_1_ = 8;
    if ((local_18 != (float *)0x0) && (*local_18 = (float)((int)*local_18 + -1), *local_18 == 0.0))
    {
      FUN_006ba940();
    }
    local_8._0_1_ = 0;
  }
  if (this->i_ca8 == 0) {
    FUN_006b8fb0("alpha.tga");
    ppfVar19 = &local_18;
    local_8._0_1_ = 9;
    FUN_0044d010(ppfVar19);
    iVar3 = FUN_0044bf20(ppfVar19);
    this->i_ca8 = iVar3;
    local_8._0_1_ = 10;
    if ((local_18 != (float *)0x0) && (*local_18 = (float)((int)*local_18 + -1), *local_18 == 0.0))
    {
      FUN_006ba940();
    }
    local_8._0_1_ = 0;
  }
  if (this->i_ca4 == 0) {
    FUN_006b8fb0("lava_nahtlos.tga");
    ppfVar19 = &local_18;
    local_8._0_1_ = 0xb;
    FUN_0044d010(ppfVar19);
    iVar3 = FUN_0044bf20(ppfVar19);
    this->i_ca4 = iVar3;
    local_8._0_1_ = 0xc;
    if ((local_18 != (float *)0x0) && (*local_18 = (float)((int)*local_18 + -1), *local_18 == 0.0))
    {
      FUN_006ba940();
    }
  }
  iStack_34 = 0;
  iStack_3c = *(int *)(*(int *)(DAT_00772400 + 0x5a4) + 0x160);
  uStack_38 = *(uint *)(*(int *)(DAT_00772400 + 0x5a4) + 0x164) ^ 0x80000000;
  FUN_0047ec30(&iStack_3c);
  FUN_0047eaf0(&this->field_0xc2c);
  fVar16 = *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158);
  local_28 = (float *)0x0;
  local_24 = 0;
  this->f_c5c = this->f_c5c + *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) * 0.1;
  this->f_c60 = fVar16 * 0.1 + this->f_c60;
  this->f_c64 = this->f_c64 + 0.0;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8._0_1_ = 0xe;
  local_18 = (float *)FUN_006ba810(0x9b);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  pcVar10 = RaiseException_exref;
  local_24 = local_24 + 1;
  local_28 = local_18;
  if (local_24 == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  pfVar4 = local_28;
  *local_28 = *in_stack_00000004;
  local_28[1] = in_stack_00000004[1];
  local_28[2] = in_stack_00000004[2];
  uVar9 = local_24 + 0x100 & 0xffffff00;
  if (uVar9 != (local_24 + 0xff & 0xffffff00)) {
    local_18 = (float *)(uVar9 * 0xc);
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 0x10;
    if (pfVar4 == (float *)0x0) {
      pfVar4 = (float *)FUN_006ba810(0x9b);
      local_8 = CONCAT31(local_8._1_3_,0xd);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_28 = pfVar4;
    }
    else {
      if (local_18 == (float *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 0x11;
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        iVar3 = FUN_006ba730();
        if (iVar3 == 0) {
          local_14 = (float *)pfVar4[-2];
          local_20 = (float *)((int)local_14 + (int)pfVar4);
          iVar3 = FUN_006ba730();
          if (iVar3 != 0) goto LAB_00577223;
          if (pfVar4[-5] != 0.0) {
            *(float *)((int)pfVar4[-5] + 4) = pfVar4[-6];
          }
          if (pfVar4[-6] != 0.0) {
            *(float *)((int)pfVar4[-6] + 8) = pfVar4[-5];
          }
          if (pfVar4 + -7 == DAT_00c3c81c) {
            DAT_00c3c81c = (float *)pfVar4[-6];
          }
          _memset(pfVar4,-0x20202021,(size_t)local_14);
          pfVar5 = pfVar4 + -7;
          bVar11 = DAT_0077248f == '\0';
          *pfVar5 = -3.2263715e+19;
          pfVar4[-1] = -3.2263715e+19;
          *local_20 = -3.2263715e+19;
          if (((bVar11) || (DAT_00c1c788 == '\0')) ||
             ((pfVar5 < DAT_00c3c7cc || ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar5)))) {
            FUN_006df631(pfVar5);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_00577223:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar4,iVar3);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      else {
        LOCK();
        _DAT_00c3c82c = _DAT_00c3c82c + 1;
        UNLOCK();
        local_14 = pfVar4 + -7;
        iVar3 = FUN_006ba730();
        if ((iVar3 == 0) && (iVar3 = FUN_006ba730(), iVar3 == 0)) {
          pfVar4 = local_18 + 8;
          if ((DAT_0077248f == '\0') ||
             (((DAT_00c1c788 == '\0' || (local_14 < DAT_00c3c7cc)) ||
              ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_14)))) {
            pfVar5 = (float *)FUN_006df8de(local_14,pfVar4);
            local_20 = pfVar5;
            if (pfVar5 == (float *)0x0) {
              FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",pfVar4,local_14)
              ;
              MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
              pfVar5 = local_20;
              goto LAB_00577415;
            }
          }
          else {
            pfVar5 = (float *)FUN_006b8a90();
LAB_00577415:
            if (pfVar5 == (float *)0x0) goto LAB_00577314;
          }
          if (local_14 == DAT_00c3c81c) {
            DAT_00c3c81c = pfVar5;
          }
          pfVar5[5] = (float)local_18;
          if (pfVar5[1] != 0.0) {
            *(float **)((int)pfVar5[1] + 8) = pfVar5;
          }
          if (pfVar5[2] != 0.0) {
            *(float **)((int)pfVar5[2] + 4) = pfVar5;
          }
          *(undefined4 *)((int)(pfVar5 + 7) + (int)local_18) = 0xfab1ffcd;
          local_8 = CONCAT31(local_8._1_3_,0xd);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_28 = pfVar5 + 7;
          goto LAB_0057746d;
        }
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar4,iVar3);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
LAB_00577314:
      local_8 = CONCAT31(local_8._1_3_,0xd);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_28 = (float *)0x0;
    }
  }
LAB_0057746d:
  local_24 = local_24 + 1;
  if (local_24 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  pfVar4 = local_28;
  local_28[3] = *in_stack_00000008;
  local_28[4] = in_stack_00000008[1];
  local_28[5] = in_stack_00000008[2];
  uVar9 = local_24 + 0x100 & 0xffffff00;
  if (uVar9 != (local_24 + 0xff & 0xffffff00)) {
    local_18 = (float *)(uVar9 * 0xc);
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 0x12;
    if (pfVar4 == (float *)0x0) {
      pfVar6 = (float *)FUN_006ba810(0x9b);
LAB_005777b6:
      local_8 = CONCAT31(local_8._1_3_,0xd);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_28 = pfVar6;
    }
    else {
      if (local_18 == (float *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 0x13;
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        iVar3 = FUN_006ba730();
        if (iVar3 == 0) {
          local_20 = (float *)pfVar4[-2];
          local_18 = (float *)((int)local_20 + (int)pfVar4);
          iVar3 = FUN_006ba730();
          if (iVar3 != 0) goto LAB_00577589;
          if (pfVar4[-5] != 0.0) {
            *(float *)((int)pfVar4[-5] + 4) = pfVar4[-6];
          }
          if (pfVar4[-6] != 0.0) {
            *(float *)((int)pfVar4[-6] + 8) = pfVar4[-5];
          }
          if (pfVar4 + -7 == DAT_00c3c81c) {
            DAT_00c3c81c = (float *)pfVar4[-6];
          }
          _memset(pfVar4,-0x20202021,(size_t)local_20);
          pfVar5 = pfVar4 + -7;
          bVar11 = DAT_0077248f == '\0';
          *pfVar5 = -3.2263715e+19;
          pfVar4[-1] = -3.2263715e+19;
          *local_18 = -3.2263715e+19;
          if (((bVar11) || (DAT_00c1c788 == '\0')) ||
             ((pfVar5 < DAT_00c3c7cc || ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar5)))) {
            FUN_006df631(pfVar5);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_00577589:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar4,iVar3);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      else {
        LOCK();
        _DAT_00c3c82c = _DAT_00c3c82c + 1;
        UNLOCK();
        pfVar5 = pfVar4 + -7;
        iVar3 = FUN_006ba730();
        if ((iVar3 == 0) && (iVar3 = FUN_006ba730(), iVar3 == 0)) {
          pfVar4 = local_18 + 8;
          if ((DAT_0077248f == '\0') ||
             (((DAT_00c1c788 == '\0' || (pfVar5 < DAT_00c3c7cc)) ||
              ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar5)))) {
            pfVar6 = (float *)FUN_006df8de(pfVar5,pfVar4);
            local_20 = pfVar6;
            if (pfVar6 == (float *)0x0) {
              FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",pfVar4,pfVar5);
              MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
              pfVar6 = local_20;
              goto LAB_00577779;
            }
          }
          else {
            pfVar6 = (float *)FUN_006b8a90();
LAB_00577779:
            if (pfVar6 == (float *)0x0) goto LAB_00577678;
          }
          if (pfVar5 == DAT_00c3c81c) {
            DAT_00c3c81c = pfVar6;
          }
          pfVar6[5] = (float)local_18;
          if (pfVar6[1] != 0.0) {
            *(float **)((int)pfVar6[1] + 8) = pfVar6;
          }
          if (pfVar6[2] != 0.0) {
            *(float **)((int)pfVar6[2] + 4) = pfVar6;
          }
          *(undefined4 *)((int)(local_18 + 7) + (int)pfVar6) = 0xfab1ffcd;
          pfVar6 = pfVar6 + 7;
          goto LAB_005777b6;
        }
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar4,iVar3);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
LAB_00577678:
      local_8 = CONCAT31(local_8._1_3_,0xd);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_28 = (float *)0x0;
    }
  }
  local_24 = local_24 + 1;
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_28[6] = *in_stack_00000010;
  local_28[7] = in_stack_00000010[1];
  local_28[8] = in_stack_00000010[2];
  FUN_00448980(1);
  if (local_24 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_28[9] = *in_stack_0000000c;
  local_28[10] = in_stack_0000000c[1];
  local_28[0xb] = in_stack_0000000c[2];
  local_30 = 0;
  local_2c = 0;
  local_8 = CONCAT31(local_8._1_3_,0x14);
  FUN_00445dd0(&local_30,&local_28);
  FUN_00445e40();
  in_stack_00000008 = (float *)0x0;
  if (0 < (int)local_2c) {
    bVar11 = local_2c != 0;
    in_stack_00000010 = (float *)0x0;
    do {
      if (!bVar11) {
        (*pcVar10)(0xc000008c,1,0,0);
      }
      iVar3 = *(int *)(local_30 + (int)in_stack_00000010);
      if (local_2c <= in_stack_00000008) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar7 = *(int *)(local_30 + 4 + (int)in_stack_00000010);
      if ((this->i_18 + 1 < iVar7) && (iVar7 < this->i_20 + -2)) {
        in_stack_0000000c = (float *)0x0;
LAB_005778d0:
        if (local_2c <= in_stack_00000008) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*(int *)(local_30 + 8 + (int)in_stack_00000010) <= (int)in_stack_0000000c)
        goto LAB_00577a01;
        if ((this->i_14 + 1 < iVar3) && (iVar3 < this->i_1c + -2)) {
          iVar8 = ((this->i_1c - this->i_14) * (iVar7 - this->i_18) - this->i_14) + iVar3;
          if ((iVar8 < 0) || (this->i_28 <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = this->i_24;
          }
          else {
            iVar8 = iVar8 * 0x40 + this->i_24;
          }
          *(undefined1 *)(iVar8 + 0x31) = 1;
          if (this->c_cb5 != '\0') {
            FUN_0056e320(iVar3,iVar7);
            iVar3 = iVar3 + 1;
            in_stack_0000000c = (float *)((int)in_stack_0000000c + 1);
            goto LAB_005778d0;
          }
          iVar8 = ((this->i_1c - this->i_14) * (iVar7 - this->i_18) - this->i_14) + iVar3;
          if ((iVar8 < 0) || (this->i_28 <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = this->i_24;
          }
          else {
            iVar8 = iVar8 * 0x40 + this->i_24;
          }
          switch(*(byte *)(iVar8 + 8) & 7) {
          case 1:
            FUN_005716e0(iVar3,iVar7);
            iVar3 = iVar3 + 1;
            in_stack_0000000c = (float *)((int)in_stack_0000000c + 1);
            goto LAB_005778d0;
          case 2:
            FUN_00573250(iVar3,iVar7);
            iVar3 = iVar3 + 1;
            in_stack_0000000c = (float *)((int)in_stack_0000000c + 1);
            goto LAB_005778d0;
          case 3:
          case 4:
            FUN_00574c60(iVar3,iVar7);
          }
        }
        iVar3 = iVar3 + 1;
        in_stack_0000000c = (float *)((int)in_stack_0000000c + 1);
        goto LAB_005778d0;
      }
LAB_00577a01:
      in_stack_00000010 = (float *)((int)in_stack_00000010 + 0xc);
      in_stack_00000008 = (float *)((int)in_stack_00000008 + 1);
      bVar11 = in_stack_00000008 < local_2c;
      pcVar10 = RaiseException_exref;
    } while ((int)in_stack_00000008 < (int)local_2c);
  }
  local_8 = CONCAT31(local_8._1_3_,0x15);
  if ((int)local_2c < 0) {
    FUN_00448980(-local_2c);
  }
  else if (0 < (int)local_2c) {
    local_2c = 0;
    FUN_00448a90(0);
  }
  if (local_30 != 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x16;
  if ((int)local_24 < 0) {
    FUN_00448980(-local_24);
  }
  else if (0 < (int)local_24) {
    local_24 = 0;
    FUN_00448a90(0);
  }
  if (local_28 != (float *)0x0) {
    FUN_006ba940();
  }
LAB_00577a8a:
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

