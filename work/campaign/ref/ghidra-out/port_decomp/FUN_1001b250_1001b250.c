
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b250(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 in_EDX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042bf2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  _DAT_10052168 = 0x3f800000;
  DAT_10052154 = 2;
  _DAT_10052150 = param_1;
  _DAT_10052160 = param_2;
  DAT_10051134 = param_2;
  if ((param_2 < 0x400) || (param_2 < 0x1000)) {
    DAT_10051134 = 0x1000;
  }
  uVar4 = DAT_10051134;
  iVar5 = DAT_10051134 << 3;
  _DAT_10051138 = DAT_10051134;
  free(DAT_1005112c);
  DAT_1005112c = (void *)0x0;
  _DAT_10051128 = 0;
  _DAT_10051130 = iVar5;
  DAT_1005112c = (void *)FUN_100402f0(uVar4 * 0x20 + 0x10);
  uVar4 = DAT_10051134;
  _DAT_10051128 = (int)DAT_1005112c + 0xfU & 0xfffffff0;
  iVar5 = DAT_10051134 * 8;
  free(DAT_10051140);
  DAT_10051140 = (void *)0x0;
  _DAT_1005113c = 0;
  _DAT_10051144 = iVar5;
  DAT_10051140 = (void *)FUN_100402f0(uVar4 * 0x20 + 0x10);
  _DAT_1005113c = (int)DAT_10051140 + 0xfU & 0xfffffff0;
  uVar4 = DAT_10051120 * 2;
  uVar3 = -(uint)((int)((ulonglong)uVar4 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar4 * 0xc);
  puVar1 = (uint *)FUN_100402f0(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
  local_8 = 0;
  *puVar1 = uVar4;
  _eh_vector_constructor_iterator_(puVar1 + 1,0xc,uVar4,FUN_1001ac30,FUN_1001acb0);
  local_8 = 0xffffffff;
  DAT_10051148 = puVar1 + 1;
  DAT_1005114c = FUN_100402f0(-(uint)((int)((ulonglong)DAT_10051120 * 4 >> 0x20) != 0) |
                              (uint)((ulonglong)DAT_10051120 * 4));
  param_1 = 0;
  if ((DAT_10051120 & 0x7fffffff) != 0) {
    iVar5 = 0;
    do {
      puVar1 = DAT_10051148;
      free(*(void **)(iVar5 + 4 + (int)DAT_10051148));
      *(undefined4 *)(iVar5 + 4 + (int)puVar1) = 0;
      *(undefined4 *)(iVar5 + (int)puVar1) = 0;
      *(undefined4 *)(iVar5 + 8 + (int)puVar1) = 0x1000;
      iVar2 = FUN_100402f0(0x4010);
      *(int *)(iVar5 + 4 + (int)puVar1) = iVar2;
      param_1 = param_1 + 1;
      *(uint *)(iVar5 + (int)puVar1) = iVar2 + 0xfU & 0xfffffff0;
      iVar5 = iVar5 + 0xc;
    } while (param_1 < DAT_10051120 * 2);
  }
  uVar4 = 0;
  if (DAT_10051120 != 0) {
    do {
      *(undefined4 *)(DAT_1005114c + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_10051120);
  }
  _DAT_10052164 = 1;
  _DAT_1005216c = 0x3f733333;
  switch(DAT_10052154) {
  case 1:
    _DAT_10052e4c = 0;
    _DAT_10052e50 = 0;
    _DAT_10052e54 = 0x3f800000;
    ExceptionList = local_10;
    return;
  case 2:
    break;
  default:
    goto switchD_1001b498_caseD_3;
  case 4:
    uRam10052e64 = 0x40000000;
    uRam10052e68 = 0;
    _DAT_10052e6c = 0xbf800000;
    _DAT_10052e70 = 0xc0000000;
    _DAT_10052e74 = 0;
    _DAT_10052e78 = 0xbf800000;
    break;
  case 6:
    uRam10052e64 = 0;
    uRam10052e68 = 0;
    _DAT_10052e6c = 0x3f800000;
    _DAT_10052e70 = 0;
    _DAT_10052e74 = 0;
    _DAT_10052e78 = 0;
    _DAT_10052e7c = 0x40000000;
    _DAT_10052e80 = 0;
    uRam10052e84 = 0xbf800000;
    uRam10052e88 = 0xc0000000;
    _DAT_10052e8c = 0;
    _DAT_10052e90 = 0xbf800000;
    break;
  case 8:
    uRam10052e64 = 0;
    uRam10052e68 = 0;
    _DAT_10052e6c = 0x3f800000;
    _DAT_10052e70 = 0;
    _DAT_10052e74 = 0;
    _DAT_10052e78 = 0;
    _DAT_10052e7c = 0x40000000;
    _DAT_10052e80 = 0;
    uRam10052e84 = 0;
    uRam10052e88 = 0xc0000000;
    _DAT_10052e8c = 0;
    _DAT_10052e90 = 0;
    uRam10052e94 = 0x40000000;
    uRam10052e98 = 0;
    _DAT_10052e9c = 0xbf800000;
    _DAT_10052ea0 = 0xc0000000;
    _DAT_10052ea4 = 0;
    _DAT_10052ea8 = 0xbf800000;
  }
  _DAT_10052e60 = 0x3f800000;
  _DAT_10052e5c = 0;
  uRam10052e58 = 0xc0000000;
  _DAT_10052e54 = 0x3f800000;
  _DAT_10052e50 = 0;
  _DAT_10052e4c = 0x40000000;
switchD_1001b498_caseD_3:
  ExceptionList = local_10;
  return;
}

