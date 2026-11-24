
/* public: __thiscall Texture::Image::~Image(void) */

void __thiscall Texture::Image::~Image(Image *this)

{
                    /* 0x15540  45  ??1Image@Texture@@QAE@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(HDC *)(this + 0x10) != (HDC)0x0) {
    DeleteDC(*(HDC *)(this + 0x10));
  }
  if (*(HGDIOBJ *)(this + 0x14) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(this + 0x14));
  }
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  free(*(void **)(this + 0xc));
  return;
}

