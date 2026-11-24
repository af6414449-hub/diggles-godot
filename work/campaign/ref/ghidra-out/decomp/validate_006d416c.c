
/* Library Function - Single Match
    public: bool __thiscall __crt_stdio_output::stream_output_adapter<char>::validate(void)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_output::stream_output_adapter<char>::validate(stream_output_adapter<char> *this)

{
  bool bVar1;
  int *piVar2;
  
  if (*(_iobuf **)this == (_iobuf *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return false;
  }
  bVar1 = __acrt_stdio_char_traits<char>::validate_stream_is_ansi_if_required(*(_iobuf **)this);
  return bVar1;
}

