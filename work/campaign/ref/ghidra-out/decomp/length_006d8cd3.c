
/* Library Function - Single Match
    public: unsigned int __thiscall __crt_stdio_input::format_string_parser<char>::length(void)const
   
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint __thiscall
__crt_stdio_input::format_string_parser<char>::length(format_string_parser<char> *this)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(this + 0x28);
  if (iVar1 < 0) {
    return 0;
  }
  if (1 < iVar1) {
    if (6 < iVar1) {
      if (iVar1 == 7) {
        uVar2 = to_floating_point_length(*(length_modifier *)(this + 0x20));
        return uVar2;
      }
      if (iVar1 == 8) goto LAB_006d8d0a;
      if (iVar1 != 9) {
        return 0;
      }
    }
    uVar2 = to_integer_length(*(length_modifier *)(this + 0x20));
    return uVar2;
  }
LAB_006d8d0a:
  return (this[0x24] != (format_string_parser<char>)0x0) + 1;
}

