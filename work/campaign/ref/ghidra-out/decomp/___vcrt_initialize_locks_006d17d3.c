
/* Library Function - Single Match
    ___vcrt_initialize_locks
   
   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_initialize_locks(void)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_00769ac4;
  uVar2 = 0;
  do {
    iVar1 = ___vcrt_InitializeCriticalSectionEx(puVar3,4000,0);
    if (iVar1 == 0) {
      ___vcrt_uninitialize_locks();
      return 0;
    }
    DAT_00769adc = DAT_00769adc + 1;
    uVar2 = uVar2 + 0x18;
    puVar3 = puVar3 + 0x18;
  } while (uVar2 < 0x18);
  return 1;
}

