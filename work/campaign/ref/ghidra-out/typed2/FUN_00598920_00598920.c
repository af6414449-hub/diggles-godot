
void FUN_00598920(void)

{
  int *piVar1;
  CMap *pCVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int extraout_ECX;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uVar9;
  int iVar10;
  undefined4 uVar11;
  int local_24;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  pCVar2 = PTR_0077241c;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_0070692d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  uVar7 = 0;
  if (0 < *(int *)(PTR_0077241c + 1)) {
    bVar8 = *(int *)(PTR_0077241c + 1) != 0;
    local_24 = 0;
    do {
      if (!bVar8) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar1 = (int *)(local_24 + 4 + pCVar2->mapFlags5);
      *piVar1 = *piVar1 + -1;
      if (*(uint *)(pCVar2 + 1) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*(int *)(local_24 + 4 + pCVar2->mapFlags5) < 1) {
        uVar6 = *(uint *)(pCVar2 + 1);
        if (uVar6 <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar6 = *(uint *)(pCVar2 + 1);
          if (uVar6 <= uVar7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar6 = *(uint *)(pCVar2 + 1);
          }
        }
        if ((int)uVar7 < (int)(uVar6 - 1)) {
          iVar5 = local_24 + pCVar2->mapFlags5;
          FUN_006d1b90(iVar5,iVar5 + 0x14,(uVar6 - uVar7) * 0x14 + -0x14);
          uVar6 = *(uint *)(pCVar2 + 1);
        }
        uVar7 = uVar7 - 1;
        *(uint *)(pCVar2 + 1) = uVar6 - 1;
        local_24 = local_24 + -0x14;
      }
      uVar7 = uVar7 + 1;
      in_ECX = local_24 + 0x14;
      bVar8 = uVar7 < *(uint *)(pCVar2 + 1);
      local_24 = in_ECX;
    } while ((int)uVar7 < (int)*(uint *)(pCVar2 + 1));
  }
  if ((*(char *)(DAT_00772400 + 0x98) != '\0') &&
     ((*(char *)(DAT_00772400 + 0x590) == '\0' || (*(char *)(DAT_00772400 + 0x99) != '\0')))) {
    iVar5 = FUN_0057d980();
                    /* WARNING: Load size is inaccurate */
    if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5470) {
      FUN_006cebf4(&DAT_00ca5470);
      iVar3 = DAT_00783650;
      if (DAT_00ca5470 == -1) {
        iVar4 = DAT_00783650 * 0x40;
        DAT_00ca5474 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar4) = "CFluid::Tick()";
        *(int *)(&DAT_00773650 + iVar4) = iVar3;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca5470);
      }
    }
    iVar4 = DAT_00ca5474;
    uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca5474 * 0x40);
    iVar3 = FUN_0043fcc0();
    *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar11;
    *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    if (iVar3 == 0) {
      uVar9 = FUN_006bd180();
      iVar3 = (&DAT_00773654)[iVar4 * 0x10];
      *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
    }
    (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
    local_14 = 0;
    *(int *)(iVar5 + 0xc70) = *(int *)(iVar5 + 0xc6c);
    *(int *)(iVar5 + 0xc6c) = 1 - *(int *)(iVar5 + 0xc6c);
    FUN_0057adf0();
    FUN_0057a1c0();
    if (*(char *)(iVar5 + 8) == '\0') {
      FUN_00578c80();
      FUN_005791a0();
    }
    *(undefined1 *)(iVar5 + 8) = 0;
    local_14 = 0xffffffff;
    FUN_0043fd30();
    in_ECX = extraout_ECX;
  }
  if (DAT_0076839a == '\0') {
    if (*(char *)(DAT_0076a338 + 0x38d9) != '\0') {
      iVar5 = pCVar2->x0_8;
      iVar3 = pCVar2->y0_8;
      iVar4 = pCVar2->x1_8;
      iVar10 = pCVar2->y1_8;
      uVar11 = 0x10;
      FUN_005a3dd0(in_ECX,iVar5,iVar3,iVar4,iVar10,0x10);
      FUN_005a3fd0(iVar5,iVar3,iVar4,iVar10,uVar11);
      *(undefined1 *)(DAT_0076a338 + 0x38d9) = 0;
    }
  }
  else if (*(char *)(DAT_0076a338 + 0x38d9) == '\0') {
    iVar5 = pCVar2->x0_8;
    iVar3 = pCVar2->y0_8;
    iVar4 = pCVar2->x1_8;
    iVar10 = pCVar2->y1_8;
    uVar11 = 0x10;
    FUN_005a3dd0(in_ECX,iVar5,iVar3,iVar4,iVar10,0x10);
    FUN_005a3fd0(iVar5,iVar3,iVar4,iVar10,uVar11);
    *(undefined1 *)(DAT_0076a338 + 0x38d9) = 1;
    ExceptionList = local_1c;
    return;
  }
  ExceptionList = local_1c;
  return;
}

