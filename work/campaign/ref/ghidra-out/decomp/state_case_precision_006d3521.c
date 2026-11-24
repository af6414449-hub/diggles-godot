
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_precision(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_precision(void)
   
   Library: Visual Studio 2019 Release */

undefined4 state_case_precision(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x28);
  if (*(char *)(in_ECX + 0x31) != '*') {
    uVar3 = parse_int_from_format_string(piVar1);
    return uVar3;
  }
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 4;
  iVar2 = *(int *)(*(int *)(in_ECX + 0x14) + -4);
  *piVar1 = iVar2;
  if (iVar2 < 0) {
    *piVar1 = -1;
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

