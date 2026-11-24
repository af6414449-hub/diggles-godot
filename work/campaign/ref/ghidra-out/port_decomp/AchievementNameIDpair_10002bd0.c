
/* public: __thiscall AchievementNameIDpair::AchievementNameIDpair(char const *,enum
   Achievements::AchID) */

AchievementNameIDpair * __thiscall
AchievementNameIDpair::AchievementNameIDpair
          (AchievementNameIDpair *this,char *param_1,AchID param_2)

{
                    /* 0x2bd0  2  ??0AchievementNameIDpair@@QAE@PBDW4AchID@Achievements@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(char **)this = param_1;
  *(AchID *)(this + 4) = param_2;
  return this;
}

