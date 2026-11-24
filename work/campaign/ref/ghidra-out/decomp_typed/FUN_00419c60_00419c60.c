
undefined4 FUN_00419c60(void)

{
  float *pfVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int this;
  int iVar7;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int *piVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  float local_14;
  int local_10;
  int local_c;
  int local_8;
  
  pfVar1 = (float *)(this + 0x40);
  iVar3 = this->i_04;
  this->i_2c = 0xffffffff;
  *pfVar1 = *(float *)(iVar3 + 0xc);
  this->i_44 = *(undefined4 *)(iVar3 + 0x10);
  this->i_48 = *(undefined4 *)(iVar3 + 0x14);
  iVar3 = this->i_04;
  this->i_4c = *(undefined4 *)(iVar3 + 0x40);
  this->i_50 = *(undefined4 *)(iVar3 + 0x44);
  this->i_54 = *(undefined4 *)(iVar3 + 0x48);
  this->i_3c = 0x3dcccccd;
  cVar2 = FUN_004192a0();
  if (cVar2 == '\0') {
    if ((*(int *)(DAT_00772400 + 0x6c) % 0x14 == 0x13) || (this->i_20 == 0)) {
      FUN_0057d980();
      cVar2 = FUN_0057a940();
      iVar3 = this->i_0c;
      if (cVar2 == '\0') {
        if (*(int *)(iVar3 + 0x798) != 1) {
          FUN_004234a0();
        }
      }
      else if ((*(int *)(iVar3 + 0x3d0) != -1) &&
              (*(undefined4 *)(iVar3 + 0x798) = 2, *(int *)(iVar3 + 0x7e8) == 0)) {
        *(undefined1 *)(iVar3 + 0x7be) = 1;
      }
    }
    piVar6 = *(int **)(this + 0x14);
    iVar3 = piVar6[1] + -1;
    iVar7 = this->i_1c;
    if (iVar3 <= this->i_1c) {
      iVar7 = iVar3;
    }
    if ((iVar7 < 0) || (piVar6[1] <= iVar7)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar3 = *piVar6;
    }
    else {
      iVar3 = iVar7 * 0x10 + *piVar6;
    }
    iVar7 = *(int *)(iVar3 + 0xc);
    local_c = iVar7;
    if (iVar7 == 0) {
      FUN_00418db0();
      iVar3 = extraout_ECX_00;
    }
    else if ((iVar7 != 1) && (iVar7 == 2)) {
      FUN_00418850();
      iVar3 = extraout_ECX;
    }
    if (this->i_2c != -1) {
      iVar4 = FUN_00422ee0(this->i_2c);
      local_14 = (float)iVar4;
      local_10 = FUN_00422fe0(this->i_2c);
      iVar3 = this->i_2c;
      local_8 = 2;
      if ((((iVar3 == 6) || (iVar3 == 8)) || (iVar3 == 0xd)) ||
         (((iVar3 == 0x10 || (iVar3 == 0x11)) || ((iVar3 == 0x14 || (iVar3 == 0x15)))))) {
        local_8 = 1;
      }
      iVar7 = local_c;
      if ((iVar4 != -1) && (local_10 != -1)) {
        iVar3 = this->i_04;
        piVar6 = (int *)(DAT_00772400 + 0x15c8);
        if (*(uint *)(iVar3 + 0xdc) < 0x2000) {
          piVar6 = piVar6 + *(uint *)(iVar3 + 0xdc);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = this->i_04;
        }
        piVar8 = (int *)(DAT_00772400 + 0x15c8);
        local_18 = *(int *)(*piVar6 + 0x38);
        if (*(uint *)(iVar3 + 0xdc) < 0x2000) {
          piVar8 = piVar8 + *(uint *)(iVar3 + 0xdc);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = this->i_04;
        }
        piVar6 = (int *)(DAT_00772400 + 0x15c8);
        local_1c = *(int *)(*piVar8 + 0x3c);
        if (*(uint *)(iVar3 + 0xdc) < 0x2000) {
          piVar6 = piVar6 + *(uint *)(iVar3 + 0xdc);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if ((((float)local_18 != local_14) || (local_1c != local_10)) ||
           (iVar3 = local_10, iVar7 = local_c, *(int *)(*piVar6 + 0x30) != local_8)) {
          FUN_005cdae0(local_14,local_10,0,local_8);
          iVar3 = extraout_ECX_01;
          iVar7 = local_c;
        }
      }
    }
    uVar5 = FUN_00419840(pfVar1,iVar3);
    switch(uVar5) {
    case 0:
      FUN_005cd7e0(pfVar1);
      FUN_005cd840(this + 0x4c);
      break;
    case 2:
      iVar3 = this->i_04;
      *pfVar1 = *(float *)(iVar3 + 0xc);
      this->i_44 = *(undefined4 *)(iVar3 + 0x10);
      this->i_48 = *(undefined4 *)(iVar3 + 0x14);
      iVar3 = this->i_04;
      this->i_4c = *(undefined4 *)(iVar3 + 0x40);
      this->i_50 = *(undefined4 *)(iVar3 + 0x44);
      this->i_54 = *(undefined4 *)(iVar3 + 0x48);
    case 1:
    case 3:
      this->i_08 = 3;
      return 0;
    }
    cVar2 = FUN_004192a0();
    if (cVar2 == '\0') {
      iVar3 = *(int *)(this->i_0c + 0x7c0);
      if (iVar3 != -1) {
        piVar6 = (int *)FUN_00407340(iVar3);
        iVar3 = *piVar6;
        if (iVar3 == 0) {
          *(undefined4 *)(this->i_0c + 0x7c0) = 0xffffffff;
        }
        else {
          local_14 = *(float *)(this->i_0c + 0x7c4);
          if (iVar7 == 0) {
            local_14 = local_14 * 0.65;
          }
          fVar9 = *(float *)(iVar3 + 0x10) - this->i_44;
          fVar11 = *(float *)(iVar3 + 0xc) - *pfVar1;
          fVar10 = (*(float *)(iVar3 + 0x14) - this->i_48) * 0.5;
          fVar9 = fVar9 * fVar9 + fVar11 * fVar11 + fVar10 * fVar10;
          FUN_0040b7e0();
          if (fVar9 <= local_14) {
            this->i_08 = 5;
            return 0;
          }
        }
      }
      return 1;
    }
    iVar3 = this->i_14;
    if (0 < *(int *)(iVar3 + 8)) {
      uVar5 = FUN_00405dd0(*(int *)(iVar3 + 8) + -1);
      FUN_005cd7e0(uVar5);
      iVar3 = this->i_14;
    }
    local_24 = *(float *)(iVar3 + 0xc);
  }
  else {
    piVar6 = *(int **)(this + 0x14);
    if (0 < piVar6[2]) {
      iVar3 = piVar6[2] + -1;
      if ((iVar3 < 0) || (piVar6[1] <= iVar3)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *piVar6;
      }
      else {
        iVar3 = iVar3 * 0x10 + *piVar6;
      }
      FUN_005cd7e0(iVar3);
    }
    local_24 = *(float *)(this->i_14 + 0xc);
  }
  if (local_24 != -1000.0) {
    local_28 = *(undefined4 *)(this->i_04 + 0x40);
    local_20 = *(undefined4 *)(this->i_04 + 0x48);
    FUN_005cd840(&local_28);
  }
  this->i_08 = 4;
  return 0;
}

