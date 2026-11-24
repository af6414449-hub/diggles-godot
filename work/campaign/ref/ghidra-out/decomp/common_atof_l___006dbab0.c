
/* Library Function - Multiple Matches With Same Base Name
    double __cdecl common_atof_l<char>(char const * const,struct __crt_locale_pointers * const)
    double __cdecl common_atof_l<wchar_t>(wchar_t const * const,struct __crt_locale_pointers *
   const)
   
   Library: Visual Studio 2019 Release */

float10 common_atof_l<>(int param_1,__crt_locale_pointers *param_2)

{
  int *piVar1;
  float10 fVar2;
  int local_20;
  undefined1 local_1c [8];
  char local_14;
  double local_10;
  
  if (param_1 == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    fVar2 = (float10)0;
  }
  else {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_20,param_2);
    local_10 = 0.0;
    __crt_strtox::parse_floating_point<class___crt_strtox::c_string_character_source<char>,double>
              (local_1c,param_1,0,&local_10);
    fVar2 = (float10)local_10;
    if (local_14 != '\0') {
      *(uint *)(local_20 + 0x350) = *(uint *)(local_20 + 0x350) & 0xfffffffd;
    }
  }
  return fVar2;
}

