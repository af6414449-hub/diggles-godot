
/* public: int __thiscall AchievementManager::EndValue(enum Achievements::AchID) */

int __thiscall AchievementManager::EndValue(AchievementManager *this,AchID param_1)

{
                    /* 0x2ed0  121  ?EndValue@AchievementManager@@QAEHW4AchID@Achievements@@@Z
                       0x2ed0  175
                       ?GetSuccessValue@AchievementManager@@QAEHW4AchID@Achievements@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return *(int *)(this + param_1 * 4 + 0x2c);
}

