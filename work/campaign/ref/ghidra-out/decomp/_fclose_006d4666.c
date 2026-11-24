
/* Library Function - Single Match
    _fclose
   
   Library: Visual Studio 2019 Release */

int __cdecl _fclose(FILE *_File)

{
  FILE *_File_00;
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007632c0,0x10);
  _File_00 = *(FILE **)(unaff_EBP + 8);
  *(FILE **)(unaff_EBP + -0x20) = _File_00;
  if (_File_00 == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    if (((uint)_File_00->_flag >> 0xc & 1) == 0) {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      __lock_file(_File_00);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar2 = __fclose_nolock(_File_00);
      *(int *)(unaff_EBP + -0x1c) = iVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
      FUN_006d46e0();
      goto LAB_006d46cd;
    }
    __acrt_stdio_free_stream();
  }
  iVar2 = -1;
LAB_006d46cd:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar2;
}

