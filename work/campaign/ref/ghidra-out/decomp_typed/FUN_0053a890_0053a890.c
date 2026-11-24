
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053a890(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int this;
  undefined4 *puVar6;
  byte bVar7;
  uint uVar8;
  code *pcVar9;
  uint uVar10;
  bool bVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined1 local_48 [16];
  int local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int *piStack_28;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070330d;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (((this->c_4c & 1) != 0) || (this->i_60 == 0)) {
    this->c_4c = 0;
    local_38 = this;
    FUN_004fede0(local_14);
    uStack_2c = 0x8a;
    piStack_28 = (int *)0x8a;
    FUN_004fee10(&uStack_2c);
    this->i_68 = this->i_f8;
    local_34 = 0;
    uStack_30 = 0;
    this->i_6c = this->i_f8 * this->i_f4;
    this->i_78 = this->i_fc;
    this->i_64 = this->i_f4;
    this->i_88 = 0xff000000;
    this->i_7c = 0xff0000;
    this->i_80 = 0xff00;
    this->i_84 = 0xff;
    this->i_74 = 4;
    this->f_b4 = 0x40800000;
    this->i_8c = 0xc47a0000;
    this->i_90 = 0xc47a0000;
    this->i_94 = 0xc47a0000;
    this->i_98 = 0xc47a0000;
    this->i_9c = 0xc47a0000;
    this->c_b1 = 0x101;
    this->i_a0 = 0;
    this->i_a4 = 0;
    this->i_a8 = 1;
    this->i_ac = 1;
    uStack_2c = 0x8a;
    piStack_28 = (undefined4 *)0x8a;
    FUN_004fee10(&uStack_2c);
    local_18 = (undefined4 *)0x0;
    if (this->i_e0 != 0) {
      FUN_004ff430(this + 0xe4,&local_18);
    }
    local_24 = (int *)0x0;
    local_20 = (undefined4 *)0x0;
    local_8 = 0;
    local_1c = (int *)0x0;
    pcVar9 = RaiseException_exref;
    do {
      piVar3 = local_24;
      if (((uint)(local_20 + 0x40) & 0xffffff00) != ((int)local_20 + 0xffU & 0xffffff00)) {
        local_18 = (undefined4 *)(((uint)(local_20 + 0x40) & 0xffffff00) * 0xc);
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        local_8._0_1_ = 1;
        if (piVar3 == (int *)0x0) {
          piVar3 = (int *)FUN_006ba810(0x9b);
          local_8 = (uint)local_8._1_3_ << 8;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_24 = piVar3;
        }
        else if (local_18 == (undefined4 *)0x0) {
          if (DAT_00c3c824 == 0) {
            DAT_00c3c824 = 1;
            InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_8 = CONCAT31(local_8._1_3_,2);
          LOCK();
          _DAT_00c3c818 = _DAT_00c3c818 + 1;
          UNLOCK();
          piVar12 = piVar3 + -7;
          iVar4 = FUN_006ba730();
          if (iVar4 == 0) {
            piStack_28 = (int *)piVar3[-2];
            local_18 = (undefined4 *)((int)(piStack_28 + 7) + (int)piVar12);
            iVar4 = FUN_006ba730();
            if (iVar4 != 0) goto LAB_0053ab0d;
            if (piVar3[-5] != 0) {
              *(int *)(piVar3[-5] + 4) = piVar3[-6];
            }
            if (piVar3[-6] != 0) {
              *(int *)(piVar3[-6] + 8) = piVar3[-5];
            }
            if (piVar12 == DAT_00c3c81c) {
              DAT_00c3c81c = (int *)piVar3[-6];
            }
            _memset(piVar3,-0x20202021,(size_t)piStack_28);
            bVar11 = DAT_0077248f == '\0';
            *piVar12 = -0x20202021;
            piVar3[-1] = -0x20202021;
            *local_18 = 0xdfdfdfdf;
            if (((bVar11) || (DAT_00c1c788 == '\0')) ||
               ((piVar12 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar12))))
            {
              FUN_006df631(piVar12);
              pcVar9 = RaiseException_exref;
            }
            else {
              FUN_006b8c20();
              pcVar9 = RaiseException_exref;
            }
          }
          else {
LAB_0053ab0d:
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar3,iVar4);
              _fflush(DAT_00c3c7d4);
            }
            pcVar9 = RaiseException_exref;
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_8 = local_8 & 0xffffff00;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          local_24 = (int *)0x0;
        }
        else {
          LOCK();
          _DAT_00c3c82c = _DAT_00c3c82c + 1;
          UNLOCK();
          piVar12 = piVar3 + -7;
          iVar4 = FUN_006ba730();
          if ((iVar4 != 0) || (iVar4 = FUN_006ba730(), iVar4 != 0)) {
            if (DAT_00c3c7d4 != (FILE *)0x0) {
              FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar3,iVar4);
              _fflush(DAT_00c3c7d4);
            }
            pcVar9 = RaiseException_exref;
            if (DAT_00c3c828 != '\0') {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_8 = (uint)local_8._1_3_ << 8;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            local_24 = (int *)0x0;
            goto LAB_0053ad5f;
          }
          piStack_28 = local_18 + 8;
          if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (piVar12 < DAT_00c3c7cc)) ||
             ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar12)) {
            piVar3 = (int *)FUN_006df8de(piVar12,piStack_28);
            if (piVar3 == (int *)0x0) {
              FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",piStack_28,
                           piVar12);
              MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
              goto LAB_0053acfb;
            }
          }
          else {
            piVar3 = (int *)FUN_006b8a90();
LAB_0053acfb:
            if (piVar3 == (int *)0x0) {
              local_8 = (uint)local_8._1_3_ << 8;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              pcVar9 = RaiseException_exref;
              local_24 = (int *)0x0;
              goto LAB_0053ad5f;
            }
          }
          if (piVar12 == DAT_00c3c81c) {
            DAT_00c3c81c = piVar3;
          }
          piVar3[5] = (int)local_18;
          if (piVar3[1] != 0) {
            *(int **)(piVar3[1] + 8) = piVar3;
          }
          if (piVar3[2] != 0) {
            *(int **)(piVar3[2] + 4) = piVar3;
          }
          *(undefined4 *)((int)(piVar3 + 7) + (int)local_18) = 0xfab1ffcd;
          local_8 = (uint)local_8._1_3_ << 8;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          pcVar9 = RaiseException_exref;
          local_24 = piVar3 + 7;
        }
      }
