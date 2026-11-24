
/* WARNING: Removing unreachable block (ram,0x005b6f5f) */

void thunk_FUN_005b6f10(void)

{
  int iVar1;
  int *piVar2;
  void **ppvVar3;
  uint uVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_007056e0;
  pvStack_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar1 = in_ECX[1];
  if (iVar1 < 0) {
    ExceptionList = &pvStack_10;
    FUN_005b7000(-iVar1);
    ppvVar3 = (void **)ExceptionList;
  }
  else {
    ppvVar3 = &pvStack_10;
    if (0 < iVar1) {
      if (iVar1 == 1) {
        puStack_c = &LAB_007056e0;
        uStack_8 = 0;
        piVar2 = *(int **)*in_ECX;
        ExceptionList = &pvStack_10;
        if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
          FUN_006ba940(uVar4);
        }
      }
      else {
        iVar6 = iVar1 * 8;
        iVar5 = iVar1;
        ExceptionList = &pvStack_10;
        do {
          iVar6 = iVar6 + -8;
          uStack_8 = 1;
          piVar2 = *(int **)(*in_ECX + iVar6);
          if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
            FUN_006ba940(uVar4);
          }
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      uStack_8 = 0xffffffff;
      in_ECX[1] = in_ECX[1] - iVar1;
      ppvVar3 = (void **)ExceptionList;
    }
  }
  ExceptionList = ppvVar3;
  if (*in_ECX != 0) {
    FUN_006ba940(uVar4);
  }
  ExceptionList = pvStack_10;
  return;
}

