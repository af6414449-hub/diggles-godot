
/* public: int __thiscall CSdlWindowHandle::GetDisplayIndex(void) */

int __thiscall CSdlWindowHandle::GetDisplayIndex(CSdlWindowHandle *this)

{
  int iVar1;
  
                    /* 0x14270  137  ?GetDisplayIndex@CSdlWindowHandle@@QAEHXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = SDL_GetWindowDisplayIndex(*(undefined4 *)this);
  return iVar1;
}

