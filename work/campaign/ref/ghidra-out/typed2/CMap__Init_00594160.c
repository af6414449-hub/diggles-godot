
void __thiscall CMap__Init(CMap *this)

{
  void *pvVar1;
  CMap *pCVar2;
  int iVar3;
  undefined4 uVar4;
  CHeightBlockArray *pCVar5;
  FILE *_File;
  CHeightBlockArray **ppCVar6;
  undefined4 *puVar7;
  CMapCell *pCVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined8 uVar12;
  int in_stack_00000004;
  int in_stack_00000008;
  int *in_stack_0000000c;
  int in_stack_00000010;
  char *pcVar13;
  CHeightBlockArray *local_24;
  CHeightBlockArray *local_20;
  int local_1c;
  CHeightBlockArray *local_18;
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
     (FUN_006cebf4(&DAT_00ca54d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca54d8 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca54dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "CMap::Init";
    *(int *)(&DAT_00773650 + iVar9) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54d8);
  }
  local_18 = (CHeightBlockArray *)(DAT_00ca54dc * 0x40);
  uVar4 = *(undefined4 *)&local_18[0x2faf5].field_0x8;
  iVar3 = FUN_0043fcc0();
  pCVar5 = local_18;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar4;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)&local_18[0x2faf5].field_0xc;
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = *(int *)&pCVar5[0x2faf5].field_0xc;
    pCVar5[0x2faf5].data = (CHeightBlock *)(int)uVar12;
    pCVar5[0x2faf5].count = (int)((ulonglong)uVar12 >> 0x20);
  }
  *(int *)&pCVar5[0x2faf5].field_0xc = iVar3 + 1;
  local_8 = 0;
  CMap__Shut(this);
  if (this->heightBlocks != (CHeightBlockArray *)0x0) goto LAB_00594481;
  uVar4 = FUN_004435d0(&local_18,"BlockDB");
  uVar4 = FUN_00443730(uVar4);
  local_8._0_1_ = 1;
  FUN_0055a950(uVar4,1);
  local_8._0_1_ = 2;
  if ((local_18 != (CHeightBlockArray *)0x0) &&
     (*(int *)local_18 = *(int *)local_18 + -1, *(int *)local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  pCVar5 = (CHeightBlockArray *)FUN_006ba810(0x163);
  local_24 = pCVar5;
  if (pCVar5 == (CHeightBlockArray *)0x0) {
    pCVar5 = (CHeightBlockArray *)0x0;
  }
  else {
    *(undefined4 *)&pCVar5->field_0x8 = 0;
    *(undefined4 *)&pCVar5->field_0xc = 0;
    *(undefined4 *)pCVar5 = 0xffffffff;
    *(undefined4 *)&pCVar5->field_0x4 = 0xffffffff;
    pCVar5->data = (CHeightBlock *)0x0;
    pCVar5->count = 0;
    *(undefined4 *)&pCVar5->field_0x18 = 0;
    *(undefined4 *)&pCVar5->field_0x1c = 0;
    local_20 = pCVar5 + 1;
    *(int *)local_20 = 0;
    *(undefined4 *)&pCVar5[1].field_0x4 = 0;
    *(undefined4 *)&pCVar5[1].field_0xc = 0;
    pCVar5[1].data = (CHeightBlock *)0x0;
    pCVar5[1].count = 0;
    *(undefined4 *)&pCVar5[1].field_0x18 = 0;
    local_8._0_1_ = 9;
    *(undefined4 *)&pCVar5[1].field_0x8 = 0;
    FUN_00492060();
    DAT_00b836a4 = 0;
    DAT_00b836a8 = 0;
    *(undefined4 *)&pCVar5->field_0x20 = 0;
  }
  local_8._0_1_ = 0;
  local_14->heightBlocks = pCVar5;
  FUN_00565fb0();
  local_1c = DAT_0076838c;
  local_24 = (CHeightBlockArray *)FUN_006ba810(0x19);
  *(undefined4 *)&local_24->field_0x4 = 0x14;
  *(undefined4 *)&local_24->field_0x8 = 0xffffffff;
  *(int *)local_24 = 0;
  local_24->field_0xc = 0;
  local_24->field_0xc = 'd';
  local_24->field_0xd = 'a';
  local_24->field_0xe = 't';
  local_24->field_0xf = 'a';
  local_24->data = (CHeightBlock *)0x6f6c425c;
  local_24->count = 0x42446b63;
  local_24->field_0x18 = '2';
  local_24->field_0x19 = '.';
  local_24->field_0x1a = 'B';
  local_24->field_0x1b = 'D';
  *(undefined2 *)&local_24->field_0x1c = 0x42;
  *(undefined4 *)&local_24->field_0x8 = 0x11;
  *(int *)local_24 = 2;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_20 = local_24;
  local_18 = local_24;
  if (local_1c == 0) {
    pcVar13 = "data\\BlockDB0.BDB";
LAB_005943c4:
    FUN_006b9200(pcVar13);
  }
  else {
    if (local_1c == 1) {
      pcVar13 = "data\\BlockDB1.BDB";
      goto LAB_005943c4;
    }
    if (local_1c == 2) {
      pcVar13 = "data\\BlockDB2.BDB";
      goto LAB_005943c4;
    }
  }
  pCVar5 = local_18;
  _File = _fopen(&local_18->field_0xc,"rb");
  if (_File == (FILE *)0x0) {
    ppCVar6 = &local_20;
  }
  else {
    _fclose(_File);
    ppCVar6 = &local_18;
  }
  FUN_00565ab0(ppCVar6);
  local_8._0_1_ = 0xc;
  if ((pCVar5 != (CHeightBlockArray *)0x0) &&
     (*(int *)pCVar5 = *(int *)pCVar5 + -1, *(int *)pCVar5 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd;
  *(int *)local_24 = *(int *)local_24 + -1;
  if (*(int *)local_24 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0;
  uVar4 = FUN_004435d0(&local_24,"BlockDB done");
  uVar4 = FUN_00443730(uVar4);
  local_8._0_1_ = 0xe;
  FUN_0055a950(uVar4,1);
  local_8._0_1_ = 0xf;
  if ((local_24 != (CHeightBlockArray *)0x0) &&
     (*(int *)local_24 = *(int *)local_24 + -1, *(int *)local_24 == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  this = local_14;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
    this = local_14;
  }
LAB_00594481:
  this->mapHeight = in_stack_00000008;
  this->mapWidth = in_stack_00000004;
  this->originX8 = (int)in_stack_0000000c * 8;
  this->originY8 = in_stack_00000010 * 8;
  this->originX = (int)in_stack_0000000c;
  this->originY = in_stack_00000010;
  this->cellCountTotal = in_stack_00000004 * in_stack_00000008;
  uVar4 = FUN_004435d0(&stack0x0000000c,"Map PosHash");
  uVar4 = FUN_00443730(uVar4);
  local_8._0_1_ = 0x10;
  FUN_0055a950(uVar4,1);
  local_8._0_1_ = 0x11;
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  FUN_005641c0(this->mapWidth,this->mapHeight);
  in_stack_0000000c = (int *)this->mapWidth;
  iVar3 = (int)in_stack_0000000c * 8;
  local_14->mapWidth8 = iVar3;
  iVar9 = local_14->mapHeight * 8;
  local_14->mapHeight8 = iVar9;
  local_14->mapArea8 = iVar9 * iVar3;
  iVar10 = 0;
  local_14->cellX0 = local_14->originX;
  local_14->cellY0 = local_14->originY;
  local_14->cellX1 = (int)in_stack_0000000c + local_14->originX;
  local_14->cellY1 = local_14->mapHeight + local_14->originY;
  local_14->x0_8 = local_14->originX8;
  local_14->y0_8 = local_14->originY8;
  local_14->x1_8 = iVar3 + local_14->originX8;
  local_14->y1_8 = iVar9 + local_14->originY8;
  local_14->x0f = (float)local_14->cellX0;
  local_14->scanlineTotal = local_14->originY * (int)in_stack_0000000c + local_14->originX;
  iVar3 = DAT_0076a338;
  local_14->y0f = (float)local_14->cellY0;
  local_14->x1f = (float)local_14->cellX1;
  local_14->y1f = (float)local_14->cellY1;
  local_14->x0_8f = (float)local_14->x0_8;
  local_14->y0_8f = (float)local_14->y0_8;
  local_14->x1_8f = (float)local_14->x1_8;
  local_14->y1_8f = (float)local_14->y1_8;
  *(undefined1 *)(iVar3 + 0x3bac) = 1;
  if (0 < *(int *)(iVar3 + 0x3ba4)) {
    in_stack_0000000c = (int *)0x0;
    do {
      if ((iVar10 < 0) || (*(int *)(iVar3 + 0x3ba0) <= iVar10)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = *(undefined4 **)(iVar3 + 0x3b9c);
      }
      else {
        puVar7 = (undefined4 *)(*(int *)(iVar3 + 0x3b9c) + (int)in_stack_0000000c);
      }
      iVar10 = iVar10 + 1;
      *puVar7 = 0xffffffff;
      in_stack_0000000c = in_stack_0000000c + 7;
    } while (iVar10 < *(int *)(iVar3 + 0x3ba4));
  }
  pCVar2 = local_14;
  uVar4 = FUN_004435d0(&stack0x0000000c,"Map VMem");
  uVar4 = FUN_00443730(uVar4);
  local_8._0_1_ = 0x12;
  FUN_0055a950(uVar4,1);
  local_8._0_1_ = 0x13;
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c == 0)) {
    FUN_006ba940();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  pCVar8 = (CMapCell *)FUN_006c4e10(pCVar2->cellCountTotal * 0x7c);
  pCVar2->cells = pCVar8;
  pCVar2->cellCount = pCVar2->cellCountTotal;
  iVar3 = pCVar2->cellCountTotal * 0x7c;
  uVar4 = 0;
  FUN_004459b0(iVar3,0);
  FUN_00445770(iVar3,uVar4);
  iVar3 = DAT_0076a324;
  pCVar2->mapFlags = 0x100;
  DAT_007683d8 = 0xffffd8f0;
  *(undefined4 *)(iVar3 + 0x4410) = 0xffffd8f0;
  FUN_0059a320();
  FUN_005a9090();
  FUN_005a7c90();
  in_stack_0000000c = (int *)FUN_005a3dd0();
  uVar11 = 0;
  in_stack_00000010 = (int)in_stack_0000000c;
  do {
    if (0xc < uVar11) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_0049c5f0(0);
    uVar11 = uVar11 + 1;
    in_stack_0000000c = (int *)((int)in_stack_0000000c + 0xc);
  } while ((int)uVar11 < 0xd);
  uVar11 = 0;
  pvVar1 = local_14->ownerBlocks;
  in_stack_00000010 = 0;
  in_stack_0000000c = (int *)0x0;
  *(undefined1 *)((int)pvVar1 + 8) = 1;
  do {
    if (uVar11 < 8) {
      *(undefined4 *)((int)in_stack_0000000c + 0xc + (int)pvVar1) = 0xffffffff;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(undefined4 *)((int)pvVar1 + 0xc) = 0xffffffff;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_00581330(0);
    in_stack_0000000c = (int *)((int)in_stack_0000000c + 4);
    uVar11 = uVar11 + 1;
    in_stack_00000010 = in_stack_00000010 + 8;
  } while ((int)uVar11 < 8);
  FUN_004455c0(1);
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

