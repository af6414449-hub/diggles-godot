
void FUN_10008010(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  uVar7 = FUN_10008500(*(undefined4 *)(*param_1 + 4),*in_ECX,param_2);
  *(undefined4 *)(*in_ECX + 4) = uVar7;
  piVar2 = (int *)*in_ECX;
  in_ECX[1] = param_1[1];
  piVar3 = (int *)piVar2[1];
  if (*(char *)((int)piVar3 + 0xd) != '\0') {
    *piVar2 = (int)piVar2;
    *(int *)(*in_ECX + 8) = *in_ECX;
    return;
  }
  cVar1 = *(char *)(*piVar3 + 0xd);
  piVar6 = (int *)*piVar3;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0xd);
    piVar3 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar2 = (int)piVar3;
  iVar4 = *(int *)(*in_ECX + 4);
  iVar5 = *(int *)(iVar4 + 8);
  cVar1 = *(char *)(iVar5 + 0xd);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0xd);
    iVar4 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*in_ECX + 8) = iVar4;
  return;
}

