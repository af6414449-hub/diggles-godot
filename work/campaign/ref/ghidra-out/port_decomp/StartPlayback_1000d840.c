
/* protected: long __thiscall CPlayer::StartPlayback(void) */

long __thiscall CPlayer::StartPlayback(CPlayer *this)

{
  int iVar1;
  long extraout_EAX;
  int *piVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
                    /* 0xd840  261  ?StartPlayback@CPlayer@@IAEJXZ */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar2 = *(int **)(this + 8);
  if (piVar2 == (int *)0x0) {
    _wassert(L"m_pSession != NULL",L"C:\\dev\\wiggles\\port\\src\\PortVideoPlayer.cpp",0x241);
    piVar2 = *(int **)(this + 8);
  }
  local_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2,&DAT_10043470,&local_18);
  if (-1 < iVar1) {
    *(undefined4 *)(this + 0x1c) = 3;
  }
  PropVariantClear((PROPVARIANT *)&local_18);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

