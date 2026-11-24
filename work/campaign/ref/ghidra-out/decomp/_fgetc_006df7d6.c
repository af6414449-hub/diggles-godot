
/* Library Function - Single Match
    _fgetc
   
   Library: Visual Studio 2019 Release */

int __cdecl _fgetc(FILE *_File)

{
  FILE *_File_00;
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007634e0,0x10);
  _File_00 = *(FILE **)(unaff_EBP + 8);
  *(FILE **)(unaff_EBP + -0x20) = _File_00;
  if (_File_00 == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    __lock_file(_File_00);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (((uint)_File_00->_flag >> 0xc & 1) != 0) {
LAB_006df8a7:
      iVar2 = __fgetc_nolock(_File_00);
      *(int *)(unaff_EBP + -0x1c) = iVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
      FUN_006df8d4();
      goto LAB_006df8c1;
    }
    uVar3 = __fileno(_File_00);
    if ((uVar3 == 0xffffffff) || (uVar3 == 0xfffffffe)) {
      puVar5 = &DAT_007672e0;
    }
    else {
      puVar5 = (undefined *)((uVar3 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar3 >> 6]);
    }
    puVar4 = &DAT_007672e0;
    if (puVar5[0x29] == '\0') {
      if ((uVar3 != 0xffffffff) && (uVar3 != 0xfffffffe)) {
        puVar4 = (undefined *)((uVar3 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar3 >> 6]);
      }
      if ((puVar4[0x2d] & 1) == 0) goto LAB_006df8a7;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    FUN_006d1670(&DAT_0076700c,unaff_EBP + -0x10,0xfffffffe);
  }
  iVar2 = -1;
LAB_006df8c1:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar2;
}

