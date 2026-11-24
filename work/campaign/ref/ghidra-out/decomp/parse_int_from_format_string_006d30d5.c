
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::parse_int_from_format_string(int * const)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::parse_int_from_format_string(int * const)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::parse_int_from_format_string(int * const)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::parse_int_from_format_string(int * const)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

undefined4 parse_int_from_format_string(long *param_1)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  char *local_8;
  
  piVar2 = *(int **)(in_ECX + 0xc);
  if (piVar2 == (int *)0x0) {
    piVar2 = __errno();
    *(int **)(in_ECX + 0xc) = piVar2;
  }
  iVar1 = *piVar2;
  *piVar2 = 0;
  local_8 = (char *)0x0;
  lVar3 = _strtol((char *)(*(int *)(in_ECX + 0x10) + -1),&local_8,10);
  *param_1 = lVar3;
  piVar4 = *(int **)(in_ECX + 0xc);
  if (piVar4 == (int *)0x0) {
    piVar4 = __errno();
    *(int **)(in_ECX + 0xc) = piVar4;
  }
  if ((*piVar4 == 0x22) || (local_8 < *(char **)(in_ECX + 0x10))) {
    uVar5 = 0;
  }
  else {
    *(char **)(in_ECX + 0x10) = local_8;
    uVar5 = 1;
  }
  if ((*piVar2 == 0) && (iVar1 != 0)) {
    *piVar2 = iVar1;
  }
  return uVar5;
}

