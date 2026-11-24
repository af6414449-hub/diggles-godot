
void FUN_0057e710(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  uint *in_ECX;
  uint uVar10;
  uint *puVar11;
  undefined8 uVar12;
  int iVar13;
  undefined4 uVar14;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070613d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5488) &&
     (FUN_006cebf4(&DAT_00ca5488,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca5488 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca548c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "void CFogOfWar::FadeBlocks(int iPlayer)";
    *(int *)(&DAT_00773650 + iVar9) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5488);
  }
  iVar9 = DAT_00ca548c;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca548c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar14;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar4 + 1;
  local_8 = 0;
  if ((PTR_0077241c != (CMap *)0x0) && ((char)PTR_0077241c->mapFlags != '\0')) {
    local_18 = 0;
    uVar1 = *in_ECX;
    puVar11 = in_ECX + 0xb;
    uVar2 = in_ECX[1];
    if (param_1 < 8) {
      puVar11 = puVar11 + param_1 * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_005a9090();
    uVar3 = puVar11[1];
    while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
      uVar5 = puVar11[1];
      if (uVar5 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar5 = puVar11[1];
      }
      uVar10 = *puVar11;
      iVar4 = *(int *)(uVar10 + uVar3 * 8);
      if (uVar5 <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar10 = *puVar11;
      }
      iVar9 = *(int *)(uVar10 + 4 + uVar3 * 8);
      if ((((iVar4 < PTR_0077241c->cellX0) || (PTR_0077241c->cellX1 <= iVar4)) ||
          (iVar9 < PTR_0077241c->cellY0)) || (PTR_0077241c->cellY1 <= iVar9)) {
        FUN_00581090(uVar3);
      }
      else {
        local_18 = local_18 + 1;
        iVar6 = FUN_00592f10(PTR_0077241c);
        pbVar7 = (byte *)(iVar6 + 0x34);
        if (param_1 < 8) {
          pbVar8 = pbVar7 + param_1;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pbVar8 = pbVar7;
        }
        local_20 = *pbVar8 - 4;
        if ((int)local_20 < 0xe3) {
          if ((int)local_20 < 2) {
            local_20 = 1;
            FUN_00581090(uVar3);
          }
          else if (((0x7b < (int)local_20) && (uVar1 == param_1)) &&
                  (((local_20 & 0xfffffffc) == 0x7c || ((int)uVar2 % 5 == 0)))) {
            uVar14 = 0x50;
            iVar6 = iVar4 * 8 + -8;
            iVar13 = iVar9 * 8 + 8;
            iVar9 = iVar9 * 8 + -8;
            iVar4 = iVar4 * 8 + 8;
            FUN_005a3dd0(iVar6,iVar9,iVar4,iVar13,0x50);
            FUN_005a3fd0(iVar6,iVar9,iVar4,iVar13,uVar14);
          }
        }
        if (param_1 < 8) {
          pbVar7[param_1] = (byte)local_20;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          *pbVar7 = (byte)local_20;
        }
      }
    }
    in_ECX[param_1 + 0x1b] = local_18;
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

