
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050ab10(ViWinClock *this)

{
  uint *puVar1;
  ViWinClock *pVVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  code *pcVar11;
  int *piVar12;
  bool bVar13;
  int *piVar14;
  float fVar15;
  float fVar16;
  int *in_stack_00000004;
  undefined4 *local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  ViWinClock *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar12 = in_stack_00000004;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070131d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = this;
  if ((this->f_48 == -1.0) || (this->f_4c == -1.0)) {
    this->c_6c = '\0';
LAB_0050ac04:
    FUN_004ff900(&this->i_ac,in_stack_00000004[2],in_stack_00000004[3],this->i_ac,this->i_b0,0,0,3);
    FUN_006b9200(&PTR_0071ce50);
  }
  else {
    if (this->c_6c == '\0') goto LAB_0050ac04;
    FUN_004ff900(&this->field_0xc8,in_stack_00000004[2],in_stack_00000004[3],
                 *(undefined4 *)&this->field_0xc8,*(undefined4 *)&this->field_0xcc,0,0,3);
    uVar4 = FUN_004435d0(&local_30,"Cycle",uVar3);
    local_2c = (int *)FUN_00443730(uVar4);
    local_8 = 0;
    piVar14 = (int *)*local_2c;
    piVar6 = *(int **)&this->field_0x30;
    *(int **)&this->field_0x30 = piVar14;
    if (piVar14 != (int *)0x0) {
      *piVar14 = *piVar14 + 1;
    }
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)&this->field_0x30 + 8) = *(undefined4 *)(*local_2c + 8);
    local_8 = 1;
    if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
  }
  fVar16 = this->f_48;
  local_2c = (int *)0x0;
  if ((fVar16 == -1.0) || (fVar15 = this->f_4c, fVar15 == -1.0)) {
    this->c_6c = '\0';
    goto LAB_0050bc8a;
  }
  if (ABS(fVar16 - fVar15) < 0.020833334) goto LAB_0050bc8a;
  local_1c = (undefined4 *)(fVar16 * 6.2831855 - 1.5707964);
  local_24 = fVar15 * 6.2831855 - 1.5707964;
  if (local_24 < (float)local_1c) {
    local_24 = local_24 + 6.2831855;
  }
  local_4c = (undefined4 *)0x0;
  local_48 = 0.0;
  local_8 = 2;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  local_8._0_1_ = 3;
  local_28 = (undefined4 *)FUN_006ba810(0x9b);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  pcVar11 = RaiseException_exref;
  local_48 = (float)((int)local_48 + 1);
  local_20 = (undefined4 *)this->f_5c;
  local_4c = local_28;
  local_28 = (undefined4 *)this->f_58;
  if (local_48 == 0.0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *local_4c = local_28;
  local_4c[1] = local_20;
  local_4c[2] = 0;
  uVar3 = (int)local_48 + 0x100U & 0xffffff00;
  if (uVar3 != ((int)local_48 + 0xffU & 0xffffff00)) {
    local_28 = (undefined4 *)(uVar3 * 0xc);
    local_18 = local_4c;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 5;
    if (local_18 == (undefined4 *)0x0) {
      local_28 = (undefined4 *)FUN_006ba810(0x9b);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_4c = local_28;
    }
    else if (local_28 == (undefined4 *)0x0) {
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
        local_20 = (undefined4 *)local_18[-2];
        local_34 = (int *)((int)local_20 + (int)local_18);
        iVar8 = FUN_006ba730();
        if (iVar8 != 0) goto LAB_0050ae74;
        if (local_18[-5] != 0) {
          *(undefined4 *)(local_18[-5] + 4) = local_18[-6];
          this = local_14;
        }
        if (local_18[-6] != 0) {
          *(undefined4 *)(local_18[-6] + 8) = local_18[-5];
          this = local_14;
        }
        if (local_18 + -7 == DAT_00c3c81c) {
          DAT_00c3c81c = (undefined4 *)local_18[-6];
        }
        _memset(local_18,-0x20202021,(size_t)local_20);
        puVar5 = local_18 + -7;
        bVar13 = DAT_0077248f == '\0';
        *puVar5 = 0xdfdfdfdf;
        local_18[-1] = 0xdfdfdfdf;
        *local_34 = 0xdfdfdfdf;
        if (((bVar13) || (DAT_00c1c788 == '\0')) ||
           ((puVar5 < DAT_00c3c7cc || ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar5)))
           ) {
          FUN_006df631(puVar5);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_0050ae74:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_18,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_4c = (undefined4 *)0x0;
    }
    else {
      LOCK();
      _DAT_00c3c82c = _DAT_00c3c82c + 1;
      UNLOCK();
      local_20 = local_18 + -7;
      iVar8 = FUN_006ba730();
      if ((iVar8 == 0) && (iVar8 = FUN_006ba730(), pVVar2 = local_14, iVar8 == 0)) {
        local_34 = local_28 + 8;
        if ((DAT_0077248f == '\0') ||
           (((DAT_00c1c788 == '\0' || (local_20 < DAT_00c3c7cc)) ||
            (this = local_14, (undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_20)))) {
          puVar5 = (undefined4 *)FUN_006df8de(local_20,local_34);
          local_18 = puVar5;
          if (puVar5 == (undefined4 *)0x0) {
            FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_34,local_20)
            ;
            MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
            puVar5 = local_18;
            goto LAB_0050b073;
          }
        }
        else {
          puVar5 = (undefined4 *)FUN_006b8a90();
          this = pVVar2;
LAB_0050b073:
          if (puVar5 == (undefined4 *)0x0) goto LAB_0050afce;
        }
        if (local_20 == DAT_00c3c81c) {
          DAT_00c3c81c = puVar5;
        }
        puVar5[5] = local_28;
        if (puVar5[1] != 0) {
          *(undefined4 **)(puVar5[1] + 8) = puVar5;
        }
        if (puVar5[2] != 0) {
          *(undefined4 **)(puVar5[2] + 4) = puVar5;
        }
        *(undefined4 *)((int)(puVar5 + 7) + (int)local_28) = 0xfab1ffcd;
        local_28 = puVar5 + 7;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_4c = local_28;
      }
      else {
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_18,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
LAB_0050afce:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_4c = (undefined4 *)0x0;
      }
    }
  }
  local_48 = (float)((int)local_48 + 1);
  puVar5 = local_1c;
  FUN_004089f0();
  local_34 = (int *)((float)puVar5 * this->f_60 + this->f_58);
  puVar5 = local_1c;
  FUN_004089d0();
  local_28 = (undefined4 *)((float)puVar5 * this->f_60 + this->f_5c);
  if ((uint)local_48 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_4c[3] = local_34;
  local_4c[4] = local_28;
  local_1c = (undefined4 *)((float)local_1c + 0.19634955);
  local_4c[5] = 0;
  if ((float)local_1c < local_24) {
    do {
      uVar3 = (int)local_48 + 0x100U & 0xffffff00;
      if (uVar3 != ((int)local_48 + 0xffU & 0xffffff00)) {
        local_28 = (undefined4 *)(uVar3 * 0xc);
        local_18 = local_4c;
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 7;
        if (local_18 == (undefined4 *)0x0) {
          local_28 = (undefined4 *)FUN_006ba810(0x9b);
        }
        else {
          if (local_28 == (undefined4 *)0x0) {
            if (DAT_00c3c824 == 0) {
              DAT_00c3c824 = 1;
              InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            puVar5 = local_18;
            local_8._0_1_ = 8;
            LOCK();
            _DAT_00c3c818 = _DAT_00c3c818 + 1;
            UNLOCK();
            puVar10 = local_18 + -7;
            iVar8 = FUN_006ba730();
            if (iVar8 == 0) {
              local_34 = (int *)puVar5[-2];
              local_28 = (undefined4 *)((int)(local_34 + 7) + (int)puVar10);
              iVar8 = FUN_006ba730();
              if (iVar8 != 0) goto LAB_0050b23b;
              if (puVar5[-5] != 0) {
                *(undefined4 *)(puVar5[-5] + 4) = puVar5[-6];
              }
              if (puVar5[-6] != 0) {
                *(undefined4 *)(puVar5[-6] + 8) = puVar5[-5];
              }
              if (puVar10 == DAT_00c3c81c) {
                DAT_00c3c81c = (undefined4 *)puVar5[-6];
              }
              _memset(local_18,-0x20202021,(size_t)local_34);
              bVar13 = DAT_0077248f == '\0';
              *puVar10 = 0xdfdfdfdf;
              puVar5[-1] = 0xdfdfdfdf;
              *local_28 = 0xdfdfdfdf;
              if (((bVar13) || (DAT_00c1c788 == '\0')) ||
                 ((puVar10 < DAT_00c3c7cc ||
                  ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar10)))) {
                FUN_006df631(puVar10);
                pcVar11 = RaiseException_exref;
              }
              else {
                FUN_006b8c20();
                pcVar11 = RaiseException_exref;
              }
            }
            else {
LAB_0050b23b:
              if (DAT_00c3c7d4 != (FILE *)0x0) {
                FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_18,iVar8);
                _fflush(DAT_00c3c7d4);
              }
              pcVar11 = RaiseException_exref;
              if (DAT_00c3c828 != '\0') {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_4c = (undefined4 *)0x0;
            goto LAB_0050b486;
          }
          LOCK();
          _DAT_00c3c82c = _DAT_00c3c82c + 1;
          UNLOCK();
          local_20 = local_18 + -7;
          iVar8 = FUN_006ba730();
          if ((iVar8 != 0) || (iVar8 = FUN_006ba730(), pVVar2 = local_14, iVar8 != 0)) {
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_18,iVar8);
              _fflush(DAT_00c3c7d4);
            }
            if (DAT_00c3c828 != '\0') {
              (*pcVar11)(0xc000008c,1,0,0);
            }
LAB_0050b38d:
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_4c = (undefined4 *)0x0;
            goto LAB_0050b486;
          }
          local_34 = local_28 + 8;
          if ((DAT_0077248f == '\0') ||
             (((DAT_00c1c788 == '\0' || (local_20 < DAT_00c3c7cc)) ||
              (this = local_14, (undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_20)))) {
            puVar5 = (undefined4 *)FUN_006df8de(local_20,local_34);
            local_18 = puVar5;
            if (puVar5 == (undefined4 *)0x0) {
              FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_34,
                           local_20);
              MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
              puVar5 = local_18;
              goto LAB_0050b432;
            }
          }
          else {
            puVar5 = (undefined4 *)FUN_006b8a90();
            this = pVVar2;
LAB_0050b432:
            if (puVar5 == (undefined4 *)0x0) goto LAB_0050b38d;
          }
          if (local_20 == DAT_00c3c81c) {
            DAT_00c3c81c = puVar5;
          }
          puVar5[5] = local_28;
          if (puVar5[1] != 0) {
            *(undefined4 **)(puVar5[1] + 8) = puVar5;
          }
          if (puVar5[2] != 0) {
            *(undefined4 **)(puVar5[2] + 4) = puVar5;
          }
          *(undefined4 *)((int)(puVar5 + 7) + (int)local_28) = 0xfab1ffcd;
          local_28 = puVar5 + 7;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_4c = local_28;
      }
LAB_0050b486:
      puVar5 = local_1c;
      local_28 = (undefined4 *)local_48;
      local_48 = (float)((int)local_48 + 1);
      FUN_004089f0();
      local_34 = (int *)((float)puVar5 * this->f_60 + this->f_58);
      puVar5 = local_1c;
      FUN_004089d0();
      local_20 = (undefined4 *)((float)puVar5 * this->f_60 + this->f_5c);
      if ((uint)local_48 <= local_28) {
        (*pcVar11)(0xc000008c,1,0,0);
      }
      local_4c[(int)local_28 * 3] = local_34;
      local_4c[(int)local_28 * 3 + 1] = local_20;
      local_1c = (undefined4 *)((float)local_1c + 0.19634955);
      local_4c[(int)local_28 * 3 + 2] = 0;
    } while ((float)local_1c < local_24);
  }
  uVar3 = (int)local_48 + 0x100U & 0xffffff00;
  if (uVar3 != ((int)local_48 + 0xffU & 0xffffff00)) {
    local_28 = (undefined4 *)(uVar3 * 0xc);
    local_18 = local_4c;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_8._0_1_ = 9;
    if (local_18 == (undefined4 *)0x0) {
      local_28 = (undefined4 *)FUN_006ba810(0x9b);
    }
    else {
      if (local_28 == (undefined4 *)0x0) {
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 10;
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        iVar8 = FUN_006ba730();
        if (iVar8 == 0) {
          local_28 = (undefined4 *)local_18[-2];
          local_20 = (undefined4 *)((int)local_28 + (int)local_18);
          iVar8 = FUN_006ba730();
          if (iVar8 != 0) goto LAB_0050b60a;
          if (local_18[-5] != 0) {
            *(undefined4 *)(local_18[-5] + 4) = local_18[-6];
            this = local_14;
          }
          if (local_18[-6] != 0) {
            *(undefined4 *)(local_18[-6] + 8) = local_18[-5];
            this = local_14;
          }
          if (local_18 + -7 == DAT_00c3c81c) {
            DAT_00c3c81c = (undefined4 *)local_18[-6];
          }
          _memset(local_18,-0x20202021,(size_t)local_28);
          puVar5 = local_18 + -7;
          bVar13 = DAT_0077248f == '\0';
          *puVar5 = 0xdfdfdfdf;
          local_18[-1] = 0xdfdfdfdf;
          *local_20 = 0xdfdfdfdf;
          if (((bVar13) || (DAT_00c1c788 == '\0')) ||
             ((puVar5 < DAT_00c3c7cc || ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar5)
              ))) {
            FUN_006df631(puVar5);
          }
          else {
            FUN_006b8c20();
          }
        }
        else {
LAB_0050b60a:
          if (DAT_00c3c7d4 != (FILE *)0x0) {
            FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_18,iVar8);
            _fflush(DAT_00c3c7d4);
          }
          if (DAT_00c3c828 != '\0') {
            (*pcVar11)(0xc000008c,1,0,0);
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_4c = (undefined4 *)0x0;
        goto LAB_0050b85b;
      }
      LOCK();
      _DAT_00c3c82c = _DAT_00c3c82c + 1;
      UNLOCK();
      local_20 = local_18 + -7;
      iVar8 = FUN_006ba730();
      if ((iVar8 != 0) || (iVar8 = FUN_006ba730(), pVVar2 = local_14, iVar8 != 0)) {
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_18,iVar8);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          (*pcVar11)(0xc000008c,1,0,0);
        }
LAB_0050b762:
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_4c = (undefined4 *)0x0;
        goto LAB_0050b85b;
      }
      local_34 = (int *)((int)local_28 + 0x20);
      if ((DAT_0077248f == '\0') ||
         (((DAT_00c1c788 == '\0' || (local_20 < DAT_00c3c7cc)) ||
          (this = local_14, (undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= local_20)))) {
        puVar5 = (undefined4 *)FUN_006df8de(local_20,local_34);
        local_1c = puVar5;
        if (puVar5 == (undefined4 *)0x0) {
          FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",local_34,local_20);
          MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
          puVar5 = local_1c;
          goto LAB_0050b807;
        }
      }
      else {
        puVar5 = (undefined4 *)FUN_006b8a90();
        this = pVVar2;
LAB_0050b807:
        if (puVar5 == (undefined4 *)0x0) goto LAB_0050b762;
      }
      if (local_20 == DAT_00c3c81c) {
        DAT_00c3c81c = puVar5;
      }
      puVar5[5] = local_28;
      if (puVar5[1] != 0) {
        *(undefined4 **)(puVar5[1] + 8) = puVar5;
      }
      if (puVar5[2] != 0) {
        *(undefined4 **)(puVar5[2] + 4) = puVar5;
      }
      *(undefined4 *)((int)puVar5 + (int)local_28 + 0x1cU) = 0xfab1ffcd;
      local_28 = puVar5 + 7;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    local_4c = local_28;
  }
LAB_0050b85b:
  fVar16 = local_24;
  local_28 = (undefined4 *)local_48;
  local_48 = (float)((int)local_48 + 1);
  FUN_004089f0();
  local_34 = (int *)(fVar16 * this->f_60 + this->f_58);
  FUN_004089d0();
  local_24 = local_24 * this->f_60 + this->f_5c;
  if ((uint)local_48 <= local_28) {
    (*pcVar11)(0xc000008c,1,0,0);
  }
  local_4c[(int)local_28 * 3] = local_34;
  local_4c[(int)local_28 * 3 + 1] = local_24;
  local_4c[(int)local_28 * 3 + 2] = 0;
  local_44 = 0.0;
  local_40 = 0.0;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_00445dd0(&local_44,&local_4c);
  FUN_00445e40();
  local_20 = (undefined4 *)0x0;
  fVar16 = local_40;
  if (0 < (int)local_40) {
    local_1c = (undefined4 *)0x0;
    bVar13 = local_40 != 0.0;
    do {
      if (!bVar13) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        fVar16 = local_40;
      }
      local_18 = *(undefined4 **)((int)local_1c + (int)local_44 + 4);
      if ((uint)fVar16 <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        fVar16 = local_40;
      }
      local_28 = *(undefined4 **)((int)local_1c + (int)local_44);
      while( true ) {
        if ((uint)fVar16 <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          fVar16 = local_40;
        }
        local_34 = (int *)local_44;
        if ((uint)fVar16 <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          fVar16 = local_40;
        }
        if (*(int *)((int)local_1c + (int)local_44 + 8) + *(int *)((int)local_1c + (int)local_34) <=
            (int)local_28) break;
        local_34 = (int *)(in_stack_00000004[2] + (int)local_28);
        puVar1 = (uint *)*in_stack_00000004;
        if ((local_34 < *puVar1) && ((uint)(in_stack_00000004[3] + (int)local_18) < puVar1[1])) {
          local_24 = *(float *)(puVar1[2] +
                               (*puVar1 * (in_stack_00000004[3] + (int)local_18) + (int)local_34) *
                               4);
        }
        else {
          local_24 = 0.0;
        }
        iVar8 = local_14->i_44 * 6;
        iVar9 = 0xff - ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2);
        iVar8 = 0x100 - iVar9;
        FUN_004d71b0((int)(((uint)local_24 >> 0x10 & 0xff) * iVar9 +
                          (uint)(byte)local_14->field_0x66 * iVar8) >> 8,
                     (int)(((uint)local_24 >> 8 & 0xff) * iVar9 +
                          (uint)(byte)local_14->field_0x65 * iVar8) >> 8,
                     (int)(((uint)local_24 & 0xff) * iVar9 +
                          (uint)(byte)local_14->field_0x64 * iVar8) >> 8,
                     (int)((uint)(byte)local_14->field_0x67 * iVar8 +
                          ((uint)local_24 >> 0x18) * iVar9) >> 8);
        piVar12 = (int *)*in_stack_00000004;
        local_34 = (int *)(in_stack_00000004[2] + (int)local_28);
        iVar8 = in_stack_00000004[3] + (int)local_18;
        if ((((piVar12[3] <= (int)local_34) && ((int)local_34 < piVar12[5])) &&
            (piVar12[4] <= iVar8)) && (iVar8 < piVar12[6])) {
          *(int **)(piVar12[2] + (*piVar12 * iVar8 + (int)local_34) * 4) = local_38;
          fVar16 = local_40;
        }
        local_28 = (undefined4 *)((int)local_28 + 1);
      }
      local_1c = local_1c + 3;
      local_20 = (undefined4 *)((int)local_20 + 1);
      bVar13 = local_20 < (uint)fVar16;
      this = local_14;
    } while ((int)local_20 < (int)fVar16);
  }
  local_8 = CONCAT31(local_8._1_3_,0xc);
  if ((int)fVar16 < 0) {
    FUN_00448980(-(int)fVar16);
  }
  else if (0 < (int)fVar16) {
    local_40 = 0.0;
    FUN_00448a90(0);
  }
  if (local_44 != 0.0) {
    FUN_006ba940();
  }
  local_8 = 0xd;
  if ((int)local_48 < 0) {
    FUN_00448980(-(int)local_48);
  }
  else if (0 < (int)local_48) {
    local_48 = 0.0;
    FUN_00448a90(0);
  }
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_28 = (undefined4 *)0xbeffffff;
  fVar16 = (this->f_48 + this->f_48) * 3.1415927 - 1.5707964;
  local_38 = (int *)fVar16;
  FUN_004089f0();
  local_34 = (int *)(fVar16 * this->f_60 + this->f_58);
  piVar14 = local_38;
  FUN_004089d0();
  piVar12 = in_stack_00000004;
  FUN_004ff250((float)in_stack_00000004[3] + (float)piVar14 * this->f_60 + this->f_5c,&local_28);
  in_stack_00000004 = (int *)0xbeffffff;
  fVar16 = (this->f_4c + this->f_4c) * 3.1415927 - 1.5707964;
  local_38 = (int *)fVar16;
  FUN_004089f0();
  local_34 = (int *)(fVar16 * this->f_60 + this->f_58);
  piVar14 = local_38;
  FUN_004089d0();
  FUN_004ff250((float)piVar12[3] + (float)piVar14 * this->f_60 + this->f_5c,&stack0x00000004);
