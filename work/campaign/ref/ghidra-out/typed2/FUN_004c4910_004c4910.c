
/* WARNING: Removing unreachable block (ram,0x004c4a31) */
/* WARNING: Removing unreachable block (ram,0x004c4a85) */

void __thiscall FUN_004c4910(CSceneRenderer *this)

{
  uint *puVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fe960;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004ce760(0);
  if (this->wallIndices != (void *)0x0) {
    FUN_006ba940(uVar4);
  }
  local_8 = 1;
  FUN_004ce630(0);
  if (this->wallVertices != (void *)0x0) {
    FUN_006ba940(uVar4);
  }
  local_8 = 2;
  FUN_004ce760(0);
  if (this->fogIndices != (void *)0x0) {
    FUN_006ba940();
  }
  local_8 = 3;
  FUN_004ce630(0);
  if (this->fogVertices != (void *)0x0) {
    FUN_006ba940();
  }
  pvVar2 = this->holesData;
  if (pvVar2 != (void *)0x0) {
    puVar1 = (uint *)((int)pvVar2 + -4);
    local_8 = 4;
    _eh_vector_destructor_iterator_(pvVar2,0x1c,*puVar1,FUN_004c4780);
    FUN_006cecca(puVar1,*puVar1 * 0x1c + 4);
  }
  local_8 = 6;
  iVar3 = this->statB;
  if (iVar3 < 0) {
    FUN_00491e00(-iVar3);
  }
  else if (0 < iVar3) {
    this->statB = this->statB - iVar3;
  }
  if (this->statA != 0) {
    FUN_006ba940();
  }
  local_8 = 7;
  iVar3 = this->textureCount;
  if (iVar3 < 0) {
    FUN_0042fc20(-iVar3);
  }
  else if (0 < iVar3) {
    this->textureCount = this->textureCount - iVar3;
  }
  if (this->textures != (void *)0x0) {
    FUN_006ba940();
  }
  local_8 = 8;
  _eh_vector_destructor_iterator_(this->maskGroups,0x204,8,FUN_004c47d0);
  ExceptionList = local_10;
  return;
}

