
/* public: void __thiscall SoloudAudioPlayer::SetVolume(int) */

void __thiscall SoloudAudioPlayer::SetVolume(SoloudAudioPlayer *this,int param_1)

{
                    /* 0x14fd0  253  ?SetVolume@SoloudAudioPlayer@@QAEXH@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(int *)(this + 0x2c) = param_1;
  if (*(int *)(this + 4) != 0) {
    *(float *)(*(int *)(this + 4) + 0x10) = (float)param_1 / 100.0;
    if (*(int *)(this + 8) != -1) {
      FUN_1001a1b0(*(int *)(this + 8));
    }
  }
  return;
}

