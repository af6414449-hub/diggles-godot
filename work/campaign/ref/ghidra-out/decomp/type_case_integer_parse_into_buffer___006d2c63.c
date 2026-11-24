
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> >
   >::type_case_integer_parse_into_buffer<unsigned int>(unsigned int,unsigned int,bool)
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_integer_parse_into_buffer<unsigned int>(unsigned int,unsigned int,bool)
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_integer_parse_into_buffer<unsigned
   int>(unsigned int,unsigned int,bool)
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_integer_parse_into_buffer<unsigned int>(unsigned int,unsigned int,bool)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

void type_case_integer_parse_into_buffer<>(uint param_1,uint param_2,byte param_3)

{
  uint uVar1;
  int in_ECX;
  formatting_buffer *pfVar2;
  char cVar3;
  formatting_buffer *pfVar4;
  
  pfVar4 = *(formatting_buffer **)(in_ECX + 0x444);
  if (*(formatting_buffer **)(in_ECX + 0x444) == (formatting_buffer *)0x0) {
    pfVar4 = (formatting_buffer *)(in_ECX + 0x40);
  }
  uVar1 = __crt_stdio_output::formatting_buffer::count<char>((formatting_buffer *)(in_ECX + 0x40));
  pfVar4 = pfVar4 + (uVar1 - 1);
  *(formatting_buffer **)(in_ECX + 0x34) = pfVar4;
  pfVar2 = pfVar4;
  while ((0 < *(int *)(in_ECX + 0x28) || (param_1 != 0))) {
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + -1;
    cVar3 = (char)(param_1 % param_2) + '0';
    if ('9' < cVar3) {
      cVar3 = cVar3 + (param_3 ^ 1) * ' ' + '\a';
    }
    **(char **)(in_ECX + 0x34) = cVar3;
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + -1;
    pfVar2 = *(formatting_buffer **)(in_ECX + 0x34);
    param_1 = param_1 / param_2;
  }
  *(int *)(in_ECX + 0x38) = (int)pfVar4 - (int)pfVar2;
  *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
  return;
}

