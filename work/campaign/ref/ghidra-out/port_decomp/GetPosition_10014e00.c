
/* public: double __thiscall SoloudAudioPlayer::GetPosition(void) */

double __thiscall SoloudAudioPlayer::GetPosition(SoloudAudioPlayer *this)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  undefined8 local_e0;
  CHAR local_d8 [204];
  uint local_c;
  
                    /* 0x14e00  167  ?GetPosition@SoloudAudioPlayer@@QAENXZ */
  local_c = DAT_1005000c ^ (uint)&local_e0;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((*(int *)(this + 4) != 0) && (*(int *)(this + 8) != -1)) {
    bVar4 = IsPlaying(this);
    if (bVar4) {
      uVar1 = *(undefined4 *)(this + 8);
      iVar2 = *(int *)this;
      if (*(LPCRITICAL_SECTION *)(iVar2 + 4) != (LPCRITICAL_SECTION)0x0) {
        EnterCriticalSection(*(LPCRITICAL_SECTION *)(iVar2 + 4));
      }
      if (*(char *)(iVar2 + 8) != '\0') {
        FUN_1001ec20(local_d8,"%s(%d): assert(%s) failed.\n",
                     "C:\\dev\\wiggles\\Wiggles\\SoLoud\\src\\core\\soloud.cpp",0x88e,
                     "!mInsideAudioThreadMutex");
        OutputDebugStringA(local_d8);
        pcVar3 = (code *)swi(3);
        fVar6 = (float10)(*pcVar3)();
        return (double)fVar6;
      }
      *(undefined1 *)(iVar2 + 8) = 1;
      iVar5 = FUN_1001a350(uVar1);
      if (iVar5 == -1) {
        local_e0 = 0;
        FUN_1001eba0();
        __security_check_cookie(local_c ^ (uint)&local_e0);
        return (double)extraout_ST0;
      }
      local_e0 = *(undefined8 *)(*(int *)(iVar2 + 0x40 + iVar5 * 4) + 0x58);
      FUN_1001eba0();
      __security_check_cookie(local_c ^ (uint)&local_e0);
      return (double)extraout_ST0_00;
    }
  }
  local_e0 = *(undefined8 *)(this + 0x20);
  __security_check_cookie(local_c ^ (uint)&local_e0);
  return (double)extraout_ST0_01;
}

