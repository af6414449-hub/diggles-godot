
/* public: void __thiscall DisplayModeManager::SetNextMode(void) */

void __thiscall DisplayModeManager::SetNextMode(DisplayModeManager *this)

{
  int iVar1;
  int iVar2;
  undefined1 local_14 [16];
  
                    /* 0x8dd0  246  ?SetNextMode@DisplayModeManager@@QAEXXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *(int *)this;
  if (((iVar1 != 2) && (iVar1 != 1)) && (iVar1 != 4)) {
    FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
  }
  iVar2 = 1;
  if (iVar1 * 2 < 5) {
    iVar2 = iVar1 * 2;
  }
  *(int *)this = iVar2;
  return;
}

