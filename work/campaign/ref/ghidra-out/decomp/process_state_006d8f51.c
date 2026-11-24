
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::process_state(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
process_state(input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  
  iVar1 = *(int *)(this + 0x28);
  if (iVar1 == 2) {
    bVar3 = process_whitespace(this);
    return bVar3;
  }
  if (iVar1 != 3) {
    if (iVar1 == 4) {
      cVar2 = FUN_006d8dc7();
      if (((cVar2 != '\0') && (*(int *)(this + 0x40) != 9)) &&
         (this[0x2e] ==
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>)0x0)) {
        *(int *)(this + 0x70) = *(int *)(this + 0x70) + 1;
        return (bool)cVar2;
      }
    }
    else {
      cVar2 = '\0';
    }
    return (bool)cVar2;
  }
  bVar3 = process_literal_character(this);
  return bVar3;
}

