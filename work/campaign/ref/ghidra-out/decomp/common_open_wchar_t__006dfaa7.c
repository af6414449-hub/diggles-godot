
/* Library Function - Single Match
    int __cdecl common_open<wchar_t>(wchar_t const * const,int,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_open<wchar_t>(wchar_t *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  errno_t eVar3;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763520,0x14);
  if (*(int *)(unaff_EBP + 8) == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    eVar3 = __wsopen_nolock((int *)(unaff_EBP + -0x24),(int *)(unaff_EBP + -0x1c),
                            *(wchar_t **)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc),0x40,
                            *(int *)(unaff_EBP + 0x10),0);
    *(errno_t *)(unaff_EBP + -0x20) = eVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006dfb1a();
    if (eVar3 == 0) {
      iVar2 = *(int *)(unaff_EBP + -0x1c);
      goto LAB_006dfb4b;
    }
    piVar1 = __errno();
    *piVar1 = eVar3;
  }
  iVar2 = -1;
LAB_006dfb4b:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar2;
}

