
/* public: __thiscall SoloudAudioPlayer::SoloudAudioPlayer(int) */

SoloudAudioPlayer * __thiscall
SoloudAudioPlayer::SoloudAudioPlayer(SoloudAudioPlayer *this,int param_1)

{
                    /* 0x14670  38  ??0SoloudAudioPlayer@@QAE@H@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(int *)(this + 0x30) = param_1;
  *(undefined **)this = &DAT_10051110;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0x28] = (SoloudAudioPlayer)0x0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return this;
}

