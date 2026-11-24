
void FUN_1000b060(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 ****ppppuVar7;
  undefined4 in_EDX;
  uint uVar8;
  int iVar9;
  undefined1 local_60 [16];
  undefined4 *local_50;
  int *local_4c;
  int *local_48;
  undefined4 ***local_44 [4];
  int local_34;
  uint local_30;
  undefined2 local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041f07;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    local_50 = (undefined4 *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_50,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  local_4c = *(int **)(*DAT_10050c64 + 4);
  FUN_1000b760();
  local_8 = 1;
  if (local_30 < 0x10) {
    iVar9 = (int)local_44 + local_34;
    ppppuVar7 = local_44;
    if (local_30 < 0x10) goto LAB_1000b119;
  }
  else {
    iVar9 = local_34 + (int)local_44[0];
  }
  ppppuVar7 = (undefined4 ****)local_44[0];
LAB_1000b119:
  local_1c = 0;
  local_2c = 0;
  local_18 = 7;
  FUN_1000b8c0(iVar9 - (int)ppppuVar7);
  local_48 = (int *)((uint)local_48 & 0xffffff00);
  FUN_1000ba20(ppppuVar7,iVar9,local_48);
  piVar1 = (int *)(in_ECX + 0x48);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  iVar9 = FUN_1000afd0("vs_4_0",piVar1);
  if (-1 < iVar9) {
    piVar2 = *(int **)(in_ECX + 0x54);
    local_48 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(in_ECX + 0x54) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    iVar9 = *local_4c;
    uVar6 = (**(code **)(*local_48 + 0x10))(local_48,0,in_ECX + 0x54);
    uVar6 = (**(code **)(*local_48 + 0xc))(local_48,uVar6);
    iVar9 = (**(code **)(iVar9 + 0x30))(local_4c,uVar6);
    if (-1 < iVar9) {
      piVar3 = *(int **)(in_ECX + 0x4c);
      piVar2 = (int *)(in_ECX + 0x4c);
      if (piVar3 != (int *)0x0) {
        *piVar2 = 0;
        (**(code **)(*piVar3 + 8))(piVar3);
      }
      iVar9 = FUN_1000afd0("ps_4_0",piVar2);
      if (-1 < iVar9) {
        piVar3 = *(int **)(in_ECX + 0x58);
        local_48 = (int *)*piVar2;
        if (piVar3 != (int *)0x0) {
          *(undefined4 *)(in_ECX + 0x58) = 0;
          (**(code **)(*piVar3 + 8))(piVar3);
        }
        iVar9 = *local_4c;
        uVar6 = (**(code **)(*local_48 + 0x10))(local_48,0,in_ECX + 0x58);
        uVar6 = (**(code **)(*local_48 + 0xc))(local_48,uVar6);
        iVar9 = (**(code **)(iVar9 + 0x3c))(local_4c,uVar6);
        if (-1 < iVar9) {
          piVar2 = *(int **)(in_ECX + 0x60);
          local_50 = (undefined4 *)(in_ECX + 0x60);
          local_48 = (int *)*piVar1;
          if (piVar2 != (int *)0x0) {
            *local_50 = 0;
            (**(code **)(*piVar2 + 8))(piVar2);
          }
          iVar9 = *(int *)(in_ECX + 0x1c);
          iVar4 = *(int *)(in_ECX + 0x18);
          iVar5 = *local_4c;
          uVar6 = (**(code **)(*local_48 + 0x10))(local_48,local_50);
          uVar6 = (**(code **)(*local_48 + 0xc))(local_48,uVar6);
          iVar9 = (**(code **)(iVar5 + 0x2c))
                            (local_4c,iVar4,(iVar9 - iVar4 >> 2) * -0x49249249,uVar6);
          if (-1 < iVar9) {
            FUN_1000b6b0();
            if (0xf < local_30) {
              uVar8 = local_30 + 1;
              ppppuVar7 = (undefined4 ****)local_44[0];
              if (0xfff < uVar8) {
                ppppuVar7 = (undefined4 ****)local_44[0][-1];
                uVar8 = local_30 + 0x24;
                if (0x1f < (uint)((int)local_44[0] + (-4 - (int)ppppuVar7))) {
                    /* WARNING: Subroutine does not return */
                  _invalid_parameter_noinfo_noreturn();
                }
              }
              FUN_100402ac(ppppuVar7,uVar8);
            }
            ExceptionList = local_10;
            __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
      }
    }
  }
  FUN_100053a0(iVar9);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_60,(ThrowInfo *)&DAT_1004a24c);
}

