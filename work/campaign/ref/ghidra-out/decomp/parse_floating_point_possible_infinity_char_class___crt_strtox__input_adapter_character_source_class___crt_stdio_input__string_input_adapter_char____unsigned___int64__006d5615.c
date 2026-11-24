
/* Library Function - Single Match
    enum __crt_strtox::floating_point_parse_result __cdecl
   __crt_strtox::parse_floating_point_possible_infinity<char,class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::string_input_adapter<char>
   >,unsigned __int64>(char &,class __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::string_input_adapter<char> > &,unsigned __int64)
   
   Library: Visual Studio 2019 Release */

floating_point_parse_result __cdecl
__crt_strtox::
parse_floating_point_possible_infinity<char,class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>,unsigned___int64>
          (char *param_1,
          input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
          *param_2,__uint64 param_3)

{
  char cVar1;
  int iVar2;
  int local_8;
  
  iVar2 = 0;
  local_8 = 0;
  while ((*param_1 == (&DAT_00716ea0)[local_8] || (*param_1 == (&DAT_00716ea4)[local_8]))) {
    cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
            get(param_2);
    local_8 = local_8 + 1;
    *param_1 = cVar1;
    if (local_8 == 3) {
      input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::unget
                (param_2,cVar1);
      cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
              get(param_2);
      *param_1 = cVar1;
      while ((*param_1 == "INITY"[iVar2] || (*param_1 == "inity"[iVar2]))) {
        cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                ::get(param_2);
        iVar2 = iVar2 + 1;
        *param_1 = cVar1;
        if (iVar2 == 5) {
          input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
          unget(param_2,cVar1);
          return 3;
        }
      }
      cVar1 = FID_conflict_operator__();
      return (uint)(cVar1 == '\0') * 4 + 3;
    }
  }
  FID_conflict_operator__();
  return 7;
}

