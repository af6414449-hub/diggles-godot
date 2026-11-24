
/* Library Function - Single Match
    private: bool __thiscall
   __crt_stdio_input::format_string_parser<char>::scan_optional_field_width(void)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::format_string_parser<char>::scan_optional_field_width
          (format_string_parser<char> *this)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  int local_8;
  
  cVar1 = **(char **)(this + 8);
  if ((byte)(cVar1 - 0x30U) < 10) {
    uVar3 = (int)cVar1 - 0x30;
  }
  else if ((byte)(cVar1 + 0x9fU) < 0x1a) {
    uVar3 = (int)cVar1 - 0x57;
  }
  else if ((byte)(cVar1 + 0xbfU) < 0x1a) {
    uVar3 = (int)cVar1 - 0x37;
  }
  else {
    uVar3 = 0xffffffff;
  }
  if (uVar3 < 10) {
    local_8 = 0;
    lVar4 = strtoull(*(char **)(this + 8),&local_8,10);
    if ((lVar4 == 0) || (local_8 == *(int *)(this + 8))) {
      *(undefined4 *)(this + 0x10) = 0;
      bVar2 = false;
      *(undefined2 *)(this + 0x14) = 0;
      this[0x16] = (format_string_parser<char>)0x0;
      *(undefined4 *)(this + 0x18) = 0;
      *(undefined4 *)(this + 0x1c) = 0;
      *(undefined4 *)(this + 0x20) = 0;
      this[0x24] = (format_string_parser<char>)0x0;
      *(undefined4 *)(this + 0x28) = 0;
      *(undefined4 *)(this + 0xc) = 0x16;
    }
    else {
      bVar2 = true;
      *(longlong *)(this + 0x18) = lVar4;
      *(int *)(this + 8) = local_8;
    }
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}

