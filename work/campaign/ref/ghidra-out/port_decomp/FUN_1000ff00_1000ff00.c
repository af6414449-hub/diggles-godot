
void FUN_1000ff00(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *in_ECX;
  uVar2 = *(undefined4 *)(iVar1 + 0x20);
  (**(code **)(**(int **)(iVar1 + 8) + 200))
            (*(int **)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x1c),&DAT_1416e9b8);
  (**(code **)(**(int **)(*in_ECX + 8) + 0xd4))(*(int **)(*in_ECX + 8),uVar2,3,0x3f800000,0xff);
  iVar1 = *in_ECX;
  uVar2 = *(undefined4 *)(iVar1 + 0x4c);
  (**(code **)(**(int **)(iVar1 + 8) + 200))
            (*(int **)(iVar1 + 8),*(undefined4 *)(iVar1 + 0x40),&DAT_1416e9b8);
  (**(code **)(**(int **)(*in_ECX + 8) + 0xd4))(*(int **)(*in_ECX + 8),uVar2,3,0x3f800000,0xff);
  return;
}

