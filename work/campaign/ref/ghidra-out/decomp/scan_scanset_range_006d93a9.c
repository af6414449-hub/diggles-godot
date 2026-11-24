
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_input::format_string_parser<char>::scan_scanset_range(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_input::format_string_parser<char>::scan_scanset_range(format_string_parser<char> *this)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  format_string_parser<char> *pfVar7;
  byte *pbVar8;
  byte *local_c;
  
  if (this + 0x2c == (format_string_parser<char> *)0x0) {
    *(undefined4 *)(this + 0xc) = 0xc;
    *(undefined2 *)(this + 0x14) = 0;
  }
  else {
    pfVar7 = this + 0x2c;
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined4 *)pfVar7 = 0;
      pfVar7 = pfVar7 + 4;
    }
    pbVar8 = *(byte **)(this + 8);
    bVar1 = *pbVar8;
    bVar6 = bVar1;
    if (bVar1 == 0x5e) {
      pbVar8 = pbVar8 + 1;
      *(byte **)(this + 8) = pbVar8;
      bVar6 = *pbVar8;
    }
    if (bVar6 == 0x5d) {
      pbVar8 = pbVar8 + 1;
      *(byte **)(this + 8) = pbVar8;
      this[0x37] = (format_string_parser<char>)((byte)this[0x37] | 0x20);
      bVar6 = *pbVar8;
    }
    local_c = (byte *)0x0;
    pbVar3 = pbVar8;
    while ((bVar6 != 0x5d && (bVar6 != 0))) {
      if ((bVar6 == 0x2d) && ((pbVar3 + -1 != local_c && (pbVar3 != pbVar8)))) {
        bVar2 = pbVar3[1];
        if (bVar2 == 0x5d) goto LAB_006d9483;
        bVar6 = pbVar3[-1];
        bVar4 = bVar2;
        if (bVar2 < bVar6) {
          bVar4 = bVar6;
          bVar6 = bVar2;
        }
        for (; local_c = pbVar3 + 1, bVar6 != (byte)(bVar4 + 1); bVar6 = bVar6 + 1) {
          this[(bVar6 >> 3) + 0x2c] =
               (format_string_parser<char>)
               ((byte)this[(bVar6 >> 3) + 0x2c] | (byte)(1 << (bVar6 & 7)));
        }
      }
      else {
LAB_006d9483:
        this[(bVar6 >> 3) + 0x2c] =
             (format_string_parser<char>)
             ((byte)this[(bVar6 >> 3) + 0x2c] | (byte)(1 << (bVar6 & 7)));
      }
      pbVar3 = (byte *)(*(int *)(this + 8) + 1);
      *(byte **)(this + 8) = pbVar3;
      bVar6 = *pbVar3;
    }
    if (*pbVar3 != 0) {
      if (bVar1 == 0x5e) {
        scanset_buffer<unsigned_char>::invert((scanset_buffer<unsigned_char> *)(this + 0x2c));
        pbVar3 = *(byte **)(this + 8);
      }
      *(byte **)(this + 8) = pbVar3 + 1;
      return true;
    }
    *(undefined2 *)(this + 0x14) = 0;
    *(undefined4 *)(this + 0xc) = 0x16;
  }
  *(undefined4 *)(this + 0x28) = 0;
  this[0x24] = (format_string_parser<char>)0x0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x16] = (format_string_parser<char>)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  return false;
}

