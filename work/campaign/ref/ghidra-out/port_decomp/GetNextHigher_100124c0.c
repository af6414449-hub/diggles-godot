
/* public: int __thiscall ScreenResolutionManager::GetNextHigher(void) */

int __thiscall ScreenResolutionManager::GetNextHigher(ScreenResolutionManager *this)

{
  int iVar1;
  
                    /* 0x124c0  160  ?GetNextHigher@ScreenResolutionManager@@QAEHXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  iVar1 = *(int *)(this + 8);
  if (*(int *)(this + 0x10) <= *(int *)(this + 8)) {
    iVar1 = *(int *)(this + 0x10) + -1;
  }
  return iVar1;
}

