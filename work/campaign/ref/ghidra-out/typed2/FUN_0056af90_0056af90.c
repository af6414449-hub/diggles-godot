
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056af90(float *param_1,float *param_2,float *param_3,float *param_4)

{
  int *piVar1;
  uint uVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  int in_ECX;
  CMap *this;
  undefined4 *puVar10;
  code *pcVar11;
  uint uVar12;
  bool bVar13;
  undefined4 **ppuVar14;
  char *pcVar15;
  int local_3c;
  uint local_38;
  float *local_34;
  uint local_30;
  uint local_2c;
  float *local_28;
  float *local_24;
  float *local_20;
  float *local_1c;
  undefined4 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar8 = DAT_00772400;
  puStack_c = &LAB_00705cb5;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if ((*(int *)(DAT_0077244c + 0x48c) != 0) &&
     ((*(byte *)(*(int *)(DAT_0077244c + 0x48c) + 0x3d0) & 1) == 0)) {
    return;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(iVar8 + 100);
  local_34 = (float *)0x0;
  local_30 = 0;
  local_8 = 0;
  local_14 = in_ECX;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8._0_1_ = 1;
  local_28 = (float *)FUN_006ba810(0x9b,uVar2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  pcVar11 = RaiseException_exref;
  local_30 = local_30 + 1;
  local_34 = local_28;
  if (local_30 == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  pfVar3 = local_34;
  *local_34 = *param_1;
  local_34[1] = param_1[1];
  local_34[2] = param_1[2];
  uVar2 = local_30 + 0x100 & 0xffffff00;
  if (uVar2 != (local_30 + 0xff & 0xffffff00)) {
    local_20 = (float *)(uVar2 * 0xc);
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 3;
    if (pfVar3 == (float *)0x0) {
      pfVar3 = (float *)FUN_006ba810(0x9b);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_34 = pfVar3;
    }
    else if (local_20 == (float *)0x0) {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8._0_1_ = 4;
      LOCK();
      _DAT_00c3c818 = _DAT_00c3c818 + 1;
      UNLOCK();
      iVar8 = FUN_006ba730();
      if (iVar8 == 0) {
        local_24 = (float *)pfVar3[-2];
        local_20 = (float *)((int)local_24 + (int)pfVar3);
        iVar8 = FUN_006ba730();
        if (iVar8 != 0) goto LAB_0056b195;
        if (pfVar3[-5] != 0.0) {
          *(float *)((int)pfVar3[-5] + 4) = pfVar3[-6];
          in_ECX = local_14;
        }
        if (pfVar3[-6] != 0.0) {
          *(float *)((int)pfVar3[-6] + 8) = pfVar3[-5];
          in_ECX = local_14;
        }
        if (pfVar3 + -7 == DAT_00c3c81c) {
          DAT_00c3c81c = (float *)pfVar3[-6];
        }
        _memset(pfVar3,-0x20202021,(size_t)local_24);
        pfVar9 = pfVar3 + -7;
        bVar13 = DAT_0077248f == '\0';
        *pfVar9 = -3.2263715e+19;
        pfVar3[-1] = -3.2263715e+19;
        *local_20 = -3.2263715e+19;
        if (((bVar13) || (DAT_00c1c788 == '\0')) ||
           ((pfVar9 < DAT_00c3c7cc || ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar9)))) {
          FUN_006df631(pfVar9);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_0056b195:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar3,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_34 = (float *)0x0;
    }
    else {
      LOCK();
      _DAT_00c3c82c = _DAT_00c3c82c + 1;
      UNLOCK();
      local_1c = pfVar3 + -7;
      iVar8 = FUN_006ba730();
      if ((iVar8 == 0) && (iVar8 = FUN_006ba730(), iVar5 = local_14, iVar8 == 0)) {
        puVar10 = local_20 + 8;
        if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (local_1c < DAT_00c3c7cc)) ||
           (in_ECX = local_14, (float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_1c)) {
          pfVar3 = (float *)FUN_006df8de(local_1c,puVar10);
          local_28 = pfVar3;
          if (pfVar3 == (float *)0x0) {
            FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",puVar10,local_1c);
            MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
            pfVar3 = local_28;
            goto LAB_0056b394;
          }
        }
        else {
          pfVar3 = (float *)FUN_006b8a90();
          in_ECX = iVar5;
LAB_0056b394:
          if (pfVar3 == (float *)0x0) goto LAB_0056b2ef;
        }
        if (local_1c == DAT_00c3c81c) {
          DAT_00c3c81c = pfVar3;
        }
        pfVar3[5] = (float)local_20;
        if (pfVar3[1] != 0.0) {
          *(float **)((int)pfVar3[1] + 8) = pfVar3;
        }
        if (pfVar3[2] != 0.0) {
          *(float **)((int)pfVar3[2] + 4) = pfVar3;
        }
        *(undefined4 *)((int)(pfVar3 + 7) + (int)local_20) = 0xfab1ffcd;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_34 = pfVar3 + 7;
      }
      else {
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar3,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
LAB_0056b2ef:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_34 = (float *)0x0;
      }
    }
  }
  local_30 = local_30 + 1;
  if (local_30 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  pfVar3 = local_34;
  local_34[3] = *param_2;
  local_34[4] = param_2[1];
  local_34[5] = param_2[2];
  uVar2 = local_30 + 0x100 & 0xffffff00;
  if (uVar2 != (local_30 + 0xff & 0xffffff00)) {
    local_20 = (float *)(uVar2 * 0xc);
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 5;
    if (pfVar3 == (float *)0x0) {
      pfVar3 = (float *)FUN_006ba810(0x9b);
    }
    else {
      if (local_20 == (float *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 6;
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        iVar8 = FUN_006ba730();
        if (iVar8 == 0) {
          local_28 = (float *)pfVar3[-2];
          local_24 = (float *)((int)local_28 + (int)pfVar3);
          iVar8 = FUN_006ba730();
          if (iVar8 != 0) goto LAB_0056b504;
          if (pfVar3[-5] != 0.0) {
            *(float *)((int)pfVar3[-5] + 4) = pfVar3[-6];
            in_ECX = local_14;
          }
          if (pfVar3[-6] != 0.0) {
            *(float *)((int)pfVar3[-6] + 8) = pfVar3[-5];
            in_ECX = local_14;
          }
          if (pfVar3 + -7 == DAT_00c3c81c) {
            DAT_00c3c81c = (float *)pfVar3[-6];
          }
          _memset(pfVar3,-0x20202021,(size_t)local_28);
          pfVar9 = pfVar3 + -7;
          bVar13 = DAT_0077248f == '\0';
          *pfVar9 = -3.2263715e+19;
          pfVar3[-1] = -3.2263715e+19;
          *local_24 = -3.2263715e+19;
          if (((bVar13) || (DAT_00c1c788 == '\0')) ||
             ((pfVar9 < DAT_00c3c7cc || ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar9)))) {
            FUN_006df631(pfVar9);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_0056b504:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar3,iVar8);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_34 = (float *)0x0;
        goto LAB_0056b755;
      }
      LOCK();
      _DAT_00c3c82c = _DAT_00c3c82c + 1;
      UNLOCK();
      pfVar9 = pfVar3 + -7;
      iVar8 = FUN_006ba730();
      if ((iVar8 != 0) || (iVar8 = FUN_006ba730(), iVar5 = local_14, iVar8 != 0)) {
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar3,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
LAB_0056b65c:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_34 = (float *)0x0;
        goto LAB_0056b755;
      }
      puVar10 = local_20 + 8;
      if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (pfVar9 < DAT_00c3c7cc)) ||
         (in_ECX = local_14, (float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar9)) {
        pfVar3 = (float *)FUN_006df8de(pfVar9,puVar10);
        local_28 = pfVar3;
        if (pfVar3 == (float *)0x0) {
          FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",puVar10,pfVar9);
          MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
          pfVar3 = local_28;
          goto LAB_0056b701;
        }
      }
      else {
        pfVar3 = (float *)FUN_006b8a90();
        in_ECX = iVar5;
LAB_0056b701:
        if (pfVar3 == (float *)0x0) goto LAB_0056b65c;
      }
      if (pfVar9 == DAT_00c3c81c) {
        DAT_00c3c81c = pfVar3;
      }
      pfVar3[5] = (float)local_20;
      if (pfVar3[1] != 0.0) {
        *(float **)((int)pfVar3[1] + 8) = pfVar3;
      }
      if (pfVar3[2] != 0.0) {
        *(float **)((int)pfVar3[2] + 4) = pfVar3;
      }
      *(undefined4 *)((int)(pfVar3 + 7) + (int)local_20) = 0xfab1ffcd;
      pfVar3 = pfVar3 + 7;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_34 = pfVar3;
  }
LAB_0056b755:
  local_30 = local_30 + 1;
  if (local_30 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  pfVar3 = local_34;
  local_34[6] = *param_4;
  local_34[7] = param_4[1];
  local_34[8] = param_4[2];
  uVar2 = local_30 + 0x100 & 0xffffff00;
  if (uVar2 == (local_30 + 0xff & 0xffffff00)) goto LAB_0056bac2;
  fVar4 = (float)(uVar2 * 0xc);
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8._0_1_ = 7;
  if (pfVar3 == (float *)0x0) {
    pfVar3 = (float *)FUN_006ba810(0x9b);
  }
  else {
    if (fVar4 == 0.0) {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_8._0_1_ = 8;
      LOCK();
      _DAT_00c3c818 = _DAT_00c3c818 + 1;
      UNLOCK();
      iVar8 = FUN_006ba730();
      if (iVar8 == 0) {
        fVar4 = pfVar3[-2];
        local_28 = (float *)((int)fVar4 + (int)pfVar3);
        iVar8 = FUN_006ba730();
        if (iVar8 != 0) goto LAB_0056b871;
        if (pfVar3[-5] != 0.0) {
          *(float *)((int)pfVar3[-5] + 4) = pfVar3[-6];
          in_ECX = local_14;
        }
        if (pfVar3[-6] != 0.0) {
          *(float *)((int)pfVar3[-6] + 8) = pfVar3[-5];
          in_ECX = local_14;
        }
        if (pfVar3 + -7 == DAT_00c3c81c) {
          DAT_00c3c81c = (float *)pfVar3[-6];
        }
        _memset(pfVar3,-0x20202021,(size_t)fVar4);
        pfVar9 = pfVar3 + -7;
        bVar13 = DAT_0077248f == '\0';
        *pfVar9 = -3.2263715e+19;
        pfVar3[-1] = -3.2263715e+19;
        *local_28 = -3.2263715e+19;
        if (((bVar13) || (DAT_00c1c788 == '\0')) ||
           ((pfVar9 < DAT_00c3c7cc || ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar9)))) {
          FUN_006df631(pfVar9);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_0056b871:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar3,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_34 = (float *)0x0;
      goto LAB_0056bac2;
    }
    LOCK();
    _DAT_00c3c82c = _DAT_00c3c82c + 1;
    UNLOCK();
    pfVar9 = pfVar3 + -7;
    iVar8 = FUN_006ba730();
    if ((iVar8 != 0) || (iVar8 = FUN_006ba730(), iVar5 = local_14, iVar8 != 0)) {
      if (DAT_00c3c7d4 != (FILE *)0x0) {
        FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar3,iVar8);
        _fflush(DAT_00c3c7d4);
      }
      if (DAT_00c3c828 != '\0') {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
LAB_0056b9c9:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_34 = (float *)0x0;
      goto LAB_0056bac2;
    }
    if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (pfVar9 < DAT_00c3c7cc)) ||
       (in_ECX = local_14, (float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar9)) {
      pfVar3 = (float *)FUN_006df8de(pfVar9,(int)fVar4 + 0x20U);
      local_28 = pfVar3;
      if (pfVar3 == (float *)0x0) {
        FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",(int)fVar4 + 0x20U,
                     pfVar9);
        MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
        pfVar3 = local_28;
        goto LAB_0056ba6e;
      }
    }
    else {
      pfVar3 = (float *)FUN_006b8a90();
      in_ECX = iVar5;
LAB_0056ba6e:
      if (pfVar3 == (float *)0x0) goto LAB_0056b9c9;
    }
    if (pfVar9 == DAT_00c3c81c) {
      DAT_00c3c81c = pfVar3;
    }
    pfVar3[5] = fVar4;
    if (pfVar3[1] != 0.0) {
      *(float **)((int)pfVar3[1] + 8) = pfVar3;
    }
    if (pfVar3[2] != 0.0) {
      *(float **)((int)pfVar3[2] + 4) = pfVar3;
    }
    pfVar3[uVar2 * 3 + 7] = -4.621124e+35;
    pfVar3 = pfVar3 + 7;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_34 = pfVar3;
LAB_0056bac2:
  local_30 = local_30 + 1;
  if (local_30 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_34[9] = *param_3;
  local_34[10] = param_3[1];
  local_34[0xb] = param_3[2];
  local_3c = 0;
  local_38 = 0;
  local_8._0_1_ = 9;
  FUN_00445dd0(&local_3c,&local_34);
  FUN_00445e40();
  param_4 = (float *)0x0;
  if (0 < (int)local_38) {
    bVar13 = local_38 != 0;
    param_3 = (float *)0x0;
    this = PTR_0077241c;
    do {
      if (!bVar13) {
        (*pcVar11)(0xc000008c,1,0,0);
        this = PTR_0077241c;
      }
      param_1 = *(float **)((int)param_3 + local_3c);
      if (local_38 <= param_4) {
        (*pcVar11)(0xc000008c,1,0,0);
        this = PTR_0077241c;
      }
      iVar8 = *(int *)((int)param_3 + 4 + local_3c);
      if ((this->cellY0 < iVar8) && (iVar8 < this->cellY1 + -2)) {
        local_20 = (float *)0x0;
        while( true ) {
          if (local_38 <= param_4) {
            (*pcVar11)(0xc000008c,1,0,0);
            this = PTR_0077241c;
          }
          if (*(int *)((int)param_3 + 8 + local_3c) <= (int)local_20) break;
          if ((this->cellX0 < (int)param_1) && ((int)param_1 < this->cellX1 + -2)) {
            iVar5 = FUN_00592f10(this);
            local_28 = (float *)(iVar5 + 8);
            iVar5 = FUN_00592f10(PTR_0077241c);
            iVar6 = FUN_00592f10(PTR_0077241c);
            iVar7 = FUN_00592f10(PTR_0077241c);
            FUN_0056ae30(param_1,iVar8,
                         *(uint *)(iVar7 + 8) >> ((byte)(*(int *)(local_14 + 0x11c) << 2) & 0x1f) &
                         0xf,*(uint *)(iVar6 + 8) >>
                             ((byte)(*(int *)(local_14 + 0x11c) << 2) & 0x1f) & 0xf,
                         *(uint *)(iVar5 + 8) >> ((byte)(*(int *)(local_14 + 0x11c) << 2) & 0x1f) &
                         0xf,(uint)*local_28 >> ((byte)(*(int *)(local_14 + 0x11c) << 2) & 0x1f) &
                             0xf,0);
            this = PTR_0077241c;
            pcVar11 = RaiseException_exref;
          }
          param_1 = (float *)((int)param_1 + 1);
          local_20 = (float *)((int)local_20 + 1);
        }
      }
      param_4 = (float *)((int)param_4 + 1);
      param_3 = (float *)((int)param_3 + 0xc);
      bVar13 = param_4 < local_38;
      in_ECX = local_14;
    } while ((int)param_4 < (int)local_38);
  }
  if (*(int *)(in_ECX + 0x108) != 0) {
    ppuVar14 = &local_18;
    pcVar15 = "DigMark 2";
    FUN_0044d010(ppuVar14,"DigMark 2");
    FUN_0044d570(ppuVar14,pcVar15);
    local_8._0_1_ = 0xc;
    if (local_18 != (undefined4 *)0x0) {
      local_18[3] = 4;
      local_18[2] = 0x26;
      local_18[4] = 1;
      local_18[5] = 0x32;
      local_18[0xf] = *(undefined4 *)(DAT_0076a338 + 0xac);
      local_18[0xe] = 0;
      local_18[0xd] = 0;
      local_18[0xc] = 0;
      local_18[0xb] = 0;
      local_18[10] = 0;
      local_18[9] = 0;
      local_18[8] = 0;
      local_18[7] = 0;
      local_18[6] = 0;
      iVar8 = FUN_006ba810(0x4a5);
      if (iVar8 == 0) {
        iVar8 = 0;
      }
      else {
        iVar8 = FUN_0045fae0();
      }
      puVar10 = (undefined4 *)local_18[0x11];
      local_18[0x11] = iVar8;
      if (iVar8 != 0) {
        LOCK();
        *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
        UNLOCK();
      }
      if (puVar10 != (undefined4 *)0x0) {
        LOCK();
        iVar8 = puVar10[1] + -1;
        puVar10[1] = iVar8;
        UNLOCK();
        if (iVar8 == 0) {
          (**(code **)*puVar10)(1);
        }
      }
      FUN_0045fd00(0x1c2,*(undefined4 *)(in_ECX + 0x108),0);
      FUN_0045fe20(*(undefined4 *)(in_ECX + 0x118),*(undefined4 *)(in_ECX + 0x10c));
      iVar8 = *(int *)(local_18[0x11] + 0x24);
      pfVar3 = (float *)FUN_0045feb0();
      iVar5 = 0;
      if (0 < *(int *)(in_ECX + 0x108)) {
        param_2 = (float *)0x0;
        param_1 = pfVar3;
        do {
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = *(float **)(in_ECX + 0xfc);
          }
          else {
            pfVar9 = (float *)((int)param_2 + *(int *)(in_ECX + 0xfc));
          }
          local_28 = (float *)(int)(*pfVar9 + 0.5);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_00592f10(PTR_0077241c);
          local_28 = *(float **)(DAT_00772400 + 0x6c);
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_20 = *(float **)(in_ECX + 0xfc);
            local_1c = local_20;
          }
          else {
            local_20 = *(float **)(in_ECX + 0xfc);
            local_1c = (float *)((int)param_2 + (int)local_20);
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = *(float **)(in_ECX + 0xfc);
            local_20 = pfVar9;
          }
          else {
            pfVar9 = (float *)((int)local_20 + (int)param_2);
          }
          local_28 = (float *)((float)(int)local_28 * 0.25);
          fVar4 = pfVar9[1] * 3.0 + *local_1c * 3.0 + (float)local_28;
          FUN_004089d0();
          local_24 = (float *)fVar4;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = *(int *)(in_ECX + 0xfc);
          }
          else {
            iVar6 = (int)local_20 + (int)param_2;
          }
          if (*(int *)(iVar6 + 0xc) == 0) {
            fVar4 = ((float)local_24 * 7.0 + 135.0) * 0.015625;
            local_20 = (float *)0x33;
            uVar2 = 0;
            if (0 < (int)ROUND(fVar4 * 56.064)) {
              uVar2 = (int)ROUND(fVar4 * 56.064);
            }
            uVar12 = 0xff;
            if ((int)uVar2 < 0xff) {
              uVar12 = uVar2;
            }
            uVar2 = 0;
            if (0 < (int)ROUND(fVar4 * 87.04)) {
              uVar2 = (int)ROUND(fVar4 * 87.04);
            }
            local_2c = 0xff;
            if ((int)uVar2 < 0xff) {
              local_2c = uVar2;
            }
            DAT_00772dd8 = (uint)ROUND(fVar4 * 43.008);
            uVar2 = 0;
            if (0 < (int)DAT_00772dd8) {
              uVar2 = DAT_00772dd8;
            }
            local_24 = (float *)0xff;
            if ((int)uVar2 < 0xff) {
              local_24 = (float *)uVar2;
            }
            if ((iVar5 < 0) || (iVar8 <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = pfVar3;
            }
            else {
              local_1c = param_1;
            }
            local_20 = (float *)((((int)local_20 << 8 | uVar12) << 8 | local_2c) << 8 |
                                (uint)local_24);
          }
          else {
            fVar4 = ((float)local_24 * 7.0 + 45.0) * 0.015625;
            local_20 = (float *)0xb3;
            uVar2 = 0;
            if (0 < (int)ROUND(fVar4 * 140.288)) {
              uVar2 = (int)ROUND(fVar4 * 140.288);
            }
            uVar12 = 0xff;
            if ((int)uVar2 < 0xff) {
              uVar12 = uVar2;
            }
            uVar2 = 0;
            if (0 < (int)ROUND(fVar4 * 144.384)) {
              uVar2 = (int)ROUND(fVar4 * 144.384);
            }
            local_24 = (float *)0xff;
            if ((int)uVar2 < 0xff) {
              local_24 = (float *)uVar2;
            }
            DAT_00772dd8 = (uint)ROUND(fVar4 * 260.096);
            uVar2 = 0;
            if (0 < (int)DAT_00772dd8) {
              uVar2 = DAT_00772dd8;
            }
            local_2c = 0xff;
            if ((int)uVar2 < 0xff) {
              local_2c = uVar2;
            }
            if ((iVar5 < 0) || (iVar8 <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = pfVar3;
            }
            else {
              local_1c = param_1;
            }
            local_20 = (float *)((((int)local_20 << 8 | uVar12) << 8 | (uint)local_24) << 8 |
                                local_2c);
          }
          in_ECX = local_14;
          local_1c[4] = (float)local_20;
          if ((iVar5 < 0) || (pfVar9 = param_1, iVar8 <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = pfVar3;
          }
          pfVar9[3] = (float)local_20;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = *(float **)(in_ECX + 0xfc);
            local_1c = pfVar9;
          }
          else {
            pfVar9 = *(float **)(in_ECX + 0xfc);
            local_1c = (float *)((int)param_2 + (int)pfVar9);
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_20 = *(float **)(in_ECX + 0xfc);
          }
          else {
            local_20 = (float *)((int)param_2 + (int)pfVar9);
          }
          if ((iVar5 < 0) || (pfVar9 = param_1, iVar8 <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = pfVar3;
          }
          fVar4 = *(float *)((int)local_20 + 4) + (float)local_28;
          local_24 = pfVar9;
          FUN_004089d0();
          *local_24 = fVar4 * 0.03 + *local_1c;
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = *(undefined4 **)(in_ECX + 0xfc);
            local_20 = (float *)puVar10;
          }
          else {
            puVar10 = *(undefined4 **)(in_ECX + 0xfc);
            local_20 = (float *)((int)param_2 + (int)puVar10);
          }
          if ((iVar5 < 0) || (*(int *)(in_ECX + 0x100) <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = *(float **)(in_ECX + 0xfc);
          }
          else {
            local_24 = (float *)((int)param_2 + (int)puVar10);
          }
          if ((iVar5 < 0) || (pfVar9 = param_1, iVar8 <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = pfVar3;
          }
          fVar4 = *local_24 + (float)local_28;
          local_1c = pfVar9;
          FUN_004089d0();
          local_1c[1] = fVar4 * 0.03 + local_20[1];
          if ((iVar5 < 0) || (pfVar9 = param_1, iVar8 <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = pfVar3;
          }
          pfVar9[2] = 15.0;
          if ((iVar5 < 0) || (pfVar9 = param_1, iVar8 <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = pfVar3;
          }
          pfVar9[5] = 0.024;
          if ((iVar5 < 0) || (pfVar9 = param_1, iVar8 <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pfVar9 = pfVar3;
          }
          pfVar9[6] = 0.487;
          iVar5 = iVar5 + 1;
          param_1 = param_1 + 7;
          param_2 = (float *)((int)param_2 + 0x10);
        } while (iVar5 < *(int *)(in_ECX + 0x108));
      }
      iVar8 = local_18[0x11];
      piVar1 = (int *)(iVar8 + 0x10);
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && (*(int **)(iVar8 + 0x14) != (int *)0x0)) {
        piVar1 = (int *)**(int **)(iVar8 + 0x14);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x18))();
        }
        *(undefined4 *)(iVar8 + 0xc) = 0;
      }
      puVar10 = local_18;
      if (local_18 != (undefined4 *)0x0) {
        LOCK();
        local_18[1] = local_18[1] + 1;
        UNLOCK();
      }
      local_8._0_1_ = 0xd;
      FUN_0044d010();
      local_8._0_1_ = 0xe;
      if (puVar10 != (undefined4 *)0x0) {
        LOCK();
        puVar10[1] = puVar10[1] + 1;
        UNLOCK();
      }
      FUN_00450720(puVar10);
      if (puVar10 != (undefined4 *)0x0) {
        LOCK();
        iVar8 = puVar10[1] + -1;
        puVar10[1] = iVar8;
        UNLOCK();
        if (iVar8 == 0) {
          (**(code **)*puVar10)(1);
        }
      }
      if (local_18 != (undefined4 *)0x0) {
        LOCK();
        piVar1 = local_18 + 1;
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (**(code **)*local_18)(1);
        }
      }
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0xf);
  if ((int)local_38 < 0) {
    FUN_00448980(-local_38);
  }
  else if (0 < (int)local_38) {
    local_38 = 0;
    FUN_00448a90(0);
  }
  if (local_3c != 0) {
    FUN_006ba940();
  }
  local_8 = 0x10;
  if ((int)local_30 < 0) {
    FUN_00448980(-local_30);
  }
  else if (0 < (int)local_30) {
    local_30 = 0;
    FUN_00448a90(0);
  }
  if (local_34 != (float *)0x0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

