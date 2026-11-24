
void FUN_1001fb90(int *param_1)

{
  double dVar1;
  int *_Memory;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  undefined4 extraout_ECX;
  int unaff_ESI;
  undefined4 local_18c [17];
  int iStack_148;
  ushort uStack_144;
  undefined4 uStack_13c;
  uint uStack_18;
  uint uStack_14;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)local_18c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_18c[0] = 0;
  (**(code **)(*param_1 + 8))(local_18c,4);
  if (unaff_ESI == 0x5367674f) {
    (**(code **)(*param_1 + 0x10))(0);
    _Memory = (int *)FUN_1003f970(&stack0xfffffe68,extraout_ECX);
    if (_Memory != (int *)0x0) {
      iVar4 = *_Memory;
      iVar2 = _Memory[1];
      if (8 < iVar2) {
        iVar2 = 8;
      }
      *(int *)(in_ECX + 0x14) = iVar2;
      *(float *)(in_ECX + 0xc) =
           (float)((double)iVar4 + *(double *)(&DAT_10047c80 + (iVar4 >> 0x1f) * -8));
      uVar3 = FUN_1003f6e0();
      FUN_1003eea0();
      if (_Memory[0x17] == 0) {
        free(_Memory);
      }
      *(undefined4 *)(in_ECX + 0x68) = 1;
      *(undefined4 *)(in_ECX + 0x78) = uVar3;
      __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffe68);
      return;
    }
  }
  else if (unaff_ESI == 0x46464952) {
    (**(code **)(*param_1 + 0x10))(0);
    iVar4 = FUN_10029a90();
    if (iVar4 != 0) {
      uVar5 = (uint)uStack_144;
      *(undefined4 *)(in_ECX + 0x68) = 0;
      if (8 < uVar5) {
        uVar5 = 8;
      }
      *(uint *)(in_ECX + 0x14) = uVar5;
      dVar1 = *(double *)(&DAT_10047c80 + (iStack_148 >> 0x1f) * -8);
      *(undefined4 *)(in_ECX + 0x78) = uStack_13c;
      *(float *)(in_ECX + 0xc) = (float)((double)iStack_148 + dVar1);
      FUN_10029b50();
      __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffe68);
      return;
    }
  }
  else {
    if (unaff_ESI != 0x43614c66) {
      FUN_1001fa80(param_1);
      __security_check_cookie(uStack_14 ^ (uint)&stack0xfffffe6c);
      return;
    }
    (**(code **)(*param_1 + 0x10))(0);
    iVar4 = FUN_10036540();
    if (iVar4 != 0) {
      uVar5 = (uint)*(byte *)(iVar4 + 0x1c);
      if (8 < uVar5) {
        uVar5 = 8;
      }
      *(uint *)(in_ECX + 0x14) = uVar5;
      *(float *)(in_ECX + 0xc) =
           (float)((double)*(int *)(iVar4 + 0x18) +
                  *(double *)(&DAT_10047c80 + (*(int *)(iVar4 + 0x18) >> 0x1f) * -8));
      *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(iVar4 + 0x20);
      *(undefined4 *)(in_ECX + 0x68) = 2;
      if (((undefined4 *)(iVar4 + 8) != (undefined4 *)0x0) &&
         (*(code **)(iVar4 + 0x14) != (code *)0x0)) {
        (**(code **)(iVar4 + 0x14))(iVar4,*(undefined4 *)(iVar4 + 8));
      }
      __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffe68);
      return;
    }
  }
  __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffe68);
  return;
}

