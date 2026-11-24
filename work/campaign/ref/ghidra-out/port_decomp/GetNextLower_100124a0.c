
/* public: int __thiscall ScreenResolutionManager::GetNextLower(void) */

int __thiscall ScreenResolutionManager::GetNextLower(ScreenResolutionManager *this)

{
  int iVar1;
  int iVar2;
  
                    /* 0x124a0  163  ?GetNextLower@ScreenResolutionManager@@QAEHXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)(this + 8);
  iVar2 = iVar1 + -1;
  *(int *)(this + 8) = iVar2;
  if (iVar1 < 1) {
    iVar2 = 0;
  }
  return iVar2;
}

