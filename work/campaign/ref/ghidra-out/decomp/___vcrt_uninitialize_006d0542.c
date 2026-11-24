
/* Library Function - Single Match
    ___vcrt_uninitialize
   
   Library: Visual Studio 2019 Release */

undefined1 ___vcrt_uninitialize(char param_1)

{
  if (param_1 == '\0') {
    ___vcrt_uninitialize_ptd();
    ___vcrt_uninitialize_locks();
  }
  return 1;
}

