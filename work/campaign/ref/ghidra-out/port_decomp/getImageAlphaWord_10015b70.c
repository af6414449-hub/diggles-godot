
/* private: void __thiscall Texture::ChunkedTexture::getImageAlphaWord(unsigned int,unsigned
   int,unsigned int,unsigned int) */

void __thiscall
Texture::ChunkedTexture::getImageAlphaWord
          (ChunkedTexture *this,uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
                    /* 0x15b70  305  ?getImageAlphaWord@ChunkedTexture@Texture@@AAEXIIII@Z */
  uVar1 = param_4;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (*(uint *)(this + 0x14) <= param_3 * param_4 && param_3 * param_4 - *(uint *)(this + 0x14) != 0
     ) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar2 = *(int *)(this + 0x2c);
  param_4 = 0;
  uVar1 = param_2 + uVar1;
  if (param_2 < uVar1) {
    uVar5 = param_2;
    do {
      param_2 = param_1;
      if (param_1 < param_1 + param_3) {
        do {
          iVar3 = *(int *)(this + 0xac);
          uVar4 = (uint)*(ushort *)(iVar2 + (*(int *)this * uVar5 + param_2) * 2);
          *(uint *)(*(int *)(this + 0xb0) + param_4 * 4) =
               (((((*(uint *)(iVar3 + 0x1c) & uVar4) >> ((byte)*(undefined4 *)(this + 0x28) & 0x1f))
                 * 0xff) / 0xf << 8 |
                (((*(uint *)(iVar3 + 0x18) & uVar4) >> ((byte)*(undefined4 *)(this + 0x24) & 0x1f))
                * 0xff) / 0xf) << 8 |
               (((*(uint *)(iVar3 + 0x14) & uVar4) >> ((byte)*(undefined4 *)(this + 0x20) & 0x1f)) *
               0xff) / 0xf) << 8 |
               (((*(uint *)(iVar3 + 0x10) & uVar4) >> ((byte)*(undefined4 *)(this + 0x1c) & 0x1f)) *
               0xff) / 0xf;
          param_4 = param_4 + 1;
          param_2 = param_2 + 1;
        } while (param_2 < param_1 + param_3);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  return;
}

