
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::process_string_specifier(enum
   __crt_stdio_input::conversion_mode)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
process_string_specifier
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this,
          conversion_mode param_1)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 1) {
    process_whitespace(this);
  }
  uVar2 = format_string_parser<char>::length((format_string_parser<char> *)(this + 0x18));
  if (uVar2 == 1) {
    bVar1 = process_string_specifier_tchar<char>(this,param_1,'\0');
  }
  else if (uVar2 == 2) {
    bVar1 = process_string_specifier_tchar<wchar_t>(this,param_1,L'\0');
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

