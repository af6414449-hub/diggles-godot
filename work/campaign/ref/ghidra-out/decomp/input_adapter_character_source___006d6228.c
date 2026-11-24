
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::console_input_adapter<char> >::input_adapter_character_source<class
   __crt_stdio_input::console_input_adapter<char> >(class
   __crt_stdio_input::console_input_adapter<char> * const,unsigned __int64,bool * const)
    public: __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::console_input_adapter<wchar_t> >::input_adapter_character_source<class
   __crt_stdio_input::console_input_adapter<wchar_t> >(class
   __crt_stdio_input::console_input_adapter<wchar_t> * const,unsigned __int64,bool * const)
    public: __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::stream_input_adapter<char> >::input_adapter_character_source<class
   __crt_stdio_input::stream_input_adapter<char> >(class
   __crt_stdio_input::stream_input_adapter<char> * const,unsigned __int64,bool * const)
    public: __thiscall __crt_strtox::input_adapter_character_source<class
   __crt_stdio_input::stream_input_adapter<wchar_t> >::input_adapter_character_source<class
   __crt_stdio_input::stream_input_adapter<wchar_t> >(class
   __crt_stdio_input::stream_input_adapter<wchar_t> * const,unsigned __int64,bool * const)
     6 names - too many to list
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void input_adapter_character_source<>
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined4 *in_ECX;
  
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = param_1;
  in_ECX[2] = param_2;
  in_ECX[3] = param_3;
  in_ECX[6] = param_4;
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = 1;
  }
  return;
}

