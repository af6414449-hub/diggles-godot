
/* Library Function - Single Match
    __wtol
   
   Library: Visual Studio 2019 Release */

long __cdecl __wtol(wchar_t *_Str)

{
  ulong uVar1;
  
  uVar1 = __crt_strtox::
          parse_integer<unsigned_long,class___crt_strtox::c_string_character_source<wchar_t>_>
                    (0,_Str,0,10,1);
  return uVar1;
}

