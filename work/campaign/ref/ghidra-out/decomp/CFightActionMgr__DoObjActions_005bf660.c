
undefined4 *
CFightActionMgr__DoObjActions
          (undefined4 *param_1,int *param_2,int *param_3,undefined4 *param_4,int *param_5,
          int *param_6)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  code *pcVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  uint uVar12;
  float *pfVar13;
  undefined4 uVar14;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int *piVar15;
  char *pcVar16;
  int iVar17;
  bool bVar18;
  int *piVar19;
  double dVar20;
  float fVar21;
  undefined8 uVar22;
  int **ppiVar23;
  int local_124;
  int *local_118;
  int local_114;
  int *local_a4;
  float local_a0;
  float local_9c;
  int *local_98;
  int *local_94;
  float local_90;
  int *local_8c;
  int *local_88;
  int *local_84;
  float local_80;
  float local_7c;
  int *local_78;
  float local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  float local_64;
  undefined8 local_60;
  code *local_58;
  uint local_54;
  int *local_50;
  int *local_4c;
  uint local_48;
  char local_41;
  int *local_40;
  int *local_3c;
  uint local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  char local_1d;
  code *local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00707e14;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca65e0) &&
     (FUN_006cebf4(), iVar7 = DAT_00783650, DAT_00ca65e0 == -1)) {
    iVar17 = DAT_00783650 * 0x40;
    DAT_00ca65e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar17) = "TCL:CFightActionMgr::DoObjActions()";
    *(int *)(&DAT_00773650 + iVar17) = iVar7;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar17 = DAT_00ca65e4;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca65e4 * 0x40);
  iVar7 = FUN_0043fcc0();
  *(undefined4 *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = uVar14;
  *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
  iVar7 = (&DAT_00773654)[iVar17 * 0x10];
  if (iVar7 == 0) {
    uVar22 = FUN_006bd180();
    iVar7 = (&DAT_00773654)[iVar17 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar17 * 0x10) = uVar22;
  }
  piVar9 = param_3;
  (&DAT_00773654)[iVar17 * 0x10] = iVar7 + 1;
  local_24 = param_3;
  local_2c = (int *)0x0;
  local_8 = 1;
  piVar8 = (int *)Tcl_NewListObj(0);
  local_1c = TclFreeObj_exref;
  if ((piVar8 != (int *)0x0) && (iVar7 = *piVar8, *piVar8 = iVar7, iVar7 < 1)) {
    TclFreeObj();
  }
  piVar8 = param_2;
  uVar5 = FUN_005bf200();
  param_3 = (int *)CONCAT13(uVar5,param_3._0_3_);
  local_41 = FUN_005bf200();
  local_9c = (float)piVar8[3];
  local_34 = (int *)piVar8[4];
  local_a0 = (float)piVar8[5];
  local_11 = '\0';
  FUN_005c37b0();
  fVar21 = (local_a0 - (float)local_78) * 0.5;
  fVar21 = (local_9c - local_80) * (local_9c - local_80) +
           ((float)local_34 - local_7c) * ((float)local_34 - local_7c) + fVar21 * fVar21;
  FUN_0040b7e0();
  local_90 = fVar21;
  FUN_005c3620();
  local_74 = fVar21;
  FUN_005c3620();
  uVar12 = local_38;
  iVar7 = piVar9[0x3a];
  if (local_74 <= fVar21) {
    local_74 = fVar21;
  }
  local_38 = local_38 & 0xffffff00;
  local_74 = local_74 + 0.2;
  if ((((iVar7 == 5) || (iVar7 == 7)) || (iVar7 == 6)) || ((iVar7 == 10 || (iVar7 == 8)))) {
    local_38._1_3_ = SUB43(uVar12,1);
    local_38 = CONCAT31(local_38._1_3_,1);
  }
  FUN_005dae40();
  if (fVar21 < 0.01) {
    piVar8 = (int *)Tcl_NewStringObj(0xa8);
    *piVar8 = *piVar8 + 1;
    param_6 = piVar8;
    FUN_006bb930();
    *piVar8 = *piVar8 + -1;
    if (*piVar8 < 1) {
      (*local_1c)();
    }
    if ((char)local_38 != '\0') {
      piVar8 = (int *)Tcl_NewStringObj(0xbc);
      *piVar8 = *piVar8 + 1;
      param_6 = piVar8;
      FUN_006bb930();
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        (*local_1c)();
      }
    }
    if (((piVar9[0x3a] == 1) && (piVar9[0xdb] == *(int *)(DAT_00772400 + 100))) &&
       (-1 < piVar9[0x102])) {
      iVar7 = FUN_00501450();
      if ((*(int *)(iVar7 + 0x8194) != 0) && (*(int *)(*(int *)(iVar7 + 0x8194) + 0xdc) != 0)) {
        FUN_0051a1c0();
      }
    }
    *param_1 = local_2c;
    if ((local_2c != (int *)0x0) && (iVar7 = *local_2c, *local_2c = iVar7, iVar7 < 1)) {
      (*local_1c)();
    }
LAB_005bf90d:
    FUN_0043fd30();
    ExceptionList = local_10;
    return param_1;
  }
  local_8c = piVar8 + 0x87;
  FUN_005dae40();
  if (param_3._3_1_ != '\0') {
    FUN_005daf50();
    fVar21 = 0.0;
  }
  local_84 = (int *)(1.0 - (fVar21 + 1.0) * 0.1);
  iVar7 = _rand();
  if (((((char)param_6 == '\0') && (param_3._3_1_ == '\0')) && (local_90 <= local_74 + 0.09)) &&
     (((char)local_38 == '\0' && ((float)local_84 < (float)iVar7 * 3.0517578e-05)))) {
    piVar9 = (int *)Tcl_NewStringObj(0xd8);
    *piVar9 = *piVar9 + 1;
    param_6 = piVar9;
    FUN_006bb930();
    pcVar4 = local_1c;
    *piVar9 = *piVar9 + -1;
    if (*piVar9 < 1) {
      (*local_1c)();
    }
    FUN_005daff0();
    *param_1 = local_2c;
    if ((local_2c != (int *)0x0) && (iVar7 = *local_2c, *local_2c = iVar7, iVar7 < 1)) {
      (*pcVar4)();
    }
    goto LAB_005bf90d;
  }
  ppiVar23 = &local_a4;
  uVar5 = 0xb0;
  FUN_006b90d0(ppiVar23,0xb0);
  local_8._0_1_ = 2;
  local_1d = FUN_005bf300(&local_24,piVar8,ppiVar23,uVar5);
  local_28 = local_24;
  local_84 = local_a4;
  local_58 = Tcl_NewStringObj_exref;
  if (local_11 != '\0') {
    FUN_006b90d0(&local_6c,0xb0);
    local_8._0_1_ = 3;
    if (*param_5 != 0) {
      Tcl_GetStringFromObj((char)*param_5);
    }
    FUN_006b8fb0();
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_006ba000((char)local_a4 + '\f');
    piVar9 = local_24;
    if (local_24 + 3 == (int *)0x0) {
      piVar15 = (int *)0x0;
      piVar8 = (int *)*param_5;
      *param_5 = 0;
    }
    else {
      piVar15 = (int *)Tcl_NewStringObj((char)(local_24 + 3));
      *piVar15 = *piVar15 + 1;
      piVar8 = (int *)*param_5;
      *param_5 = (int)piVar15;
      if (piVar15 != (int *)0x0) {
        *piVar15 = *piVar15 + 1;
      }
    }
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      (*local_1c)();
    }
    if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 < 1)) {
      (*local_1c)();
    }
    iVar7 = local_28[0x3a];
    if ((((iVar7 == 5) || (iVar7 == 7)) || (iVar7 == 6)) || ((iVar7 == 10 || (iVar7 == 8)))) {
      local_38 = CONCAT31(local_38._1_3_,1);
    }
    local_8._0_1_ = 5;
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 6;
    if ((local_6c != (int *)0x0) && (*local_6c = *local_6c + -1, *local_6c == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 2;
  }
  piVar9 = local_84;
  if ((char)local_38 != '\0') {
    piVar8 = (int *)(*local_58)(0xbc);
    *piVar8 = *piVar8 + 1;
    local_50 = piVar8;
    FUN_006bb930();
    *piVar8 = *piVar8 + -1;
    if (*piVar8 < 1) {
      (*local_1c)();
    }
  }
  fVar21 = local_74 + 0.09;
  if (fVar21 < local_90) {
    fVar21 = 2.0;
    if (2.0 <= local_74) {
      fVar21 = local_74;
    }
    if (((fVar21 <= local_90) || (param_3._3_1_ != '\0')) || ((char)param_6 != '\0')) {
      piVar8 = (int *)(*local_58)(0xf0);
      *piVar8 = *piVar8 + 1;
      param_6 = piVar8;
      FUN_006bb930();
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        (*local_1c)();
      }
    }
    else {
      piVar8 = (int *)FUN_006b90d0(&param_2,"reapproach %f",SUB81((double)local_74,0));
      if (*piVar8 + 0xc == 0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)(*local_58)((char)(*piVar8 + 0xc));
        *piVar8 = *piVar8 + 1;
      }
      param_6 = piVar8;
      FUN_006bb930();
      if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
        (*local_1c)();
      }
      local_8._0_1_ = 7;
      if ((param_2 != (int *)0x0) && (*param_2 = *param_2 + -1, *param_2 == 0)) {
        FUN_006ba940();
      }
    }
    piVar8 = local_2c;
    *param_1 = local_2c;
    if (local_2c != (int *)0x0) {
      *local_2c = *local_2c + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,8);
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
      FUN_006ba940();
    }
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      (*local_1c)();
    }
    goto LAB_005c0e6e;
  }
  local_64 = local_9c - local_80;
  local_60 = CONCAT44(local_a0 * 0.5 - (float)local_78 * 0.5,(float)local_34 - local_7c);
  FUN_00410940();
  local_50 = (int *)(fVar21 + 1.5707964);
  piVar8 = (int *)param_2[0x11];
  local_4c = piVar8;
  FUN_00423b40();
  piVar15 = local_28;
  local_50 = piVar8;
  local_4c = (int *)FUN_005bf080((char)param_2);
  local_70 = (int *)FUN_005bf080((char)piVar15);
  local_24 = (int *)((uint)local_70 & 0xffffff00);
  dVar20 = ABS((double)(float)local_50);
  if (((0.26179938779916667 < dVar20) && (local_11 == '\0')) && (param_3._3_1_ == '\0')) {
    local_24 = (int *)(uint)((char)param_6 == '\0');
  }
  FUN_005beaf0(param_2,piVar15,&local_54,&local_48,&param_6,&local_30,local_4c,local_70,0xff);
  piVar8 = local_18;
  piVar19 = SUB84(dVar20,0);
  if (local_54 == 0) {
    if ((char)local_24 == '\0') {
      uVar5 = 0xd8;
    }
    else {
      uVar5 = 0;
    }
    piVar8 = (int *)(*local_58)(uVar5);
    *piVar8 = *piVar8 + 1;
    param_6 = piVar8;
    FUN_006bb930();
    *piVar8 = *piVar8 + -1;
    if (*piVar8 < 1) {
      (*local_1c)();
    }
    piVar8 = local_2c;
    *param_1 = local_2c;
    if (local_2c != (int *)0x0) {
      *local_2c = *local_2c + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,9);
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
      FUN_006ba940();
    }
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      (*local_1c)();
    }
    goto LAB_005c0e6e;
  }
  piVar9 = local_18 + 2;
  local_4c = (int *)0x0;
  local_34 = (int *)0x0;
  local_40 = piVar9;
  if ((uint)local_18[3] <= param_6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_50 = (int *)((int)param_6 * 0x40);
  FUN_005dae40();
  local_98 = piVar19;
  FUN_005dae40();
  local_24 = (int *)0x0;
  local_3c = (int *)0x3f800000;
  local_94 = piVar19;
  if ((uint)piVar8[3] <= param_6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (-1 < *(int *)((int)local_50 + 0x30 + *piVar9)) {
    iVar7 = FUN_004e3d30((char)param_6);
    FUN_0058ef30((char)*(undefined4 *)(iVar7 + 0x30));
    cVar6 = FUN_005c4310();
    if (cVar6 != '\0') {
      FUN_004e3d30();
      iVar7 = FUN_004e3d30((char)param_6);
      FUN_0058ef30((char)*(undefined4 *)(iVar7 + 0x30));
      puVar10 = (undefined4 *)FUN_0040b900();
      local_3c = (int *)*puVar10;
    }
  }
  if ((int *)piVar8[3] <= local_30) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar7 = (int)local_30 * 0x40;
  if (-1 < *(int *)(iVar7 + 0x30 + *piVar9)) {
    iVar7 = FUN_004e3d30((char)local_30);
    FUN_0058ef30((char)*(undefined4 *)(iVar7 + 0x30));
    cVar6 = FUN_005c4310();
    iVar7 = extraout_ECX;
    if (cVar6 != '\0') {
      FUN_004e3d30();
      iVar7 = FUN_004e3d30(local_30._0_1_);
      FUN_0058ef30((char)*(undefined4 *)(iVar7 + 0x30));
      puVar10 = (undefined4 *)FUN_0040b900();
      local_3c = (int *)*puVar10;
      iVar7 = extraout_ECX_00;
    }
  }
  local_6c = (int *)((uint)local_6c & 0xffffff00);
  uVar5 = FUN_005bedd0(iVar7,piVar15,local_54,(char)local_48);
  local_50 = (int *)CONCAT31(local_50._1_3_,uVar5);
  uVar12 = local_18[1];
  if (uVar12 <= local_48) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    uVar12 = local_18[1];
  }
  iVar17 = *local_18;
  iVar7 = iVar17 + local_48 * 0x44;
  if (uVar12 <= local_54) {
    local_60._4_4_ = iVar7;
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar17 = *local_18;
    iVar7 = local_60._4_4_;
  }
  local_60 = CONCAT44(local_54 * 0x44,(undefined4)local_60);
  FUN_005bdab0(local_54 * 0x44 + iVar17,iVar7,local_94,&local_4c,&local_34,&param_6,&local_30,
               &local_24,(char)local_3c);
  local_30 = local_34;
  piVar9 = local_34;
  if (0.0 < (float)local_34) {
    uVar5 = FUN_005bebc0(param_2,piVar15,local_54,(char)local_48);
    local_6c = (int *)CONCAT31(local_6c._1_3_,uVar5);
    FUN_006b8f50();
    local_8 = CONCAT31(local_8._1_3_,10);
    piVar9 = SUB84((double)(float)local_24,0);
    FUN_006b9040(&local_3c,"ratio %f",SUB81((double)(float)local_24,0));
    piVar8 = local_3c;
    if (local_3c + 3 == (int *)0x0) {
      piVar15 = (int *)0x0;
    }
    else {
      piVar15 = (int *)(*local_58)((char)(local_3c + 3));
      *piVar15 = *piVar15 + 1;
    }
    local_24 = piVar15;
    FUN_006bb930();
    if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 < 1)) {
      (*local_1c)();
    }
    local_8._0_1_ = 0xb;
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 2;
    piVar15 = local_28;
  }
  FUN_005c46b0((char)*(undefined4 *)(piVar15[0x35] + 8));
  piVar8 = local_34;
  if ((float)piVar9 != 0.0) {
    piVar8 = (int *)((float)local_34 / (float)piVar9);
    local_30 = piVar8;
  }
  if ((char)local_38 != '\0') {
    local_30 = (int *)((float)piVar8 * 0.1);
  }
  local_24 = (int *)((uint)local_24 & 0xffffff00);
  FUN_005dae40();
  if ((float)piVar9 - (float)local_30 < 0.01) {
    local_30 = (int *)((float)piVar9 + 0.1);
    FUN_005bf040(extraout_ECX_01,piVar15,&local_54,(char)&local_48);
    local_24 = (int *)CONCAT31(local_24._1_3_,1);
  }
  if (local_1d == '\0') {
    param_6 = (int *)((uint)param_6 & 0xffffff);
  }
  else {
    iVar7 = FUN_004e3d30();
    local_40 = *(int **)(iVar7 + 0x10);
    FUN_004e3d30();
    FUN_005daff0();
    FUN_005c3190();
    FUN_004e3d30();
    FUN_005daff0();
    FUN_005c3190();
    param_6 = (int *)((uint)param_6 & 0xffffff);
    if (*(int *)(piVar15[0x35] + 0x54) == 1) {
      if (piVar15[0x80] != -1) {
        pcVar16 = "fight_dispatch";
        FUN_0045f6d0();
        pbVar11 = (byte *)FUN_006bafc0();
        do {
          bVar3 = *pbVar11;
          bVar18 = bVar3 < (byte)*pcVar16;
          if (bVar3 != *pcVar16) {
LAB_005c0302:
            uVar12 = -(uint)bVar18 | 1;
            goto LAB_005c0307;
          }
          if (bVar3 == 0) break;
          bVar3 = pbVar11[1];
          bVar18 = bVar3 < ((byte *)pcVar16)[1];
          if (bVar3 != ((byte *)pcVar16)[1]) goto LAB_005c0302;
          pbVar11 = pbVar11 + 2;
          pcVar16 = (char *)((byte *)pcVar16 + 2);
        } while (bVar3 != 0);
        uVar12 = 0;
LAB_005c0307:
        bVar18 = uVar12 == 0;
LAB_005c030c:
        param_6 = (int *)CONCAT13(bVar18,param_6._0_3_);
        piVar15 = local_28;
      }
    }
    else {
      iVar7 = FUN_006b9f40();
      if (iVar7 < 0) {
        param_6 = (int *)CONCAT13(1,param_6._0_3_);
        if (piVar15[0x80] != -1) {
          pcVar16 = "trapped";
          FUN_0045f6d0();
          pbVar11 = (byte *)FUN_006bafc0();
          do {
            bVar3 = *pbVar11;
            bVar18 = bVar3 < (byte)*pcVar16;
            if (bVar3 != *pcVar16) {
LAB_005c04f0:
              uVar12 = -(uint)bVar18 | 1;
              goto LAB_005c04f5;
            }
            if (bVar3 == 0) break;
            bVar3 = pbVar11[1];
            bVar18 = bVar3 < ((byte *)pcVar16)[1];
            if (bVar3 != ((byte *)pcVar16)[1]) goto LAB_005c04f0;
            pbVar11 = pbVar11 + 2;
            pcVar16 = (char *)((byte *)pcVar16 + 2);
          } while (bVar3 != 0);
          uVar12 = 0;
LAB_005c04f5:
          piVar15 = local_28;
          if (uVar12 == 0) {
            bVar18 = false;
            goto LAB_005c030c;
          }
        }
      }
    }
  }
  FUN_006b8fb0();
  local_8._0_1_ = 0xc;
  FUN_00405e10();
  local_8._0_1_ = 0xf;
  if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xe;
  local_3c = local_88;
  FUN_006b8fb0();
  local_8._0_1_ = 0x10;
  FUN_00405e10();
  local_8._0_1_ = 0x13;
  if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x12;
  uVar5 = (undefined1)local_8;
  local_8._0_1_ = 0x12;
  local_34 = (int *)0x0;
  local_11 = param_6._3_1_;
  piVar9 = (int *)0x0;
  if (param_6._3_1_ != '\0') {
    if ((((local_1d == '\0') || (FUN_005d0c20(), uVar5 = (undefined1)local_8, local_41 == '\0')) ||
        ((char)local_38 != '\0')) ||
       (cVar6 = FUN_004097b0((float)piVar15[3] + 0.0,SUB41((float)piVar15[4] + 0.25,0)),
       uVar5 = (undefined1)local_8, cVar6 == '\0')) {
      local_8._0_1_ = uVar5;
      local_34 = local_68;
      piVar9 = local_68;
      uVar5 = (undefined1)local_8;
    }
    else {
      FUN_006b8fb0();
      local_8._0_1_ = 0x14;
      FUN_00405e10();
      FUN_00409280();
      FUN_00406f00();
      local_8._0_1_ = 0x15;
      if ((param_6 != (int *)0x0) && (*param_6 = *param_6 + -1, *param_6 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x12;
      piVar8 = (int *)*param_5;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      (**(code **)(*local_68 + 8))(0,piVar15,piVar8,0);
      param_6 = (int *)((uint)param_6 & 0xffffff);
      uVar5 = (undefined1)local_8;
    }
  }
  local_8._0_1_ = uVar5;
  piVar8 = local_18;
  uVar12 = local_18[1];
  if (uVar12 <= local_54) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    uVar12 = piVar8[1];
  }
  iVar7 = *piVar8;
  iVar17 = local_60._4_4_ + iVar7;
  if (uVar12 <= local_54) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar7 = *local_18;
  }
  iVar17 = *(int *)(iVar17 + 0x1c);
  local_3c[0xb] = *(int *)(local_60._4_4_ + 0x18 + iVar7);
  local_3c[0xc] = iVar17;
  local_3c[7] = (int)piVar9;
  local_3c[8] = 0;
  local_3c[0xf] = (int)local_4c;
  *(undefined2 *)(local_3c + 0x12) = 0;
  *(bool *)((int)local_3c + 0x4a) = local_1d == '\0';
  *(undefined1 *)((int)local_3c + 0x51) = 0;
  FUN_006b8fb0();
  local_60 = 0x3fd3333340000000;
  FUN_006bad90();
  piVar8 = local_70;
  piVar9 = local_98;
  local_4c = local_70;
  if (local_70 != (int *)0x0) {
    *local_70 = *local_70 + 1;
  }
  local_94 = local_98;
  local_40 = local_98;
  if (local_98 != (int *)0x0) {
    *local_98 = *local_98 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,0x19);
  piVar15 = (int *)local_3c[9];
  local_3c[9] = (int)local_98;
  if (local_98 != (int *)0x0) {
    *local_98 = *local_98 + 1;
  }
  if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
    FUN_006ba940();
  }
  *(int *)(local_3c[9] + 8) = piVar9[2];
  piVar15 = (int *)local_3c[10];
  local_3c[10] = (int)piVar8;
  if (piVar8 != (int *)0x0) {
    *piVar8 = *piVar8 + 1;
  }
  if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 < 1)) {
    (*local_1c)();
  }
  local_8._0_1_ = 0x1a;
  *piVar9 = *piVar9 + -1;
  if (*piVar9 == 0) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x17);
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*local_1c)();
  }
  FUN_005bdf80(param_2,(char)local_3c);
  param_2[0x82] = 0;
  param_2[0xf7] = 0;
  piVar9 = (int *)*param_4;
  if (piVar9 != (int *)0x0) {
    *piVar9 = *piVar9 + 1;
  }
  (**(code **)(*local_88 + 8))(0,param_2,piVar9,0);
  FUN_005d0c20();
  puVar10 = (undefined4 *)param_2[0xfe];
  param_2[0xfe] = (int)local_88;
  if (local_88 != (int *)0x0) {
    LOCK();
    local_88[1] = local_88[1] + 1;
    UNLOCK();
  }
  if (puVar10 != (undefined4 *)0x0) {
    LOCK();
    iVar7 = puVar10[1] + -1;
    puVar10[1] = iVar7;
    UNLOCK();
    if (iVar7 == 0) {
      (**(code **)*puVar10)();
    }
  }
  FUN_005daff0();
  if ((((char)local_38 == '\0') && (0.01 <= (float)local_30)) && (local_1d != '\0')) {
    FUN_005daff0();
  }
  if (param_6._3_1_ == '\0') {
    FUN_006b8f50();
    local_8._0_1_ = 0x1b;
    FUN_006b9040(&param_6,
                 "set_event %i evt_fight_get_hurt -target %i -delay %f -num1 %f -subject1 %i",
                 local_28[0x37],local_28[0x37],(int)local_60,(int)((ulonglong)local_60 >> 0x20),
                 SUB84((double)((float)local_30 * 0.6),0),
                 (char)((ulonglong)(double)((float)local_30 * 0.6) >> 0x20));
    piVar9 = param_6;
    if (param_6 != (int *)0x0) {
      *param_6 = *param_6 + 1;
    }
    FUN_0054ea20();
    local_8._0_1_ = 0x1c;
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,0x17);
    piVar15 = local_28;
  }
  else {
    param_6 = (int *)CONCAT13(local_28[0xde] != *(int *)(DAT_00772400 + 100),param_6._0_3_);
    iVar7 = FUN_005c63c0();
    iVar7 = *(int *)(iVar7 + 0x1c);
    iVar17 = FUN_005c63c0();
    uVar5 = (undefined1)local_38;
    local_34[0xb] = *(int *)(iVar17 + 0x18);
    *(undefined1 *)(local_34 + 0x12) = local_6c._0_1_;
    *(char *)((int)local_34 + 0x4a) = param_6._3_1_;
    *(undefined1 *)((int)local_34 + 0x51) = uVar5;
    *(undefined1 *)((int)local_34 + 0x49) = local_50._0_1_;
    local_34[7] = 0;
    local_34[8] = (int)local_3c;
    local_34[0xc] = iVar7;
    local_34[0xf] = (int)local_30;
    *(char *)((int)local_34 + 0x53) = (char)local_24;
    piVar9 = local_30;
    piVar19 = local_6c;
    iVar7 = FUN_005c63c0(local_48);
    uVar14 = *(undefined4 *)(iVar7 + 0x1c);
    iVar7 = FUN_005c63c0(local_48);
    piVar15 = local_28;
    FUN_005c6050(param_2[0x37],local_28[0x37],*(undefined4 *)(iVar7 + 0x18),uVar14,piVar9,piVar19,
                 uVar5);
    FUN_005bdf80(piVar15,(char)local_34);
    piVar15[0x82] = 0;
    piVar15[0xf7] = 0;
    piVar9 = (int *)*param_5;
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    (**(code **)(*local_68 + 8))(0,piVar15,piVar9,0);
    iVar7 = FUN_006b9f40();
    if (iVar7 == -1) {
      if (((param_3._3_1_ == '\0') && (local_41 == '\0')) && (local_90 < local_74 - 0.3)) {
        local_64 = local_80 - local_9c;
        local_60 = (ulonglong)(uint)((float)local_78 - local_a0) << 0x20;
        cVar6 = FUN_004094a0();
        if (cVar6 == '\0') {
          iVar7 = param_2[0x11];
          FUN_004089f0();
          local_60 = CONCAT44(iVar7,(undefined4)local_60);
          fVar21 = (float)param_2[0x11];
          FUN_004089d0();
          local_64 = fVar21;
        }
        pfVar13 = (float *)FUN_0040b810();
        param_5 = (int *)(*pfVar13 * 0.03125);
        param_3 = (int *)(pfVar13[2] * 0.03125);
        local_80 = local_80 + (float)param_5 * 4.0;
        local_7c = local_7c + 0.0;
        param_6 = (int *)((float)local_78 + (float)param_3 * 4.0);
        local_78 = param_6;
        cVar6 = FUN_005bf200();
        if ((cVar6 == '\0') && ((float)param_6 < 15.0)) {
          local_34[0x15] = (int)param_5;
          local_34[0x16] = 0;
          local_34[0x17] = (int)param_3;
          local_34[0x18] = 0;
          local_34[0x19] = 4;
        }
      }
    }
    else {
      *(double *)(local_34 + 0x10) = *(double *)(DAT_00772400 + 0xa088) + 0.6;
      *(undefined1 *)((int)local_34 + 0x52) = 1;
    }
  }
  if (local_11 != '\0') {
    FUN_00409280();
  }
  if ((((char)local_38 == '\0') && (piVar15[0xdb] == *(int *)(DAT_00772400 + 100))) &&
     (piVar15[0x102] == -2)) {
    param_6 = (int *)0xff;
    if (-1 < param_2[0xdb]) {
      param_6 = (int *)(~(1 << (param_2[0xdb] & 0x1fU)) & 0xffU | 0x10000);
    }
    FUN_005ddd60();
    local_8._0_1_ = 0x1d;
    iVar7 = FUN_005de0c0((char)piVar15);
    uVar12 = *(uint *)(iVar7 + 0x1c);
    *(undefined4 *)(iVar7 + 0x34) = 1;
    if (uVar12 == 0xffffffff) {
      uVar12 = 0;
    }
    *(uint *)(iVar7 + 0x1c) = (uint)param_6 | uVar12;
    cVar6 = '\x01';
    fVar21 = (float)piVar15[4];
    fVar1 = (float)piVar15[5];
    *(float *)(iVar7 + 0x54) = (float)piVar15[3] - 20.0;
    *(float *)(iVar7 + 0x58) = fVar21 - 20.0;
    *(float *)(iVar7 + 0x5c) = fVar1 - 20.0;
    fVar21 = (float)piVar15[3];
    fVar1 = (float)piVar15[4];
    fVar2 = (float)piVar15[5];
    *(undefined4 *)(iVar7 + 8) = 0x43c80000;
    *(float *)(iVar7 + 0x60) = fVar21 + 20.0;
    *(float *)(iVar7 + 100) = fVar1 + 20.0;
    *(float *)(iVar7 + 0x68) = fVar2 + 20.0;
    do {
      param_6 = (int *)CONCAT13(cVar6,param_6._0_3_);
      do {
        if (local_124 == -2) {
          FUN_005e12a0();
          cVar6 = param_6._3_1_;
        }
        iVar7 = DAT_00772400;
        local_124 = local_124 + 1;
        if (local_114 <= local_124) {
          if (cVar6 != '\0') {
            if ((*(double *)(DAT_00772400 + 0xa090) != 1.0) &&
               (*(undefined8 *)(DAT_00772400 + 0xa090) = 0x3ff0000000000000,
               *(char *)(iVar7 + 0xa098) != '\0')) {
              *(undefined1 *)(iVar7 + 0xa098) = 1;
            }
            iVar7 = FUN_00501450();
            if ((*(int *)(iVar7 + 0x8194) != 0) &&
               (param_2 = *(int **)(*(int *)(iVar7 + 0x8194) + 0xdc), param_2 != (int *)0x0)) {
              uVar14 = FUN_004435d0((char)&param_5);
              piVar9 = (int *)FUN_00443730(uVar14);
              local_8._0_1_ = 0x1e;
              param_6 = (int *)FUN_00519ea0(*piVar9 + 0xc,0xff);
              local_8._0_1_ = 0x1f;
              if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 == 0)) {
                FUN_006ba940();
              }
              local_8._0_1_ = 0x1d;
              FUN_0051a340((char)param_6);
              FUN_006b8f50();
              local_8 = CONCAT31(local_8._1_3_,0x20);
              FUN_006b9040(&param_5,"newsticker delete %d; set_view %.2f %.2f 0 -0.35 0",param_6,
                           (double)(float)piVar15[3],SUB81((double)((float)piVar15[4] - 1.0),0));
              piVar9 = param_5;
              param_3 = (int *)&stack0xfffffec0;
              puVar10 = (undefined4 *)&stack0xfffffec0;
              if (param_5 + 3 != (int *)0x0) {
                piVar15 = (int *)(*local_58)(param_5 + 3,0xff);
                *param_3 = (int)piVar15;
                *piVar15 = *piVar15 + 1;
                puVar10 = param_3;
              }
              param_3 = puVar10;
              FUN_0051a3a0((char)param_6);
              local_28[0x102] = (int)param_6;
              local_8._0_1_ = 0x21;
              if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
                FUN_006ba940();
              }
            }
          }
          local_8 = CONCAT31(local_8._1_3_,0x17);
          FUN_005ddfc0();
          goto LAB_005c0d5d;
        }
        if ((local_124 < 0) || (local_114 <= local_124)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar9 = local_118;
        }
        else {
          piVar9 = local_118 + local_124;
        }
        cVar6 = param_6._3_1_;
      } while (*(int *)(*piVar9 + 0x408) == -2);
      piVar15[0x102] = -1;
      cVar6 = '\0';
    } while( true );
  }
