
/* public: virtual unsigned long __stdcall CPlayer::AddRef(void) */

ulong CPlayer::AddRef(void)

{
  int *piVar1;
  int iVar2;
  int in_stack_00000004;
  
                    /* 0xd120  98  ?AddRef@CPlayer@@UAGKXZ */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  LOCK();
  piVar1 = (int *)(in_stack_00000004 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}

