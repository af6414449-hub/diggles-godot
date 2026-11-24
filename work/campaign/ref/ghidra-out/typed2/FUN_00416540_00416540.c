
undefined1 __thiscall FUN_00416540(CAct_MetaWalk *this)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  
  uVar6 = 1;
  piVar3 = (int *)this->i_14;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)FUN_004163a0();
    this->i_14 = (int)piVar3;
    if (piVar3 == (int *)0x0) {
      return 0;
    }
  }
  cVar2 = (**(code **)(*piVar3 + 0xc))();
  if (cVar2 == '\0') {
    puVar1 = (undefined4 *)this->i_14;
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
    if (puVar1[2] == 4) {
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      iVar4 = FUN_004163a0();
      this->i_14 = iVar4;
      uVar5 = 0;
      if (iVar4 != 0) {
        uVar5 = uVar6;
      }
      return uVar5;
    }
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    this->i_14 = 0;
  }
  return uVar6;
}

