
void FUN_10020900(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  DWORD DVar8;
  DWORD DVar9;
  int iVar10;
  int iVar11;
  int local_c;
  uint local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_c = 0;
  iVar6 = (param_1[4] * 1000) / param_1[5];
  cVar1 = (char)param_1[7];
  while (cVar1 != '\0') {
    iVar11 = param_1[4];
    iVar2 = param_1[3];
    iVar3 = *param_1;
    FUN_1001de50(iVar11);
    iVar4 = *(int *)(iVar2 + 0x18);
    iVar10 = 0;
    uVar5 = *(uint *)(iVar2 + 0x1044);
    local_8 = 0;
    if (uVar5 != 0) {
      uVar7 = local_8;
      do {
        for (; uVar7 < uVar5 * iVar11; uVar7 = uVar7 + uVar5) {
          iVar2 = iVar10 * 4;
          iVar10 = iVar10 + 1;
          *(undefined4 *)(iVar3 + uVar7 * 4) = *(undefined4 *)(iVar4 + iVar2);
        }
        uVar7 = local_8 + 1;
        local_8 = uVar7;
      } while (uVar7 < uVar5);
    }
    DVar8 = GetTickCount();
    do {
      Sleep(1);
      DVar9 = GetTickCount();
      iVar11 = DVar9 - (DVar8 - local_c);
    } while (iVar11 < iVar6);
    local_c = iVar11 - iVar6;
    cVar1 = (char)param_1[7];
  }
  return;
}

