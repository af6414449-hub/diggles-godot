
/* public: int __thiscall PostProcessOptionManager::GetModeSet(enum PEO::PostEffectOption) */

int __thiscall
PostProcessOptionManager::GetModeSet(PostProcessOptionManager *this,PostEffectOption param_1)

{
                    /* 0x144d0  158
                       ?GetModeSet@PostProcessOptionManager@@QAEHW4PostEffectOption@PEO@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return *(int *)(this + param_1 * 4 + 8);
}

