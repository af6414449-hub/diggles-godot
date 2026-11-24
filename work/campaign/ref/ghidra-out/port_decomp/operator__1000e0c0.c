
/* public: class Texture::ChunkedTexture & __thiscall Texture::ChunkedTexture::operator=(class
   Texture::ChunkedTexture const &) */

ChunkedTexture * __thiscall
Texture::ChunkedTexture::operator=(ChunkedTexture *this,ChunkedTexture *param_1)

{
  int iVar1;
  ChunkedTexture *pCVar2;
  
                    /* 0xe0c0  57  ??4ChunkedTexture@Texture@@QAEAAV01@ABV01@@Z */
  pCVar2 = this;
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pCVar2 = pCVar2 + 4;
  }
  return this;
}

