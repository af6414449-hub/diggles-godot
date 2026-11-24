
/* private: __thiscall CSdlManager::~CSdlManager(void) */

void __thiscall CSdlManager::~CSdlManager(CSdlManager *this)

{
  CSdlManager *pCVar1;
  
                    /* 0x13ae0  42  ??1CSdlManager@@AAE@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  SDL_Quit();
  pCVar1 = DAT_10050c7c;
  if (DAT_10050c7c != (CSdlManager *)0x0) {
    ~CSdlManager(DAT_10050c7c);
    FUN_100402ac(pCVar1,1);
  }
  return;
}

