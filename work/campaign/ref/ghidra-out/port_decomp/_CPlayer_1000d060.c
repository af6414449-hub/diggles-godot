
/* protected: virtual __thiscall CPlayer::~CPlayer(void) */

void __thiscall CPlayer::~CPlayer(CPlayer *this)

{
  undefined4 in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
                    /* 0xd060  40  ??1CPlayer@@MAE@XZ */
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10041ad0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  *(undefined ***)this = vftable;
  if (*(int *)(this + 8) != 0) {
    _wassert(L"m_pSession == NULL",L"C:\\dev\\wiggles\\port\\src\\PortVideoPlayer.cpp",100);
  }
  CloseSession(this);
  MFShutdown();
  if (*(HANDLE *)(this + 0x20) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(this + 0x20));
    *(undefined4 *)(this + 0x20) = 0;
  }
  ExceptionList = local_10;
  return;
}

