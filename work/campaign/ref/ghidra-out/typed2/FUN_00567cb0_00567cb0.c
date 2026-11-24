
void FUN_00567cb0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  undefined4 extraout_ECX;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  code *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00705c2d;
  local_1c = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_4c = *(uint *)(in_ECX + 0x11c);
  iVar6 = *(int *)(in_ECX + 0xe0);
  local_44 = in_ECX;
  puVar3 = &stack0xfffffffc;
  if (iVar6 == 4) {
    FUN_00567410(param_1);
    iVar6 = *(int *)(in_ECX + 0xe0);
    puVar3 = puStack_20;
  }
  puStack_20 = puVar3;
  local_48 = RaiseException_exref;
  if (iVar6 == 3) {
    iStack_5c = (int)*(float *)(in_ECX + 0xf4);
    *(undefined4 *)(in_ECX + 0xe0) = 0;
    local_70 = 0;
    local_6c = 0;
    local_54 = iStack_5c + -0x20;
    local_58 = (int)*(float *)(in_ECX + 0xf0) + -0x10;
    iStack_60 = (int)*(float *)(in_ECX + 0xf0) + 0x10;
    local_14 = 0;
    local_40 = iStack_60;
    local_34 = iStack_5c;
    local_30 = local_58;
    cVar4 = FUN_00566a60(&local_58,&iStack_60,&local_70,8);
    if (cVar4 == '\0') {
      thunk_FUN_0060fc30(0);
      ExceptionList = local_1c;
      return;
    }
    FUN_005f8080();
    FUN_005fa510(local_30 + -4,local_34 + -0x24,0xc,0xc);
    piVar10 = (int *)(DAT_00772400 + 0xa328);
    if (*(uint *)(in_ECX + 0x11c) < 8) {
      piVar10 = piVar10 + *(uint *)(in_ECX + 0x11c) * 4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar6 = local_44;
    local_68 = *piVar10;
    if (local_30 < *piVar10) {
      local_68 = local_30;
    }
    iStack_64 = piVar10[1];
    if (local_34 + -0x20 < piVar10[1]) {
      iStack_64 = local_34 + -0x20;
    }
    iStack_60 = piVar10[2];
    if (piVar10[2] < local_40) {
      iStack_60 = local_40;
    }
    local_3c = piVar10[3];
    if (piVar10[3] < local_34) {
      local_3c = local_34;
    }
    if (local_68 < PTR_0077241c->cellX0) {
      local_68 = PTR_0077241c->cellX0;
    }
    if (iStack_64 < PTR_0077241c->cellY0) {
      iStack_64 = PTR_0077241c->cellY0;
    }
    if (PTR_0077241c->cellX1 < iStack_60) {
      iStack_60 = PTR_0077241c->cellX1;
    }
    iStack_5c = local_3c;
    if (PTR_0077241c->cellY1 < local_3c) {
      iStack_5c = PTR_0077241c->cellY1;
    }
    piVar10 = (int *)(DAT_00772400 + 0xa328);
    if (*(uint *)(local_44 + 0x11c) < 8) {
      piVar10 = piVar10 + *(uint *)(local_44 + 0x11c) * 4;
    }
    else {
      (*local_48)(0xc000008c,1,0,0);
    }
    *piVar10 = local_68;
    piVar10[1] = iStack_64;
    piVar10[2] = iStack_60;
    piVar10[3] = iStack_5c;
    iStack_60 = local_30;
    iStack_5c = local_34 + -0x20;
    local_58 = local_40;
    local_54 = local_34;
    FUN_0056de10(&iStack_60,local_34);
    FUN_0056de10(&local_58,extraout_ECX);
    iVar9 = 0x7fffffff;
    local_38 = 0x7fffffff;
    local_24 = 0x7fffffff;
    local_28 = 0;
    local_2c = 0;
    local_3c = iStack_5c;
    iVar7 = local_58;
    iVar8 = iStack_5c;
    if (iStack_5c < local_54) {
      do {
        iVar2 = local_44;
        if (iStack_60 < iVar7) {
          local_50 = (iVar8 - (local_34 + -0x20)) * 0x20 - local_30;
          iVar11 = iStack_60;
          local_3c = iVar8;
          do {
            if (*(uint *)(iVar2 + 0xdc) < 4) {
              iVar6 = iVar2 + *(uint *)(iVar2 + 0xdc) * 0x28;
            }
            else {
              (*local_48)(0xc000008c,1,0,0);
              iVar6 = iVar2;
              iVar8 = local_3c;
            }
            cVar4 = *(char *)(*(int *)(iVar6 + 0x14) + (local_50 + iVar11) * 4);
            iVar6 = local_2c;
            if (cVar4 != '\x04') {
              FUN_005671a0(iVar11,iVar8,cVar4,local_4c);
              iVar6 = iVar11;
              if (local_38 < iVar11) {
                iVar6 = local_38;
              }
              iVar7 = local_3c;
              if (local_24 < local_3c) {
                iVar7 = local_24;
              }
              iVar9 = iVar11;
              if (iVar11 < local_28) {
                iVar9 = local_28;
              }
              iVar8 = local_3c;
              local_38 = iVar6;
              iVar6 = local_3c;
              local_28 = iVar9;
              local_24 = iVar7;
              if (local_3c < local_2c) {
                iVar6 = local_2c;
              }
            }
            local_2c = iVar6;
            iVar11 = iVar11 + 1;
            iVar7 = local_58;
            iVar9 = local_38;
            iVar6 = iVar2;
          } while (iVar11 < local_58);
        }
        local_3c = iVar8 + 1;
        iVar8 = local_3c;
      } while (local_3c < local_54);
    }
    uVar1 = *(undefined4 *)(iVar6 + 0xdc);
    iStack_5c = local_2c;
    iStack_60 = local_28;
    local_68 = iVar9;
    iStack_64 = local_24;
    iVar7 = FUN_0058a820();
    FUN_0058eb30(&local_68);
    FUN_0058fb10(1);
    iVar6 = *(int *)(iVar7 + 0x34);
    uVar12 = 0x40;
    iVar7 = *(int *)(iVar7 + 0x30);
    *(undefined4 *)(iVar7 + -4 + iVar6 * 0x14) = uVar1;
    *(int *)(iVar7 + -0x14 + iVar6 * 0x14) = local_38;
    *(int *)(iVar7 + -0x10 + iVar6 * 0x14) = local_24;
    *(int *)(iVar7 + -0xc + iVar6 * 0x14) = local_28;
    *(int *)(iVar7 + -8 + iVar6 * 0x14) = local_2c;
    iVar9 = local_30 << 3;
    iVar6 = local_34 * 8 + 8;
    iVar8 = (local_34 + -0x20) * 8;
    iVar7 = local_40 * 8 + 8;
    local_68 = iVar9;
    iStack_64 = iVar8;
    iStack_60 = iVar7;
    iStack_5c = iVar6;
    FUN_005a3dd0(local_34,iVar9,iVar8,iVar7,iVar6,0x40);
    FUN_005a3fd0(iVar9,iVar8,iVar7,iVar6,uVar12);
    thunk_FUN_0060fc30(0);
    in_ECX = local_44;
  }
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  piVar10 = (int *)(in_ECX + 0xb4);
  if (local_4c < 8) {
    piVar10 = piVar10 + local_4c;
  }
  else {
    (*local_48)(0xc000008c,1,0,0,uVar5);
  }
  *piVar10 = *piVar10 + 1;
  ExceptionList = local_1c;
  return;
}

