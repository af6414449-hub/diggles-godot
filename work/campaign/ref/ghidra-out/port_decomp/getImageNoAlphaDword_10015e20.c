
/* private: void __thiscall Texture::ChunkedTexture::getImageNoAlphaDword(unsigned int,unsigned
   int,unsigned int,unsigned int) */

void __thiscall
Texture::ChunkedTexture::getImageNoAlphaDword
          (ChunkedTexture *this,uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
                    /* 0x15e20  306  ?getImageNoAlphaDword@ChunkedTexture@Texture@@AAEXIIII@Z */
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
    do {
      local_8 = param_1;
      if (param_1 < param_3 + param_1) {
        do {
          iVar3 = *(int *)(this + 0xac);
          uVar4 = *(uint *)(iVar2 + (*(int *)this * param_2 + local_8) * 4);
          local_8 = local_8 + 1;
          *(uint *)(*(int *)(this + 0xb0) + param_4 * 4) =
               (((*(uint *)(iVar3 + 0x18) & uVar4) >> ((byte)*(undefined4 *)(this + 0x24) & 0x1f) |
                0xffffff00) << 8 |
               (*(uint *)(iVar3 + 0x14) & uVar4) >> ((byte)*(undefined4 *)(this + 0x20) & 0x1f)) <<
               8 | (*(uint *)(iVar3 + 0x10) & uVar4) >> ((byte)*(undefined4 *)(this + 0x1c) & 0x1f);
          param_4 = param_4 + 1;
        } while (local_8 < param_3 + param_1);
      }
      param_2 = param_2 + 1;
    } while (param_2 < uVar1);
  }
  return;
}

