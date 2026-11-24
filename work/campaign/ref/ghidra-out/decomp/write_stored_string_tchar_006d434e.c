
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::string_output_adapter<char> > >::write_stored_string_tchar(char)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::string_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::string_output_adapter<char> >
   >::write_stored_string_tchar(char)
   
   Library: Visual Studio 2019 Release */

void write_stored_string_tchar(void)

{
  wchar_t _WCh;
  errno_t eVar1;
  int in_ECX;
  int iVar2;
  wchar_t *pwVar3;
  int local_14;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if ((*(char *)(in_ECX + 0x3c) == '\0') || (*(int *)(in_ECX + 0x38) < 1)) {
    __crt_stdio_output::string_output_adapter<char>::write_string
              ((string_output_adapter<char> *)(in_ECX + 0x448),*(char **)(in_ECX + 0x34),
               *(int *)(in_ECX + 0x38),(int *)(in_ECX + 0x18),
               (__crt_deferred_errno_cache *)(in_ECX + 0xc));
  }
  else {
    pwVar3 = *(wchar_t **)(in_ECX + 0x34);
    iVar2 = 0;
    if (*(int *)(in_ECX + 0x38) != 0) {
      do {
        _WCh = *pwVar3;
        pwVar3 = pwVar3 + 1;
        local_14 = 0;
        eVar1 = _wctomb_s(&local_14,local_10,6,_WCh);
        if ((eVar1 != 0) || (local_14 == 0)) {
          *(undefined4 *)(in_ECX + 0x18) = 0xffffffff;
          break;
        }
        __crt_stdio_output::string_output_adapter<char>::write_string
                  ((string_output_adapter<char> *)(in_ECX + 0x448),local_10,local_14,
                   (int *)(in_ECX + 0x18),(__crt_deferred_errno_cache *)(in_ECX + 0xc));
        iVar2 = iVar2 + 1;
      } while (iVar2 != *(int *)(in_ECX + 0x38));
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

