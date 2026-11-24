
void FUN_10018770(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar2 = 1;
  iVar3 = *(int *)(in_ECX + 0x34);
  iVar1 = *(int *)(in_ECX + 0x38);
  *(undefined **)(in_ECX + 0xd0) = &DAT_1016dec0;
  *(undefined **)(in_ECX + 0xcc) = &DAT_1016dec0;
  if (1 < *(int *)(in_ECX + 0x40)) {
    local_8 = (undefined4 *)(in_ECX + 0xd4);
    do {
      iVar1 = iVar1 >> 1;
      iVar3 = iVar3 >> 1;
      FUN_100028b0(&DAT_1416efe0,0x80,"Creating mipmap level %d : W - %d, H - %d \n",iVar2,iVar3,
                   iVar1);
      OutputDebugStringA(&DAT_1416efe0);
      if ((iVar1 < 1) || (iVar3 < 1)) {
        FUN_100028b0(&DAT_1416efe0,0x80,"Mipmap at level %d has: W - %d, H - %d \n",iVar2,iVar3,
                     iVar1);
        OutputDebugStringA(&DAT_1416efe0);
      }
      iVar2 = iVar2 + 1;
      *local_8 = &DAT_1016dec0;
      local_8 = local_8 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0x40));
  }
  return;
}

