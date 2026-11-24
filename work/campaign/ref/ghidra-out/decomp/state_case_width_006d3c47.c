
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_width(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_width(void)
   
   Library: Visual Studio 2019 Release */

undefined4 state_case_width(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x24);
  if (*(char *)(in_ECX + 0x31) != '*') {
    uVar2 = parse_int_from_format_string(piVar1);
    return uVar2;
  }
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 4;
  iVar3 = *(int *)(*(int *)(in_ECX + 0x14) + -4);
  *piVar1 = iVar3;
  if (iVar3 < 0) {
    *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) | 4;
    iVar3 = -iVar3;
    *piVar1 = iVar3;
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}

