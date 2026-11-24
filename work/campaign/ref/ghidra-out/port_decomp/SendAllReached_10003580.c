
/* public: void __thiscall AchievementManager::SendAllReached(void) */

void __thiscall AchievementManager::SendAllReached(AchievementManager *this)

{
  AchID AVar1;
  
                    /* 0x3580  236  ?SendAllReached@AchievementManager@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  AVar1 = 0;
  do {
    if ((((AVar1 != 1) && (*(int *)(this + AVar1 * 4) == *(int *)(this + AVar1 * 4 + 0x2c))) &&
        (this[AVar1 + 0x58] == (AchievementManager)0x0)) &&
       ((AVar1 != 2 ||
        ((*(int *)this == *(int *)(this + 0x2c) && (*(int *)(this + 4) == *(int *)(this + 0x30))))))
       ) {
      Achieved(this,AVar1);
    }
    AVar1 = AVar1 + 1;
  } while ((int)AVar1 < 10);
  if ((((*(int *)(this + 0x28) == *(int *)(this + 0x54)) &&
       (*(int *)(this + 8) == *(int *)(this + 0x34))) &&
      ((*(int *)(this + 0xc) == *(int *)(this + 0x38) &&
       (((*(int *)(this + 0x10) == *(int *)(this + 0x3c) &&
         (*(int *)(this + 0x14) == *(int *)(this + 0x40))) &&
        (*(int *)(this + 0x18) == *(int *)(this + 0x44))))))) &&
     (*(int *)(this + 0x1c) == *(int *)(this + 0x48))) {
    Achieved(this,10);
  }
  return;
}

