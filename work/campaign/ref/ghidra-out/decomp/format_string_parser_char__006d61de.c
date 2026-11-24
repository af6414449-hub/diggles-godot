
/* Library Function - Single Match
    public: __thiscall
   __crt_stdio_input::format_string_parser<char>::format_string_parser<char>(unsigned
   __int64,unsigned char const * const)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

format_string_parser<char> * __thiscall
__crt_stdio_input::format_string_parser<char>::format_string_parser<char>
          (format_string_parser<char> *this,__uint64 param_1,uchar *param_2)

{
  int iVar1;
  format_string_parser<char> *pfVar2;
  
  *(__uint64 *)this = param_1;
  *(uchar **)(this + 8) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  pfVar2 = this + 0x2c;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pfVar2 = 0;
    pfVar2 = pfVar2 + 4;
  }
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  this[0x16] = (format_string_parser<char>)0x0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  this[0x24] = (format_string_parser<char>)0x0;
  *(undefined4 *)(this + 0x28) = 0;
  return this;
}

