
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::process_integer_specifier(unsigned int,bool)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
process_integer_specifier
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this,
          uint param_1,bool param_2)

{
  bool bVar1;
  __uint64 _Var2;
  undefined1 auStack_38 [28];
  undefined4 uStack_1c;
  undefined4 uStack_8;
  
  uStack_8 = this;
  process_whitespace(this);
  uStack_8 = (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *)
             ((uint)uStack_8 & 0xffffff);
  make_input_adapter_character_source<>
            (auStack_38,this + 8,*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x34),
             (int)&uStack_8 + 3);
  _Var2 = __crt_strtox::
          parse_integer<unsigned___int64,class___crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>_>
                    (*(undefined4 *)(this + 0x68));
  if (uStack_8._3_1_ == '\0') {
    bVar1 = false;
  }
  else if (this[0x2e] ==
           (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>)0x0) {
    uStack_1c = 0x6d8ec8;
    bVar1 = write_integer(this,_Var2);
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

