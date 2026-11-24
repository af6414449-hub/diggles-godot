
/* public: class ScreenResolutionManager & __thiscall ScreenResolutionManager::operator=(class
   ScreenResolutionManager const &) */

ScreenResolutionManager * __thiscall
ScreenResolutionManager::operator=(ScreenResolutionManager *this,ScreenResolutionManager *param_1)

{
  void *_Src;
  void *_Dst;
  code *pcVar1;
  size_t _Size;
  int iVar2;
  ScreenResolutionManager *pSVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_c;
  
                    /* 0x5620  83  ??4ScreenResolutionManager@@QAEAAV0@ABV0@@Z */
  if (this != param_1) {
    iVar2 = *(int *)this;
    FUN_100080a0(this,*(undefined4 *)(iVar2 + 4));
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    *(int *)(iVar2 + 8) = iVar2;
    *(undefined4 *)(this + 4) = 0;
    FUN_10008010(param_1,local_c);
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  this[0x1c] = param_1[0x1c];
  pSVar3 = this + 0x20;
  this[0x1d] = param_1[0x1d];
  if (pSVar3 != param_1 + 0x20) {
    _Src = *(void **)(param_1 + 0x20);
    _Size = *(int *)(param_1 + 0x24) - (int)_Src;
    uVar5 = (int)_Size >> 4;
    uVar4 = *(int *)(this + 0x28) - *(int *)pSVar3 >> 4;
    if (uVar4 < uVar5) {
      if (0xfffffff < uVar5) {
        FUN_10008180();
        pcVar1 = (code *)swi(3);
        pSVar3 = (ScreenResolutionManager *)(*pcVar1)();
        return pSVar3;
      }
      if (0xfffffff - (uVar4 >> 1) < uVar4) {
        uVar6 = 0xfffffff;
      }
      else {
        uVar6 = (uVar4 >> 1) + uVar4;
        if (uVar6 < uVar5) {
          uVar6 = uVar5;
        }
      }
      if (*(int *)pSVar3 != 0) {
        FUN_10007c90(*(int *)pSVar3,uVar4);
        *(int *)pSVar3 = 0;
        *(undefined4 *)(this + 0x24) = 0;
        *(undefined4 *)(this + 0x28) = 0;
      }
      iVar2 = FUN_10007c20(uVar6);
      *(int *)pSVar3 = iVar2;
      *(int *)(this + 0x24) = iVar2;
      *(uint *)(this + 0x28) = uVar6 * 0x10 + iVar2;
    }
    _Dst = *(void **)pSVar3;
    memmove(_Dst,_Src,_Size);
    *(size_t *)(this + 0x24) = _Size + (int)_Dst;
  }
  return this;
}

