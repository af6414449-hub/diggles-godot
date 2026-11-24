
/* public: __thiscall TimeManager::TimeManager(void) */

TimeManager * __thiscall TimeManager::TimeManager(TimeManager *this)

{
  int iVar1;
  
                    /* 0x16260  39  ??0TimeManager@@QAE@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)(this + 0x1000) = 0;
  iVar1 = 0;
  do {
    *(undefined4 *)(this + iVar1 * 8) = 0;
    *(undefined4 *)(this + iVar1 * 8 + 4) = 0;
    *(undefined4 *)(this + iVar1 * 8 + 0x800) = 0;
    *(undefined4 *)(this + iVar1 * 8 + 0x804) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return this;
}

