
/* public: int __thiscall TimeManager::GetFreeTimerIndex(void) */

int __thiscall TimeManager::GetFreeTimerIndex(TimeManager *this)

{
  int iVar1;
  
                    /* 0x16300  140  ?GetFreeTimerIndex@TimeManager@@QAEHXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(this + 0x1000);
  *(int *)(this + 0x1000) = iVar1 + 1;
  return iVar1;
}

