
void __thiscall FUN_00513f00(ViWinLayout *this)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int **ppiVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  ViWinLayout *pVVar11;
  undefined4 *puVar12;
  double *pdVar13;
  int *in_stack_00000004;
  undefined1 *puVar14;
  undefined4 uVar15;
  int local_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int *local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int *local_54;
  int local_50;
  undefined4 *local_4c;
  int local_48;
  uint local_44;
  int *local_40;
  undefined1 local_3c;
  undefined2 local_3b;
  undefined1 local_39;
  undefined1 local_38;
  undefined2 local_37;
  undefined1 local_35;
  int *local_34;
  undefined1 local_30;
  undefined2 local_2f;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined2 local_2b;
  undefined1 local_29;
  int local_28;
  ViWinLayout *local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00701a8d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  local_24 = this;
  FUN_00514f90(this);
  local_28 = 0xd2000000;
  local_44 = *in_stack_00000004;
  local_50 = -0x2e000000;
  if (*(int *)(local_44 + 8) != 0) {
    FUN_004ff430(local_44 + 0xc,&local_50);
    local_44 = *in_stack_00000004;
  }
  local_40 = (int *)&this->field_0x44;
  local_48 = this->i_18 - this->i_10;
  iVar8 = 0;
  local_4c = (undefined4 *)(this->i_14 - this->i_0c);
  local_50 = *local_40;
  if (local_50 < (int)local_4c) {
    iVar8 = 0;
    do {
      FUN_004ff900(local_40,in_stack_00000004[2] + iVar8,in_stack_00000004[3] + 5,*local_40,
                   local_40[1],0,0,8);
      iVar8 = iVar8 + local_50;
    } while (local_50 + iVar8 < (int)local_4c);
    local_44 = *in_stack_00000004;
    this = local_24;
    local_50 = iVar8;
  }
  FUN_004ff900(&this->i_60,in_stack_00000004[2] + iVar8,in_stack_00000004[3] + 5,this->i_60,
               this->i_64,0,0,8);
  local_50 = this->i_80;
  local_44 = local_50 * 2;
  local_4c = (undefined4 *)0x0;
  puVar12 = local_4c;
  if ((int)local_44 < local_48) {
    local_4c = (undefined4 *)&this->field_0x7c;
    puVar12 = (undefined4 *)0x0;
    do {
      FUN_004ff900(local_4c,in_stack_00000004[2] + 5,in_stack_00000004[3] + (int)puVar12,*local_4c,
                   local_4c[1],0,0,8);
      puVar12 = (undefined4 *)((int)puVar12 + local_50);
      this = local_24;
    } while ((int)(local_44 + (int)puVar12) < local_48);
  }
  local_4c = puVar12;
  FUN_004ff900(&this->i_98,in_stack_00000004[2] + 5,in_stack_00000004[3] + (int)local_4c,this->i_98,
               this->i_9c,0,0,8);
  local_4c = (undefined4 *)this->i_10;
  local_48 = this->i_0c;
  for (iVar8 = this->i_34; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x34)) {
    local_48 = local_48 + *(int *)(iVar8 + 0xc);
    local_4c = (undefined4 *)((int)local_4c + *(int *)(iVar8 + 0x10));
  }
  local_50 = this->i_134;
  local_58 = FUN_00501450();
  local_58 = local_58 + 0x81ac;
  iStack_80 = this->i_1d0 + (int)local_4c;
  local_40 = (int *)*in_stack_00000004;
  iVar9 = this->i_1cc + local_48;
  iVar8 = local_40[3];
  local_4c = (undefined4 *)(this->i_1c8 + (int)local_4c);
  local_8c = this->i_1c4 + local_48;
  iVar2 = local_40[5];
  iVar3 = local_40[4];
  if (local_8c <= iVar8) {
    local_8c = iVar8;
  }
  iVar4 = local_40[6];
  iStack_88 = (int)local_4c;
  if ((int)local_4c <= iVar3) {
    iStack_88 = iVar3;
  }
  iStack_84 = iVar9;
  if (iVar2 <= iVar9) {
    iStack_84 = iVar2;
  }
  if (iVar4 <= iStack_80) {
    iStack_80 = iVar4;
  }
  local_40[3] = local_8c;
  local_40[4] = iStack_88;
  local_40[5] = iStack_84;
  local_40[6] = iStack_80;
  local_44 = 0;
  if (0 < local_50) {
    local_28 = 0;
    pVVar11 = local_24;
    local_48 = iVar9;
    do {
      if ((uint)pVVar11->i_134 <= local_44) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      pdVar13 = (double *)(*(int *)&pVVar11->field_0x130 + local_28);
      if (*(int *)((int)pdVar13 + 0x34) == 0) {
        iVar9 = *(int *)(pdVar13 + 6);
        if (*(int *)(iVar9 + 8) == -1) {
          pcVar10 = (char *)(iVar9 + 0xc);
          local_4c = (undefined4 *)(iVar9 + 0xd);
          do {
            cVar1 = *pcVar10;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          *(int *)(iVar9 + 8) = (int)pcVar10 - (int)local_4c;
          iVar9 = *(int *)(pdVar13 + 6);
        }
        if (*(int *)(iVar9 + 8) < 1) goto LAB_005141c1;
        uVar5 = *(uint *)((int)pdVar13 + 0x34);
LAB_005141cf:
        if (uVar5 == 0) {
          iVar9 = *(int *)(pdVar13 + 6);
          if (*(int *)(iVar9 + 8) == -1) {
            pcVar10 = (char *)(iVar9 + 0xc);
            local_4c = (undefined4 *)(iVar9 + 0xd);
            do {
              cVar1 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar1 != '\0');
            *(int *)(iVar9 + 8) = (int)pcVar10 - (int)local_4c;
            iVar9 = *(int *)(pdVar13 + 6);
          }
          if (*(int *)(iVar9 + 8) < 1) goto LAB_00514451;
          iVar9 = *(int *)(pdVar13 + 7);
          if (4 < iVar9) {
            iVar9 = 4;
          }
          if (iVar9 < 0) {
            iVar9 = 0;
          }
          local_48 = iVar9 * 3 + 0x2d;
          piVar6 = (int *)FUN_006ba810(0x19);
          piVar6[1] = 0x14;
          piVar6[2] = -1;
          *(undefined1 *)(piVar6 + 3) = 0;
          *piVar6 = 1;
          local_14 = 0;
          local_78 = *(int *)(&pVVar11->field_0x4 + local_48 * 4);
          local_7c = *(int **)(&pVVar11->field_0x0 + local_48 * 4);
          iVar9 = 1;
          if (local_7c != (int *)0x0) {
            *local_7c = *local_7c + 1;
            iVar9 = *piVar6;
          }
          *piVar6 = iVar9 + -1;
          local_4c = (undefined4 *)local_78;
          local_34 = local_7c;
          if (iVar9 + -1 == 0) {
            FUN_006ba940();
          }
          local_34[2] = *(int *)(*(int *)(&pVVar11->field_0x0 + local_48 * 4) + 8);
          local_74 = *(int *)(&pVVar11->field_0x8 + local_48 * 4);
          local_14 = 1;
          local_54 = (int *)(*(int *)(pdVar13 + 6) + 0xc);
          local_48 = local_74;
          if (*(int *)((int)pdVar13 + 0x3c) == 0) {
            local_37 = 0xffff;
            local_38 = 0xff;
            local_35 = 0xff;
            piVar6 = (int *)FUN_004ef240();
            if (local_48 == *piVar6) {
              puVar12 = local_4c;
              if (local_4c == (undefined4 *)0x0) goto LAB_005143e0;
            }
            else {
              local_78 = 0;
              local_74 = *piVar6;
LAB_005143e0:
              local_78 = FUN_004ef660(local_34 + 3);
              puVar12 = (undefined4 *)local_78;
            }
            iVar9 = (int)pdVar13[1] + *(int *)((int)puVar12 + 0x200) + pVVar11->i_1c8;
            uVar15 = 1;
            local_70 = (int)*pdVar13 + pVVar11->i_1c4;
            puVar14 = &local_38;
            piVar6 = &local_70;
            local_6c = iVar9;
          }
          else if (local_44 == pVVar11->i_1c0) {
            local_2b = 0xffff;
            local_2c = 0x37;
            local_29 = 0xff;
            piVar6 = (int *)FUN_004ef240();
            if (local_48 == *piVar6) {
              puVar12 = local_4c;
              if (local_4c == (undefined4 *)0x0) goto LAB_005142fb;
            }
            else {
              local_78 = 0;
              local_74 = *piVar6;
LAB_005142fb:
              local_78 = FUN_004ef660(local_34 + 3);
              puVar12 = (undefined4 *)local_78;
            }
            iVar9 = (int)pdVar13[1] + *(int *)((int)puVar12 + 0x200) + pVVar11->i_1c8;
            uVar15 = 3;
            local_60 = (int)*pdVar13 + pVVar11->i_1c4;
            puVar14 = &local_2c;
            piVar6 = &local_60;
            local_5c = iVar9;
          }
          else {
            local_2f = 0xffff;
            local_30 = 0xff;
            local_2d = 0xff;
            piVar6 = (int *)FUN_004ef240();
            if (local_48 == *piVar6) {
              puVar12 = local_4c;
              if (local_4c == (undefined4 *)0x0) goto LAB_0051436f;
            }
            else {
              local_78 = 0;
              local_74 = *piVar6;
LAB_0051436f:
              local_78 = FUN_004ef660(local_34 + 3);
              puVar12 = (undefined4 *)local_78;
            }
            iVar9 = (int)pdVar13[1] + *(int *)((int)puVar12 + 0x200) + pVVar11->i_1c8;
            uVar15 = 3;
            local_68 = (int)*pdVar13 + pVVar11->i_1c4;
            puVar14 = &local_30;
            piVar6 = &local_68;
            local_64 = iVar9;
          }
          FUN_004fdff0(piVar6,local_54,puVar14,&local_7c,uVar15,iVar9);
          local_14 = 2;
          if ((local_7c != (int *)0x0) && (*local_7c = *local_7c + -1, *local_7c == 0)) {
            FUN_006ba940();
          }
        }
        else {
LAB_00514451:
          if (((*(uint *)((int)pdVar13 + 0x34) & 0x8000038) == 0) ||
             ((*(uint *)((int)pdVar13 + 0x34) >> 0x1b & 1) != 0)) goto LAB_00514571;
          piVar6 = *(int **)(pdVar13 + 6);
          if (piVar6 != (int *)0x0) {
            *piVar6 = *piVar6 + 1;
          }
          local_14 = 3;
          local_54 = piVar6;
          local_34 = (int *)FUN_004e6fe0(piVar6 + 3);
          if ((local_34 != (int *)0x0) &&
             (FUN_004ff900(local_34,(int)*pdVar13 + local_24->i_1c4 + in_stack_00000004[2],
                           (int)pdVar13[1] + local_24->i_1c8 + in_stack_00000004[3],*local_34,
                           local_34[1],0,0,3), *(int *)((int)pdVar13 + 0x3c) != 0)) {
            local_8c = (int)*pdVar13 + local_24->i_1c4;
            iStack_84 = *local_34 + local_8c;
            iStack_88 = (int)pdVar13[1] + local_24->i_1c8;
            iStack_80 = local_34[1] + iStack_88;
            if (local_44 == local_24->i_1c0) {
              local_3b = 0xffff;
              ppiVar7 = (int **)&local_3c;
              local_3c = 0;
              local_39 = 0xff;
            }
            else {
              ppiVar7 = &local_40;
              local_40 = (int *)0xffffffff;
            }
            FUN_004fdc40(&local_8c,ppiVar7);
          }
          local_14 = 4;
          pVVar11 = local_24;
          if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
            FUN_006ba940();
            pVVar11 = local_24;
          }
        }
        local_14 = 0xffffffff;
      }
      else {
LAB_005141c1:
        uVar5 = *(uint *)((int)pdVar13 + 0x34);
        if ((uVar5 & 0x8000038) != 0) goto LAB_005141cf;
      }
LAB_00514571:
      local_28 = local_28 + 0x40;
      local_44 = local_44 + 1;
    } while ((int)local_44 < local_50);
  }
  iVar9 = *in_stack_00000004;
  *(int *)(iVar9 + 0xc) = iVar8;
  *(int *)(iVar9 + 0x10) = iVar3;
  *(int *)(iVar9 + 0x14) = iVar2;
  *(int *)(iVar9 + 0x18) = iVar4;
  ExceptionList = local_1c;
  return;
}

