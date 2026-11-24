
undefined4 FUN_0059ca30(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  int *piVar4;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int iVar5;
  int iVar6;
  int iVar7;
  int *local_1c;
  int *local_18;
  undefined1 local_5;
  
  in_ECX[3] = 0;
  if (in_ECX[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar3 = (int *)*in_ECX;
  *piVar3 = param_3;
  piVar3[1] = param_4;
  iVar5 = (DAT_00b9bf20 * param_4 + param_3) % DAT_00b9bf28;
  if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar3 = DAT_00b9bf18;
  }
  else {
    piVar3 = DAT_00b9bf18 + iVar5;
  }
  iVar5 = FUN_0059a8b0(param_3,param_4,param_3,param_4,param_4);
  *piVar3 = iVar5;
  in_ECX[4] = 1;
  local_5 = 0;
  do {
    iVar5 = in_ECX[3];
    if ((iVar5 < 0) || (in_ECX[1] <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = (int *)*in_ECX;
      iVar5 = in_ECX[3];
      piVar4 = piVar3;
    }
    else {
      piVar3 = (int *)*in_ECX + iVar5 * 2;
      piVar4 = (int *)*in_ECX;
    }
    iVar7 = *piVar3;
    if ((iVar5 < 0) || (in_ECX[1] <= iVar5)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar4 = (int *)*in_ECX;
      iVar5 = in_ECX[3];
    }
    else {
      piVar4 = piVar4 + iVar5 * 2;
    }
    iVar1 = piVar4[1];
    iVar5 = iVar5 + 1;
    in_ECX[3] = iVar5;
    if ((in_ECX[2] <= iVar5) || (in_ECX[2] <= in_ECX[4])) goto LAB_0059cda2;
    if ((DAT_00b9bf2c + 2 <= iVar7) &&
       (((DAT_00b9bf30 + 2 <= iVar1 && (iVar7 < DAT_00b9bf20 + -2 + DAT_00b9bf2c)) &&
        (iVar1 < DAT_00b9bf24 + -2 + DAT_00b9bf30)))) {
      iVar2 = DAT_00b9bf20 * iVar1 + iVar7;
      iVar5 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar5 + 6) != -1) {
        iVar6 = (DAT_00b9bf20 + iVar2) % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = DAT_00b9bf18;
        }
        else {
          local_18 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = iVar2 % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar3 = extraout_ECX;
          piVar4 = DAT_00b9bf18;
        }
        else {
          piVar3 = DAT_00b9bf18;
          piVar4 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = FUN_0059a8b0(iVar7,iVar1,iVar7,iVar1 + 1,piVar3);
        if (*piVar4 + iVar6 < *local_18) {
          if (param_5 < 8) {
            iVar5 = iVar5 + param_5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*(char *)(iVar5 + 0x34) != '\0') {
            iVar5 = iVar2 % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = DAT_00b9bf18;
            }
            else {
              local_1c = DAT_00b9bf18 + iVar5;
            }
            iVar5 = (DAT_00b9bf20 + iVar2) % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = extraout_ECX_00;
              piVar4 = DAT_00b9bf18;
            }
            else {
              piVar3 = DAT_00b9bf18;
              piVar4 = DAT_00b9bf18 + iVar5;
            }
            iVar5 = FUN_0059a8b0(iVar7,iVar1,iVar7,iVar1 + 1,piVar3);
            *piVar4 = *local_1c + iVar5;
            iVar5 = in_ECX[4];
            if ((iVar5 < 0) || (in_ECX[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = (int *)*in_ECX;
            }
            else {
              piVar3 = (int *)(*in_ECX + iVar5 * 8);
            }
            *piVar3 = iVar7;
            piVar3[1] = iVar1 + 1;
            iVar5 = in_ECX[4];
            in_ECX[4] = iVar5 + 1;
            if ((param_1 == iVar7) && (param_2 == iVar1 + 1)) {
              local_5 = 1;
              DAT_00772dd8 = (int)ROUND((float)(iVar5 + 1) * 1.5);
              if (DAT_00772dd8 <= param_6) {
                DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
                param_6 = DAT_00772dd8;
              }
            }
            iVar5 = in_ECX[2];
            if ((iVar5 <= in_ECX[3]) || (iVar5 <= in_ECX[4])) {
LAB_0059cda2:
              return CONCAT31((int3)((uint)iVar5 >> 8),local_5);
            }
          }
        }
      }
      iVar5 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar5 + 6) != -1) {
        iVar6 = (iVar2 - DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = DAT_00b9bf18;
        }
        else {
          local_1c = DAT_00b9bf18 + iVar6;
        }
        iVar6 = iVar2 % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar3 = extraout_ECX_01;
          piVar4 = DAT_00b9bf18;
        }
        else {
          piVar3 = DAT_00b9bf18;
          piVar4 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = FUN_0059a8b0(iVar7,iVar1,iVar7,iVar1 + -1,piVar3);
        if (*piVar4 + iVar6 < *local_1c) {
          if (param_5 < 8) {
            iVar5 = iVar5 + param_5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*(char *)(iVar5 + 0x34) != '\0') {
            iVar5 = iVar2 % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = DAT_00b9bf18;
            }
            else {
              local_1c = DAT_00b9bf18 + iVar5;
            }
            iVar5 = (iVar2 - DAT_00b9bf20) % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = extraout_ECX_02;
              piVar4 = DAT_00b9bf18;
            }
            else {
              piVar3 = DAT_00b9bf18;
              piVar4 = DAT_00b9bf18 + iVar5;
            }
            iVar5 = FUN_0059a8b0(iVar7,iVar1,iVar7,iVar1 + -1,piVar3);
            *piVar4 = *local_1c + iVar5;
            iVar5 = in_ECX[4];
            if ((iVar5 < 0) || (in_ECX[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = (int *)*in_ECX;
            }
            else {
              piVar3 = (int *)(*in_ECX + iVar5 * 8);
            }
            *piVar3 = iVar7;
            piVar3[1] = iVar1 + -1;
            iVar5 = in_ECX[4];
            in_ECX[4] = iVar5 + 1;
            if ((param_1 == iVar7) && (param_2 == iVar1 + -1)) {
              local_5 = 1;
              DAT_00772dd8 = (int)ROUND((float)(iVar5 + 1) * 1.5);
              if (DAT_00772dd8 <= param_6) {
                DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
                param_6 = DAT_00772dd8;
              }
            }
            iVar5 = in_ECX[2];
            if ((iVar5 <= in_ECX[3]) || (iVar5 <= in_ECX[4])) goto LAB_0059cda2;
          }
        }
      }
      iVar5 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar5 + 6) != -1) {
        iVar6 = (iVar2 + 1) % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = DAT_00b9bf18;
        }
        else {
          local_1c = DAT_00b9bf18 + iVar6;
        }
        iVar6 = iVar2 % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar3 = extraout_ECX_03;
          piVar4 = DAT_00b9bf18;
        }
        else {
          piVar3 = DAT_00b9bf18;
          piVar4 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = FUN_0059a8b0(iVar7,iVar1,iVar7 + 1,iVar1,piVar3);
        if (*piVar4 + iVar6 < *local_1c) {
          if (param_5 < 8) {
            iVar5 = iVar5 + param_5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*(char *)(iVar5 + 0x34) != '\0') {
            iVar5 = iVar2 % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = DAT_00b9bf18;
            }
            else {
              local_1c = DAT_00b9bf18 + iVar5;
            }
            iVar5 = (iVar2 + 1) % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = extraout_ECX_04;
              piVar4 = DAT_00b9bf18;
            }
            else {
              piVar3 = DAT_00b9bf18;
              piVar4 = DAT_00b9bf18 + iVar5;
            }
            iVar5 = FUN_0059a8b0(iVar7,iVar1,iVar7 + 1,iVar1,piVar3);
            *piVar4 = *local_1c + iVar5;
            iVar5 = in_ECX[4];
            if ((iVar5 < 0) || (in_ECX[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = (int *)*in_ECX;
            }
            else {
              piVar3 = (int *)(*in_ECX + iVar5 * 8);
            }
            *piVar3 = iVar7 + 1;
            piVar3[1] = iVar1;
            iVar5 = in_ECX[4];
            in_ECX[4] = iVar5 + 1;
            if ((param_1 == iVar7 + 1) && (param_2 == iVar1)) {
              local_5 = 1;
              DAT_00772dd8 = (int)ROUND((float)(iVar5 + 1) * 1.5);
              if (DAT_00772dd8 <= param_6) {
                DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
                param_6 = DAT_00772dd8;
              }
            }
            iVar5 = in_ECX[2];
            if ((iVar5 <= in_ECX[3]) || (iVar5 <= in_ECX[4])) goto LAB_0059cda2;
          }
        }
      }
      iVar5 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar5 + 6) != -1) {
        iVar6 = (iVar2 + -1) % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = DAT_00b9bf18;
        }
        else {
          local_1c = DAT_00b9bf18 + iVar6;
        }
        iVar6 = iVar2 % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar3 = extraout_ECX_05;
          piVar4 = DAT_00b9bf18;
        }
        else {
          piVar3 = DAT_00b9bf18;
          piVar4 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = FUN_0059a8b0(iVar7,iVar1,iVar7 + -1,iVar1,piVar3);
        if (*piVar4 + iVar6 < *local_1c) {
          if (param_5 < 8) {
            iVar5 = iVar5 + param_5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*(char *)(iVar5 + 0x34) != '\0') {
            iVar5 = iVar2 % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = DAT_00b9bf18;
            }
            else {
              local_1c = DAT_00b9bf18 + iVar5;
            }
            iVar5 = (iVar2 + -1) % DAT_00b9bf28;
            if ((iVar5 < 0) || (DAT_00b9bf1c <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = extraout_ECX_06;
              piVar4 = DAT_00b9bf18;
            }
            else {
              piVar3 = DAT_00b9bf18;
              piVar4 = DAT_00b9bf18 + iVar5;
            }
            iVar5 = FUN_0059a8b0(iVar7,iVar1,iVar7 + -1,iVar1,piVar3);
            *piVar4 = *local_1c + iVar5;
            iVar5 = in_ECX[4];
            if ((iVar5 < 0) || (in_ECX[1] <= iVar5)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar3 = (int *)*in_ECX;
            }
            else {
              piVar3 = (int *)(*in_ECX + iVar5 * 8);
            }
            *piVar3 = iVar7 + -1;
            piVar3[1] = iVar1;
            iVar5 = in_ECX[4];
            in_ECX[4] = iVar5 + 1;
            if ((param_1 == iVar7 + -1) && (param_2 == iVar1)) {
              local_5 = 1;
              DAT_00772dd8 = (int)ROUND((float)(iVar5 + 1) * 1.5);
              if (DAT_00772dd8 <= param_6) {
                DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
                param_6 = DAT_00772dd8;
              }
            }
            iVar5 = in_ECX[2];
            if ((iVar5 <= in_ECX[3]) || (iVar5 <= in_ECX[4])) goto LAB_0059cda2;
          }
        }
      }
    }
    iVar5 = in_ECX[3];
    if ((in_ECX[4] == iVar5) || (param_6 <= iVar5)) goto LAB_0059cda2;
    if (in_ECX[2] < in_ECX[4] + 4) {
      iVar7 = in_ECX[2] + 0x400;
      in_ECX[2] = iVar7;
      iVar5 = FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathfinder.cpp",0x2dc);
      *in_ECX = iVar5;
      in_ECX[1] = iVar7;
    }
  } while( true );
}

