
/* public: static struct tagPOINT __cdecl CSdlInformWindowHandle::GetCurrentDisplayCenter(int) */

void __cdecl CSdlInformWindowHandle::GetCurrentDisplayCenter(int param_1)

{
  int iVar1;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [12];
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_14;
  
                    /* 0x142f0  128
                       ?GetCurrentDisplayCenter@CSdlInformWindowHandle@@SA?AUtagPOINT@@H@Z */
  local_14 = DAT_1005000c ^ (uint)auStack_40;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iVar1 = SDL_GetDisplayBounds(param_1,&local_30);
  if (iVar1 == 0) {
    __security_check_cookie(local_14 ^ (uint)auStack_40);
    return;
  }
  FUN_100052e0("SDL_GetDisplayBounds failed");
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(auStack_3c,(ThrowInfo *)&DAT_1004a25c);
}

