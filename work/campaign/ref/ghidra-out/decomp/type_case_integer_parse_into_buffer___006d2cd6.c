
/* Library Function - Multiple Matches With Same Base Name
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> >
   >::type_case_integer_parse_into_buffer<unsigned __int64>(unsigned __int64,unsigned int,bool)
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_integer_parse_into_buffer<unsigned __int64>(unsigned __int64,unsigned int,bool)
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_integer_parse_into_buffer<unsigned
   __int64>(unsigned __int64,unsigned int,bool)
    private: void __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_integer_parse_into_buffer<unsigned __int64>(unsigned __int64,unsigned int,bool)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

void type_case_integer_parse_into_buffer<>
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  uint uVar1;
  char extraout_CL;
  char cVar2;
  int in_ECX;
  formatting_buffer *pfVar3;
  formatting_buffer *pfVar4;
  longlong lVar5;
  
  lVar5 = CONCAT44(param_2,param_1);
  pfVar4 = *(formatting_buffer **)(in_ECX + 0x444);
  if (*(formatting_buffer **)(in_ECX + 0x444) == (formatting_buffer *)0x0) {
    pfVar4 = (formatting_buffer *)(in_ECX + 0x40);
  }
  uVar1 = __crt_stdio_output::formatting_buffer::count<char>((formatting_buffer *)(in_ECX + 0x40));
  pfVar4 = pfVar4 + (uVar1 - 1);
  *(formatting_buffer **)(in_ECX + 0x34) = pfVar4;
  pfVar3 = pfVar4;
  while ((0 < *(int *)(in_ECX + 0x28) || (lVar5 != 0))) {
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + -1;
    lVar5 = __aulldvrm(lVar5,param_3,0);
    cVar2 = extraout_CL + '0';
    if ('9' < cVar2) {
      cVar2 = cVar2 + (param_4 ^ 1) * ' ' + '\a';
    }
    **(char **)(in_ECX + 0x34) = cVar2;
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + -1;
    pfVar3 = *(formatting_buffer **)(in_ECX + 0x34);
  }
  *(int *)(in_ECX + 0x38) = (int)pfVar4 - (int)pfVar3;
  *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
  return;
}

