
/* public: bool __thiscall SoloudAudioPlayer::Pause(void) */

bool __thiscall SoloudAudioPlayer::Pause(SoloudAudioPlayer *this)

{
  int iVar1;
  undefined4 extraout_ECX;
  
                    /* 0x14ba0  215  ?Pause@SoloudAudioPlayer@@QAE_NXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(this + 4);
  if (iVar1 != 0) {
    FUN_10019e90(*(undefined4 *)(this + 8),extraout_ECX);
  }
  return iVar1 != 0;
}

