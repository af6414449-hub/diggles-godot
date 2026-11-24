
void FUN_10035d80(undefined4 *param_1,void *param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined1 auStack_14c [4];
  uint local_148;
  uint local_144;
  void *local_140;
  uint local_13c [2];
  undefined4 *local_134;
  undefined4 local_130 [4];
  int local_120;
  byte local_114;
  byte abStack_113 [263];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)auStack_14c;
  local_134 = param_1;
  local_140 = param_2;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_148 = 0;
  if (param_3 == 0) {
LAB_10035fc2:
    __security_check_cookie(local_c ^ (uint)auStack_14c);
    return;
  }
  uVar5 = param_1[0x9a];
LAB_10035dd0:
  pvVar3 = local_140;
  uVar9 = param_3 - local_148;
  if (uVar5 < uVar9) {
    if (uVar5 != 0) {
      memcpy(local_140,(void *)((param_1[0x9b] - uVar5) + 0x270 + (int)param_1),uVar5);
      iVar4 = param_1[0x9a];
      local_148 = local_148 + iVar4;
      param_1[0x9a] = 0;
      local_140 = (void *)((int)pvVar3 + iVar4);
    }
    local_144 = 0;
    iVar4 = FUN_100359f0(local_130,local_13c,&local_144);
    if (iVar4 != 0) {
      __security_check_cookie(local_c ^ (uint)auStack_14c);
      return;
    }
    do {
      iVar7 = 0;
      local_144 = (uint)local_114;
      iVar10 = 0;
      puVar1 = param_1 + 4;
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + local_13c[0];
      local_13c[1] = 0;
      param_1[5] = param_1[5] + (uint)CARRY4(uVar5,local_13c[0]);
      iVar4 = 0;
      if (1 < local_144) {
        do {
          iVar7 = iVar7 + (uint)abStack_113[iVar4];
          iVar2 = iVar4 + 1;
          iVar4 = iVar4 + 2;
          iVar10 = iVar10 + (uint)abStack_113[iVar2];
        } while (iVar4 < (int)(local_144 - 1));
      }
      if (iVar4 < (int)local_144) {
        uVar5 = (uint)abStack_113[iVar4];
      }
      else {
        uVar5 = 0;
      }
      uVar5 = iVar10 + iVar7 + uVar5;
      if (uVar5 < 0xff1c) {
        if (local_120 == param_1[8]) goto LAB_10035f1d;
        if ((uVar5 != 0) && (iVar4 = FUN_10035ae0(uVar5,0), iVar4 == 0)) goto LAB_10035f04;
      }
      local_144 = 0;
      iVar4 = FUN_100359f0(local_130,local_13c,&local_144);
      if (iVar4 != 0) {
LAB_10035f04:
        __security_check_cookie(local_c ^ (uint)auStack_14c);
        return;
      }
    } while( true );
  }
  memcpy(local_140,(void *)((param_1[0x9b] - uVar5) + 0x270 + (int)param_1),uVar9);
  param_1[0x9a] = param_1[0x9a] - uVar9;
  goto LAB_10035fc2;
LAB_10035f1d:
  uVar6 = (*(code *)*param_1)(param_1[2],param_1 + 0x9c,uVar5);
  puVar1 = param_1 + 4;
  uVar9 = *puVar1;
  *puVar1 = *puVar1 + uVar6;
  param_1[5] = param_1[5] + (uint)CARRY4(uVar9,uVar6);
  if (uVar6 != uVar5) goto LAB_10035fc2;
  param_1[0x9b] = uVar5;
  puVar8 = local_130;
  puVar11 = param_1 + 0x52;
  for (iVar4 = 0x48; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar11 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar11 = puVar11 + 1;
  }
  local_134[0x9a] = uVar5;
  param_1 = local_134;
  if (param_3 <= local_148) {
    __security_check_cookie(local_c ^ (uint)auStack_14c);
    return;
  }
  goto LAB_10035dd0;
}

