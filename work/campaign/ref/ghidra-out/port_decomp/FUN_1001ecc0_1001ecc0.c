
undefined4 * FUN_1001ecc0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  FILE *pFVar5;
  undefined4 uVar6;
  void *_Dst;
  undefined4 *in_ECX;
  undefined4 extraout_ECX;
  undefined4 in_EDX;
  bool bVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042c1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  in_ECX[0x1c] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x25] = 0;
  *(undefined8 *)(in_ECX + 0x1e) = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x31] = 0;
  *(undefined8 *)(in_ECX + 0x2a) = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x3d] = 0;
  *(undefined8 *)(in_ECX + 0x36) = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0;
  in_ECX[0x49] = 0;
  *(undefined8 *)(in_ECX + 0x42) = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x4b] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  in_ECX[0x52] = 0;
  in_ECX[0x53] = 0;
  in_ECX[0x55] = 0;
  *(undefined8 *)(in_ECX + 0x4e) = 0;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0x3f800000;
  in_ECX[7] = 0x3f800000;
  in_ECX[8] = 0x3f800000;
  in_ECX[9] = 0x3f800000;
  in_ECX[10] = 0x3f800000;
  in_ECX[0xb] = 0x3f800000;
  in_ECX[0xc] = 0x3f800000;
  in_ECX[0xd] = 0x3f800000;
  in_ECX[0xe] = 0x3f800000;
  in_ECX[0x10] = 0x472c4400;
  in_ECX[0x11] = 0x472c4400;
  in_ECX[0x13] = 0x3f800000;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x56] = 0;
  in_ECX[0x12] = 1;
  in_ECX[0x60] = 0xffffffff;
  in_ECX[3] = 0;
  *(undefined8 *)(in_ECX + 0x6e) = 0;
  in_ECX[0x61] = 0;
  in_ECX[0x62] = 0;
  in_ECX[99] = 0;
  in_ECX[100] = 0;
  in_ECX[0x65] = 0;
  in_ECX[0x66] = 0;
  in_ECX[0x67] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x5a] = 0;
  in_ECX[0x5b] = 0;
  in_ECX[0x5c] = 0;
  in_ECX[0x5d] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x69] = 0;
  in_ECX[0x6a] = 0;
  in_ECX[0x6b] = 0;
  in_ECX[0x6c] = 0;
  in_ECX[0x6d] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x14] = 0x3f800000;
  local_8 = 0;
  *in_ECX = SoLoud::WavStreamInstance::vftable;
  in_ECX[0x70] = param_1;
  in_ECX[0x71] = 0;
  in_ECX[0x73] = 0;
  in_ECX[0x72] = 0;
  if (*(int *)(param_1 + 0x70) == 0) {
    if (*(int *)(param_1 + 0x6c) == 0) {
      piVar1 = *(int **)(param_1 + 0x74);
      if (piVar1 == (int *)0x0) {
        ExceptionList = local_10;
        return in_ECX;
      }
      in_ECX[0x72] = piVar1;
      (**(code **)(*piVar1 + 0x10))(0);
    }
    else {
      puVar4 = (undefined8 *)FUN_1003ff62(8);
      *puVar4 = 0;
      *(undefined ***)puVar4 = SoLoud::DiskFile::vftable;
      *(undefined4 *)((int)puVar4 + 4) = 0;
      in_ECX[0x72] = puVar4;
      if (*(char **)(param_1 + 0x6c) != (char *)0x0) {
        pFVar5 = fopen(*(char **)(param_1 + 0x6c),"rb");
        *(FILE **)((int)puVar4 + 4) = pFVar5;
      }
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_1003ff62(0x14);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    *puVar2 = SoLoud::MemoryFile::vftable;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(undefined1 *)(puVar2 + 4) = 0;
    in_ECX[0x72] = puVar2;
    iVar3 = (**(code **)(**(int **)(param_1 + 0x70) + 0xc))();
    param_1 = (**(code **)(**(int **)(param_1 + 0x70) + 0x1c))();
    if ((param_1 != 0) && (iVar3 != 0)) {
      if (*(char *)(puVar2 + 4) != '\0') {
        free((void *)puVar2[1]);
      }
      puVar2[2] = iVar3;
      puVar2[3] = 0;
      puVar2[1] = param_1;
      *(undefined1 *)(puVar2 + 4) = 0;
    }
  }
  puVar2 = (undefined4 *)in_ECX[0x72];
  if (puVar2 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return in_ECX;
  }
  iVar3 = *(int *)(in_ECX[0x70] + 0x68);
  if (iVar3 == 0) {
    uVar6 = FUN_1003ff62(0x178);
    in_ECX[0x73] = uVar6;
    iVar3 = FUN_10029a90();
    if (iVar3 != 0) {
      ExceptionList = local_10;
      return in_ECX;
    }
    uVar6 = 0x178;
LAB_1001f20f:
    FUN_100402ac(in_ECX[0x73],uVar6);
    in_ECX[0x73] = 0;
LAB_1001f227:
    puVar2 = (undefined4 *)in_ECX[0x72];
    if (puVar2 == *(undefined4 **)(in_ECX[0x70] + 0x74)) goto LAB_1001f247;
    bVar7 = puVar2 == (undefined4 *)0x0;
  }
  else {
    if (iVar3 == 1) {
      iVar3 = FUN_1003f970(&param_1,puVar2);
      in_ECX[0x73] = iVar3;
      if (iVar3 == 0) {
        puVar2 = (undefined4 *)in_ECX[0x72];
        if ((puVar2 != *(undefined4 **)(in_ECX[0x70] + 0x74)) && (puVar2 != (undefined4 *)0x0)) {
          (**(code **)*puVar2)(1);
        }
        in_ECX[0x72] = 0;
      }
      in_ECX[0x74] = 0;
      in_ECX[0x75] = 0;
      in_ECX[0x76] = 0;
      ExceptionList = local_10;
      return in_ECX;
    }
    if (iVar3 == 2) {
      iVar3 = FUN_10036ac0(puVar2,puVar2);
      in_ECX[0x73] = iVar3;
      if (iVar3 != 0) {
        ExceptionList = local_10;
        return in_ECX;
      }
      goto LAB_1001f227;
    }
    if (iVar3 == 3) {
      _Dst = (void *)FUN_1003ff62(0x52c8);
      in_ECX[0x73] = _Dst;
      uVar6 = in_ECX[0x72];
      memset(_Dst,0,0x52c8);
      iVar3 = FUN_10027e00(extraout_ECX,uVar6);
      if (iVar3 != 0) {
        ExceptionList = local_10;
        return in_ECX;
      }
      uVar6 = 0x52c8;
      goto LAB_1001f20f;
    }
    bVar7 = puVar2 == *(undefined4 **)(in_ECX[0x70] + 0x74);
  }
  if (!bVar7) {
    (**(code **)*puVar2)(1);
  }
LAB_1001f247:
  in_ECX[0x72] = 0;
  ExceptionList = local_10;
  return in_ECX;
}

