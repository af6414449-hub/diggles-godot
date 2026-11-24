
/* public: void __thiscall PostProcessOptionManager::Revert(enum PEO::PostEffectOption) */

void __thiscall
PostProcessOptionManager::Revert(PostProcessOptionManager *this,PostEffectOption param_1)

{
                    /* 0x14580  233
                       ?Revert@PostProcessOptionManager@@QAEXW4PostEffectOption@PEO@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)(this + param_1 * 4) = *(undefined4 *)(this + param_1 * 4 + 8);
  return;
}

