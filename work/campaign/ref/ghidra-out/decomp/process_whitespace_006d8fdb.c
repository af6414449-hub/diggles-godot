
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::process_whitespace(void)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
process_whitespace(input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this)

{
  int iVar1;
  
  iVar1 = skip_whitespace<class___crt_stdio_input::string_input_adapter,char>
                    ((string_input_adapter<char> *)(this + 8),
                     *(__crt_locale_pointers **)(this + 0x68));
  string_input_adapter<char>::unget((string_input_adapter<char> *)(this + 8),iVar1);
  return true;
}

