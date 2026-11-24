
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CSceneRenderer * __thiscall FUN_004c4420(CSceneRenderer *this)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fe93d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _eh_vector_constructor_iterator_(this->maskGroups,0x204,8,FUN_004ce600,FUN_004c47d0);
  local_8 = 0;
  this->textures = (void *)0x0;
  this->textureCount = 0;
  this->statA = 0;
  this->statB = 0;
  this->holesData = (void *)0x0;
  this->holeCount = 0;
  this->fogVertices = (void *)0x0;
  this->fogVertexCount = 0;
  FUN_0040ba00(uVar1);
  this->wallVertices = (void *)0x0;
  this->wallVertexCount = 0;
  FUN_0040ba00();
  local_8 = CONCAT31(local_8._1_3_,7);
  iVar4 = 0;
  _DAT_00772350 = 0;
  uVar1 = 0;
  do {
    if (uVar1 < 0x52) {
      *(undefined4 *)((int)this->textureIndex + iVar4) = 0;
      puVar2 = (uint *)((int)this->variants + iVar4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      this->textureIndex[0] = 0;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar2 = this->variants;
    }
    uVar1 = uVar1 + 1;
    *puVar2 = 0;
    iVar4 = iVar4 + 4;
  } while ((int)uVar1 < 0x52);
  this->defaultTexture = 0;
  this->holeCapacity = 0x400;
  puVar3 = (undefined4 *)FUN_006ba810(0x2c);
  local_8 = CONCAT31(local_8._1_3_,8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = puVar3 + 1;
    *puVar3 = 0x400;
    _eh_vector_constructor_iterator_(puVar6,0x1c,0x400,FUN_004c4750,FUN_004c4780);
  }
  this->holesData = puVar6;
  iVar4 = 0;
  this->holeCount = this->holeCapacity;
  if (0 < this->holeCapacity) {
    iVar5 = 0;
    do {
      if ((iVar4 < 0) || (this->holeCount <= iVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar3 = (undefined4 *)this->holesData;
      }
      else {
        puVar3 = (undefined4 *)((int)this->holesData + iVar5);
      }
      iVar4 = iVar4 + 1;
      *puVar3 = 0xffffffff;
      iVar5 = iVar5 + 0x1c;
    } while (iVar4 < this->holeCapacity);
  }
  this->flag4 = '\x01';
  this->flag2 = DAT_0076839a;
  this->flag1 = '\x01';
  this->fogScale = 0.1;
  this->maskGroups[0x80] = 0x14;
  this->maskGroups[0x101] = 0x14;
  this->maskGroups[0x182] = 0x14;
  this->maskGroups[0x203] = 0x15;
  this->maskGroups[0x284] = 0x14;
  this->maskGroups[0x305] = 0x14;
  this->maskGroups[0x386] = 0x14;
  this->maskGroups[0x407] = 0x15;
  this->flag3 = '\0';
  ExceptionList = local_10;
  return this;
}

