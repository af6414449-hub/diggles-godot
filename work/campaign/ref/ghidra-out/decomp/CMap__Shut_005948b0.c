
void CMap__Shut(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  int *piVar7;
  undefined8 uVar8;
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
     (FUN_006cebf4(&DAT_00ca54e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca54e0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca54e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "CMap::Shut";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54e0);
  }
  iVar5 = DAT_00ca54e4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca54e4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  if (DAT_0077244c != 0) {
    FUN_005641c0(2,2);
  }
  if (DAT_00772340 != 0) {
    uVar6 = 0;
    piVar7 = in_ECX + 0x14;
    do {
      if (uVar6 < 8) {
        piVar3 = piVar7 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar3 = piVar7;
      }
      iVar2 = *piVar3;
      FUN_00492250(iVar2);
      FUN_004957e0(iVar2);
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 8);
    uVar6 = 0;
    do {
      if (uVar6 < 8) {
        piVar3 = piVar7 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar3 = piVar7;
      }
      uVar6 = uVar6 + 1;
      *piVar3 = -1;
    } while ((int)uVar6 < 8);
  }
  if (in_ECX[5] != 0) {
    piVar7 = (int *)*in_ECX;
    if (piVar7 == (int *)0x0) {
LAB_00594a17:
      FUN_006b8c20();
    }
    else {
      do {
        uVar6 = piVar7[1];
        uVar4 = uVar6 | 2;
        piVar7[1] = uVar4;
        if ((code *)piVar7[3] != (code *)0x0) {
          (*(code *)piVar7[3])(piVar7,uVar4,uVar6);
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
      if (in_ECX[5] != 0) goto LAB_00594a17;
    }
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[0x21] = 0;
    in_ECX[0x22] = 0;
    in_ECX[0x23] = 0;
    in_ECX[0x24] = 0;
    in_ECX[0x25] = 0;
    in_ECX[0x26] = 0;
    in_ECX[0x27] = 0;
    in_ECX[0x28] = 0;
  }
  if ((in_ECX[9] != 0) && (param_1 != '\0')) {
    FUN_00593e10(in_ECX[9]);
    in_ECX[9] = 0;
  }
  iVar2 = FUN_004459b0();
  iStack_18 = *(int *)(iVar2 + 0x11c);
  iStack_1c = *(int *)(iVar2 + 0x118);
  *(undefined4 *)(iVar2 + 0x110) = 0;
  *(undefined4 *)(iVar2 + 0x114) = 0;
  if ((((-1 < iStack_18) && (*(int *)(iVar2 + 0x124) < 1)) &&
      ((*(int *)(iVar2 + 0x124) < 0 || (*(int *)(iVar2 + 0x120) == 0)))) &&
     (*(char *)(iVar2 + 0x128) != '\0')) goto LAB_00594b2d;
  if (*(char *)(iVar2 + 0x128) == '\0') {
    *(undefined4 *)(iVar2 + 0x120) = 0;
    *(undefined4 *)(iVar2 + 0x124) = 0;
    *(undefined1 *)(iVar2 + 0x128) = 1;
LAB_00594af5:
    iStack_18 = 0;
    iStack_1c = 0;
  }
  else if ((iStack_18 < 0) || ((iStack_18 < 1 && (iStack_1c == 0)))) goto LAB_00594af5;
  *(int *)(iVar2 + 0x11c) = iStack_18;
  iStack_18 = *(int *)(iVar2 + 0x124);
  *(int *)(iVar2 + 0x118) = iStack_1c;
  iStack_1c = *(undefined4 *)(iVar2 + 0x120);
  if ((0 < iStack_18) || (-1 < iStack_18)) {
    iStack_18 = 0;
    iStack_1c = 0;
  }
  *(int *)(iVar2 + 0x120) = iStack_1c;
  *(int *)(iVar2 + 0x124) = iStack_18;
LAB_00594b2d:
  FUN_005a9090();
  FUN_005a7dc0();
  *(undefined1 *)((int)in_ECX + 0x29) = 0;
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

