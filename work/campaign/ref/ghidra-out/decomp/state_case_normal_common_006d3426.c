
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::string_output_adapter<char> > >::state_case_normal_common(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_normal_common(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 state_case_normal_common(void)

{
  undefined4 uVar1;
  undefined3 extraout_var;
  int in_ECX;
  
  uVar1 = state_case_normal_tchar(0);
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  __crt_stdio_output::string_output_adapter<char>::write_character
            ((string_output_adapter<char> *)(in_ECX + 0x448),*(char *)(in_ECX + 0x31),
             (int *)(in_ECX + 0x18));
  return CONCAT31(extraout_var,1);
}

