
/* public: void __thiscall ScreenResolutionManager::FillResolutions(int) */

void __thiscall ScreenResolutionManager::FillResolutions(ScreenResolutionManager *this,int param_1)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 extraout_ECX;
  undefined4 uVar5;
  int iVar6;
  undefined4 in_EDX;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  ScreenResolutionManager *pSVar10;
  uint uVar11;
  int local_e0;
  int iStack_dc;
  int iStack_d8;
  int iStack_d4;
  undefined8 local_d0;
  uint local_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  undefined8 local_b8;
  uint local_ac [4];
  undefined4 local_9c;
  uint local_98;
  uint local_94;
  undefined4 local_84;
  uint local_80;
  ScreenResolutionManager *local_7c;
  int *local_78;
  void *local_74;
  uint local_70;
  int local_6c [5];
  uint local_58;
  undefined1 local_50 [16];
  char local_40 [8];
  undefined1 local_38 [16];
  char local_28 [4];
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
                    /* 0x12080  123  ?FillResolutions@ScreenResolutionManager@@QAEXH@Z */
  puStack_20 = &stack0xfffffffc;
  local_14._0_1_ = 0xff;
  local_14._1_3_ = 0xffffff;
  puStack_18 = &LAB_10042580;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_7c = this;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  local_78 = DAT_10050c64;
  if (DAT_10050c64 == (int *)0x0) {
    local_74 = (void *)FUN_1003ff62(0xcbc);
    local_14 = 0;
    memset(local_74,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_14._0_1_ = 0xff;
    local_14._1_3_ = 0xffffff;
  }
  local_78 = DAT_10050c64;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(*DAT_10050c64 + 0x8c);
  iVar6 = *(int *)this;
  FUN_100080a0(this,*(undefined4 *)(iVar6 + 4));
  *(int *)(iVar6 + 4) = iVar6;
  uVar11 = 0;
  *(int *)iVar6 = iVar6;
  *(int *)(iVar6 + 8) = iVar6;
  *(undefined4 *)(local_7c + 4) = 0;
  pSVar10 = local_7c;
  if (0 < *(int *)(local_7c + 0x10)) {
    local_74 = (void *)0x0;
    do {
      if (((int)local_74 < 0) || (*(uint *)(*local_78 + 0x8c) <= uVar11)) {
        FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_38,(ThrowInfo *)&DAT_1004a24c);
      }
      iVar6 = *(int *)(*local_78 + 0x90);
      pcVar9 = local_28 + 1;
      puVar4 = (uint *)(iVar6 + (int)local_74);
      local_c8 = *puVar4;
      uStack_c4 = puVar4[1];
      uStack_c0 = puVar4[2];
      uStack_bc = puVar4[3];
      local_b8 = *(undefined8 *)(iVar6 + 0x10 + (int)local_74);
      uVar7 = uStack_c4;
      do {
        pcVar9 = pcVar9 + -1;
        local_70 = uVar7 / 10;
        *pcVar9 = (char)uVar7 + (char)local_70 * -10 + '0';
        uVar7 = local_70;
      } while (local_70 != 0);
      local_9c = 0;
      local_98 = 0xf;
      local_ac[0] = local_ac[0] & 0xffffff00;
      if (pcVar9 != local_28 + 1) {
        FUN_10003a00(pcVar9,(int)(local_28 + 1) - (int)pcVar9);
      }
      local_14 = 1;
      pcVar9 = local_40 + 1;
      uVar7 = local_c8;
      do {
        pcVar9 = pcVar9 + -1;
        local_70 = uVar7 / 10;
        *pcVar9 = (char)uVar7 + (char)local_70 * -10 + '0';
        uVar7 = local_70;
      } while (local_70 != 0);
      local_84 = 0;
      local_80 = 0xf;
      local_94 = local_94 & 0xffffff00;
      uVar5 = 0;
      if (pcVar9 != local_40 + 1) {
        FUN_10003a00(pcVar9,(int)(local_40 + 1) - (int)pcVar9);
        uVar5 = extraout_ECX;
      }
      local_14._0_1_ = 2;
      piVar3 = (int *)FUN_100138e0(uVar5,1);
      local_e0 = *piVar3;
      iStack_dc = piVar3[1];
      iStack_d8 = piVar3[2];
      iStack_d4 = piVar3[3];
      local_d0 = *(undefined8 *)(piVar3 + 4);
      piVar3[4] = 0;
      piVar3[5] = 0xf;
      *(undefined1 *)piVar3 = 0;
      local_14._0_1_ = 3;
      FUN_10013720(local_74,&local_e0,local_ac);
      local_14._0_1_ = 5;
      uVar2 = (undefined1)local_14;
      local_14._0_1_ = 5;
      if (0xf < local_d0._4_4_) {
        uVar7 = local_d0._4_4_ + 1;
        iVar6 = local_e0;
        if (0xfff < uVar7) {
          iVar6 = *(int *)(local_e0 + -4);
          uVar7 = local_d0._4_4_ + 0x24;
          if (0x1f < (local_e0 - iVar6) - 4U) goto LAB_1001245e;
        }
        FUN_100402ac(iVar6,uVar7);
      }
      local_14._0_1_ = 6;
      if (0xf < local_80) {
        uVar8 = local_80 + 1;
        uVar7 = local_94;
        if (0xfff < uVar8) {
          uVar7 = *(uint *)(local_94 - 4);
          uVar8 = local_80 + 0x24;
          uVar2 = (undefined1)local_14;
          if (0x1f < (local_94 - uVar7) - 4) goto LAB_1001245e;
        }
        FUN_100402ac(uVar7,uVar8);
      }
      local_84 = 0;
      local_80 = 0xf;
      local_94 = local_94 & 0xffffff00;
      local_14._0_1_ = 7;
      if (0xf < local_98) {
        uVar8 = local_98 + 1;
        uVar7 = local_ac[0];
        if (0xfff < uVar8) {
          uVar7 = *(uint *)(local_ac[0] - 4);
          uVar8 = local_98 + 0x24;
          uVar2 = (undefined1)local_14;
          if (0x1f < (local_ac[0] - uVar7) - 4) goto LAB_1001245e;
        }
        FUN_100402ac(uVar7,uVar8);
      }
      pSVar10 = local_7c;
      puVar4 = (uint *)FUN_10013340(local_6c);
      local_14._0_1_ = 0xff;
      local_14._1_3_ = 0xffffff;
      *puVar4 = uVar11;
      if (0xf < local_58) {
        uVar7 = local_58 + 1;
        iVar6 = local_6c[0];
        if (0xfff < uVar7) {
          iVar6 = *(int *)(local_6c[0] + -4);
          uVar7 = local_58 + 0x24;
          uVar2 = (undefined1)local_14;
          if (0x1f < (local_6c[0] - iVar6) - 4U) {
LAB_1001245e:
            local_14._0_1_ = uVar2;
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(iVar6,uVar7);
      }
      uVar11 = uVar11 + 1;
      local_74 = (void *)((int)local_74 + 0x1c);
    } while ((int)uVar11 < *(int *)(pSVar10 + 0x10));
  }
  piVar3 = local_78;
  uVar11 = FUN_100078b0(*(undefined4 *)(pSVar10 + 0x14),*(undefined4 *)(pSVar10 + 0x18),param_1);
  *(uint *)(pSVar10 + 0xc) = uVar11;
  if ((-1 < (int)uVar11) && (uVar11 < *(uint *)(*piVar3 + 0x8c))) {
    iVar6 = *(int *)(*piVar3 + 0x90);
    puVar1 = (undefined4 *)(iVar6 + uVar11 * 0x1c);
    uVar5 = puVar1[1];
    local_b8 = *(undefined8 *)(iVar6 + 0x10 + uVar11 * 0x1c);
    *(undefined4 *)(pSVar10 + 0x14) = *puVar1;
    *(undefined4 *)(pSVar10 + 0x18) = uVar5;
    *(uint *)(pSVar10 + 8) = uVar11;
    ExceptionList = local_1c;
    __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
    return;
  }
  FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_50,(ThrowInfo *)&DAT_1004a24c);
}

