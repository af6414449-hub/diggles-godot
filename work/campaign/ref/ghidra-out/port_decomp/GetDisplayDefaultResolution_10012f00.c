
/* public: void __thiscall ScreenResolutionManager::GetDisplayDefaultResolution(int,unsigned int
   &,unsigned int &) */

void __thiscall
ScreenResolutionManager::GetDisplayDefaultResolution
          (ScreenResolutionManager *this,int param_1,uint *param_2,uint *param_3)

{
  undefined1 local_1c [4];
  uint local_18;
  uint local_14;
  uint local_8;
  
                    /* 0x12f00  135
                       ?GetDisplayDefaultResolution@ScreenResolutionManager@@QAEXHAAI0@Z */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  SDL_GetCurrentDisplayMode(param_1,local_1c);
  *param_2 = local_18;
  *param_3 = local_14;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

