
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::state_case_normal_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::positional_parameter_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::state_case_normal_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_normal_tchar(char)
   
   Library: Visual Studio 2019 Release */

undefined4 state_case_normal_tchar(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  cVar1 = *(char *)(in_ECX + 0x31);
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  iVar3 = ___acrt_locale_get_ctype_array_value
                    (*(undefined4 *)**(undefined4 **)(in_ECX + 8),(int)cVar1,0x8000);
  if (iVar3 != 0) {
    bVar2 = __crt_stdio_output::stream_output_adapter<char>::write_character_without_count_update
                      ((stream_output_adapter<char> *)(in_ECX + 0x448),cVar1);
    if (bVar2) {
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    }
    else {
      *(undefined4 *)(in_ECX + 0x18) = 0xffffffff;
    }
    cVar1 = **(char **)(in_ECX + 0x10);
    *(char *)(in_ECX + 0x31) = cVar1;
    *(char **)(in_ECX + 0x10) = *(char **)(in_ECX + 0x10) + 1;
    if (cVar1 == '\0') {
      piVar4 = __errno();
      *piVar4 = 0x16;
      FUN_006e510d();
      return 0;
    }
  }
  return 1;
}

