
void FUN_005eae80(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((int)param_1 + 0x3d0);
  if ((uVar3 & 1) != 0) {
    *(undefined1 *)((int)param_1 + 0x3b4) = 1;
    FUN_005ca8b0();
    uVar3 = *(uint *)((int)param_1 + 0x3d0);
  }
  *(uint *)((int)param_1 + 0x3d0) = uVar3 & 0xfffffffe;
  if (DAT_0076a33c == (undefined4 *)0x0) {
    DAT_0076a33c = (undefined4 *)FUN_006ba810(0x1e2);
    if (DAT_0076a33c == (undefined4 *)0x0) {
      DAT_0076a33c = (undefined4 *)0x0;
    }
    else {
      *DAT_0076a33c = 0;
      DAT_0076a33c[1] = 0;
    }
  }
  FUN_004845a0(param_1);
  iVar1 = DAT_0077247c;
  BVar2 = IsBadReadPtr(param_1,0x10);
  if ((((BVar2 == 0) && (*(int *)((int)param_1 + 8) == 0x616e4f62)) &&
      ((DAT_00768398 == '\0' || (*(int *)((int)param_1 + 0xdc) != 0)))) &&
     (*(char *)((int)param_1 + 0x404) == '\0')) {
    *(undefined1 *)((int)param_1 + 0x404) = 1;
    uVar3 = FUN_0042f510();
    if (*(uint *)(iVar1 + 0x410) <= uVar3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(void **)(*(int *)(iVar1 + 0x40c) + uVar3 * 4) = param_1;
  }
  return;
}

