
/* public: struct HWND__ * __thiscall CSdlWindowHandle::GetHWnd(void)const  */

HWND__ * __thiscall CSdlWindowHandle::GetHWnd(CSdlWindowHandle *this)

{
  int iVar1;
  HWND__ *extraout_EAX;
  undefined1 local_64 [12];
  undefined2 local_58;
  undefined1 local_56;
  uint local_c;
  
                    /* 0x13e40  142  ?GetHWnd@CSdlWindowHandle@@QBEPAUHWND__@@XZ */
  local_c = DAT_1005000c ^ (uint)local_64;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_58 = 2;
  local_56 = 0xc;
  if (*(int *)this == 0) {
    FUN_100052e0("SDL window is null");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_64,(ThrowInfo *)&DAT_1004a25c);
  }
  iVar1 = SDL_GetWindowWMInfo(*(int *)this,&local_58);
  if (iVar1 == 1) {
    __security_check_cookie(local_c ^ (uint)local_64);
    return extraout_EAX;
  }
  FUN_100052e0("SDL_GetWindowWMInfo failed");
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_64,(ThrowInfo *)&DAT_1004a25c);
}

