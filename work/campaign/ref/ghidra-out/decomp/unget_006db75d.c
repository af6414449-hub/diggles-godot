
/* Library Function - Single Match
    public: void __thiscall __crt_strtox::c_string_character_source<char>::unget(char)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_strtox::c_string_character_source<char>::unget
          (c_string_character_source<char> *this,char param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)this;
  *(char **)this = (char *)(iVar1 + -1);
  if ((param_1 != '\0') && (*(char *)(iVar1 + -1) != param_1)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  return;
}

