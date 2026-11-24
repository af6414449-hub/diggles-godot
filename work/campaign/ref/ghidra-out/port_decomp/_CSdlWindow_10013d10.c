
/* public: __thiscall CSdlWindow::~CSdlWindow(void) */

void __thiscall CSdlWindow::~CSdlWindow(CSdlWindow *this)

{
  int *piVar1;
  
                    /* 0x13d10  43  ??1CSdlWindow@@QAE@XZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = *(int **)(this + 4);
  if (*piVar1 != 0) {
    SDL_DestroyWindow(*piVar1);
    piVar1 = *(int **)(this + 4);
  }
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      SDL_DestroyWindow(*piVar1);
    }
    FUN_100402ac(piVar1,4);
  }
  return;
}

