
/* Library Function - Single Match
    enum __crt_strtox::floating_point_parse_result __cdecl
   __crt_strtox::parse_floating_point_possible_infinity<char,class
   __crt_strtox::c_string_character_source<char>,char const *>(char &,class
   __crt_strtox::c_string_character_source<char> &,char const *)
   
   Library: Visual Studio 2019 Release */

floating_point_parse_result __cdecl
__crt_strtox::
parse_floating_point_possible_infinity<char,class___crt_strtox::c_string_character_source<char>,char_const*>
          (char *param_1,c_string_character_source<char> *param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar2 = *param_1;
  while ((cVar2 == (&DAT_00716f04)[iVar3] || (cVar2 == (&DAT_00716f08)[iVar3]))) {
    cVar2 = **(char **)param_2;
    iVar3 = iVar3 + 1;
    *(char **)param_2 = *(char **)param_2 + 1;
    *param_1 = cVar2;
    if (iVar3 == 3) {
      c_string_character_source<char>::unget(param_2,cVar2);
      pcVar1 = *(char **)param_2;
      iVar3 = 0;
      cVar2 = *pcVar1;
      *(char **)param_2 = pcVar1 + 1;
      *param_1 = cVar2;
      while ((cVar2 == "INITY"[iVar3] || (cVar2 == "inity"[iVar3]))) {
        cVar2 = **(char **)param_2;
        iVar3 = iVar3 + 1;
        *(char **)param_2 = *(char **)param_2 + 1;
        *param_1 = cVar2;
        if (iVar3 == 5) {
          c_string_character_source<char>::unget(param_2,cVar2);
          return 3;
        }
      }
      c_string_character_source<char>::unget(param_2,cVar2);
      *param_1 = '\0';
      *(char **)param_2 = pcVar1;
      return 3;
    }
  }
  c_string_character_source<char>::unget(param_2,cVar2);
  *param_1 = '\0';
  *(char **)param_2 = param_3;
  return 7;
}

