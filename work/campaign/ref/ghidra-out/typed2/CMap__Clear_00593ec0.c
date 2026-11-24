
void __thiscall CMap__Clear(CMap *this)

{
  CMapCell **ppCVar1;
  undefined4 uVar2;
  CMap *pCVar3;
  int iVar4;
  CMapCell *pCVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pCVar3 = PTR_0077241c;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070692d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54d0) &&
     (FUN_006cebf4(&DAT_00ca54d0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca54d0 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca54d4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "CMap::Clear";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54d0);
  }
  iVar6 = DAT_00ca54d4;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca54d4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar2;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar8 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  iVar4 = pCVar3->heightBlocks->currentBlock;
  iVar6 = 0;
  if (iVar4 != -1) {
    iVar6 = iVar4;
  }
  iVar4 = 0;
  if (0 < pCVar3->mapHeight * pCVar3->mapWidth) {
    ppCVar1 = &pCVar3->cells;
    local_14 = 0;
    do {
      if ((iVar4 < 0) || (pCVar3->cellCount <= iVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        (*ppCVar1)->objectIndex = 0xffff;
        if (-1 < iVar4) goto LAB_00593fc7;
LAB_00593fd7:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        (*ppCVar1)->field_0x6 = 0xff;
        if (-1 < iVar4) goto LAB_00593ff7;
LAB_00594008:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        (*ppCVar1)->heightBlockIndex = iVar6;
        if (-1 < iVar4) goto LAB_00594029;
LAB_00594039:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        (*ppCVar1)->light = '\x04';
        if (-1 < iVar4) goto LAB_00594059;
LAB_00594064:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar5 = *ppCVar1;
      }
      else {
        pCVar5 = *ppCVar1;
        (pCVar5->ownerIndex + local_14 + -0x30)[0] = 0xff;
        (pCVar5->ownerIndex + local_14 + -0x30)[1] = 0xff;
LAB_00593fc7:
        if (pCVar3->cellCount <= iVar4) goto LAB_00593fd7;
        (*ppCVar1)->ownerIndex[local_14 + -0x2e] = 0xff;
LAB_00593ff7:
        if (pCVar3->cellCount <= iVar4) goto LAB_00594008;
        *(int *)((*ppCVar1)->ownerIndex + local_14 + -0x34) = iVar6;
LAB_00594029:
        if (pCVar3->cellCount <= iVar4) goto LAB_00594039;
        (*ppCVar1)->ownerIndex[local_14 + -0x2d] = '\x04';
LAB_00594059:
        if (pCVar3->cellCount <= iVar4) goto LAB_00594064;
        pCVar5 = (CMapCell *)((*ppCVar1)->ownerIndex + local_14 + -0x34);
      }
      _memset(&pCVar5->digMarks,0,0x74);
      iVar4 = iVar4 + 1;
      local_14 = local_14 + 0x7c;
    } while (iVar4 < pCVar3->mapHeight * pCVar3->mapWidth);
  }
  uVar7 = 0;
  do {
    if (7 < uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_00581330(0);
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 8);
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

