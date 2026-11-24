
/* Library Function - Single Match
    void __cdecl try_cor_exit_process(unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl try_cor_exit_process(uint param_1)

{
  BOOL BVar1;
  FARPROC pFVar2;
  HMODULE local_8;
  
  local_8 = (HMODULE)0x0;
  BVar1 = GetModuleHandleExW(0,L"mscoree.dll",&local_8);
  if ((BVar1 != 0) && (pFVar2 = GetProcAddress(local_8,"CorExitProcess"), pFVar2 != (FARPROC)0x0)) {
    guard_check_icall(param_1);
    (*pFVar2)();
  }
  if (local_8 != (HMODULE)0x0) {
    FreeLibrary(local_8);
  }
  return;
}

