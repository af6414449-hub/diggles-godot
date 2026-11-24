
/* public: __thiscall CSdlInformWindowHandle::CSdlInformWindowHandle(void) */

CSdlInformWindowHandle * __thiscall
CSdlInformWindowHandle::CSdlInformWindowHandle(CSdlInformWindowHandle *this)

{
  undefined4 uVar1;
  
                    /* 0x14290  5  ??0CSdlInformWindowHandle@@QAE@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)this = 0;
  uVar1 = SDL_CreateWindow(&DAT_10045424,10,10,10,10,0x18);
  *(undefined4 *)this = uVar1;
  return this;
}

