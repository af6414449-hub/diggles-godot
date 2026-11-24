
undefined4
CTclGlobalMethods__Def_Class(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined **ppuVar10;
  undefined4 uVar11;
  bool bVar12;
  undefined8 uVar13;
  int local_3c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ca4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6df8) {
    FUN_006cebf4(&DAT_00ca6df8,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar5 = DAT_00783650;
    if (DAT_00ca6df8 == -1) {
      iVar9 = DAT_00783650 * 0x40;
      DAT_00ca6dfc = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::Def_Class()";
      *(int *)(&DAT_00773650 + iVar9) = iVar5;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6df8);
    }
  }
  iVar9 = DAT_00ca6dfc;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6dfc * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar11;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar5 == 0) {
    uVar13 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  iVar5 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if (param_1 == (int *)0x0) {
    FUN_006bc6a0("Fatal Error: no ClientData !",0);
    uVar11 = 1;
  }
  else if (param_1 == *(int **)(DAT_0077244c + 0xd4)) {
    if (DAT_00772440[1] == 0) {
      ppuVar10 = &PTR_0071ce50;
      pbVar6 = (byte *)(DAT_00772440[2] + 0xc);
      do {
        bVar1 = *pbVar6;
        bVar12 = bVar1 < *(byte *)ppuVar10;
        if (bVar1 != *(byte *)ppuVar10) {
LAB_0062ecc1:
          uVar7 = -(uint)bVar12 | 1;
          goto LAB_0062ecc6;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar12 = bVar1 < *(byte *)((int)ppuVar10 + 1);
        if (bVar1 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0062ecc1;
        pbVar6 = pbVar6 + 2;
        ppuVar10 = (undefined **)((int)ppuVar10 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_0062ecc6:
      if (uVar7 == 0) {
        if (iVar5 == 7) {
          puVar8 = (undefined4 *)FUN_004295e0(1);
          piVar2 = (int *)*puVar8;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          puVar8 = (undefined4 *)FUN_004295e0(2);
          piVar3 = (int *)*puVar8;
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + 1;
          }
          puVar8 = (undefined4 *)FUN_004295e0(3);
          piVar3 = (int *)*puVar8;
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + 1;
          }
          puVar8 = (undefined4 *)FUN_004295e0(4);
          piVar3 = (int *)*puVar8;
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + 1;
          }
          puVar8 = (undefined4 *)FUN_004295e0(5);
          piVar3 = (int *)*puVar8;
          if (piVar3 != (int *)0x0) {
            *piVar3 = *piVar3 + 1;
          }
          puVar8 = (undefined4 *)FUN_004295e0(6);
          local_18 = (int *)*puVar8;
          if (local_18 != (int *)0x0) {
            *local_18 = *local_18 + 1;
          }
          local_8._0_1_ = 8;
          uVar11 = FUN_006bafc0();
          FUN_006b8fb0(uVar11);
          local_8._0_1_ = 9;
          iVar5 = FUN_00601ff0(&param_1,*DAT_00772440,FUN_005c7b70);
          if (iVar5 == 0) {
            if (piVar2 != (int *)0x0) {
              *piVar2 = *piVar2 + 1;
            }
            FUN_006bc6a0("class redefinition",piVar2);
            uVar11 = 1;
          }
          else {
            *(undefined1 *)(iVar5 + 0xcc3) = 1;
            uVar11 = FUN_006bafc0();
            FUN_006b8fb0(uVar11);
            uVar11 = FUN_005fffe0();
            *(undefined4 *)(iVar5 + 0x54) = uVar11;
            local_8._0_1_ = 0xb;
            if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 9;
            uVar11 = FUN_006bafc0();
            FUN_006b8fb0(uVar11);
            uVar11 = FUN_00600190();
            *(undefined4 *)(iVar5 + 0x58) = uVar11;
            local_8._0_1_ = 0xc;
            if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 9;
            uVar11 = FUN_006bafc0();
            FUN_006b8fb0(uVar11);
            local_8._0_1_ = 0xd;
            uVar11 = FUN_00600480();
            *(undefined4 *)(iVar5 + 0x5c) = uVar11;
            local_8._0_1_ = 0xe;
            if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 9;
            uVar11 = FUN_006baee0();
            *(undefined4 *)(iVar5 + 0x60) = uVar11;
            FUN_006b91c0(&param_1);
            DAT_00772440[1] = iVar5;
            FUN_00600740(iVar5,&local_18);
            cVar4 = FUN_006b9930();
            if (cVar4 != '\0') {
              DAT_00772454 = iVar5;
            }
            FUN_006b9200(&PTR_0071ce50);
            uVar11 = 0;
            DAT_00772440[1] = 0;
          }
          local_8._0_1_ = 0xf;
          if ((param_1 != (int *)0x0) && (*param_1 = *param_1 + -1, *param_1 == 0)) {
            FUN_006ba940();
          }
          FUN_006bad60();
          FUN_006bad60();
          FUN_006bad60();
          FUN_006bad60();
          FUN_006bad60();
          FUN_006bad60();
        }
        else {
          FUN_006bc8f0(6);
          uVar11 = 1;
        }
        goto LAB_0062ef40;
      }
    }
    FUN_006bc6a0("dont nest class definitions",0);
    uVar11 = 1;
  }
  else {
    FUN_006bc6a0("defclass only in top-level init script!",0);
    uVar11 = 1;
  }
LAB_0062ef40:
  local_8._0_1_ = 0x10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_004297b0(0);
  if (local_3c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

