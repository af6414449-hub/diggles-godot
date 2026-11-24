
void __thiscall FUN_00512c10(ViWinInventory *this)

{
  BOOL BVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int *piVar9;
  int in_stack_00000004;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  uint local_18;
  ViWinInventory *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007018a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar9 = (int *)&this[2].field_0xa;
  local_1c = 0;
  local_18 = 0;
  uVar5 = 0;
  local_14 = this;
  do {
    if (uVar5 < 6) {
      piVar4 = (int *)((int)piVar9 + local_18);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar4 = piVar9;
    }
    if (*piVar4 != 0) {
      if (uVar5 < 6) {
        puVar2 = (undefined4 *)((int)piVar9 + local_18);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar2 = piVar9;
      }
      local_20 = (int *)*puVar2;
      if ((((local_20 == (int *)0x0) || (BVar1 = IsBadReadPtr(local_20,0x10), BVar1 != 0)) ||
          (*(int *)((int)local_20 + 8) != 0x616e4f62)) ||
         ((DAT_00768398 != '\0' && (*(int *)((int)local_20 + 0xdc) == 0)))) {
        if (uVar5 < 6) {
          puVar2 = (undefined4 *)((int)piVar9 + local_18);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar2 = piVar9;
        }
        *puVar2 = 0;
      }
    }
    uVar5 = uVar5 + 1;
    local_18 = local_18 + 0x34;
  } while ((int)uVar5 < 6);
  local_18 = 0;
  do {
    if (local_18 == 1) {
      if (((piVar9[0xd] == 0) || (*(int *)&local_14[5].field_0x1b == 0)) ||
         (*(int *)(*(int *)&local_14[4].field_0x4 + 0x5c) != 0)) {
LAB_00512d45:
        if (piVar9[local_18 * 0xd] != 0) {
          uVar6 = 0;
          uVar5 = local_18;
          while( true ) {
            iVar7 = DAT_00772478 + 0x10;
            if (uVar5 < 6) {
              iVar7 = iVar7 + uVar5 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*(int *)(iVar7 + 4) <= (int)uVar6) break;
            uVar3 = uVar6 & 0x80000001;
            if ((int)uVar3 < 0) {
              uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;
            }
            iVar7 = local_1c + ((int)uVar6 / 2) * 0x28;
            FUN_004ff900(&local_14[0xd].field_0xb,*(int *)(in_stack_00000004 + 8) + iVar7,
                         *(int *)(in_stack_00000004 + 0xc) + 10 + uVar3 * 0x28,0x28,0x28,0,0,0);
            uVar5 = local_18;
            local_24 = uVar3 * 0x28 + 8;
            local_28 = iVar7;
            if (local_18 < 6) {
              puVar8 = (undefined1 *)((int)local_14 + local_18 * 0x34 + 0x44);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar8 = &local_14[2].field_0xa;
            }
            if (((int)uVar6 < 0) || (*(int *)(puVar8 + 0x10) <= (int)uVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              FUN_00504a70(&local_28);
              uVar6 = uVar6 + 1;
            }
            else {
              FUN_00504a70(&local_28);
              uVar6 = uVar6 + 1;
            }
          }
          if (uVar5 < 6) {
            puVar8 = &local_14[2].field_0xa + uVar5 * 0x34;
            piVar9 = (int *)&local_14[2].field_0xa;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar8 = &local_14[2].field_0xa;
            piVar9 = (int *)puVar8;
          }
          FUN_004ff900((int)puVar8 + 0x14,*(int *)(in_stack_00000004 + 8) + local_1c,
                       *(int *)(in_stack_00000004 + 0xc) + 0x50,0x14,0x14,0,0,3);
          local_20 = (int *)(DAT_00772478 + 0x10);
          if (uVar5 < 6) {
            piVar4 = (int *)((int)local_20 + uVar5 * 8);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar4 = local_20;
          }
          local_1c = local_1c + ((*(int *)((int)piVar4 + 4) + -1) / 2) * 0x28 + 0x32;
          local_18 = uVar5;
        }
      }
    }
    else if (((local_18 != 2) || (piVar9[0x1a] == 0)) ||
            ((*(int *)&local_14[4].field_0x4 == 0 ||
             (*(int *)(*(int *)&local_14[4].field_0x4 + 0x5c) < 1)))) goto LAB_00512d45;
    local_18 = local_18 + 1;
  } while ((int)local_18 < 6);
  if (*piVar9 == 0) {
    ExceptionList = local_10;
    return;
  }
  piVar9 = *(int **)(*piVar9 + 0xd8);
  if (piVar9 != (int *)0x0) {
    *piVar9 = *piVar9 + 1;
  }
  local_8 = 0;
  local_20 = piVar9;
  FUN_004ef860(&DAT_00725a00);
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar4 = (int *)FUN_004ef240();
  if (local_2c == *piVar4) {
    if (local_30 != 0) goto LAB_00512f5d;
  }
  else {
    local_30 = 0;
    local_2c = *piVar4;
  }
  local_30 = FUN_004ef660(local_34 + 3);
LAB_00512f5d:
  iVar7 = -(*(int *)(local_30 + 0x200) / 2);
  local_1c = -0x1000000;
  local_28 = 0x11;
  local_24 = iVar7 + 0x7e;
  FUN_004fdff0(&local_28,piVar9 + 3,&local_1c,&local_34,1,local_24);
  local_24 = iVar7 + 0x7c;
  local_1c = -0x373738;
  local_28 = 0xf;
  FUN_004fdff0(&local_28,piVar9 + 3,&local_1c,&local_34,1,extraout_ECX);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  local_8 = 3;
  if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

