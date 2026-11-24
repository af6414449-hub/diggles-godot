
/* Library Function - Single Match
    void __cdecl exit_or_terminate_process(unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl exit_or_terminate_process(uint param_1)

{
  int iVar1;
  HANDLE hProcess;
  uint uExitCode;
  
  iVar1 = ___acrt_get_process_end_policy();
  if ((iVar1 != 1) && ((*(uint *)((int)ProcessEnvironmentBlock + 0x68) >> 8 & 1) == 0)) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  try_cor_exit_process(param_1);
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}

