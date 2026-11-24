
void FUN_10020ab0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  DWORD DVar7;
  int iVar8;
  undefined1 *unaff_ESI;
  undefined1 *puVar9;
  int *piVar10;
  undefined1 *puVar11;
  uint uStack_5c;
  int local_58;
  int iStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int local_44;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  uint uStack_24;
  undefined1 local_1c [16];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&uStack_5c;
  local_44 = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  pcVar4 = WaitForSingleObject_exref;
  puVar9 = (undefined1 *)0x0;
  local_58 = 0;
  DVar7 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),0);
  while (DVar7 != 0) {
    piVar10 = *(int **)(param_1 + 0x10);
    puVar11 = local_1c;
    (**(code **)(*piVar10 + 100))(piVar10,puVar11,0);
    puVar5 = unaff_ESI;
    while (uStack_24 < 2) {
      local_58 = *(int *)(param_1 + 0x28);
      iStack_54 = *(int *)(param_1 + (int)puVar9 * 4);
      iVar2 = *(int *)(param_1 + 0x24);
      FUN_1001de50(local_58);
      param_1 = iStack_50;
      uVar3 = *(uint *)(iVar2 + 0x1044);
      iVar2 = *(int *)(iVar2 + 0x18);
      iVar8 = 0;
      uStack_5c = 0;
      if (uVar3 != 0) {
        uVar6 = uStack_5c;
        do {
          for (; uVar6 < uVar3 * local_58; uVar6 = uVar6 + uVar3) {
            iVar1 = iVar8 * 4;
            iVar8 = iVar8 + 1;
            *(undefined4 *)(iStack_54 + uVar6 * 4) = *(undefined4 *)(iVar2 + iVar1);
          }
          uStack_5c = uStack_5c + 1;
          uVar6 = uStack_5c;
        } while (uStack_5c < uVar3);
      }
      uStack_4c = 0;
      uStack_48 = *(undefined4 *)(iStack_50 + 0x2c);
      local_44 = *(int *)(iStack_50 + (int)unaff_ESI * 4);
      uStack_40 = 0;
      uStack_38 = 0;
      uStack_30 = 0;
      (**(code **)(**(int **)(iStack_50 + 0x10) + 0x54))(*(int **)(iStack_50 + 0x10),&uStack_4c,0);
      puVar9 = (undefined1 *)0x0;
      if ((int)(unaff_ESI + 1) < 2) {
        puVar9 = unaff_ESI + 1;
      }
      puVar11 = puVar9;
      (**(code **)(**(int **)(param_1 + 0x10) + 100))
                (*(int **)(param_1 + 0x10),(int)&uStack_38 + 4,0);
      puVar5 = puVar9;
      pcVar4 = WaitForSingleObject_exref;
    }
    (*pcVar4)(*(undefined4 *)(param_1 + 0x14),0xffffffff,piVar10,puVar11);
    DVar7 = (*pcVar4)(*(undefined4 *)(param_1 + 0x18),0);
    unaff_ESI = puVar5;
  }
  __security_check_cookie(local_c ^ (uint)&uStack_5c);
  return;
}

