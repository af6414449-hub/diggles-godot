
/* long __cdecl Texture::GetPixelFormatR8G8B8A8(struct _DDPIXELFORMAT *) */

long __cdecl Texture::GetPixelFormatR8G8B8A8(_DDPIXELFORMAT *param_1)

{
                    /* 0x15a10  165  ?GetPixelFormatR8G8B8A8@Texture@@YAJPAU_DDPIXELFORMAT@@@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined4 *)param_1 = 0x20;
  *(undefined4 *)(param_1 + 0xc) = 0x20;
  *(undefined4 *)(param_1 + 4) = 0x41;
  *(undefined4 *)(param_1 + 0x10) = 0xff0000;
  *(undefined4 *)(param_1 + 0x14) = 0xff00;
  *(undefined4 *)(param_1 + 0x18) = 0xff;
  *(undefined4 *)(param_1 + 0x1c) = 0xff000000;
  return 0;
}

