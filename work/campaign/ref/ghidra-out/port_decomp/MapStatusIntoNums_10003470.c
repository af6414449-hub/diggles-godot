
/* public: void __thiscall AchievementManager::MapStatusIntoNums(int &,int &) */

void __thiscall
AchievementManager::MapStatusIntoNums(AchievementManager *this,int *param_1,int *param_2)

{
  uint uVar1;
  
                    /* 0x3470  204  ?MapStatusIntoNums@AchievementManager@@QAEXAAH0@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *param_2 = *(int *)(this + 0x28);
  *param_1 = 0;
  uVar1 = *(uint *)this;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 4) * 2 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 8) << 2 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 0xc) << 3 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 0x10) << 4 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 0x14) << 5 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 0x18) << 6 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 0x1c) << 7 | uVar1;
  *param_1 = uVar1;
  uVar1 = *(int *)(this + 0x20) << 8 | uVar1;
  *param_1 = uVar1;
  *param_1 = *(int *)(this + 0x24) << 0xb | uVar1;
  return;
}

