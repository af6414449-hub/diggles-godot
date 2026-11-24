
/* public: class AchievementNameIDpair & __thiscall AchievementNameIDpair::operator=(class
   AchievementNameIDpair &&) */

AchievementNameIDpair * __thiscall
AchievementNameIDpair::operator=(AchievementNameIDpair *this,AchievementNameIDpair *param_1)

{
                    /* 0x2b10  50  ??4AchievementNameIDpair@@QAEAAV0@$$QAV0@@Z
                       0x2b10  62  ??4GammaManager@@QAEAAV0@$$QAV0@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return this;
}

