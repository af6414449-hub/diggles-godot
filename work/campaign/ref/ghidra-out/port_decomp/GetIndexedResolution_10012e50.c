
/* public: void __thiscall ScreenResolutionManager::GetIndexedResolution(int,unsigned int &,unsigned
   int &) */

void __thiscall
ScreenResolutionManager::GetIndexedResolution
          (ScreenResolutionManager *this,int param_1,uint *param_2,uint *param_3)

{
  undefined4 in_EDX;
  uint local_30;
  uint local_2c;
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x12e50  146  ?GetIndexedResolution@ScreenResolutionManager@@QAEXHAAI0@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042687;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (DAT_10050c64 == 0) {
    local_14 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_14,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  FUN_10010120(&local_30,param_1);
  *param_2 = local_30;
  *param_3 = local_2c;
  ExceptionList = local_10;
  return;
}

