
/* Library Function - Multiple Matches With Same Base Name
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::console_output_adapter<char> > >::type_case_Z(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::console_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::console_output_adapter<char> >
   >::type_case_Z(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::format_validation_base<char,class
   __crt_stdio_output::stream_output_adapter<char> > >::type_case_Z(void)
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::type_case_Z(void)
     6 names - too many to list
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

undefined4 type_case_Z(void)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  bool bVar4;
  undefined3 extraout_var;
  __uint64 *in_ECX;
  uint uVar6;
  int iVar5;
  
  *(int *)((int)in_ECX + 0x14) = *(int *)((int)in_ECX + 0x14) + 4;
  iVar5 = *(int *)((int)in_ECX + 0x14);
  puVar2 = *(ushort **)(iVar5 + -4);
  if ((puVar2 == (ushort *)0x0) || (iVar3 = *(int *)(puVar2 + 2), iVar3 == 0)) {
    *(char **)((int)in_ECX + 0x34) = "(null)";
    uVar6 = 6;
  }
  else {
    bVar4 = __crt_stdio_output::is_wide_character_specifier<char>
                      (*in_ECX,*(char *)((int)in_ECX + 0x31),
                       *(length_modifier *)((int)in_ECX + 0x2c));
    iVar5 = CONCAT31(extraout_var,bVar4);
    *(int *)((int)in_ECX + 0x34) = iVar3;
    uVar1 = *puVar2;
    uVar6 = (uint)uVar1;
    if (bVar4) {
      *(undefined1 *)((int)in_ECX + 0x3c) = 1;
      uVar6 = (uint)(uVar1 >> 1);
      goto LAB_006d3d17;
    }
  }
  *(undefined1 *)((int)in_ECX + 0x3c) = 0;
LAB_006d3d17:
  *(uint *)(in_ECX + 7) = uVar6;
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}

