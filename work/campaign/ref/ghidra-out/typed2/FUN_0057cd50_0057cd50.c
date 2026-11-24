
void FUN_0057cd50(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  
  iVar2 = PTR_0077241c->cellX0 + 4;
  if (param_1 < iVar2) {
    param_1 = iVar2;
  }
  iVar2 = PTR_0077241c->cellY0 + 4;
  if (param_2 < iVar2) {
    param_2 = iVar2;
  }
  iVar2 = PTR_0077241c->cellX1 + -4;
  if (iVar2 < param_3) {
    param_3 = iVar2;
  }
  iVar2 = PTR_0077241c->cellY1 + -4;
  if (iVar2 < param_4) {
    param_4 = iVar2;
  }
  for (; iVar2 = param_1, param_2 < param_4; param_2 = param_2 + 1) {
    for (; iVar2 < param_3; iVar2 = iVar2 + 1) {
      uVar4 = *(uint *)(in_ECX + 0xcb1);
      if ((uVar4 + 0x20 & 0xffffffe0) != (uVar4 + 0x1f & 0xffffffe0)) {
        uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        uVar4 = *(uint *)(in_ECX + 0xcb1);
        *(undefined4 *)(in_ECX + 0xcad) = uVar3;
      }
      *(uint *)(in_ECX + 0xcb1) = uVar4 + 1;
      if (uVar4 + 1 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar1 = *(int *)(in_ECX + 0xcad);
      *(int *)(iVar1 + uVar4 * 8) = iVar2;
      *(int *)(iVar1 + 4 + uVar4 * 8) = param_2;
    }
  }
  return;
}

