
/* public: __thiscall Texture::Image::Image(wchar_t const *) */

Image * __thiscall Texture::Image::Image(Image *this,wchar_t *param_1)

{
                    /* 0x154f0  35  ??0Image@Texture@@QAE@PB_W@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)this = 0;
  *(int *)(this + 8) = 0;
  *(int *)(this + 4) = 0;
  LoadPixelsFromBMP(param_1,(void **)(this + 0xc),(int *)this,(int *)(this + 4),(int *)(this + 8));
  return this;
}

