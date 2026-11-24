
void FUN_1000be50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 in_EDX;
  int *piVar8;
  undefined1 local_134 [8];
  undefined1 local_12c [8];
  int local_124;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  void *local_e8;
  int *local_e4;
  void *local_e0;
  void *local_dc;
  int local_d8;
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  undefined4 *local_84;
  undefined4 local_80;
  undefined4 *local_7c;
  undefined4 local_78;
  int *local_74;
  int local_70;
  int local_6c;
  undefined4 *local_68;
  int *local_64;
  int *local_60;
  int local_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_10042178;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  if (DAT_10050c64 == (int *)0x0) {
    local_60 = (int *)FUN_1003ff62(0xcbc);
    local_14 = 0;
    memset(local_60,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_14 = 0xffffffff;
  }
  local_74 = DAT_10050c64;
  local_6c = 0;
  local_70 = 100;
  piVar8 = DAT_10050c64 + 0x236;
  piVar7 = DAT_10050c64;
  do {
    if (param_1 == 0x102) {
      if (DAT_100500b3 != '\0') {
        if (DAT_10050c64 == (int *)0x0) {
          local_dc = (void *)FUN_1003ff62(0xcbc);
          local_14 = 1;
          memset(local_dc,0,0xcbc);
          DAT_10050c64 = (int *)FUN_1000e160();
          local_14 = 0xffffffff;
        }
        (**(code **)(**(int **)(*DAT_10050c64 + 4) + 0x5c))
                  (*(int **)(*DAT_10050c64 + 4),&DAT_10050128,&DAT_1416e958);
        DAT_100500b3 = '\0';
      }
      FUN_1000c730(&local_90,&param_1);
      if ((*(char *)(local_88 + 0xd) != '\0') ||
         (iVar6 = local_88, param_1 < *(int *)(local_88 + 0x10))) {
        if (local_68[1] == 0xaaaaaaa) goto LAB_1000c473;
        uVar1 = *local_68;
        local_7c = local_68;
        local_14 = 2;
        local_78 = 0;
        puVar5 = (undefined4 *)FUN_1003ff62(0x18);
        local_14 = 0xffffffff;
        local_78 = 0;
        puVar5[4] = param_1;
        puVar5[5] = 0;
        *puVar5 = uVar1;
        puVar5[1] = uVar1;
        puVar5[2] = uVar1;
        *(undefined2 *)(puVar5 + 3) = 0;
        iVar6 = FUN_10003d60(local_90,local_8c,puVar5);
      }
      local_64 = *(int **)(iVar6 + 0x14);
      local_28 = DAT_1416e958;
      if (DAT_10050c64 == (int *)0x0) {
        local_e0 = (void *)FUN_1003ff62(0xcbc);
        local_14 = 3;
        memset(local_e0,0,0xcbc);
        DAT_10050c64 = (int *)FUN_1000e160();
        local_14 = 0xffffffff;
      }
      piVar7 = *(int **)(*DAT_10050c64 + 8);
      *(int *)((int)local_64 + local_70) = local_28;
      (**(code **)(*piVar7 + 0x28))(piVar7,local_6c,1,(int *)((int)local_64 + local_70));
      piVar7 = local_74;
    }
    if (*(int *)((int)piVar7 + local_70 + 0xc20) != 0) {
      iStack_d4 = piVar8[-5];
      iVar6 = *piVar8;
      local_110 = 0;
      uStack_10c = 0x10;
      uStack_108 = 1;
      uStack_f4 = 0;
      local_f0 = 0x7f7fffff;
      iStack_d0 = piVar8[-4];
      iStack_cc = piVar8[-6];
      uStack_104 = 0;
      uStack_100 = 0;
      uStack_fc = 0;
      uStack_f8 = 0;
      if (iVar6 == 1) {
        if (piVar8[-2] == 1) {
          *piVar8 = 2;
          iVar6 = 2;
        }
        else if (piVar8[-2] == 2) {
          *piVar8 = 3;
          iVar6 = 3;
        }
        else {
          *piVar8 = 1;
          iVar6 = 1;
        }
      }
      iVar2 = piVar8[-2];
      if (((iVar2 == 5) || (iVar3 = piVar8[-1], iVar3 == 3)) || (iVar6 == 1)) {
LAB_1000c22b:
        local_d8 = 0x55;
      }
      else if (iVar2 == 1) {
        if (iVar3 == 1) {
          if (iVar6 == 2) {
            local_d8 = 0;
          }
          else {
            local_d8 = 0x55;
            if (iVar6 == 3) {
              local_d8 = 1;
            }
          }
        }
        else {
          if (iVar3 != 2) goto LAB_1000c22b;
          if (iVar6 == 2) {
            local_d8 = 0x10;
          }
          else {
            local_d8 = 0x55;
            if (iVar6 == 3) {
              local_d8 = 0x11;
            }
          }
        }
      }
      else {
        if (iVar2 != 2) goto LAB_1000c22b;
        if (iVar3 == 1) {
          if (iVar6 == 2) {
            local_d8 = 4;
          }
          else {
            local_d8 = 0x55;
            if (iVar6 == 3) {
              local_d8 = 5;
            }
          }
        }
        else {
          if (iVar3 != 2) goto LAB_1000c22b;
          if (iVar6 == 2) {
            local_d8 = 0x14;
          }
          else {
            local_d8 = 0x55;
            if (iVar6 == 3) {
              local_d8 = 0x15;
            }
          }
        }
      }
      local_2c = 0x7f7fffff;
      local_4c = 0;
      uStack_48 = 0x10;
      uStack_44 = 1;
      uStack_40 = 0;
      local_5c = local_d8;
      local_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      iStack_58 = iStack_d4;
      iStack_54 = iStack_d0;
      iStack_50 = iStack_cc;
      if (DAT_10050c6c == (int *)0x0) {
        piVar7 = (int *)FUN_1003ff62(8);
        local_14 = 4;
        piVar7[0] = 0;
        piVar7[1] = 0;
        *piVar7 = 0;
        piVar7[1] = 0;
        local_e4 = piVar7;
        iVar6 = FUN_1003ff62(0x18);
        local_14 = 0xffffffff;
        DAT_10050c6c = piVar7;
        *(int *)iVar6 = iVar6;
        *(int *)(iVar6 + 4) = iVar6;
        *(int *)(iVar6 + 8) = iVar6;
        *(undefined2 *)(iVar6 + 0xc) = 0x101;
        *piVar7 = iVar6;
      }
      puVar5 = local_68;
      local_64 = DAT_10050c6c;
      iVar6 = iStack_54 + (iStack_58 + local_5c * 10) * 10;
      piVar7 = local_74;
      if (iVar6 != *(int *)((int)local_68 + local_70 + -0x5c)) {
        *(int *)((int)local_68 + local_70 + -0x5c) = iVar6;
        local_28 = iVar6;
        FUN_1000c730(local_12c,&local_28);
        if (((*(char *)(local_124 + 0xd) == '\0') && (*(int *)(local_124 + 0x10) <= local_28)) &&
           (local_124 != *local_64)) {
          local_64 = *(int **)(local_124 + 0x14);
        }
        else {
          if (DAT_10050c64 == (int *)0x0) {
            local_e8 = (void *)FUN_1003ff62(0xcbc);
            local_14 = 5;
            memset(local_e8,0,0xcbc);
            DAT_10050c64 = (int *)FUN_1000e160();
            local_14 = 0xffffffff;
            puVar5 = local_68;
          }
          (**(code **)(**(int **)(*DAT_10050c64 + 4) + 0x5c))
                    (*(int **)(*DAT_10050c64 + 4),&local_5c,&local_60);
          piVar7 = (int *)FUN_10011470(local_134,&local_28);
          *(int **)(*piVar7 + 0x14) = local_60;
          local_64 = local_60;
        }
        FUN_1000c730(&local_9c,&param_1);
        if ((*(char *)(local_94 + 0xd) != '\0') || (param_1 < *(int *)(local_94 + 0x10))) {
          if (puVar5[1] == 0xaaaaaaa) {
LAB_1000c473:
            FUN_10002ad0();
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          uVar1 = *puVar5;
          local_84 = local_68;
          local_14 = 6;
          local_80 = 0;
          puVar5 = (undefined4 *)FUN_1003ff62(0x18);
          local_14 = 0xffffffff;
          local_80 = 0;
          puVar5[4] = param_1;
          puVar5[5] = 0;
          *puVar5 = uVar1;
          puVar5[1] = uVar1;
          puVar5[2] = uVar1;
          *(undefined2 *)(puVar5 + 3) = 0;
          FUN_10003d60(local_9c,local_98,puVar5);
        }
        FUN_1000b520(local_64,local_6c);
        piVar7 = local_74;
      }
    }
    local_70 = local_70 + 4;
    local_6c = local_6c + 1;
    piVar8 = piVar8 + 0x18;
    if (0x83 < local_70) {
      ExceptionList = local_1c;
      __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
      return;
    }
  } while( true );
}

