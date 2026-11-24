
void __thiscall FUN_005343b0(ViWinSimpleFinder *this)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int in_stack_00000004;
  int local_b0;
  int local_ac;
  undefined4 local_a8;
  int local_a4;
  undefined4 local_a0;
  int local_9c;
  int local_98;
  int local_94;
  undefined4 local_90;
  int local_8c;
  undefined4 local_88;
  int local_84;
  int *local_80 [3];
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int *local_50;
  int *local_4c;
  undefined1 local_48;
  undefined2 local_47;
  undefined1 local_45;
  undefined4 local_44;
  undefined1 local_40;
  undefined2 local_3f;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined2 local_2f;
  undefined1 local_2d;
  int local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00702f35;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00504fd0(in_stack_00000004);
  iVar6 = this->i_78;
  local_54 = iVar6;
  FUN_004ef7b0(in_stack_00000004 + 0x10);
  local_8 = 0;
  local_28 = 0;
  if (0 < iVar6) {
    local_6c = 10;
    local_14 = 0;
    local_20 = 0x12;
    do {
      iVar6 = local_14;
      uVar3 = local_28;
      uVar7 = this->i_78;
      local_1c = 1;
      if (uVar7 <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar7 = this->i_78;
      }
      local_24 = *(uint *)(this->i_74 + 0x18 + iVar6);
      local_18 = local_24;
      if (uVar7 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*(char *)(this->i_74 + 0x24 + iVar6) != '\0') {
        local_2f = 0x7878;
        local_30 = 0x78;
        local_2d = 0xff;
        local_8c = local_20 + -10;
        local_90 = 10;
        local_84 = local_20 + 6;
        local_88 = 0xa0;
        FUN_004fdf00(&local_90,&local_30);
        local_34 = 0xff000000;
        local_18 = 0xff000000;
        local_24 = 0xff000000;
      }
      if (uVar3 == this->i_80) {
LAB_0053451a:
        local_38 = 0xff5aff5a;
        local_1c = 3;
        local_18 = 0xff5aff5a;
        local_24 = 0xff5aff5a;
      }
      else {
        if ((uint)this->i_78 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (((*(int *)(this->i_74 + 0xc + iVar6) == *(int *)(DAT_00772400 + 0xa0cc)) &&
            (this->i_80 == -1)) && (*(int *)(DAT_00772400 + 0xa0cc) != -1)) goto LAB_0053451a;
      }
      if ((uint)this->i_78 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = *(int **)(this->i_74 + local_14);
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      local_50 = piVar2;
      local_4c = piVar2;
      if ((uint)this->i_78 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = this->i_74;
      if (*(int *)(iVar6 + 0x20 + local_14) != -1) {
        if ((uint)this->i_78 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = this->i_74;
        }
        local_2c = (*(int *)(iVar6 + 0x20 + local_14) * 0x32) / 100;
        if ((uint)this->i_78 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar6 = local_20;
        local_a0 = 0x73;
        uVar7 = (uint)*(byte *)(this->i_74 + 0x1f + local_14) * 0x7f + 0x807f >> 8;
        local_3a = (undefined1)((uint)*(byte *)(this->i_74 + 0x1e + local_14) * 0x7f >> 8);
        local_3b = (undefined1)((uint)*(byte *)(this->i_74 + 0x1d + local_14) * 0x7f >> 8);
        local_3c = (undefined1)((uint)*(byte *)(this->i_74 + 0x1c + local_14) * 0x7f >> 8);
        if (0xff < uVar7) {
          uVar7 = 0xff;
        }
        local_39 = (undefined1)uVar7;
        iVar8 = local_2c + 0x73;
        local_9c = local_20;
        local_94 = local_20 + 5;
        local_98 = iVar8;
        FUN_004fdf00(&local_a0,&local_3c);
        local_ac = iVar6 + 2;
        local_a4 = iVar6 + 3;
        local_3f = 0x8080;
        local_40 = 0x80;
        local_3d = 0xff;
        local_a8 = 0xa5;
        local_b0 = iVar8;
        FUN_004fdf00(&local_b0,&local_40);
        uVar3 = local_28;
        piVar2 = local_4c;
      }
      uVar7 = this->i_78;
      if (uVar7 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar7 = this->i_78;
      }
      iVar6 = this->i_74;
      if (*(int *)(iVar6 + 0xc + local_14) != -1) {
        if (uVar7 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = this->i_74;
        }
        if (*(int *)(iVar6 + 0xc + local_14) == *(int *)(DAT_00772400 + 0xa0d4)) {
          uVar7 = local_18 >> 8;
          uVar3 = local_18 & 0xff;
          local_18 = piVar2[2];
          local_44._0_2_ =
               CONCAT11((char)(((uVar7 & 0xff) + 0xff) * 0x80 >> 8),(char)((uVar3 << 7) >> 8));
          local_44 = CONCAT13((char)(((local_24 >> 0x18) + 0xb9) * 0x80 >> 8),
                              CONCAT12((char)(((local_24 >> 0x10 & 0xff) + 0xff) * 0x80 >> 8),
                                       (undefined2)local_44));
          local_24 = local_44;
          if (local_18 == 0xffffffff) {
            piVar4 = piVar2 + 3;
            do {
              iVar6 = *piVar4;
              piVar4 = (int *)((int)piVar4 + 1);
            } while ((char)iVar6 != '\0');
            local_18 = (int)piVar4 - ((int)piVar2 + 0xd);
            piVar2[2] = local_18;
          }
          iVar6 = local_18 + 2;
          piVar2 = (int *)FUN_006b8df0(piVar2,local_18 + 3);
          *(undefined2 *)(local_18 + 0xc + (int)piVar2) = 0x2a20;
          *(undefined1 *)(local_18 + 0xe + (int)piVar2) = 0;
          piVar2[2] = iVar6;
          uVar3 = local_28;
          local_50 = piVar2;
          local_4c = piVar2;
        }
        if ((int)uVar3 < local_54 + -1) {
          local_60 = local_20 + 6;
          local_47 = 0x3232;
          local_48 = 0x32;
          local_45 = 0xff;
          local_5c = 0xa0;
          local_64 = 5;
          local_58 = local_60;
          FUN_004fdbd0(&local_64,&local_5c,&local_48);
        }
      }
      local_68 = local_20 + 2;
      FUN_004fdff0(&local_6c,piVar2 + 3,&local_24,local_80,local_1c,local_68);
      if ((uint)this->i_78 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_18 = this->i_74 + local_14;
      iVar6 = *(int *)(local_18 + 8);
      if (*(int *)(iVar6 + 8) == -1) {
        pcVar5 = (char *)(iVar6 + 0xc);
        local_2c = iVar6 + 0xd;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        *(int *)(iVar6 + 8) = (int)pcVar5 - local_2c;
        iVar6 = *(int *)(local_18 + 8);
      }
      if (*(int *)(iVar6 + 8) != 0) {
        uVar7 = this->i_78;
        if (uVar7 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar7 = this->i_78;
        }
        iVar6 = this->i_74;
        local_2c = iVar6 + local_14;
        if (uVar7 <= uVar3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar6 = this->i_74;
        }
        iVar6 = *(int *)(iVar6 + 8 + local_14) + 0xc;
        local_70 = local_20 + 2;
        local_74 = 0x78;
        FUN_004fdff0(&local_74,iVar6,local_2c + 0x1c,local_80,local_1c,iVar6);
      }
      if ((uint)this->i_78 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar7 = *(uint *)(this->i_74 + 0x14 + local_14);
      if (uVar7 != 0xffffffff) {
        local_1c = ((int)uVar7 >> 2) << 4;
        FUN_004ff900(&this->field_0xa0,*(int *)(in_stack_00000004 + 8) + 0x5a,
                     *(int *)(in_stack_00000004 + 0xc) + local_20 + -10,0x10,0x10,(uVar7 & 3) << 4,
                     local_1c,3);
      }
      local_1c = 0x6b;
      local_18 = 0;
      local_24 = 1;
      uVar7 = local_28;
      do {
        uVar3 = local_24;
        if ((uint)this->i_78 <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((*(uint *)(this->i_74 + 0x10 + local_14) & uVar3) != 0) {
          local_50 = (int *)(local_18 & 3);
          FUN_004ff900(&this->field_0x84,*(int *)(in_stack_00000004 + 8) + local_1c,
                       *(int *)(in_stack_00000004 + 0xc) + local_20 + -10,0x10,0x10,
                       (int)local_50 << 4,(local_18 >> 2) << 4,3);
          local_1c = local_1c + 0x14;
          uVar3 = local_24;
          uVar7 = local_28;
        }
        local_18 = local_18 + 1;
        local_24 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      } while ((int)local_18 < 0x20);
      local_20 = local_20 + 0x12;
      local_8 = CONCAT31(local_8._1_3_,2);
      if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c == 0)) {
        FUN_006ba940();
      }
      local_28 = local_28 + 1;
      local_14 = local_14 + 0x28;
    } while ((int)local_28 < local_54);
  }
  local_8 = 3;
  if ((local_80[0] != (int *)0x0) && (*local_80[0] = *local_80[0] + -1, *local_80[0] == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

