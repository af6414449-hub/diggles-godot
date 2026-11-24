
/* public: void __thiscall ScreenResolutionManager::GetDesiredResolution(unsigned int &,unsigned int
   &) */

void __thiscall
ScreenResolutionManager::GetDesiredResolution
          (ScreenResolutionManager *this,uint *param_1,uint *param_2)

{
                    /* 0x12df0  132  ?GetDesiredResolution@ScreenResolutionManager@@QAEXAAI0@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *param_1 = *(uint *)(this + 0x14);
  *param_2 = *(uint *)(this + 0x18);
  return;
}

