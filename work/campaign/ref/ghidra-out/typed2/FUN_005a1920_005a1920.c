
void FUN_005a1920(undefined4 *param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *piVar6;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int local_1c;
  int *local_14;
  int *local_10;
  
  piVar5 = (int *)in_ECX[3];
  *in_ECX = 0;
  if (piVar5[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar5 = (int *)*piVar5;
  *piVar5 = param_2;
  piVar5[1] = param_3;
  iVar7 = (DAT_00b9bf20 * param_3 + param_2) % DAT_00b9bf28;
  if ((iVar7 < 0) || (DAT_00b9bf1c <= iVar7)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar5 = DAT_00b9bf18;
  }
  else {
    piVar5 = DAT_00b9bf18 + iVar7;
  }
  iVar7 = FUN_0059a8b0(param_2,param_3,param_2,param_3,param_3);
  *piVar5 = iVar7;
  in_ECX[1] = 1;
  iVar7 = *(int *)(in_ECX[3] + 8);
  if (iVar7 <= param_4) {
    *(int *)(in_ECX[3] + 8) = iVar7 + param_4 + 1;
    uVar1 = *(undefined4 *)(in_ECX[3] + 8);
    uVar2 = FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathFinder_Random.cpp",0x215);
    puVar9 = (undefined4 *)in_ECX[3];
    *puVar9 = uVar2;
    puVar9[1] = uVar1;
  }
  do {
    iVar7 = *in_ECX;
    piVar5 = (int *)in_ECX[3];
    if ((iVar7 < 0) || (piVar5[1] <= iVar7)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = (int *)*piVar5;
      iVar7 = *in_ECX;
      piVar5 = (int *)in_ECX[3];
      local_1c = *piVar6;
      if (-1 < iVar7) goto LAB_005a1a37;
LAB_005a1a43:
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar8 = *piVar5;
      iVar7 = *in_ECX;
      piVar5 = (int *)in_ECX[3];
    }
    else {
      local_1c = *(int *)(*piVar5 + iVar7 * 8);
LAB_005a1a37:
      if (piVar5[1] <= iVar7) goto LAB_005a1a43;
      iVar8 = *piVar5 + iVar7 * 8;
    }
    iVar8 = *(int *)(iVar8 + 4);
    *in_ECX = iVar7 + 1;
    if ((piVar5[2] <= iVar7 + 1) || (piVar5[2] <= in_ECX[1])) break;
    if ((DAT_00b9bf2c + 2 <= local_1c) &&
       (((DAT_00b9bf30 + 2 <= iVar8 && (local_1c < DAT_00b9bf20 + -2 + DAT_00b9bf2c)) &&
        (iVar8 < DAT_00b9bf24 + -2 + DAT_00b9bf30)))) {
      iVar7 = DAT_00b9bf20 * iVar8 + local_1c;
      if ((param_5 & 4) != 0) {
        iVar4 = iVar8 + 1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if (*(char *)(iVar3 + 6) != -1) {
          iVar3 = (DAT_00b9bf20 + iVar7) % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_10 = DAT_00b9bf18;
          }
          else {
            local_10 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = iVar7 % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
            piVar6 = extraout_ECX;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar3;
            piVar6 = DAT_00b9bf18;
          }
          iVar3 = FUN_0059a8b0(local_1c,iVar8,local_1c,iVar4,piVar6);
          if (*piVar5 + iVar3 < *local_10) {
            iVar3 = FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)(iVar3 + 0x34);
            if (param_6 < 8) {
              pcVar10 = pcVar10 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar10 != '\0') {
              iVar3 = iVar7 % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar3;
              }
              iVar3 = (DAT_00b9bf20 + iVar7) % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = DAT_00b9bf18;
                piVar6 = extraout_ECX_00;
              }
              else {
                piVar5 = DAT_00b9bf18 + iVar3;
                piVar6 = DAT_00b9bf18;
              }
              iVar3 = FUN_0059a8b0(local_1c,iVar8,local_1c,iVar4,piVar6);
              *piVar5 = *local_10 + iVar3;
              iVar3 = in_ECX[1];
              piVar5 = (int *)in_ECX[3];
              if ((iVar3 < 0) || (piVar5[1] <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = (int *)*piVar5;
              }
              else {
                piVar5 = (int *)(*piVar5 + iVar3 * 8);
              }
              *piVar5 = local_1c;
              piVar5[1] = iVar4;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
      if ((param_5 & 1) != 0) {
        iVar4 = iVar8 + -1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if (*(char *)(iVar3 + 6) != -1) {
          iVar3 = (iVar7 - DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14 = DAT_00b9bf18;
          }
          else {
            local_14 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = iVar7 % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
            piVar6 = extraout_ECX_01;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar3;
            piVar6 = DAT_00b9bf18;
          }
          iVar3 = FUN_0059a8b0(local_1c,iVar8,local_1c,iVar4,piVar6);
          if (*piVar5 + iVar3 < *local_14) {
            iVar3 = FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)(iVar3 + 0x34);
            if (param_6 < 8) {
              pcVar10 = pcVar10 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar10 != '\0') {
              iVar3 = iVar7 % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar3;
              }
              iVar3 = (iVar7 - DAT_00b9bf20) % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = DAT_00b9bf18;
                piVar6 = extraout_ECX_02;
              }
              else {
                piVar5 = DAT_00b9bf18 + iVar3;
                piVar6 = DAT_00b9bf18;
              }
              iVar3 = FUN_0059a8b0(local_1c,iVar8,local_1c,iVar4,piVar6);
              *piVar5 = *local_10 + iVar3;
              iVar3 = in_ECX[1];
              piVar5 = (int *)in_ECX[3];
              if ((iVar3 < 0) || (piVar5[1] <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = (int *)*piVar5;
              }
              else {
                piVar5 = (int *)(*piVar5 + iVar3 * 8);
              }
              *piVar5 = local_1c;
              piVar5[1] = iVar4;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
      if ((param_5 & 2) != 0) {
        iVar4 = FUN_00592f10(PTR_0077241c);
        if (*(char *)(iVar4 + 6) != -1) {
          iVar4 = (iVar7 + 1) % DAT_00b9bf28;
          if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14 = DAT_00b9bf18;
          }
          else {
            local_14 = DAT_00b9bf18 + iVar4;
          }
          iVar4 = iVar7 % DAT_00b9bf28;
          if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
            piVar6 = extraout_ECX_03;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar4;
            piVar6 = DAT_00b9bf18;
          }
          iVar4 = FUN_0059a8b0(local_1c,iVar8,local_1c + 1,iVar8,piVar6);
          if (*piVar5 + iVar4 < *local_14) {
            iVar4 = FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)(iVar4 + 0x34);
            if (param_6 < 8) {
              pcVar10 = pcVar10 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar10 != '\0') {
              iVar4 = iVar7 % DAT_00b9bf28;
              if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar4;
              }
              iVar4 = (iVar7 + 1) % DAT_00b9bf28;
              if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = DAT_00b9bf18;
                piVar6 = extraout_ECX_04;
              }
              else {
                piVar5 = DAT_00b9bf18 + iVar4;
                piVar6 = DAT_00b9bf18;
              }
              iVar4 = FUN_0059a8b0(local_1c,iVar8,local_1c + 1,iVar8,piVar6);
              *piVar5 = *local_10 + iVar4;
              iVar4 = in_ECX[1];
              piVar5 = (int *)in_ECX[3];
              if ((iVar4 < 0) || (piVar5[1] <= iVar4)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = (int *)*piVar5;
              }
              else {
                piVar5 = (int *)(*piVar5 + iVar4 * 8);
              }
              *piVar5 = local_1c + 1;
              piVar5[1] = iVar8;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
      if ((param_5 & 8) != 0) {
        iVar4 = FUN_00592f10(PTR_0077241c);
        if (*(char *)(iVar4 + 6) != -1) {
          iVar4 = (iVar7 + -1) % DAT_00b9bf28;
          if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14 = DAT_00b9bf18;
          }
          else {
            local_14 = DAT_00b9bf18 + iVar4;
          }
          iVar4 = iVar7 % DAT_00b9bf28;
          if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
            piVar6 = extraout_ECX_05;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar4;
            piVar6 = DAT_00b9bf18;
          }
          iVar4 = FUN_0059a8b0(local_1c,iVar8,local_1c + -1,iVar8,piVar6);
          if (*piVar5 + iVar4 < *local_14) {
            iVar4 = FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)(iVar4 + 0x34);
            if (param_6 < 8) {
              pcVar10 = pcVar10 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar10 != '\0') {
              iVar4 = iVar7 % DAT_00b9bf28;
              if ((iVar4 < 0) || (DAT_00b9bf1c <= iVar4)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar4;
              }
              iVar7 = (iVar7 + -1) % DAT_00b9bf28;
              if ((iVar7 < 0) || (DAT_00b9bf1c <= iVar7)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = extraout_ECX_06;
                piVar6 = DAT_00b9bf18;
              }
              else {
                piVar5 = DAT_00b9bf18;
                piVar6 = DAT_00b9bf18 + iVar7;
              }
              iVar7 = FUN_0059a8b0(local_1c,iVar8,local_1c + -1,iVar8,piVar5);
              *piVar6 = *local_10 + iVar7;
              iVar7 = in_ECX[1];
              piVar5 = (int *)in_ECX[3];
              if ((iVar7 < 0) || (piVar5[1] <= iVar7)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar5 = (int *)*piVar5;
              }
              else {
                piVar5 = (int *)(*piVar5 + iVar7 * 8);
              }
              *piVar5 = local_1c + -1;
              piVar5[1] = iVar8;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
    }
  } while (in_ECX[1] != *in_ECX);
  iVar7 = in_ECX[1] + -1;
  piVar5 = (int *)in_ECX[3];
  if ((iVar7 < 0) || (piVar5[1] <= iVar7)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = (undefined4 *)*piVar5;
  }
  else {
    puVar9 = (undefined4 *)(*piVar5 + iVar7 * 8);
  }
  uVar1 = puVar9[1];
  *param_1 = *puVar9;
  param_1[1] = uVar1;
  return;
}

