
void __thiscall FUN_00512580(ViWinInventory *this)

{
  void *pvVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  BOOL BVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  float in_XMM0_Da;
  int local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  int *local_24;
  ViWinInventory *local_20;
  uint local_1c;
  undefined1 *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pvVar1 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9510;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->c_1c == '\0') {
    return;
  }
  piVar8 = (int *)(DAT_00772400 + 0xa0c8);
  ExceptionList = &local_10;
  *(undefined4 *)(DAT_00772400 + 0xa0d0) = 0xffffffff;
  local_20 = this;
  if (*piVar8 == 0) {
    if (this->c_1c == '\0') {
      ExceptionList = pvVar1;
      return;
    }
    FUN_00504ee0(uVar4);
    this->c_1c = '\0';
    ExceptionList = local_10;
    return;
  }
  piVar8 = (int *)&this[2].field_0xa;
  local_11 = '\0';
  local_2c = 0;
  local_1c = 0;
  local_18 = (undefined1 *)0x0;
  local_24 = piVar8;
  do {
    if (&DAT_00000005 < local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar11 = piVar8;
    }
    else {
      piVar11 = (int *)((int)piVar8 + local_1c);
    }
    if (*piVar11 != 0) {
      if (&DAT_00000005 < local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = piVar8;
      }
      else {
        puVar6 = (undefined4 *)((int)piVar8 + local_1c);
      }
      pvVar1 = (void *)*puVar6;
      if ((((pvVar1 == (void *)0x0) || (BVar5 = IsBadReadPtr(pvVar1,0x10), BVar5 != 0)) ||
          (*(int *)((int)pvVar1 + 8) != 0x616e4f62)) ||
         ((DAT_00768398 != '\0' && (*(int *)((int)pvVar1 + 0xdc) == 0)))) {
        if (&DAT_00000005 < local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          *piVar8 = 0;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar7 = (undefined1 *)piVar8;
        }
        else {
          *(undefined4 *)((int)piVar8 + local_1c) = 0;
          puVar7 = (undefined1 *)((int)piVar8 + local_1c);
        }
        *(undefined4 *)(puVar7 + 0x30) = 0xffffffff;
      }
      else {
        uVar4 = 0;
        local_28 = (int *)0x0;
        while( true ) {
          if (&DAT_00000005 < local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar11 = piVar8;
          }
          else {
            piVar11 = (int *)((int)piVar8 + local_1c);
          }
          if (*(int *)(*piVar11 + 0x5c) <= (int)uVar4) break;
          if (&DAT_00000005 < local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar6 = piVar8;
          }
          else {
            puVar6 = (undefined4 *)((int)piVar8 + local_1c);
          }
          local_30 = (int *)*puVar6;
          if ((-1 < (int)uVar4) && ((int)uVar4 < local_30[0x17])) {
            if ((uint)local_30[0x17] <= uVar4) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar10 = *(int *)(local_30[0x16] + uVar4 * 4);
            if (iVar10 != 0) {
              local_28 = (int *)((int)local_28 + *(int *)(iVar10 + 0xdc));
            }
          }
          uVar4 = uVar4 + 1;
        }
        if (&DAT_00000005 < local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar7 = (undefined1 *)piVar8;
        }
        else {
          puVar7 = (undefined1 *)((int)piVar8 + local_1c);
        }
        piVar11 = local_28;
        if (local_28 != *(int **)(puVar7 + 0x30)) {
          local_11 = '\x01';
          if (local_2c < 6) {
            *(int **)((int)piVar8 + (local_2c * 0xd + 0xc) * 4) = local_28;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(int **)(this + 4) = piVar11;
          }
          goto LAB_005128b1;
        }
      }
    }
    local_2c = local_2c + 1;
    local_18 = local_18 + 1;
    local_1c = local_1c + 0x34;
  } while ((int)local_18 < 6);
  local_28 = (int *)0x0;
  local_1c = 0;
  local_2c = 0;
  do {
    if (local_1c < 6) {
      piVar11 = (int *)((int)piVar8 + local_2c);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar11 = piVar8;
    }
    if (*piVar11 != 0) {
      iVar10 = 0;
      while( true ) {
        local_30 = (int *)(DAT_00772478 + 0x10);
        if (local_1c < 6) {
          piVar11 = local_30 + local_1c * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = local_30;
        }
        if (piVar11[1] <= iVar10) break;
        if (local_1c < 6) {
          local_18 = (undefined1 *)((int)piVar8 + local_2c);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = (undefined1 *)piVar8;
        }
        if ((iVar10 < 0) || (*(int *)(local_18 + 8) <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = *(int **)(local_18 + 4);
        }
        else {
          piVar11 = (int *)(*(int *)(local_18 + 4) + iVar10 * 4);
        }
        if ((*piVar11 != 0) &&
           (cVar3 = FUN_0046a9d0(*(undefined4 *)(*piVar11 + 0xdc)), cVar3 != '\0')) {
          local_28 = (int *)((int)local_28 + 1);
        }
        iVar10 = iVar10 + 1;
      }
    }
    local_1c = local_1c + 1;
    local_2c = local_2c + 0x34;
  } while ((int)local_1c < 6);
  if (local_28 != *(int **)&local_20[0xd].field_0x3) {
    *(int **)&local_20[0xd].field_0x3 = local_28;
    local_11 = '\x01';
  }
LAB_005128b1:
  if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
    iVar10 = 0;
  }
  else {
    piVar11 = (int *)(DAT_0077244c + 0x488);
    if (**(uint **)(DAT_00772400 + 0xa0c4) < 0x2000) {
      piVar11 = piVar11 + **(uint **)(DAT_00772400 + 0xa0c4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar10 = *piVar11;
  }
  local_1c = *piVar8;
  if ((local_1c == iVar10) && (local_11 == '\0')) {
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
      uVar4 = 0xffffffff;
      if (local_11 != '\0') {
        uVar4 = local_2c;
      }
      if (*(int *)(local_1c + 0x21c) == 0) {
        if (uVar4 < 0x200) {
          iVar10 = FUN_005da0f0();
          in_XMM0_Da = *(float *)(iVar10 + 0x1804 + uVar4 * 4);
        }
        else {
LAB_005129f1:
          in_XMM0_Da = 0.0;
        }
      }
      else {
        if (0x1ff < uVar4) goto LAB_005129f1;
        in_XMM0_Da = *(float *)(*(int *)(local_1c + 0x21c) + uVar4 * 4);
      }
    }
    else {
      FUN_005da900("exp_Kampf");
    }
    if (in_XMM0_Da == *(float *)&local_20[0xd].field_0x7) goto LAB_00512a24;
    *(float *)&local_20[0xd].field_0x7 = in_XMM0_Da;
  }
  FUN_00511c50();
LAB_00512a24:
  iVar10 = FUN_00501450();
  local_34 = 0xb9;
  local_30 = (int *)((*(int *)(*(int *)(iVar10 + 0x8194) + 0x18) -
                     *(int *)(*(int *)(iVar10 + 0x8194) + 0x10)) + -0x78);
  FUN_00504a70(&local_34);
  iVar10 = FUN_00501450();
  local_30 = (int *)0x78;
  local_34 = (*(int *)(*(int *)(iVar10 + 0x8194) + 0x14) - *(int *)(*(int *)(iVar10 + 0x8194) + 0xc)
             ) + -0x172;
  FUN_00504ba0(&local_34);
  local_1c = 0;
  do {
    if (*(int *)(DAT_00772400 + 0xa0d0) != -1) {
      ExceptionList = local_10;
      return;
    }
    if (local_1c < 6) {
      piVar11 = piVar8 + local_1c * 0xd;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar11 = piVar8;
    }
    if (*piVar11 != 0) {
      uVar4 = 0;
      while( true ) {
        local_30 = (int *)(DAT_00772478 + 0x10);
        if (local_1c < 6) {
          piVar11 = local_30 + local_1c * 2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = local_30;
        }
        if (piVar11[1] <= (int)uVar4) break;
        if (local_1c < 6) {
          piVar8 = local_24 + local_1c * 0xd;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (((int)uVar4 < 0) || (piVar8[4] <= (int)uVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar8 = (int *)piVar8[3];
        }
        else {
          piVar8 = (int *)(piVar8[3] + uVar4 * 4);
        }
        iVar10 = *piVar8;
        iVar9 = FUN_00501450();
        if ((*(int *)(iVar9 + 0x8198) == iVar10) &&
           ((iVar9 = FUN_00501450(), *(int *)(iVar9 + 0x81a4) == 0 ||
            (iVar9 = FUN_00501450(), *(int *)(iVar9 + 0x81a4) == iVar10)))) {
          uVar2 = local_1c;
          if (local_1c < 6) {
            local_30 = local_24 + local_1c * 0xd;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_30 = local_24;
          }
          local_30 = (int *)*local_30;
          if ((-1 < (int)uVar4) && ((int)uVar4 < local_30[0x17])) {
            if ((uint)local_30[0x17] <= uVar4) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar10 = *(int *)(local_30[0x16] + uVar4 * 4);
            if (iVar10 != 0) {
              *(undefined4 *)(DAT_00772400 + 0xa0d0) = *(undefined4 *)(iVar10 + 0xdc);
              if ((-1 < (int)uVar2) && ((int)uVar2 < 6)) {
                ExceptionList = local_10;
                return;
              }
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              ExceptionList = local_10;
              return;
            }
          }
        }
        uVar4 = uVar4 + 1;
        piVar8 = local_24;
      }
    }
    local_1c = local_1c + 1;
    if (5 < (int)local_1c) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

