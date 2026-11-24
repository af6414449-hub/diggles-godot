
undefined4 FUN_004237e0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_00592f10(PTR_0077241c);
  uVar2 = (uint)*(ushort *)(iVar1 + 0x16);
  if (uVar2 == 0) {
    iVar1 = FUN_00592f10(PTR_0077241c);
    uVar2 = (uint)*(ushort *)(iVar1 + 0x16);
    if (uVar2 == 0) {
      iVar1 = FUN_00592f10(PTR_0077241c);
      uVar2 = (uint)*(ushort *)(iVar1 + 0x16);
      if (uVar2 == 0) {
        iVar1 = FUN_00592f10(PTR_0077241c);
        uVar2 = (uint)*(ushort *)(iVar1 + 0x16);
        if (uVar2 == 0) {
          iVar1 = FUN_00592f10(PTR_0077241c);
          uVar2 = (uint)*(ushort *)(iVar1 + 0x16);
          if (uVar2 == 0) {
            return *(undefined4 *)(DAT_0077244c + 0x488);
          }
        }
      }
    }
  }
  puVar3 = (undefined4 *)(DAT_0077244c + 0x488);
  if (uVar2 < 0x2000) {
    return puVar3[uVar2];
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  return *puVar3;
}

