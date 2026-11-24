
/* Library Function - Multiple Matches With Different Base Names
    public: bool __thiscall <lambda_c7c3f778895f47e7f4eff38a8fef279a>::operator()(void)const 
    public: bool __thiscall <lambda_f765c90ab33e8386abf09c0f079d37e9>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

void FID_conflict_operator__(void)

{
  undefined4 *in_ECX;
  
  __crt_strtox::input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_>
  ::unget((input_adapter_character_source<class___crt_stdio_input::string_input_adapter<char>_> *)
          *in_ECX,*(char *)in_ECX[1]);
  *(undefined1 *)in_ECX[1] = 0;
  restore_state(*(undefined4 *)in_ECX[2],((undefined4 *)in_ECX[2])[1]);
  return;
}

