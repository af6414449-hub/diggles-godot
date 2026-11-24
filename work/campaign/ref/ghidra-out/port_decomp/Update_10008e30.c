
/* public: void __thiscall DisplayModeManager::Update(void) */

void __thiscall DisplayModeManager::Update(DisplayModeManager *this)

{
                    /* 0x8e30  271  ?Update@DisplayModeManager@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 4) != *(int *)this) {
    *(int *)(this + 4) = *(int *)this;
    this[8] = (DisplayModeManager)0x1;
  }
  return;
}

