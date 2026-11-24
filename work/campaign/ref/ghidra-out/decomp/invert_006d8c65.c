
/* Library Function - Single Match
    public: void __thiscall __crt_stdio_input::scanset_buffer<unsigned char>::invert(void)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void __thiscall
__crt_stdio_input::scanset_buffer<unsigned_char>::invert(scanset_buffer<unsigned_char> *this)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0;
  bVar2 = this + 0x20 < this;
  if (this <= this + 0x20) {
    do {
      *this = (scanset_buffer<unsigned_char>)~(byte)*this;
      this = this + 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 != (-(uint)bVar2 & 0xffffffe0) + 0x20);
  }
  return;
}

