
/* Library Function - Single Match
    private: void __thiscall
   __crt_stdio_input::format_string_parser<char>::scan_optional_length_modifier(void)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __thiscall
__crt_stdio_input::format_string_parser<char>::scan_optional_length_modifier
          (format_string_parser<char> *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = *(byte **)(this + 8);
  bVar1 = *pbVar2;
  if (bVar1 < 0x6b) {
    if (bVar1 == 0x6a) {
      pbVar3 = pbVar2 + 1;
      *(undefined4 *)(this + 0x20) = 5;
    }
    else if (bVar1 == 0x49) {
      bVar1 = pbVar2[1];
      if (bVar1 == 0x33) {
        if (pbVar2[2] != 0x32) {
LAB_006d92c5:
          if ((((bVar1 != 100) && (bVar1 != 0x69)) && (bVar1 != 0x6f)) &&
             (((bVar1 != 0x75 && (bVar1 != 0x78)) && (bVar1 != 0x58)))) {
            return;
          }
          *(byte **)(this + 8) = pbVar2 + 1;
          *(undefined4 *)(this + 0x20) = 9;
          return;
        }
        pbVar3 = pbVar2 + 3;
        *(undefined4 *)(this + 0x20) = 9;
      }
      else {
        if ((bVar1 != 0x36) || (pbVar2[2] != 0x34)) goto LAB_006d92c5;
        pbVar3 = pbVar2 + 3;
        *(undefined4 *)(this + 0x20) = 10;
      }
    }
    else if (bVar1 == 0x4c) {
      pbVar3 = pbVar2 + 1;
      *(undefined4 *)(this + 0x20) = 8;
    }
    else {
      if (bVar1 != 0x54) {
        if (bVar1 != 0x68) {
          return;
        }
        bVar1 = pbVar2[1];
        *(byte **)(this + 8) = pbVar2 + (bVar1 == 0x68) + 1;
        *(uint *)(this + 0x20) = (bVar1 != 0x68) + 1;
        return;
      }
      pbVar3 = pbVar2 + 1;
      *(undefined4 *)(this + 0x20) = 0xb;
    }
  }
  else if (bVar1 == 0x6c) {
    pbVar3 = pbVar2 + 1;
    if (*pbVar3 == 0x6c) {
      pbVar3 = pbVar2 + 2;
      *(undefined4 *)(this + 0x20) = 4;
    }
    else {
      *(undefined4 *)(this + 0x20) = 3;
    }
  }
  else if (bVar1 == 0x74) {
    pbVar3 = pbVar2 + 1;
    *(undefined4 *)(this + 0x20) = 7;
  }
  else {
    if (bVar1 != 0x7a) {
      return;
    }
    pbVar3 = pbVar2 + 1;
    *(undefined4 *)(this + 0x20) = 6;
  }
  *(byte **)(this + 8) = pbVar3;
  return;
}

