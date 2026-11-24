
/* protected: long __thiscall CPlayer::CreateSession(void) */

long __thiscall CPlayer::CreateSession(CPlayer *this)

{
  int *piVar1;
  long lVar2;
  
                    /* 0xd720  111  ?CreateSession@CPlayer@@IAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  lVar2 = CloseSession(this);
  if (-1 < lVar2) {
    if (*(int *)(this + 0x1c) != 0) {
      _wassert(L"m_state == PlayerState::Closed",L"C:\\dev\\wiggles\\port\\src\\PortVideoPlayer.cpp"
               ,0x1f2);
    }
    lVar2 = MFCreateMediaSession(0,this + 8);
    if ((-1 < lVar2) &&
       (piVar1 = *(int **)(this + 8), lVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,this,0),
       -1 < lVar2)) {
      *(undefined4 *)(this + 0x1c) = 1;
    }
  }
  return lVar2;
}

