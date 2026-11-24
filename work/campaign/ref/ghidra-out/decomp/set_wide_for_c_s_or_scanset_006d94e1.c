
/* Library Function - Single Match
    private: void __thiscall
   __crt_stdio_input::format_string_parser<char>::set_wide_for_c_s_or_scanset(void)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall
__crt_stdio_input::format_string_parser<char>::set_wide_for_c_s_or_scanset
          (format_string_parser<char> *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x20);
  if (iVar1 == 2) {
    this[0x24] = (format_string_parser<char>)0x0;
  }
  if (((iVar1 == 3) || (iVar1 == 4)) || (iVar1 == 8)) {
    this[0x24] = (format_string_parser<char>)0x1;
  }
  return;
}

