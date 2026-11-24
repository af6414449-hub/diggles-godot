
/* Library Function - Single Match
    ___vcrt_uninitialize_locks
   
   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_uninitialize_locks(void)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (DAT_00769adc != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_00769aac + DAT_00769adc * 0x18);
    iVar1 = DAT_00769adc;
    do {
      DeleteCriticalSection(lpCriticalSection);
      DAT_00769adc = DAT_00769adc + -1;
      lpCriticalSection = lpCriticalSection + -1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 1;
}

