
/* Library Function - Single Match
    int __cdecl common_getenv_s<char>(unsigned int * const,char * const,unsigned int,char const *
   const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_getenv_s<char>(uint *param_1,char *param_2,uint param_3,char *param_4)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763828,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(0xb);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = common_getenv_s_nolock<char>
                    (*(uint **)(unaff_EBP + 8),*(char **)(unaff_EBP + 0xc),
                     *(uint *)(unaff_EBP + 0x10),*(char **)(unaff_EBP + 0x14));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e97e3();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

