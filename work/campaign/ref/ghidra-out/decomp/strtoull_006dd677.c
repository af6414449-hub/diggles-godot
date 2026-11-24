
/* Library Function - Single Match
    _strtoull
   
   Library: Visual Studio 2019 Release */

__uint64 __cdecl strtoull(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  __uint64 _Var1;
  undefined1 auStack_18 [8];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0;
  uStack_10 = param_3;
  make_c_string_character_source<>(auStack_18,param_1,param_2);
  _Var1 = __crt_strtox::
          parse_integer<unsigned___int64,class___crt_strtox::c_string_character_source<char>_>(0);
  return _Var1;
}

