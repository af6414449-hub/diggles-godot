
/* public: void __thiscall ScreenResolutionManager::ValidateDesiredResolution(int,unsigned int
   &,unsigned int &,int) */

void __thiscall
ScreenResolutionManager::ValidateDesiredResolution
          (ScreenResolutionManager *this,int param_1,uint *param_2,uint *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  uint uStack_98;
  ScreenResolutionManager *local_94;
  uint *local_90;
  int local_8c;
  double dStack_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  uint uStack_74;
  double dStack_70;
  double dStack_68;
  undefined4 local_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint local_14;
  
                    /* 0x129d0  274
                       ?ValidateDesiredResolution@ScreenResolutionManager@@QAEXHAAI0H@Z */
  local_14 = DAT_1005000c ^ (uint)&uStack_98;
  local_8c = param_1;
  local_90 = param_3;
  local_94 = this;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  local_50 = 0;
  iVar1 = SDL_GetDisplayMode(param_1,0,&local_60);
  if (iVar1 != 0) {
    uVar2 = SDL_GetError();
    SDL_Log("SDL_GetDisplayMode failed: %s",uVar2);
    __security_check_cookie(local_14 ^ (uint)&uStack_98);
    return;
  }
  iVar1 = SDL_GetNumVideoDisplays();
  if (param_1 < iVar1) {
    puVar3 = (undefined4 *)(param_1 * 0x10 + *(int *)(local_94 + 0x20));
    uStack_80 = *puVar3;
    uStack_7c = puVar3[1];
    uStack_78 = puVar3[2];
    uStack_74 = puVar3[3];
  }
  else {
    uStack_80 = 0;
    uStack_7c = 0;
    uStack_78 = 0;
    uStack_74 = 0;
  }
  local_94 = (ScreenResolutionManager *)*param_2;
  if ((uStack_78 < local_94) || (uStack_98 = *local_90, uStack_74 < uStack_98)) {
    *param_2 = uStack_78;
    *local_90 = uStack_74;
    local_94 = (ScreenResolutionManager *)*param_2;
    uStack_98 = *local_90;
  }
  uStack_5c = (uint)local_94;
  uStack_58 = uStack_98;
  if (param_4 == 1) {
    iVar1 = SDL_GetClosestDisplayMode(local_8c,&local_60,&local_40);
    if (iVar1 != 0) {
      *param_2 = uStack_3c;
      *local_90 = uStack_38;
      __security_check_cookie(local_14 ^ (uint)&uStack_98);
      return;
    }
  }
  else {
    if (param_4 == 4) {
      *param_2 = uStack_78;
      *local_90 = uStack_74;
      __security_check_cookie(local_14 ^ (uint)&uStack_98);
      return;
    }
    dVar8 = 999999999.0;
    iVar1 = -1;
    iVar5 = 0;
    dVar6 = (double)(int)uStack_78 + *(double *)(&DAT_10047c80 + ((int)uStack_78 >> 0x1f) * -8);
    puVar4 = local_90;
    dStack_88 = dVar6;
    do {
      dVar7 = (double)(int)(&DAT_100510a0)[iVar5 * 2] +
              *(double *)(&DAT_10047c80 + ((int)(&DAT_100510a0)[iVar5 * 2] >> 0x1f) * -8);
      if (((dVar7 < dVar6) &&
          (dStack_70 = (double)(int)(&DAT_100510a4)[iVar5 * 2] +
                       *(double *)(&DAT_10047c80 + ((int)(&DAT_100510a4)[iVar5 * 2] >> 0x1f) * -8),
          dVar6 = dStack_88,
          dStack_70 <
          (double)(int)uStack_74 + *(double *)(&DAT_10047c80 + ((int)uStack_74 >> 0x1f) * -8))) &&
         ((dVar7 = ABS(((double)(int)*param_2 +
                       *(double *)(&DAT_10047c80 + ((int)*param_2 >> 0x1f) * -8)) - dVar7) * 10000.0
                   + ABS(((double)(int)*puVar4 +
                         *(double *)(&DAT_10047c80 + ((int)*puVar4 >> 0x1f) * -8)) - dStack_70),
          dVar7 < dVar8 || (iVar1 < 0)))) {
        local_8c = iVar5;
        dStack_68 = dVar7;
        local_94 = (ScreenResolutionManager *)FUN_10041395();
        uStack_98 = FUN_10041395();
        puVar4 = local_90;
        iVar1 = iVar5;
        dVar8 = dStack_68;
        dVar6 = dStack_88;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xe);
    *param_2 = (uint)local_94;
    *puVar4 = uStack_98;
  }
  __security_check_cookie(local_14 ^ (uint)&uStack_98);
  return;
}

