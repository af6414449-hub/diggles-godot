
/* Library Function - Single Match
    public: bool __thiscall __crt_stdio_input::format_string_parser<char>::validate(void)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::format_string_parser<char>::validate(format_string_parser<char> *this)

{
  int *piVar1;
  
  if (*(int *)(this + 8) == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return false;
  }
  return true;
}

