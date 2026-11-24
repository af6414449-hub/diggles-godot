
void __thiscall CMap__Init(CMap *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  CMap *pCVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  FILE *_File;
  int **ppiVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined8 uVar14;
  int in_stack_00000004;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int in_stack_00000010;
  char *pcVar15;
  int *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  CMap *local_14;
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
     (FUN_006cebf4(&DAT_00ca54d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar11 = DAT_00783650,
     DAT_00ca54d8 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca54dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "CMap::Init";
    *(int *)(&DAT_00773650 + iVar6) = iVar11;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54d8);
  }
  local_18 = (int *)(DAT_00ca54dc * 0x40);
  iVar11 = local_18[0x1dcd94];
  iVar6 = FUN_0043fcc0();
  piVar8 = local_18;
  *(int *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = iVar11;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar11 = local_18[0x1dcd95];
  if (iVar11 == 0) {
    uVar14 = FUN_006bd180();
    iVar11 = piVar8[0x1dcd95];
    *(undefined8 *)(piVar8 + 0x1dcd96) = uVar14;
  }
  piVar8[0x1dcd95] = iVar11 + 1;
  local_8 = 0;
  CMap__Shut(this);
  if (this->i_24 != 0) goto LAB_00594481;
  uVar7 = FUN_004435d0(&local_18,"BlockDB");
  uVar7 = FUN_00443730(uVar7);
  local_8._0_1_ = 1;
  FUN_0055a950(uVar7,1);
  local_8._0_1_ = 2;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  piVar8 = (int *)FUN_006ba810(0x163);
  local_24 = piVar8;
  if (piVar8 == (int *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8[2] = 0;
    piVar8[3] = 0;
    *piVar8 = -1;
    piVar8[1] = -1;
    piVar8[4] = 0;
    piVar8[5] = 0;
    piVar8[6] = 0;
    piVar8[7] = 0;
    local_20 = piVar8 + 10;
    *local_20 = 0;
    piVar8[0xb] = 0;
    piVar8[0xd] = 0;
    piVar8[0xe] = 0;
    piVar8[0xf] = 0;
    piVar8[0x10] = 0;
    local_8._0_1_ = 9;
    piVar8[0xc] = 0;
    FUN_00492060();
    DAT_00b836a4 = 0;
    DAT_00b836a8 = 0;
    piVar8[8] = 0;
  }
  local_8._0_1_ = 0;
  local_14->i_24 = (int)piVar8;
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
    pcVar15 = "data\\BlockDB0.BDB";
LAB_005943c4:
    FUN_006b9200(pcVar15);
  }
  else {
    if (local_1c == 1) {
      pcVar15 = "data\\BlockDB1.BDB";
      goto LAB_005943c4;
    }
    if (local_1c == 2) {
      pcVar15 = "data\\BlockDB2.BDB";
      goto LAB_005943c4;
    }
  }
  piVar8 = local_18;
  _File = _fopen((char *)(local_18 + 3),"rb");
  if (_File == (FILE *)0x0) {
    ppiVar9 = &local_20;
  }
  else {
    _fclose(_File);
    ppiVar9 = &local_18;
  }
  FUN_00565ab0(ppiVar9);
  local_8._0_1_ = 0xc;
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd;
  *local_24 = *local_24 + -1;
  if (*local_24 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0;
  uVar7 = FUN_004435d0(&local_24,"BlockDB done");
  uVar7 = FUN_00443730(uVar7);
  local_8._0_1_ = 0xe;
  FUN_0055a950(uVar7,1);
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
  this->i_48 = in_stack_00000008;
  this->i_44 = in_stack_00000004;
  this->i_7c = (int)in_stack_0000000c * 8;
  this->i_80 = in_stack_00000010 * 8;
  *(int **)&this->field_0x74 = in_stack_0000000c;
  this->i_78 = in_stack_00000010;
  this->i_4c = in_stack_00000004 * in_stack_00000008;
  uVar7 = FUN_004435d0(&stack0x0000000c,"Map PosHash");
  uVar7 = FUN_00443730(uVar7);
  local_8._0_1_ = 0x10;
  FUN_0055a950(uVar7,1);
  local_8._0_1_ = 0x11;
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  FUN_005641c0(this->i_44,this->i_48);
  in_stack_0000000c = (int *)this->i_44;
  iVar1 = local_14->i_48;
  iVar11 = (int)in_stack_0000000c * 8;
  *(int *)&local_14->field_0x38 = iVar11;
  iVar6 = iVar1 * 8;
  iVar2 = local_14->i_78;
  *(int *)&local_14->field_0x3c = iVar6;
  *(int *)&local_14->field_0x40 = iVar6 * iVar11;
  iVar3 = *(int *)&local_14->field_0x74;
  iVar4 = local_14->i_80;
  iVar12 = 0;
  *(int *)(local_14 + 1) = iVar3;
  *(int *)&local_14[1].field_0x4 = local_14->i_78;
  *(int *)&local_14[1].field_0x8 = (int)in_stack_0000000c + iVar3;
  *(int *)&local_14[1].field_0xc = iVar1 + iVar2;
  iVar1 = local_14->i_7c;
  iVar2 = local_14->i_78;
  *(int *)&local_14[1].field_0x10 = iVar1;
  *(int *)&local_14[1].field_0x14 = iVar4;
  *(int *)&local_14[1].field_0x18 = iVar11 + iVar1;
  *(int *)&local_14[1].field_0x1c = iVar6 + iVar4;
  *(float *)&local_14[1].field_0x20 = (float)*(int *)(local_14 + 1);
  iVar11 = *(int *)&local_14[1].field_0x4;
  *(int *)&local_14->field_0x70 = iVar2 * (int)in_stack_0000000c + *(int *)&local_14->field_0x74;
  iVar6 = DAT_0076a338;
  local_14[1].i_24 = (int)(float)iVar11;
  *(float *)&local_14[1].field_0x28 = (float)*(int *)&local_14[1].field_0x8;
  *(float *)&local_14[1].field_0x2c = (float)*(int *)&local_14[1].field_0xc;
  *(float *)&local_14[1].field_0x30 = (float)*(int *)&local_14[1].field_0x10;
  *(float *)&local_14[1].field_0x34 = (float)*(int *)&local_14[1].field_0x14;
  *(float *)&local_14[1].field_0x38 = (float)*(int *)&local_14[1].field_0x18;
  *(float *)&local_14[1].field_0x3c = (float)*(int *)&local_14[1].field_0x1c;
  *(undefined1 *)(iVar6 + 0x3bac) = 1;
  if (0 < *(int *)(iVar6 + 0x3ba4)) {
    in_stack_0000000c = (int *)0x0;
    do {
      if ((iVar12 < 0) || (*(int *)(iVar6 + 0x3ba0) <= iVar12)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = *(undefined4 **)(iVar6 + 0x3b9c);
      }
      else {
        puVar10 = (undefined4 *)(*(int *)(iVar6 + 0x3b9c) + (int)in_stack_0000000c);
      }
      iVar12 = iVar12 + 1;
      *puVar10 = 0xffffffff;
      in_stack_0000000c = in_stack_0000000c + 7;
    } while (iVar12 < *(int *)(iVar6 + 0x3ba4));
  }
  pCVar5 = local_14;
  uVar7 = FUN_004435d0(&stack0x0000000c,"Map VMem");
  uVar7 = FUN_00443730(uVar7);
  local_8._0_1_ = 0x12;
  FUN_0055a950(uVar7,1);
  local_8._0_1_ = 0x13;
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  uVar7 = FUN_006c4e10(pCVar5->i_4c * 0x7c);
  *(undefined4 *)&pCVar5->field_0x14 = uVar7;
  *(int *)&pCVar5->field_0x18 = pCVar5->i_4c;
  iVar11 = pCVar5->i_4c * 0x7c;
  uVar7 = 0;
  FUN_004459b0(iVar11,0);
  FUN_00445770(iVar11,uVar7);
  iVar11 = DAT_0076a324;
  *(undefined2 *)&pCVar5->field_0x29 = 0x100;
  DAT_007683d8 = 0xffffd8f0;
  *(undefined4 *)(iVar11 + 0x4410) = 0xffffd8f0;
  FUN_0059a320();
  FUN_005a9090();
  FUN_005a7c90();
  in_stack_0000000c = (int *)FUN_005a3dd0();
  uVar13 = 0;
  in_stack_00000010 = (int)in_stack_0000000c;
  do {
    if (0xc < uVar13) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_0049c5f0(0);
    uVar13 = uVar13 + 1;
    in_stack_0000000c = (int *)((int)in_stack_0000000c + 0xc);
  } while ((int)uVar13 < 0xd);
  uVar13 = 0;
  iVar11 = *(int *)&local_14->field_0x20;
  in_stack_00000010 = 0;
  in_stack_0000000c = (int *)0x0;
  *(undefined1 *)(iVar11 + 8) = 1;
  do {
    if (uVar13 < 8) {
      *(undefined4 *)((int)in_stack_0000000c + 0xc + iVar11) = 0xffffffff;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)(iVar11 + 0xc) = 0xffffffff;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_00581330(0);
    in_stack_0000000c = (int *)((int)in_stack_0000000c + 4);
    uVar13 = uVar13 + 1;
    in_stack_00000010 = in_stack_00000010 + 8;
  } while ((int)uVar13 < 8);
  FUN_004455c0(1);
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

