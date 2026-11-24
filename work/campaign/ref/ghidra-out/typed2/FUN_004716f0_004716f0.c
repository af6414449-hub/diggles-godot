
int * FUN_004716f0(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  char local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int *local_24;
  float local_20;
  float local_1c;
  undefined4 *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fd85d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_30 = 0;
  local_2c = 0;
  fVar9 = (float)(*(double *)(DAT_00772400 + 0x282e) - *(double *)(DAT_00772400 + 0x282c)) * 10.0;
  fVar8 = 0.0;
  if (0.0 <= fVar9) {
    fVar8 = fVar9;
  }
  local_1c = 1.0;
  if (fVar8 <= 1.0) {
    local_1c = fVar8;
  }
  local_8 = 0;
  iVar4 = DAT_00772400[0x19];
  FUN_005b78b0();
  local_14 = DAT_00772400;
  piVar3 = DAT_00772400;
  if (((((char)PTR_0077241c->mapFlags != '\0') && (DAT_0076a32a != '\0')) &&
      (piVar3 = (int *)FUN_0043e3c0(), param_1 != -1)) &&
     (piVar3 = (int *)FUN_0047dae0(), piVar3[0x1d] == iVar4)) {
    iVar4 = FUN_0047dae0();
    fVar8 = *(float *)(iVar4 + 0x40);
    local_38 = *(float *)(iVar4 + 0x44);
    local_34 = *(float *)(iVar4 + 0x48);
    local_3c = fVar8;
    local_20 = local_34;
    local_18 = (undefined4 *)local_38;
    iVar4 = FUN_0047dae0();
    if (*(char *)(iVar4 + 0x85) != '\0') {
      iVar4 = FUN_0047dae0();
      local_3c = *(float *)(iVar4 + 0x90) * local_1c + fVar8;
      local_38 = *(float *)(iVar4 + 0x94) * local_1c + (float)local_18;
      local_34 = local_20 + *(float *)(iVar4 + 0x98) * local_1c;
    }
    iVar4 = FUN_0047dae0();
    local_48 = *(undefined4 *)(iVar4 + 0x9c);
    local_44 = *(undefined4 *)(iVar4 + 0xa0);
    local_40 = *(undefined4 *)(iVar4 + 0xa4);
    iVar4 = FUN_0047dae0();
    piVar3 = *(int **)(iVar4 + 0x78);
    iVar4 = FUN_0047dae0();
    iVar4 = *(int *)(iVar4 + 0x7c);
    if (((piVar3 != (int *)0xffffffff) && (iVar4 != -1)) &&
       (local_28 = iVar4, piVar3 = (int *)FUN_0040b550(), iVar4 < *(int *)(*piVar3 + 0x3c))) {
      FUN_004059a0();
      local_18 = (undefined4 *)0x0;
      local_8._0_1_ = 1;
      FUN_006b90d0(&local_24);
      local_8._0_1_ = 2;
      pfVar10 = &local_20;
      FUN_0044d010(pfVar10);
      FUN_0044d570(pfVar10);
      FUN_00409280();
      piVar3 = (int *)FUN_00406f00();
      local_8._0_1_ = 3;
      if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
        piVar3 = (int *)FUN_006ba940();
      }
      puVar2 = local_18;
      local_8._0_1_ = 1;
      if (local_18 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)FUN_0040b550();
        local_14 = (int *)*puVar5;
        FUN_00490940();
        local_8 = CONCAT31(local_8._1_3_,4);
        iVar6 = FUN_004059a0();
        iVar4 = iVar6;
        if ((*(int *)(iVar6 + 0xdc) != -1) &&
           (iVar7 = FUN_0047dae0(), *(char *)(iVar7 + 0x84) != '\0')) {
          iVar4 = FUN_004059a0();
        }
        FUN_00490a70(local_14,iVar6,iVar4,local_1c,&local_3c,&local_48);
        if (local_4c != '\0') {
          piVar3 = puVar2 + 1;
          LOCK();
          *piVar3 = *piVar3 + 1;
          UNLOCK();
          FUN_004914b0(puVar2,0x7d,param_2,0);
          LOCK();
          *piVar3 = *piVar3 + 1;
          UNLOCK();
          local_8._0_1_ = 5;
          FUN_0044d010();
          local_8 = CONCAT31(local_8._1_3_,4);
          FUN_0044d6e0();
        }
        FUN_004909f0();
        LOCK();
        piVar1 = puVar2 + 1;
        iVar4 = *piVar1;
        piVar3 = (int *)*piVar1;
        *piVar1 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          piVar3 = (int *)(**(code **)*puVar2)();
        }
      }
    }
  }
  ExceptionList = local_10;
  return piVar3;
}

