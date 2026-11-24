
/* Library Function - Single Match
    long __cdecl common_ftell<long>(class __crt_stdio_stream)
   
   Library: Visual Studio 2019 Release */

long __cdecl common_ftell<long>(void)

{
  int *piVar1;
  long lVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007634a0,0xc);
  if (*(int *)(unaff_EBP + 8) == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    lVar2 = -1;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    __lock_file(*(FILE **)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    lVar2 = common_ftell_nolock<long>(*(undefined4 *)(unaff_EBP + 8));
    *(long *)(unaff_EBP + -0x1c) = lVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006de383();
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return lVar2;
}

