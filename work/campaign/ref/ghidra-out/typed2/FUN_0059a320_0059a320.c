
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059a320(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = PTR_0077241c->cellX0;
  iVar2 = PTR_0077241c->cellX1 - iVar4;
  if ((DAT_00b9bf20 != iVar2) || (DAT_00b9bf24 != PTR_0077241c->cellY1 - PTR_0077241c->cellY0)) {
    iVar2 = (PTR_0077241c->cellY1 - PTR_0077241c->cellY0) * iVar2;
    iVar4 = DAT_00b9bf28;
    if (iVar2 - DAT_00b9bf28 != 0) {
      iVar4 = iVar2;
      if (DAT_00b9bf18 == (undefined4 *)0x0) {
        DAT_00b9bf18 = (undefined4 *)FUN_006ba810(0x3f);
        iVar3 = 0;
        DAT_00b9bf1c = iVar2;
        if (0 < iVar2) {
          do {
            if (iVar3 < DAT_00b9bf1c) {
              puVar1 = DAT_00b9bf18 + iVar3;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar1 = DAT_00b9bf18;
            }
            iVar3 = iVar3 + 1;
            *puVar1 = 0x7fffffff;
          } while (iVar3 < iVar2);
        }
      }
      else {
        DAT_00b9bf18 = (undefined4 *)
                       FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathfinder.cpp",
                                    0x33);
        DAT_00b9bf1c = iVar2;
        for (iVar3 = DAT_00b9bf28; iVar3 < iVar2; iVar3 = iVar3 + 1) {
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar1 = DAT_00b9bf18;
          }
          else {
            puVar1 = DAT_00b9bf18 + iVar3;
          }
          *puVar1 = 0x7fffffff;
        }
      }
    }
    DAT_00b9bf28 = iVar4;
    DAT_00b9bf20 = PTR_0077241c->cellX1 - PTR_0077241c->cellX0;
    DAT_00b9bf24 = PTR_0077241c->cellY1 - PTR_0077241c->cellY0;
    iVar4 = PTR_0077241c->cellX0;
  }
  DAT_00b9bf2c = iVar4;
  DAT_00b9bf30 = PTR_0077241c->cellY0;
  _DAT_00b9bf34 = (PTR_0077241c->cellY0 * DAT_00b9bf20 - DAT_00b9bf28) + iVar4;
  return;
}

