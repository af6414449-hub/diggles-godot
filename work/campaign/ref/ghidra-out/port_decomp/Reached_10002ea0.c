
/* public: bool __thiscall AchievementManager::Reached(enum Achievements::AchID) */

bool __thiscall AchievementManager::Reached(AchievementManager *this,AchID param_1)

{
                    /* 0x2ea0  220  ?Reached@AchievementManager@@QAE_NW4AchID@Achievements@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return *(int *)(this + param_1 * 4) == *(int *)(this + param_1 * 4 + 0x2c);
}

