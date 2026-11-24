
void CDummyObjMgr__FlushRenderJobs(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *in_ECX;
  int iVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uVar7;
  int iStack_54;
  uint uStack_50;
  int local_4c;
  uint local_48;
  undefined4 *local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 *local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007079dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_34 = in_ECX;
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6570) &&
     (FUN_006cebf4(&DAT_00ca6570,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6570 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6574 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "CDummyObjMgr::FlushRenderJobs";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6570);
  }
  local_30 = DAT_00ca6574 * 0x40;
  local_44 = &DAT_00ca6574;
  uVar1 = *(undefined4 *)(&DAT_00773650 + local_30);
  iVar3 = FUN_0043fcc0();
  iVar4 = local_30;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)&DAT_00773654 + local_30);
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = *(int *)((int)&DAT_00773654 + iVar4);
    *(undefined8 *)((int)&DAT_00773658 + iVar4) = uVar7;
  }
  *(int *)((int)&DAT_00773654 + iVar4) = iVar3 + 1;
  local_8 = 0;
  *in_ECX = *(undefined4 *)(DAT_00772400 + 100);
  iStack_54 = param_1[2];
  uStack_50 = param_1[3];
  local_24 = (int)(*param_1 + -0x20 + (*param_1 + -0x20 >> 0x1f & 7U)) >> 3;
  local_30 = (int)(iStack_54 + 0x20 + (iStack_54 + 0x20 >> 0x1f & 7U)) >> 3;
  local_14 = (int)(param_1[1] + -0x20 + (param_1[1] + -0x20 >> 0x1f & 7U)) >> 3;
  iVar3 = (int)(((int)(uStack_50 + 0x20) >> 0x1f & 7U) + uStack_50 + 0x20) >> 3;
  local_40 = iVar3;
  FUN_0040ba00();
  local_4c = 0;
  local_48 = 0;
  local_8._0_1_ = 2;
  local_18 = DAT_0077244c;
  if (local_14 < 1) {
    local_14 = (local_14 - 1U & 7) + 1;
  }
  if (local_24 < 1) {
    local_24 = (local_24 - 1U & 7) + 1;
  }
  iVar4 = local_30;
  if (local_14 <= iVar3) {
    do {
      local_20 = local_24;
      if (local_24 <= iVar4) {
        local_3c = local_18 + 0x849c;
        local_28 = (int)(local_14 + (local_14 >> 0x1f & 7U)) >> 3;
        do {
          FUN_005647a0(&iStack_54,local_20,local_14);
          uVar5 = 0;
          if (0 < (int)uStack_50) {
            bVar6 = uStack_50 != 0;
            do {
              if (!bVar6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_2c = *(int **)(iStack_54 + uVar5 * 4);
              if (local_2c < (int *)0x3000) {
                local_1c = (int)local_2c * 0xd8;
                if ((int)local_2c < (int)in_ECX[0x3003]) {
                  iVar3 = in_ECX[0x3002] + local_1c;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar3 = in_ECX[0x3002];
                }
                cVar2 = FUN_005b8190(param_1,iVar3);
                if (cVar2 != '\0') {
                  if ((int)local_2c < (int)in_ECX[0x3003]) {
                    iVar3 = in_ECX[0x3002] + local_1c;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar3 = in_ECX[0x3002];
                  }
                  FUN_00453f00(iVar3 + 0x4c);
                }
              }
              uVar5 = uVar5 + 1;
              bVar6 = uVar5 < uStack_50;
            } while ((int)uVar5 < (int)uStack_50);
          }
          local_2c = (int *)((int)(local_20 + (local_20 >> 0x1f & 7U)) >> 3);
          iVar3 = *(int *)(local_18 + 0x849c) * local_28 + (int)local_2c;
          if (iVar3 < 0) {
            FUN_0042fbb0(0);
          }
          else {
            iVar3 = FUN_00564090(iVar3);
            if (&local_4c != (int *)(iVar3 + 8)) {
              FUN_0042fbb0(*(undefined4 *)(iVar3 + 0xc));
              iVar4 = 0;
              if (0 < *(int *)(iVar3 + 0xc)) {
                do {
                  *(undefined4 *)(local_4c + iVar4 * 4) =
                       *(undefined4 *)(*(int *)(iVar3 + 8) + iVar4 * 4);
                  iVar4 = iVar4 + 1;
                } while (iVar4 < *(int *)(iVar3 + 0xc));
              }
            }
          }
          uVar5 = 0;
          if (0 < (int)local_48) {
            bVar6 = local_48 != 0;
            do {
              if (!bVar6) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              FUN_005cb210();
              uVar5 = uVar5 + 1;
              bVar6 = uVar5 < local_48;
              in_ECX = local_34;
            } while ((int)uVar5 < (int)local_48);
          }
          iVar3 = FUN_00564090(*(int *)(local_18 + 0x849c) * local_28 + (int)local_2c);
          local_38 = *(int *)(iVar3 + 0x1c);
          local_2c = (int *)(iVar3 + 0x18);
          uVar5 = 0;
          if (0 < local_38) {
            local_1c = 0;
            do {
              if ((uint)local_2c[1] <= uVar5) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              FUN_005b8540(param_1,*local_2c + local_1c);
              local_1c = local_1c + 0x34;
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 < local_38);
          }
          local_20 = local_20 + 8;
          iVar4 = local_30;
        } while (local_20 <= local_30);
      }
      local_14 = local_14 + 8;
    } while (local_14 <= local_40);
  }
  uVar5 = uStack_50;
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_0042fbb0(0);
  if (local_4c != 0) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if ((int)uVar5 < 0) {
    FUN_0040b930(-uVar5);
  }
  if (iStack_54 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

