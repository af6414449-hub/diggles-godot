
void FUN_0059fda0(undefined4 *param_1,int param_2,int param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  code *pcVar10;
  int local_18;
  int *local_14;
  int *local_10;
  
  pcVar10 = RaiseException_exref;
  piVar6 = (int *)in_ECX[3];
  *in_ECX = 0;
  if (piVar6[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar6 = (int *)*piVar6;
  *piVar6 = param_2;
  piVar6[1] = param_3;
  iVar7 = (DAT_00b9bf20 * param_3 + param_2) % DAT_00b9bf28;
  if ((iVar7 < 0) || (DAT_00b9bf1c <= iVar7)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = DAT_00b9bf18;
  }
  else {
    piVar6 = DAT_00b9bf18 + iVar7;
  }
  iVar7 = FUN_0059a740(param_2,param_3,param_2,param_3);
  *piVar6 = iVar7;
  in_ECX[1] = 1;
  iVar7 = *(int *)(in_ECX[3] + 8);
  if (iVar7 <= param_4) {
    *(int *)(in_ECX[3] + 8) = iVar7 + param_4 + 1;
    uVar1 = *(undefined4 *)(in_ECX[3] + 8);
    uVar2 = FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathFinder_Random.cpp",0x103);
    puVar9 = (undefined4 *)in_ECX[3];
    *puVar9 = uVar2;
    puVar9[1] = uVar1;
  }
  do {
    iVar7 = *in_ECX;
    piVar6 = (int *)in_ECX[3];
    if ((iVar7 < 0) || (piVar6[1] <= iVar7)) {
      (*pcVar10)(0xc000008c,1,0,0);
      piVar4 = (int *)*piVar6;
      iVar7 = *in_ECX;
      piVar6 = (int *)in_ECX[3];
      local_18 = *piVar4;
      if (-1 < iVar7) goto LAB_0059feaf;
LAB_0059febb:
      (*pcVar10)(0xc000008c,1,0,0);
      iVar8 = *piVar6;
      iVar7 = *in_ECX;
    }
    else {
      local_18 = *(int *)(*piVar6 + iVar7 * 8);
LAB_0059feaf:
      if (piVar6[1] <= iVar7) goto LAB_0059febb;
      iVar8 = *piVar6 + iVar7 * 8;
    }
    iVar8 = *(int *)(iVar8 + 4);
    *in_ECX = iVar7 + 1;
    if ((((DAT_00b9bf2c + 2 <= local_18) && (DAT_00b9bf30 + 2 <= iVar8)) &&
        (local_18 < DAT_00b9bf2c + -2 + DAT_00b9bf20)) &&
       (pcVar10 = RaiseException_exref, iVar8 < DAT_00b9bf24 + DAT_00b9bf30 + -2)) {
      iVar7 = DAT_00b9bf20 * iVar8 + local_18;
      if ((param_5 & 4) != 0) {
        iVar5 = iVar8 + 1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if ((*(char *)(iVar3 + 6) != -1) &&
           (iVar3 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar3 + 0x12) & 0x40) != 0)) {
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
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = FUN_0059a740(local_18,iVar8,local_18,iVar5);
          if (*piVar6 + iVar3 < *local_10) {
            iVar3 = iVar7 % DAT_00b9bf28;
            if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = DAT_00b9bf18;
            }
            else {
              piVar6 = DAT_00b9bf18 + iVar3;
            }
            iVar3 = (DAT_00b9bf20 + iVar7) % DAT_00b9bf28;
            if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar4 = DAT_00b9bf18;
            }
            else {
              piVar4 = DAT_00b9bf18 + iVar3;
            }
            iVar3 = FUN_0059a740(local_18,iVar8,local_18,iVar5);
            *piVar4 = *piVar6 + iVar3;
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
            iVar5 = in_ECX[1];
            if (param_4 <= iVar5) break;
          }
        }
      }
      if ((param_5 & 1) != 0) {
        iVar5 = iVar8 + -1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if ((*(char *)(iVar3 + 6) != -1) &&
           (iVar3 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar3 + 0x12) & 0x40) != 0)) {
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
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = FUN_0059a740(local_18,iVar8,local_18,iVar5);
          if (*piVar6 + iVar3 < *local_14) {
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
              piVar6 = DAT_00b9bf18;
            }
            else {
              piVar6 = DAT_00b9bf18 + iVar3;
            }
            iVar3 = FUN_0059a740(local_18,iVar8,local_18,iVar5);
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
            iVar5 = in_ECX[1];
            if (param_4 <= iVar5) break;
          }
        }
      }
      if ((((param_5 & 2) != 0) && (iVar5 = FUN_00592f10(PTR_0077241c), *(char *)(iVar5 + 6) != -1))
         && (iVar5 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar5 + 0x12) & 0x40) != 0)) {
        iVar5 = (iVar7 + 1) % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_14 = DAT_00b9bf18;
        }
        else {
          local_14 = DAT_00b9bf18 + iVar5;
        }
        iVar5 = iVar7 % DAT_00b9bf28;
        if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = DAT_00b9bf18;
        }
        else {
          piVar6 = DAT_00b9bf18 + iVar5;
        }
        iVar5 = FUN_0059a740(local_18,iVar8,local_18 + 1,iVar8);
        if (*piVar6 + iVar5 < *local_14) {
          iVar5 = iVar7 % DAT_00b9bf28;
          if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_10 = DAT_00b9bf18;
          }
          else {
            local_10 = DAT_00b9bf18 + iVar5;
          }
          iVar5 = (iVar7 + 1) % DAT_00b9bf28;
          if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar5;
          }
          iVar5 = FUN_0059a740(local_18,iVar8,local_18 + 1,iVar8);
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
          piVar6[1] = iVar8;
          in_ECX[1] = in_ECX[1] + 1;
          iVar5 = in_ECX[1];
          if (param_4 <= iVar5) break;
        }
      }
      if ((param_5 & 8) != 0) {
        iVar5 = FUN_00592f10(PTR_0077241c);
        if ((*(char *)(iVar5 + 6) != -1) &&
           (iVar5 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar5 + 0x12) & 0x40) != 0)) {
          iVar5 = (iVar7 + -1) % DAT_00b9bf28;
          if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14 = DAT_00b9bf18;
          }
          else {
            local_14 = DAT_00b9bf18 + iVar5;
          }
          iVar5 = iVar7 % DAT_00b9bf28;
          if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar5;
          }
          iVar5 = FUN_0059a740(local_18,iVar8,local_18 + -1,iVar8);
          if (*piVar6 + iVar5 < *local_14) {
            iVar5 = iVar7 % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_10 = DAT_00b9bf18;
            }
            else {
              local_10 = DAT_00b9bf18 + iVar5;
            }
            iVar7 = (iVar7 + -1) % DAT_00b9bf28;
            if ((iVar7 < 0) || (DAT_00b9bf1c <= iVar7)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = DAT_00b9bf18;
            }
            else {
              piVar6 = DAT_00b9bf18 + iVar7;
            }
            iVar7 = FUN_0059a740(local_18,iVar8,local_18 + -1,iVar8);
            *piVar6 = *local_10 + iVar7;
            iVar7 = in_ECX[1];
            piVar6 = (int *)in_ECX[3];
            if ((iVar7 < 0) || (piVar6[1] <= iVar7)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar6 = (int *)*piVar6;
            }
            else {
              piVar6 = (int *)(*piVar6 + iVar7 * 8);
            }
            *piVar6 = local_18 + -1;
            piVar6[1] = iVar8;
            in_ECX[1] = in_ECX[1] + 1;
            iVar5 = in_ECX[1];
            if (param_4 <= iVar5) break;
          }
        }
      }
    }
    iVar5 = in_ECX[1];
  } while (iVar5 != *in_ECX);
  piVar6 = (int *)in_ECX[3];
  iVar5 = iVar5 + -1;
  if ((iVar5 < 0) || (piVar6[1] <= iVar5)) {
    (*pcVar10)(0xc000008c,1,0,0);
    puVar9 = (undefined4 *)*piVar6;
  }
  else {
    puVar9 = (undefined4 *)(*piVar6 + iVar5 * 8);
  }
  uVar1 = puVar9[1];
  *param_1 = *puVar9;
  param_1[1] = uVar1;
  return;
}

