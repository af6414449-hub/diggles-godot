
int * FUN_004158a0(int *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 *in_ECX;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 **ppuVar12;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_006f9dd6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  local_18 = in_ECX;
  if (*(int *)(in_ECX[3] + 0x7b4) == 0) {
    ppuVar12 = &local_18;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_0059a4b0(ppuVar12);
    local_8 = (uint)local_8._1_3_ << 8;
    piVar5 = (int *)FUN_0059d440(ppuVar12);
    puVar2 = (undefined4 *)*param_1;
    iVar3 = *piVar5;
    *param_1 = iVar3;
    if (iVar3 != 0) {
      LOCK();
      *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
      UNLOCK();
    }
    if (puVar2 != (undefined4 *)0x0) {
      LOCK();
      iVar3 = puVar2[1] + -1;
      puVar2[1] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)*puVar2)();
      }
    }
    if (local_18 != (undefined4 *)0x0) {
      LOCK();
      piVar5 = local_18 + 1;
      iVar3 = *piVar5;
      *piVar5 = *piVar5 + -1;
      UNLOCK();
      if ((iVar3 == 1) && (local_18 != (undefined4 *)0x0)) {
        (**(code **)*local_18)();
      }
    }
  }
  else {
    fVar11 = *(float *)(in_ECX[1] + 0xc);
    local_8 = 3;
    if (DAT_00772424 == 0) {
      DAT_00772424 = FUN_006ba810();
    }
    local_8 = local_8 & 0xffffff00;
    DAT_00772dd8 = (int)ROUND(fVar11 * 8.0);
    FUN_005a22f0();
    puVar2 = (undefined4 *)*param_1;
    *param_1 = (int)local_14;
    if (local_14 != (undefined4 *)0x0) {
      LOCK();
      local_14[1] = local_14[1] + 1;
      UNLOCK();
    }
    if (puVar2 != (undefined4 *)0x0) {
      LOCK();
      iVar3 = puVar2[1] + -1;
      puVar2[1] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)*puVar2)();
      }
    }
    if (local_14 != (undefined4 *)0x0) {
      LOCK();
      piVar5 = local_14 + 1;
      iVar3 = *piVar5;
      *piVar5 = *piVar5 + -1;
      UNLOCK();
      if ((iVar3 == 1) && (local_14 != (undefined4 *)0x0)) {
        (**(code **)*local_14)();
      }
    }
    iVar3 = in_ECX[1];
    iVar4 = in_ECX[3];
    *(undefined4 *)(iVar4 + 0x7a4) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar4 + 0x7a8) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar4 + 0x7ac) = *(undefined4 *)(iVar3 + 0x14);
    iVar3 = *param_1;
    if (iVar3 == 0) {
      ExceptionList = local_10;
      return param_1;
    }
    uVar7 = *(uint *)(iVar3 + 0xc);
    if (0 < (int)uVar7) {
      uVar1 = uVar7 - 1;
      if (uVar7 <= uVar1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)(*(int *)(iVar3 + 8) + uVar1 * 8);
      iVar3 = *(int *)(*(int *)(iVar3 + 8) + 4 + uVar1 * 8);
      iVar6 = local_18[3];
      uVar7 = FUN_004093f0(PTR_0077241c);
      fVar8 = (float)*(int *)(iVar6 + 0x7b8);
      fVar11 = *(float *)(local_18[1] + 0x14);
      fVar10 = fVar11 - fVar8;
      fVar9 = (float)(int)(*(float *)(iVar6 + 0x7dc) + (float)((uVar7 & 0xff) + 1));
      if (fVar10 <= fVar9) {
        fVar10 = fVar9;
      }
      fVar9 = 14.5;
      if (fVar10 <= 14.5) {
        fVar9 = fVar10;
      }
      iVar6 = _rand();
      fVar11 = fVar11 + fVar8;
      if (14.5 <= fVar11) {
        fVar11 = 14.5;
      }
      *(float *)(local_18[3] + 0x7ac) = (float)iVar6 * 3.0517578e-05 * (fVar11 - fVar9) + fVar9;
      *(float *)(local_18[3] + 0x7a4) = (float)iVar4 * 0.125;
      *(float *)(local_18[3] + 0x7a8) = (float)iVar3 * 0.125;
      in_ECX = local_18;
    }
  }
  if (*param_1 != 0) {
    if (*(int *)(*param_1 + 0xc) < 1) {
      uVar7 = FUN_00416630();
      iVar3 = *param_1;
      fVar11 = *(float *)(in_ECX[3] + 0x7a4);
      fVar10 = *(float *)(in_ECX[3] + 0x7a8);
      if (*(uint *)(iVar3 + 0xc) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = *(int *)(iVar3 + 8);
      *(int *)(iVar3 + uVar7 * 8) = (int)(fVar11 * 8.0);
      *(int *)(iVar3 + 4 + uVar7 * 8) = (int)(fVar10 * 8.0);
    }
    else {
      uVar7 = FUN_00416630();
      iVar3 = *param_1;
      if (*(uint *)(iVar3 + 0xc) <= uVar7 - 1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = *(int *)(iVar3 + 8);
      iVar4 = *param_1;
      if (*(uint *)(iVar4 + 0xc) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar4 = *(int *)(iVar4 + 8);
      *(undefined4 *)(iVar4 + uVar7 * 8) = *(undefined4 *)(iVar3 + -8 + uVar7 * 8);
      *(undefined4 *)(iVar4 + 4 + uVar7 * 8) = *(undefined4 *)(iVar3 + -4 + uVar7 * 8);
    }
  }
  ExceptionList = local_10;
  return param_1;
}

