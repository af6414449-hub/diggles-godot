
/* public: int __thiscall PostProcessOptionManager::GetMode(enum PEO::PostEffectOption) */

int __thiscall
PostProcessOptionManager::GetMode(PostProcessOptionManager *this,PostEffectOption param_1)

{
                    /* 0x2d70  156
                       ?GetMode@PostProcessOptionManager@@QAEHW4PostEffectOption@PEO@@@Z
                       0x2d70  174  ?GetStatus@AchievementManager@@QAEHW4AchID@Achievements@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return *(int *)(this + param_1 * 4);
}

