
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::write_floating_point<float>(float const &)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
write_floating_point<float>
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this,
          float *param_1)

{
  float *pfVar1;
  int *piVar2;
  
  *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + 4;
  pfVar1 = *(float **)(*(int *)(this + 0x6c) + -4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = *param_1;
  }
  else {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  return pfVar1 != (float *)0x0;
}

