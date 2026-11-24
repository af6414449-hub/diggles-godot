
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::string_output_adapter<char> > >::state_case_normal_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::positional_parameter_base<char,class
   __crt_stdio_output::string_output_adapter<char> > >::state_case_normal_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_normal_tchar(char)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 state_case_normal_tchar(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  cVar1 = *(char *)(in_ECX + 0x31);
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  iVar2 = ___acrt_locale_get_ctype_array_value
                    (*(undefined4 *)**(undefined4 **)(in_ECX + 8),(int)cVar1,0x8000);
  if (iVar2 != 0) {
    __crt_stdio_output::string_output_adapter<char>::write_character
              ((string_output_adapter<char> *)(in_ECX + 0x448),cVar1,(int *)(in_ECX + 0x18));
    cVar1 = **(char **)(in_ECX + 0x10);
    *(char *)(in_ECX + 0x31) = cVar1;
    *(char **)(in_ECX + 0x10) = *(char **)(in_ECX + 0x10) + 1;
    if (cVar1 == '\0') {
      piVar3 = __errno();
      *piVar3 = 0x16;
      FUN_006e510d();
      return 0;
    }
  }
  return 1;
}

