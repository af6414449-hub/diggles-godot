
/* Library Function - Single Match
    public: int __thiscall <lambda_0be4ab1c2a6918fda4e39227d83ea893>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

int __thiscall
<lambda_0be4ab1c2a6918fda4e39227d83ea893>::operator()
          (<lambda_0be4ab1c2a6918fda4e39227d83ea893> *this)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  char *unaff_EDI;
  int local_478;
  char local_474 [8];
  char local_46c;
  undefined4 local_468;
  undefined4 local_464;
  output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_> local_460 [64];
  formatting_buffer local_420 [1040];
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar1 = **(undefined4 **)this;
  uVar2 = ___acrt_stdio_begin_temporary_buffering_nolock(uVar1);
  local_468 = CONCAT31(local_468._1_3_,uVar2);
  _LocaleUpdate::_LocaleUpdate
            ((_LocaleUpdate *)&local_478,(__crt_locale_pointers *)**(undefined4 **)(this + 4));
  local_464 = **(undefined4 **)this;
  __crt_stdio_output::
  output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_>::
  output_adapter_data<char,class___crt_stdio_output::string_output_adapter<char>_>
            (local_460,(string_output_adapter<char> *)&local_464,
             CONCAT44(**(undefined4 **)(this + 0xc),*(undefined4 *)(*(int *)(this + 8) + 4)),
             local_474,(__crt_locale_pointers *)**(undefined4 **)(this + 0x10),unaff_EDI);
  local_10 = 0;
  __crt_stdio_output::
  output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
  ::process((output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
             *)local_460);
  __crt_stdio_output::formatting_buffer::~formatting_buffer(local_420);
  if (local_46c != '\0') {
    *(uint *)(local_478 + 0x350) = *(uint *)(local_478 + 0x350) & 0xfffffffd;
  }
  ___acrt_stdio_end_temporary_buffering_nolock(local_468,uVar1);
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}

