
/* Library Function - Single Match
    public: wchar_t * __thiscall __crt_win32_buffer<wchar_t,struct
   __crt_win32_buffer_public_dynamic_resizing>::detach(void)
   
   Library: Visual Studio 2019 Release */

wchar_t * __thiscall
__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing>::detach
          (__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing> *this)

{
  int iVar1;
  wchar_t *_Dst;
  
  _Dst = *(wchar_t **)(this + 8);
  if ((_Dst == (wchar_t *)0x0) || (iVar1 = *(int *)(this + 0x10), iVar1 == 0)) {
    _Dst = (wchar_t *)0x0;
  }
  else {
    if ((this[0x14] ==
         (__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing>)0x0) &&
       (iVar1 != 0)) {
      _Dst = (wchar_t *)FUN_006df64c(iVar1 * 2);
      _memcpy_s(_Dst,*(rsize_t *)(this + 0x10),*(void **)(this + 8),*(rsize_t *)(this + 0xc));
    }
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 8) = *(undefined4 *)this;
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 4);
  }
  return _Dst;
}

