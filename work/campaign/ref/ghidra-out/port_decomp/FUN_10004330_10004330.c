
void FUN_10004330(int *param_1,int *param_2,uint *param_3)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *in_ECX;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  piVar7 = (int *)*in_ECX;
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    if ((*(char *)(piVar7[1] + 0xd) != '\0') ||
       (uVar8 = *param_3, *(uint *)(piVar7[2] + 0x10) < uVar8)) {
      *param_1 = piVar7[2];
      *(undefined1 *)(param_1 + 2) = 0;
      param_1[1] = 0;
      return;
    }
    goto LAB_100044a9;
  }
  uVar8 = *param_3;
  uVar6 = param_2[4];
  if (param_2 == (int *)*piVar7) {
    if (uVar8 < uVar6) {
      *param_1 = (int)param_2;
      param_1[1] = 1;
      *(undefined1 *)(param_1 + 2) = 0;
      return;
    }
    goto LAB_100044a9;
  }
  if (uVar8 < uVar6) {
    piVar4 = (int *)*param_2;
    if (*(char *)((int)piVar4 + 0xd) == '\0') {
      cVar2 = *(char *)(piVar4[2] + 0xd);
      piVar5 = (int *)piVar4[2];
      while (cVar2 == '\0') {
        cVar2 = *(char *)(piVar5[2] + 0xd);
        piVar4 = piVar5;
        piVar5 = (int *)piVar5[2];
      }
    }
    else {
      cVar2 = *(char *)(param_2[1] + 0xd);
      piVar3 = (int *)param_2[1];
      piVar5 = param_2;
      while ((piVar4 = piVar3, cVar2 == '\0' && (piVar5 == (int *)*piVar4))) {
        cVar2 = *(char *)(piVar4[1] + 0xd);
        piVar3 = (int *)piVar4[1];
        piVar5 = piVar4;
      }
      if (*(char *)((int)piVar5 + 0xd) != '\0') {
        piVar4 = piVar5;
      }
    }
    if ((uint)piVar4[4] < uVar8) {
      cVar2 = *(char *)(piVar4[2] + 0xd);
      *(undefined1 *)(param_1 + 2) = 0;
      if (cVar2 == '\0') {
        *param_1 = (int)param_2;
        param_1[1] = 1;
        return;
      }
      *param_1 = (int)piVar4;
      param_1[1] = 0;
      return;
    }
    goto LAB_100044a9;
  }
  if (uVar8 <= uVar6) {
    *(undefined1 *)(param_1 + 2) = 1;
    goto LAB_10004531;
  }
  piVar4 = (int *)param_2[2];
  cVar2 = *(char *)((int)piVar4 + 0xd);
  if (cVar2 == '\0') {
    cVar1 = *(char *)(*piVar4 + 0xd);
    piVar5 = (int *)*piVar4;
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*piVar5 + 0xd);
      piVar4 = piVar5;
      piVar5 = (int *)*piVar5;
    }
LAB_1000449c:
    if ((*(char *)((int)piVar4 + 0xd) == '\0') && ((uint)piVar4[4] <= uVar8)) {
LAB_100044a9:
      piVar4 = (int *)piVar7[1];
      uVar6 = 0;
      cVar2 = *(char *)((int)piVar4 + 0xd);
      piVar5 = piVar4;
      while (piVar3 = piVar4, cVar2 == '\0') {
        if (uVar8 <= (uint)piVar3[4]) {
          piVar4 = (int *)*piVar3;
          piVar7 = piVar3;
        }
        else {
          piVar4 = (int *)piVar3[2];
        }
        uVar6 = (uint)(uVar8 <= (uint)piVar3[4]);
        cVar2 = *(char *)((int)piVar4 + 0xd);
        piVar5 = piVar3;
      }
      if ((*(char *)((int)piVar7 + 0xd) == '\0') && ((uint)piVar7[4] <= uVar8)) {
        *param_1 = (int)piVar7;
        param_1[1] = 2;
        *(undefined1 *)(param_1 + 2) = 1;
        return;
      }
      *param_1 = (int)piVar5;
      param_1[1] = uVar6;
      *(undefined1 *)(param_1 + 2) = 0;
      return;
    }
  }
  else {
    piVar5 = (int *)param_2[1];
    piVar3 = param_2;
    piVar4 = piVar5;
    if (*(char *)((int)piVar5 + 0xd) == '\0') {
      do {
        piVar4 = piVar5;
        if (piVar3 != (int *)piVar5[2]) break;
        piVar4 = (int *)piVar5[1];
        piVar3 = piVar5;
        piVar5 = piVar4;
      } while (*(char *)((int)piVar4 + 0xd) == '\0');
      goto LAB_1000449c;
    }
  }
  *(undefined1 *)(param_1 + 2) = 0;
  if (cVar2 == '\0') {
    *param_1 = (int)piVar4;
    param_1[1] = 1;
    return;
  }
LAB_10004531:
  *param_1 = (int)param_2;
  param_1[1] = 0;
  return;
}

