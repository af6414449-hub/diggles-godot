
undefined4 * FUN_100134a0(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  char cVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *in_ECX;
  int *piVar10;
  undefined4 in_EDX;
  int *piVar11;
  int *piVar12;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042715;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170680,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  local_18 = (int *)*in_ECX;
  local_14 = 0;
  piVar11 = (int *)local_18[1];
  cVar6 = *(char *)((int)piVar11 + 0xd);
  piVar12 = piVar11;
  while (piVar8 = piVar11, cVar6 == '\0') {
    uVar1 = piVar8[8];
    uVar2 = *(uint *)(param_2 + 0x10);
    uVar7 = uVar1;
    if (uVar2 < uVar1) {
      uVar7 = uVar2;
    }
    uVar7 = FUN_10003ee0(uVar7);
    if (uVar7 == 0) {
      if (uVar1 < uVar2) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = (uint)(uVar2 < uVar1);
      }
    }
    if ((int)uVar7 < 0) {
      piVar11 = (int *)piVar8[2];
    }
    else {
      piVar11 = (int *)*piVar8;
      local_18 = piVar8;
    }
    local_14 = uVar7 >> 0x1f ^ 1;
    cVar6 = *(char *)((int)piVar11 + 0xd);
    piVar12 = piVar8;
  }
  if ((*(char *)((int)local_18 + 0xd) == '\0') &&
     (cVar6 = FUN_10013a60(param_2,local_18 + 4), cVar6 == '\0')) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = local_18;
    ExceptionList = local_10;
    return param_1;
  }
  if (in_ECX[1] == 0x5d1745d) {
    FUN_10002ad0();
    pcVar5 = (code *)swi(3);
    puVar9 = (undefined4 *)(*pcVar5)();
    return puVar9;
  }
  iVar3 = *in_ECX;
  local_8 = 0;
  piVar8 = (int *)FUN_1003ff62(0x2c);
  local_8 = 1;
  FUN_10008a90(param_2);
  piVar8[10] = 0;
  *piVar8 = iVar3;
  piVar8[1] = iVar3;
  piVar8[2] = iVar3;
  *(undefined2 *)(piVar8 + 3) = 0;
  piVar11 = (int *)*in_ECX;
  in_ECX[1] = in_ECX[1] + 1;
  piVar8[1] = (int)piVar12;
  if (piVar12 == piVar11) {
    *piVar11 = (int)piVar8;
    piVar11[1] = (int)piVar8;
    piVar11[2] = (int)piVar8;
    *(undefined1 *)(piVar8 + 3) = 1;
  }
  else {
    if (local_14 == 0) {
      piVar12[2] = (int)piVar8;
      if (piVar12 == (int *)piVar11[2]) {
        piVar11[2] = (int)piVar8;
      }
    }
    else {
      *piVar12 = (int)piVar8;
      if (piVar12 == (int *)*piVar11) {
        *piVar11 = (int)piVar8;
      }
    }
    cVar6 = *(char *)(piVar8[1] + 0xc);
    piVar12 = piVar8;
    while (cVar6 == '\0') {
      piVar4 = (int *)piVar12[1];
      piVar10 = *(int **)piVar4[1];
      if (piVar4 == piVar10) {
        piVar10 = (int *)((undefined4 *)piVar4[1])[2];
        if ((char)piVar10[3] == '\0') {
LAB_1001369b:
          *(undefined1 *)(piVar4 + 3) = 1;
          *(undefined1 *)(piVar10 + 3) = 1;
          *(undefined1 *)(*(int *)(piVar12[1] + 4) + 0xc) = 0;
          piVar12 = *(int **)(piVar12[1] + 4);
        }
        else {
          if (piVar12 == (int *)piVar4[2]) {
            FUN_10004000(piVar4);
            piVar12 = piVar4;
          }
          *(undefined1 *)(piVar12[1] + 0xc) = 1;
          *(undefined1 *)(*(int *)(piVar12[1] + 4) + 0xc) = 0;
          FUN_10003f90(*(undefined4 *)(piVar12[1] + 4));
        }
      }
      else {
        if ((char)piVar10[3] == '\0') goto LAB_1001369b;
        if (piVar12 == (int *)*piVar4) {
          FUN_10003f90(piVar4);
          piVar12 = piVar4;
        }
        *(undefined1 *)(piVar12[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar12[1] + 4) + 0xc) = 0;
        FUN_10004000(*(undefined4 *)(piVar12[1] + 4));
      }
      cVar6 = *(char *)(piVar12[1] + 0xc);
    }
    *(undefined1 *)(piVar11[1] + 0xc) = 1;
  }
  *param_1 = piVar8;
  *(undefined1 *)(param_1 + 1) = 1;
  ExceptionList = local_10;
  return param_1;
}

