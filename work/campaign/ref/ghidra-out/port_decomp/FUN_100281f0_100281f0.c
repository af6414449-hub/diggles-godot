
undefined4 FUN_100281f0(uint param_1,uint param_2)

{
  undefined8 uVar1;
  uint *puVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  double dVar10;
  double dVar11;
  longlong lVar12;
  uint local_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  ushort local_24;
  ushort uStack_22;
  uint uStack_10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  puVar2 = (uint *)(*(int *)(in_ECX + 0x52a0) + 8);
  uVar8 = *(uint *)(*(int *)(in_ECX + 0x52a0) + 0xc);
  if ((uVar8 < param_2) || ((uVar8 <= param_2 && (*puVar2 <= param_1)))) {
    uVar8 = 0;
    uVar7 = 0;
    if (*(int *)(in_ECX + 0x52a4) != 0) {
      do {
        uVar4 = uVar8;
        if ((param_2 < puVar2[1]) || ((param_2 <= puVar2[1] && (param_1 < *puVar2)))) break;
        puVar2 = puVar2 + 6;
        uVar8 = uVar4 + 1;
        uVar7 = uVar4;
      } while (uVar4 + 1 < *(uint *)(in_ECX + 0x52a4));
    }
    puVar2 = (uint *)(*(int *)(in_ECX + 0x52a0) + uVar7 * 0x18);
    local_34 = *puVar2;
    uStack_30 = puVar2[1];
    uStack_2c = puVar2[2];
    uStack_28 = puVar2[3];
    uVar1 = *(undefined8 *)(*(int *)(in_ECX + 0x52a0) + 0x10 + uVar7 * 0x18);
    uStack_22 = (ushort)((ulonglong)uVar1 >> 0x10);
    uStack_10 = (uint)uStack_22;
    local_24 = (ushort)uVar1;
  }
  else {
    local_24 = 0;
    local_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_10 = 0;
  }
  if ((uStack_30 == 0) && (local_34 < 0x80000000)) {
    iVar3 = (**(code **)(in_ECX + 0x1a2c))(*(undefined4 *)(in_ECX + 0x1a30),local_34,0);
    if (iVar3 == 0) {
      return 0;
    }
    *(uint *)(in_ECX + 0x3e60) = local_34;
    *(int *)(in_ECX + 0x3e64) = (int)local_34 >> 0x1f;
  }
  else {
    iVar3 = (**(code **)(in_ECX + 0x1a2c))(*(undefined4 *)(in_ECX + 0x1a30),0x7fffffff,0);
    if (iVar3 == 0) {
      return 0;
    }
    *(undefined4 *)(in_ECX + 0x3e60) = 0x7fffffff;
    *(undefined4 *)(in_ECX + 0x3e64) = 0;
    while( true ) {
      bVar9 = 0x7ffffffe < local_34;
      local_34 = local_34 + 0x80000001;
      uStack_30 = (uStack_30 - 1) + (uint)bVar9;
      if ((uStack_30 == 0) && (local_34 == 0)) goto LAB_10028360;
      if ((uStack_30 == 0) && (local_34 < 0x80000000)) break;
      iVar3 = (**(code **)(in_ECX + 0x1a2c))(*(undefined4 *)(in_ECX + 0x1a30),0x7fffffff,1);
      if (iVar3 == 0) {
        return 0;
      }
      puVar2 = (uint *)(in_ECX + 0x3e60);
      uVar8 = *puVar2;
      *puVar2 = *puVar2 + 0x7fffffff;
      *(int *)(in_ECX + 0x3e64) = *(int *)(in_ECX + 0x3e64) + (uint)(0x80000000 < uVar8);
    }
    iVar3 = (**(code **)(in_ECX + 0x1a2c))(*(undefined4 *)(in_ECX + 0x1a30),local_34,1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar2 = (uint *)(in_ECX + 0x3e60);
    uVar8 = *puVar2;
    *puVar2 = *puVar2 + local_34;
    *(int *)(in_ECX + 0x3e64) =
         *(int *)(in_ECX + 0x3e64) + ((int)local_34 >> 0x1f) + (uint)CARRY4(uVar8,local_34);
  }
LAB_10028360:
  FUN_10028100();
  uVar6 = 0;
  if (local_24 != 0) {
    do {
      iVar3 = FUN_10027ab0(1);
      if (iVar3 == 0) {
        return 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < local_24);
  }
  uVar8 = uStack_2c - uStack_10;
  *(uint *)(in_ECX + 0x3e58) = uVar8;
  iVar5 = uStack_28 - (uStack_2c < uStack_10);
  *(int *)(in_ECX + 0x3e5c) = iVar5;
  dVar10 = (double)*(int *)(in_ECX + 0x3e6c) +
           *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x3e6c) >> 0x1f) * -8);
  dVar11 = ((double)*(int *)(in_ECX + 0x3e68) +
           *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x3e68) >> 0x1f) * -8)) / dVar10;
  FUN_100415c0();
  iVar3 = FUN_10041395();
  dVar10 = dVar11 * dVar10 - ((double)iVar3 + *(double *)(&DAT_10047c80 + (iVar3 >> 0x1f) * -8));
  *(double *)(in_ECX + 0x5290) = dVar10;
  if (0.0 < dVar10) {
    *(uint *)(in_ECX + 0x5298) = *(uint *)(in_ECX + 0x5298) | 1;
  }
  iVar3 = (param_2 - iVar5) - (uint)(param_1 < uVar8);
  lVar12 = FUN_10027ee0(param_1 - uVar8,iVar3);
  if (lVar12 != CONCAT44(iVar3,param_1 - uVar8)) {
    return 0;
  }
  return 1;
}

