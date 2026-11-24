
/* long __cdecl Texture::ReCreateTextureSurface(class IDirectDraw7Port *,class
   IDirectDrawSurface7Port * *,struct _DDPIXELFORMAT *,wchar_t const *) */

long __cdecl
Texture::ReCreateTextureSurface
          (IDirectDraw7Port *param_1,IDirectDrawSurface7Port **param_2,_DDPIXELFORMAT *param_3,
          wchar_t *param_4)

{
  IDirectDrawSurface7Port *pIVar1;
  long lVar2;
  
                    /* 0x159d0  219
                       ?ReCreateTextureSurface@Texture@@YAJPAVIDirectDraw7Port@@PAPAVIDirectDrawSurface7Port@@PAU_DDPIXELFORMAT@@PB_W@Z
                        */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  pIVar1 = *param_2;
  if (pIVar1 != (IDirectDrawSurface7Port *)0x0) {
    (**(code **)(*(int *)pIVar1 + 8))(pIVar1);
    *param_2 = (IDirectDrawSurface7Port *)0x0;
  }
  lVar2 = CreateTextureSurface(param_1,param_2,param_3,param_4);
  return lVar2;
}

