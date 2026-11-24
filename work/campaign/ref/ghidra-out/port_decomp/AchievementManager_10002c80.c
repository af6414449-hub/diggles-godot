
/* public: __thiscall AchievementManager::AchievementManager(void) */

AchievementManager * __thiscall AchievementManager::AchievementManager(AchievementManager *this)

{
  int iVar1;
  
                    /* 0x2c80  1  ??0AchievementManager@@QAE@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)(this + 0x2c) = 1;
  iVar1 = 0;
  *(undefined4 *)(this + 0x30) = 1;
  *(undefined4 *)(this + 0x34) = 1;
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined4 *)(this + 0x3c) = 1;
  *(undefined4 *)(this + 0x40) = 1;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined4 *)(this + 0x48) = 1;
  *(undefined4 *)(this + 0x4c) = 1;
  *(undefined4 *)(this + 0x50) = 360000;
  *(undefined4 *)(this + 0x54) = 0x1fffffff;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  do {
    this[iVar1 + 0x58] =
         (AchievementManager)(*(int *)(this + iVar1 * 4) == *(int *)(this + iVar1 * 4 + 0x2c));
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  return this;
}

