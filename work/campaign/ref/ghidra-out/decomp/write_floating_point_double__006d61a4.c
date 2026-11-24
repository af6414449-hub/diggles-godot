
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::write_floating_point<double>(double const &)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
write_floating_point<double>
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this,
          double *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + 4;
  puVar1 = *(undefined4 **)(*(int *)(this + 0x6c) + -4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)param_1;
    puVar1[1] = *(undefined4 *)((int)param_1 + 4);
  }
  else {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  return puVar1 != (undefined4 *)0x0;
}

