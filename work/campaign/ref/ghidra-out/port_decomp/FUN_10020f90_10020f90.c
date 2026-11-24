
void FUN_10020f90(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  DWORD DVar6;
  MMRESULT MVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int local_14;
  uint local_10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  DVar6 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x5c),0);
  do {
    if (DVar6 == 0) {
      return;
    }
    puVar11 = (uint *)(param_1 + 0x24);
    piVar8 = (int *)(param_1 + 0xc);
    local_14 = 0;
    do {
      if ((*puVar11 & 0x10) == 0) {
        iVar2 = *piVar8;
        iVar3 = *(int *)(param_1 + 0x60);
        iVar4 = *(int *)(param_1 + 100);
        FUN_1001de50(iVar4);
        uVar5 = *(uint *)(iVar3 + 0x1044);
        iVar3 = *(int *)(iVar3 + 0x18);
        iVar9 = 0;
        local_10 = 0;
        if (uVar5 != 0) {
          uVar10 = local_10;
          do {
            for (; uVar10 < uVar5 * iVar4; uVar10 = uVar10 + uVar5) {
              iVar1 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              *(short *)(iVar2 + uVar10 * 2) = (short)(int)(*(float *)(iVar3 + iVar1) * 32767.0);
            }
            uVar10 = local_10 + 1;
            local_10 = uVar10;
          } while (uVar10 < uVar5);
        }
        MVar7 = waveOutWrite(*(HWAVEOUT *)(param_1 + 0x54),(LPWAVEHDR)(puVar11 + -4),0x20);
        if (MVar7 != 0) {
          return;
        }
      }
      local_14 = local_14 + 1;
      piVar8 = piVar8 + 1;
      puVar11 = puVar11 + 8;
    } while (local_14 < 2);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x58),0xffffffff);
    DVar6 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x5c),0);
  } while( true );
}

