
/* public: bool __thiscall SoloudAudioPlayer::Stop(void) */

bool __thiscall SoloudAudioPlayer::Stop(SoloudAudioPlayer *this)

{
  bool bVar1;
  double dVar2;
  
                    /* 0x14bd0  263  ?Stop@SoloudAudioPlayer@@QAE_NXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  bVar1 = false;
  if ((*(int *)(this + 4) != 0) && (*(int *)(this + 8) != -1)) {
    dVar2 = GetPosition(this);
    *(double *)(this + 0x20) = dVar2;
    FUN_1001a9c0(*(undefined4 *)(this + 8));
    *(undefined4 *)(this + 8) = 0xffffffff;
    bVar1 = true;
  }
  return bVar1;
}

