
/* public: void __thiscall SoloudAudioPlayer::Tick(void) */

void __thiscall SoloudAudioPlayer::Tick(SoloudAudioPlayer *this)

{
  int iVar1;
  double dVar2;
  double dVar3;
  
                    /* 0x150b0  266  ?Tick@SoloudAudioPlayer@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(this + 4);
  if ((iVar1 != 0) && (this[0x28] != (SoloudAudioPlayer)0x0)) {
    if (*(float *)(iVar1 + 0xc) == (float)(undefined *)0x0) {
      dVar2 = 0.0;
    }
    else {
      dVar2 = (double)((float)((double)*(int *)(iVar1 + 0x78) +
                              *(double *)(&DAT_10047c80 + (*(int *)(iVar1 + 0x78) >> 0x1f) * -8)) /
                      *(float *)(iVar1 + 0xc));
    }
    dVar3 = GetPosition(this);
    if (dVar2 <= dVar3) {
      *(undefined8 *)(this + 0x10) = 0;
    }
  }
  return;
}

