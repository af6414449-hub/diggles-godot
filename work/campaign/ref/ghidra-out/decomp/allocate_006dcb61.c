
/* Library Function - Multiple Matches With Same Base Name
    public: int __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_internal_dynamic_resizing>::allocate(unsigned int)
    public: int __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_public_dynamic_resizing>::allocate(unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int allocate(uint param_1)

{
  int iVar1;
  __crt_win32_buffer_empty_debug_info *in_ECX;
  
  deallocate();
  iVar1 = __crt_win32_buffer_internal_dynamic_resizing::allocate
                    ((void **)(in_ECX + 8),param_1,in_ECX);
  if (iVar1 == 0) {
    in_ECX[0x14] = (__crt_win32_buffer_empty_debug_info)0x1;
    iVar1 = 0;
    *(uint *)(in_ECX + 0xc) = param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    in_ECX[0x14] = (__crt_win32_buffer_empty_debug_info)0x0;
  }
  return iVar1;
}

