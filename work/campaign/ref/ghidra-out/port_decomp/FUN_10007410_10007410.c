
void FUN_10007410(undefined4 param_1)

{
  undefined4 uVar1;
  DisplayIndexManager *pDVar2;
  ScreenResolutionManager *pSVar3;
  int iVar4;
  void *_Dst;
  int *pExceptionObject;
  int in_ECX;
  uint *puVar5;
  undefined4 in_EDX;
  char *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int local_78 [4];
  undefined4 local_68;
  undefined4 *local_64;
  undefined4 *local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  ScreenResolutionManager *local_4c;
  int *local_48;
  undefined4 local_44;
  uint local_40;
  char *local_3c;
  uint local_38;
  undefined4 *local_34;
  int local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_100419e4;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  local_48 = (int *)0x0;
  local_28 = (int *)0x0;
  FUN_10006b00(&local_48,&local_28);
  if (local_28 == (int *)0x0) {
    FUN_100028b0(&DAT_1416ed48,0x80,"Failed to find output for point %d, %d \n",
                 *(undefined4 *)(in_ECX + 0xbc),*(undefined4 *)(in_ECX + 0xc0));
    OutputDebugStringA(&DAT_1416ed48);
    iVar4 = -1;
  }
  else {
    pDVar2 = DisplayIndexManager::GetInstance();
    local_30 = *(int *)pDVar2;
    if (ScreenResolutionManager::s_instance == (ScreenResolutionManager *)0x0) {
      pSVar3 = (ScreenResolutionManager *)FUN_1003ff62(0x2c);
      local_14 = 0;
      local_4c = pSVar3;
      memset(pSVar3,0,0x2c);
      ScreenResolutionManager::s_instance =
           (ScreenResolutionManager *)ScreenResolutionManager::ScreenResolutionManager(pSVar3);
      local_14 = 0xffffffff;
    }
    ScreenResolutionManager::GetDisplayBounds
              (ScreenResolutionManager::s_instance,local_30,(tagRECT *)&local_5c);
    local_38 = local_50 - local_58;
    uVar8 = local_54 - local_5c;
    local_64 = (undefined4 *)(in_ECX + 0x8c);
    local_34 = (undefined4 *)uVar8;
    if (*(int *)(in_ECX + 0x8c) != 0) {
      free(*(void **)(in_ECX + 0x90));
      *(undefined4 *)(in_ECX + 0xb0) = 0;
      *(undefined4 *)(in_ECX + 0x94) = 0;
      *(undefined4 *)(in_ECX + 0x98) = 0;
      *(undefined4 *)(in_ECX + 0x9c) = 0;
      *(undefined4 *)(in_ECX + 0xa0) = 0;
      *(undefined8 *)(in_ECX + 0xa4) = 0;
      *(undefined4 *)(in_ECX + 0xac) = 0;
    }
    local_2c = 0;
    iVar4 = (**(code **)(*local_28 + 0x20))(local_28,param_1,0,&local_2c,0);
    if (-1 < iVar4) {
      *(uint *)(in_ECX + 0x8c) = local_2c;
      _Dst = (void *)FUN_100402f0(-(uint)((int)((ulonglong)local_2c * 0x1c >> 0x20) != 0) |
                                  (uint)((ulonglong)local_2c * 0x1c));
      local_4c = (ScreenResolutionManager *)(in_ECX + 0x90);
      *(void **)local_4c = _Dst;
      memset(_Dst,0,local_2c * 0x1c);
      iVar4 = (**(code **)(*local_28 + 0x20))
                        (local_28,param_1,0,&local_2c,*(undefined4 *)(in_ECX + 0x90));
      if (-1 < iVar4) {
        FUN_10006df0(uVar8,local_38);
        local_60 = (undefined4 *)(in_ECX + 0xd4);
        local_30 = 0;
        local_44 = 0;
        if ((void *)*local_60 != (void *)0x0) {
          free((void *)*local_60);
        }
        local_68 = *(undefined4 *)(in_ECX + 0x90);
        uVar8 = 1;
        local_3c = (char *)FUN_100402f0(0xe);
        puVar5 = &DAT_100510a8;
        *local_3c = '\0';
        pcVar6 = local_3c;
        do {
          pcVar6 = pcVar6 + 1;
          *pcVar6 = '\0';
          if ((*puVar5 < local_34) && (puVar5[1] < local_38)) {
            uVar8 = uVar8 + 1;
          }
          else {
            *pcVar6 = '\x01';
          }
          puVar5 = puVar5 + 2;
        } while ((int)puVar5 < 0x10051110);
        local_40 = uVar8;
        local_34 = (undefined4 *)
                   FUN_100402f0(-(uint)((int)((ulonglong)uVar8 * 8 >> 0x20) != 0) |
                                (uint)((ulonglong)uVar8 * 8));
        puVar7 = local_34;
        for (; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7 = puVar7 + 2;
        }
        puVar9 = &DAT_100510a8;
        puVar7 = local_34;
        pcVar6 = local_3c;
        do {
          if (*pcVar6 == '\0') {
            uVar1 = puVar9[-1];
            *puVar7 = puVar9[-2];
            puVar7[1] = uVar1;
            puVar7 = puVar7 + 2;
          }
          if (pcVar6[1] == '\0') {
            uVar1 = puVar9[1];
            *puVar7 = *puVar9;
            puVar7[1] = uVar1;
            puVar7 = puVar7 + 2;
          }
          puVar9 = puVar9 + 4;
          pcVar6 = pcVar6 + 2;
        } while ((int)puVar9 < 0x10051118);
        free(local_3c);
        puVar9 = local_34;
        puVar7 = local_64;
        FUN_10006fc0(local_34,local_40,&local_30,local_60,&local_44);
        free(puVar9);
        pSVar3 = local_4c;
        *puVar7 = local_44;
        free(*(void **)local_4c);
        *(int *)pSVar3 = local_30;
        (**(code **)(*local_48 + 8))(local_48);
        (**(code **)(*local_28 + 8))(local_28);
        ExceptionList = local_1c;
        __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
        return;
      }
      FUN_100053a0(iVar4);
      pExceptionObject = local_78;
      goto LAB_10007798;
    }
  }
  FUN_100053a0(iVar4);
  pExceptionObject = &local_5c;
LAB_10007798:
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_1004a24c);
}

