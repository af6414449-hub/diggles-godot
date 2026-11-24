
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_internal_dynamic_resizing>::_deallocate(void)
    private: void __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_public_dynamic_resizing>::_deallocate(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void deallocate(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x14) != '\0') {
    FUN_006df631(*(undefined4 *)(in_ECX + 8));
    *(undefined1 *)(in_ECX + 0x14) = 0;
  }
  return;
}

