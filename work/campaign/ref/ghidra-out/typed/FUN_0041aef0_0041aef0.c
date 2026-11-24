
undefined1 __thiscall FUN_0041aef0(CAct_WalkFloor *this)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined1 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  uVar6 = 1;
  piVar4 = (int *)this->i_18;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)FUN_0041aac0();
    this->i_18 = (int)piVar4;
    if (piVar4 != (int *)0x0) goto LAB_0041af0d;
  }
  else {
LAB_0041af0d:
    cVar3 = (**(code **)(*piVar4 + 0xc))();
    if (cVar3 != '\0') goto LAB_0041af63;
    puVar1 = (undefined4 *)this->i_18;
    uVar6 = 1;
    switch(puVar1[2]) {
    case 0:
      uVar6 = 0;
    default:
      this->i_08 = 0;
      break;
    case 3:
      this->i_08 = 3;
      uVar6 = 0;
      break;
    case 4:
      break;
    case 5:
      this->i_08 = 5;
      uVar6 = 0;
    }
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    iVar5 = FUN_0041aac0();
    this->i_18 = iVar5;
    if (iVar5 != 0) goto LAB_0041af63;
  }
  uVar6 = 0;
LAB_0041af63:
  iVar5 = this->i_0c;
  if (((*(int *)(iVar5 + 0x7b4) == 0) && (0.0 <= *(float *)(iVar5 + 0x7c8))) &&
     (iVar2 = this->i_04, fVar9 = *(float *)(iVar2 + 0x10) - *(float *)(iVar5 + 0x7a8),
     fVar8 = *(float *)(iVar2 + 0xc) - *(float *)(iVar5 + 0x7a4),
     fVar7 = (*(float *)(iVar2 + 0x14) - *(float *)(iVar5 + 0x7ac)) * 0.5,
     fVar9 * fVar9 + fVar8 * fVar8 + fVar7 * fVar7 < *(float *)(iVar5 + 0x7c8))) {
    this->i_08 = 5;
    return 0;
  }
  return uVar6;
}

