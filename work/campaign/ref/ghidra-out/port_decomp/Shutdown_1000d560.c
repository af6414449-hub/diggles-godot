
/* public: long __thiscall CPlayer::Shutdown(void) */

long __thiscall CPlayer::Shutdown(CPlayer *this)

{
  long lVar1;
  
                    /* 0xd560  259  ?Shutdown@CPlayer@@QAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  lVar1 = CloseSession(this);
  MFShutdown();
  if (*(HANDLE *)(this + 0x20) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(this + 0x20));
    *(undefined4 *)(this + 0x20) = 0;
  }
  return lVar1;
}

