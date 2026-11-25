
void FUN_00599fc0(void)

{
  byte bVar1;
  int iVar2;
  FILE *_File;
  int *piVar3;
  uint *puVar4;
  char *in_ECX;
  int *in_EDX;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
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
    iVar7 = local_20 * local_24;
    thunk_FUN_0060fc30(*in_EDX);
    in_EDX[1] = iVar7;
    iVar7 = FUN_006ba810(0x5e);
    *in_EDX = iVar7;
    local_1c = 0;
    iVar7 = local_20;
    iVar5 = local_24;
    pcVar6 = RaiseException_exref;
    if (0 < local_20) {
      do {
        iVar8 = 0;
        if (0 < iVar5) {
          do {
            iVar7 = local_1c * iVar5 + iVar8;
            if ((iVar7 < 0) || (local_c <= iVar7)) {
              (*pcVar6)(0xc000008c,1,0,0);
              piVar3 = local_18;
              iVar5 = local_24;
            }
            else {
              piVar3 = local_18 + iVar7;
            }
            iVar7 = *piVar3;
            iVar2 = *(int *)(DAT_0077241c + 0x24);
            if ((iVar7 < 0) || (*(int *)(iVar2 + 0x14) <= iVar7)) {
              (*pcVar6)(0xc000008c,1,0,0);
              iVar7 = *(int *)(iVar2 + 0x10);
              iVar5 = local_24;
            }
            else {
              iVar7 = iVar7 * 0x59 + *(int *)(iVar2 + 0x10);
            }
            bVar1 = *(byte *)(iVar7 + 0x1b);
            iVar7 = local_1c * iVar5 + iVar8;
            if ((iVar7 < 0) || (local_14[1] <= iVar7)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar4 = (uint *)*local_14;
            }
            else {
              puVar4 = (uint *)(*local_14 + iVar7 * 4);
            }
            *puVar4 = (uint)((bVar1 & 0xf) == 0xb);
            iVar8 = iVar8 + 1;
            iVar7 = local_20;
            iVar5 = local_24;
            pcVar6 = RaiseException_exref;
          } while (iVar8 < local_24);
        }
        local_1c = local_1c + 1;
      } while (local_1c < iVar7);
    }
    thunk_FUN_0060fc30(local_18);
    thunk_FUN_0060fc30(local_10);
  }
  return;
}

