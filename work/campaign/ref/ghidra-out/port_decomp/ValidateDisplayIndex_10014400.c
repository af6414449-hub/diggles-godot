
/* public: static int __cdecl CSdlInformWindowHandle::ValidateDisplayIndex(int,struct tagRECT) */

int __cdecl
CSdlInformWindowHandle::ValidateDisplayIndex
          (undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int iVar2;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint local_c;
  
                    /* 0x14400  275  ?ValidateDisplayIndex@CSdlInformWindowHandle@@SAHHUtagRECT@@@Z
                        */
  local_c = DAT_1005000c ^ (uint)&iStack_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar2 = 0;
  iVar1 = SDL_GetNumVideoDisplays();
  if (0 < iVar1) {
    do {
      SDL_GetDisplayBounds(iVar2,&iStack_1c);
      if ((((iStack_1c == param_2) && (iStack_18 == param_3)) && (iStack_14 == param_4 - param_2))
         && (iStack_10 == param_5 - param_3)) {
        __security_check_cookie(local_c ^ (uint)&iStack_1c);
        return extraout_EAX_00;
      }
      iVar2 = iVar2 + 1;
      iVar1 = SDL_GetNumVideoDisplays();
    } while (iVar2 < iVar1);
  }
  __security_check_cookie(local_c ^ (uint)&iStack_1c);
  return extraout_EAX;
}

