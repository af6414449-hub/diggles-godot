
/* public: long __thiscall CPlayer::Stop(void) */

long __thiscall CPlayer::Stop(CPlayer *this)

{
  int *piVar1;
  long lVar2;
  
                    /* 0xd2f0  262  ?Stop@CPlayer@@QAEJXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if ((*(int *)(this + 0x1c) != 3) && (*(int *)(this + 0x1c) != 4)) {
    return -0x3ff2c94e;
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 == (int *)0x0) {
    return -0x7fff0001;
  }
  lVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1);
  if (-1 < lVar2) {
    *(undefined4 *)(this + 0x1c) = 5;
  }
  return lVar2;
}

