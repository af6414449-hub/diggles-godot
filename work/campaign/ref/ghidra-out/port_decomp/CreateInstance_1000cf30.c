
/* public: static long __cdecl CPlayer::CreateInstance(struct HWND__ *,struct HWND__ *,class CPlayer
   * *) */

long __cdecl CPlayer::CreateInstance(HWND__ *param_1,HWND__ *param_2,CPlayer **param_3)

{
  CPlayer *pCVar1;
  long lVar2;
  
                    /* 0xcf30  110  ?CreateInstance@CPlayer@@SAJPAUHWND__@@0PAPAV1@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (param_3 == (CPlayer **)0x0) {
    return -0x7fffbffd;
  }
  pCVar1 = (CPlayer *)FUN_1003ff62(0x24);
  *(undefined4 *)pCVar1 = 0;
  *(undefined4 *)(pCVar1 + 4) = 0;
  *(undefined4 *)(pCVar1 + 8) = 0;
  *(undefined4 *)(pCVar1 + 0xc) = 0;
  *(undefined4 *)(pCVar1 + 0x10) = 0;
  *(undefined4 *)(pCVar1 + 0x14) = 0;
  *(undefined4 *)(pCVar1 + 0x18) = 0;
  *(undefined4 *)(pCVar1 + 0x1c) = 0;
  *(undefined4 *)(pCVar1 + 0x20) = 0;
  pCVar1 = (CPlayer *)CPlayer(pCVar1,param_1,param_2);
  if (pCVar1 == (CPlayer *)0x0) {
    return -0x7ff8fff2;
  }
  lVar2 = Initialize(pCVar1);
  if (-1 < lVar2) {
    *param_3 = pCVar1;
    return lVar2;
  }
  (**(code **)(*(int *)pCVar1 + 8))(pCVar1);
  return lVar2;
}

