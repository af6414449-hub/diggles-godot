
/* Library Function - Single Match
    ___vcrt_uninitialize_ptd
   
   Library: Visual Studio 2019 Release */

undefined4 ___vcrt_uninitialize_ptd(void)

{
  if (DAT_00767020 != -1) {
    ___vcrt_FlsFree(DAT_00767020);
    DAT_00767020 = -1;
  }
  return 1;
}

