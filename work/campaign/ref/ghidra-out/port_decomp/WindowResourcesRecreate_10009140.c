
/* void __cdecl WindowResourcesRecreate(class CSdlWindowHandle *) */

void __cdecl WindowResourcesRecreate(CSdlWindowHandle *param_1)

{
  ScreenResolutionManager *this;
  void *_Dst;
  undefined4 in_EDX;
  ScreenResolutionManager *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x9140  276  ?WindowResourcesRecreate@@YAXPAVCSdlWindowHandle@@@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041a66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  if (ScreenResolutionManager::s_instance == (ScreenResolutionManager *)0x0) {
    this = (ScreenResolutionManager *)FUN_1003ff62(0x2c);
    local_8 = 0;
    local_18 = this;
    memset(this,0,0x2c);
    ScreenResolutionManager::s_instance =
         (ScreenResolutionManager *)ScreenResolutionManager::ScreenResolutionManager(this);
    local_8 = 0xffffffff;
  }
  ScreenResolutionManager::GetIndexedResolution
            (ScreenResolutionManager::s_instance,*(int *)(ScreenResolutionManager::s_instance + 0xc)
             ,(uint *)&local_18,&local_14);
  CSdlWindowHandle::ResizeWindow(param_1,(int)local_18,local_14);
  if (DAT_10050c64 == 0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 1;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  FUN_10010060(local_18,local_14);
  ExceptionList = local_10;
  return;
}

