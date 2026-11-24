
void FUN_10013720(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint _Size;
  uint uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  void *pvVar8;
  undefined4 *in_ECX;
  undefined4 *puVar9;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  _Size = param_2[4];
  uVar2 = param_3[4];
  uVar1 = uVar2 + _Size;
  if ((uVar2 <= param_2[5] - _Size) && ((uint)param_3[5] <= (uint)param_2[5])) {
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = param_2[3];
    *in_ECX = *param_2;
    in_ECX[1] = uVar4;
    in_ECX[2] = uVar5;
    in_ECX[3] = uVar6;
    *(undefined8 *)(in_ECX + 4) = *(undefined8 *)(param_2 + 4);
    param_2[4] = 0;
    param_2[5] = 0xf;
    *(undefined1 *)param_2 = 0;
    puVar9 = in_ECX;
    if (0xf < (uint)in_ECX[5]) {
      puVar9 = (undefined4 *)*in_ECX;
    }
    if (0xf < (uint)param_3[5]) {
      param_3 = (undefined4 *)*param_3;
    }
    memcpy((void *)((int)puVar9 + _Size),param_3,uVar2 + 1);
    in_ECX[4] = uVar1;
    return;
  }
  if (_Size <= param_3[5] - uVar2) {
    uVar4 = param_3[1];
    uVar5 = param_3[2];
    uVar6 = param_3[3];
    *in_ECX = *param_3;
    in_ECX[1] = uVar4;
    in_ECX[2] = uVar5;
    in_ECX[3] = uVar6;
    *(undefined8 *)(in_ECX + 4) = *(undefined8 *)(param_3 + 4);
    param_3[4] = 0;
    param_3[5] = 0xf;
    *(undefined1 *)param_3 = 0;
    pvVar8 = (void *)*in_ECX;
    memmove((void *)((int)pvVar8 + _Size),pvVar8,uVar2 + 1);
    if (0xf < (uint)param_2[5]) {
      param_2 = (undefined4 *)*param_2;
    }
    memcpy(pvVar8,param_2,_Size);
    in_ECX[4] = uVar1;
    return;
  }
  if (uVar2 <= 0x7fffffff - _Size) {
    uVar7 = uVar1 | 0xf;
    if (uVar7 < 0x80000000) {
      if (uVar7 < 0x16) {
        uVar7 = 0x16;
      }
    }
    else {
      uVar7 = 0x7fffffff;
    }
    pvVar8 = (void *)FUN_10003e80(-(uint)(0xfffffffe < uVar7) | uVar7 + 1);
    in_ECX[4] = uVar1;
    *in_ECX = pvVar8;
    in_ECX[5] = uVar7;
    if (0xf < (uint)param_2[5]) {
      param_2 = (undefined4 *)*param_2;
    }
    memcpy(pvVar8,param_2,_Size);
    if (0xf < (uint)param_3[5]) {
      param_3 = (undefined4 *)*param_3;
    }
    memcpy((void *)((int)pvVar8 + _Size),param_3,uVar2 + 1);
    return;
  }
  FUN_10002ab0();
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

