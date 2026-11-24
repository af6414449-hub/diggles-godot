
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::type_case_n(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_n(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_n(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_n(void)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

uint type_case_n(void)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int in_ECX;
  
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 4;
  puVar1 = *(uint **)(*(int *)(in_ECX + 0x14) + -4);
  iVar2 = __get_printf_count_output();
  if (iVar2 == 0) {
LAB_006d4069:
    piVar3 = __errno();
    *piVar3 = 0x16;
    uVar4 = FUN_006e510d();
    uVar4 = uVar4 & 0xffffff00;
  }
  else {
    uVar4 = __crt_stdio_output::to_integer_size(*(length_modifier *)(in_ECX + 0x2c));
    if (uVar4 == 1) {
      uVar4 = 0;
      *(undefined1 *)puVar1 = *(undefined1 *)(in_ECX + 0x18);
    }
    else if (uVar4 == 2) {
      uVar4 = (uint)*(ushort *)(in_ECX + 0x18);
      *(ushort *)puVar1 = *(ushort *)(in_ECX + 0x18);
    }
    else if (uVar4 == 4) {
      uVar4 = *(uint *)(in_ECX + 0x18);
      *puVar1 = uVar4;
    }
    else {
      if (uVar4 != 8) goto LAB_006d4069;
      uVar4 = *(uint *)(in_ECX + 0x18);
      *puVar1 = uVar4;
      puVar1[1] = (int)uVar4 >> 0x1f;
    }
    *(undefined1 *)(in_ECX + 0x30) = 1;
    uVar4 = CONCAT31((int3)(uVar4 >> 8),1);
  }
  return uVar4;
}

