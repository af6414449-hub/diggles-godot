
void CMap__Init(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  FILE *_File;
  int **ppiVar5;
  undefined4 *puVar6;
  int this;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  char *pcVar10;
  int *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007069d4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_14 = this;
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54d8) &&
     (FUN_006cebf4(&DAT_00ca54d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca54d8 == -1)) {
    iVar1 = DAT_00783650 * 0x40;
    DAT_00ca54dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar1) = "CMap::Init";
    *(int *)(&DAT_00773650 + iVar1) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54d8);
  }
  local_18 = (int *)(DAT_00ca54dc * 0x40);
  iVar2 = local_18[0x1dcd94];
  iVar1 = FUN_0043fcc0();
  piVar4 = local_18;
  *(int *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = iVar2;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar2 = local_18[0x1dcd95];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = piVar4[0x1dcd95];
    *(undefined8 *)(piVar4 + 0x1dcd96) = uVar9;
  }
  piVar4[0x1dcd95] = iVar2 + 1;
  local_8 = 0;
  CMap__Shut(1);
  if (this->i_24 != 0) goto LAB_00594481;
  uVar3 = FUN_004435d0(&local_18,"BlockDB");
  uVar3 = FUN_00443730(uVar3);
  local_8._0_1_ = 1;
  FUN_0055a950(uVar3,1);
  local_8._0_1_ = 2;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  piVar4 = (int *)FUN_006ba810(0x163);
  local_24 = piVar4;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4[2] = 0;
    piVar4[3] = 0;
    *piVar4 = -1;
    piVar4[1] = -1;
    piVar4[4] = 0;
    piVar4[5] = 0;
    piVar4[6] = 0;
    piVar4[7] = 0;
    local_20 = piVar4 + 10;
    *local_20 = 0;
    piVar4[0xb] = 0;
    piVar4[0xd] = 0;
    piVar4[0xe] = 0;
    piVar4[0xf] = 0;
    piVar4[0x10] = 0;
    local_8._0_1_ = 9;
    piVar4[0xc] = 0;
    FUN_00492060();
    DAT_00b836a4 = 0;
    DAT_00b836a8 = 0;
    piVar4[8] = 0;
  }
  local_8._0_1_ = 0;
  *(int **)(local_14 + 0x24) = piVar4;
  FUN_00565fb0();
  local_1c = DAT_0076838c;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 0x14;
  local_24[2] = -1;
  *local_24 = 0;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[3] = 0x61746164;
  local_24[4] = 0x6f6c425c;
  local_24[5] = 0x42446b63;
  local_24[6] = 0x44422e32;
  *(undefined2 *)(local_24 + 7) = 0x42;
  local_24[2] = 0x11;
  *local_24 = 2;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_20 = local_24;
  local_18 = local_24;
  if (local_1c == 0) {
    pcVar10 = "data\\BlockDB0.BDB";
LAB_005943c4:
    FUN_006b9200(pcVar10);
  }
  else {
    if (local_1c == 1) {
      pcVar10 = "data\\BlockDB1.BDB";
      goto LAB_005943c4;
    }
    if (local_1c == 2) {
      pcVar10 = "data\\BlockDB2.BDB";
      goto LAB_005943c4;
    }
  }
  piVar4 = local_18;
  _File = _fopen((char *)(local_18 + 3),"rb");
  if (_File == (FILE *)0x0) {
    ppiVar5 = &local_20;
  }
  else {
    _fclose(_File);
    ppiVar5 = &local_18;
  }
  FUN_00565ab0(ppiVar5);
  local_8._0_1_ = 0xc;
  if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd;
  *local_24 = *local_24 + -1;
  if (*local_24 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0;
  uVar3 = FUN_004435d0(&local_24,"BlockDB done");
  uVar3 = FUN_00443730(uVar3);
  local_8._0_1_ = 0xe;
  FUN_0055a950(uVar3,1);
  local_8._0_1_ = 0xf;
  if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  this = local_14;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
    this = local_14;
  }
