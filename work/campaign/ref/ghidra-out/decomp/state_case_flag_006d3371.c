
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_flag(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_flag(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 state_case_flag(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (int)*(char *)(in_ECX + 0x31);
  if (iVar1 == 0x20) {
    *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) | 2;
    iVar1 = 0;
  }
  else if (iVar1 == 0x23) {
    *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) | 0x20;
    iVar1 = 0;
  }
  else if (iVar1 == 0x2b) {
    *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) | 1;
    iVar1 = 0;
  }
  else if (iVar1 == 0x2d) {
    *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) | 4;
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + -0x30;
    if (iVar1 == 0) {
      *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) | 8;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

