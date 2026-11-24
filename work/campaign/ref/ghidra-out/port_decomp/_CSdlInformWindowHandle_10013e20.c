
/* public: __thiscall CSdlInformWindowHandle::~CSdlInformWindowHandle(void) */

void __thiscall CSdlInformWindowHandle::~CSdlInformWindowHandle(CSdlInformWindowHandle *this)

{
                    /* 0x13e20  41  ??1CSdlInformWindowHandle@@QAE@XZ
                       0x13e20  44  ??1CSdlWindowHandle@@QAE@XZ
                       0x13e20  106  ?Close@CSdlWindowHandle@@AAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)this != 0) {
    SDL_DestroyWindow(*(int *)this);
  }
  return;
}