LAB_00594481:
  this->i_48 = param_2;
  this->i_44 = param_1;
  this->i_7c = (int)param_3 * 8;
  this->i_80 = param_4 * 8;
  *(int **)(this + 0x74) = param_3;
  this->i_78 = param_4;
  this->i_4c = param_1 * param_2;
  uVar3 = FUN_004435d0(&param_3,"Map PosHash");
  uVar3 = FUN_00443730(uVar3);
  local_8._0_1_ = 0x10;
  FUN_0055a950(uVar3,1);
  local_8._0_1_ = 0x11;
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  FUN_005641c0(this->i_44,this->i_48);
  param_3 = *(int **)(this + 0x44);
  iVar2 = (int)param_3 * 8;
  *(int *)(local_14 + 0x38) = iVar2;
  iVar1 = *(int *)(local_14 + 0x48) * 8;
  *(int *)(local_14 + 0x3c) = iVar1;
  *(int *)(local_14 + 0x40) = iVar1 * iVar2;
  iVar7 = 0;
  *(int *)(local_14 + 0x84) = *(int *)(local_14 + 0x74);
  *(undefined4 *)(local_14 + 0x88) = *(undefined4 *)(local_14 + 0x78);
  *(int *)(local_14 + 0x8c) = (int)param_3 + *(int *)(local_14 + 0x74);
  *(int *)(local_14 + 0x90) = *(int *)(local_14 + 0x48) + *(int *)(local_14 + 0x78);
  *(int *)(local_14 + 0x94) = *(int *)(local_14 + 0x7c);
  *(int *)(local_14 + 0x98) = *(int *)(local_14 + 0x80);
  *(int *)(local_14 + 0x9c) = iVar2 + *(int *)(local_14 + 0x7c);
  *(int *)(local_14 + 0xa0) = iVar1 + *(int *)(local_14 + 0x80);
  *(float *)(local_14 + 0xa4) = (float)*(int *)(local_14 + 0x84);
  *(int *)(local_14 + 0x70) = *(int *)(local_14 + 0x78) * (int)param_3 + *(int *)(local_14 + 0x74);
  iVar2 = DAT_0076a338;
  *(float *)(local_14 + 0xa8) = (float)*(int *)(local_14 + 0x88);
  *(float *)(local_14 + 0xac) = (float)*(int *)(local_14 + 0x8c);
  *(float *)(local_14 + 0xb0) = (float)*(int *)(local_14 + 0x90);
  *(float *)(local_14 + 0xb4) = (float)*(int *)(local_14 + 0x94);
  *(float *)(local_14 + 0xb8) = (float)*(int *)(local_14 + 0x98);
  *(float *)(local_14 + 0xbc) = (float)*(int *)(local_14 + 0x9c);
  *(float *)(local_14 + 0xc0) = (float)*(int *)(local_14 + 0xa0);
  *(undefined1 *)(iVar2 + 0x3bac) = 1;
  if (0 < *(int *)(iVar2 + 0x3ba4)) {
    param_3 = (int *)0x0;
    do {
      if ((iVar7 < 0) || (*(int *)(iVar2 + 0x3ba0) <= iVar7)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = *(undefined4 **)(iVar2 + 0x3b9c);
      }
      else {
        puVar6 = (undefined4 *)(*(int *)(iVar2 + 0x3b9c) + (int)param_3);
      }
      iVar7 = iVar7 + 1;
      *puVar6 = 0xffffffff;
      param_3 = param_3 + 7;
    } while (iVar7 < *(int *)(iVar2 + 0x3ba4));
  }
  iVar2 = local_14;
  uVar3 = FUN_004435d0(&param_3,"Map VMem");
  uVar3 = FUN_00443730(uVar3);
  local_8._0_1_ = 0x12;
  FUN_0055a950(uVar3,1);
  local_8._0_1_ = 0x13;
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  uVar3 = FUN_006c4e10(*(int *)(iVar2 + 0x4c) * 0x7c);
  *(undefined4 *)(iVar2 + 0x14) = uVar3;
  *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x4c);
  iVar1 = *(int *)(iVar2 + 0x4c) * 0x7c;
  uVar3 = 0;
  FUN_004459b0(iVar1,0);
  FUN_00445770(iVar1,uVar3);
  iVar1 = DAT_0076a324;
  *(undefined2 *)(iVar2 + 0x29) = 0x100;
  DAT_007683d8 = 0xffffd8f0;
  *(undefined4 *)(iVar1 + 0x4410) = 0xffffd8f0;
  FUN_0059a320();
  FUN_005a9090();
  FUN_005a7c90();
  param_3 = (int *)FUN_005a3dd0();
  uVar8 = 0;
  param_4 = (int)param_3;
  do {
    if (0xc < uVar8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_0049c5f0(0);
    uVar8 = uVar8 + 1;
    param_3 = (int *)((int)param_3 + 0xc);
  } while ((int)uVar8 < 0xd);
  uVar8 = 0;
  iVar2 = *(int *)(local_14 + 0x20);
  param_4 = 0;
  param_3 = (int *)0x0;
  *(undefined1 *)(iVar2 + 8) = 1;
  do {
    if (uVar8 < 8) {
      *(undefined4 *)((int)param_3 + 0xc + iVar2) = 0xffffffff;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_00581330(0);
    param_3 = (int *)((int)param_3 + 4);
    uVar8 = uVar8 + 1;
    param_4 = param_4 + 8;
  } while ((int)uVar8 < 8);
  FUN_004455c0(1);
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

