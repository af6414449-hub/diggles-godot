
/* public: class AchievementNameIDpair & __thiscall AchievementNameIDpair::operator=(class
   AchievementNameIDpair const &) */

AchievementNameIDpair * __thiscall
AchievementNameIDpair::operator=(AchievementNameIDpair *this,AchievementNameIDpair *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2af0  51  ??4AchievementNameIDpair@@QAEAAV0@ABV0@@Z
                       0x2af0  54  ??4CSdlWindow@@QAEAAV0@ABV0@@Z
                       0x2af0  63  ??4GammaManager@@QAEAAV0@ABV0@@Z */
  uVar1 = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)this = uVar1;
  return this;
}

