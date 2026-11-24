
/* public: bool __thiscall PostProcessOptionManager::Differ(enum PEO::PostEffectOption) */

bool __thiscall
PostProcessOptionManager::Differ(PostProcessOptionManager *this,PostEffectOption param_1)

{
                    /* 0x145c0  116
                       ?Differ@PostProcessOptionManager@@QAE_NW4PostEffectOption@PEO@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  return *(int *)(this + param_1 * 4) != *(int *)(this + param_1 * 4 + 8);
}

