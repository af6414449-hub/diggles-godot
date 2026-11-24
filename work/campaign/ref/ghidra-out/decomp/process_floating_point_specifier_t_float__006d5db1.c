
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::input_processor<char,class
   __crt_stdio_input::string_input_adapter<char> >::process_floating_point_specifier_t<float>(void)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
process_floating_point_specifier_t<float>
          (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> *this)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_38 [28];
  undefined4 uStack_1c;
  float local_c;
  char local_5;
  
  local_5 = '\0';
  local_c = 0.0;
  make_input_adapter_character_source<>
            (auStack_38,this + 8,*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x34),&local_5)
  ;
  iVar2 = parse_floating_point<>(*(undefined4 *)(this + 0x68));
  if ((local_5 == '\0') || (iVar2 == 1)) {
    bVar1 = false;
  }
  else if (this[0x2e] ==
           (input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>)0x0) {
    uStack_1c = 0x6d5e10;
    bVar1 = write_floating_point<float>(this,&local_c);
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

