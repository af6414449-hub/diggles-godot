
/* public: long __thiscall CPlayer::Repaint(void) */

long __thiscall CPlayer::Repaint(CPlayer *this)

{
  int *piVar1;
  long lVar2;
  
                    /* 0xd340  223  ?Repaint@CPlayer@@QAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = *(int **)(this + 0x10);
  if (piVar1 != (int *)0x0) {
    lVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1);
    return lVar2;
  }
  return 0;
}

