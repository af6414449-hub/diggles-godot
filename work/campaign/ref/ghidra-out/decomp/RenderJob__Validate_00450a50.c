
undefined4 RenderJob__Validate(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0x48);
  iVar1 = *(int *)(*param_2 + 0x48);
  if (iVar1 < iVar2) {
    return 1;
  }
  if (iVar1 <= iVar2) {
    iVar2 = *(int *)(*param_1 + 0x4c);
    iVar1 = *(int *)(*param_2 + 0x4c);
    if (iVar1 < iVar2) {
      return 1;
    }
    if (iVar1 <= iVar2) {
      return 0;
    }
  }
  return 0xffffffff;
}

