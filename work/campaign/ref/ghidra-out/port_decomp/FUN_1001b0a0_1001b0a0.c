
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001b0a0(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  HANDLE pvVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  void *_Memory;
  undefined4 uVar6;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  FUN_1001aff0();
  _DAT_10051114 = FUN_100213c0();
  _DAT_10052158 = 0;
  _DAT_1005215c = (char *)0x0;
  iVar1 = FUN_10020d20(0xac44,0x1000,extraout_ECX);
  if (iVar1 == 0) {
    _DAT_10052158 = 5;
    return 0;
  }
  iVar1 = FUN_100211a0(0xac44,0x1000,extraout_ECX_00);
  if (iVar1 == 0) {
    _DAT_10052158 = 4;
    return 0;
  }
  uVar6 = 0x20;
  puVar2 = (uint *)FUN_1003ff62(0x20);
  puVar2[1] = 0;
  *puVar2 = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  *(undefined1 *)(puVar2 + 7) = 0;
  _DAT_1005111c = FUN_100209d0;
  _DAT_10051110 = puVar2;
  puVar2[4] = 0x800;
  puVar2[5] = 0xac44;
  puVar2[3] = (uint)&DAT_10051110;
  _Memory = (void *)puVar2[1];
  free(_Memory);
  puVar2[1] = 0;
  *puVar2 = 0;
  puVar2[2] = 0x1000;
  uVar3 = FUN_100402f0(0x4010);
  puVar2[1] = uVar3;
  *puVar2 = uVar3 + 0xf & 0xfffffff0;
  *(undefined1 *)(puVar2 + 7) = 1;
  FUN_1001b250(0xac44,puVar2[4] * 2,_Memory,uVar6);
  puVar4 = (undefined4 *)FUN_1003ff62(8);
  *puVar4 = FUN_10020900;
  puVar4[1] = puVar2;
  pvVar5 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100213f0,puVar4,0,(LPDWORD)0x0);
  if (pvVar5 == (HANDLE)0x0) {
    puVar2[6] = 0;
  }
  else {
    puVar4 = (undefined4 *)FUN_1003ff62(4);
    *puVar4 = pvVar5;
    puVar2[6] = (uint)puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      _DAT_1005215c = "NoSound";
      _DAT_10052158 = 0xf;
      return 0;
    }
  }
  return 7;
}

