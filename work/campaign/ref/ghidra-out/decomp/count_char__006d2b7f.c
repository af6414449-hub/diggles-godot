
/* Library Function - Single Match
    public: unsigned int __thiscall __crt_stdio_output::formatting_buffer::count<char>(void)const 
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

uint __thiscall __crt_stdio_output::formatting_buffer::count<char>(formatting_buffer *this)

{
  if (*(int *)(this + 0x404) == 0) {
    return 0x200;
  }
  return *(uint *)(this + 0x400) >> 1;
}

