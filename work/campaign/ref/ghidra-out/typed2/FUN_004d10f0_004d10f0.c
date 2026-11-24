
uint FUN_004d10f0(float param_1,float param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  float local_20;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fee70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar8 = *(int *)(in_ECX + 0x14);
  uVar9 = 0;
  local_14 = 0xffffffff;
  local_20 = 3.4028235e+38;
  if (0 < iVar8) {
    local_18 = 0;
    do {
      if (*(uint *)(in_ECX + 0x14) <= uVar9) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar13 = *(float *)(local_18 + 4 + *(int *)(in_ECX + 0x10));
      fVar12 = *(float *)(local_18 + 8 + *(int *)(in_ECX + 0x10));
      if ((((fVar13 < PTR_0077241c->x0f + 4.0) || (PTR_0077241c->x1f - 4.0 <= fVar13)) ||
          (fVar12 < PTR_0077241c->y0f + 4.0)) || (PTR_0077241c->y1f - 4.0 <= fVar12)) {
        if ((*(uint *)(in_ECX + 0x14) <= uVar9) &&
           (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0), *(uint *)(in_ECX + 0x14) <= uVar9)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_8 = 0;
        piVar3 = *(int **)(*(int *)(in_ECX + 0x10) + 0x14 + local_18);
        if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
          FUN_006ba940();
        }
        local_8 = 0xffffffff;
        iVar8 = *(int *)(in_ECX + 0x14);
        if ((int)uVar9 < iVar8 + -1) {
          iVar8 = *(int *)(in_ECX + 0x10);
          iVar4 = *(int *)(in_ECX + 0x14);
          puVar2 = (undefined4 *)(iVar8 + -0x18 + iVar4 * 0x18);
          uVar5 = puVar2[1];
          uVar6 = puVar2[2];
          uVar7 = puVar2[3];
          puVar1 = (undefined4 *)(local_18 + iVar8);
          *puVar1 = *puVar2;
          puVar1[1] = uVar5;
          puVar1[2] = uVar6;
          puVar1[3] = uVar7;
          *(undefined8 *)(local_18 + 0x10 + iVar8) = *(undefined8 *)(iVar8 + -8 + iVar4 * 0x18);
          iVar8 = *(int *)(in_ECX + 0x14);
        }
        uVar9 = uVar9 - 1;
        *(int *)(in_ECX + 0x14) = iVar8 + -1;
        local_18 = local_18 + -0x18;
      }
      iVar8 = *(int *)(in_ECX + 0x14);
      uVar9 = uVar9 + 1;
      local_18 = local_18 + 0x18;
    } while ((int)uVar9 < iVar8);
  }
  uVar10 = 0;
  uVar9 = 0xffffffff;
  if (0 < iVar8) {
    bVar11 = *(int *)(in_ECX + 0x14) != 0;
    local_18 = 0;
    do {
      if (!bVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      fVar13 = *(float *)(local_18 + 4 + *(int *)(in_ECX + 0x10));
      fVar12 = *(float *)(local_18 + 8 + *(int *)(in_ECX + 0x10));
      if ((0.0 < fVar13) && (0.0 < fVar12)) {
        fVar12 = fVar12 - param_2;
        fVar13 = fVar13 - param_1;
        fVar13 = fVar12 * fVar12 + fVar13 * fVar13;
        FUN_0040b7e0();
        if (*(uint *)(in_ECX + 0x14) <= uVar10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar8 = *(int *)(in_ECX + 0x10);
        if (fVar13 < *(float *)(local_18 + 0x10 + iVar8)) {
          if (*(uint *)(in_ECX + 0x14) <= uVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar8 = *(int *)(in_ECX + 0x10);
          }
          if (((100.0 < *(float *)(local_18 + 0x10 + iVar8)) ||
              (iVar8 = FUN_005ab220(*(undefined4 *)(DAT_00772400 + 100)), 0 < iVar8)) &&
             (fVar13 < local_20)) {
            local_20 = fVar13;
            local_14 = uVar10;
          }
        }
      }
      local_18 = local_18 + 0x18;
      uVar10 = uVar10 + 1;
      bVar11 = uVar10 < *(uint *)(in_ECX + 0x14);
      uVar9 = local_14;
    } while ((int)uVar10 < (int)*(uint *)(in_ECX + 0x14));
  }
  ExceptionList = local_10;
  return uVar9;
}

