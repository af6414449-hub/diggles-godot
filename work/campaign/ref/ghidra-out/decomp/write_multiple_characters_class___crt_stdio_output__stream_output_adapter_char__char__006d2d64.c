
/* Library Function - Single Match
    void __cdecl __crt_stdio_output::write_multiple_characters<class
   __crt_stdio_output::stream_output_adapter<char>,char>(class
   __crt_stdio_output::stream_output_adapter<char> const &,char,int,int * const)
   
   Library: Visual Studio 2019 Release */

void __cdecl
__crt_stdio_output::
write_multiple_characters<class___crt_stdio_output::stream_output_adapter<char>,char>
          (stream_output_adapter<char> *param_1,char param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    do {
      bVar1 = stream_output_adapter<char>::write_character_without_count_update(param_1,param_2);
      if (bVar1) {
        *param_4 = *param_4 + 1;
        iVar2 = *param_4;
      }
      else {
        *param_4 = -1;
        iVar2 = -1;
      }
    } while ((iVar2 != -1) && (iVar3 = iVar3 + 1, iVar3 < param_3));
  }
  return;
}

