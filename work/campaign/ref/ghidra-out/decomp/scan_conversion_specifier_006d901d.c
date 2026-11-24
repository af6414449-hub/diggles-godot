
/* Library Function - Single Match
    private: bool __thiscall
   __crt_stdio_input::format_string_parser<char>::scan_conversion_specifier(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::format_string_parser<char>::scan_conversion_specifier
          (format_string_parser<char> *this)

{
  byte bVar1;
  bool bVar2;
  
  bVar1 = **(byte **)(this + 8);
  if (bVar1 < 0x65) {
    if (bVar1 == 100) {
      *(undefined4 *)(this + 0x28) = 3;
      goto LAB_006d90db;
    }
    if (bVar1 < 0x54) {
      if (bVar1 == 0x53) goto LAB_006d9177;
      if (bVar1 != 0x41) {
        if (bVar1 == 0x43) goto LAB_006d9096;
        if (bVar1 < 0x45) {
LAB_006d9145:
          *(undefined4 *)(this + 0xc) = 0x16;
          *(undefined4 *)(this + 0x10) = 0;
          *(undefined2 *)(this + 0x14) = 0;
          this[0x16] = (format_string_parser<char>)0x0;
          *(undefined4 *)(this + 0x18) = 0;
          *(undefined4 *)(this + 0x1c) = 0;
          *(undefined4 *)(this + 0x20) = 0;
          this[0x24] = (format_string_parser<char>)0x0;
          *(undefined4 *)(this + 0x28) = 0;
          return false;
        }
        if (0x47 < bVar1) {
          if (bVar1 != 0x49) goto LAB_006d9145;
          goto LAB_006d906c;
        }
      }
    }
    else {
      if (bVar1 == 0x58) goto LAB_006d912c;
      if (bVar1 == 0x5b) {
        set_wide_for_c_s_or_scanset(this);
        *(int *)(this + 8) = *(int *)(this + 8) + 1;
        *(undefined4 *)(this + 0x28) = 8;
        bVar2 = scan_scanset_range(this);
        return bVar2;
      }
      if (bVar1 != 0x61) {
        if (bVar1 != 99) goto LAB_006d9145;
LAB_006d9096:
        if (*(int *)(this + 0x18) == 0 && *(int *)(this + 0x1c) == 0) {
          *(undefined4 *)(this + 0x18) = 1;
          *(undefined4 *)(this + 0x1c) = 0;
        }
        set_wide_for_c_s_or_scanset(this);
        *(undefined4 *)(this + 0x28) = 0;
        goto LAB_006d9185;
      }
    }
LAB_006d911c:
    *(undefined4 *)(this + 0x28) = 7;
  }
  else {
    if (bVar1 < 0x71) {
      if (bVar1 != 0x70) {
        if (bVar1 < 0x65) goto LAB_006d9145;
        if (0x67 < bVar1) {
          if (bVar1 != 0x69) {
            if (bVar1 == 0x6e) {
              *(undefined4 *)(this + 0x28) = 9;
            }
            else {
              if (bVar1 != 0x6f) goto LAB_006d9145;
              *(undefined4 *)(this + 0x28) = 4;
            }
            goto LAB_006d90db;
          }
LAB_006d906c:
          *(undefined4 *)(this + 0x28) = 2;
          goto LAB_006d90db;
        }
        goto LAB_006d911c;
      }
      *(undefined4 *)(this + 0x20) = 9;
    }
    else {
      if (bVar1 == 0x73) {
LAB_006d9177:
        set_wide_for_c_s_or_scanset(this);
        *(undefined4 *)(this + 0x28) = 1;
LAB_006d9185:
        *(int *)(this + 8) = *(int *)(this + 8) + 1;
        return true;
      }
      if (bVar1 == 0x75) {
        *(undefined4 *)(this + 0x28) = 5;
        goto LAB_006d90db;
      }
      if (bVar1 != 0x78) goto LAB_006d9145;
    }
LAB_006d912c:
    *(undefined4 *)(this + 0x28) = 6;
  }
LAB_006d90db:
  *(byte **)(this + 8) = *(byte **)(this + 8) + 1;
  return true;
}