LAB_005c0d5d:
  FUN_006b8f50();
  local_8 = CONCAT31(local_8._1_3_,0x22);
  FUN_006b9040(&param_6,0xdc);
  if (param_6 + 3 == (int *)0x0) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)(*local_58)((char)(param_6 + 3));
    *piVar9 = *piVar9 + 1;
  }
  param_2 = piVar9;
  FUN_006bb930();
  if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
    (*local_1c)();
  }
  local_8 = CONCAT31(local_8._1_3_,0x23);
  if ((param_6 != (int *)0x0) && (*param_6 = *param_6 + -1, *param_6 == 0)) {
    FUN_006ba940();
  }
  pcVar4 = local_1c;
  piVar9 = local_2c;
  *param_1 = local_2c;
  if (local_2c != (int *)0x0) {
    *local_2c = *local_2c + 1;
  }
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*local_1c)();
  }
  local_8 = CONCAT31(local_8._1_3_,0x24);
  *local_94 = *local_94 + -1;
  if (*local_94 == 0) {
    FUN_006ba940();
  }
  if (local_68 != (int *)0x0) {
    LOCK();
    iVar7 = local_68[1] + -1;
    local_68[1] = iVar7;
    UNLOCK();
    if ((iVar7 == 0) && (local_68 != (int *)0x0)) {
      (**(code **)*local_68)();
    }
  }
  if (local_88 != (int *)0x0) {
    LOCK();
    piVar8 = local_88 + 1;
    iVar7 = *piVar8;
    *piVar8 = *piVar8 + -1;
    UNLOCK();
    if ((iVar7 == 1) && (local_88 != (int *)0x0)) {
      (**(code **)*local_88)();
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0x25);
  if ((local_84 != (int *)0x0) && (*local_84 = *local_84 + -1, *local_84 == 0)) {
    FUN_006ba940();
  }
  if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
    (*pcVar4)();
  }
LAB_005c0e6e:
  FUN_0043fd30();
  ExceptionList = local_10;
  return param_1;
}