LAB_0053ad5f:
      puVar6 = (undefined4 *)((int)local_20 + 1);
      local_18 = local_20;
      if (puVar6 <= local_20) {
        local_20 = puVar6;
        (*pcVar9)(0xc000008c,1,0,0);
        puVar6 = local_20;
      }
      local_20 = puVar6;
      piVar3 = local_24;
      piStack_28 = (int *)((int)local_18 * 0xc);
      piVar12 = local_1c;
      FUN_004089f0();
      *(float *)((int)piVar3 + (int)piStack_28) = (float)piVar12 * 74.0 + 60.0;
      if (local_20 <= local_18) {
        (*pcVar9)(0xc000008c,1,0,0);
      }
      piVar3 = local_1c;
      FUN_004089d0();
      iVar4 = local_38;
      *(float *)((int)(local_24 + 1) + (int)piStack_28) = (float)piVar3 * 74.0 + 168.0;
      local_1c = (int *)((float)local_1c + 0.09817477);
    } while ((float)local_1c < 6.2831855);
    iVar1 = *(int *)(local_38 + 0x60);
    piVar3 = (int *)(local_38 + 0x5c);
    piStack_28 = piVar3;
    if (iVar1 < 0) {
      FUN_00448980(-iVar1);
    }
    else if (0 < iVar1) {
      *(undefined4 *)(local_38 + 0x60) = 0;
    }
    if (DAT_0076a2a0 == (undefined4 *)0x0) {
      DAT_0076a2a0 = (undefined4 *)FUN_006ba810(0x12);
      if (DAT_0076a2a0 == (undefined4 *)0x0) {
        DAT_0076a2a0 = (undefined4 *)0x0;
      }
      else {
        *DAT_0076a2a0 = CPolyFill::vftable;
      }
    }
    FUN_00445e40(piVar3,&local_24);
    uVar10 = *(int *)(iVar4 + 0x60) - 1;
    if (-1 < (int)uVar10) {
      local_18 = (undefined4 *)(uVar10 * 0xc);
      do {
        if ((uint)piVar3[1] <= uVar10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar4 = *piVar3;
        if (*(int *)((int)local_18 + iVar4 + 4) < 0xe2) {
          if ((uint)piVar3[1] <= uVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar4 = *piVar3;
          }
          if (*(int *)((int)local_18 + iVar4) < 0) {
            uVar8 = piVar3[1];
            if (uVar8 <= uVar10) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *piVar3;
              uVar8 = *(uint *)(local_38 + 0x60);
            }
            piVar3 = piStack_28;
            local_1c = (int *)(iVar4 + 8 + (int)local_18);
            if (uVar8 <= uVar10) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *piVar3;
            }
            *local_1c = *local_1c + *(int *)((int)local_18 + iVar4);
            if ((uint)piVar3[1] <= uVar10) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)((int)local_18 + *piVar3) = 0;
          }
        }
        else {
          uVar8 = piVar3[1];
          if (uVar8 <= uVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar8 = piVar3[1];
            if (uVar8 <= uVar10) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar8 = piVar3[1];
            }
          }
          if ((int)uVar10 < (int)(uVar8 - 1)) {
            FUN_006d1b90((int)local_18 + *piVar3,(int)local_18 + *piVar3 + 0xc,
                         (uVar8 - uVar10) * 0xc + -0xc);
            uVar8 = piVar3[1];
          }
          piVar3[1] = uVar8 - 1;
        }
        local_18 = local_18 + -3;
        uVar10 = uVar10 - 1;
      } while (-1 < (int)uVar10);
    }
    FUN_00504ee0();
    local_8 = 3;
    if ((int)local_20 < 0) {
      FUN_00448980(-(int)local_20);
    }
    else if (0 < (int)local_20) {
      local_20 = (undefined4 *)0x0;
    }
    piVar3 = local_24;
    this = local_38;
    if (local_24 != (int *)0x0) {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      if (piVar3 != (int *)0x0) {
        LOCK();
        _DAT_00c3c818 = _DAT_00c3c818 + 1;
        UNLOCK();
        piVar12 = piVar3 + -7;
        if (DAT_00c3c824 == 0) {
          DAT_00c3c824 = 1;
          InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
        bVar11 = piVar3[-1] != -0x10324e01 || *piVar12 != -0x4e005433;
        bVar7 = bVar11 | 2;
        if (*piVar12 != -0x20202021) {
          bVar7 = bVar11;
        }
        if (bVar7 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          piStack_28 = (int *)piVar3[-2];
          local_1c = (int *)((int)(piStack_28 + 7) + (int)piVar12);
          pcVar5 = (char *)FUN_006ba730();
          if (pcVar5 == (char *)0x0) {
            if (piVar3[-5] != 0) {
              *(int *)(piVar3[-5] + 4) = piVar3[-6];
            }
            if (piVar3[-6] != 0) {
              *(int *)(piVar3[-6] + 8) = piVar3[-5];
            }
            if (piVar12 == DAT_00c3c81c) {
              DAT_00c3c81c = (int *)piVar3[-6];
            }
            _memset(piVar3,-0x20202021,(size_t)piStack_28);
            bVar11 = DAT_0077248f == '\0';
            *piVar12 = -0x20202021;
            piVar3[-1] = -0x20202021;
            *local_1c = -0x20202021;
            if (((bVar11) || (DAT_00c1c788 == '\0')) ||
               ((piVar12 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar12))))
            {
              FUN_006df631(piVar12);
            }
            else {
              FUN_006b8c20();
            }
            goto LAB_0053b1a0;
          }
        }
        else if (bVar7 == 3) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          pcVar5 = "already freed";
        }
        else if (bVar7 == 1) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          pcVar5 = "corrupted";
        }
        else {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
          pcVar5 = "corrupted freed";
        }
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",piVar3,pcVar5);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
LAB_0053b1a0:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      this = local_38;
    }
  }
  local_8 = 0xffffffff;
  local_24 = (int *)0x0;
  local_20 = (undefined4 *)
             ((*(int *)(this->i_34 + 0x18) - *(int *)(this->i_34 + 0x10))
             - this->i_c0);
  FUN_00504a70(&local_24);
  iVar4 = *(int *)(DAT_00772400 + 0x5a4);
  if ((((this->i_8c == *(float *)(iVar4 + 0x154)) &&
       (this->i_90 == *(float *)(iVar4 + 0x158))) &&
      (this->i_94 == *(float *)(iVar4 + 0x160))) &&
     ((this->i_98 == *(float *)(iVar4 + 0x164) &&
      (this->i_9c == *(float *)(iVar4 + 0x15c))))) {
    puVar6 = (undefined4 *)FUN_0053a7b0(local_48);
    uVar13 = *puVar6;
    uVar14 = puVar6[1];
    uVar15 = puVar6[2];
    uVar16 = puVar6[3];
    FUN_005a9090(uVar13,uVar14,uVar15,uVar16);
    cVar2 = FUN_005a8ac0(uVar13,uVar14,uVar15,uVar16);
    if ((cVar2 == '\0') && (*(int *)(DAT_00772400 + 0x6c) - this->i_44 < 4))
    goto LAB_0053b28e;
  }
  FUN_00504ee0();
LAB_0053b28e:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

