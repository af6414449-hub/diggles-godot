
void FUN_10011d90(int *param_1,int *param_2,ushort *param_3)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b81);
  if (*(char *)((int)param_2 + 0xd) != '\0') {
    if ((*(char *)(DAT_1416ee94[1] + 0xd) != '\0') ||
       (*(ushort *)(DAT_1416ee94[2] + 0xe) < *param_3)) {
      *param_1 = DAT_1416ee94[2];
      *(undefined1 *)(param_1 + 2) = 0;
      param_1[1] = 0;
      return;
    }
    goto LAB_10011f18;
  }
  uVar3 = *(ushort *)((int)param_2 + 0xe);
  uVar4 = *param_3;
  local_8 = (uint)uVar4;
  if (param_2 == (int *)*DAT_1416ee94) {
    if (uVar4 < uVar3) {
      *param_1 = (int)param_2;
      param_1[1] = 1;
      *(undefined1 *)(param_1 + 2) = 0;
      return;
    }
    goto LAB_10011f18;
  }
  if (uVar4 < uVar3) {
    piVar7 = (int *)*param_2;
    if (*(char *)((int)piVar7 + 0xd) == '\0') {
      cVar1 = *(char *)(piVar7[2] + 0xd);
      piVar6 = (int *)piVar7[2];
      while (cVar1 == '\0') {
        cVar1 = *(char *)(piVar6[2] + 0xd);
        piVar7 = piVar6;
        piVar6 = (int *)piVar6[2];
      }
    }
    else {
      cVar1 = *(char *)(param_2[1] + 0xd);
      piVar5 = (int *)param_2[1];
      piVar6 = param_2;
      while ((piVar7 = piVar5, cVar1 == '\0' && (piVar6 == (int *)*piVar7))) {
        cVar1 = *(char *)(piVar7[1] + 0xd);
        piVar5 = (int *)piVar7[1];
        piVar6 = piVar7;
      }
      if (*(char *)((int)piVar6 + 0xd) != '\0') {
        piVar7 = piVar6;
      }
    }
    if (*(ushort *)((int)piVar7 + 0xe) < uVar4) {
      cVar1 = *(char *)(piVar7[2] + 0xd);
      *(undefined1 *)(param_1 + 2) = 0;
      if (cVar1 == '\0') {
        *param_1 = (int)param_2;
        param_1[1] = 1;
        return;
      }
      *param_1 = (int)piVar7;
      param_1[1] = 0;
      return;
    }
    goto LAB_10011f18;
  }
  if (uVar4 <= uVar3) {
    *(undefined1 *)(param_1 + 2) = 1;
    goto LAB_10011f93;
  }
  piVar7 = (int *)param_2[2];
  cVar1 = *(char *)((int)piVar7 + 0xd);
  if (cVar1 == '\0') {
    cVar2 = *(char *)(*piVar7 + 0xd);
    piVar6 = (int *)*piVar7;
    while (cVar2 == '\0') {
      cVar2 = *(char *)(*piVar6 + 0xd);
      piVar7 = piVar6;
      piVar6 = (int *)*piVar6;
    }
LAB_10011f0c:
    if ((*(char *)((int)piVar7 + 0xd) == '\0') && (*(ushort *)((int)piVar7 + 0xe) <= uVar4)) {
LAB_10011f18:
      FUN_10011d30(&local_14,param_3);
      if ((*(char *)(local_c + 0xd) == '\0') && (*(ushort *)(local_c + 0xe) <= *param_3)) {
        *param_1 = local_c;
        param_1[1] = 2;
        *(undefined1 *)(param_1 + 2) = 1;
        return;
      }
      *param_1 = local_14;
      param_1[1] = local_10;
      *(undefined1 *)(param_1 + 2) = 0;
      return;
    }
  }
  else {
    piVar6 = (int *)param_2[1];
    piVar5 = param_2;
    piVar7 = piVar6;
    if (*(char *)((int)piVar6 + 0xd) == '\0') {
      do {
        piVar7 = piVar6;
        if (piVar5 != (int *)piVar6[2]) break;
        piVar7 = (int *)piVar6[1];
        piVar5 = piVar6;
        piVar6 = piVar7;
      } while (*(char *)((int)piVar7 + 0xd) == '\0');
      goto LAB_10011f0c;
    }
  }
  *(undefined1 *)(param_1 + 2) = 0;
  if (cVar1 == '\0') {
    *param_1 = (int)piVar7;
    param_1[1] = 1;
    return;
  }
LAB_10011f93:
  *param_1 = (int)param_2;
  param_1[1] = 0;
  return;
}

