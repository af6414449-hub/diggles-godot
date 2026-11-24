
void FUN_005fa510(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  param_1 = param_1 - ((int)(PTR_0077241c->originX + (PTR_0077241c->originX >> 0x1f & 3U)) >> 2);
  param_2 = param_2 - ((int)(PTR_0077241c->originY + (PTR_0077241c->originY >> 0x1f & 3U)) >> 2);
  if ((((-1 < param_1) && (param_3 = param_3 + param_1, param_3 <= *(int *)(in_ECX + 0x7c))) &&
      (-1 < param_2)) && (param_4 + param_2 <= *(int *)(in_ECX + 0x80))) {
    for (; iVar1 = param_2, param_1 < param_3; param_1 = param_1 + 1) {
      for (; iVar1 < param_4 + param_2; iVar1 = iVar1 + 1) {
        iVar2 = *(int *)(in_ECX + 0x7c) * iVar1 + param_1;
        if ((iVar2 < 0) || (*(int *)(in_ECX + 0x34) <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar3 = *(undefined4 **)(in_ECX + 0x30);
        }
        else {
          puVar3 = (undefined4 *)(*(int *)(in_ECX + 0x30) + iVar2 * 4);
        }
        *puVar3 = 1;
      }
    }
  }
  return;
}

