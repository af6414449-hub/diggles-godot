
/* public: virtual unsigned long __stdcall CPlayer::Release(void) */

ulong CPlayer::Release(void)

{
  int *piVar1;
  int iVar2;
  int *in_stack_00000004;
  
                    /* 0xd140  222  ?Release@CPlayer@@UAGKXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  LOCK();
  piVar1 = in_stack_00000004 + 1;
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((iVar2 - 1U == 0) && (in_stack_00000004 != (int *)0x0)) {
    (**(code **)(*in_stack_00000004 + 0x14))(1);
  }
  return iVar2 - 1U;
}

