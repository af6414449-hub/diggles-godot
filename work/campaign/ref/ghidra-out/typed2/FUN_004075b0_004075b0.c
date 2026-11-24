
char __thiscall FUN_004075b0(CActWalk *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void **ppvVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  CActWalk_AutoRetry *this_00;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  char *pcVar12;
  float fVar13;
  float fVar14;
  float fVar15;
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
  uVar8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ppvVar5 = &local_10;
  if (this->i_20 == 0) {
    iVar2 = this->i_1c;
    if ((*(int *)(iVar2 + 0x7b4) == 0) &&
       ((((*(float *)(iVar2 + 0x7a4) < PTR_0077241c->x0f + 2.0 ||
          (PTR_0077241c->x1f - 2.0 <= *(float *)(iVar2 + 0x7a4))) ||
         (*(float *)(iVar2 + 0x7a8) < PTR_0077241c->y0f + 2.0)) ||
        (PTR_0077241c->y1f - 2.0 <= *(float *)(iVar2 + 0x7a8))))) {
      this->i_24 = 3;
      *(undefined4 *)(this->i_0c + 0x248) = 3;
      return '\0';
    }
    ExceptionList = &local_10;
    this_00 = (CActWalk_AutoRetry *)FUN_006ba810(0x6d,uVar8);
    if (this_00 == (CActWalk_AutoRetry *)0x0) {
      this_00 = (CActWalk_AutoRetry *)0x0;
    }
    else {
      this_00->i_0c = 0;
      *(undefined4 *)&this_00->field_0x10 = 0;
      *(undefined ***)this_00 = CActWalk_AutoRetry::vftable;
      *(undefined4 *)&this_00->field_0x1c = 0;
      *(undefined4 *)&this_00->field_0x18 = 0;
      *(undefined4 *)&this_00->field_0x14 = 0;
      this_00->i_20 = 0;
    }
    piVar11 = (int *)this->i_1c;
    this->i_20 = (int)this_00;
    if (piVar11 != (int *)0x0) {
      LOCK();
      piVar11[1] = piVar11[1] + 1;
      UNLOCK();
      this_00 = (CActWalk_AutoRetry *)this->i_20;
    }
    local_8 = 0;
    if (piVar11 != (int *)0x0) {
      LOCK();
      piVar11[1] = piVar11[1] + 1;
      UNLOCK();
    }
    local_1c = piVar11;
    FUN_0041fe30(this_00);
    *(undefined4 *)&this_00->field_0x14 = 0xc47a0000;
    *(undefined4 *)&this_00->field_0x18 = 0xc47a0000;
    *(undefined4 *)&this_00->field_0x1c = 0xc47a0000;
    FUN_00407fb0();
    local_8 = 0xffffffff;
    ppvVar5 = (void **)ExceptionList;
    if (piVar11 != (int *)0x0) {
      LOCK();
      iVar2 = piVar11[1] + -1;
      piVar11[1] = iVar2;
      UNLOCK();
      ppvVar5 = (void **)ExceptionList;
      if (iVar2 == 0) {
        (**(code **)*piVar11)(1);
        ppvVar5 = (void **)ExceptionList;
      }
    }
  }
  ExceptionList = ppvVar5;
  cVar6 = (**(code **)(*(int *)this->i_20 + 0xc))();
  if (cVar6 == '\0') {
    *(undefined1 *)(this->i_0c + 0x2b4) = 0;
    iVar2 = *(int *)(this->i_20 + 8);
    this->i_24 = iVar2;
    *(int *)(this->i_0c + 0x248) = iVar2;
    if ((undefined4 *)this->i_20 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)this->i_20)(1);
    }
    iVar2 = this->i_1c;
    iVar3 = this->i_24;
    this->i_20 = 0;
    this->i_18 = iVar3;
    if ((1.0 < *(float *)(iVar2 + 0x7a4)) && (fVar1 = *(float *)(iVar2 + 0x7a8), 1.0 < fVar1)) {
      iVar4 = this->i_0c;
      fVar14 = *(float *)(iVar4 + 0xc) - *(float *)(iVar2 + 0x7a4);
      fVar13 = *(float *)(iVar4 + 0x14) - *(float *)(iVar2 + 0x7ac);
      fVar15 = *(float *)(iVar4 + 0x10) - fVar1;
      fVar13 = fVar15 * fVar15 + fVar14 * fVar14 + fVar13 * fVar13;
      if ((((0.0625 < fVar13) && ((iVar3 != 3 && (iVar3 != 5)))) &&
          (*(char *)(iVar2 + 0x7bc) == '\0')) &&
         ((2.25 < fVar13 && (*(char *)(iVar2 + 0x7bf) != '\0')))) {
        local_1c = (int *)0x0;
        local_14 = (int *)0x0;
        DAT_00772dd8 = (int)ROUND(*(float *)(this->i_1c + 0x7a4) * 8.0);
        local_18 = DAT_00772dd8;
        uVar9 = FUN_00407e70(DAT_00772dd8,(int)ROUND(fVar1 * 8.0));
        if (((uVar9 & 2) == 0) &&
           (uVar9 = FUN_00407e70(local_18,(int)ROUND(fVar1 * 8.0) + -1), (uVar9 & 2) == 0)) {
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
    local_14 = (int *)FUN_006ba810(0x19,uVar8);
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
  piVar11 = (int *)(this->i_1c + 0x7e4);
  *piVar11 = *piVar11 + 1;
  iVar2 = *(int *)(this->i_1c + 0x7e0);
  if ((iVar2 != -1) && ((*(int *)(this->i_1c + 0x7e4) % iVar2 == 0 || (cVar6 == '\0')))) {
    *(undefined1 *)(this->i_0c + 0x400) = 1;
    cVar7 = FUN_00555a00(this->i_1c + 0x7ec);
    if (cVar7 == '\0') {
      *(undefined4 *)(this->i_1c + 0x7e0) = 0xffffffff;
    }
    *(undefined1 *)(this->i_0c + 0x400) = 0;
    puVar10 = (undefined4 *)FUN_005c9cc0();
    piVar11 = (int *)Tcl_GetObjResult(*puVar10);
    local_1c = piVar11;
    if (piVar11 == (int *)0x0) {
      cVar7 = '\0';
    }
    else {
      *piVar11 = *piVar11 + 1;
      pcVar12 = (char *)Tcl_GetStringFromObj(piVar11,0);
      if ((pcVar12 == (char *)0x0) || (cVar7 = *pcVar12, cVar7 == '1')) {
        *piVar11 = *piVar11 + -1;
        if (0 < *piVar11) {
          ExceptionList = local_10;
          return cVar6;
        }
        TclFreeObj(piVar11);
        ExceptionList = local_10;
        return cVar6;
      }
    }
    if (cVar7 != '0') {
      FUN_006baea0(&local_1c);
    }
    this->i_24 = 5;
    *(undefined4 *)(this->i_0c + 0x248) = 5;
    if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
      TclFreeObj(piVar11);
    }
    ExceptionList = local_10;
    return '\0';
  }
  ExceptionList = local_10;
  return cVar6;
}

