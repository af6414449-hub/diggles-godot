
/* Library Function - Single Match
    struct _iobuf * __cdecl common_fsopen<char>(char const * const,char const * const,int)
   
   Library: Visual Studio 2019 Release */

_iobuf * __cdecl common_fsopen<char>(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  int *piVar3;
  _iobuf *p_Var4;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763260,0x10);
  pcVar1 = *(char **)(unaff_EBP + 8);
  if (((pcVar1 == (char *)0x0) || (pcVar2 = *(char **)(unaff_EBP + 0xc), pcVar2 == (char *)0x0)) ||
     (*pcVar2 == '\0')) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
  }
  else if (*pcVar1 == '\0') {
    piVar3 = __errno();
    *piVar3 = 0x16;
  }
  else {
    __acrt_stdio_allocate_stream();
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      p_Var4 = (_iobuf *)
               FUN_006e5966(pcVar1,pcVar2,*(undefined4 *)(unaff_EBP + 0x10),
                            *(undefined4 *)(unaff_EBP + -0x1c));
      *(_iobuf **)(unaff_EBP + -0x20) = p_Var4;
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
      FUN_006d2864();
      goto LAB_006d2851;
    }
    piVar3 = __errno();
    *piVar3 = 0x18;
  }
  p_Var4 = (_iobuf *)0x0;
LAB_006d2851:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return p_Var4;
}

