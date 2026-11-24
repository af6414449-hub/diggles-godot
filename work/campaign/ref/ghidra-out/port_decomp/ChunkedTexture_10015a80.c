
/* public: __thiscall Texture::ChunkedTexture::ChunkedTexture(void *,struct _DDSURFACEDESC2) */

ChunkedTexture * __thiscall
Texture::ChunkedTexture::ChunkedTexture(ChunkedTexture *this,undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  ChunkedTexture *pCVar4;
  
                    /* 0x15a80  9  ??0ChunkedTexture@Texture@@QAE@PAXU_DDSURFACEDESC2@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)(this + 0x2c) = param_1;
  *(undefined4 *)(this + 0xc) = 0x200;
  puVar3 = (undefined4 *)&stack0x00000008;
  pCVar4 = this + 0x30;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    pCVar4 = pCVar4 + 4;
  }
  *(undefined4 *)this = *(undefined4 *)(this + 0x3c);
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0x38);
  *(undefined4 *)(this + 0x10) = 0x200;
  *(undefined4 *)(this + 0x14) = 0x40000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined **)(this + 0xb0) = &DAT_1006dec0;
  *(ChunkedTexture **)(this + 0xac) = this + 0x78;
  *(uint *)(this + 8) = *(uint *)(this + 0x84) >> 3;
  uVar2 = *(uint *)(this + 0x88);
  for (iVar1 = 0; ((uVar2 & 1) == 0 && (iVar1 < 0x20)); iVar1 = iVar1 + 1) {
    uVar2 = uVar2 >> 1;
  }
  *(int *)(this + 0x1c) = iVar1;
  uVar2 = *(uint *)(this + 0x8c);
  for (iVar1 = 0; ((uVar2 & 1) == 0 && (iVar1 < 0x20)); iVar1 = iVar1 + 1) {
    uVar2 = uVar2 >> 1;
  }
  *(int *)(this + 0x20) = iVar1;
  uVar2 = *(uint *)(this + 0x90);
  for (iVar1 = 0; ((uVar2 & 1) == 0 && (iVar1 < 0x20)); iVar1 = iVar1 + 1) {
    uVar2 = uVar2 >> 1;
  }
  *(int *)(this + 0x24) = iVar1;
  uVar2 = *(uint *)(this + 0x94);
  for (iVar1 = 0; ((uVar2 & 1) == 0 && (iVar1 < 0x20)); iVar1 = iVar1 + 1) {
    uVar2 = uVar2 >> 1;
  }
  *(int *)(this + 0x28) = iVar1;
  return this;
}

