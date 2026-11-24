
void FUN_00508f00(int *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int this;
  char *pcVar7;
  int iVar8;
  double *pdVar9;
  int *piStack_44;
  int iStack_40;
  int iStack_3c;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  int *local_28;
  int local_24;
  uint local_20;
  int local_1c;
  undefined1 local_18;
  undefined2 local_17;
  undefined1 local_15;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701085;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = this->i_10;
  iVar8 = this->i_18;
  iVar2 = this->i_14;
  local_1c = this->i_0c;
  iVar4 = (iVar2 - local_1c) + -0x14;
  iVar5 = (iVar8 - local_20) + -0x14;
  local_28 = (int *)(this + 0x80);
  if ((iVar4 != this->i_e8) || (iVar5 != this->i_ec)) {
    this->i_e8 = iVar4;
    this->i_ec = iVar5;
    this->c_f8 = 1;
  }
  local_24 = iVar8;
  local_14 = this;
  FUN_004df230(uVar3);
  FUN_00504fd0(param_1);
  local_24 = *(int *)(local_14 + 0x84);
  local_30 = FUN_00501450();
  local_30 = local_30 + 0x81ac;
  iStack_3c = iVar8 + -10;
  iStack_40 = iVar2 + -10;
  piStack_44 = (int *)(local_20 + 10);
  iVar5 = *param_1;
  *(int *)(iVar5 + 0xc) = local_1c + 10;
  *(int **)(iVar5 + 0x10) = piStack_44;
  *(int *)(iVar5 + 0x14) = iStack_40;
  *(int *)(iVar5 + 0x18) = iStack_3c;
  local_20 = 0;
  if (0 < local_24) {
    local_1c = 0;
    do {
      iVar5 = local_1c;
      piVar6 = local_28;
      if ((uint)local_28[1] <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      pdVar9 = (double *)(*piVar6 + iVar5);
      if (*(int *)((int)pdVar9 + 0x34) == 0) {
        iVar8 = *(int *)(pdVar9 + 6);
        if (*(int *)(iVar8 + 8) == -1) {
          pcVar7 = (char *)(iVar8 + 0xc);
          local_2c = (int *)(iVar8 + 0xd);
          do {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          *(int *)(iVar8 + 8) = (int)pcVar7 - (int)local_2c;
          iVar8 = *(int *)(pdVar9 + 6);
        }
        if (0 < *(int *)(iVar8 + 8)) {
          iVar5 = *(int *)(pdVar9 + 7);
          if (4 < iVar5) {
            iVar5 = 4;
          }
          if (iVar5 < 0) {
            iVar5 = 0;
          }
          FUN_004ef7b0(local_14 + (iVar5 * 3 + 0x11) * 4);
          local_8 = 0;
          iVar5 = *(int *)(pdVar9 + 6);
          local_17 = 0xffff;
          local_18 = 0xff;
          local_15 = 0xff;
          piVar6 = (int *)FUN_004ef240();
          if (iStack_3c == *piVar6) {
            if (iStack_40 == 0) goto LAB_005090b2;
          }
          else {
            iStack_40 = 0;
            iStack_3c = *piVar6;
LAB_005090b2:
            iStack_40 = FUN_004ef660(piStack_44 + 3);
          }
          local_34 = (int)pdVar9[1] + *(int *)(iStack_40 + 0x200) + 10;
          local_38 = (int)*pdVar9 + 10;
          FUN_004fdff0(&local_38,iVar5 + 0xc,&local_18,&piStack_44,0,local_34);
          local_8 = 1;
          if ((piStack_44 != (int *)0x0) && (*piStack_44 = *piStack_44 + -1, *piStack_44 == 0)) {
            FUN_006ba940();
          }
          local_8 = 0xffffffff;
          iVar5 = local_1c;
        }
      }
      if ((*(uint *)((int)pdVar9 + 0x34) & 0x8000038) != 0) {
        piVar6 = *(int **)(pdVar9 + 6);
        if (piVar6 != (int *)0x0) {
          *piVar6 = *piVar6 + 1;
        }
        local_8 = 2;
        local_2c = piVar6;
        local_2c = (int *)FUN_004e6fe0(piVar6 + 3);
        if (local_2c != (undefined4 *)0x0) {
          FUN_004ff900(local_2c,(int)*pdVar9 + param_1[2] + 10,param_1[3] + 10 + (int)pdVar9[1],
                       *local_2c,local_2c[1],0,0,0);
        }
        local_8 = 3;
        if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
          FUN_006ba940();
        }
        local_8 = 0xffffffff;
        iVar5 = local_1c;
      }
      local_1c = iVar5 + 0x40;
      local_20 = local_20 + 1;
    } while ((int)local_20 < local_24);
  }
  ExceptionList = local_10;
  return;
}

