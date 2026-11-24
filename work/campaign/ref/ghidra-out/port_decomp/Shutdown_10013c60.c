
/* private: void __thiscall CSdlManager::Shutdown(void) */

void __thiscall CSdlManager::Shutdown(CSdlManager *this)

{
                    /* 0x13c60  260  ?Shutdown@CSdlManager@@AAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
                    /* WARNING: Could not recover jumptable at 0x10013c6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  SDL_Quit();
  return;
}

