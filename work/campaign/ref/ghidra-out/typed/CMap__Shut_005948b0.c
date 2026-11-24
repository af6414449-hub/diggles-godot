
void __thiscall CMap__Shut(CMap *this)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  char in_stack_00000004;
  undefined4 uVar9;
  int iStack_1c;
  int iStack_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706a0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54e0) &&
     (FUN_006cebf4(&DAT_00ca54e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca54e0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca54e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "CMap::Shut";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54e0);
  }
  iVar4 = DAT_00ca54e4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca54e4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar9;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  if (DAT_0077244c != 0) {
    FUN_005641c0(2,2);
  }
  if (DAT_00772340 != 0) {
    uVar5 = 0;
    puVar7 = &this->field_0x50;
    do {
      if (uVar5 < 8) {
        puVar2 = (undefined4 *)(puVar7 + uVar5 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar2 = (undefined4 *)puVar7;
      }
      uVar9 = *puVar2;
      FUN_00492250(uVar9);
      FUN_004957e0(uVar9);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
    uVar5 = 0;
    do {
      if (uVar5 < 8) {
        puVar2 = (undefined4 *)(puVar7 + uVar5 * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar2 = (undefined4 *)puVar7;
      }
      uVar5 = uVar5 + 1;
      *puVar2 = 0xffffffff;
    } while ((int)uVar5 < 8);
  }
  if (*(int *)&this->field_0x14 != 0) {
    piVar6 = *(int **)this;
    if (piVar6 == (int *)0x0) {
LAB_00594a17:
      FUN_006b8c20();
    }
    else {
      do {
        uVar5 = piVar6[1];
        uVar3 = uVar5 | 2;
        piVar6[1] = uVar3;
        if ((code *)piVar6[3] != (code *)0x0) {
          (*(code *)piVar6[3])(piVar6,uVar3,uVar5);
        }
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
      if (*(int *)&this->field_0x14 != 0) goto LAB_00594a17;
    }
    *(undefined4 *)&this->field_0x14 = 0;
    *(undefined4 *)&this->field_0x18 = 0;
    *(undefined4 *)(this + 1) = 0;
    *(undefined4 *)&this[1].field_0x4 = 0;
    *(undefined4 *)&this[1].field_0x8 = 0;
    *(undefined4 *)&this[1].field_0xc = 0;
    *(undefined4 *)&this[1].field_0x10 = 0;
    *(undefined4 *)&this[1].field_0x14 = 0;
    *(undefined4 *)&this[1].field_0x18 = 0;
    *(undefined4 *)&this[1].field_0x1c = 0;
  }
  if ((this->i_24 != 0) && (in_stack_00000004 != '\0')) {
    FUN_00593e10(this->i_24);
    this->i_24 = 0;
  }
  iVar1 = FUN_004459b0();
  iStack_18 = *(int *)(iVar1 + 0x11c);
  iStack_1c = *(int *)(iVar1 + 0x118);
  *(undefined4 *)(iVar1 + 0x110) = 0;
  *(undefined4 *)(iVar1 + 0x114) = 0;
  if ((((-1 < iStack_18) && (*(int *)(iVar1 + 0x124) < 1)) &&
      ((*(int *)(iVar1 + 0x124) < 0 || (*(int *)(iVar1 + 0x120) == 0)))) &&
     (*(char *)(iVar1 + 0x128) != '\0')) goto LAB_00594b2d;
  if (*(char *)(iVar1 + 0x128) == '\0') {
    *(undefined4 *)(iVar1 + 0x120) = 0;
    *(undefined4 *)(iVar1 + 0x124) = 0;
    *(undefined1 *)(iVar1 + 0x128) = 1;
LAB_00594af5:
    iStack_18 = 0;
    iStack_1c = 0;
  }
  else if ((iStack_18 < 0) || ((iStack_18 < 1 && (iStack_1c == 0)))) goto LAB_00594af5;
  *(int *)(iVar1 + 0x11c) = iStack_18;
  iStack_18 = *(int *)(iVar1 + 0x124);
  *(int *)(iVar1 + 0x118) = iStack_1c;
  iStack_1c = *(undefined4 *)(iVar1 + 0x120);
  if ((0 < iStack_18) || (-1 < iStack_18)) {
    iStack_18 = 0;
    iStack_1c = 0;
  }
  *(int *)(iVar1 + 0x120) = iStack_1c;
  *(int *)(iVar1 + 0x124) = iStack_18;
LAB_00594b2d:
  FUN_005a9090();
  FUN_005a7dc0();
  this->field_0x29 = 0;
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

