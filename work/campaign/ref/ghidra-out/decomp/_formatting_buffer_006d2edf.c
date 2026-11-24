
/* Library Function - Single Match
    public: __thiscall __crt_stdio_output::formatting_buffer::~formatting_buffer(void)
   
   Library: Visual Studio 2019 Release */

void __thiscall __crt_stdio_output::formatting_buffer::~formatting_buffer(formatting_buffer *this)

{
  FID_conflict__free(*(void **)(this + 0x404));
  *(undefined4 *)(this + 0x404) = 0;
  return;
}

