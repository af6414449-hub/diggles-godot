
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::state_case_normal(void)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_output::
output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
::state_case_normal(output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                    *this)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = state_case_normal_common();
  if (cVar1 == '\0') {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return false;
  }
  return true;
}

