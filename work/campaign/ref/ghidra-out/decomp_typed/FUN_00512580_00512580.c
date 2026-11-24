
void FUN_00512580(void)

{
  void *pvVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  BOOL BVar6;
  int iVar7;
  int this;
  int iVar8;
  int *piVar9;
  int *piVar10;
  float in_XMM0_Da;
  int local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  uint local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9510;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->c_1c == '\0') {
    return;
  }
  piVar9 = (int *)(DAT_00772400 + 0xa0c8);
  ExceptionList = &local_10;
  *(undefined4 *)(DAT_00772400 + 0xa0d0) = 0xffffffff;
  if (*piVar9 == 0) {
    if (this->c_1c == '\0') {
      ExceptionList = pvVar1;
      return;
    }
    FUN_00504ee0(uVar5);
    this->c_1c = 0;
    ExceptionList = local_10;
    return;
  }
  piVar9 = (int *)(this + 0x44);
  local_11 = '\0';
  local_2c = 0;
  local_1c = 0;
  local_18 = (int *)0x0;
  local_24 = piVar9;
  local_20 = this;
  do {
    if (&DAT_00000005 < local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar10 = piVar9;
    }
    else {
      piVar10 = (int *)(local_1c + (int)piVar9);
    }
    if (*piVar10 != 0) {
      if (&DAT_00000005 < local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = piVar9;
      }
      else {
        piVar10 = (int *)(local_1c + (int)piVar9);
      }
      pvVar1 = (void *)*piVar10;
      if ((((pvVar1 == (void *)0x0) || (BVar6 = IsBadReadPtr(pvVar1,0x10), BVar6 != 0)) ||
          (*(int *)((int)pvVar1 + 8) != 0x616e4f62)) ||
         ((DAT_00768398 != '\0' && (*(int *)((int)pvVar1 + 0xdc) == 0)))) {
        if (&DAT_00000005 < local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          *piVar9 = 0;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = piVar9;
        }
        else {
          *(undefined4 *)(local_1c + (int)piVar9) = 0;
          piVar10 = (int *)(local_1c + (int)piVar9);
        }
        piVar10[0xc] = -1;
      }
      else {
        uVar5 = 0;
        local_28 = (int *)0x0;
        while( true ) {
          if (&DAT_00000005 < local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar10 = piVar9;
          }
          else {
            piVar10 = (int *)(local_1c + (int)piVar9);
          }
          if (*(int *)(*piVar10 + 0x5c) <= (int)uVar5) break;
          if (&DAT_00000005 < local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_30 = piVar9;
          }
          else {
            local_30 = (int *)(local_1c + (int)piVar9);
          }
          local_30 = (int *)*local_30;
          if ((-1 < (int)uVar5) && ((int)uVar5 < local_30[0x17])) {
            if ((uint)local_30[0x17] <= uVar5) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar8 = *(int *)(local_30[0x16] + uVar5 * 4);
            if (iVar8 != 0) {
              local_28 = (int *)((int)local_28 + *(int *)(iVar8 + 0xdc));
            }
          }
          uVar5 = uVar5 + 1;
        }
        if (&DAT_00000005 < local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = piVar9;
        }
        else {
          piVar10 = (int *)(local_1c + (int)piVar9);
        }
        piVar2 = local_28;
        if (local_28 != (int *)piVar10[0xc]) {
          local_11 = '\x01';
          if (local_2c < 6) {
            piVar9[local_2c * 0xd + 0xc] = (int)local_28;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(int **)(this + 0x74) = piVar2;
          }
          goto LAB_005128b1;
        }
      }
    }
    local_2c = local_2c + 1;
    local_18 = (int *)((int)local_18 + 1);
    local_1c = local_1c + 0x34;
  } while ((int)local_18 < 6);
  local_28 = (int *)0x0;
  local_1c = 0;
  local_2c = 0;
  do {
    if (local_1c < 6) {
      piVar10 = (int *)(local_2c + (int)piVar9);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar10 = piVar9;
    }
    if (*piVar10 != 0) {
      iVar8 = 0;
      while( true ) {
        local_30 = (int *)(DAT_00772478 + 0x10);
        if (local_1c < 6) {
          piVar10 = local_30 + local_1c * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = local_30;
        }
        if (piVar10[1] <= iVar8) break;
        if (local_1c < 6) {
          local_18 = (int *)(local_2c + (int)piVar9);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = piVar9;
        }
        if ((iVar8 < 0) || (local_18[2] <= iVar8)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = (int *)local_18[1];
        }
        else {
          piVar10 = (int *)(local_18[1] + iVar8 * 4);
        }
        if ((*piVar10 != 0) &&
           (cVar4 = FUN_0046a9d0(*(undefined4 *)(*piVar10 + 0xdc)), cVar4 != '\0')) {
          local_28 = (int *)((int)local_28 + 1);
        }
        iVar8 = iVar8 + 1;
      }
    }
    local_1c = local_1c + 1;
    local_2c = local_2c + 0x34;
  } while ((int)local_1c < 6);
  if (local_28 != *(int **)(local_20 + 0x17c)) {
    *(int **)(local_20 + 0x17c) = local_28;
    local_11 = '\x01';
  }
