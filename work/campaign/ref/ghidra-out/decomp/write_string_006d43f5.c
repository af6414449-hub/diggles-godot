
/* Library Function - Single Match
    public: void __thiscall __crt_stdio_output::stream_output_adapter<char>::write_string(char const
   * const,int,int * const,class __crt_deferred_errno_cache &)const 
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_stdio_output::stream_output_adapter<char>::write_string
          (stream_output_adapter<char> *this,char *param_1,int param_2,int *param_3,
          __crt_deferred_errno_cache *param_4)

{
  if (((*(uint *)(*(int *)this + 0xc) >> 0xc & 1) != 0) && (*(int *)(*(int *)this + 4) == 0)) {
    *param_3 = *param_3 + param_2;
    return;
  }
  output_adapter_common<char,class___crt_stdio_output::stream_output_adapter<char>_>::
  write_string_impl((output_adapter_common<char,class___crt_stdio_output::stream_output_adapter<char>_>
                     *)this,param_1,param_2,param_3,param_4);
  return;
}

