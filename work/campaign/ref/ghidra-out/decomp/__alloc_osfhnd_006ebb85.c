
/* Library Function - Single Match
    __alloc_osfhnd
   
   Library: Visual Studio 2019 Release */

int __cdecl __alloc_osfhnd(void)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  uint uVar3;
  int unaff_EBP;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar4;
  
  FUN_006cf3b0(&DAT_00763868,0x1c);
  ___acrt_lock(7);
  uVar3 = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0xffffffff;
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    *(int *)(unaff_EBP + -0x2c) = iVar4;
    if (0x7f < iVar4) {
LAB_006ebbf3:
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
      FUN_006ebc8f();
      ExceptionList = *(void **)(unaff_EBP + -0x10);
      return uVar3;
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_00769d80)[iVar4];
    *(LPCRITICAL_SECTION *)(unaff_EBP + -0x28) = lpCriticalSection;
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      iVar1 = ___acrt_lowio_create_handle_array();
      (&DAT_00769d80)[iVar4] = iVar1;
      if (iVar1 != 0) {
        DAT_00769f80 = DAT_00769f80 + 0x40;
        uVar3 = iVar4 << 6;
        ___acrt_lowio_lock_fh(uVar3);
        *(undefined1 *)((&DAT_00769d80)[(int)uVar3 >> 6] + 0x28) = 1;
LAB_006ebbf0:
        *(uint *)(unaff_EBP + -0x1c) = uVar3;
      }
      goto LAB_006ebbf3;
    }
    p_Var2 = (LPCRITICAL_SECTION)&lpCriticalSection[0x95].RecursionCount;
    *(LPCRITICAL_SECTION *)(unaff_EBP + -0x20) = p_Var2;
    for (; *(LPCRITICAL_SECTION *)(unaff_EBP + -0x24) = lpCriticalSection,
        lpCriticalSection != p_Var2;
        lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[2].RecursionCount) {
      if (((uint)lpCriticalSection[1].LockSemaphore & 1) == 0) {
        EnterCriticalSection(lpCriticalSection);
        if (((uint)lpCriticalSection[1].LockSemaphore & 1) == 0) {
          uVar3 = iVar4 * 0x40 + ((int)lpCriticalSection - *(int *)(unaff_EBP + -0x28)) / 0x38;
          iVar4 = (uVar3 & 0x3f) * 0x38;
          *(undefined1 *)((&DAT_00769d80)[(int)uVar3 >> 6] + 0x28 + iVar4) = 1;
          *(undefined4 *)((&DAT_00769d80)[(int)uVar3 >> 6] + 0x18 + iVar4) = 0xffffffff;
          goto LAB_006ebbf0;
        }
        LeaveCriticalSection(lpCriticalSection);
        p_Var2 = *(LPCRITICAL_SECTION *)(unaff_EBP + -0x20);
      }
    }
    iVar4 = iVar4 + 1;
  } while( true );
}

