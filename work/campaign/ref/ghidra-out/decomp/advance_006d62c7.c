
/* Library Function - Single Match
    public: bool __thiscall __crt_stdio_input::format_string_parser<char>::advance(void)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::format_string_parser<char>::advance(format_string_parser<char> *this)

{
  format_string_parser<char> *pfVar1;
  format_string_parser<char> fVar2;
  format_string_parser<char> *pfVar3;
  bool bVar4;
  int iVar5;
  
  if (*(int *)(this + 0xc) == 0) {
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined2 *)(this + 0x14) = 0;
    this[0x16] = (format_string_parser<char>)0x0;
    *(undefined4 *)(this + 0x18) = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined4 *)(this + 0x20) = 0;
    this[0x24] = (format_string_parser<char>)0x0;
    *(undefined4 *)(this + 0x28) = 0;
    if (**(byte **)(this + 8) == 0) {
      *(undefined4 *)(this + 0x10) = 1;
    }
    else {
      iVar5 = _isspace((uint)**(byte **)(this + 8));
      pfVar3 = *(format_string_parser<char> **)(this + 8);
      if (iVar5 != 0) {
        *(undefined4 *)(this + 0x10) = 2;
        fVar2 = *pfVar3;
        while (iVar5 = _isspace((uint)(byte)fVar2), iVar5 != 0) {
          *(int *)(this + 8) = *(int *)(this + 8) + 1;
          fVar2 = **(format_string_parser<char> **)(this + 8);
        }
        return true;
      }
      if ((*pfVar3 != (format_string_parser<char>)0x25) ||
         (pfVar1 = pfVar3 + 1, *pfVar1 == (format_string_parser<char>)0x25)) {
        *(undefined4 *)(this + 0x10) = 3;
        this[0x14] = *pfVar3;
        *(format_string_parser<char> **)(this + 8) =
             pfVar3 + (*pfVar3 == (format_string_parser<char>)0x25) + 1;
        bVar4 = scan_optional_literal_character_trail_bytes_tchar(this,'\0');
        return bVar4;
      }
      *(undefined4 *)(this + 0x10) = 4;
      *(format_string_parser<char> **)(this + 8) = pfVar1;
      if (*pfVar1 == (format_string_parser<char>)0x2a) {
        this[0x16] = (format_string_parser<char>)0x1;
        *(format_string_parser<char> **)(this + 8) = pfVar3 + 2;
      }
      bVar4 = scan_optional_field_width(this);
      if (bVar4) {
        scan_optional_length_modifier(this);
        scan_optional_wide_modifier(this);
        bVar4 = scan_conversion_specifier(this);
        if (bVar4) {
          if ((&DAT_00716e28)[*(int *)(this + 0x20) + *(int *)(this + 0x28) * 0xc] != '\0') {
            return true;
          }
          *(undefined4 *)(this + 0x10) = 0;
          *(undefined2 *)(this + 0x14) = 0;
          this[0x16] = (format_string_parser<char>)0x0;
          *(undefined4 *)(this + 0x18) = 0;
          *(undefined4 *)(this + 0x1c) = 0;
          *(undefined4 *)(this + 0x20) = 0;
          this[0x24] = (format_string_parser<char>)0x0;
          *(undefined4 *)(this + 0x28) = 0;
          *(undefined4 *)(this + 0xc) = 0x16;
        }
      }
    }
  }
  return false;
}

