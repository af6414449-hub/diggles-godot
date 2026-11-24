
/* Library Function - Multiple Matches With Same Base Name
    public: bool __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::console_input_adapter<char> >::restore_state(unsigned __int64)
    public: bool __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::stream_input_adapter<char> >::restore_state(unsigned __int64)
    public: bool __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::string_input_adapter<char> >::restore_state(unsigned __int64)
   
   Library: Visual Studio 2019 Release */

undefined4 restore_state(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((param_1 == *(int *)(in_ECX + 0x10)) && (param_2 == *(int *)(in_ECX + 0x14))) {
    uVar1 = 1;
  }
  else {
    **(undefined1 **)(in_ECX + 0x18) = 0;
    uVar1 = 0;
  }
  return uVar1;
}

