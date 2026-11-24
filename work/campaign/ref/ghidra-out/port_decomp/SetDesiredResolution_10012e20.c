
/* public: void __thiscall ScreenResolutionManager::SetDesiredResolution(unsigned int,unsigned int)
    */

void __thiscall
ScreenResolutionManager::SetDesiredResolution
          (ScreenResolutionManager *this,uint param_1,uint param_2)

{
                    /* 0x12e20  239  ?SetDesiredResolution@ScreenResolutionManager@@QAEXII@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(uint *)(this + 0x14) = param_1;
  *(uint *)(this + 0x18) = param_2;
  return;
}

