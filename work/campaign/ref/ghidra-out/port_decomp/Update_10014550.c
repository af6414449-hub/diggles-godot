
/* public: void __thiscall PostProcessOptionManager::Update(enum PEO::PostEffectOption) */

void __thiscall
PostProcessOptionManager::Update(PostProcessOptionManager *this,PostEffectOption param_1)

{
                    /* 0x14550  272
                       ?Update@PostProcessOptionManager@@QAEXW4PostEffectOption@PEO@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + param_1 * 4 + 8) != *(int *)(this + param_1 * 4)) {
    *(int *)(this + param_1 * 4 + 8) = *(int *)(this + param_1 * 4);
    this[param_1 + 0x10] = (PostProcessOptionManager)0x1;
  }
  return;
}

