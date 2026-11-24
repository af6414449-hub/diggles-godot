
/* public: __thiscall ScreenResolutionManager::ScreenResolutionManager(class ScreenResolutionManager
   const &) */

ScreenResolutionManager * __thiscall
ScreenResolutionManager::ScreenResolutionManager
          (ScreenResolutionManager *this,ScreenResolutionManager *param_1)

{
  void *_Src;
  void *_Dst;
  uint uVar1;
  int iVar2;
  size_t _Size;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x5500  36  ??0ScreenResolutionManager@@QAE@ABV0@@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_100417f5;
  local_10 = ExceptionList;
  uVar1 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  iVar2 = FUN_1003ff62(0x2c,uVar1);
  *(int *)iVar2 = iVar2;
  *(int *)(iVar2 + 4) = iVar2;
  *(int *)(iVar2 + 8) = iVar2;
  *(undefined2 *)(iVar2 + 0xc) = 0x101;
  *(int *)this = iVar2;
  local_8 = 0;
  FUN_10008010(param_1,this);
  local_8 = 1;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  this[0x1c] = param_1[0x1c];
  this[0x1d] = param_1[0x1d];
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  _Src = *(void **)(param_1 + 0x20);
  if (_Src != *(void **)(param_1 + 0x24)) {
    _Size = (int)*(void **)(param_1 + 0x24) - (int)_Src;
    iVar3 = (int)_Size >> 4;
    iVar2 = FUN_10007c20(iVar3);
    *(int *)(this + 0x20) = iVar2;
    *(int *)(this + 0x24) = iVar2;
    *(int *)(this + 0x28) = iVar2 + iVar3 * 0x10;
    _Dst = *(void **)(this + 0x20);
    memmove(_Dst,_Src,_Size);
    *(void **)(this + 0x24) = (void *)((int)_Dst + iVar3 * 0x10);
  }
  ExceptionList = local_10;
  return this;
}

