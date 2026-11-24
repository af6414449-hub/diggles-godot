
/* Library Function - Single Match
    bool __cdecl __crt_strtox::parse_floating_point_possible_nan_is_ind<char,class
   __crt_strtox::c_string_character_source<char> >(char &,class
   __crt_strtox::c_string_character_source<char> &)
   
   Library: Visual Studio 2019 Release */

bool __cdecl
__crt_strtox::
parse_floating_point_possible_nan_is_ind<char,class___crt_strtox::c_string_character_source<char>_>
          (char *param_1,c_string_character_source<char> *param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = 0;
  cVar2 = *param_1;
  while ((cVar2 == (&DAT_00716f34)[iVar1] || (cVar2 == (&DAT_00716f38)[iVar1]))) {
    cVar2 = **(char **)param_2;
    iVar1 = iVar1 + 1;
    *(char **)param_2 = *(char **)param_2 + 1;
    *param_1 = cVar2;
    if (iVar1 == 4) {
      return true;
    }
  }
  return false;
}

