
/* public: void __thiscall Texture::ChunkedTexture::updateRealTexture(struct ID3D11Texture2D
   *,int,int,int,int) */

void __thiscall
Texture::ChunkedTexture::updateRealTexture
          (ChunkedTexture *this,ID3D11Texture2D *param_1,int param_2,int param_3,int param_4,
          int param_5)

{
  int *piVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 in_EDX;
  uint uVar5;
  uint local_3c;
  uint local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  int local_20;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x16010  318
                       ?updateRealTexture@ChunkedTexture@Texture@@QAEXPAUID3D11Texture2D@@HHHH@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042837;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar1 = *(int **)(*DAT_10050c64 + 8);
  local_20 = *(int *)this + param_2;
  local_1c = 0;
  uVar2 = *(uint *)(this + 0x14) / (uint)param_4;
  local_24 = 0;
  local_18 = 1;
  local_2c = param_2;
  if (uVar2 == 0) {
    RaiseException(0xc0000094,1,0,(ULONG_PTR *)0x0);
  }
  local_30 = (uint)param_5 / uVar2;
  *(uint *)(this + 0x18) = local_30;
  if ((uint)param_5 % uVar2 != 0) {
    local_30 = local_30 + 1;
    *(uint *)(this + 0x18) = local_30;
  }
  uVar3 = param_5 + param_3;
  local_3c = 0;
  if (local_30 != 0) {
    do {
      uVar5 = uVar2 + param_3;
      local_1c = uVar5;
      if (uVar3 < uVar5) {
        local_1c = uVar3;
      }
      uVar4 = local_1c - param_3;
      local_28 = param_3;
      if (*(int *)(this + 8) == 2) {
        if (*(int *)(*(int *)(this + 0xac) + 0x1c) == 0) {
          getImageNoAlphaWord(this,param_2,param_3,param_4,uVar4);
        }
        else {
          getImageAlphaWord(this,param_2,param_3,param_4,uVar4);
        }
      }
      else if (*(int *)(*(int *)(this + 0xac) + 0x1c) == 0) {
        getImageNoAlphaDword(this,param_2,param_3,param_4,uVar4);
      }
      else {
        getImageAlphaDword(this,param_2,param_3,param_4,uVar4);
      }
      (**(code **)(*piVar1 + 0xc0))
                (piVar1,param_1,0,&local_2c,*(undefined4 *)(this + 0xb0),param_4 * 4,0);
      local_3c = local_3c + 1;
      param_3 = uVar5;
    } while (local_3c < *(uint *)(this + 0x18));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

