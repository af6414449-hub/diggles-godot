
int * FUN_10011d30(int *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  iVar2 = DAT_1416ee94;
  puVar3 = *(undefined4 **)(DAT_1416ee94 + 4);
  *param_1 = (int)puVar3;
  param_1[1] = 0;
  param_1[2] = iVar2;
  if (*(char *)((int)puVar3 + 0xd) == '\0') {
    uVar1 = *param_2;
    do {
      *param_1 = (int)puVar3;
      bVar4 = uVar1 <= *(ushort *)((int)puVar3 + 0xe);
      if (bVar4) {
        param_1[2] = (int)puVar3;
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)puVar3[2];
      }
      param_1[1] = (uint)bVar4;
    } while (*(char *)((int)puVar3 + 0xd) == '\0');
  }
  return param_1;
}

