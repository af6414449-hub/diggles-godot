
/* Library Function - Single Match
    public: void __thiscall __crt_strtox::c_string_character_source<wchar_t>::unget(wchar_t)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_strtox::c_string_character_source<wchar_t>::unget
          (c_string_character_source<wchar_t> *this,wchar_t param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)this;
  *(wchar_t **)this = (wchar_t *)(iVar1 + -2);
  if ((param_1 != L'\0') && (*(wchar_t *)(iVar1 + -2) != param_1)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  return;
}

