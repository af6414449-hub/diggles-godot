
/* public: static void __cdecl CSdlManager::Init(void) */

void __cdecl CSdlManager::Init(void)

{
                    /* 0x13b10  182  ?Init@CSdlManager@@SAXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (DAT_10050c7c == (CSdlManager *)0x0) {
    DAT_10050c7c = (CSdlManager *)FUN_1003ff62(1);
    Initialize(DAT_10050c7c);
    return;
  }
  return;
}

