
/* Library Function - Single Match
    struct _iobuf * __cdecl common_fsopen<wchar_t>(wchar_t const * const,wchar_t const * const,int)
   
   Library: Visual Studio 2019 Release */

_iobuf * __cdecl common_fsopen<wchar_t>(wchar_t *param_1,wchar_t *param_2,int param_3)

{
  short *psVar1;
  short *psVar2;
  int *piVar3;
  _iobuf *p_Var4;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763280,0x10);
  psVar1 = *(short **)(unaff_EBP + 8);
  if (((psVar1 == (short *)0x0) || (psVar2 = *(short **)(unaff_EBP + 0xc), psVar2 == (short *)0x0))
     || (*psVar2 == 0)) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
  }
  else if (*psVar1 == 0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
  }
  else {
    __acrt_stdio_allocate_stream();
    if (*(int *)(unaff_EBP + -0x1c) != 0) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      p_Var4 = (_iobuf *)
               FUN_006e5971(psVar1,psVar2,*(undefined4 *)(unaff_EBP + 0x10),
                            *(undefined4 *)(unaff_EBP + -0x1c));
      *(_iobuf **)(unaff_EBP + -0x20) = p_Var4;
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
      FUN_006d291a();
      goto LAB_006d2907;
    }
    piVar3 = __errno();
    *piVar3 = 0x18;
  }
  p_Var4 = (_iobuf *)0x0;
LAB_006d2907:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return p_Var4;
}

