
/* Library Function - Single Match
    public: __thiscall __crt_unique_heap_ptr<struct __acrt_thread_parameter,struct `anonymous
   namespace'::thread_parameter_free_policy>::~__crt_unique_heap_ptr<struct
   __acrt_thread_parameter,struct `anonymous namespace'::thread_parameter_free_policy>(void)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_unique_heap_ptr<struct___acrt_thread_parameter,struct__anon_4E93FCDD::thread_parameter_free_policy>
::
~__crt_unique_heap_ptr<struct___acrt_thread_parameter,struct__anonymous_namespace_::thread_parameter_free_policy>
          (__crt_unique_heap_ptr<struct___acrt_thread_parameter,struct__anon_4E93FCDD::thread_parameter_free_policy>
           *this)

{
  void *_Memory;
  
  _Memory = *(void **)this;
  if (_Memory != (void *)0x0) {
    if (*(int *)((int)_Memory + 8) != 0) {
      CloseHandle(*(HANDLE *)((int)_Memory + 8));
    }
    if (*(int *)((int)_Memory + 0xc) != 0) {
      FreeLibrary(*(HMODULE *)((int)_Memory + 0xc));
    }
    FID_conflict__free(_Memory);
  }
  *(undefined4 *)this = 0;
  return;
}

