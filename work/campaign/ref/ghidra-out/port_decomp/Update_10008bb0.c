
/* public: void __thiscall DisplayIndexManager::Update(void) */

void __thiscall DisplayIndexManager::Update(DisplayIndexManager *this)

{
                    /* 0x8bb0  270  ?Update@DisplayIndexManager@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 4) != *(int *)this) {
    *(int *)(this + 4) = *(int *)this;
    this[0x14] = (DisplayIndexManager)0x1;
  }
  return;
}

