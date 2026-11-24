
/* Library Function - Multiple Matches With Same Base Name
    void __cdecl uninitialize_environment_internal<char>(char * * &)
    void __cdecl uninitialize_environment_internal<wchar_t>(wchar_t * * &)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void uninitialize_environment_internal<>(undefined4 *param_1)

{
  if ((char **)*param_1 != DAT_00769d2c) {
    free_environment<char>((char **)*param_1);
  }
  return;
}

