
/* Library Function - Single Match
    char * __cdecl common_strerror<char>(int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

char * __cdecl common_strerror<char>(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  
  iVar1 = ___acrt_getptd_noexit();
  if (iVar1 == 0) {
LAB_006e0a53:
    pcVar3 = "Visual C++ CRT: Not enough memory to complete call to strerror.";
  }
  else {
    iVar4 = *(int *)(iVar1 + 0x40);
    if (iVar4 == 0) {
      uVar2 = __calloc_base(0x86,1);
      *(undefined4 *)(iVar1 + 0x40) = uVar2;
      FID_conflict__free((void *)0x0);
      iVar4 = *(int *)(iVar1 + 0x40);
      if (iVar4 == 0) goto LAB_006e0a53;
    }
    pcVar3 = __get_sys_err_msg(param_1);
    iVar4 = FUN_006e9950(iVar4,0x86,pcVar3,0x85);
    if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    pcVar3 = *(char **)(iVar1 + 0x40);
  }
  return pcVar3;
}

