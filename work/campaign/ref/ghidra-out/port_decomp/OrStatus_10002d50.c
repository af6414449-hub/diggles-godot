
/* public: void __thiscall AchievementManager::OrStatus(enum Achievements::AchID,int) */

void __thiscall AchievementManager::OrStatus(AchievementManager *this,AchID param_1,int param_2)

{
                    /* 0x2d50  213  ?OrStatus@AchievementManager@@QAEXW4AchID@Achievements@@H@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(uint *)(this + param_1 * 4) = *(uint *)(this + param_1 * 4) | param_2;
  return;
}

