
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::type_case_a(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_a(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_a(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_a(void)
     6 names - too many to list
   
   Library: Visual Studio 2019 Release */

undefined4 type_case_a(void)

{
  formatting_buffer *this;
  char *pcVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  formatting_buffer *pfVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *in_ECX;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 local_c;
  undefined4 local_8;
  
  in_ECX[8] = in_ECX[8] | 0x10;
  iVar12 = in_ECX[10];
  if (iVar12 < 0) {
    if ((*(char *)((int)in_ECX + 0x31) == 'a') || (*(char *)((int)in_ECX + 0x31) == 'A')) {
      iVar12 = 0xd;
    }
    else {
      iVar12 = 6;
    }
    in_ECX[10] = iVar12;
  }
  else if ((iVar12 == 0) &&
          ((*(char *)((int)in_ECX + 0x31) == 'g' ||
           (iVar12 = 0, *(char *)((int)in_ECX + 0x31) == 'G')))) {
    in_ECX[10] = 1;
    iVar12 = 1;
  }
  this = (formatting_buffer *)(in_ECX + 0x10);
  bVar3 = __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>
                    (this,iVar12 + 0x15d);
  if (!bVar3) {
    uVar4 = __crt_stdio_output::formatting_buffer::count<char>(this);
    in_ECX[10] = uVar4 - 0x15d;
  }
  pfVar5 = (formatting_buffer *)in_ECX[0x111];
  if ((formatting_buffer *)in_ECX[0x111] == (formatting_buffer *)0x0) {
    pfVar5 = this;
  }
  in_ECX[0xd] = pfVar5;
  in_ECX[5] = in_ECX[5] + 8;
  local_c = *(undefined4 *)(in_ECX[5] + -8);
  local_8 = *(undefined4 *)(in_ECX[5] + -4);
  uVar4 = __crt_stdio_output::formatting_buffer::count<char>(this);
  pfVar5 = (formatting_buffer *)in_ECX[0x111];
  if ((formatting_buffer *)in_ECX[0x111] == (formatting_buffer *)0x0) {
    pfVar5 = this;
  }
  uVar11 = in_ECX[2];
  iVar12 = (int)*(char *)((int)in_ECX + 0x31);
  uVar10 = in_ECX[1];
  uVar9 = *in_ECX;
  uVar8 = in_ECX[10];
  pcVar6 = __crt_stdio_output::formatting_buffer::scratch_data<char>(this);
  uVar7 = __crt_stdio_output::formatting_buffer::count<char>(this);
  ___acrt_fp_format(&local_c,pfVar5,uVar7,pcVar6,uVar4,iVar12,uVar8,uVar9,uVar10,uVar11);
  if ((((uint)in_ECX[8] >> 5 & 1) != 0) && (in_ECX[10] == 0)) {
    __crt_stdio_output::force_decimal_point((char *)in_ECX[0xd],(__crt_locale_pointers *)in_ECX[2]);
  }
  if (((*(char *)((int)in_ECX + 0x31) == 'g') || (*(char *)((int)in_ECX + 0x31) == 'G')) &&
     (((uint)in_ECX[8] >> 5 & 1) == 0)) {
    __crt_stdio_output::crop_zeroes((char *)in_ECX[0xd],(__crt_locale_pointers *)in_ECX[2]);
  }
  pcVar6 = (char *)in_ECX[0xd];
  cVar2 = *pcVar6;
  if (cVar2 == '-') {
    in_ECX[8] = in_ECX[8] | 0x40;
    pcVar6 = pcVar6 + 1;
    in_ECX[0xd] = pcVar6;
    cVar2 = *pcVar6;
  }
  if (((cVar2 == 'i') || (cVar2 == 'I')) || ((cVar2 == 'n' || (cVar2 == 'N')))) {
    in_ECX[8] = in_ECX[8] & 0xfffffff7;
    *(undefined1 *)((int)in_ECX + 0x31) = 0x73;
  }
  pcVar1 = pcVar6 + 1;
  do {
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  in_ECX[0xe] = (int)pcVar6 - (int)pcVar1;
  return 1;
}

