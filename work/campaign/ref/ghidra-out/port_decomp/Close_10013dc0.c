
/* public: void __thiscall CSdlWindow::Close(void) */

void __thiscall CSdlWindow::Close(CSdlWindow *this)

{
                    /* 0x13dc0  105  ?Close@CSdlWindow@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (**(int **)(this + 4) != 0) {
    SDL_DestroyWindow(**(int **)(this + 4));
  }
  return;
}

