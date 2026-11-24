
/* Library Function - Multiple Matches With Same Base Name
    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::console_input_adapter<char>
   >,double>(struct __crt_locale_pointers * const,class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::console_input_adapter<char>
   >,double * const)
    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::stream_input_adapter<char>
   >,double>(struct __crt_locale_pointers * const,class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::stream_input_adapter<char>
   >,double * const)
    enum SLD_STATUS __cdecl __crt_strtox::parse_floating_point<class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::string_input_adapter<char>
   >,double>(struct __crt_locale_pointers * const,class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::string_input_adapter<char>
   >,double * const)
   
   Library: Visual Studio 2019 Release */

void parse_floating_point<>(__crt_locale_pointers *param_1)

{
  double *pdVar1;
  int *piVar2;
  floating_point_parse_result fVar3;
  int in_stack_00000018;
  int in_stack_0000001c;
  undefined1 *in_stack_00000020;
  double *in_stack_00000028;
  floating_point_string local_314 [780];
  uint local_8;
  
  pdVar1 = in_stack_00000028;
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if ((in_stack_00000028 == (double *)0x0) || (param_1 == (__crt_locale_pointers *)0x0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  else {
    fVar3 = __crt_strtox::
            parse_floating_point_from_source<class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>_>
                      (param_1,(input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                                *)&stack0x00000008,local_314);
    __crt_strtox::parse_floating_point_write_result<double>(fVar3,local_314,pdVar1);
  }
  if ((in_stack_00000020 != (undefined1 *)0x0) && (in_stack_00000018 == 0 && in_stack_0000001c == 0)
     ) {
    *in_stack_00000020 = 0;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

