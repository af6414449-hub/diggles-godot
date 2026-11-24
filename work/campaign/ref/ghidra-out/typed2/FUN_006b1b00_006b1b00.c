
/* WARNING: Removing unreachable block (ram,0x006b3092) */
/* WARNING: Removing unreachable block (ram,0x006b3146) */

void FUN_006b1b00(void)

{
  LPCRITICAL_SECTION p_Var1;
  void *pvVar2;
  DisplayIndexManager *this;
  int *piVar3;
  ScreenResolutionManager *this_00;
  PostProcessOptionManager *this_01;
  int iVar4;
  DisplayModeManager *this_02;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *local_5c;
  int *local_58;
  int *local_54;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined8 local_34;
  int *local_2c;
  FILE *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712cc5;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)g_pServiceManager_exref != (int *)0x0) {
    (**(code **)(**(int **)g_pServiceManager_exref + 0x5c))();
  }
  if (DAT_00773648 != (HWND)0x0) {
    local_38 = 0;
    local_34 = 0.0;
    SendMessageA(DAT_00773648,0x4a,0,(LPARAM)&local_38);
  }
  if (DAT_0076a338 != 0) {
    FUN_00479c10();
    *(undefined1 *)(DAT_00772400 + 0x8a) = 0;
    this = DisplayIndexManager::GetInstance();
    local_28 = (FILE *)DisplayIndexManager::GetDisplayIndex(this);
    local_34 = (double)CONCAT44(&stack0xffffff90,(undefined4)local_34);
    piVar3 = (int *)FUN_006ba810();
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x74646957;
    *(undefined2 *)(piVar3 + 4) = 0x68;
    piVar3[2] = 5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 0;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00();
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_34 = (double)CONCAT44(&stack0xffffff90,(undefined4)local_34);
    piVar3 = (int *)FUN_006ba810();
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x67696548;
    *(undefined2 *)(piVar3 + 4) = 0x7468;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 1;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00();
    local_8 = 0xffffffff;
    FUN_006bec60();
    this_00 = ScreenResolutionManager::GetInstance();
    ScreenResolutionManager::GetDisplayBounds(this_00,(int)&local_24);
    local_28 = (FILE *)&stack0xffffff8c;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x70736944;
    piVar3[4] = 0x4979616c;
    piVar3[5] = 0x7865646e;
    *(undefined1 *)(piVar3 + 6) = 0;
    piVar3[2] = 0xc;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 2;
    piVar3 = (int *)FUN_006ba810(0x19,0x7865646e);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_34 = (double)local_24;
    local_28 = (FILE *)&stack0xffffff8c;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x70736944;
    piVar3[4] = 0x5879616c;
    *(undefined1 *)(piVar3 + 5) = 0;
    piVar3[2] = 8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 3;
    piVar3 = (int *)FUN_006ba810(0x19,extraout_ECX & 0xffffff00);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_34 = (double)local_20;
    local_28 = (FILE *)&stack0xffffff8c;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x70736944;
    piVar3[4] = 0x5979616c;
    *(undefined1 *)(piVar3 + 5) = 0;
    piVar3[2] = 8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 4;
    piVar3 = (int *)FUN_006ba810(0x19,extraout_ECX_00 & 0xffffff00);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_34 = (double)local_1c;
    local_28 = (FILE *)&stack0xffffff8c;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x70736944;
    piVar3[4] = 0x5779616c;
    *(undefined1 *)(piVar3 + 5) = 0;
    piVar3[2] = 8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 5;
    piVar3 = (int *)FUN_006ba810(0x19,extraout_ECX_01 & 0xffffff00);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_34 = (double)local_18;
    local_28 = (FILE *)&stack0xffffff8c;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x70736944;
    piVar3[4] = 0x4879616c;
    *(undefined1 *)(piVar3 + 5) = 0;
    piVar3[2] = 8;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 6;
    piVar3 = (int *)FUN_006ba810(0x19,extraout_ECX_02 & 0xffffff00);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    this_01 = PostProcessOptionManager::GetInstance();
    iVar4 = PostProcessOptionManager::GetModeSet(this_01,0);
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)iVar4;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x69746e41;
    piVar3[4] = 0x61696c41;
    piVar3[5] = 0x676e6973;
    *(undefined1 *)(piVar3 + 6) = 0;
    piVar3[2] = 0xc;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 7;
    piVar3 = (int *)FUN_006ba810(0x19,0x676e6973);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    iVar4 = PostProcessOptionManager::GetModeSet(this_01,1);
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)iVar4;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x74736f50;
    piVar3[4] = 0x65666645;
    *(undefined2 *)(piVar3 + 5) = 0x7463;
    *(undefined1 *)((int)piVar3 + 0x16) = 0;
    piVar3[2] = 10;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 8;
    piVar3 = (int *)FUN_006ba810(0x19,CONCAT22(extraout_var,0x7463));
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    this_02 = DisplayModeManager::GetInstance();
    iVar4 = DisplayModeManager::GetCurrentSet(this_02);
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)iVar4;
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x6c6c7546;
    piVar3[4] = 0x65726373;
    *(undefined2 *)(piVar3 + 5) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x16) = 0;
    piVar3[2] = 10;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 9;
    piVar3 = (int *)FUN_006ba810(0x19,CONCAT22(extraout_var_00,0x6e65));
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)*(float *)(DAT_00772400 + 0x17c);
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x67697242;
    piVar3[4] = 0x656e7468;
    *(undefined2 *)(piVar3 + 5) = 0x7373;
    *(undefined1 *)((int)piVar3 + 0x16) = 0;
    piVar3[2] = 10;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 10;
    piVar3 = (int *)FUN_006ba810(0x19,CONCAT22(extraout_var_01,0x7373));
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)*(float *)(DAT_00772400 + 0x180);
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x6d6d6147;
    *(undefined2 *)(piVar3 + 4) = 0x61;
    piVar3[2] = 5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 0xb;
    piVar3 = (int *)FUN_006ba810(0x19,0x6d6d0061);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x65726353;
    *(undefined2 *)(piVar3 + 4) = 0x6e65;
    *(undefined1 *)((int)piVar3 + 0x12) = 0;
    piVar3[2] = 6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)*(int *)(DAT_00772400 + 0x188);
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x756c6f56;
    piVar3[4] = 0x754d656d;
    piVar3[5] = 0x636973;
    piVar3[2] = 0xb;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 0xc;
    piVar3 = (int *)FUN_006ba810(0x19,0x636973);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x6e756f53;
    *(undefined2 *)(piVar3 + 4) = 100;
    piVar3[2] = 5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    local_28 = (FILE *)&stack0xffffff8c;
    local_34 = (double)*(int *)(DAT_00772400 + 0x184);
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x756c6f56;
    piVar3[4] = 0x6f53656d;
    piVar3[5] = 0x646e75;
    piVar3[2] = 0xb;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    local_8 = 0xd;
    piVar3 = (int *)FUN_006ba810(0x19,0x646e75);
    piVar3[1] = 0x14;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    piVar3[3] = 0x6e756f53;
    *(undefined2 *)(piVar3 + 4) = 100;
    piVar3[2] = 5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bfc00(piVar3);
    local_8 = 0xffffffff;
    FUN_006bec60();
    FUN_0055f320();
    *(undefined1 *)(*(int *)(DAT_00772400 + 0x5a0) + 0xb0) = 1;
    FUN_00479c10(0);
    (**(code **)(**(int **)(DAT_00772400 + 0x5a0) + 0x18))();
    FUN_00479c10();
    FUN_00479c10();
    if ((DAT_007683b5 != '\0') && (local_28 = _fopen("animstats.txt","w"), local_28 != (FILE *)0x0))
    {
      local_34 = (double)CONCAT44(DAT_0077244c,(undefined4)local_34);
      if (0 < *(int *)(DAT_0077244c + 0x115a0)) {
        local_3c = 0;
        local_48 = 0;
        local_44 = 0;
        iVar4 = DAT_0077244c;
        do {
          uVar5 = 0;
          local_40 = 0;
          while( true ) {
            if (*(uint *)(iVar4 + 0x115a0) <= local_48) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*(int *)(local_44 + 4 + *(int *)(iVar4 + 0x1159c)) <= (int)uVar5) break;
            if (local_48 < 0x100) {
              iVar4 = *(int *)(local_3c + 0x5c8 + DAT_00772400);
              local_58 = (int *)(iVar4 + 0xc);
            }
            else {
              iVar4 = 0;
              local_58 = (int *)0xc;
            }
            if (((int)uVar5 < 0) || (*(int *)(iVar4 + 0x50) <= (int)uVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (local_48 < 0x100) {
              iVar4 = *(int *)(local_3c + 0x5c8 + DAT_00772400);
            }
            else {
              iVar4 = 0;
            }
            if (((int)uVar5 < 0) || (*(int *)(iVar4 + 0x50) <= (int)uVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *(int *)(iVar4 + 0x4c);
            }
            else {
              iVar4 = *(int *)(iVar4 + 0x4c) + local_40;
            }
            iVar4 = *(int *)(iVar4 + 0x10);
            piVar3 = (int *)FUN_006ba810();
            piVar3[1] = 4;
            *(undefined2 *)(piVar3 + 3) = 0x3f;
            piVar3[2] = 1;
            *piVar3 = 1;
            local_8 = 0xe;
            local_54 = piVar3;
            if (-1 < iVar4) {
              if (local_48 < 0x100) {
                iVar6 = *(int *)(local_3c + 0x5c8 + DAT_00772400);
              }
              else {
                iVar6 = 0;
              }
              if (iVar4 < *(int *)(iVar6 + 0x44)) {
                if (local_48 < 0x100) {
                  iVar6 = *(int *)(local_3c + 0x5c8 + DAT_00772400);
                }
                else {
                  iVar6 = 0;
                }
                if (iVar4 < *(int *)(iVar6 + 0x44)) {
                  piVar7 = (int *)(iVar4 * 0x10 + *(int *)(iVar6 + 0x40));
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar7 = *(int **)(iVar6 + 0x40);
                }
                local_54 = (int *)*piVar7;
                if (local_54 != (int *)0x0) {
                  *local_54 = *local_54 + 1;
                }
                *piVar3 = *piVar3 + -1;
                if (*piVar3 == 0) {
                  FUN_006ba940();
                }
                local_54[2] = *(int *)(*piVar7 + 8);
              }
            }
            FUN_006b9500();
            local_8 = CONCAT31(local_8._1_3_,0xf);
            FUN_006b9410();
            iVar4 = local_34._4_4_;
            if (*(uint *)(local_34._4_4_ + 0x115a0) <= local_48) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*(uint *)(*(int *)(iVar4 + 0x1159c) + local_44 + 4) <= uVar5) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_00405ab0(local_28,"%i(%s) %i(%s) %i\n",local_48,*local_58 + 0xc,uVar5);
            local_8._0_1_ = 0x10;
            if ((local_5c != (int *)0x0) && (*local_5c = *local_5c + -1, *local_5c == 0)) {
              FUN_006ba940();
            }
            local_8 = CONCAT31(local_8._1_3_,0x11);
            if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
              FUN_006ba940();
            }
            local_8 = 0x12;
            *local_54 = *local_54 + -1;
            if (*local_54 == 0) {
              FUN_006ba940();
            }
            uVar5 = uVar5 + 1;
            local_40 = local_40 + 0x3c;
            local_8 = 0xffffffff;
            iVar4 = local_34._4_4_;
          }
          local_44 = local_44 + 8;
          local_48 = local_48 + 1;
          local_3c = local_3c + 4;
        } while ((int)local_48 < *(int *)(iVar4 + 0x115a0));
      }
      _fclose(local_28);
    }
    FUN_00460eb0();
    FUN_00479c10();
    if (DAT_00c1bf54 != '\0') {
      FUN_006c4310();
      DAT_00c1bf54 = '\0';
    }
    p_Var1 = DAT_0076a29c;
    if (DAT_0076a29c != (LPCRITICAL_SECTION)0x0) {
      local_8 = 0x13;
      FUN_004452c0();
      if (p_Var1[1].LockCount != 0) {
        FUN_006ba940();
      }
      local_8 = 0xffffffff;
      DeleteCriticalSection(p_Var1);
      FUN_006cecd8();
    }
    p_Var1 = DAT_00772404;
    if (DAT_00772404 != (LPCRITICAL_SECTION)0x0) {
      FUN_0055c540();
      DeleteCriticalSection(p_Var1);
      FUN_006cecd8();
    }
    FUN_005c7940();
    FUN_00479c10();
    iVar4 = DAT_00772420;
    if (DAT_00772420 != 0) {
      thunk_FUN_0060fc30();
      FUN_006cecd8(iVar4);
    }
    pvVar2 = DAT_00772428;
    DAT_00772420 = 0;
    if (DAT_00772428 != (void *)0x0) {
      local_8 = 0x14;
      _eh_vector_destructor_iterator_((void *)((int)DAT_00772428 + 0x9c),0xc,0xd,FUN_0049c0d0);
      local_8 = 0x15;
      _eh_vector_destructor_iterator_(pvVar2,0xc,0xd,FUN_0049c0d0);
      local_8 = 0xffffffff;
      FUN_006cecd8();
    }
    piVar3 = DAT_00772480;
    DAT_00772428 = (void *)0x0;
    if (DAT_00772480 != (int *)0x0) {
      local_8 = 0x16;
      FUN_00606b50();
      if (*piVar3 != 0) {
        FUN_006ba940();
      }
      local_8 = 0xffffffff;
      FUN_006cecd8();
    }
    DAT_00772480 = (int *)0x0;
    FUN_00479c10();
    if (DAT_00772368 != 0) {
      FUN_004e4480();
      FUN_006cecd8();
    }
    DAT_00772368 = 0;
    if (DAT_00772470 != 0) {
      FUN_006cecd8();
    }
    DAT_00772470 = 0;
    FUN_00479c10();
    iVar4 = DAT_00772354;
    if (*(char *)(DAT_00772400 + 0x599) != '\0') {
      if (DAT_00772354 != 0) {
        local_8 = 0x17;
        if (*(FILE **)(DAT_00772354 + 0x48) != (FILE *)0x0) {
          _fclose(*(FILE **)(DAT_00772354 + 0x48));
          *(undefined4 *)(iVar4 + 0x48) = 0;
        }
        if (*(int *)(iVar4 + 0x34) != 0) {
          FUN_006cecd8();
        }
        if (DAT_0076a2dc != 0) {
          FUN_00454e20();
          FUN_006cecd8();
        }
        DAT_0076a2e0 = 0;
        SoloudAudioPlayer::Deinit();
        local_8 = CONCAT31(local_8._1_3_,0x18);
        piVar3 = *(int **)(iVar4 + 0x14);
        if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
          FUN_006ba940();
        }
        FUN_004d0950();
        FUN_004d0a00();
        local_8 = 0xffffffff;
        FUN_006cecd8();
      }
      iVar4 = DAT_00772358;
      DAT_00772354 = 0;
      if (DAT_00772358 != 0) {
        local_8 = 0x19;
        FUN_004d1d90();
        if (*(int *)(iVar4 + 0x10) != 0) {
          FUN_006ba940();
        }
        local_8 = 0xffffffff;
        FUN_006cecd8();
      }
      DAT_00772358 = 0;
    }
    FUN_00479c10();
    FUN_005b7940();
    iVar4 = DAT_00772460;
    if (DAT_00772460 != 0) {
      local_8 = 0x1a;
      FUN_0040b980();
      if (*(int *)(iVar4 + 0x3004) != 0) {
        FUN_006ba940();
      }
      local_8 = 0x1b;
      _eh_vector_destructor_iterator_((void *)(iVar4 + 0x2804),8,0x100,FUN_00440560);
      local_8 = 0x1c;
      _eh_vector_destructor_iterator_((void *)(iVar4 + 0x2004),4,0x200,FUN_006b8ed0);
      local_8 = 0x1d;
      _eh_vector_destructor_iterator_((void *)(iVar4 + 4),4,0x200,FUN_006b8ed0);
      local_8 = 0xffffffff;
      FUN_006cecd8();
    }
    DAT_00772460 = 0;
    FUN_00479c10();
    pvVar2 = DAT_00772418;
    if (DAT_00772418 != (void *)0x0) {
      local_8 = 0x1f;
      iVar4 = *(int *)((int)DAT_00772418 + 0x12004);
      if (iVar4 < 0) {
        FUN_00592e10();
      }
      else if (0 < iVar4) {
        *(int *)((int)DAT_00772418 + 0x12004) = *(int *)((int)DAT_00772418 + 0x12004) - iVar4;
      }
      if (*(int *)((int)pvVar2 + 0x12000) != 0) {
        FUN_006ba940();
      }
      local_8 = 0x20;
      _eh_vector_destructor_iterator_(pvVar2,0x24,0x800,guard_check_icall);
      local_8 = 0xffffffff;
      FUN_006cecd8();
    }
    DAT_00772418 = (void *)0x0;
    if (DAT_0076a2a0 != (undefined4 *)0x0) {
      (**(code **)*DAT_0076a2a0)();
    }
    iVar4 = DAT_00772344;
    DAT_0076a2a0 = (undefined4 *)0x0;
    if (DAT_00772344 != 0) {
      local_8 = 0x21;
      iVar6 = *(int *)(DAT_00772344 + 0x1078);
      if (iVar6 < 0) {
        FUN_004c4280();
      }
      else if (0 < iVar6) {
        *(int *)(DAT_00772344 + 0x1078) = *(int *)(DAT_00772344 + 0x1078) - iVar6;
      }
      if (*(int *)(iVar4 + 0x1074) != 0) {
        FUN_006ba940();
      }
      local_8 = 0x22;
      _eh_vector_destructor_iterator_((void *)(iVar4 + 0x38),0x20,0x80,guard_check_icall);
      local_8 = 0xffffffff;
      FUN_004c4040();
      FUN_006cecd8();
    }
    DAT_00772344 = 0;
    FUN_00479c10();
    piVar3 = DAT_00772484;
    if (DAT_00772484 != (int *)0x0) {
      local_8 = 0x23;
      FUN_0060dc60();
      local_8 = CONCAT31(local_8._1_3_,0x24);
      FUN_0040b980();
      if (*piVar3 != 0) {
        FUN_006ba940();
      }
      local_8 = 0xffffffff;
      FUN_006cecd8();
    }
    pvVar2 = DAT_0077240c;
    DAT_00772484 = (int *)0x0;
    if (DAT_0077240c != (void *)0x0) {
      local_8 = 0x25;
      FUN_006ba940();
      *(undefined4 *)((int)pvVar2 + 0xfc) = 0;
      *(undefined4 *)((int)pvVar2 + 0x100) = 0;
      FUN_006ba940();
      *(undefined4 *)((int)pvVar2 + 0x10c) = 0;
      *(undefined4 *)((int)pvVar2 + 0x110) = 0;
      thunk_FUN_0060fc30();
      thunk_FUN_0060fc30();
      local_8 = CONCAT31(local_8._1_3_,0x26);
      _eh_vector_destructor_iterator_(pvVar2,0x28,4,FUN_006c0310);
      local_8 = 0xffffffff;
      FUN_006cecd8();
    }
    DAT_0077240c = (void *)0x0;
    if (DAT_00772414 != 0) {
      FUN_00581740();
      FUN_006cecd8();
    }
    DAT_00772414 = 0;
    FUN_00479c10();
    if (DAT_00772340 != 0) {
      FUN_00492380();
      FUN_006cecd8();
    }
    DAT_00772340 = 0;
    FUN_00479c10();
    CMap__Shut(PTR_0077241c);
    FUN_00479c10();
    if (PTR_0077241c != (CMap *)0x0) {
      FUN_00593c20();
      FUN_006cecd8();
    }
    PTR_0077241c = (CMap *)0x0;
    FUN_00479c10();
    iVar4 = DAT_0076a338;
    DAT_0076a338 = 0;
    Sleep(100);
    if (iVar4 != 0) {
      FUN_00464ab0();
      FUN_006cecd8();
    }
    ReleaseCapture();
    FUN_006be3f0();
    FUN_006be780();
    if (DAT_00772400 != 0) {
      FUN_006b3420();
      FUN_006cecd8();
    }
    DAT_00772400 = 0;
    if (*(int **)g_pServiceManager_exref != (int *)0x0) {
      (**(code **)(**(int **)g_pServiceManager_exref + 4))();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

