
/* public: char const * __thiscall DisplayModeManager::GetLine(void) */

char * __thiscall DisplayModeManager::GetLine(DisplayModeManager *this)

{
  char *pcVar1;
  
                    /* 0x8e50  154  ?GetLine@DisplayModeManager@@QAEPBDXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)this == 1) {
    return "Fullscreen";
  }
  pcVar1 = "Borderless";
  if (*(int *)this != 4) {
    pcVar1 = "Windowed";
  }
  return pcVar1;
}

