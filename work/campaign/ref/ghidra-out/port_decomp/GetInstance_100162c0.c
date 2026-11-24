
/* public: static class TimeManager * __cdecl TimeManager::GetInstance(void) */

TimeManager * __cdecl TimeManager::GetInstance(void)

{
  TimeManager *this;
  
                    /* 0x162c0  153  ?GetInstance@TimeManager@@SAPAV1@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (s_instance == (TimeManager *)0x0) {
    this = (TimeManager *)FUN_1003ff62(0x1008);
    s_instance = (TimeManager *)TimeManager(this);
  }
  return s_instance;
}

