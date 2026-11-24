
/* Library Function - Single Match
    public: bool __thiscall __crt_strtox::c_string_character_source<char>::validate(void)const 
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_strtox::c_string_character_source<char>::validate(c_string_character_source<char> *this)

{
  int *piVar1;
  
  if (*(int *)this == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return false;
  }
  return true;
}

