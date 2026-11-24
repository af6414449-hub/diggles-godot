
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: int __thiscall AchievementManager::GetIncrement(enum Achievements::AchID) */

int __thiscall AchievementManager::GetIncrement(AchievementManager *this,AchID param_1)

{
  double in_XMM0_Qa;
  undefined8 uVar1;
  
                    /* 0x31e0  145  ?GetIncrement@AchievementManager@@QAEHW4AchID@Achievements@@@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (param_1 == 9) {
    if (*(int *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) < DAT_1416eb68) {
      FUN_1003fe8c(&DAT_1416eb68);
      if (DAT_1416eb68 == -1) {
        _DAT_1416ebf0 = _Xtime_get_ticks();
        FUN_1003fe42(&DAT_1416eb68);
      }
    }
    uVar1 = _Xtime_get_ticks();
    _DAT_1416ebf0 = uVar1;
    FUN_100415c0();
    return (int)(in_XMM0_Qa / 10000000.0);
  }
  return 1;
}

