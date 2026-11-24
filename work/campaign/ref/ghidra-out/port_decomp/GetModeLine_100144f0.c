
/* public: char * __thiscall PostProcessOptionManager::GetModeLine(enum PEO::PostEffectOption) */

char * __thiscall
PostProcessOptionManager::GetModeLine(PostProcessOptionManager *this,PostEffectOption param_1)

{
  char *pcVar1;
  char *pcVar2;
  
                    /* 0x144f0  157
                       ?GetModeLine@PostProcessOptionManager@@QAEPADW4PostEffectOption@PEO@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  pcVar1 = "enabled";
  if (*(int *)(this + param_1 * 4) != 1) {
    pcVar1 = "disabled";
  }
  pcVar2 = "Anti-Aliasing";
  if (param_1 != 0) {
    pcVar2 = "Post Effect";
  }
  FUN_100028b0(&DAT_1416ef20,0x40,"%s : %s",pcVar2,pcVar1);
  return &DAT_1416ef20;
}

