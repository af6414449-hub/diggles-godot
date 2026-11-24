
/* Library Function - Single Match
    public: void __thiscall __crt_win32_buffer<char,struct
   __crt_win32_buffer_no_resizing>::set_to_nullptr(void)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall
__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>::set_to_nullptr
          (__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing> *this)

{
  if (this[0x14] != (__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>)0x0) {
    this[0x14] = (__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>)0x0;
  }
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

