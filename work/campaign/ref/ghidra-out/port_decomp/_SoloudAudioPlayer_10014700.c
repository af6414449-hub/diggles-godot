
/* public: __thiscall SoloudAudioPlayer::~SoloudAudioPlayer(void) */

void __thiscall SoloudAudioPlayer::~SoloudAudioPlayer(SoloudAudioPlayer *this)

{
                    /* 0x14700  47  ??1SoloudAudioPlayer@@QAE@XZ
                       0x14700  107  ?Close@SoloudAudioPlayer@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 4) != 0) {
    FUN_1001a9c0(*(undefined4 *)(this + 8));
    if (*(int **)(this + 4) != (int *)0x0) {
      (**(code **)(**(int **)(this + 4) + 4))(1);
    }
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x14) = 0;
    *(undefined4 *)(this + 0x18) = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined8 *)(this + 0x20) = 0;
  }
  return;
}

