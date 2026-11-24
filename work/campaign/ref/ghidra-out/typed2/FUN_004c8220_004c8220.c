
void __thiscall FUN_004c8220(CSceneRenderer *this)

{
  CHeightBlockArray *pCVar1;
  uint uVar2;
  CMap *this_00;
  int *piVar3;
  CHeightBlock *pCVar4;
  int iVar5;
  char *pcVar6;
  int in_stack_00000004;
  int in_stack_00000008;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  int local_18;
  int local_14;
  uint local_10;
  float local_c;
  float local_8;
  
  piVar3 = (int *)FUN_00592f10(PTR_0077241c);
  iVar5 = *piVar3;
  pCVar1 = PTR_0077241c->heightBlocks;
  if ((iVar5 < 0) || (pCVar1->count <= iVar5)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar4 = pCVar1->data;
  }
  else {
    pCVar4 = pCVar1->data + iVar5;
  }
  local_c = (float)(pCVar4->cornerLevels & 0xf) * 0.5 + 7.0;
  piVar3 = (int *)FUN_00592f10(PTR_0077241c);
  iVar5 = *piVar3;
  pCVar1 = PTR_0077241c->heightBlocks;
  if ((iVar5 < 0) || (pCVar1->count <= iVar5)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar4 = pCVar1->data;
  }
  else {
    pCVar4 = pCVar1->data + iVar5;
  }
  this_00 = PTR_0077241c;
  local_8 = (float)(pCVar4->cornerLevels >> 4) * 0.5 + 7.0;
  if (local_c < this->minHeight) {
    this->minHeight = local_c;
  }
  local_10 = *(uint *)this;
  iVar5 = FUN_00592f10(this_00);
  pcVar6 = (char *)(iVar5 + 0x34);
  if (local_10 < 8) {
    pcVar6 = pcVar6 + local_10;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_1c = local_8;
  if (*pcVar6 == '\0') {
    local_10 = *(uint *)this;
    local_14 = in_stack_00000008 + 1;
    iVar5 = FUN_00592f10(PTR_0077241c);
    pcVar6 = (char *)(iVar5 + 0x34);
    if (local_10 < 8) {
      pcVar6 = pcVar6 + local_10;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_1c = local_8;
    if (*pcVar6 == '\0') {
      local_10 = *(uint *)this;
      local_18 = in_stack_00000004 + 1;
      iVar5 = FUN_00592f10(PTR_0077241c);
      pcVar6 = (char *)(iVar5 + 0x34);
      if (local_10 < 8) {
        pcVar6 = pcVar6 + local_10;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_1c = local_8;
      if (*pcVar6 == '\0') {
        uVar2 = *(uint *)this;
        iVar5 = FUN_00592f10(PTR_0077241c);
        pcVar6 = (char *)(iVar5 + 0x34);
        if (uVar2 < 8) {
          pcVar6 = pcVar6 + uVar2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_1c = local_8;
        if (*pcVar6 == '\0') {
          local_1c = 14.5;
        }
      }
    }
  }
  local_24 = (float)in_stack_00000004 + 1.0;
  local_30 = (float)in_stack_00000004 + 0.0;
  local_20 = (float)in_stack_00000008 + 1.0;
  local_2c = (float)in_stack_00000008 + 0.0;
  local_28 = local_c;
  FUN_00473300(&local_30,&local_24);
  return;
}

