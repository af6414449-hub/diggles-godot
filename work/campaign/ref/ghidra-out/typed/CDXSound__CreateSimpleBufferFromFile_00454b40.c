
int __thiscall CDXSound__CreateSimpleBufferFromFile(CDXSound *this)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  FILE *_File;
  CDXSound *extraout_ECX;
  CDXSound *this_00;
  undefined4 extraout_ECX_00;
  size_t _ElementSize;
  undefined8 uVar6;
  char *in_stack_00000004;
  long local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fc76d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c86be0) {
    FUN_006cebf4(&DAT_00c86be0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar4 = DAT_00783650;
    if (DAT_00c86be0 == -1) {
      iVar5 = DAT_00783650 * 0x40;
      DAT_00c86be4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar5) =
           "CDXSound::CreateSimpleBufferFromFile(const char* pcFilename)";
      *(int *)(&DAT_00773650 + iVar5) = iVar4;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c86be0);
    }
  }
  iVar5 = DAT_00c86be4;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00c86be4 * 0x40);
  iVar4 = FUN_0043fcc0();
  this_00 = *(CDXSound **)(iVar4 + 0x8000);
  *(undefined4 *)(iVar4 + (int)this_00 * 4) = uVar2;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar4 == 0) {
    uVar6 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar6;
    this_00 = extraout_ECX;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
  local_8 = 0;
  cVar3 = CDXSound__GetFileFormat(this_00);
  if (cVar3 != '\0') {
    iVar4 = FUN_00454470(local_20,local_1c,local_18,local_14,extraout_ECX_00);
    if (iVar4 != 0) {
      FUN_006b9200(in_stack_00000004);
      piVar1 = (int *)(iVar4 + 0x50);
      _ElementSize = (int)((local_18 * local_14 >> 0x1f & 7U) + local_18 * local_14) >> 3;
      if (*piVar1 == 0) {
        iVar5 = (**(code **)(**(int **)(iVar4 + 0x38) + 0x2c))
                          (*(int **)(iVar4 + 0x38),0,_ElementSize,piVar1,iVar4 + 0x54,iVar4 + 0x58,
                           iVar4 + 0x5c,0);
        if (-1 < iVar5) {
          _File = _fopen(in_stack_00000004,"rb");
          _fseek(_File,local_24,0);
          _fread((void *)*piVar1,_ElementSize,1,_File);
          _fclose(_File);
          if (*piVar1 != 0) {
            (**(code **)(**(int **)(iVar4 + 0x38) + 0x4c))
                      (*(int **)(iVar4 + 0x38),*piVar1,*(undefined4 *)(iVar4 + 0x54),
                       *(undefined4 *)(iVar4 + 0x58),*(undefined4 *)(iVar4 + 0x5c));
            *piVar1 = 0;
          }
          goto LAB_00454cc9;
        }
      }
      FUN_00454330(iVar4);
    }
  }
  iVar4 = 0;
LAB_00454cc9:
  FUN_0043fd30();
  ExceptionList = local_10;
  return iVar4;
}

