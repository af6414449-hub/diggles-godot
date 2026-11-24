
CMap * __thiscall FUN_005939b0(CMap *this)

{
  uint uVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007068f5;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)this = 0;
  this->mapFlags1 = 0;
  this->mapFlags2 = 0;
  this->mapFlags3 = 1;
  this->cells = (CMapCell *)0x0;
  this->cellCount = 0;
  this->cellY1 = 0;
  this->cellX1 = 0;
  this->cellY0 = 0;
  this->cellX0 = 0;
  this->y1_8 = 0;
  this->x1_8 = 0;
  this->y0_8 = 0;
  this->x0_8 = 0;
  this->mapFlags5 = 0;
  *(undefined4 *)(this + 1) = 0;
  local_8 = 3;
  this->mapFlags8 = 0;
  uVar5 = 0;
  this->mapWidth = 1;
  this->mapHeight = 1;
  this->cellCountTotal = 1;
  this->mapWidth8 = 8;
  this->mapHeight8 = 8;
  this->mapArea8 = 0x40;
  *(undefined1 *)&this->mapFlags = 0;
  this->mapFlags0 = 0;
  do {
    if (uVar5 < 8) {
      piVar2 = &this->mapFlags9 + uVar5;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = &this->mapFlags9;
    }
    uVar5 = uVar5 + 1;
    *piVar2 = -1;
  } while ((int)uVar5 < 8);
  this->cells = (CMapCell *)0x0;
  this->cellCount = 0;
  pvVar3 = (void *)FUN_006ba810(0x11a,uVar1);
  local_8._0_1_ = 4;
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    _eh_vector_constructor_iterator_((void *)((int)pvVar3 + 0x2c),8,8,FUN_00440550,FUN_00581100);
    *(undefined1 *)((int)pvVar3 + 8) = 1;
    uVar5 = 0;
    do {
      if (uVar5 < 8) {
        puVar4 = (undefined4 *)((int)pvVar3 + 0xc) + uVar5;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = (undefined4 *)((int)pvVar3 + 0xc);
      }
      *puVar4 = 0xffffffff;
      *(undefined4 *)((int)pvVar3 + uVar5 * 4 + 0x6c) = 0;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
    *(undefined4 *)((int)pvVar3 + 4) = 0;
  }
  local_8._0_1_ = 3;
  this->ownerBlocks = pvVar3;
  puVar4 = (undefined4 *)FUN_006ba810(0x11b,uVar1);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[4] = 0;
    puVar4[3] = 0;
    puVar4[2] = 0;
    puVar4[0x12] = 0;
    puVar4[0x11] = 0;
    puVar4[0x10] = 0;
    *(undefined4 *)((int)puVar4 + 0x5a) = 0;
    *(undefined4 *)((int)puVar4 + 0x5e) = 0;
    *(undefined4 *)((int)puVar4 + 0x62) = 0;
    *(undefined4 *)((int)puVar4 + 0x66) = 0;
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_005a9190();
  }
  this->mapFlags4 = (int)puVar4;
  this->heightBlocks = (CHeightBlockArray *)0x0;
  ExceptionList = local_10;
  return this;
}

