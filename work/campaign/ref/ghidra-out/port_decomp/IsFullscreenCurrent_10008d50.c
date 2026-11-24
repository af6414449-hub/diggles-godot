
/* public: bool __thiscall DisplayModeManager::IsFullscreenCurrent(void) */

bool __thiscall DisplayModeManager::IsFullscreenCurrent(DisplayModeManager *this)

{
                    /* 0x8d50  194  ?IsFullscreenCurrent@DisplayModeManager@@QAE_NXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return *(int *)(this + 4) == 1;
}

