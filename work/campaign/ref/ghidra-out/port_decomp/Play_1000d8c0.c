
/* public: long __thiscall CPlayer::Play(void) */

long __thiscall CPlayer::Play(CPlayer *this)

{
  long lVar1;
  
                    /* 0xd8c0  216  ?Play@CPlayer@@QAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((*(int *)(this + 0x1c) != 4) && (*(int *)(this + 0x1c) != 5)) {
    return -0x3ff2c94e;
  }
  if ((*(int *)(this + 8) != 0) && (*(int *)(this + 0xc) != 0)) {
    lVar1 = StartPlayback(this);
    return lVar1;
  }
  return -0x7fff0001;
}

