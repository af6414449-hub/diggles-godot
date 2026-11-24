
/* public: bool __thiscall SoloudAudioPlayer::IsPaused(void) */

bool __thiscall SoloudAudioPlayer::IsPaused(SoloudAudioPlayer *this)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined1 extraout_AL;
  undefined1 extraout_AL_00;
  int iVar4;
  CHAR local_d0 [200];
  uint local_8;
  
                    /* 0x14c70  195  ?IsPaused@SoloudAudioPlayer@@QAE_NXZ */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 4) != 0) {
    uVar1 = *(undefined4 *)(this + 8);
    iVar4 = *(int *)this;
    if (*(LPCRITICAL_SECTION *)(iVar4 + 4) != (LPCRITICAL_SECTION)0x0) {
      EnterCriticalSection(*(LPCRITICAL_SECTION *)(iVar4 + 4));
    }
    if (*(char *)(iVar4 + 8) != '\0') {
      FUN_1001ec20(local_d0,"%s(%d): assert(%s) failed.\n",
                   "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x88e,
                   "!mInsideAudioThreadMutex");
      OutputDebugStringA(local_d0);
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return (bool)uVar3;
    }
    *(undefined1 *)(iVar4 + 8) = 1;
    iVar4 = FUN_1001a350(uVar1);
    if (iVar4 == -1) {
      FUN_1001eba0();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return (bool)extraout_AL;
    }
    FUN_1001eba0();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return (bool)extraout_AL_00;
}

