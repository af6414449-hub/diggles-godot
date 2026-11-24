
/* public: static class DisplayIndexManager * __cdecl DisplayIndexManager::GetInstance(void) */

DisplayIndexManager * __cdecl DisplayIndexManager::GetInstance(void)

{
  DisplayIndexManager *pDVar1;
  undefined4 uVar2;
  
                    /* 0x8cc0  148  ?GetInstance@DisplayIndexManager@@SAPAV1@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (s_instance == (DisplayIndexManager *)0x0) {
    pDVar1 = (DisplayIndexManager *)FUN_1003ff62(0x18);
    *(undefined4 *)pDVar1 = 0xffffffff;
    *(undefined4 *)(pDVar1 + 4) = 0;
    *(undefined4 *)(pDVar1 + 8) = 0;
    *(undefined4 *)(pDVar1 + 0xc) = 0x32;
    *(undefined4 *)(pDVar1 + 0x10) = 0x32;
    pDVar1[0x14] = (DisplayIndexManager)0x0;
    s_instance = pDVar1;
    uVar2 = SDL_GetNumVideoDisplays();
    *(undefined4 *)(pDVar1 + 8) = uVar2;
  }
  return s_instance;
}

