
/* Library Function - Single Match
    int __cdecl common_fseek(class __crt_stdio_stream,__int64,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_fseek(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763380,0xc);
  if ((*(int *)(unaff_EBP + 8) == 0) ||
     (((iVar2 = *(int *)(unaff_EBP + 0x14), iVar2 != 0 && (iVar2 != 1)) && (iVar2 != 2)))) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    iVar2 = -1;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
    __lock_file(*(FILE **)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar2 = common_fseek_nolock(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                                *(undefined4 *)(unaff_EBP + 0x10),iVar2);
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006daa7d();
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar2;
}

