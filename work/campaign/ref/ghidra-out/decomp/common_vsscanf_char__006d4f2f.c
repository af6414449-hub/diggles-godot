
/* Library Function - Single Match
    int __cdecl common_vsscanf<char>(unsigned __int64,char const * const,unsigned int,char const *
   const,struct __crt_locale_pointers * const,char * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_vsscanf<char>
          (__uint64 param_1,char *param_2,uint param_3,char *param_4,__crt_locale_pointers *param_5,
          char *param_6)

{
  int *piVar1;
  int iVar2;
  char *unaff_ESI;
  int local_9c;
  char local_98 [8];
  char local_90;
  char *local_8c;
  char *local_88;
  char *local_84;
  input_processor<char,class___crt_stdio_input::string_input_adapter<char>_> local_80 [120];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if ((param_2 == (char *)0x0) || (param_4 == (char *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    iVar2 = FUN_006e5cd8(param_2,param_3);
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_9c,param_5);
    local_88 = param_2 + iVar2;
    local_8c = param_2;
    local_84 = param_2;
    __crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
    input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>
              (local_80,(string_input_adapter<char> *)&local_8c,CONCAT44(param_4,param_1._4_4_),
               local_98,(__crt_locale_pointers *)param_6,unaff_ESI);
    __crt_stdio_input::input_processor<char,class___crt_stdio_input::string_input_adapter<char>_>::
    process(local_80);
    if (local_90 != '\0') {
      *(uint *)(local_9c + 0x350) = *(uint *)(local_9c + 0x350) & 0xfffffffd;
    }
  }
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

