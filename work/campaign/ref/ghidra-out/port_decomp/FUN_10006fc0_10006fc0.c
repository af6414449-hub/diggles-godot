
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10006fc0(int param_1,size_t param_2,int *param_3,int *param_4,uint *param_5)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  void *pvVar9;
  uint uVar10;
  int *in_ECX;
  undefined4 *puVar11;
  uint in_EDX;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  int local_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int local_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  undefined8 local_78;
  char *pcStack_70;
  int iStack_6c;
  undefined1 local_68 [8];
  undefined8 local_60;
  uint *local_58;
  int local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  char *local_44;
  int *local_40;
  void *local_3c;
  void *local_38;
  uint local_34;
  undefined8 local_30;
  int *local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_1004199d;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_50 = param_3;
  local_4c = param_4;
  local_58 = param_5;
  local_48 = in_ECX;
  local_34 = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  if (local_34 == 0) {
    FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_68,(ThrowInfo *)&DAT_1004a24c);
  }
  local_38 = (void *)FUN_100402f0(param_2);
  local_3c = (void *)FUN_100402f0(-(uint)((int)((ulonglong)local_34 * 4 >> 0x20) != 0) |
                                  (uint)((ulonglong)local_34 * 4));
  if (0 < (int)param_2) {
    memset(local_38,0,param_2);
  }
  local_54 = 0;
  piVar12 = in_ECX;
  if (0 < (int)local_34) {
    do {
      local_40 = piVar12;
      puVar11 = (undefined4 *)((int)local_3c + local_54 * 4);
      *puVar11 = 1;
      iVar8 = 0;
      if (0 < (int)param_2) {
        do {
          if (((*(char *)(iVar8 + (int)local_38) == '\0') &&
              (*(int *)(param_1 + iVar8 * 8) == *local_40)) &&
             (*(int *)(param_1 + 4 + iVar8 * 8) == local_40[1])) {
            *(undefined1 *)(iVar8 + (int)local_38) = 1;
            *puVar11 = 3;
            break;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)param_2);
      }
      local_54 = local_54 + 1;
      local_40 = local_40 + 7;
      piVar12 = local_40;
    } while (local_54 < (int)local_34);
  }
  piVar12 = (int *)0x0;
  puVar2 = (uint *)((int)local_3c + local_34 * 4 + -4);
  *puVar2 = *puVar2 | 4;
  local_44 = (char *)local_48[6];
  local_98 = *local_48;
  iStack_94 = local_48[1];
  iVar8 = local_48[2];
  iVar14 = local_48[3];
  local_30._0_4_ = 0;
  uVar15 = *(undefined8 *)(local_48 + 4);
  local_30 = 0;
  local_28 = (int *)0x0;
  iVar13 = 0;
  local_14 = 0;
  pvVar9 = local_38;
  iStack_90 = iVar8;
  iStack_8c = iVar14;
  local_60 = uVar15;
  if (0 < (int)param_2) {
    do {
      if (*(char *)(iVar13 + (int)pvVar9) == '\0') {
        iStack_6c = 2;
        local_88 = *(int *)(param_1 + iVar13 * 8);
        iStack_84 = *(int *)(param_1 + 4 + iVar13 * 8);
        pcStack_70 = local_44;
        iStack_80 = iVar8;
        iStack_7c = iVar14;
        local_78 = uVar15;
        if (piVar12 == local_28) {
          FUN_10007d10(piVar12,&local_88);
          pvVar9 = local_38;
          piVar12 = local_30._4_4_;
          iVar8 = iStack_90;
          iVar14 = iStack_8c;
          uVar15 = local_60;
        }
        else {
          *piVar12 = local_88;
          piVar12[1] = iStack_84;
          piVar12[2] = iVar8;
          piVar12[3] = iVar14;
          local_78._0_4_ = (int)uVar15;
          local_78._4_4_ = (int)((ulonglong)uVar15 >> 0x20);
          piVar12[4] = (int)local_78;
          piVar12[5] = local_78._4_4_;
          piVar12[6] = (int)local_44;
          piVar12[7] = 2;
          piVar12 = (int *)((int)local_30._4_4_ + 0x20);
          local_30 = CONCAT44(piVar12,(int)local_30);
          pvVar9 = local_38;
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < (int)param_2);
  }
  iVar14 = 0;
  iVar8 = (int)local_30;
  if (0 < (int)local_34) {
    do {
      local_88 = *local_48;
      iStack_84 = local_48[1];
      iStack_80 = local_48[2];
      iStack_7c = local_48[3];
      local_78 = *(undefined8 *)(local_48 + 4);
      iStack_6c = *(int *)((int)local_3c + iVar14 * 4);
      pcStack_70 = (char *)local_48[6];
      if (piVar12 == local_28) {
        FUN_10007d10(piVar12,&local_88);
        piVar12 = local_30._4_4_;
      }
      else {
        local_78._4_4_ = (int)((ulonglong)local_78 >> 0x20);
        *piVar12 = local_88;
        piVar12[1] = iStack_84;
        piVar12[2] = iStack_80;
        piVar12[3] = iStack_7c;
        piVar12[4] = (int)local_78;
        piVar12[5] = local_78._4_4_;
        piVar12[6] = (int)pcStack_70;
        piVar12[7] = iStack_6c;
        piVar12 = (int *)((int)local_30._4_4_ + 0x20);
        local_30 = CONCAT44(piVar12,(int)local_30);
      }
      iVar14 = iVar14 + 1;
      local_48 = local_48 + 7;
    } while (iVar14 < (int)local_34);
    iVar8 = (int)local_30;
  }
  FUN_100081e0((int)piVar12 - iVar8 >> 5,FUN_10011fb0);
  puVar2 = local_58;
  uVar10 = (int)local_30._4_4_ - (int)local_30 >> 5;
  *local_58 = uVar10;
  lVar4 = (ulonglong)uVar10 * 0x1c;
  iVar8 = FUN_100402f0(-(uint)((int)((ulonglong)lVar4 >> 0x20) != 0) | (uint)lVar4);
  *local_50 = iVar8;
  lVar4 = (ulonglong)*puVar2 * 4;
  iVar8 = FUN_100402f0(-(uint)((int)((ulonglong)lVar4 >> 0x20) != 0) | (uint)lVar4);
  uVar10 = 0;
  *local_4c = iVar8;
  if (*puVar2 != 0) {
    iVar8 = 0;
    local_44 = "Fullscreen";
    local_40 = (int *)0x0;
    do {
      puVar11 = (undefined4 *)((int)local_30 + (int)local_40);
      uVar5 = puVar11[1];
      uVar6 = puVar11[2];
      uVar7 = puVar11[3];
      iVar14 = *local_50;
      puVar1 = (undefined4 *)(iVar14 + iVar8);
      *puVar1 = *puVar11;
      puVar1[1] = uVar5;
      puVar1[2] = uVar6;
      puVar1[3] = uVar7;
      *(undefined8 *)(iVar14 + 0x10 + iVar8) = *(undefined8 *)((int)local_30 + 0x10 + (int)local_40)
      ;
      *(undefined4 *)(iVar14 + 0x18 + iVar8) = *(undefined4 *)((int)local_30 + 0x18 + (int)local_40)
      ;
      *(undefined4 *)(*local_4c + uVar10 * 4) =
           *(undefined4 *)((int)local_30 + 0x1c + (int)local_40);
      uVar3 = *(uint *)(*local_4c + uVar10 * 4);
      puVar11 = (undefined4 *)(*local_50 + iVar8);
      if ((uVar3 & 1) == 0) {
        _DAT_1416ecc0 = "Windowed";
      }
      else if ((uVar3 & 2) == 0) {
        _DAT_1416ecc0 = "Fullscreen & Borderless";
        if ((uVar3 & 4) == 0) {
          _DAT_1416ecc0 = local_44;
        }
      }
      else {
        _DAT_1416ecc0 = "Windowed & Fullscreen";
      }
      if (uVar3 == 0) {
        FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_98,(ThrowInfo *)&DAT_1004a24c);
      }
      FUN_100028b0(&DAT_1416ecc8,0x80,"Sorted display mode : %d x %d, %u Hz, %s \n",*puVar11,
                   puVar11[1],(uint)puVar11[2] / (uint)puVar11[3],_DAT_1416ecc0);
      OutputDebugStringA(&DAT_1416ecc8);
      uVar10 = uVar10 + 1;
      iVar8 = iVar8 + 0x1c;
      local_40 = local_40 + 8;
    } while (uVar10 < *local_58);
  }
  free(local_38);
  free(local_3c);
  if ((int)local_30 != 0) {
    uVar10 = (int)local_28 - (int)local_30 & 0xffffffe0;
    iVar8 = (int)local_30;
    if (0xfff < uVar10) {
      iVar8 = *(int *)((int)local_30 + -4);
      uVar10 = uVar10 + 0x23;
      if (0x1f < ((int)local_30 - iVar8) - 4U) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
    }
    FUN_100402ac(iVar8,uVar10);
  }
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
  return;
}

