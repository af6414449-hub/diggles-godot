
/* public: void __thiscall PostProcessOptionManager::SetModeValue(enum PEO::PostEffectOption,int) */

void __thiscall
PostProcessOptionManager::SetModeValue
          (PostProcessOptionManager *this,PostEffectOption param_1,int param_2)

{
                    /* 0x2d90  245
                       ?SetModeValue@PostProcessOptionManager@@QAEXW4PostEffectOption@PEO@@H@Z
                       0x2d90  250  ?SetStatus@AchievementManager@@QAEXW4AchID@Achievements@@H@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(int *)(this + param_1 * 4) = param_2;
  return;
}

