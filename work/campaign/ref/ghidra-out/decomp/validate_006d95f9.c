
/* Library Function - Multiple Matches With Same Base Name
    public: bool __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::console_input_adapter<char> >::validate(void)const 
    public: bool __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::stream_input_adapter<char> >::validate(void)const 
    public: bool __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::string_input_adapter<char> >::validate(void)const 
   
   Library: Visual Studio 2019 Release */

undefined4 validate(void)

{
  int *piVar1;
  int *in_ECX;
  
  if ((*in_ECX != 0) && (in_ECX[6] != 0)) {
    return 1;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_006e510d();
  return 0;
}

