
/* public: void __thiscall AchievementManager::UnmapStatusFromNums(int,int) */

void __thiscall
AchievementManager::UnmapStatusFromNums(AchievementManager *this,int param_1,int param_2)

{
                    /* 0x3500  269  ?UnmapStatusFromNums@AchievementManager@@QAEXHH@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(int *)(this + 0x28) = param_2;
  if ((param_1 & 1U) != 0) {
    *(uint *)this = *(uint *)this | 1;
  }
  if ((param_1 & 2U) != 0) {
    *(uint *)(this + 4) = *(uint *)(this + 4) | 1;
  }
  if ((param_1 & 4U) != 0) {
    *(uint *)(this + 8) = *(uint *)(this + 8) | 1;
  }
  if ((param_1 & 8U) != 0) {
    *(uint *)(this + 0xc) = *(uint *)(this + 0xc) | 1;
  }
  if ((param_1 & 0x10U) != 0) {
    *(uint *)(this + 0x10) = *(uint *)(this + 0x10) | 1;
  }
  if ((param_1 & 0x20U) != 0) {
    *(uint *)(this + 0x14) = *(uint *)(this + 0x14) | 1;
  }
  if ((param_1 & 0x40U) != 0) {
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) | 1;
  }
  if ((char)param_1 < '\0') {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 1;
  }
  if ((param_1 & 0x100U) != 0) {
    *(uint *)(this + 0x20) = *(uint *)(this + 0x20) | 1;
  }
  if (*(int *)(this + 0x24) < param_1 >> 0xb) {
    *(int *)(this + 0x24) = param_1 >> 0xb;
  }
  return;
}

