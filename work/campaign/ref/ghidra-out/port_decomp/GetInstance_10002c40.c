
/* public: static class AchievementManager * __cdecl AchievementManager::GetInstance(void) */

AchievementManager * __cdecl AchievementManager::GetInstance(void)

{
  AchievementManager *this;
  
                    /* 0x2c40  147  ?GetInstance@AchievementManager@@SAPAV1@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (s_instance == (AchievementManager *)0x0) {
    this = (AchievementManager *)FUN_1003ff62(100);
    s_instance = (AchievementManager *)AchievementManager(this);
  }
  return s_instance;
}

