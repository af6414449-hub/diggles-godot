
/* public: bool __thiscall SoloudAudioPlayer::IsStopped(void) */

bool __thiscall SoloudAudioPlayer::IsStopped(SoloudAudioPlayer *this)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  
                    /* 0x14d40  197  ?IsStopped@SoloudAudioPlayer@@QAE_NXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  bVar2 = false;
  if (*(int *)(this + 4) != 0) {
    uVar1 = *(uint *)(this + 8);
    if ((uVar1 & 0xfffff000) != 0xfffff000) {
      FUN_1001eb20();
      iVar3 = FUN_1001a350(uVar1);
      if (iVar3 != -1) {
        FUN_1001eba0();
        return false;
      }
      FUN_1001eba0();
    }
    bVar2 = true;
  }
  return bVar2;
}

