
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::is_character_allowed_in_string(enum
   __crt_stdio_input::conversion_mode,int)const 
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
is_character_allowed_in_string
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this,
          conversion_mode param_1,int param_2)

{
  bool bVar1;
  
  if (param_2 == -1) goto LAB_006d8cb9;
  if (param_1 == 0) {
LAB_006d8ccf:
    bVar1 = true;
  }
  else {
    if (param_1 == 1) {
      if (((param_2 < 9) || (0xd < param_2)) && (param_2 != 0x20)) goto LAB_006d8ccf;
    }
    else if ((param_1 == 8) &&
            (((byte)this[((param_2 & 0xffU) >> 3) + 0x44] & (byte)(1 << ((byte)param_2 & 7))) != 0))
    goto LAB_006d8ccf;
LAB_006d8cb9:
    bVar1 = false;
  }
  return bVar1;
}

