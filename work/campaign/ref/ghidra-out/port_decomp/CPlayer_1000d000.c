
/* protected: __thiscall CPlayer::CPlayer(struct HWND__ *,struct HWND__ *) */

CPlayer * __thiscall CPlayer::CPlayer(CPlayer *this,HWND__ *param_1,HWND__ *param_2)

{
                    /* 0xd000  3  ??0CPlayer@@IAE@PAUHWND__@@0@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(HWND__ **)(this + 0x14) = param_1;
  *(HWND__ **)(this + 0x18) = param_2;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 1;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  return this;
}

