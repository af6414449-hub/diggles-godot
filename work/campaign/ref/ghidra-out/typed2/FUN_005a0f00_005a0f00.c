
void FUN_005a0f00(undefined4 *param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int local_18;
  int *local_14;
  int *local_10;
  
  piVar6 = (int *)in_ECX[3];
  *in_ECX = 0;
  if (piVar6[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar6 = (int *)*piVar6;
  *piVar6 = param_2;
  piVar6[1] = param_3;
  iVar8 = (DAT_00b9bf20 * param_3 + param_2) % DAT_00b9bf28;
  if ((iVar8 < 0) || (DAT_00b9bf1c <= iVar8)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = DAT_00b9bf18;
  }
  else {
    piVar6 = DAT_00b9bf18 + iVar8;
  }
  iVar8 = FUN_0059a8b0(param_2,param_3,param_2,param_3,param_3);
  *piVar6 = iVar8;
  in_ECX[1] = 1;
  iVar8 = *(int *)(in_ECX[3] + 8);
  if (iVar8 <= param_4) {
    *(int *)(in_ECX[3] + 8) = iVar8 + param_4 + 1;
    uVar1 = *(undefined4 *)(in_ECX[3] + 8);
    uVar2 = FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathFinder_Random.cpp",0x1b5);
    puVar10 = (undefined4 *)in_ECX[3];
    *puVar10 = uVar2;
    puVar10[1] = uVar1;
  }
  do {
    iVar8 = *in_ECX;
    piVar6 = (int *)in_ECX[3];
    if ((iVar8 < 0) || (piVar6[1] <= iVar8)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = (int *)*piVar6;
      iVar8 = *in_ECX;
      piVar6 = (int *)in_ECX[3];
      local_18 = *piVar7;
      if (-1 < iVar8) goto LAB_005a1017;
LAB_005a1023:
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar9 = *piVar6;
      iVar8 = *in_ECX;
      piVar6 = (int *)in_ECX[3];
    }
    else {
      local_18 = *(int *)(*piVar6 + iVar8 * 8);
LAB_005a1017:
      if (piVar6[1] <= iVar8) goto LAB_005a1023;
      iVar9 = *piVar6 + iVar8 * 8;
    }
    iVar9 = *(int *)(iVar9 + 4);
    *in_ECX = iVar8 + 1;
    if ((piVar6[2] <= iVar8 + 1) || (piVar6[2] <= in_ECX[1])) break;
    if ((DAT_00b9bf2c + 2 <= local_18) &&
       (((DAT_00b9bf30 + 2 <= iVar9 && (local_18 < DAT_00b9bf20 + -2 + DAT_00b9bf2c)) &&
        (iVar9 < DAT_00b9bf24 + -2 + DAT_00b9bf30)))) {
      iVar8 = DAT_00b9bf20 * iVar9 + local_18;
      if ((param_5 & 4) != 0) {
        iVar5 = iVar9 + 1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if ((*(char *)(iVar3 + 6) != -1) &&
           (iVar3 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar3 + 0x12) & 0x40) != 0)) {
          iVar3 = (DAT_00b9bf20 + iVar8) % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_10 = DAT_00b9bf18;
          }
          else {
            local_10 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = iVar8 % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
            piVar7 = extraout_ECX;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar3;
            piVar7 = DAT_00b9bf18;
          }
          iVar3 = FUN_0059a8b0(local_18,iVar9,local_18,iVar5,piVar7);
          if (*piVar6 + iVar3 < *local_10) {
            iVar3 = FUN_00592f10(PTR_0077241c);
            pcVar4 = (char *)(iVar3 + 0x34);
            if (param_6 < 8) {
              pcVar4 = pcVar4 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar4 != '\0') {
              iVar3 = iVar8 % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar3;
              }
              iVar3 = (DAT_00b9bf20 + iVar8) % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = DAT_00b9bf18;
                piVar7 = extraout_ECX_00;
              }
              else {
                piVar6 = DAT_00b9bf18 + iVar3;
                piVar7 = DAT_00b9bf18;
              }
              iVar3 = FUN_0059a8b0(local_18,iVar9,local_18,iVar5,piVar7);
              *piVar6 = *local_10 + iVar3;
              iVar3 = in_ECX[1];
              piVar6 = (int *)in_ECX[3];
              if ((iVar3 < 0) || (piVar6[1] <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = (int *)*piVar6;
              }
              else {
                piVar6 = (int *)(*piVar6 + iVar3 * 8);
              }
              *piVar6 = local_18;
              piVar6[1] = iVar5;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
      if ((param_5 & 1) != 0) {
        iVar5 = iVar9 + -1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if ((*(char *)(iVar3 + 6) != -1) &&
           (iVar3 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar3 + 0x12) & 0x40) != 0)) {
          iVar3 = (iVar8 - DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14 = DAT_00b9bf18;
          }
          else {
            local_14 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = iVar8 % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
            piVar7 = extraout_ECX_01;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar3;
            piVar7 = DAT_00b9bf18;
          }
          iVar3 = FUN_0059a8b0(local_18,iVar9,local_18,iVar5,piVar7);
          if (*piVar6 + iVar3 < *local_14) {
            iVar3 = FUN_00592f10(PTR_0077241c);
            pcVar4 = (char *)(iVar3 + 0x34);
            if (param_6 < 8) {
              pcVar4 = pcVar4 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar4 != '\0') {
              iVar3 = iVar8 % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar3;
              }
              iVar3 = (iVar8 - DAT_00b9bf20) % DAT_00b9bf28;
              if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = DAT_00b9bf18;
                piVar7 = extraout_ECX_02;
              }
              else {
                piVar6 = DAT_00b9bf18 + iVar3;
                piVar7 = DAT_00b9bf18;
              }
              iVar3 = FUN_0059a8b0(local_18,iVar9,local_18,iVar5,piVar7);
              *piVar6 = *local_10 + iVar3;
              iVar3 = in_ECX[1];
              piVar6 = (int *)in_ECX[3];
              if ((iVar3 < 0) || (piVar6[1] <= iVar3)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = (int *)*piVar6;
              }
              else {
                piVar6 = (int *)(*piVar6 + iVar3 * 8);
              }
              *piVar6 = local_18;
              piVar6[1] = iVar5;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
      if ((((param_5 & 2) != 0) && (iVar5 = FUN_00592f10(PTR_0077241c), *(char *)(iVar5 + 6) != -1))
         && (iVar5 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar5 + 0x12) & 0x40) != 0)) {
        iVar5 = (iVar8 + 1) % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_14 = DAT_00b9bf18;
        }
        else {
          local_14 = DAT_00b9bf18 + iVar5;
        }
        iVar5 = iVar8 % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = DAT_00b9bf18;
          piVar7 = extraout_ECX_03;
        }
        else {
          piVar6 = DAT_00b9bf18 + iVar5;
          piVar7 = DAT_00b9bf18;
        }
        iVar5 = FUN_0059a8b0(local_18,iVar9,local_18 + 1,iVar9,piVar7);
        if (*piVar6 + iVar5 < *local_14) {
          iVar5 = FUN_00592f10(PTR_0077241c);
          pcVar4 = (char *)(iVar5 + 0x34);
          if (param_6 < 8) {
            pcVar4 = pcVar4 + param_6;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*pcVar4 != '\0') {
            iVar5 = iVar8 % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_10 = DAT_00b9bf18;
            }
            else {
              local_10 = DAT_00b9bf18 + iVar5;
            }
            iVar5 = (iVar8 + 1) % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = DAT_00b9bf18;
              piVar7 = extraout_ECX_04;
            }
            else {
              piVar6 = DAT_00b9bf18 + iVar5;
              piVar7 = DAT_00b9bf18;
            }
            iVar5 = FUN_0059a8b0(local_18,iVar9,local_18 + 1,iVar9,piVar7);
            *piVar6 = *local_10 + iVar5;
            iVar5 = in_ECX[1];
            piVar6 = (int *)in_ECX[3];
            if ((iVar5 < 0) || (piVar6[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = (int *)*piVar6;
            }
            else {
              piVar6 = (int *)(*piVar6 + iVar5 * 8);
            }
            *piVar6 = local_18 + 1;
            piVar6[1] = iVar9;
            in_ECX[1] = in_ECX[1] + 1;
            if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
               (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
          }
        }
      }
      if ((param_5 & 8) != 0) {
        iVar5 = FUN_00592f10(PTR_0077241c);
        if ((*(char *)(iVar5 + 6) != -1) &&
           (iVar5 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar5 + 0x12) & 0x40) != 0)) {
          iVar5 = (iVar8 + -1) % DAT_00b9bf28;
          if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14 = DAT_00b9bf18;
          }
          else {
            local_14 = DAT_00b9bf18 + iVar5;
          }
          iVar5 = iVar8 % DAT_00b9bf28;
          if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
            piVar7 = extraout_ECX_05;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar5;
            piVar7 = DAT_00b9bf18;
          }
          iVar5 = FUN_0059a8b0(local_18,iVar9,local_18 + -1,iVar9,piVar7);
          if (*piVar6 + iVar5 < *local_14) {
            iVar5 = FUN_00592f10(PTR_0077241c);
            pcVar4 = (char *)(iVar5 + 0x34);
            if (param_6 < 8) {
              pcVar4 = pcVar4 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            if (*pcVar4 != '\0') {
              iVar5 = iVar8 % DAT_00b9bf28;
              if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_10 = DAT_00b9bf18;
              }
              else {
                local_10 = DAT_00b9bf18 + iVar5;
              }
              iVar8 = (iVar8 + -1) % DAT_00b9bf28;
              if ((iVar8 < 0) || (DAT_00b9bf1c <= iVar8)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = DAT_00b9bf18;
                piVar7 = extraout_ECX_06;
              }
              else {
                piVar6 = DAT_00b9bf18 + iVar8;
                piVar7 = DAT_00b9bf18;
              }
              iVar8 = FUN_0059a8b0(local_18,iVar9,local_18 + -1,iVar9,piVar7);
              *piVar6 = *local_10 + iVar8;
              iVar8 = in_ECX[1];
              piVar6 = (int *)in_ECX[3];
              if ((iVar8 < 0) || (piVar6[1] <= iVar8)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = (int *)*piVar6;
              }
              else {
                piVar6 = (int *)(*piVar6 + iVar8 * 8);
              }
              *piVar6 = local_18 + -1;
              piVar6[1] = iVar9;
              in_ECX[1] = in_ECX[1] + 1;
              if (((param_4 == in_ECX[1]) || (*(int *)(in_ECX[3] + 8) <= *in_ECX)) ||
                 (*(int *)(in_ECX[3] + 8) <= in_ECX[1])) break;
            }
          }
        }
      }
    }
  } while (in_ECX[1] != *in_ECX);
  iVar8 = in_ECX[1] + -1;
  piVar6 = (int *)in_ECX[3];
  if ((iVar8 < 0) || (piVar6[1] <= iVar8)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar10 = (undefined4 *)*piVar6;
  }
  else {
    puVar10 = (undefined4 *)(*piVar6 + iVar8 * 8);
  }
  uVar1 = puVar10[1];
  *param_1 = *puVar10;
  param_1[1] = uVar1;
  return;
}

