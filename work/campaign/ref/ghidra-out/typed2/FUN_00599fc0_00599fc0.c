
void FUN_00599fc0(void)

{
  byte bVar1;
  CHeightBlockArray *pCVar2;
  FILE *_File;
  int *piVar3;
  CHeightBlock *pCVar4;
  uint *puVar5;
  char *in_ECX;
  int *in_EDX;
  int iVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  int local_c;
  
  local_14 = in_EDX;
  _File = _fopen(in_ECX,"rb");
  if (_File != (FILE *)0x0) {
    _fread(&local_24,4,1,_File);
    _fread(&local_20,4,1,_File);
    thunk_FUN_0060fc30(0);
    local_10 = (void *)FUN_006ba810(0x5e);
    local_c = local_20 * local_24;
    thunk_FUN_0060fc30(0);
    piVar3 = (int *)FUN_006ba810(0x5e);
    local_18 = piVar3;
    _fread(local_10,local_20 * local_24,1,_File);
    _fread(piVar3,local_20 * local_24,4,_File);
    _fclose(_File);
    iVar8 = local_20 * local_24;
    thunk_FUN_0060fc30(*in_EDX);
    in_EDX[1] = iVar8;
    iVar8 = FUN_006ba810(0x5e);
    *in_EDX = iVar8;
    local_1c = 0;
    iVar8 = local_20;
    iVar6 = local_24;
    pcVar7 = RaiseException_exref;
    if (0 < local_20) {
      do {
        iVar9 = 0;
        if (0 < iVar6) {
          do {
            iVar8 = local_1c * iVar6 + iVar9;
            if ((iVar8 < 0) || (local_c <= iVar8)) {
              (*pcVar7)(0xc000008c,1,0,0);
              piVar3 = local_18;
              iVar6 = local_24;
            }
            else {
              piVar3 = local_18 + iVar8;
            }
            iVar8 = *piVar3;
            pCVar2 = PTR_0077241c->heightBlocks;
            if ((iVar8 < 0) || (pCVar2->count <= iVar8)) {
              (*pcVar7)(0xc000008c,1,0,0);
              pCVar4 = pCVar2->data;
              iVar6 = local_24;
            }
            else {
              pCVar4 = pCVar2->data + iVar8;
            }
            bVar1 = pCVar4->heights[0x1b];
            iVar8 = local_1c * iVar6 + iVar9;
            if ((iVar8 < 0) || (local_14[1] <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar5 = (uint *)*local_14;
            }
            else {
              puVar5 = (uint *)(*local_14 + iVar8 * 4);
            }
            *puVar5 = (uint)((bVar1 & 0xf) == 0xb);
            iVar9 = iVar9 + 1;
            iVar8 = local_20;
            iVar6 = local_24;
            pcVar7 = RaiseException_exref;
          } while (iVar9 < local_24);
        }
        local_1c = local_1c + 1;
      } while (local_1c < iVar8);
    }
    thunk_FUN_0060fc30(local_18);
    thunk_FUN_0060fc30(local_10);
  }
  return;
}

