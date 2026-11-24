
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::type_case_s(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_s(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_s(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_s(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

undefined4 type_case_s(void)

{
  bool bVar1;
  undefined4 uVar2;
  __uint64 *in_ECX;
  int iVar3;
  char *pcVar4;
  
  *(int *)((int)in_ECX + 0x14) = *(int *)((int)in_ECX + 0x14) + 4;
  iVar3 = (int)in_ECX[5];
  pcVar4 = *(char **)(*(int *)((int)in_ECX + 0x14) + -4);
  *(char **)((int)in_ECX + 0x34) = pcVar4;
  if (iVar3 == -1) {
    iVar3 = 0x7fffffff;
  }
  bVar1 = __crt_stdio_output::is_wide_character_specifier<char>
                    (*in_ECX,*(char *)((int)in_ECX + 0x31),*(length_modifier *)((int)in_ECX + 0x2c))
  ;
  if (bVar1) {
    if ((wchar_t *)pcVar4 == (wchar_t *)0x0) {
      *(wchar_t **)((int)in_ECX + 0x34) = L"(null)";
      pcVar4 = (char *)L"(null)";
    }
    *(undefined1 *)((int)in_ECX + 0x3c) = 1;
    uVar2 = FUN_006e5dfa(pcVar4,iVar3);
  }
  else {
    if ((wchar_t *)pcVar4 == (wchar_t *)0x0) {
      pcVar4 = "(null)";
      *(char **)((int)in_ECX + 0x34) = "(null)";
    }
    uVar2 = FUN_006e5cd8(pcVar4,iVar3);
  }
  *(undefined4 *)(in_ECX + 7) = uVar2;
  return 1;
}

