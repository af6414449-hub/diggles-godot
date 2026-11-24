
/* public: void __thiscall AchievementManager::Store(enum Achievements::AchID,int) */

void __thiscall AchievementManager::Store(AchievementManager *this,AchID param_1,int param_2)

{
  int iVar1;
  
                    /* 0x2dd0  264  ?Store@AchievementManager@@QAEXW4AchID@Achievements@@H@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  OutputDebugStringA("AchievementManager::Store call start \n");
  if (param_1 == 10) {
    *(uint *)(this + 0x28) = *(uint *)(this + 0x28) | param_2;
  }
  else {
    if (this[param_1 + 0x58] != (AchievementManager)0x0) goto LAB_10002e42;
    if (param_1 == 2) {
      if (*(int *)this != *(int *)(this + 0x2c)) {
        return;
      }
      if (*(int *)(this + 4) != *(int *)(this + 0x30)) {
        return;
      }
    }
    iVar1 = GetIncrement(this,param_1);
    if (*(int *)(this + param_1 * 4 + 0x2c) <= iVar1 + *(int *)(this + param_1 * 4)) {
      *(int *)(this + param_1 * 4) = *(int *)(this + param_1 * 4 + 0x2c);
      Achieved(this,param_1);
      goto LAB_10002e42;
    }
    *(int *)(this + param_1 * 4) = iVar1 + *(int *)(this + param_1 * 4);
  }
  Triggered(this,param_1);
LAB_10002e42:
  if ((((*(int *)(this + 0x28) == *(int *)(this + 0x54)) &&
       (*(int *)(this + 8) == *(int *)(this + 0x34))) &&
      (*(int *)(this + 0xc) == *(int *)(this + 0x38))) &&
     (((*(int *)(this + 0x10) == *(int *)(this + 0x3c) &&
       (*(int *)(this + 0x14) == *(int *)(this + 0x40))) &&
      ((*(int *)(this + 0x18) == *(int *)(this + 0x44) &&
       (*(int *)(this + 0x1c) == *(int *)(this + 0x48))))))) {
    Achieved(this,10);
  }
  OutputDebugStringA("AchievementManager::Store call stop \n");
  return;
}

