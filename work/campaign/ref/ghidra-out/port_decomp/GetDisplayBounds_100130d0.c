
/* public: void __thiscall ScreenResolutionManager::GetDisplayBounds(int,struct tagRECT *) */

void __thiscall
ScreenResolutionManager::GetDisplayBounds
          (ScreenResolutionManager *this,int param_1,tagRECT *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
                    /* 0x130d0  134  ?GetDisplayBounds@ScreenResolutionManager@@QAEXHPAUtagRECT@@@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar4 = SDL_GetNumVideoDisplays();
  if (param_1 < iVar4) {
    piVar5 = (int *)(param_1 * 0x10 + *(int *)(this + 0x20));
    iVar4 = *piVar5;
    iVar1 = piVar5[1];
    iVar2 = piVar5[2];
    iVar3 = piVar5[3];
    *(int *)(param_2 + 4) = iVar1;
    *(int *)param_2 = iVar4;
    *(int *)(param_2 + 8) = iVar2 + iVar4;
    *(int *)(param_2 + 0xc) = iVar1 + iVar3;
    return;
  }
  *(undefined4 *)param_2 = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 0x400;
  *(undefined4 *)(param_2 + 0xc) = 0x300;
  return;
}

