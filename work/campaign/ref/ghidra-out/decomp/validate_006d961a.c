
/* Library Function - Single Match
    public: bool __thiscall __crt_stdio_input::string_input_adapter<char>::validate(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::string_input_adapter<char>::validate(string_input_adapter<char> *this)

{
  int *piVar1;
  
  if ((*(uint *)(this + 8) != 0) && (*(uint *)(this + 8) <= *(uint *)(this + 4))) {
    return true;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_006e510d();
  return false;
}

