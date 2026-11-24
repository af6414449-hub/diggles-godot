
/* Library Function - Single Match
    protected: __thiscall __crt_stdio_output::output_adapter_data<char,class
   __crt_stdio_output::string_output_adapter<char> >::output_adapter_data<char,class
   __crt_stdio_output::string_output_adapter<char> >(class
   __crt_stdio_output::string_output_adapter<char> const &,unsigned __int64,char const *
   const,struct __crt_locale_pointers * const,char * const)
   
   Library: Visual Studio 2019 Release */

output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_> * __thiscall
__crt_stdio_output::output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_>
::output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_>
          (output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_> *this,
          string_output_adapter<char> *param_1,__uint64 param_2,char *param_3,
          __crt_locale_pointers *param_4,char *param_5)

{
  undefined4 in_stack_00000008;
  
  common_data<char>::common_data<char>((common_data<char> *)this);
  *(undefined4 *)(this + 0x448) = *(undefined4 *)param_1;
  *(undefined4 *)this = in_stack_00000008;
  *(undefined4 *)(this + 4) = (undefined4)param_2;
  *(char **)(this + 8) = param_3;
  *(undefined4 *)(this + 0x10) = param_2._4_4_;
  *(__crt_locale_pointers **)(this + 0x14) = param_4;
  return this;
}

