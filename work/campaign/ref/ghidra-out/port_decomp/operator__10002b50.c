
/* public: class AchievementManager & __thiscall AchievementManager::operator=(class
   AchievementManager const &) */

AchievementManager * __thiscall
AchievementManager::operator=(AchievementManager *this,AchievementManager *param_1)

{
  int iVar1;
  AchievementManager *pAVar2;
  
                    /* 0x2b50  49  ??4AchievementManager@@QAEAAV0@ABV0@@Z */
  pAVar2 = this;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pAVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pAVar2 = pAVar2 + 4;
  }
  return this;
}

