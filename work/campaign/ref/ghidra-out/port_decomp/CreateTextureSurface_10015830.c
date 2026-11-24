
/* long __cdecl Texture::CreateTextureSurface(class IDirectDraw7Port *,class IDirectDrawSurface7Port
   * *,struct _DDPIXELFORMAT *,wchar_t const *) */

long __cdecl
Texture::CreateTextureSurface
          (IDirectDraw7Port *param_1,IDirectDrawSurface7Port **param_2,_DDPIXELFORMAT *param_3,
          wchar_t *param_4)

{
  int iVar1;
  long extraout_EAX;
  undefined4 in_EDX;
  int local_b4;
  int aiStack_b0 [2];
  void *pvStack_a8;
  undefined8 local_a4;
  undefined4 local_9c;
  IDirectDrawSurface7Port **local_98;
  _DDPIXELFORMAT *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  int local_84;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x15830  112
                       ?CreateTextureSurface@Texture@@YAJPAVIDirectDraw7Port@@PAPAVIDirectDrawSurface7Port@@PAU_DDPIXELFORMAT@@PB_W@Z
                        */
  local_8 = 0xffffffff;
  puStack_c = &LAB_100427f0;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_98 = param_2;
  local_94 = param_3;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_9c = 0;
  local_a4 = 0;
  pvStack_a8 = (void *)0x0;
  local_b4 = 0;
  aiStack_b0[0] = 0;
  aiStack_b0[1] = 0;
  LoadPixelsFromBMP(param_4,&pvStack_a8,&local_b4,aiStack_b0,aiStack_b0 + 1);
  local_8 = 0;
  memset(&local_90,0,0x7c);
  local_84 = local_b4;
  local_88 = aiStack_b0[0];
  local_90 = 0x7c;
  local_48 = *(undefined4 *)local_94;
  uStack_44 = *(undefined4 *)(local_94 + 4);
  uStack_40 = *(undefined4 *)(local_94 + 8);
  uStack_3c = *(undefined4 *)(local_94 + 0xc);
  local_8c = 0x1007;
  local_28 = 0x1000;
  local_38 = *(undefined4 *)(local_94 + 0x10);
  uStack_34 = *(undefined4 *)(local_94 + 0x14);
  uStack_30 = *(undefined4 *)(local_94 + 0x18);
  uStack_2c = *(undefined4 *)(local_94 + 0x1c);
  iVar1 = (**(code **)(*(int *)param_1 + 0xc))(&local_90,local_98,0);
  if (-1 < iVar1) {
    LPDDS_ReloadFromImage(*local_98,local_94,(Image *)&local_b4);
  }
  if ((HDC)local_a4 != (HDC)0x0) {
    DeleteDC((HDC)local_a4);
  }
  if (local_a4._4_4_ != (HGDIOBJ)0x0) {
    DeleteObject(local_a4._4_4_);
  }
  free(pvStack_a8);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

