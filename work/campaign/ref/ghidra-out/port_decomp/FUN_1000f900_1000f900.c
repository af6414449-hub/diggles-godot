
void FUN_1000f900(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  ScreenResolutionManager **ppSVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  ScreenResolutionManager *pSVar7;
  int iVar8;
  int *piVar9;
  undefined1 *pExceptionObject;
  ScreenResolutionManager **in_ECX;
  undefined4 in_EDX;
  undefined1 local_6c [16];
  undefined1 local_5c [16];
  undefined4 local_4c;
  ScreenResolutionManager *local_48;
  ScreenResolutionManager *local_44;
  ScreenResolutionManager *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_2c;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_100423a5;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  pSVar7 = (ScreenResolutionManager *)FUN_1003ff62(0xd8);
  *(int *)(pSVar7 + 0x88) = 0;
  *(int *)(pSVar7 + 0x90) = 0;
  *(int *)(pSVar7 + 0x94) = 0;
  *(int *)(pSVar7 + 0x98) = 0;
  *(int *)(pSVar7 + 0x9c) = 0;
  *(int *)(pSVar7 + 0xa0) = 0;
  *(int *)(pSVar7 + 0xa4) = 0;
  *(int *)(pSVar7 + 0xa8) = 0;
  *(int *)(pSVar7 + 0xac) = 0;
  *(undefined8 *)(pSVar7 + 0xb4) = 0;
  *(undefined8 *)(pSVar7 + 0xc6) = 0;
  *(undefined2 *)(pSVar7 + 0xce) = 0;
  *(undefined2 *)(pSVar7 + 0xd1) = 0;
  pSVar7[0xd3] = (ScreenResolutionManager)0x0;
  *(int *)pSVar7 = 0;
  *(int *)(pSVar7 + 4) = 0;
  *(int *)(pSVar7 + 8) = 0;
  *(int *)(pSVar7 + 0xc) = 0;
  *(int *)(pSVar7 + 0x10) = 0;
  *(int *)(pSVar7 + 0x14) = 0;
  *(int *)(pSVar7 + 0x18) = 0;
  *(int *)(pSVar7 + 0x1c) = 0;
  *(int *)(pSVar7 + 0x20) = 0;
  *(int *)(pSVar7 + 0x24) = 0;
  *(int *)(pSVar7 + 0x28) = 0;
  *(int *)(pSVar7 + 0x2c) = 0;
  *(int *)(pSVar7 + 0x30) = 0;
  *(undefined8 *)(pSVar7 + 0x34) = 0;
  *(int *)(pSVar7 + 0x3c) = 0;
  *(int *)(pSVar7 + 0x40) = 0;
  *(int *)(pSVar7 + 0x44) = 0;
  *(int *)(pSVar7 + 0x48) = 0;
  *(int *)(pSVar7 + 0x4c) = 0;
  *(int *)(pSVar7 + 0x50) = 0;
  *(int *)(pSVar7 + 100) = 0;
  *(int *)(pSVar7 + 0x6c) = 0;
  *(int *)(pSVar7 + 0x70) = 0;
  *(int *)(pSVar7 + 0x7c) = 0;
  *(int *)(pSVar7 + 0x84) = 0;
  *(int *)(pSVar7 + 0x8c) = 0;
  *(int *)(pSVar7 + 0xb0) = 0;
  *(undefined2 *)(pSVar7 + 0xc4) = 0;
  *(int *)(pSVar7 + 0xd4) = 0;
  *(int *)(pSVar7 + 0x54) = 0x57;
  *(int *)(pSVar7 + 0x58) = 0x28;
  *(int *)(pSVar7 + 0x5c) = 2;
  *(int *)(pSVar7 + 0x60) = 0xb000;
  *(int *)(pSVar7 + 0x68) = 0xb000;
  *(int *)(pSVar7 + 0x74) = 1;
  *(int *)(pSVar7 + 0x78) = 1;
  *(int *)(pSVar7 + 0x80) = 1;
  *(int *)(pSVar7 + 0xbc) = 0x32;
  *(int *)(pSVar7 + 0xc0) = 0x32;
  pSVar7[0xd0] = (ScreenResolutionManager)0x1;
  if (in_ECX == &local_44) {
    FUN_10010680();
LAB_1000fa82:
    FUN_100402ac(pSVar7,0xd8);
  }
  else {
    local_40 = *in_ECX;
    *in_ECX = pSVar7;
    if (local_40 != (ScreenResolutionManager *)0x0) {
      FUN_10010680();
      pSVar7 = local_40;
      goto LAB_1000fa82;
    }
  }
  iVar8 = FUN_10005840();
  if (iVar8 < 0) goto LAB_1000fe22;
  *(undefined4 *)(*in_ECX + 100) = param_1;
  local_40 = ScreenResolutionManager::s_instance;
  if (ScreenResolutionManager::s_instance == (ScreenResolutionManager *)0x0) {
    pSVar7 = (ScreenResolutionManager *)FUN_1003ff62(0x2c);
    local_14 = 0;
    local_44 = pSVar7;
    memset(pSVar7,0,0x2c);
    ScreenResolutionManager::s_instance =
         (ScreenResolutionManager *)ScreenResolutionManager::ScreenResolutionManager(pSVar7);
    local_14 = 0xffffffff;
  }
  local_40 = ScreenResolutionManager::s_instance;
  local_44 = *(ScreenResolutionManager **)(ScreenResolutionManager::s_instance + 0x14);
  local_4c = *(undefined4 *)(ScreenResolutionManager::s_instance + 0x18);
  uVar3 = param_3[1];
  pSVar7 = *in_ECX;
  *(undefined4 *)(pSVar7 + 0xbc) = *param_3;
  *(undefined4 *)(pSVar7 + 0xc0) = uVar3;
  (*in_ECX)[0xc4] = (ScreenResolutionManager)0x1;
  local_48 = (ScreenResolutionManager *)FUN_1003ff62(0xac);
  local_14 = 1;
  memset(local_48,0,0xac);
  pSVar7 = (ScreenResolutionManager *)FUN_100096d0();
  local_14 = 0xffffffff;
  ppSVar1 = in_ECX + 2;
  if (ppSVar1 == &local_48) {
    if (pSVar7 != (ScreenResolutionManager *)0x0) {
      FUN_100103f0();
      goto LAB_1000fb81;
    }
  }
  else {
    local_48 = *ppSVar1;
    *ppSVar1 = pSVar7;
    if (local_48 != (ScreenResolutionManager *)0x0) {
      FUN_100103f0();
      pSVar7 = local_48;
LAB_1000fb81:
      FUN_100402ac(pSVar7,0xac);
    }
  }
  FUN_10010060(local_44,local_4c);
  pSVar7 = *in_ECX;
  iVar8 = *(int *)(pSVar7 + 0x74);
  local_44 = (ScreenResolutionManager *)(*(int *)(pSVar7 + 0x78) - *(int *)(pSVar7 + 0x70));
  iVar4 = *(int *)(pSVar7 + 0x6c);
  if (DisplayModeManager::s_instance == (DisplayModeManager *)0x0) {
    DisplayModeManager::s_instance = (DisplayModeManager *)FUN_1003ff62(0xc);
    *(undefined8 *)DisplayModeManager::s_instance = 0;
    *(undefined4 *)(DisplayModeManager::s_instance + 8) = 0;
  }
  pSVar7 = local_40;
  ScreenResolutionManager::ReconstructAfterEnumeration
            (local_40,iVar8 - iVar4,(uint)local_44,*(int *)(DisplayModeManager::s_instance + 4));
  pSVar7[0x1d] = (ScreenResolutionManager)0x0;
  pSVar7 = in_ECX[3];
  local_2c = 0;
  local_38 = 0;
  piVar9 = *(int **)(*in_ECX + 4);
  local_3c = 0x80;
  local_34 = 4;
  local_30 = 0;
  if (pSVar7 != (ScreenResolutionManager *)0x0) {
    in_ECX[3] = (ScreenResolutionManager *)0x0;
    (**(code **)(*(int *)pSVar7 + 8))(pSVar7);
  }
  iVar8 = (**(code **)(*piVar9 + 0xc))(piVar9,&local_3c,0,in_ECX + 3);
  if (iVar8 < 0) {
LAB_1000fe55:
    FUN_100053a0(iVar8);
    pExceptionObject = local_5c;
LAB_1000fe66:
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_1004a24c);
  }
  pSVar7 = in_ECX[4];
  local_2c = 0;
  local_38 = 0;
  local_3c = 0x50;
  local_34 = 4;
  local_30 = 0;
  if (pSVar7 != (ScreenResolutionManager *)0x0) {
    in_ECX[4] = (ScreenResolutionManager *)0x0;
    (**(code **)(*(int *)pSVar7 + 8))(pSVar7);
  }
  iVar8 = (**(code **)(*piVar9 + 0xc))(piVar9,&local_3c,0,in_ECX + 4);
  if (iVar8 < 0) goto LAB_1000fe55;
  pSVar7 = in_ECX[0x329];
  local_2c = 0;
  local_38 = 0;
  local_3c = 0x300;
  local_34 = 4;
  local_30 = 0;
  if (pSVar7 != (ScreenResolutionManager *)0x0) {
    in_ECX[0x329] = (ScreenResolutionManager *)0x0;
    (**(code **)(*(int *)pSVar7 + 8))(pSVar7);
  }
  iVar8 = (**(code **)(*piVar9 + 0xc))(piVar9,&local_3c,0,in_ECX + 0x329);
  if (iVar8 < 0) goto LAB_1000fe55;
  pSVar7 = in_ECX[0x32a];
  local_2c = 0;
  local_38 = 0;
  local_3c = 0x20;
  local_34 = 4;
  local_30 = 0;
  if (pSVar7 != (ScreenResolutionManager *)0x0) {
    in_ECX[0x32a] = (ScreenResolutionManager *)0x0;
    (**(code **)(*(int *)pSVar7 + 8))(pSVar7);
  }
  iVar8 = (**(code **)(*piVar9 + 0xc))(piVar9,&local_3c,0,in_ECX + 0x32a);
  if (iVar8 < 0) goto LAB_1000fe55;
  local_44 = (ScreenResolutionManager *)FUN_1003ff62(0x2c);
  local_14 = 2;
  memset(local_44,0,0x2c);
  piVar9 = (int *)FUN_1000bc30();
  local_14 = 0xffffffff;
  local_40 = (ScreenResolutionManager *)(in_ECX + 1);
  if (local_40 == (ScreenResolutionManager *)&local_44) {
    if (piVar9 != (int *)0x0) {
      FUN_1000c790(piVar9,*(undefined4 *)(*piVar9 + 4));
      FUN_100402ac(*piVar9,0x18);
      goto LAB_1000fdba;
    }
  }
  else {
    piVar5 = *(int **)local_40;
    *(int **)local_40 = piVar9;
    if (piVar5 != (int *)0x0) {
      FUN_1000c790(piVar5,*(undefined4 *)(*piVar5 + 4));
      FUN_100402ac(*piVar5,0x18);
      piVar9 = piVar5;
LAB_1000fdba:
      FUN_100402ac(piVar9,0x2c);
    }
  }
  piVar9 = *(int **)**(undefined4 **)local_40;
  cVar2 = *(char *)((int)piVar9 + 0xd);
  while (cVar2 == '\0') {
    iVar8 = FUN_1000b060();
    if (iVar8 < 0) {
      FUN_100053a0(iVar8);
      pExceptionObject = local_6c;
      goto LAB_1000fe66;
    }
    piVar5 = (int *)piVar9[2];
    if (*(char *)((int)piVar5 + 0xd) == '\0') {
      cVar2 = *(char *)(*piVar5 + 0xd);
      piVar9 = piVar5;
      piVar5 = (int *)*piVar5;
      while (cVar2 == '\0') {
        cVar2 = *(char *)(*piVar5 + 0xd);
        piVar9 = piVar5;
        piVar5 = (int *)*piVar5;
      }
    }
    else {
      cVar2 = *(char *)(piVar9[1] + 0xd);
      piVar6 = (int *)piVar9[1];
      piVar5 = piVar9;
      while ((piVar9 = piVar6, cVar2 == '\0' && (piVar5 == (int *)piVar9[2]))) {
        cVar2 = *(char *)(piVar9[1] + 0xd);
        piVar6 = (int *)piVar9[1];
        piVar5 = piVar9;
      }
    }
    cVar2 = *(char *)((int)piVar9 + 0xd);
  }
LAB_1000fe22:
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
  return;
}

