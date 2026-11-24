
/* protected: long __thiscall CPlayer::Initialize(void) */

long __thiscall CPlayer::Initialize(CPlayer *this)

{
  DWORD DVar1;
  HANDLE pvVar2;
  
                    /* 0xcfb0  184  ?Initialize@CPlayer@@IAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  DVar1 = MFStartup(0x20070,0);
  if (-1 < (int)DVar1) {
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)(this + 0x20) = pvVar2;
    if ((pvVar2 == (HANDLE)0x0) && (DVar1 = GetLastError(), 0 < (int)DVar1)) {
      return DVar1 & 0xffff | 0x80070000;
    }
  }
  return DVar1;
}

