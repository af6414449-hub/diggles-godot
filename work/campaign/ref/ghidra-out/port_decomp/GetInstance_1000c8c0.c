
/* public: static class GammaManager * __cdecl GammaManager::GetInstance(void) */

GammaManager * __cdecl GammaManager::GetInstance(void)

{
                    /* 0xc8c0  150  ?GetInstance@GammaManager@@SAPAV1@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (s_instance == (GammaManager *)0x0) {
    s_instance = (GammaManager *)FUN_1003ff62(8);
    *(undefined8 *)s_instance = 0;
  }
  return s_instance;
}

