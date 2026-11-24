
/* Library Function - Single Match
    enum __crt_strtox::floating_point_parse_result __cdecl
   __crt_strtox::parse_floating_point_possible_nan<char,class
   __crt_strtox::c_string_character_source<char>,char const *>(char &,class
   __crt_strtox::c_string_character_source<char> &,char const *)
   
   Library: Visual Studio 2019 Release */

floating_point_parse_result __cdecl
__crt_strtox::
parse_floating_point_possible_nan<char,class___crt_strtox::c_string_character_source<char>,char_const*>
          (char *param_1,c_string_character_source<char> *param_2,char *param_3)

{
  bool bVar1;
  floating_point_parse_result fVar2;
  char cVar3;
  int iVar4;
  c_string_character_source<char> *local_10;
  char *local_c;
  char **local_8;
  
  local_8 = &param_3;
  iVar4 = 0;
  local_10 = param_2;
  local_c = param_1;
  cVar3 = *param_1;
  do {
    if ((cVar3 != (&DAT_00716f1c)[iVar4]) && (cVar3 != (&DAT_00716f20)[iVar4])) {
      <lambda_32aa245da1b5b882fa96db788295c8b2>::operator()
                ((<lambda_32aa245da1b5b882fa96db788295c8b2> *)&local_10);
      return 7;
    }
    cVar3 = **(char **)param_2;
    iVar4 = iVar4 + 1;
    *(char **)param_2 = *(char **)param_2 + 1;
    *param_1 = cVar3;
  } while (iVar4 != 3);
  c_string_character_source<char>::unget(param_2,cVar3);
  param_3 = *(char **)param_2;
  cVar3 = *param_3;
  *(char **)param_2 = param_3 + 1;
  *param_1 = cVar3;
  if (cVar3 == '(') {
    cVar3 = **(char **)param_2;
    *(char **)param_2 = *(char **)param_2 + 1;
    *param_1 = cVar3;
    bVar1 = parse_floating_point_possible_nan_is_snan<char,class___crt_strtox::c_string_character_source<char>_>
                      (param_1,param_2);
    if (bVar1) {
      c_string_character_source<char>::unget(param_2,*param_1);
      return 5;
    }
    bVar1 = parse_floating_point_possible_nan_is_ind<char,class___crt_strtox::c_string_character_source<char>_>
                      (param_1,param_2);
    cVar3 = *param_1;
    if (bVar1) {
      c_string_character_source<char>::unget(param_2,cVar3);
      return 6;
    }
    if (cVar3 != ')') {
      do {
        if (cVar3 == '\0') break;
        if ((((9 < (byte)(cVar3 - 0x30U)) && (0x19 < (byte)(cVar3 + 0x9fU))) &&
            (0x19 < (byte)(cVar3 + 0xbfU))) && (cVar3 != '_')) goto LAB_006dc06a;
        cVar3 = **(char **)param_2;
        *(char **)param_2 = *(char **)param_2 + 1;
        *param_1 = cVar3;
      } while (cVar3 != ')');
      if (cVar3 != ')') goto LAB_006dc06a;
    }
    fVar2 = 4;
  }
  else {
LAB_006dc06a:
    bVar1 = <lambda_32aa245da1b5b882fa96db788295c8b2>::operator()
                      ((<lambda_32aa245da1b5b882fa96db788295c8b2> *)&local_10);
    fVar2 = (-(uint)bVar1 & 0xfffffffd) + 7;
  }
  return fVar2;
}