LAB_0050bc8a:
  fVar16 = (float)*(double *)(DAT_00772400 + 0xa088) / 150.0;
  in_stack_00000004 = (int *)fVar16;
  FUN_00565490();
  local_28 = (undefined4 *)CONCAT13(0xff,(undefined3)local_28);
  in_stack_00000004 = (int *)((fVar16 + fVar16) * 3.1415927 - 1.5707964);
  piVar14 = (int *)((float)in_stack_00000004 + 0.7853982);
  local_38 = piVar14;
  FUN_004089f0();
  fVar16 = (float)in_stack_00000004;
  local_34 = piVar14;
  FUN_004089f0();
  local_20 = (undefined4 *)(fVar16 * 8.0);
  piVar14 = local_38;
  local_18 = (undefined4 *)fVar16;
  FUN_004089d0();
  fVar16 = (float)in_stack_00000004;
  local_30 = piVar14;
  FUN_004089d0();
  local_1c = (undefined4 *)(fVar16 * 8.0);
  local_24 = (float)CONCAT13(0xff,(undefined3)local_24);
  fVar15 = (float)in_stack_00000004 - 0.7853982;
  in_stack_00000004 = (int *)fVar15;
  local_14 = (ViWinClock *)fVar16;
  FUN_004089f0();
  fVar16 = (float)in_stack_00000004;
  local_40 = fVar15;
  FUN_004089d0();
  in_stack_00000004 = (int *)0xff;
  local_48 = fVar16;
  do {
    local_3c = (float)local_2c * 20.0;
    DAT_00772dd8 = (int)ROUND(local_3c);
    iVar8 = 0xa0 - DAT_00772dd8;
    if (0xa0 - DAT_00772dd8 < 0) {
      iVar8 = 0;
    }
    if (0xff < iVar8) {
      iVar8 = (int)in_stack_00000004;
    }
    iVar9 = 0xa0 - (int)ROUND(local_3c);
    if (0xa0 - (int)ROUND(local_3c) < 0) {
      iVar9 = 0;
    }
    local_38 = (int *)0x0;
    if (0xff < iVar9) {
      iVar9 = (int)in_stack_00000004;
    }
    iVar7 = 0xa0 - (int)ROUND(local_3c);
    if (0xa0 - (int)ROUND(local_3c) < 0) {
      iVar7 = 0;
    }
    if (0xff < iVar7) {
      iVar7 = (int)in_stack_00000004;
    }
    local_28 = (undefined4 *)
               CONCAT31(CONCAT21(CONCAT11(local_28._3_1_,(char)iVar8),(char)iVar9),(char)iVar7);
    FUN_004ff250((float)piVar12[3] + (float)local_14 * this->f_60 + this->f_5c,&local_28);
    fVar16 = ROUND(local_3c);
    DAT_00772dd8 = (int)ROUND(local_3c);
    iVar8 = 0xa0 - DAT_00772dd8;
    if (0xa0 - DAT_00772dd8 < 0) {
      iVar8 = 0;
    }
    if (0xff < iVar8) {
      iVar8 = (int)in_stack_00000004;
    }
    iVar9 = 0xa0 - (int)ROUND(local_3c);
    if (0xa0 - (int)ROUND(local_3c) < 0) {
      iVar9 = 0;
    }
    if (0xff < iVar9) {
      iVar9 = (int)in_stack_00000004;
    }
    local_3c = 0.0;
    iVar7 = 0xa0 - (int)fVar16;
    if (0xa0 - (int)fVar16 < 0) {
      iVar7 = 0;
    }
    if (0xff < iVar7) {
      iVar7 = (int)in_stack_00000004;
    }
    local_24 = (float)CONCAT31(CONCAT21(CONCAT11(local_24._3_1_,(char)iVar8),(char)iVar9),
                               (char)iVar7);
    FUN_004ff250((float)piVar12[3] + (float)local_14 * this->f_60 + this->f_5c,&local_24);
    local_2c = (int *)((float)local_2c + 1.0);
  } while ((float)local_2c < 7.0);
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 0x14;
  local_2c[2] = -1;
  *(undefined1 *)(local_2c + 3) = 0;
  *local_2c = 1;
  local_8 = 0xe;
  DAT_00772dd8 = (int)ROUND((float)*(double *)(DAT_00772400 + 0xa088) / 150.0);
  in_stack_00000004 = (int *)0x14;
  iVar8 = ((int)ROUND((float)*(double *)(DAT_00772400 + 0xa088) / 150.0) / 0xf0) % 0xc + 1;
  FUN_006b9040(&local_2c,"%2d.%2d.%2d",(DAT_00772dd8 / 0xc) % 0x14 + 1,iVar8,
               (int)ROUND((float)*(double *)(DAT_00772400 + 0xa088) / 150.0) / 0xb40 + 1);
  piVar14 = local_2c;
  iVar9 = 0x50c119;
  piVar6 = (int *)FUN_004ef240();
  if (piVar12[6] == *piVar6) {
    iVar7 = piVar12[5];
  }
  else {
    piVar12[5] = 0;
    piVar12[6] = *piVar6;
    iVar7 = 0;
  }
  if (iVar7 == 0) {
    iVar9 = piVar12[4] + 0xc;
    iVar8 = 0x50c147;
    iVar7 = FUN_004ef660(iVar9);
    piVar12[5] = iVar7;
  }
  FUN_004edf70(&local_4c,piVar14 + 3,iVar8,iVar9);
  local_48 = 1.9478e-43;
  local_4c = (undefined4 *)(0x40 - (int)local_4c / 2);
  in_stack_00000004 = (int *)0xc8969696;
  FUN_004fdff0(&local_4c,piVar14 + 3,&stack0x00000004,piVar12 + 4,1,local_4c);
  local_8 = 0xf;
  if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

