
/* Library Function - Single Match
    enum __crt_strtox::floating_point_parse_result __cdecl
   __crt_strtox::parse_floating_point_possible_nan<char,class
   __crt_strtox::input_adapter_character_source<class __crt_stdio_input::string_input_adapter<char>
   >,unsigned __int64>(char &,class __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::string_input_adapter<char> > &,unsigned __int64)
   
   Library: Visual Studio 2019 Release */

floating_point_parse_result __cdecl
__crt_strtox::
parse_floating_point_possible_nan<char,class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>,unsigned___int64>
          (char *param_1,
          input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
          *param_2,__uint64 param_3)

{
  char cVar1;
  bool bVar2;
  floating_point_parse_result fVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if ((*param_1 != (&DAT_00716eb8)[iVar4]) && (*param_1 != (&DAT_00716ebc)[iVar4])) {
      FID_conflict_operator__();
      return 7;
    }
    cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
            get(param_2);
    iVar4 = iVar4 + 1;
    *param_1 = cVar1;
  } while (iVar4 != 3);
  input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::unget
            (param_2,cVar1);
  cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::get
                    (param_2);
  *param_1 = cVar1;
  if (cVar1 == '(') {
    cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::
            get(param_2);
    *param_1 = cVar1;
    bVar2 = parse_floating_point_possible_nan_is_snan<char,class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>_>
                      (param_1,param_2);
    if (bVar2) {
      input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::unget
                (param_2,*param_1);
      fVar3 = 5;
    }
    else {
      bVar2 = parse_floating_point_possible_nan_is_ind<char,class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>_>
                        (param_1,param_2);
      cVar1 = *param_1;
      if (bVar2) {
        input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>::unget
                  (param_2,cVar1);
        fVar3 = 6;
      }
      else {
        while (cVar1 != ')') {
          if ((cVar1 == '\0') ||
             ((((9 < (byte)(cVar1 - 0x30U) && (0x19 < (byte)(cVar1 + 0x9fU))) &&
               (0x19 < (byte)(cVar1 + 0xbfU))) && (cVar1 != '_')))) goto LAB_006d5735;
          cVar1 = input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
                  ::get(param_2);
          *param_1 = cVar1;
        }
        fVar3 = 4;
      }
    }
  }
  else {
LAB_006d5735:
    cVar1 = FID_conflict_operator__();
    fVar3 = (-(uint)(cVar1 != '\0') & 0xfffffffd) + 7;
  }
  return fVar3;
}

