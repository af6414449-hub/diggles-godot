
/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    int __cdecl common_vsprintf<class __crt_stdio_output::standard_base,char>(unsigned __int64,char
   * const,unsigned int,char const * const,struct __crt_locale_pointers * const,char * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_vsprintf<class___crt_stdio_output::standard_base,char>
          (__uint64 param_1,char *param_2,uint param_3,char *param_4,__crt_locale_pointers *param_5,
          char *param_6)

{
  char *******pppppppcVar1;
  int *piVar2;
  int iVar3;
  char *unaff_EDI;
  int local_488;
  char local_484 [8];
  char local_47c;
  uint local_478;
  char *******local_474;
  uint local_470;
  uint local_46c;
  undefined4 local_468;
  char *******local_464;
  output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_> local_460 [64];
  formatting_buffer local_420 [1040];
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_464 = (char *******)param_2;
  if ((param_4 == (char *)0x0) || ((param_3 != 0 && (param_2 == (char *)0x0)))) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    goto LAB_006d2b56;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_488,param_5);
  pppppppcVar1 = local_464;
  local_478 = (uint)param_1 & 2;
  local_474 = local_464;
  local_470 = param_3;
  local_46c = 0;
  if (((param_1 & 2) != 0) || (local_468 = 0, local_464 == (char *******)0x0)) {
    local_468 = 1;
  }
  local_464 = (char *******)&local_474;
  __crt_stdio_output::
  output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_>::
  output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_>
            (local_460,(string_output_adapter<char> *)&local_464,CONCAT44(param_4,param_1._4_4_),
             local_484,(__crt_locale_pointers *)param_6,unaff_EDI);
  local_10 = 0;
  iVar3 = __crt_stdio_output::
          output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
          ::process((output_processor<char,class___crt_stdio_output::string_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::string_output_adapter<char>_>_>
                     *)local_460);
  if (pppppppcVar1 != (char *******)0x0) {
    if ((param_1 & 1) == 0) {
      if (local_478 == 0) {
        if (param_3 != 0) {
          if (local_46c != param_3) goto LAB_006d2b2e;
LAB_006d2b79:
          *(undefined1 *)((int)pppppppcVar1 + (param_3 - 1)) = 0;
        }
      }
      else if (param_3 != 0) {
        if (-1 < iVar3) {
          if (local_46c == param_3) goto LAB_006d2b79;
          goto LAB_006d2b2e;
        }
        *(undefined1 *)pppppppcVar1 = 0;
      }
    }
    else if (((param_3 != 0) || (iVar3 == 0)) && (local_46c != param_3)) {
LAB_006d2b2e:
      *(undefined1 *)((int)pppppppcVar1 + local_46c) = 0;
    }
  }
  __crt_stdio_output::formatting_buffer::~formatting_buffer(local_420);
  if (local_47c != '\0') {
    *(uint *)(local_488 + 0x350) = *(uint *)(local_488 + 0x350) & 0xfffffffd;
  }
LAB_006d2b56:
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}

