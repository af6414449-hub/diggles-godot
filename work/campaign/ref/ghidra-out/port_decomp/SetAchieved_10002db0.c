
/* public: void __thiscall AchievementManager::SetAchieved(enum Achievements::AchID,bool) */

void __thiscall AchievementManager::SetAchieved(AchievementManager *this,AchID param_1,bool param_2)

{
                    /* 0x2db0  237  ?SetAchieved@AchievementManager@@QAEXW4AchID@Achievements@@_N@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  this[param_1 + 0x58] = (AchievementManager)((byte)this[param_1 + 0x58] | param_2);
  return;
}

