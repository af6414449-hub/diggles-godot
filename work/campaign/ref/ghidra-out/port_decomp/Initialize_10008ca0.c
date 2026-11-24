
/* public: void __thiscall DisplayIndexManager::Initialize(void) */

void __thiscall DisplayIndexManager::Initialize(DisplayIndexManager *this)

{
  undefined4 uVar1;
  
                    /* 0x8ca0  186  ?Initialize@DisplayIndexManager@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar1 = SDL_GetNumVideoDisplays();
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

