
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::write_integer(unsigned __int64)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
write_integer(input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this,
             __uint64 param_1)

{
  __uint64 *p_Var1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  
  *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + 4;
  p_Var1 = *(__uint64 **)(*(int *)(this + 0x6c) + -4);
  if (p_Var1 == (__uint64 *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
LAB_006d96cd:
    bVar2 = false;
  }
  else {
    uVar4 = format_string_parser<char>::length((format_string_parser<char> *)(this + 0x18));
    if (uVar4 == 1) {
      *(undefined1 *)p_Var1 = (undefined1)param_1;
    }
    else if (uVar4 == 2) {
      *(short *)p_Var1 = (short)param_1;
    }
    else if (uVar4 == 4) {
      *(int *)p_Var1 = (int)param_1;
    }
    else {
      if (uVar4 != 8) goto LAB_006d96cd;
      *p_Var1 = param_1;
    }
    bVar2 = true;
  }
  return bVar2;
}

