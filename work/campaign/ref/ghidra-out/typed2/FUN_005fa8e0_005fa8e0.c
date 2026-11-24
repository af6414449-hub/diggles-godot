
undefined4 FUN_005fa8e0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  local_8 = 0;
  if (0 < param_3) {
    do {
      iVar4 = 0;
      if (0 < param_4) {
        do {
          iVar2 = (iVar4 - ((int)(PTR_0077241c->originY + (PTR_0077241c->originY >> 0x1f & 3U)) >> 2
                           )) + param_2;
          iVar3 = (local_8 -
                  ((int)(PTR_0077241c->originX + (PTR_0077241c->originX >> 0x1f & 3U)) >> 2)) +
                  param_1;
          if ((((iVar3 < 0) || (*(int *)(in_ECX + 0x7c) <= iVar3)) || (iVar2 < 0)) ||
             (*(int *)(in_ECX + 0x80) <= iVar2)) {
            return 0;
          }
          iVar3 = *(int *)(in_ECX + 0x7c) * iVar2 + iVar3;
          if ((iVar3 < 0) || (*(int *)(in_ECX + 0x34) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar1 = *(int **)(in_ECX + 0x30);
          }
          else {
            piVar1 = (int *)(*(int *)(in_ECX + 0x30) + iVar3 * 4);
          }
          if (*piVar1 == 1) {
            return 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_4);
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  return 1;
}

