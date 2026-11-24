
/* Library Function - Multiple Matches With Same Base Name
    public: void __thiscall __crt_state_management::dual_state_global<char * *>::uninitialize<void
   (__cdecl&)(char * * &)>(void (__cdecl&)(char * * &))
    public: void __thiscall __crt_state_management::dual_state_global<wchar_t *
   *>::uninitialize<void (__cdecl&)(wchar_t * * &)>(void (__cdecl&)(wchar_t * * &))
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void uninitialize<>(code *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = in_ECX + 4;
  for (; in_ECX != iVar1; in_ECX = in_ECX + 4) {
    guard_check_icall(in_ECX);
    (*param_1)();
  }
  return;
}

