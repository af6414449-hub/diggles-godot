
void FUN_0040e1f0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  float *pfVar12;
  int in_ECX;
  undefined4 *puVar13;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9a90;
  local_10 = ExceptionList;
  uVar8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00608940(*(undefined4 *)(*(int *)(in_ECX + 4) + 0xdc));
  fVar1 = *(float *)(in_ECX + 0x3c);
  fVar2 = *(float *)(in_ECX + 0x38);
  fVar3 = *(float *)(in_ECX + 0x34);
  uVar4 = (uint)ROUND(fVar2 * 8.0);
  DAT_00772dd8 = (uint)ROUND(fVar3 * 8.0);
  uVar9 = DAT_00772dd8 & 7;
  iVar10 = FUN_00592f10(PTR_0077241c);
  if ((*(byte *)(((uVar4 & 7) << 3 | uVar9) + 0x3c + iVar10) & 2) == 0) {
    iVar10 = FUN_00592f10(PTR_0077241c);
    if ((*(byte *)(((uVar4 - 1 & 7) << 3 | uVar9) + 0x3c + iVar10) & 2) == 0) {
      iVar10 = FUN_00592f10(PTR_0077241c);
      if ((*(byte *)(((uVar4 + 1 & 7) << 3 | uVar9) + 0x3c + iVar10) & 2) == 0) {
        *(undefined1 *)(in_ECX + 0x58) = 1;
        goto LAB_0040e50f;
      }
    }
  }
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_0040baf0(*(int *)(in_ECX + 0x44));
  }
  puVar11 = (undefined4 *)FUN_006ba810(0x13a,uVar8);
  if (puVar11 == (undefined4 *)0x0) {
    puVar11 = (undefined4 *)0x0;
  }
  else {
    *puVar11 = 0;
    puVar11[1] = 0;
    puVar11[3] = 0xc47a0000;
  }
  *(undefined4 **)(in_ECX + 0x44) = puVar11;
  puVar11 = (undefined4 *)FUN_006ba810(0x13b);
  local_8 = 0;
  if (puVar11 == (undefined4 *)0x0) {
    puVar13 = (undefined4 *)0x0;
  }
  else {
    puVar13 = puVar11 + 1;
    *puVar11 = 2;
    _eh_vector_constructor_iterator_(puVar13,0x10,2,FUN_00405b50,guard_check_icall);
  }
  local_8 = 0xffffffff;
  puVar11 = *(undefined4 **)(in_ECX + 0x44);
  *puVar11 = puVar13;
  puVar11[1] = 2;
  *(undefined4 *)(*(int *)(in_ECX + 0x44) + 8) = 2;
  piVar5 = *(int **)(in_ECX + 0x44);
  if (piVar5[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar10 = *(int *)(in_ECX + 4);
  puVar11 = (undefined4 *)*piVar5;
  *puVar11 = *(undefined4 *)(iVar10 + 0xc);
  puVar11[1] = *(undefined4 *)(iVar10 + 0x10);
  puVar11[2] = *(undefined4 *)(iVar10 + 0x14);
  piVar5 = *(int **)(in_ECX + 0x44);
  if (piVar5[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  *(undefined4 *)(*piVar5 + 0xc) = 2;
  piVar5 = *(int **)(in_ECX + 0x44);
  if (piVar5[1] < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pfVar12 = (float *)*piVar5;
  }
  else {
    pfVar12 = (float *)(*piVar5 + 0x10);
  }
  *pfVar12 = fVar3;
  pfVar12[1] = fVar2;
  pfVar12[2] = fVar1;
  piVar5 = *(int **)(in_ECX + 0x44);
  if (piVar5[1] < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar10 = *piVar5;
  }
  else {
    iVar10 = *piVar5 + 0x10;
  }
  *(undefined4 *)(iVar10 + 0xc) = 2;
  if (*(undefined4 **)(in_ECX + 0x48) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x48))(1);
  }
  puVar11 = (undefined4 *)FUN_006ba810(0x144);
  if (puVar11 == (undefined4 *)0x0) {
    puVar11 = (undefined4 *)0x0;
  }
  else {
    puVar11[3] = 0;
    puVar11[4] = 0;
    *puVar11 = CAct_WalkAnim::vftable;
    puVar11[0x12] = 0;
    puVar11[0x11] = 0;
    puVar11[0x10] = 0;
    puVar11[0x15] = 0;
    puVar11[0x14] = 0;
    puVar11[0x13] = 0;
    puVar11[0x16] = 0;
  }
  uVar6 = *(undefined4 *)(in_ECX + 0x44);
  *(undefined4 **)(in_ECX + 0x48) = puVar11;
  uVar7 = *(undefined4 *)(in_ECX + 4);
  iVar10 = *(int *)(in_ECX + 0xc);
  if (iVar10 != 0) {
    LOCK();
    *(int *)(iVar10 + 4) = *(int *)(iVar10 + 4) + 1;
    UNLOCK();
  }
  FUN_00419130(iVar10,uVar7,uVar6,0,0);
LAB_0040e50f:
  *(undefined4 *)(in_ECX + 0x50) = 6;
  ExceptionList = local_10;
  return;
}

