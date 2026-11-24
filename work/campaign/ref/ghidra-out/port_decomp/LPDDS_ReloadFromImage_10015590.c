
/* long __cdecl Texture::LPDDS_ReloadFromImage(struct IDirectDrawSurface7 *,struct _DDPIXELFORMAT
   *,class Texture::Image *) */

long __cdecl
Texture::LPDDS_ReloadFromImage(IDirectDrawSurface7 *param_1,_DDPIXELFORMAT *param_2,Image *param_3)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  long extraout_EAX;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int local_8c;
  int local_88;
  undefined4 local_84;
  undefined1 local_80 [12];
  uint local_74;
  uint *local_60;
  uint local_8;
  
                    /* 0x15590  200
                       ?LPDDS_ReloadFromImage@Texture@@YAJPAUIDirectDrawSurface7@@PAU_DDPIXELFORMAT@@PAVImage@1@@Z
                        */
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  memset(local_80,0,0x78);
  local_84 = 0x7c;
  iVar2 = (**(code **)(*(int *)param_1 + 100))(param_1,0,&local_84,1,0);
  if (iVar2 == 0) {
    iVar2 = 0;
    local_88 = 0;
    local_8c = 0;
    iVar1 = *(int *)(param_3 + 0xc);
    if (0 < *(int *)param_3) {
      iVar4 = *(int *)(param_3 + 4);
      do {
        iVar6 = 0;
        if (0 < iVar4) {
          pbVar3 = (byte *)(iVar1 + 2 + iVar2);
          puVar5 = local_60;
          do {
            iVar6 = iVar6 + 1;
            iVar2 = local_88 + 3;
            *puVar5 = (uint)*pbVar3 << 0x10 | (uint)pbVar3[-1] << 8 | (uint)pbVar3[-2] | 0xff000000;
            puVar5 = (uint *)((int)puVar5 + (local_74 & 0xfffffffc));
            iVar4 = *(int *)(param_3 + 4);
            pbVar3 = pbVar3 + 3;
            local_88 = iVar2;
          } while (iVar6 < iVar4);
        }
        local_8c = local_8c + 1;
        local_60 = local_60 + 1;
      } while (local_8c < *(int *)param_3);
    }
    (**(code **)(*(int *)param_1 + 0x80))(param_1,0);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return extraout_EAX;
}

