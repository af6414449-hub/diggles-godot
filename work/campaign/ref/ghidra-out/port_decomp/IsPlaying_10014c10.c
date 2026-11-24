
/* public: bool __thiscall SoloudAudioPlayer::IsPlaying(void) */

bool __thiscall SoloudAudioPlayer::IsPlaying(SoloudAudioPlayer *this)

{
  uint uVar1;
  int iVar2;
  
                    /* 0x14c10  196  ?IsPlaying@SoloudAudioPlayer@@QAE_NXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((*(int *)(this + 4) != 0) && (uVar1 = *(uint *)(this + 8), (uVar1 & 0xfffff000) != 0xfffff000)
     ) {
    FUN_1001eb20();
    iVar2 = FUN_1001a350(uVar1);
    if (iVar2 != -1) {
      FUN_1001eba0();
      return true;
    }
    FUN_1001eba0();
  }
  return false;
}

