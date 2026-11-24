
/* public: long __thiscall CPlayer::Pause(void) */

long __thiscall CPlayer::Pause(CPlayer *this)

{
  int *piVar1;
  long lVar2;
  
                    /* 0xd2a0  214  ?Pause@CPlayer@@QAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(int *)(this + 0x1c) != 3) {
    return -0x3ff2c94e;
  }
  piVar1 = *(int **)(this + 8);
  if ((piVar1 == (int *)0x0) || (*(int *)(this + 0xc) == 0)) {
    lVar2 = -0x7fff0001;
  }
  else {
    lVar2 = (**(code **)(*piVar1 + 0x28))(piVar1);
    if (-1 < lVar2) {
      *(undefined4 *)(this + 0x1c) = 4;
      return lVar2;
    }
  }
  return lVar2;
}

