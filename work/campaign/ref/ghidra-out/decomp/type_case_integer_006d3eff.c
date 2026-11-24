
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::type_case_integer(unsigned int,bool)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_integer(unsigned int,bool)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_integer(unsigned int,bool)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_integer(unsigned int,bool)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

uint type_case_integer(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  uVar1 = __crt_stdio_output::to_integer_size(*(length_modifier *)(in_ECX + 0x2c));
  if (uVar1 == 1) {
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 4;
    if ((*(uint *)(in_ECX + 0x20) >> 4 & 1) == 0) {
      uVar6 = (uint)*(byte *)(*(int *)(in_ECX + 0x14) + -4);
    }
    else {
      uVar6 = (uint)*(char *)(*(int *)(in_ECX + 0x14) + -4);
    }
  }
  else if (uVar1 == 2) {
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 4;
    if ((*(uint *)(in_ECX + 0x20) >> 4 & 1) == 0) {
      uVar6 = (uint)*(ushort *)(*(int *)(in_ECX + 0x14) + -4);
    }
    else {
      uVar6 = (uint)*(short *)(*(int *)(in_ECX + 0x14) + -4);
    }
  }
  else {
    if (uVar1 != 4) {
      if (uVar1 != 8) {
        piVar2 = __errno();
        *piVar2 = 0x16;
        uVar1 = FUN_006e510d();
        return uVar1 & 0xffffff00;
      }
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 8;
      uVar6 = *(uint *)(*(int *)(in_ECX + 0x14) + -8);
      iVar5 = *(int *)(*(int *)(in_ECX + 0x14) + -4);
      goto LAB_006d3fb5;
    }
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 4;
    if ((*(uint *)(in_ECX + 0x20) >> 4 & 1) == 0) {
      uVar6 = *(uint *)(*(int *)(in_ECX + 0x14) + -4);
      iVar5 = 0;
      goto LAB_006d3fb5;
    }
    uVar6 = *(uint *)(*(int *)(in_ECX + 0x14) + -4);
  }
  iVar5 = (int)uVar6 >> 0x1f;
LAB_006d3fb5:
  uVar4 = *(uint *)(in_ECX + 0x20);
  if ((((uVar4 >> 4 & 1) != 0) && (iVar5 < 1)) && (iVar5 < 0)) {
    bVar7 = uVar6 != 0;
    uVar6 = -uVar6;
    iVar5 = -(iVar5 + (uint)bVar7);
    uVar4 = uVar4 | 0x40;
    *(uint *)(in_ECX + 0x20) = uVar4;
  }
  if (*(int *)(in_ECX + 0x28) < 0) {
    *(undefined4 *)(in_ECX + 0x28) = 1;
  }
  else {
    *(uint *)(in_ECX + 0x20) = uVar4 & 0xfffffff7;
    __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>
              ((formatting_buffer *)(in_ECX + 0x40),*(uint *)(in_ECX + 0x28));
  }
  if (uVar6 == 0 && iVar5 == 0) {
    *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) & 0xffffffdf;
  }
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  if (uVar1 == 8) {
    type_case_integer_parse_into_buffer<>(uVar6,iVar5,param_1,param_2);
  }
  else {
    type_case_integer_parse_into_buffer<>(uVar6,param_1,param_2);
  }
  pcVar3 = (char *)(*(uint *)(in_ECX + 0x20) >> 7);
  if ((((uint)pcVar3 & 1) != 0) &&
     ((*(int *)(in_ECX + 0x38) == 0 || (pcVar3 = *(char **)(in_ECX + 0x34), *pcVar3 != '0')))) {
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + -1;
    **(undefined1 **)(in_ECX + 0x34) = 0x30;
    *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + 1;
  }
  return CONCAT31((int3)((uint)pcVar3 >> 8),1);
}

