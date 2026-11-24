
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050e2a0(ViWinDigButtons *this)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_24;
  float local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701471;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c9337c) {
    FUN_006cebf4(&DAT_00c9337c,DAT_0076700c ^ (uint)&stack0xfffffffc);
    if (DAT_00c9337c == -1) {
      local_8 = 0;
      if (DAT_00772400 != 0) {
        FUN_00565700(&DAT_007688f8);
        iVar5 = _rand();
        _DAT_007688f8 = (double)iVar5 * _DAT_00768900 * 3.0517578125e-05;
      }
      _atexit(FUN_007140d0);
      local_8 = 0xffffffff;
      FUN_006cebaa(&DAT_00c9337c);
    }
  }
  cVar3 = FUN_00565940();
  if (cVar3 != '\0') {
    iVar5 = DAT_0077244c + 0x84e4;
    uVar1 = *(int *)(DAT_00772400 + 100) + 1;
    iVar4 = (*(int *)(DAT_00772400 + 100) + 1) * 0x808;
    if (uVar1 < 9) {
      iVar5 = iVar5 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_1c = 0.0;
    if (*(uint *)(DAT_00772400 + 0xa3c0) < 0x200) {
      local_24 = *(float *)(iVar5 + *(uint *)(DAT_00772400 + 0xa3c0) * 4);
    }
    else {
      local_24 = 0.0;
    }
    iVar5 = DAT_0077244c + 0x84e4;
    if (uVar1 < 9) {
      iVar5 = iVar5 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    fVar6 = 0.0;
    if (*(uint *)(DAT_00772400 + 0xa3c4) < 0x200) {
      fVar6 = *(float *)(iVar5 + *(uint *)(DAT_00772400 + 0xa3c4) * 4);
    }
    iVar5 = DAT_0077244c + 0x84e4;
    if (uVar1 < 9) {
      iVar5 = iVar5 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*(uint *)(DAT_00772400 + 0xa3c8) < 0x200) {
      fVar7 = *(float *)(iVar5 + *(uint *)(DAT_00772400 + 0xa3c8) * 4);
    }
    else {
      fVar7 = 0.0;
    }
    iVar5 = DAT_0077244c + 0x84e4;
    if (uVar1 < 9) {
      iVar5 = iVar5 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*(uint *)(DAT_00772400 + 0xa3cc) < 0x200) {
      fVar8 = *(float *)(iVar5 + *(uint *)(DAT_00772400 + 0xa3cc) * 4);
    }
    else {
      fVar8 = 0.0;
    }
    iVar5 = DAT_0077244c + 0x84e4;
    if (uVar1 < 9) {
      iVar5 = iVar5 + iVar4;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*(uint *)(DAT_00772400 + 0xa3d0) < 0x200) {
      local_1c = *(float *)(iVar5 + *(uint *)(DAT_00772400 + 0xa3d0) * 4);
    }
    if (0.5 <= local_24 != (bool)*(char *)(this->i_44 + 0x1c)) {
      *(bool *)(this->i_44 + 0x1c) = 0.5 <= local_24;
      FUN_00504ee0();
    }
    if (0.5 <= fVar6 != (bool)*(char *)(this->i_48 + 0x1c)) {
      *(bool *)(this->i_48 + 0x1c) = 0.5 <= fVar6;
      FUN_00504ee0();
    }
    if (0.5 <= fVar7 != (bool)*(char *)(this->i_4c + 0x1c)) {
      *(bool *)(this->i_4c + 0x1c) = 0.5 <= fVar7;
      FUN_00504ee0();
    }
    if (0.5 <= fVar8 != (bool)*(char *)(this->i_50 + 0x1c)) {
      *(bool *)(this->i_50 + 0x1c) = 0.5 <= fVar8;
      FUN_00504ee0();
    }
    if (0.5 <= local_1c != (bool)*(char *)(this->i_54 + 0x1c)) {
      *(bool *)(this->i_54 + 0x1c) = 0.5 <= local_1c;
      FUN_00504ee0();
    }
    bVar2 = 0.5 < fVar6 + local_24 + fVar7 + fVar8 + local_1c;
    if (bVar2 != (bool)*(char *)(this->i_58 + 0x1c)) {
      *(bool *)(this->i_58 + 0x1c) = bVar2;
      FUN_00504ee0();
    }
    FUN_00504ee0();
  }
  ExceptionList = local_10;
  return;
}

