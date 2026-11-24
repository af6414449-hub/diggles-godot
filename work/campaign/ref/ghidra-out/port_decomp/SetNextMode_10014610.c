
/* public: void __thiscall PostProcessOptionManager::SetNextMode(enum PEO::PostEffectOption) */

void __thiscall
PostProcessOptionManager::SetNextMode(PostProcessOptionManager *this,PostEffectOption param_1)

{
                    /* 0x14610  247
                       ?SetNextMode@PostProcessOptionManager@@QAEXW4PostEffectOption@PEO@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(uint *)(this + param_1 * 4) = (uint)(*(uint *)(this + param_1 * 4) == 0);
  return;
}

