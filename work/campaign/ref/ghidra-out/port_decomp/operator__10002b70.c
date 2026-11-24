
/* public: class AchievementManager & __thiscall AchievementManager::operator=(class
   AchievementManager &&) */

AchievementManager * __thiscall
AchievementManager::operator=(AchievementManager *this,AchievementManager *param_1)

{
  AchievementManager *pAVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2b70  48  ??4AchievementManager@@QAEAAV0@$$QAV0@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 0xb;
  pAVar1 = this;
  do {
    *(undefined4 *)pAVar1 = *(undefined4 *)(pAVar1 + iVar2);
    iVar3 = iVar3 + -1;
    pAVar1 = pAVar1 + 4;
  } while (iVar3 != 0);
  iVar3 = 0xb;
  pAVar1 = this + 0x2c;
  do {
    *(undefined4 *)pAVar1 = *(undefined4 *)(pAVar1 + iVar2);
    iVar3 = iVar3 + -1;
    pAVar1 = pAVar1 + 4;
  } while (iVar3 != 0);
  iVar3 = 0xb;
  pAVar1 = this + 0x58;
  do {
    *pAVar1 = pAVar1[iVar2];
    iVar3 = iVar3 + -1;
    pAVar1 = pAVar1 + 1;
  } while (iVar3 != 0);
  return this;
}

