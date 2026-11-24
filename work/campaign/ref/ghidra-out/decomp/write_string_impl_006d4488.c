
/* Library Function - Single Match
    protected: void __thiscall __crt_stdio_output::output_adapter_common<char,class
   __crt_stdio_output::stream_output_adapter<char> >::write_string_impl(char const * const,int,int *
   const,class __crt_deferred_errno_cache &)const 
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_stdio_output::
output_adapter_common<char,class___crt_stdio_output::stream_output_adapter<char>_>::
write_string_impl(output_adapter_common<char,class___crt_stdio_output::stream_output_adapter<char>_>
                  *this,char *param_1,int param_2,int *param_3,__crt_deferred_errno_cache *param_4)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  
  piVar3 = *(int **)param_4;
  if (piVar3 == (int *)0x0) {
    piVar3 = __errno();
    *(int **)param_4 = piVar3;
  }
  iVar1 = *piVar3;
  pcVar5 = param_1 + param_2;
  *piVar3 = 0;
  if (param_1 != pcVar5) {
    do {
      bVar2 = stream_output_adapter<char>::write_character_without_count_update
                        ((stream_output_adapter<char> *)this,*param_1);
      if (bVar2) {
LAB_006d44fc:
        *param_3 = *param_3 + 1;
      }
      else {
        piVar4 = *(int **)param_4;
        if (piVar4 == (int *)0x0) {
          piVar4 = __errno();
          *(int **)param_4 = piVar4;
        }
        if (*piVar4 != 0x2a) {
          *param_3 = -1;
          break;
        }
        bVar2 = stream_output_adapter<char>::write_character_without_count_update
                          ((stream_output_adapter<char> *)this,'?');
        if (bVar2) goto LAB_006d44fc;
        *param_3 = -1;
      }
      param_1 = param_1 + 1;
    } while (param_1 != pcVar5);
  }
  if ((*piVar3 == 0) && (iVar1 != 0)) {
    *piVar3 = iVar1;
  }
  return;
}

