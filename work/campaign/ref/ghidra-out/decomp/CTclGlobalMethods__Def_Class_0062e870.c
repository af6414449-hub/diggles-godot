
undefined4
CTclGlobalMethods__Def_Class(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined **ppuVar9;
  undefined4 uVar10;
  bool bVar11;
  undefined8 uVar12;
  char *pcVar13;
  int local_2c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c9c5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6df0) {
    FUN_006cebf4(&DAT_00ca6df0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar4 = DAT_00783650;
    if (DAT_00ca6df0 == -1) {
      iVar8 = DAT_00783650 * 0x40;
      DAT_00ca6df4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::Def_Class()";
      *(int *)(&DAT_00773650 + iVar8) = iVar4;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6df0);
    }
  }
  iVar8 = DAT_00ca6df4;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6df4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar10;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar12;
  }
  iVar3 = param_3;
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8._0_1_ = 2;
  if (param_1 != (int *)0x0) {
    if (param_1 == *(int **)(DAT_0077244c + 0xd4)) {
      if (DAT_00772440[1] == 0) {
        ppuVar9 = &PTR_0071ce50;
        pbVar5 = (byte *)(DAT_00772440[2] + 0xc);
        do {
          bVar1 = *pbVar5;
          bVar11 = bVar1 < *(byte *)ppuVar9;
          if (bVar1 != *(byte *)ppuVar9) {
LAB_0062e9e7:
            uVar6 = -(uint)bVar11 | 1;
            goto LAB_0062e9ec;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar11 = bVar1 < *(byte *)((int)ppuVar9 + 1);
          if (bVar1 != *(byte *)((int)ppuVar9 + 1)) goto LAB_0062e9e7;
          pbVar5 = pbVar5 + 2;
          ppuVar9 = (undefined **)((int)ppuVar9 + 2);
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_0062e9ec:
        if (uVar6 == 0) {
          if (iVar3 == 3) {
            puVar7 = (undefined4 *)FUN_004295e0(1);
            piVar2 = (int *)*puVar7;
            if (piVar2 != (int *)0x0) {
              *piVar2 = *piVar2 + 1;
            }
            puVar7 = (undefined4 *)FUN_004295e0(2);
            local_14 = (int *)*puVar7;
            if (local_14 != (int *)0x0) {
              *local_14 = *local_14 + 1;
            }
            local_8._0_1_ = 4;
            uVar10 = FUN_006bafc0();
            FUN_006b8fb0(uVar10);
            local_8 = CONCAT31(local_8._1_3_,5);
            iVar4 = FUN_00601ff0(&param_1,*DAT_00772440,FUN_005c7b70);
            if (iVar4 == 0) {
              if (piVar2 != (int *)0x0) {
                *piVar2 = *piVar2 + 1;
              }
              FUN_006bc6a0("class redefinition",piVar2);
              uVar10 = 1;
            }
            else {
              *(undefined1 *)(iVar4 + 0xcc3) = 1;
              *(undefined1 *)(iVar4 + 0xcc1) = 1;
              FUN_006b91c0(&param_1);
              DAT_00772440[1] = iVar4;
              FUN_00600740(iVar4,&local_14);
              *(undefined1 *)(iVar4 + 0xcc1) = 1;
              FUN_006b9200(&PTR_0071ce50);
              uVar10 = 0;
              DAT_00772440[1] = 0;
            }
            local_8._0_1_ = 7;
            if ((param_1 != (int *)0x0) && (*param_1 = *param_1 + -1, *param_1 == 0)) {
              FUN_006ba940();
            }
            FUN_006bad60();
            FUN_006bad60();
            goto LAB_0062e95a;
          }
          FUN_006bc8f0(2);
          goto LAB_0062e955;
        }
      }
      pcVar13 = "dont nest class definitions";
    }
    else {
      pcVar13 = "defclass only in top-level init script!";
    }
    FUN_006bc6a0(pcVar13,0);
  }
LAB_0062e955:
  uVar10 = 1;
LAB_0062e95a:
  FUN_006bc0d0();
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_2c != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

