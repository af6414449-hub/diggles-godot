
void __thiscall FUN_00527fa0(ViWinRoot *this)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int local_30;
  int local_2c;
  undefined4 local_28;
  ViWinRoot *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070292d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this->i_44 = *(int *)(DAT_00772400 + 100);
  local_24 = this;
  FUN_00505e90(20000000,0,1,0);
  if (*(char *)(DAT_00772400 + 0x590) == '\0') {
    local_1c = (int *)FUN_006ba810(0x93,uVar1);
    local_8 = 0;
    if (local_1c == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_005392c0();
    }
    local_8 = 0xffffffff;
    *(undefined4 *)&this->field_0xac = uVar2;
    FUN_00504ce0(uVar2);
    local_1c = (int *)FUN_006ba810(0x9d,uVar1);
    local_8 = 1;
    if (local_1c == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_005113a0();
    }
    local_8 = 0xffffffff;
    *(undefined4 *)&this->field_0xb0 = uVar2;
    FUN_00504ce0(uVar2);
    iVar6 = *(int *)&this->field_0xb0;
    if (*(char *)(iVar6 + 0x1c) != '\0') {
      FUN_00504ee0();
      *(undefined1 *)(iVar6 + 0x1c) = 0;
    }
    piVar3 = (int *)FUN_006ba810(0xa0);
    local_8 = 2;
    local_1c = piVar3;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      FUN_005044d0();
      *piVar3 = (int)ViWinDigButtons::vftable;
      piVar3[10] = 2;
      piVar3[0x17] = -1;
    }
    local_8 = 0xffffffff;
    *(int **)&this->field_0xb4 = piVar3;
    FUN_00504ce0(piVar3);
    (**(code **)(**(int **)&this->field_0xb4 + 0x38))();
    local_1c = (int *)FUN_006ba810(0xa4);
    local_8 = 3;
    if (local_1c == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00523100();
    }
    local_8 = 0xffffffff;
    *(undefined4 *)&this->field_0xbc = uVar2;
    FUN_00504ce0(uVar2);
    iVar6 = *(int *)&this->field_0xbc;
    if (*(char *)(iVar6 + 0x1c) != '\0') {
      FUN_00504ee0();
      *(undefined1 *)(iVar6 + 0x1c) = 0;
    }
    iVar6 = this->i_14;
    iVar9 = this->i_0c;
    local_1c = (int *)((this->i_18 - this->i_10) + -0x98);
    puVar4 = (undefined4 *)FUN_006ba810(0x37);
    local_8 = 4;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
      local_14 = (int *)0x0;
    }
    else {
      local_14 = puVar4;
      FUN_005044d0();
      *puVar4 = ViWinClock::vftable;
      puVar4[0x19] = 0xff000000;
      puVar4[0x1a] = 0xff000000;
      puVar4[0x2b] = 0;
      puVar4[0x2c] = 0;
      puVar4[0x31] = 0;
      puVar4[0x2f] = 0;
      puVar4[0x30] = 0;
      puVar4[0x2e] = 0;
      puVar4[0x2d] = 0;
      puVar4[0x32] = 0;
      puVar4[0x33] = 0;
      puVar4[0x38] = 0;
      puVar4[0x36] = 0;
      puVar4[0x37] = 0;
      puVar4[0x35] = 0;
      puVar4[0x34] = 0;
      puVar4[0x19] = 0x80dab674;
      local_14 = (int *)0xa51e2a63;
      puVar4[10] = 2;
      puVar4[0x11] = 0;
      puVar4[0x12] = 0xbf800000;
      puVar4[0x13] = 0xbf800000;
      puVar4[0x14] = 0xc7c35000;
      *(undefined2 *)(puVar4 + 0x15) = 0;
      *(undefined1 *)(puVar4 + 0x1b) = 0;
      puVar4[0x16] = 0x42800000;
      puVar4[0x17] = 0x42800000;
      puVar4[0x18] = 0x42140000;
      puVar4[0x1a] = 0xa51e2a63;
      puVar4[0x22] = 0;
      puVar4[0x23] = 0x3e800000;
      puVar4[0x24] = 0x3f000000;
      puVar4[0x25] = 0x3f400000;
      puVar4[0x26] = 0x3f000000;
      puVar4[0x27] = 0x3f400000;
      puVar4[0x28] = 0x3f800000;
      puVar4[0x29] = 0x3fa00000;
      puVar4[0x3a] = 0;
    }
    local_8 = 0xffffffff;
    puVar4[0x39] = this;
    FUN_00504ce0(puVar4);
    FUN_00504ee0();
    local_14 = local_1c;
    *(undefined4 **)&this->field_0xd4 = puVar4;
    local_18 = (iVar6 - iVar9) + -0x96;
    FUN_00504a70(&local_18);
    local_1c = (int *)FUN_006ba810(0xc0);
    local_8 = 5;
    if (local_1c == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0054d140();
    }
    local_8 = 0xffffffff;
    *(undefined4 *)&this->field_0x114 = uVar2;
    FUN_00504ce0(uVar2);
    local_20 = 600;
    local_1c = (int *)0x190;
    FUN_00504ba0(&local_20);
    local_1c = (int *)((this->i_18 - this->i_10) / 2 + -200);
    local_20 = (this->i_14 - this->i_0c) / 2 + -300;
    FUN_00504a70(&local_20);
    iVar6 = *(int *)&this->field_0x114;
    if (*(char *)(iVar6 + 0x1c) != '\0') {
      FUN_00504ee0();
      *(undefined1 *)(iVar6 + 0x1c) = 0;
    }
    piVar3 = (int *)FUN_006ba810(0xc6);
    local_8 = 6;
    local_1c = piVar3;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      FUN_00533b10();
      local_8._0_1_ = 7;
      *piVar3 = (int)ViWinBigInfo::vftable;
      piVar5 = (int *)FUN_006ba810(0x19);
      piVar5[1] = 0x14;
      piVar5[2] = -1;
      *piVar5 = 0;
      *(undefined1 *)(piVar5 + 3) = 0;
      piVar3[0x1a] = (int)piVar5;
      *piVar5 = *piVar5 + 1;
      local_8._0_1_ = 8;
      piVar3[10] = 2;
      local_14 = (int *)FUN_006ba810(0xc);
      local_8._0_1_ = 9;
      if (local_14 == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_00513650();
      }
      local_8 = CONCAT31(local_8._1_3_,8);
      local_18 = 0x15e;
      local_14 = (int *)0x320;
      FUN_00504ba0(&local_18);
      piVar3[0x14] = iVar6;
      FUN_006b9200(&PTR_0071ce50);
      piVar3[0x19] = 0;
    }
    local_8 = 0xffffffff;
    this->i_118 = (int)piVar3;
    FUN_00504ce0(piVar3);
    local_1c = (int *)0x1e;
    local_20 = ((this->i_14 - this->i_0c) + -600) / 2;
    FUN_00504a70(&local_20);
    local_1c = (int *)((this->i_18 - this->i_10) + -0x8c);
    local_20 = 600;
    FUN_00504ba0(&local_20);
    iVar6 = this->i_118;
    if (*(char *)(iVar6 + 0x1c) != '\0') {
      FUN_00504ee0();
      *(undefined1 *)(iVar6 + 0x1c) = 0;
    }
    local_14 = (int *)(this->i_14 - this->i_0c);
    local_20 = 10;
    local_1c = (int *)0x2;
    iVar6 = FUN_00507ab0("data/gui/buttons/LO_Main");
    *(undefined4 *)(iVar6 + 0x28) = 2;
    uVar2 = FUN_004435d0(&local_1c,"Main menu");
    piVar7 = (int *)FUN_00443730(uVar2);
    local_8 = 10;
    piVar3 = (int *)*piVar7;
    piVar5 = *(int **)(iVar6 + 0x30);
    *(int **)(iVar6 + 0x30) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x30) + 8) = *(undefined4 *)(*piVar7 + 8);
    local_8 = 0xb;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    this->i_fc = iVar6;
    local_30 = 10;
    local_2c = 0x28;
    piVar3 = (int *)FUN_006ba810(0xd);
    local_8 = 0xc;
    local_1c = piVar3;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      FUN_005044d0();
      *piVar3 = (int)ViWinAutoPopup::vftable;
      piVar3[10] = 2;
    }
    local_8 = 0xffffffff;
    FUN_00504a70(&local_30);
    FUN_00504ce0(piVar3);
    this->i_100 = (int)piVar3;
    piVar3[10] = 2;
    iVar6 = this->i_100;
    if (*(char *)(iVar6 + 0x1c) != '\0') {
      FUN_00504ee0();
      *(undefined1 *)(iVar6 + 0x1c) = 0;
    }
    uVar2 = FUN_004435d0(&local_1c,"Main menu");
    piVar7 = (int *)FUN_00443730(uVar2);
    local_8 = 0xd;
    iVar6 = this->i_100;
    piVar3 = (int *)*piVar7;
    piVar5 = *(int **)(iVar6 + 0x30);
    *(int **)(iVar6 + 0x30) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x30) + 8) = *(undefined4 *)(*piVar7 + 8);
    local_8 = 0xe;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    local_30 = 0x8c;
    local_2c = 0;
    iVar6 = FUN_00507ab0("data/gui/buttons/LO_Halter_links");
    *(undefined4 *)(iVar6 + 0x28) = 2;
    if (*(int *)(iVar6 + 0x58) != 5) {
      *(undefined4 *)(iVar6 + 0x58) = 5;
      FUN_00504ee0();
    }
    FUN_00505f70();
    piVar3 = local_14;
    local_2c = 0;
    local_30 = (int)local_14 + -0x118;
    iVar6 = FUN_00507ab0("data/gui/buttons/LO_Halter_rechts");
    *(undefined4 *)(iVar6 + 0x28) = 2;
    if (*(int *)(iVar6 + 0x58) != 5) {
      *(undefined4 *)(iVar6 + 0x58) = 5;
      FUN_00504ee0();
    }
    FUN_00505f70();
    local_30 = (int)piVar3 + -0x109;
    *(int *)&this->field_0xec = iVar6;
    local_2c = 0x11;
    iVar6 = FUN_00507ab0("data/gui/buttons/LO_Pfeil_down");
    *(undefined4 *)(iVar6 + 0x28) = 2;
    FUN_00505ed0();
    this->i_f0 = iVar6;
    uVar2 = FUN_004435d0(&local_1c,"Toggle newsticker");
    piVar7 = (int *)FUN_00443730(uVar2);
    local_8 = 0xf;
    iVar6 = this->i_f0;
    piVar3 = (int *)*piVar7;
    piVar5 = *(int **)(iVar6 + 0x30);
    *(int **)(iVar6 + 0x30) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x30) + 8) = *(undefined4 *)(*piVar7 + 8);
    local_8 = 0x10;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    local_30 = (int)local_14 + -0xaa;
    local_2c = 0;
    iVar6 = FUN_00507ab0("data/gui/buttons/LO_Finder_Z");
    *(undefined4 *)(iVar6 + 0x28) = 2;
    this->i_f8 = iVar6;
    uVar2 = FUN_004435d0(&local_1c,"Finder mode");
    piVar7 = (int *)FUN_00443730(uVar2);
    local_8 = 0x11;
    iVar6 = this->i_f8;
    piVar3 = (int *)*piVar7;
    piVar5 = *(int **)(iVar6 + 0x30);
    *(int **)(iVar6 + 0x30) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x30) + 8) = *(undefined4 *)(*piVar7 + 8);
    local_8 = 0x12;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    local_30 = (int)local_14 + -0x50;
    local_2c = 0x11;
    iVar6 = FUN_00507ab0("data/gui/buttons/LO_Pfeil_up");
    *(undefined4 *)(iVar6 + 0x28) = 2;
    FUN_00505ed0();
    this->i_f4 = iVar6;
    uVar2 = FUN_004435d0(&local_1c,"Toggle finder");
    piVar7 = (int *)FUN_00443730(uVar2);
    local_8 = 0x13;
    iVar6 = this->i_f4;
    piVar3 = (int *)*piVar7;
    piVar5 = *(int **)(iVar6 + 0x30);
    *(int **)(iVar6 + 0x30) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x30) + 8) = *(undefined4 *)(*piVar7 + 8);
    local_8 = 0x14;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    local_1c = (int *)FUN_006ba810(0xf9);
    local_8 = 0x15;
    if (local_1c == (int *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_005190c0();
    }
    local_8 = 0xffffffff;
    this->i_dc = iVar6;
    local_30 = 0xc3;
    local_2c = 0x12;
    FUN_00504a70(&local_30);
    local_30 = (int)local_14 + -0x1cc;
    local_2c = 0x1c;
    FUN_00504ba0(&local_30);
    uVar2 = FUN_004435d0(&local_1c,"Newsticker");
    piVar7 = (int *)FUN_00443730(uVar2);
    local_8 = 0x16;
    iVar6 = this->i_dc;
    piVar3 = (int *)*piVar7;
    piVar5 = *(int **)(iVar6 + 0x30);
    *(int **)(iVar6 + 0x30) = piVar3;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
      FUN_006ba940();
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x30) + 8) = *(undefined4 *)(*piVar7 + 8);
    local_8 = 0x17;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_00504ce0(this->i_dc);
    iVar9 = (this->i_18 - this->i_10) / 2;
    iVar6 = (this->i_14 - this->i_0c) / 2;
    FUN_00501450(iVar6,iVar9);
    FUN_00501ec0(iVar6,iVar9);
    local_1c = (int *)FUN_006ba810(0x3e);
    local_8 = 0x18;
    if (local_1c == (int *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_00524e60();
    }
    local_8 = 0xffffffff;
    local_30 = 300;
    local_2c = 0xaa;
    FUN_00504ba0(&local_30);
    FUN_00504ce0(iVar6);
    this->i_b8 = iVar6;
    local_30 = ((this->i_14 - *(int *)(iVar6 + 0x14)) - this->i_0c) + *(int *)(iVar6 + 0xc);
    local_2c = 0;
    FUN_00504a70(&local_30);
    if (*(char *)(this->i_b8 + 0x4c) != '\0') {
      *(undefined1 *)(this->i_b8 + 0x4c) = 0;
      FUN_00505ed0();
      FUN_00525920();
    }
    piVar3 = (int *)FUN_006ba810(0x12);
    local_8 = 0x19;
    local_1c = piVar3;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      FUN_005044d0();
      local_8 = CONCAT31(local_8._1_3_,0x1a);
      *piVar3 = (int)ViWinQuickHelp::vftable;
      piVar5 = (int *)FUN_006ba810(0x19);
      piVar5[1] = 0x14;
      piVar5[2] = -1;
      *piVar5 = 0;
      *(undefined1 *)(piVar5 + 3) = 0;
      piVar3[0x11] = (int)piVar5;
      *piVar5 = *piVar5 + 1;
      piVar3[0x12] = 0;
      piVar3[0x13] = 0;
      piVar3[10] = 2;
    }
    local_8 = 0xffffffff;
    local_30 = 300;
    local_2c = 0xaa;
    FUN_00504ba0(&local_30);
    FUN_00504ce0(piVar3);
    *(int **)&this->field_0x10c = piVar3;
    piVar3 = (int *)FUN_006ba810(0x1f);
    local_8 = 0x1b;
    local_1c = piVar3;
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      FUN_005044d0();
      local_8 = CONCAT31(local_8._1_3_,0x1c);
      *piVar3 = (int)ViWinSpeechText::vftable;
      piVar7 = (int *)FUN_006ba810(0x19);
      piVar5 = piVar3 + 0x16;
      local_14 = (int *)0xa0c8c8c8;
      piVar7[1] = 0x14;
      piVar7[2] = -1;
      *piVar7 = 0;
      *(undefined1 *)(piVar7 + 3) = 0;
      piVar3[0x11] = (int)piVar7;
      *piVar7 = *piVar7 + 1;
      piVar3[0x12] = 0;
      piVar3[0x13] = 0;
      *piVar5 = -0x1000000;
      piVar3[0x17] = -0x1000000;
      piVar3[0x18] = -0x1000000;
      piVar3[0x19] = -0x1000000;
      piVar3[0x14] = 0;
      piVar3[0x15] = 0;
      *(undefined1 *)(piVar3 + 7) = 0;
      uVar8 = 0;
      do {
        if (uVar8 < 4) {
          piVar3 = piVar5 + uVar8;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar3 = piVar5;
        }
        uVar8 = uVar8 + 1;
        *piVar3 = -0x5f373738;
      } while ((int)uVar8 < 4);
      local_1c[10] = 4;
      piVar3 = local_1c;
      this = local_24;
    }
    local_8 = 0xffffffff;
    local_30 = 300;
    local_2c = 0xaa;
    FUN_00504ba0(&local_30);
    FUN_00504ce0(piVar3);
    *(int **)&this->field_0x110 = piVar3;
    local_30 = 10;
    local_2c = 10;
    puVar4 = (undefined4 *)FUN_006ba810(8);
    local_8 = 0x1d;
    local_24 = (ViWinRoot *)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      FUN_005044d0();
      *puVar4 = ViWinOverlayMsg::vftable;
      puVar4[0x11] = 0;
      puVar4[0x12] = 0;
    }
    local_8 = 0xffffffff;
    FUN_00504a70(&local_30);
    FUN_0051ec10();
    FUN_00504ce0(puVar4);
    *(undefined4 **)&this->field_0xe0 = puVar4;
    puVar4 = (undefined4 *)FUN_006ba810(0x28);
    local_8 = 0x1e;
    local_24 = (ViWinRoot *)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      FUN_005044d0();
      *puVar4 = ViWinSimpleFinder::vftable;
      FUN_0040ba00();
      FUN_0040ba00();
      puVar4[0x1d] = 0;
      puVar4[0x1e] = 0;
      FUN_004fed60();
      FUN_004fed60();
      local_8 = CONCAT31(local_8._1_3_,0x24);
      puVar4[10] = 2;
      puVar4[0x30] = 0;
      *(undefined1 *)(puVar4 + 0x2f) = 1;
      puVar4[0x31] = 0;
      puVar4[0x1f] = 0xffffffff;
      puVar4[0x20] = 0xffffffff;
      puVar4[0x12] = 0xffffffff;
      puVar4[0x11] = 0xffffffff;
      puVar4[0x14] = 0xffffffff;
      puVar4[0x15] = 0xffffffff;
      puVar4[0x19] = 0;
      puVar4[0x1a] = 0;
      local_30 = 0x40;
      local_2c = 0;
      iVar6 = FUN_00507ab0("data/gui/buttons/LO_Pfeil_up");
      puVar4[0x19] = iVar6;
      local_30 = 0x68;
      *(undefined4 *)(iVar6 + 0x28) = 2;
      local_2c = 0;
      iVar6 = FUN_00507ab0("data/gui/buttons/LO_Pfeil_down");
      puVar4[0x1a] = iVar6;
      *(undefined4 *)(iVar6 + 0x28) = 2;
    }
    local_8 = 0xffffffff;
    FUN_00504ce0(puVar4);
    this->i_e4 = (int)puVar4;
    local_30 = this->i_14 - this->i_0c;
    local_2c = 0x20;
    local_28 = 0;
    local_24 = (ViWinRoot *)0xc;
    uVar2 = FUN_0050d8c0(&local_30);
    *(undefined4 *)&this->field_0xcc = uVar2;
    local_30 = this->i_14 - this->i_0c;
    local_24 = (ViWinRoot *)((this->i_18 - this->i_10) + -0x20);
    local_2c = 0x20;
    local_28 = 0;
    uVar2 = FUN_0050d8c0(&local_30);
    *(undefined4 *)&this->field_0xd0 = uVar2;
    FUN_00505f70();
    FUN_00505f70();
    FUN_00527f40(this->i_14 - this->i_0c,this->i_18 - this->i_10);
  }
  local_2c = (this->i_18 - this->i_10) + -400;
  local_30 = 5;
  puVar4 = (undefined4 *)FUN_006ba810(0x1d,uVar1);
  local_8 = 0x25;
  local_24 = (ViWinRoot *)puVar4;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_005044d0();
    *puVar4 = ViWinChat::vftable;
    puVar4[0x12] = 0;
    *(undefined1 *)(puVar4 + 0x13) = 0;
    puVar4[0x16] = 0;
    *(undefined1 *)(puVar4 + 0x17) = 0;
    puVar4[0x1a] = 0;
    *(undefined1 *)(puVar4 + 0x1b) = 0;
    puVar4[0x1e] = 0;
    *(undefined1 *)(puVar4 + 0x1f) = 0;
    puVar4[0x22] = 0;
    *(undefined1 *)(puVar4 + 0x23) = 0;
    puVar4[0x26] = 0;
    *(undefined1 *)(puVar4 + 0x27) = 0;
    puVar4[0x2a] = 0;
    *(undefined1 *)(puVar4 + 0x2b) = 0;
    puVar4[0x2e] = 0;
    *(undefined1 *)(puVar4 + 0x2f) = 0;
    puVar4[10] = 2;
  }
  local_8 = 0xffffffff;
  FUN_00504a70(&local_30);
  local_30 = 0x1a4;
  local_2c = 0x88;
  FUN_00504ba0(&local_30);
  FUN_00504ce0(puVar4);
  this->i_104 = (int)puVar4;
  if (*(char *)(puVar4 + 0xb) != '\0') {
    *(undefined1 *)(puVar4 + 0xb) = 0;
    FUN_00504ee0();
    puVar4 = (undefined4 *)this->i_104;
  }
  if (*(char *)(puVar4 + 7) != '\0') {
    FUN_00504ee0();
    *(undefined1 *)(puVar4 + 7) = 0;
  }
  FUN_00504ee0();
  ExceptionList = local_10;
  return;
}

