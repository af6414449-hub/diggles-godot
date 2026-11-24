
/* public: void __thiscall ScreenResolutionManager::FillDisplayBounds(void) */

void __thiscall ScreenResolutionManager::FillDisplayBounds(ScreenResolutionManager *this)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_14;
  
                    /* 0x13010  122  ?FillDisplayBounds@ScreenResolutionManager@@QAEXXZ */
  local_14 = DAT_1005000c ^ (uint)auStack_38;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar3 = 0;
  iVar2 = SDL_GetNumVideoDisplays();
  if (0 < iVar2) {
    do {
      SDL_GetDisplayBounds(iVar3,&uStack_30);
      puVar1 = *(undefined4 **)(this + 0x24);
      if (puVar1 == *(undefined4 **)(this + 0x28)) {
        FUN_10013380(puVar1,&uStack_30);
      }
      else {
        *puVar1 = uStack_30;
        puVar1[1] = uStack_2c;
        puVar1[2] = uStack_28;
        puVar1[3] = uStack_24;
        *(int *)(this + 0x24) = *(int *)(this + 0x24) + 0x10;
      }
      iVar3 = iVar3 + 1;
      iVar2 = SDL_GetNumVideoDisplays();
    } while (iVar3 < iVar2);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_38);
  return;
}

