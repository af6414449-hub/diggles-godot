
int * FUN_1000c730(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  iVar1 = *in_ECX;
  puVar3 = *(undefined4 **)(iVar1 + 4);
  *param_1 = (int)puVar3;
  param_1[1] = 0;
  param_1[2] = iVar1;
  if (*(char *)((int)puVar3 + 0xd) == '\0') {
    iVar1 = *param_2;
    do {
      *param_1 = (int)puVar3;
      iVar2 = puVar3[4];
      if (iVar1 <= iVar2) {
        param_1[2] = (int)puVar3;
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)puVar3[2];
      }
      param_1[1] = (uint)(iVar1 <= iVar2);
    } while (*(char *)((int)puVar3 + 0xd) == '\0');
  }
  return param_1;
}

