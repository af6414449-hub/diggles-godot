
/* public: int __thiscall SoloudAudioPlayer::GetState(void) */

int __thiscall SoloudAudioPlayer::GetState(SoloudAudioPlayer *this)

{
  bool bVar1;
  
                    /* 0x14da0  173  ?GetState@SoloudAudioPlayer@@QAEHXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 4) == 0) {
    return -1;
  }
  bVar1 = IsStopped(this);
  if (bVar1) {
    return 0;
  }
  bVar1 = IsPaused(this);
  return 2 - (uint)bVar1;
}