LAB_005128b1:
  if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
    iVar8 = 0;
  }
  else {
    piVar10 = (int *)(DAT_0077244c + 0x488);
    if (**(uint **)(DAT_00772400 + 0xa0c4) < 0x2000) {
      piVar10 = piVar10 + **(uint **)(DAT_00772400 + 0xa0c4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar8 = *piVar10;
  }
  local_1c = *piVar9;
  if ((local_1c == iVar8) && (local_11 == '\0')) {
    if (*(int *)(local_1c + 0x21c) == 0) {
      FUN_005da0f0();
      local_2c = 0xffffffff;
      local_30 = (int *)FUN_006ba810(0x19);
      local_30[1] = 0x14;
      local_30[2] = -1;
      *local_30 = 0;
      *(undefined1 *)(local_30 + 3) = 0;
      local_30[3] = 0x5f707865;
      local_30[4] = 0x706d614b;
      *(undefined2 *)(local_30 + 5) = 0x66;
      local_30[2] = 9;
      *local_30 = 1;
      local_28 = local_30;
      local_11 = FUN_00444990(&local_30,&local_2c);
      local_8 = 0;
      *local_28 = *local_28 + -1;
      if (*local_28 == 0) {
        FUN_006ba940();
      }
      local_8 = 0xffffffff;
      uVar5 = 0xffffffff;
      if (local_11 != '\0') {
        uVar5 = local_2c;
      }
      if (*(int *)(local_1c + 0x21c) == 0) {
        if (uVar5 < 0x200) {
          iVar8 = FUN_005da0f0();
          in_XMM0_Da = *(float *)(iVar8 + 0x1804 + uVar5 * 4);
        }
        else {
LAB_005129f1:
          in_XMM0_Da = 0.0;
        }
      }
      else {
        if (0x1ff < uVar5) goto LAB_005129f1;
        in_XMM0_Da = *(float *)(*(int *)(local_1c + 0x21c) + uVar5 * 4);
      }
    }
    else {
      FUN_005da900("exp_Kampf");
    }
    if (in_XMM0_Da == *(float *)(local_20 + 0x180)) goto LAB_00512a24;
    *(float *)(local_20 + 0x180) = in_XMM0_Da;
  }
  FUN_00511c50();
LAB_00512a24:
  iVar8 = FUN_00501450();
  local_34 = 0xb9;
  local_30 = (int *)((*(int *)(*(int *)(iVar8 + 0x8194) + 0x18) -
                     *(int *)(*(int *)(iVar8 + 0x8194) + 0x10)) + -0x78);
  FUN_00504a70(&local_34);
  iVar8 = FUN_00501450();
  local_30 = (int *)0x78;
  local_34 = (*(int *)(*(int *)(iVar8 + 0x8194) + 0x14) - *(int *)(*(int *)(iVar8 + 0x8194) + 0xc))
             + -0x172;
  FUN_00504ba0(&local_34);
  local_1c = 0;
  do {
    if (*(int *)(DAT_00772400 + 0xa0d0) != -1) {
      ExceptionList = local_10;
      return;
    }
    if (local_1c < 6) {
      piVar10 = piVar9 + local_1c * 0xd;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar10 = piVar9;
    }
    if (*piVar10 != 0) {
      uVar5 = 0;
      while( true ) {
        local_30 = (int *)(DAT_00772478 + 0x10);
        if (local_1c < 6) {
          piVar10 = local_30 + local_1c * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = local_30;
        }
        if (piVar10[1] <= (int)uVar5) break;
        if (local_1c < 6) {
          piVar9 = local_24 + local_1c * 0xd;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (((int)uVar5 < 0) || (piVar9[4] <= (int)uVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar9 = (int *)piVar9[3];
        }
        else {
          piVar9 = (int *)(piVar9[3] + uVar5 * 4);
        }
        iVar8 = *piVar9;
        iVar7 = FUN_00501450();
        if ((*(int *)(iVar7 + 0x8198) == iVar8) &&
           ((iVar7 = FUN_00501450(), *(int *)(iVar7 + 0x81a4) == 0 ||
            (iVar7 = FUN_00501450(), *(int *)(iVar7 + 0x81a4) == iVar8)))) {
          uVar3 = local_1c;
          if (local_1c < 6) {
            local_30 = local_24 + local_1c * 0xd;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_30 = local_24;
          }
          local_30 = (int *)*local_30;
          if ((-1 < (int)uVar5) && ((int)uVar5 < local_30[0x17])) {
            if ((uint)local_30[0x17] <= uVar5) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar8 = *(int *)(local_30[0x16] + uVar5 * 4);
            if (iVar8 != 0) {
              *(undefined4 *)(DAT_00772400 + 0xa0d0) = *(undefined4 *)(iVar8 + 0xdc);
              if ((-1 < (int)uVar3) && ((int)uVar3 < 6)) {
                ExceptionList = local_10;
                return;
              }
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              ExceptionList = local_10;
              return;
            }
          }
        }
        uVar5 = uVar5 + 1;
        piVar9 = local_24;
      }
    }
    local_1c = local_1c + 1;
    if (5 < (int)local_1c) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

