
/* public: struct SDL_Rect __thiscall ScreenResolutionManager::GetDisplayBounds(int) */

void __thiscall ScreenResolutionManager::GetDisplayBounds(ScreenResolutionManager *this,int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_stack_00000008;
  
                    /* 0x13090  133  ?GetDisplayBounds@ScreenResolutionManager@@QAE?AUSDL_Rect@@H@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar4 = SDL_GetNumVideoDisplays();
  if (in_stack_00000008 < iVar4) {
    puVar5 = (undefined4 *)(in_stack_00000008 * 0x10 + *(int *)(this + 0x20));
    uVar1 = puVar5[1];
    uVar2 = puVar5[2];
    uVar3 = puVar5[3];
    *(undefined4 *)param_1 = *puVar5;
    *(undefined4 *)(param_1 + 4) = uVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
    return;
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

