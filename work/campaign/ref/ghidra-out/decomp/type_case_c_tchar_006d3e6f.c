
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::type_case_c_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_c_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_c_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_c_tchar(char)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

undefined4 type_case_c_tchar(void)

{
  bool bVar1;
  uint _SizeInBytes;
  errno_t eVar2;
  __uint64 *in_ECX;
  formatting_buffer *pfVar3;
  formatting_buffer *this;
  wchar_t _WCh;
  
  this = (formatting_buffer *)(in_ECX + 8);
  bVar1 = __crt_stdio_output::is_wide_character_specifier<char>
                    (*in_ECX,*(char *)((int)in_ECX + 0x31),*(length_modifier *)((int)in_ECX + 0x2c))
  ;
  if (bVar1) {
    *(int *)((int)in_ECX + 0x14) = *(int *)((int)in_ECX + 0x14) + 4;
    _WCh = *(wchar_t *)(*(int *)((int)in_ECX + 0x14) + -4);
    pfVar3 = *(formatting_buffer **)((int)in_ECX + 0x444);
    if (*(formatting_buffer **)((int)in_ECX + 0x444) == (formatting_buffer *)0x0) {
      pfVar3 = this;
    }
    _SizeInBytes = __crt_stdio_output::formatting_buffer::count<char>(this);
    eVar2 = _wctomb_s((int *)(in_ECX + 7),(char *)pfVar3,_SizeInBytes,_WCh);
    if (eVar2 != 0) {
      *(undefined1 *)(in_ECX + 6) = 1;
    }
  }
  else {
    pfVar3 = *(formatting_buffer **)((int)in_ECX + 0x444);
    if (*(formatting_buffer **)((int)in_ECX + 0x444) == (formatting_buffer *)0x0) {
      pfVar3 = this;
    }
    *(int *)((int)in_ECX + 0x14) = *(int *)((int)in_ECX + 0x14) + 4;
    *pfVar3 = *(formatting_buffer *)(*(int *)((int)in_ECX + 0x14) + -4);
    *(undefined4 *)(in_ECX + 7) = 1;
  }
  pfVar3 = *(formatting_buffer **)((int)in_ECX + 0x444);
  if (pfVar3 != (formatting_buffer *)0x0) {
    this = pfVar3;
  }
  *(formatting_buffer **)((int)in_ECX + 0x34) = this;
  return CONCAT31((int3)((uint)pfVar3 >> 8),1);
}

