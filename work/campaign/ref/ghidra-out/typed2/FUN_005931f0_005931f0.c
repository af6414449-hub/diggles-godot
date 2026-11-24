
void FUN_005931f0(int *param_1)

{
  CMap *pCVar1;
  CMap *pCVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  CMap *this;
  int iVar9;
  int iVar10;
  int iVar11;
  int *local_2c;
  undefined1 local_28 [4];
  int *local_24;
  int local_20;
  int *local_1c;
  uint local_18;
  CMap *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070686d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = PTR_0077241c;
  piVar7 = param_1;
  this = PTR_0077241c;
  if (*param_1 == 2) {
    piVar8 = &PTR_0077241c->mapWidth;
    FUN_00406f60(piVar8);
    piVar6 = &local_14->mapHeight;
    FUN_00406f60(piVar6);
    FUN_00406f60(&local_14->cellX0);
    FUN_00406f60(&local_14->cellY0);
    FUN_00406f60(&local_14->cellX1);
    FUN_00406f60(&local_14->cellY1);
    this = local_14;
    piVar7 = param_1;
    local_20 = *piVar8 * *piVar6;
    local_1c = (int *)0x0;
    if (0 < local_20) {
      local_18 = 0;
      do {
        if (this->cellCount <= (int)local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_00592f90(piVar7);
        local_1c = (int *)((int)local_1c + 1);
        local_18 = local_18 + 0x7c;
      } while ((int)local_1c < local_20);
    }
    local_18 = 0;
    do {
      local_1c = (int *)((int)this->ownerBlocks + 0xc);
      if (local_18 < 8) {
        local_1c = (int *)((int)local_1c + local_18 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *piVar7;
      if (iVar5 == 1) {
        iVar5 = piVar7[1];
        if (((iVar5 != 0) && (*(int *)(iVar5 + 0x10) == 0x1c4f)) &&
           ((*(int *)(iVar5 + 0x5c) == 0 || (*(int *)(iVar5 + 0x5c) == -5)))) {
          FUN_006c6da0(4);
          iVar5 = *piVar7;
          goto LAB_00593347;
        }
      }
      else {
LAB_00593347:
        if ((((iVar5 == 2) && (iVar5 = piVar7[1], iVar5 != 0)) && (*(int *)(iVar5 + 0x10) == 0x79b1)
            ) && (*(int *)(iVar5 + 0x5c) == 0)) {
          FUN_006c76b0(4);
        }
      }
      local_18 = local_18 + 1;
    } while ((int)local_18 < 8);
    FUN_00406f60(&DAT_007683d8);
    local_24 = *(int **)(DAT_0076a324 + 0x4410);
    FUN_00406f60(&local_24);
  }
  if (*piVar7 == 1) {
    uVar4 = FUN_004435d0(&local_24,"World shut",uVar3);
    uVar4 = FUN_00443730(uVar4);
    local_8 = 0;
    FUN_0055a950(uVar4,1);
    local_8 = 1;
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00479c10(1,1);
    CMap__Shut(this);
    FUN_00406f60(&local_2c);
    FUN_00406f60(local_28);
    uVar4 = FUN_004435d0(&local_24,"World init");
    uVar4 = FUN_00443730(uVar4);
    local_8 = 2;
    FUN_0055a950(uVar4,1);
    local_8 = 3;
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00479c10(1,1);
    CMap__Init(this);
    piVar7 = &this->cellX0;
    FUN_00406f60(piVar7);
    piVar6 = &this->cellY0;
    FUN_00406f60(piVar6);
    FUN_00406f60(&local_14->cellX1);
    FUN_00406f60(&local_14->cellY1);
    this = local_14;
    local_1c = (int *)*piVar7;
    iVar9 = *piVar6;
    local_20 = (int)local_1c << 3;
    local_24 = (int *)(local_14->cellX1 * 8);
    local_14->x1_8 = (int)local_24;
    local_14->x0_8 = local_20;
    local_14->y0_8 = iVar9 * 8;
    local_14->x0f = (float)(int)local_1c;
    iVar5 = local_14->cellY1 * 8;
    local_14->y1_8 = iVar5;
    local_14->y0f = (float)iVar9;
    local_14->x1f = (float)local_14->cellX1;
    local_14->y1f = (float)local_14->cellY1;
    local_14->x0_8f = (float)local_20;
    local_14->y0_8f = (float)(iVar9 * 8);
    local_14->x1_8f = (float)(int)local_24;
    pCVar1 = PTR_0077241c;
    local_14->originY = iVar9;
    local_14->y1_8f = (float)iVar5;
    local_14->originX = (int)local_1c;
    local_14->originX8 = local_20;
    local_14->originY8 = iVar9 * 8;
    iVar5 = FUN_005a9090();
    pCVar2 = PTR_0077241c;
    *(int *)(iVar5 + 0x54) = pCVar1->cellX0;
    iVar5 = FUN_005a9090();
    *(int *)(iVar5 + 0x58) = pCVar2->cellY0;
    uVar4 = FUN_004435d0(&local_24,"World blocks");
    uVar4 = FUN_00443730(uVar4);
    local_8 = 4;
    FUN_0055a950(uVar4,1);
    local_8 = 5;
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00479c10(1,1);
    piVar7 = param_1;
    local_14 = (CMap *)(this->mapHeight * this->mapWidth);
    local_20 = 0;
    if (DAT_007723fc < 0x7c) {
      if (0 < (int)local_14) {
        local_1c = (int *)0x0;
        do {
          if (this->cellCount <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_00593070(piVar7);
          local_20 = local_20 + 1;
          local_1c = (int *)((int)local_1c + 0x7c);
        } while (local_20 < (int)local_14);
      }
    }
    else if (0 < (int)local_14) {
      local_1c = (int *)0x0;
      do {
        if (this->cellCount <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_00592f90(piVar7);
        local_20 = local_20 + 1;
        local_1c = (int *)((int)local_1c + 0x7c);
      } while (local_20 < (int)local_14);
    }
    uVar4 = FUN_004435d0(&local_24,"World FoW I");
    uVar4 = FUN_00443730(uVar4);
    local_8 = 6;
    FUN_0055a950(uVar4,1);
    local_8 = 7;
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00479c10(1,1);
    param_1 = (int *)0x0;
    do {
      iVar5 = *piVar7;
      if (iVar5 == 1) {
        iVar5 = piVar7[1];
        if (((iVar5 != 0) && (*(int *)(iVar5 + 0x10) == 0x1c4f)) &&
           ((*(int *)(iVar5 + 0x5c) == 0 || (*(int *)(iVar5 + 0x5c) == -5)))) {
          FUN_006c6da0(4);
          iVar5 = *piVar7;
          goto LAB_00593772;
        }
      }
      else {
LAB_00593772:
        if ((((iVar5 == 2) && (iVar5 = piVar7[1], iVar5 != 0)) && (*(int *)(iVar5 + 0x10) == 0x79b1)
            ) && (*(int *)(iVar5 + 0x5c) == 0)) {
          FUN_006c76b0(4);
        }
      }
      FUN_00580610(local_18,param_1);
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < 8);
    FUN_00406f60(&local_18);
    FUN_00590620(local_18);
    if (0x7a < DAT_007723fc) {
      FUN_00406f60(&local_18);
      *(uint *)(DAT_0076a324 + 0x4410) = local_18;
    }
    uVar4 = FUN_004435d0(&local_24,"World validate");
    uVar4 = FUN_00443730(uVar4);
    local_8 = 8;
    FUN_0055a950(uVar4,1);
    local_8 = 9;
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00479c10(1,1);
    iVar5 = this->x0_8;
    iVar9 = this->y0_8;
    iVar10 = this->x1_8;
    iVar11 = this->y1_8;
    uVar4 = 0x5f;
    this->mapFlags = 0x100;
    FUN_005a3dd0(iVar5,iVar9,iVar10,iVar11,0x5f);
    FUN_005a3fd0(iVar5,iVar9,iVar10,iVar11,uVar4);
    uVar4 = 0x7ff;
    FUN_005a3dd0(0x7ff);
    FUN_005a46d0(uVar4);
    *(undefined1 *)((int)this->ownerBlocks + 8) = 1;
    *(undefined1 *)&this->mapFlags = 1;
  }
  uVar4 = FUN_004435d0(&local_2c,"World fluid",uVar3);
  uVar4 = FUN_00443730(uVar4);
  local_8 = 10;
  FUN_0055a950(uVar4,1);
  local_8 = 0xb;
  if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  FUN_00479c10(1,1);
  FUN_0057d980(piVar7);
  FUN_0057ce70(piVar7);
  uVar4 = FUN_004435d0(&local_2c,"World FoW II");
  uVar4 = FUN_00443730(uVar4);
  local_8 = 0xc;
  FUN_0055a950(uVar4,1);
  local_8 = 0xd;
  if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  FUN_00479c10(1,1);
  local_1c = (int *)((int)this->ownerBlocks + 0x2c);
  local_20 = 8;
  do {
    param_1 = (int *)local_1c[1];
    FUN_00406f60(&param_1);
    FUN_00581330(param_1);
    iVar5 = 0;
    if (0 < (int)param_1) {
      do {
        iVar10 = *local_1c + iVar5 * 8;
        iVar9 = iVar10 + 4;
        FUN_00406f60(iVar10);
        FUN_00406f60(iVar9);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)param_1);
    }
    local_1c = local_1c + 2;
    local_20 = local_20 + -1;
  } while (local_20 != 0);
  FUN_0059a320();
  ExceptionList = local_10;
  return;
}

