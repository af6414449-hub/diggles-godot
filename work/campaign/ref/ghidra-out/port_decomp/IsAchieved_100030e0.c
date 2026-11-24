
/* public: bool __thiscall AchievementManager::IsAchieved(enum Achievements::AchID) */

bool __thiscall AchievementManager::IsAchieved(AchievementManager *this,AchID param_1)

{
                    /* 0x30e0  189  ?IsAchieved@AchievementManager@@QAE_NW4AchID@Achievements@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return (bool)this[param_1 + 0x58];
}

