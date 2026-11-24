
/* Library Function - Single Match
    public: bool __thiscall
   __crt_stdio_output::stream_output_adapter<char>::write_character_without_count_update(char)const 
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_output::stream_output_adapter<char>::write_character_without_count_update
          (stream_output_adapter<char> *this,char param_1)

{
  int iVar1;
  bool bVar2;
  
  if (((*(uint *)(*(int *)this + 0xc) >> 0xc & 1) == 0) || (*(int *)(*(int *)this + 4) != 0)) {
    iVar1 = __fputc_nolock((int)param_1,*(undefined4 *)this);
    bVar2 = iVar1 != -1;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}

