
/* public: static class DisplayModeManager * __cdecl DisplayModeManager::GetInstance(void) */

DisplayModeManager * __cdecl DisplayModeManager::GetInstance(void)

{
                    /* 0x8e80  149  ?GetInstance@DisplayModeManager@@SAPAV1@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (s_instance == (DisplayModeManager *)0x0) {
    s_instance = (DisplayModeManager *)FUN_1003ff62(0xc);
    *(undefined8 *)s_instance = 0;
    *(undefined4 *)(s_instance + 8) = 0;
  }
  return s_instance;
}

