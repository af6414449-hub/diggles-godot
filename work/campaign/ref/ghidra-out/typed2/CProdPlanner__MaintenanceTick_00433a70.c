
/* WARNING: Removing unreachable block (ram,0x00433d94) */

void __thiscall CProdPlanner__MaintenanceTick(CProdPlanner *this)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 extraout_ECX;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  bool bVar14;
  undefined8 uVar15;
  uint local_20;
  int *local_1c;
  code *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fb1ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c67194) &&
     (FUN_006cebf4(&DAT_00c67194,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00c67194 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00c67198 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "CProdPlanner::MaintenanceTick()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c67194);
  }
  iVar8 = DAT_00c67198;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c67198 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar15 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_0042fbb0(0);
  FUN_0042fbb0(0);
  pcVar13 = RaiseException_exref;
  uVar11 = 0xffffffff;
  local_14 = DAT_0077244c;
  local_18 = RaiseException_exref;
  iVar3 = DAT_0077244c;
  while( true ) {
    uVar11 = uVar11 + 1;
    if ((int)*(uint *)(iVar3 + 0x84b5) <= (int)uVar11) break;
    if (*(uint *)(iVar3 + 0x84b5) <= uVar11) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar3 = local_14;
    }
    uVar12 = *(uint *)(*(int *)(iVar3 + 0x84b1) + uVar11 * 4);
    puVar9 = (uint *)(iVar3 + 0x488);
    if (uVar12 < 0x2000) {
      puVar9 = puVar9 + uVar12;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar3 = local_14;
    }
    piVar10 = (int *)*puVar9;
    local_1c = piVar10;
    if (piVar10[0xdb] == this->i_04) {
      if (piVar10[0xf8] != 0) {
        uVar12 = this->i_20;
        if ((uVar12 + 0x10 & 0xfffffff0) != (uVar12 + 0xf & 0xfffffff0)) {
          iVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                               ,0x9b);
          uVar12 = this->i_20;
          this->i_1c = iVar3;
        }
        uVar4 = uVar12 + 1;
        this->i_20 = uVar4;
        if (uVar4 <= uVar12) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar4 = this->i_20;
        }
        if (uVar4 <= uVar4 - 1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(int **)(this->i_1c + (uVar4 - 1) * 4) = piVar10;
      }
      iVar3 = local_14;
      if (piVar10[0xf9] != 0) {
        if (((*(int *)(piVar10[0xf9] + 0x40) != -1) && ((char)piVar10[0xd7] != '\0')) &&
           ((*(char *)((int)piVar10 + 0x35d) != '\0' && ((piVar10[0xf4] & 0x800000U) == 0)))) {
          FUN_0043d6d0(&local_1c);
        }
        local_1c = (int *)FUN_0043a050(piVar10);
        iVar3 = local_14;
        if (local_1c != (int *)0xffffffff) {
          if ((int *)this->i_70 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar5 = (int)local_1c * 0x10 + this->i_6c;
          iVar8 = *(int *)(iVar5 + 4);
          iVar3 = local_14;
          if ((-1 < iVar8) &&
             (cVar2 = FUN_0043a290(iVar8,iVar5,iVar8), iVar3 = local_14, cVar2 == '\0')) {
            FUN_0043d4b0(local_1c);
            FUN_0043a0c0(piVar10);
            *(undefined1 *)(piVar10[0xf9] + 4) = 1;
            FUN_0043a7b0(piVar10);
            iVar3 = local_14;
          }
        }
      }
    }
  }
  FUN_004338a0();
  FUN_004344e0();
  iVar3 = this->i_60;
  local_1c = (int *)0x0;
  if (0 < iVar3) {
    local_14 = 0;
    do {
      if ((int *)this->i_60 <= local_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(this->i_5c + 4 + local_14) = 0;
      local_14 = local_14 + 0x18;
      local_1c = (int *)((int)local_1c + 1);
    } while ((int)local_1c < iVar3);
  }
  local_20 = 0;
  if (0 < this->i_70) {
    bVar14 = this->i_70 != 0;
    do {
      if (!bVar14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_20 = local_20 + 1;
      bVar14 = local_20 < (uint)this->i_70;
    } while ((int)local_20 < this->i_70);
  }
  iVar3 = this->i_68;
  if (iVar3 < 0) {
    FUN_0043dbd0(-iVar3);
  }
  else if (0 < iVar3) {
    this->i_68 = this->i_68 - iVar3;
  }
  FUN_00434e60();
  FUN_00436440();
  FUN_00433780();
  FUN_00435f50();
  FUN_00433780();
  FUN_00436750();
  FUN_00433780();
  FUN_00436d40();
  FUN_00433780();
  FUN_004375c0();
  FUN_00433780();
  local_1c = (int *)this->i_60;
  if (0 < (int)local_1c) {
    uVar11 = 0;
    local_20 = 0;
    do {
      if ((uint)this->i_60 <= uVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar10 = (int *)(local_20 + 0x14 + this->i_5c);
      *piVar10 = *piVar10 + -1;
      if ((uint)this->i_60 <= uVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*(int *)(this->i_5c + 0x14 + local_20) < 1) {
        uVar12 = this->i_60;
        if (uVar12 <= uVar11) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar12 = this->i_60;
          if (uVar12 <= uVar11) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar12 = this->i_60;
          }
        }
        if ((int)uVar11 < (int)(uVar12 - 1)) {
          iVar3 = local_20 + this->i_5c;
          FUN_006d1b90(iVar3,iVar3 + 0x18,(uVar12 - uVar11) * 0x18 + -0x18);
          uVar12 = this->i_60;
        }
        this->i_60 = uVar12 - 1;
        uVar11 = uVar11 - 1;
        local_20 = local_20 + -0x18;
        local_1c = (int *)((int)local_1c + -1);
      }
      uVar11 = uVar11 + 1;
      local_20 = local_20 + 0x18;
    } while ((int)uVar11 < (int)local_1c);
  }
  FUN_0043bdd0();
  FUN_00433780();
  FUN_0043b620();
  FUN_00433780();
  iVar3 = this->i_38;
  local_20 = 0;
  if (0 < iVar3) {
    piVar10 = (int *)(DAT_0077244c + 0x488);
    local_1c = piVar10;
    do {
      if ((uint)this->i_38 <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = local_1c;
      }
      uVar11 = *(uint *)(this->i_34 + local_20 * 4);
      if (uVar11 < 0x2000) {
        piVar6 = piVar10 + uVar11;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar6 = local_1c;
        piVar10 = local_1c;
      }
      if ((*piVar6 != 0) && (iVar8 = *(int *)(*piVar6 + 0x3e4), iVar8 != 0)) {
        *(undefined1 *)(iVar8 + 4) = 0;
      }
      local_20 = local_20 + 1;
    } while ((int)local_20 < iVar3);
  }
  FUN_0040b980(0);
  FUN_0042fbb0(0);
  local_14 = DAT_0077244c;
  uVar11 = 0xffffffff;
LAB_00433f87:
  uVar11 = uVar11 + 1;
  if ((int)uVar11 < (int)*(uint *)(local_14 + 0x84d7)) {
    if (*(uint *)(local_14 + 0x84d7) <= uVar11) {
      (*pcVar13)(0xc000008c,1,0,0);
    }
    uVar12 = *(uint *)(*(int *)(local_14 + 0x84d3) + uVar11 * 4);
    puVar7 = (undefined4 *)(local_14 + 0x488);
    if (uVar12 < 0x2000) {
      puVar7 = puVar7 + uVar12;
    }
    else {
      (*pcVar13)(0xc000008c,1,0,0);
    }
    iVar3 = DAT_0077244c;
    local_1c = (int *)*puVar7;
    if ((local_1c != (int *)0x0) && (local_1c[0xdb] == this->i_04)) {
      iVar8 = local_1c[0xf9];
      uVar12 = *(uint *)(iVar8 + 0x28);
      if (uVar12 != 0xffffffff) {
        if (uVar12 < 0x2000) {
          iVar5 = DAT_0077244c + uVar12 * 4;
        }
        else {
          (*pcVar13)(0xc000008c,1,0,0);
          iVar5 = iVar3;
        }
        if (*(int *)(iVar5 + 0x488) != 0) {
          *(undefined4 *)(*(int *)(iVar5 + 0x488) + 1000) = 2;
        }
      }
      uVar12 = *(uint *)(iVar8 + 0x2c);
      if (uVar12 != 0xffffffff) {
        if (uVar12 < 0x2000) {
          iVar3 = iVar3 + uVar12 * 4;
        }
        else {
          (*pcVar13)(0xc000008c,1,0,0);
        }
        if (*(int *)(iVar3 + 0x488) != 0) {
          *(undefined4 *)(*(int *)(iVar3 + 0x488) + 1000) = 2;
        }
      }
      piVar10 = (int *)local_1c[0xf9];
      if ((char)piVar10[1] == '\0') {
        iVar3 = 0;
      }
      else {
        iVar3 = *piVar10 + 1;
        if (2 < iVar3) {
          *piVar10 = 0;
          piVar10[10] = -1;
          piVar10[0xb] = -1;
          piVar10[0xc] = -1;
          piVar10[6] = 0;
          piVar10[5] = 0;
          piVar10[4] = 0;
          piVar10[9] = 0;
          piVar10[8] = 0;
          piVar10[7] = 0;
          piVar10[3] = 2;
          *(undefined1 *)(piVar10 + 1) = 1;
        }
      }
      *piVar10 = iVar3;
      iVar3 = local_1c[0xf9];
      if ((*(int *)(iVar3 + 0xc) == 0xe) && (*(char *)((int)local_1c + 0x35d) == '\0')) {
        FUN_005dc6a0(iVar3);
        FUN_005ee9d0();
        if (*(char *)(iVar3 + 0x44) != '\0') {
          *(undefined1 *)(iVar3 + 0x44) = 0;
        }
        iVar3 = local_1c[0xf9];
        FUN_005dc6a0(extraout_ECX);
        *(undefined4 *)(iVar3 + 0x34) = 1;
        iVar3 = local_1c[0xf9];
        pcVar13 = local_18;
      }
      if ((((*(int *)(iVar3 + 0xc) == 2) && ((char)local_1c[0xd7] != '\0')) &&
          (*(char *)((int)local_1c + 0x35d) != '\0')) && ((local_1c[0xf4] & 0x800000U) == 0)) {
        *(undefined1 *)((int)local_1c + 0x35e) = 0;
        iVar3 = this->i_30;
        uVar12 = 0;
        piVar10 = local_1c;
        if (0 < iVar3) {
          do {
            if ((uint)this->i_30 <= uVar12) {
              (*local_18)(0xc000008c,1,0,0);
              piVar10 = local_1c;
            }
            pcVar13 = local_18;
            if (*(int **)(this->i_2c + uVar12 * 4) == piVar10) goto LAB_00433f87;
            uVar12 = uVar12 + 1;
          } while ((int)uVar12 < iVar3);
        }
        uVar12 = FUN_0042f510();
        pcVar13 = local_18;
        if ((uint)this->i_30 <= uVar12) {
          (*local_18)(0xc000008c,1,0,0);
        }
        *(int **)(this->i_2c + uVar12 * 4) = local_1c;
      }
    }
    goto LAB_00433f87;
  }
  local_1c = (int *)this->i_30;
  if (0 < (int)local_1c) {
    local_20 = 0;
    do {
      if ((uint)this->i_30 <= local_20) {
        (*pcVar13)(0xc000008c,1,0,0);
      }
      iVar3 = *(int *)(this->i_2c + local_20 * 4);
      iVar8 = FUN_0043a050(iVar3);
      *(undefined4 *)(*(int *)(iVar3 + 0x3e4) + 0x48) = 0;
      if (iVar8 == -1) {
        FUN_0043a0c0(iVar3);
        if (*(char *)(iVar3 + 0x35d) == '\0') goto LAB_00434318;
      }
      else {
        *(undefined4 *)(iVar3 + 1000) = 2;
        *(undefined1 *)(iVar3 + 0x35e) = 1;
        FUN_0043a460(iVar3,iVar8);
LAB_00434318:
        if ((uint)this->i_30 <= local_20) {
          (*pcVar13)(0xc000008c,1,0,0);
        }
        local_14 = *(int *)(this->i_2c + local_20 * 4);
        if (local_14 != 0) {
          iVar3 = this->i_30;
          uVar11 = 0;
          pcVar13 = local_18;
          if (0 < iVar3) {
            do {
              if ((uint)this->i_30 <= uVar11) {
                (*local_18)(0xc000008c,1,0,0);
              }
              if (*(int *)(this->i_2c + uVar11 * 4) == local_14) {
                FUN_0040b5c0(uVar11);
                pcVar13 = local_18;
                goto LAB_00434399;
              }
              uVar11 = uVar11 + 1;
            } while ((int)uVar11 < iVar3);
            local_20 = local_20 - 1;
            local_1c = (int *)((int)local_1c - 1);
            pcVar13 = local_18;
            goto LAB_00434281;
          }
        }
LAB_00434399:
        local_20 = local_20 - 1;
        local_1c = (int *)((int)local_1c - 1);
      }
LAB_00434281:
      local_20 = local_20 + 1;
    } while ((int)local_20 < (int)local_1c);
  }
  FUN_00437bb0();
  uVar11 = this->i_30 - 1;
  if (-1 < (int)uVar11) {
    puVar9 = (uint *)(&this[0x47].field_0x44 + this->i_30 * 4);
    do {
      local_1c = (int *)*puVar9;
      if (local_1c != (int *)0xffffffff) {
        if ((int *)this->i_68 <= local_1c) {
          (*pcVar13)(0xc000008c,1,0,0);
        }
        if (0.0 < *(float *)(this->i_64 + 0x18 + (int)local_1c * 0x28)) {
          if ((uint)this->i_30 <= uVar11) {
            (*pcVar13)(0xc000008c,1,0,0);
          }
          iVar3 = uVar11 * 4;
          FUN_00437da0(*(undefined4 *)(this->i_2c + iVar3),
                       *(undefined4 *)(&this[0x47].field_0x48 + uVar11 * 4));
          if ((uint)this->i_30 <= uVar11) {
            (*pcVar13)(0xc000008c,1,0,0);
          }
          iVar8 = FUN_0043a050(*(undefined4 *)(this->i_2c + iVar3));
          if (iVar8 != -1) {
            if ((uint)this->i_30 <= uVar11) {
              (*pcVar13)(0xc000008c,1,0,0);
            }
            iVar3 = *(int *)(iVar3 + this->i_2c);
            iVar8 = FUN_0043a050(iVar3);
            *(undefined4 *)(*(int *)(iVar3 + 0x3e4) + 0x48) = 0;
            if (iVar8 == -1) {
              FUN_0043a0c0(iVar3);
            }
            else {
              *(undefined4 *)(iVar3 + 1000) = 2;
              *(undefined1 *)(iVar3 + 0x35e) = 1;
              FUN_0043a460(iVar3,iVar8);
            }
          }
          break;
        }
      }
      uVar11 = uVar11 - 1;
      puVar9 = puVar9 + -1;
    } while (-1 < (int)uVar11);
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

