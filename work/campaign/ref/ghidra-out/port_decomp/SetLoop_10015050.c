
/* public: void __thiscall SoloudAudioPlayer::SetLoop(bool) */

void __thiscall SoloudAudioPlayer::SetLoop(SoloudAudioPlayer *this,bool param_1)

{
  undefined3 in_stack_00000005;
  
                    /* 0x15050  243  ?SetLoop@SoloudAudioPlayer@@QAEX_N@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  this[0x28] = (SoloudAudioPlayer)param_1;
  if ((*(int *)(this + 4) != 0) && (*(int *)(this + 8) != -1)) {
    FUN_1001a020(*(int *)(this + 8),_param_1);
  }
  return;
}

