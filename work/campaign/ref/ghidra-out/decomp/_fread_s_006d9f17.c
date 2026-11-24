
/* Library Function - Single Match
    _fread_s
   
   Library: Visual Studio 2019 Release */

size_t __cdecl _fread_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File)

{
  FILE *_File_00;
  int *piVar1;
  size_t sVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763360,0xc);
  if ((*(int *)(unaff_EBP + 0x10) != 0) && (*(int *)(unaff_EBP + 0x14) != 0)) {
    _File_00 = *(FILE **)(unaff_EBP + 0x18);
    if (_File_00 != (FILE *)0x0) {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      __lock_file(_File_00);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      sVar2 = __fread_nolock_s(*(void **)(unaff_EBP + 8),*(size_t *)(unaff_EBP + 0xc),
                               *(size_t *)(unaff_EBP + 0x10),*(size_t *)(unaff_EBP + 0x14),_File_00)
      ;
      *(size_t *)(unaff_EBP + -0x1c) = sVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
      FUN_006d9fac();
      goto LAB_006d9f5d;
    }
    if (*(int *)(unaff_EBP + 0xc) != -1) {
      _memset(*(void **)(unaff_EBP + 8),0,*(size_t *)(unaff_EBP + 0xc));
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  sVar2 = 0;
LAB_006d9f5d:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return sVar2;
}

