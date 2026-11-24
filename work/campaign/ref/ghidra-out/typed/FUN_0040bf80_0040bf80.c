
undefined1 __thiscall FUN_0040bf80(CAct_Climb *this)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  
  if (*(char *)(this->i_0c + 0x7b0) == '\0') {
    this->i_08 = 3;
    return 0;
  }
  piVar3 = (int *)this->i_20;
  uVar5 = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_0040be90();
    this->i_20 = (int)piVar3;
    if (piVar3 != (int *)0x0) goto LAB_0040bfb4;
    goto LAB_0040c00d;
  }
LAB_0040bfb4:
  cVar2 = (**(code **)(*piVar3 + 0xc))();
  if (cVar2 != '\0') {
    return 1;
  }
  puVar1 = (undefined4 *)this->i_20;
  switch(puVar1[2]) {
  case 0:
    this->i_08 = 0;
    break;
  default:
    goto switchD_0040bfca_caseD_1;
  case 3:
    this->i_08 = 3;
    break;
  case 4:
    this->i_08 = 4;
    goto switchD_0040bfca_caseD_1;
  case 5:
    this->i_08 = 5;
  }
  uVar5 = 0;
switchD_0040bfca_caseD_1:
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  iVar4 = FUN_0040be90();
  this->i_20 = iVar4;
  if (iVar4 == 0) {
LAB_0040c00d:
    uVar5 = 0;
  }
  return uVar5;
}

