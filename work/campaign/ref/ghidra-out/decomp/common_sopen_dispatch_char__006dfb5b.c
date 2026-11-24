
/* Library Function - Single Match
    int __cdecl common_sopen_dispatch<char>(char const * const,int,int,int,int * const,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_sopen_dispatch<char>
          (char *param_1,int param_2,int param_3,int param_4,int *param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763540,0x10);
  piVar1 = *(int **)(unaff_EBP + 0x18);
  if (((piVar1 == (int *)0x0) || (*piVar1 = -1, *(int *)(unaff_EBP + 8) == 0)) ||
     ((*(int *)(unaff_EBP + 0x1c) != 0 && ((*(uint *)(unaff_EBP + 0x14) & 0xfffffe7f) != 0)))) {
    piVar1 = __errno();
    iVar2 = 0x16;
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar2 = __sopen_nolock((int *)(unaff_EBP + -0x20),piVar1,*(char **)(unaff_EBP + 8),
                           *(int *)(unaff_EBP + 0xc),*(int *)(unaff_EBP + 0x10),
                           *(int *)(unaff_EBP + 0x14),*(int *)(unaff_EBP + 0x1c));
    *(int *)(unaff_EBP + -0x1c) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006dfbf0();
    if (iVar2 != 0) {
      *piVar1 = -1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar2;
}

