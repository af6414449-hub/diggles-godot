
char FUN_004075b0(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  void **ppvVar6;
  char cVar7;
  char cVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  char *pcVar13;
  int this;
  float fVar14;
  float fVar15;
  float fVar16;
  float local_28;
  float local_24;
  float local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f96b5;
  local_10 = ExceptionList;
  uVar9 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ppvVar6 = &local_10;
  if (this->i_20 == 0) {
    iVar2 = this->i_1c;
    if ((*(int *)(iVar2 + 0x7b4) == 0) &&
       ((((*(float *)(iVar2 + 0x7a4) < *(float *)(DAT_0077241c + 0xa4) + 2.0 ||
          (*(float *)(DAT_0077241c + 0xac) - 2.0 <= *(float *)(iVar2 + 0x7a4))) ||
         (*(float *)(iVar2 + 0x7a8) < *(float *)(DAT_0077241c + 0xa8) + 2.0)) ||
        (*(float *)(DAT_0077241c + 0xb0) - 2.0 <= *(float *)(iVar2 + 0x7a8))))) {
      this->i_24 = 3;
      *(undefined4 *)(this->i_0c + 0x248) = 3;
      return '\0';
    }
    ExceptionList = &local_10;
    puVar10 = (undefined4 *)FUN_006ba810(0x6d,uVar9);
    if (puVar10 == (undefined4 *)0x0) {
      puVar10 = (undefined4 *)0x0;
    }
    else {
      puVar10[3] = 0;
      puVar10[4] = 0;
      *puVar10 = CActWalk_AutoRetry::vftable;
      puVar10[7] = 0;
      puVar10[6] = 0;
      puVar10[5] = 0;
      puVar10[8] = 0;
    }
    piVar12 = *(int **)(this + 0x1c);
    uVar3 = this->i_0c;
    *(undefined4 **)(this + 0x20) = puVar10;
    if (piVar12 != (int *)0x0) {
      LOCK();
      piVar12[1] = piVar12[1] + 1;
      UNLOCK();
      puVar10 = *(undefined4 **)(this + 0x20);
    }
    local_8 = 0;
    if (piVar12 != (int *)0x0) {
      LOCK();
      piVar12[1] = piVar12[1] + 1;
      UNLOCK();
    }
    local_1c = piVar12;
    FUN_0041fe30(piVar12,uVar3,0);
    puVar10[5] = 0xc47a0000;
    puVar10[6] = 0xc47a0000;
    puVar10[7] = 0xc47a0000;
    FUN_00407fb0();
    local_8 = 0xffffffff;
    ppvVar6 = (void **)ExceptionList;
    if (piVar12 != (int *)0x0) {
      LOCK();
      iVar2 = piVar12[1] + -1;
      piVar12[1] = iVar2;
      UNLOCK();
      ppvVar6 = (void **)ExceptionList;
      if (iVar2 == 0) {
        (**(code **)*piVar12)(1);
        ppvVar6 = (void **)ExceptionList;
      }
    }
  }
  ExceptionList = ppvVar6;
  cVar7 = (**(code **)(**(int **)(this + 0x20) + 0xc))();
  if (cVar7 == '\0') {
    *(undefined1 *)(this->i_0c + 0x2b4) = 0;
    uVar3 = *(undefined4 *)(this->i_20 + 8);
    this->i_24 = uVar3;
    *(undefined4 *)(this->i_0c + 0x248) = uVar3;
    if (*(undefined4 **)(this + 0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(this + 0x20))(1);
    }
    iVar2 = this->i_1c;
    iVar4 = this->i_24;
    this->i_20 = 0;
    this->i_18 = iVar4;
    if ((1.0 < *(float *)(iVar2 + 0x7a4)) && (fVar1 = *(float *)(iVar2 + 0x7a8), 1.0 < fVar1)) {
      iVar5 = this->i_0c;
      fVar15 = *(float *)(iVar5 + 0xc) - *(float *)(iVar2 + 0x7a4);
      fVar14 = *(float *)(iVar5 + 0x14) - *(float *)(iVar2 + 0x7ac);
      fVar16 = *(float *)(iVar5 + 0x10) - fVar1;
      fVar14 = fVar16 * fVar16 + fVar15 * fVar15 + fVar14 * fVar14;
      if ((((0.0625 < fVar14) && ((iVar4 != 3 && (iVar4 != 5)))) &&
          (*(char *)(iVar2 + 0x7bc) == '\0')) &&
         ((2.25 < fVar14 && (*(char *)(iVar2 + 0x7bf) != '\0')))) {
        local_1c = (int *)0x0;
        local_14 = (int *)0x0;
        DAT_00772dd8 = (int)ROUND(*(float *)(this->i_1c + 0x7a4) * 8.0);
        local_18 = DAT_00772dd8;
        uVar11 = FUN_00407e70(DAT_00772dd8,(int)ROUND(fVar1 * 8.0));
        if (((uVar11 & 2) == 0) &&
           (uVar11 = FUN_00407e70(local_18,(int)ROUND(fVar1 * 8.0) + -1), (uVar11 & 2) == 0)) {
          local_14 = (int *)0x3f800000;
          local_28 = 0.0;
          local_24 = 3.1415927;
          local_20 = 0.0;
          FUN_005cd840(&local_28);
        }
        iVar2 = this->i_1c;
        local_28 = *(float *)(iVar2 + 0x7a4) + (float)local_1c;
        local_24 = *(float *)(iVar2 + 0x7a8) + (float)local_1c;
        local_20 = *(float *)(iVar2 + 0x7ac) + (float)local_14;
        FUN_005cd7e0(&local_28);
      }
    }
    local_14 = (int *)FUN_006ba810(0x19,uVar9);
    local_14[1] = 0x14;
    local_14[2] = -1;
    *(undefined1 *)(local_14 + 3) = 0;
    *local_14 = 1;
    local_8 = 1;
    switch(this->i_24) {
    case 0:
      FUN_006b9200("WS_ERROR");
      break;
    case 1:
      FUN_006b9200("WS_WALKABORTED");
      break;
    case 2:
      FUN_006b9200("WS_NOTFINISHED");
      break;
    case 3:
      FUN_006b9200("WS_NOPASSAGE");
      break;
    case 4:
      FUN_006b9200("WS_TARGETREACHED");
      break;
    case 5:
      FUN_006b9200("WS_WALKEVENT");
      break;
    default:
      FUN_006b9040(&local_14,"UNKNOWN RESULT (%d)",this->i_24);
    }
    local_8 = 2;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
  }
  piVar12 = (int *)(this->i_1c + 0x7e4);
  *piVar12 = *piVar12 + 1;
  iVar2 = *(int *)(this->i_1c + 0x7e0);
  if ((iVar2 != -1) && ((*(int *)(this->i_1c + 0x7e4) % iVar2 == 0 || (cVar7 == '\0')))
     ) {
    *(undefined1 *)(this->i_0c + 0x400) = 1;
    cVar8 = FUN_00555a00(this->i_1c + 0x7ec);
    if (cVar8 == '\0') {
      *(undefined4 *)(this->i_1c + 0x7e0) = 0xffffffff;
    }
    *(undefined1 *)(this->i_0c + 0x400) = 0;
    puVar10 = (undefined4 *)FUN_005c9cc0();
    piVar12 = (int *)Tcl_GetObjResult(*puVar10);
    local_1c = piVar12;
    if (piVar12 == (int *)0x0) {
      cVar8 = '\0';
    }
    else {
      *piVar12 = *piVar12 + 1;
      pcVar13 = (char *)Tcl_GetStringFromObj(piVar12,0);
      if ((pcVar13 == (char *)0x0) || (cVar8 = *pcVar13, cVar8 == '1')) {
        *piVar12 = *piVar12 + -1;
        if (0 < *piVar12) {
          ExceptionList = local_10;
          return cVar7;
        }
        TclFreeObj(piVar12);
        ExceptionList = local_10;
        return cVar7;
      }
    }
    if (cVar8 != '0') {
      FUN_006baea0(&local_1c);
    }
    this->i_24 = 5;
    *(undefined4 *)(this->i_0c + 0x248) = 5;
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    ExceptionList = local_10;
    return '\0';
  }
  ExceptionList = local_10;
  return cVar7;
}

