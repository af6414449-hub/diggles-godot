
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00509570(ViWinChat *this)

{
  double dVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined1 *puVar7;
  int *piVar8;
  code *pcVar9;
  uint uVar10;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701111;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c93378) {
    FUN_006cebf4(&DAT_00c93378,DAT_0076700c ^ (uint)&stack0xfffffffc);
    if (DAT_00c93378 == -1) {
      local_8 = 0;
      if (DAT_00772400 != 0) {
        FUN_00565700(&DAT_007688e0);
        iVar3 = _rand();
        _DAT_007688e0 = (double)iVar3 * _DAT_007688e8 * 3.0517578125e-05;
      }
      _atexit(FUN_00714070);
      local_8 = 0xffffffff;
      FUN_006cebaa(&DAT_00c93378);
    }
  }
  cVar2 = FUN_00565940();
  if (cVar2 != '\0') {
    iVar3 = FUN_00501450();
    if ((*(int *)(iVar3 + 0x81a8) == 0) || (*(int *)(*(int *)(iVar3 + 0x81a8) + 0xb0) != 7)) {
      puVar7 = &this->field_0x48;
      uVar10 = 0;
      local_14 = 0;
      dVar1 = *(double *)(DAT_00772400 + 0xa088);
      pcVar9 = RaiseException_exref;
      do {
        if (uVar10 < 8) {
          puVar4 = puVar7 + local_14;
        }
        else {
          (*pcVar9)(0xc000008c,1,0,0);
          puVar4 = puVar7;
        }
        if (*(double *)(puVar4 + 8) + 10.0 < dVar1) {
          if (uVar10 < 8) {
            piVar8 = (int *)(puVar7 + local_14);
          }
          else {
            (*pcVar9)(0xc000008c,1,0,0);
            piVar8 = (int *)puVar7;
          }
          iVar3 = *piVar8;
          if (iVar3 != 0) {
            *(undefined1 *)(iVar3 + 0x2d) = 1;
            iVar5 = FUN_00501450();
            if ((*(int *)(iVar5 + 0x81a0) != 0) && (*(int *)(iVar5 + 0x81a0) == iVar3)) {
              iVar3 = FUN_00501450();
              *(undefined4 *)(iVar3 + 0x81a0) = 0;
            }
            *piVar8 = 0;
          }
          *(undefined1 *)(piVar8 + 1) = 0;
          pcVar9 = RaiseException_exref;
        }
        uVar10 = uVar10 + 1;
        local_14 = local_14 + 0x10;
      } while ((int)uVar10 < 8);
      iVar3 = FUN_005b28d0();
      if (*(int *)(iVar3 + 0x10c) != 0) {
        uVar6 = extraout_ECX;
        if (*(int *)(iVar3 + 0x10c) == 0) {
          (*pcVar9)(0xc000008c,1,0,0);
          uVar6 = extraout_ECX_00;
        }
        piVar8 = *(int **)(*(int *)(iVar3 + 0x108) + 4);
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
        }
        local_8 = 1;
        if (*(int *)(iVar3 + 0x10c) == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar6 = extraout_ECX_01;
        }
        uVar10 = **(uint **)(iVar3 + 0x108);
        FUN_0050a1c0(uVar6);
        iVar3 = DAT_00772400 + 0xa5c0;
        if (uVar10 < 8) {
          iVar3 = iVar3 + uVar10 * 4;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
        }
        uVar6 = FUN_00509bf0(piVar8,1,iVar3);
        local_8._0_1_ = 2;
        FUN_00509970(uVar6,iVar3);
        local_8 = CONCAT31(local_8._1_3_,3);
        if ((puVar7 != (undefined1 *)0x0) &&
           (*(int *)puVar7 = *(int *)puVar7 + -1, *(int *)puVar7 == 0)) {
          FUN_006ba940();
        }
        local_8 = 4;
        if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
          FUN_006ba940();
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

