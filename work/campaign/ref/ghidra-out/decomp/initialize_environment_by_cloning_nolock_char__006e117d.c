
/* Library Function - Single Match
    int __cdecl initialize_environment_by_cloning_nolock<char>(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl initialize_environment_by_cloning_nolock<char>(void)

{
  int iVar1;
  void *_Memory;
  int *piVar2;
  
  if (DAT_00769d24 == (int *)0x0) {
LAB_006e11f9:
    iVar1 = -1;
  }
  else {
    iVar1 = *DAT_00769d24;
    piVar2 = DAT_00769d24;
    while (iVar1 != 0) {
      iVar1 = ___acrt_WideCharToMultiByte(0,0,iVar1,0xffffffff,0,0,0,0);
      if (iVar1 == 0) goto LAB_006e11f9;
      _Memory = (void *)__calloc_base(iVar1,1);
      if ((_Memory == (void *)0x0) ||
         (iVar1 = ___acrt_WideCharToMultiByte(0,0,*piVar2,0xffffffff,_Memory,iVar1,0,0), iVar1 == 0)
         ) {
        FID_conflict__free(_Memory);
        goto LAB_006e11f9;
      }
      FUN_006ed3ab(_Memory,0);
      FID_conflict__free((void *)0x0);
      piVar2 = piVar2 + 1;
      iVar1 = *piVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}

