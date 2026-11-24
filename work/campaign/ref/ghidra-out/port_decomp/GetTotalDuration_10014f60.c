
/* public: double __thiscall SoloudAudioPlayer::GetTotalDuration(void) */

double __thiscall SoloudAudioPlayer::GetTotalDuration(SoloudAudioPlayer *this)

{
  int iVar1;
  double local_10;
  
                    /* 0x14f60  176  ?GetTotalDuration@SoloudAudioPlayer@@QAENXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(this + 4);
  local_10 = 0.0;
  if ((iVar1 != 0) && (local_10 = 0.0, *(float *)(iVar1 + 0xc) != (float)(undefined *)0x0)) {
    local_10 = (double)((float)((double)*(int *)(iVar1 + 0x78) +
                               *(double *)(&DAT_10047c80 + (*(int *)(iVar1 + 0x78) >> 0x1f) * -8)) /
                       *(float *)(iVar1 + 0xc));
  }
  return local_10;
}

