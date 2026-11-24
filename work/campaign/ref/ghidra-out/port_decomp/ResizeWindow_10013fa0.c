
/* public: void __thiscall CSdlWindowHandle::ResizeWindow(int,int)const  */

void __thiscall CSdlWindowHandle::ResizeWindow(CSdlWindowHandle *this,int param_1,int param_2)

{
  uint uVar1;
  DisplayIndexManager *pDVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  int iStack_3c;
  int iStack_38;
  int local_34;
  int local_30;
  int iStack_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  uint local_c;
  
                    /* 0x13fa0  226  ?ResizeWindow@CSdlWindowHandle@@QBEXHH@Z */
  local_c = DAT_1005000c ^ (uint)&iStack_3c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  FUN_100028b0(&DAT_1416eee0,0x40,"Calling ResizeWindow!\n");
  OutputDebugStringA(&DAT_1416eee0);
  local_34 = 0;
  local_30 = 0;
  if (DisplayModeManager::s_instance == (DisplayModeManager *)0x0) {
    DisplayModeManager::s_instance = (DisplayModeManager *)FUN_1003ff62(0xc);
    *(undefined8 *)DisplayModeManager::s_instance = 0;
    *(undefined4 *)(DisplayModeManager::s_instance + 8) = 0;
  }
  local_28 = *(int *)(DisplayModeManager::s_instance + 4);
  if (local_28 == 1) {
    FUN_100028b0(&DAT_1416eee0,0x40,"Want to set fullscreen!\n");
    OutputDebugStringA(&DAT_1416eee0);
    uVar1 = SDL_GetWindowFlags(*(undefined4 *)this);
    pcVar6 = SDL_SetWindowFullscreen_exref;
    if ((uVar1 & 1) != 0) {
      FUN_100028b0(&DAT_1416eee0,0x40,"Already fullscreen! Calculated window shift : (%d, %d) \n",0,
                   0);
      OutputDebugStringA(&DAT_1416eee0);
      pcVar6 = SDL_SetWindowFullscreen_exref;
      SDL_SetWindowFullscreen(*(undefined4 *)this,0);
      SDL_SetWindowSize(*(undefined4 *)this,param_1,param_2);
    }
    pDVar2 = DisplayIndexManager::GetInstance();
    iStack_3c = 0;
    iStack_38 = *(int *)pDVar2;
    iVar3 = SDL_GetNumVideoDisplays();
    if (iStack_38 < iVar3) {
      SDL_GetDisplayBounds(iStack_38,&iStack_24);
      iStack_3c = iStack_24;
    }
    else {
      iStack_20 = 0;
    }
    SDL_SetWindowPosition(*(undefined4 *)this,iStack_3c + 0x32,iStack_20 + 0x32);
    (*pcVar6)(*(undefined4 *)this,1);
  }
  else {
    FUN_100028b0(&DAT_1416eee0,0x40,"Calling SDL_SetWindowPosition. Window size - (%d x %d), %d \n",
                 param_1,param_2,local_28);
    OutputDebugStringA(&DAT_1416eee0);
    SDL_SetWindowFullscreen(*(undefined4 *)this,0);
    pDVar2 = DisplayIndexManager::GetInstance();
    iVar3 = 0;
    iStack_38 = 0;
    iStack_3c = 0;
    iStack_2c = *(int *)pDVar2;
    iVar4 = SDL_GetNumVideoDisplays();
    if (iStack_2c < iVar4) {
      SDL_GetDisplayBounds(iStack_2c,&iStack_24);
      local_34 = iStack_1c;
      iStack_38 = iStack_24;
      iStack_3c = iStack_20;
      local_30 = iStack_18;
      iVar3 = iStack_24;
    }
    else {
      iStack_20 = 0;
    }
    if (local_28 == 4) {
      SDL_SetWindowPosition(*(undefined4 *)this,iVar3,iStack_20);
      uVar7 = 0;
    }
    else {
      SDL_GetWindowBordersSize(*(undefined4 *)this,&iStack_2c,&local_28,auStack_10,auStack_14);
      iVar3 = iVar3 + (local_34 / 2 - param_1 / 2);
      iVar5 = (local_30 / 2 - param_2 / 2) + iStack_3c;
      iVar4 = iStack_2c + iStack_3c;
      if (iStack_2c + iStack_3c <= iVar5) {
        iVar4 = iVar5;
      }
      iVar5 = iStack_38 + local_28;
      if (iStack_38 + local_28 <= iVar3) {
        iVar5 = iVar3;
      }
      SDL_SetWindowPosition(*(undefined4 *)this,iVar5,iVar4);
      uVar7 = 1;
    }
    SDL_SetWindowBordered(*(undefined4 *)this,uVar7);
  }
  SDL_SetWindowSize(*(undefined4 *)this,param_1,param_2);
  __security_check_cookie(local_c ^ (uint)&iStack_3c);
  return;
}

