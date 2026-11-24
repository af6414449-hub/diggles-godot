
/* public: int __thiscall DisplayIndexManager::GetNextInCycle(void) */

int __thiscall DisplayIndexManager::GetNextInCycle(DisplayIndexManager *this)

{
  int iVar1;
  
                    /* 0x8c20  161  ?GetNextInCycle@DisplayIndexManager@@QAEHXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 8) == 0) {
    return 0;
  }
  iVar1 = (*(int *)this + 1) % *(int *)(this + 8);
  *(int *)this = iVar1;
  return iVar1;
}

