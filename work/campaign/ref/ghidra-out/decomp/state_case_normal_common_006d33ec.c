
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::state_case_normal_common(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_normal_common(void)
   
   Library: Visual Studio 2019 Release */

char state_case_normal_common(void)

{
  char cVar1;
  bool bVar2;
  int in_ECX;
  
  cVar1 = state_case_normal_tchar(0);
  if (cVar1 != '\0') {
    bVar2 = __crt_stdio_output::stream_output_adapter<char>::write_character_without_count_update
                      ((stream_output_adapter<char> *)(in_ECX + 0x448),*(char *)(in_ECX + 0x31));
    if (bVar2) {
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    }
    else {
      *(undefined4 *)(in_ECX + 0x18) = 0xffffffff;
    }
    cVar1 = '\x01';
  }
  return cVar1;
}

