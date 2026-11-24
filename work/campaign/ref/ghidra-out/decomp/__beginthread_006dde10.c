
/* Library Function - Single Match
    __beginthread
   
   Library: Visual Studio 2019 Release */

uintptr_t __cdecl __beginthread(_StartAddress *_StartAddress,uint _StackSize,void *_ArgList)

{
  int *piVar1;
  __acrt_thread_parameter *lpParameter;
  HANDLE hThread;
  DWORD DVar2;
  DWORD local_c;
  __acrt_thread_parameter *local_8;
  
  if (_StartAddress == (_StartAddress *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0xffffffff;
  }
  lpParameter = create_thread_parameter(_StartAddress,_ArgList);
  local_8 = lpParameter;
  if (lpParameter != (__acrt_thread_parameter *)0x0) {
    local_c = 0;
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,_StackSize,
                           (LPTHREAD_START_ROUTINE)&LAB_006ddcb2,lpParameter,4,&local_c);
    if (hThread != (HANDLE)0x0) {
      *(HANDLE *)(lpParameter + 8) = hThread;
      DVar2 = ResumeThread(hThread);
      if (DVar2 != 0xffffffff) {
        local_8 = (__acrt_thread_parameter *)0x0;
        goto LAB_006dde7b;
      }
    }
    DVar2 = GetLastError();
    ___acrt_errno_map_os_error(DVar2);
  }
  hThread = (HANDLE)0xffffffff;
LAB_006dde7b:
  __crt_unique_heap_ptr<struct___acrt_thread_parameter,struct__anon_4E93FCDD::thread_parameter_free_policy>
  ::
  ~__crt_unique_heap_ptr<struct___acrt_thread_parameter,struct__anonymous_namespace_::thread_parameter_free_policy>
            ((__crt_unique_heap_ptr<struct___acrt_thread_parameter,struct__anon_4E93FCDD::thread_parameter_free_policy>
              *)&local_8);
  return (uintptr_t)hThread;
}

