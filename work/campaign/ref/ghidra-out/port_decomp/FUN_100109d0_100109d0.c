
void FUN_100109d0(int param_1,void *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  void *_Dst;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 in_EDX;
  int iVar7;
  undefined1 local_88 [16];
  int *local_78;
  int *local_74;
  void *local_70;
  int local_6c;
  int local_68;
  int *local_64;
  int *local_60;
  undefined4 *local_5c;
  void *local_58 [3];
  void *local_4c;
  undefined8 local_48;
  int local_40;
  int local_3c [7];
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_10042420;
  local_1c = ExceptionList;
  local_3c[6] = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_70 = param_2;
  local_64 = param_3;
  local_78 = param_4;
  local_74 = param_5;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_3c[6]);
  puVar2 = local_5c;
  local_40 = 0;
  iVar6 = local_5c[2];
  iVar3 = iVar6;
  while (iVar3 < param_1) {
    local_40 = local_40 + 1;
    iVar3 = iVar6 << ((byte)local_40 & 0x1f);
  }
  piVar1 = local_5c + 3;
  iVar3 = local_5c[3];
  iVar7 = local_5c[4] - iVar3 >> 2;
  local_6c = (iVar6 << ((byte)local_40 & 0x1f)) * local_5c[1];
  local_60 = piVar1;
  if (iVar7 <= local_40) {
    local_68 = (local_40 - iVar7) + 1;
    do {
      piVar4 = (int *)FUN_1003ff62(0x14);
      local_14 = 0;
      *piVar4 = 0;
      piVar4[1] = 0;
      piVar4[2] = 0;
      piVar4[3] = 0;
      piVar4[4] = 0;
      puVar5 = (undefined4 *)FUN_1003ff62(8);
      local_14 = 0xffffffff;
      puVar5[1] = 0;
      *piVar4 = (int)puVar5;
      *puVar5 = piVar4;
      puVar5 = (undefined4 *)puVar2[4];
      local_60 = piVar4;
      if (puVar5 == (undefined4 *)puVar2[5]) {
        FUN_10007ea0(puVar5,&local_60);
      }
      else {
        *puVar5 = piVar4;
        puVar2[4] = puVar2[4] + 4;
      }
      local_60 = (int *)FUN_100402f0(local_6c);
      piVar4 = (int *)local_5c[7];
      if (piVar4 == (int *)local_5c[8]) {
        FUN_10007ea0(piVar4,&local_60);
      }
      else {
        *piVar4 = (int)local_60;
        local_5c[7] = local_5c[7] + 4;
      }
      local_68 = local_68 + -1;
    } while (local_68 != 0);
    iVar3 = *piVar1;
    local_68 = 0;
  }
  iVar7 = local_40;
  piVar1 = local_78;
  iVar6 = *(int *)(iVar3 + local_40 * 4);
  if (*(int *)(iVar6 + 0x10) == 0) {
    local_40 = 0;
    _Dst = *(void **)(local_5c[6] + iVar7 * 4);
    memcpy(_Dst,local_70,local_5c[1] * param_1);
    local_48 = 0;
    local_3c[1] = 0;
    local_3c[2] = 0;
    local_3c[3] = 0;
    local_3c[0] = local_6c;
    local_3c[4] = 0;
    local_3c[5] = 0;
    local_4c = _Dst;
    (**(code **)*local_5c)(local_3c);
    iVar6 = (**(code **)(*local_64 + 0xc))(local_64,local_3c,&local_4c,&local_40);
    if (iVar6 < 0) {
      FUN_100053a0(iVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_88,(ThrowInfo *)&DAT_1004a24c);
    }
    *local_74 = local_40;
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(iVar6 + 4) +
                             (*(uint *)(iVar6 + 0xc) >> 2 & *(int *)(iVar6 + 8) - 1U) * 4) +
                    (*(uint *)(iVar6 + 0xc) & 3) * 4);
    piVar4 = (int *)(iVar6 + 0x10);
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      *(undefined4 *)(iVar6 + 0xc) = 0;
    }
    else {
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
    }
    (**(code **)(*local_78 + 0x38))(local_78,iVar3,0,4,0,local_58);
    memcpy(local_58[0],local_70,local_5c[1] * param_1);
    (**(code **)(*piVar1 + 0x3c))(piVar1,iVar3,0);
    *local_74 = iVar3;
  }
  ExceptionList = local_1c;
  __security_check_cookie(local_3c[6] ^ (uint)&stack0xfffffff0);
  return;
}

