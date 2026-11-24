
/* Library Function - Single Match
    ___vcrt_initialize_ptd
   
   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_initialize_ptd(void)

{
  int iVar1;
  
  DAT_00767020 = ___vcrt_FlsAlloc(FUN_006d06f6);
  if (DAT_00767020 != -1) {
    iVar1 = ___vcrt_FlsSetValue(DAT_00767020,&DAT_00769a9c);
    if (iVar1 != 0) {
      return 1;
    }
    ___vcrt_uninitialize_ptd();
  }
  return 0;
}

