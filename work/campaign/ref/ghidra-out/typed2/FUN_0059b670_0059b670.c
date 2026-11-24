
undefined4 FUN_0059b670(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  int *piVar7;
  int *local_1c;
  int *local_18;
  int *local_14;
  undefined1 local_5;
  
  in_ECX[3] = 0;
  if (in_ECX[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar5 = (int *)*in_ECX;
  *piVar5 = param_3;
  piVar5[1] = param_4;
  iVar6 = (DAT_00b9bf20 * param_4 + param_3) % DAT_00b9bf28;
  if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar5 = DAT_00b9bf18;
  }
  else {
    piVar5 = DAT_00b9bf18 + iVar6;
  }
  iVar6 = FUN_0059a740(param_3,param_4,param_3,param_4);
  *piVar5 = iVar6;
  in_ECX[4] = 1;
  local_5 = 0;
  do {
    iVar6 = in_ECX[3];
    if ((iVar6 < 0) || (in_ECX[1] <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar5 = (int *)*in_ECX;
      iVar6 = in_ECX[3];
      piVar7 = piVar5;
    }
    else {
      piVar5 = (int *)*in_ECX + iVar6 * 2;
      piVar7 = (int *)*in_ECX;
    }
    iVar4 = *piVar5;
    if ((iVar6 < 0) || (in_ECX[1] <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = (int *)*in_ECX;
      iVar6 = in_ECX[3];
    }
    else {
      piVar7 = piVar7 + iVar6 * 2;
    }
    iVar6 = iVar6 + 1;
    iVar1 = piVar7[1];
    in_ECX[3] = iVar6;
    if ((in_ECX[2] <= iVar6) || (in_ECX[2] <= in_ECX[4])) goto LAB_0059bf78;
    if ((DAT_00b9bf2c + 2 <= iVar4) &&
       (((DAT_00b9bf30 + 2 <= iVar1 && (iVar4 < DAT_00b9bf20 + DAT_00b9bf2c + -2)) &&
        (iVar1 < DAT_00b9bf24 + -2 + DAT_00b9bf30)))) {
      iVar2 = DAT_00b9bf20 * iVar1 + iVar4;
      iVar6 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar6 + 6) != -1) {
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
          piVar5 = DAT_00b9bf18;
        }
        else {
          piVar5 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = FUN_0059a740(iVar4,iVar1,iVar4,iVar1 + 1);
        if (*piVar5 + iVar6 < *local_18) {
          iVar6 = iVar2 % DAT_00b9bf28;
          if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_18 = DAT_00b9bf18;
          }
          else {
            local_18 = DAT_00b9bf18 + iVar6;
          }
          iVar6 = (DAT_00b9bf20 + iVar2) % DAT_00b9bf28;
          if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar6;
          }
          iVar6 = FUN_0059a740(iVar4,iVar1,iVar4,iVar1 + 1);
          *piVar5 = *local_18 + iVar6;
          iVar6 = in_ECX[4];
          if ((iVar6 < 0) || (in_ECX[1] <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = (int *)*in_ECX;
          }
          else {
            piVar5 = (int *)(*in_ECX + iVar6 * 8);
          }
          *piVar5 = iVar4;
          piVar5[1] = iVar1 + 1;
          iVar6 = in_ECX[4];
          in_ECX[4] = iVar6 + 1;
          if ((param_1 == iVar4) && (param_2 == iVar1 + 1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar6 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
          iVar6 = in_ECX[2];
          if ((iVar6 <= in_ECX[3]) || (iVar6 <= in_ECX[4])) {
LAB_0059bf78:
            return CONCAT31((int3)((uint)iVar6 >> 8),local_5);
          }
        }
      }
      iVar6 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar6 + 6) != -1) {
        iVar6 = (iVar2 - DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_14 = DAT_00b9bf18;
        }
        else {
          local_14 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = iVar2 % DAT_00b9bf28;
        if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar5 = DAT_00b9bf18;
        }
        else {
          piVar5 = DAT_00b9bf18 + iVar6;
        }
        iVar6 = FUN_0059a740(iVar4,iVar1,iVar4,iVar1 + -1);
        if (*piVar5 + iVar6 < *local_14) {
          iVar6 = iVar2 % DAT_00b9bf28;
          if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_18 = DAT_00b9bf18;
          }
          else {
            local_18 = DAT_00b9bf18 + iVar6;
          }
          iVar6 = (iVar2 - DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar6 < 0) || (DAT_00b9bf1c <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar6;
          }
          iVar6 = FUN_0059a740(iVar4,iVar1,iVar4,iVar1 + -1);
          *piVar5 = *local_18 + iVar6;
          iVar6 = in_ECX[4];
          if ((iVar6 < 0) || (in_ECX[1] <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = (int *)*in_ECX;
          }
          else {
            piVar5 = (int *)(*in_ECX + iVar6 * 8);
          }
          *piVar5 = iVar4;
          piVar5[1] = iVar1 + -1;
          iVar6 = in_ECX[4];
          in_ECX[4] = iVar6 + 1;
          if ((param_1 == iVar4) && (param_2 == iVar1 + -1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar6 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
          iVar6 = in_ECX[2];
          if ((iVar6 <= in_ECX[3]) || (iVar6 <= in_ECX[4])) goto LAB_0059bf78;
        }
      }
      iVar6 = iVar4 + 1;
      iVar3 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar3 + 6) != -1) {
        iVar3 = (iVar2 + 1) % DAT_00b9bf28;
        if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = DAT_00b9bf18;
        }
        else {
          local_1c = DAT_00b9bf18 + iVar3;
        }
        iVar3 = iVar2 % DAT_00b9bf28;
        if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar5 = DAT_00b9bf18;
        }
        else {
          piVar5 = DAT_00b9bf18 + iVar3;
        }
        iVar3 = FUN_0059a740(iVar4,iVar1,iVar6,iVar1);
        if (*piVar5 + iVar3 < *local_1c) {
          iVar3 = iVar2 % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_1c = DAT_00b9bf18;
          }
          else {
            local_1c = DAT_00b9bf18 + iVar3;
          }
          iVar3 = (iVar2 + 1) % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar3;
          }
          iVar3 = FUN_0059a740(iVar4,iVar1,iVar6,iVar1);
          *piVar5 = *local_1c + iVar3;
          iVar3 = in_ECX[4];
          if ((iVar3 < 0) || (in_ECX[1] <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = (int *)*in_ECX;
          }
          else {
            piVar5 = (int *)(*in_ECX + iVar3 * 8);
          }
          *piVar5 = iVar6;
          piVar5[1] = iVar1;
          iVar3 = in_ECX[4];
          in_ECX[4] = iVar3 + 1;
          if ((param_1 == iVar6) && (param_2 == iVar1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar3 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
          iVar6 = in_ECX[2];
          if ((iVar6 <= in_ECX[3]) || (iVar6 <= in_ECX[4])) goto LAB_0059bf78;
        }
      }
      iVar6 = iVar4 + -1;
      iVar3 = FUN_00592f10(PTR_0077241c);
      if (*(char *)(iVar3 + 6) != -1) {
        iVar3 = (iVar2 + -1) % DAT_00b9bf28;
        if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = DAT_00b9bf18;
        }
        else {
          local_18 = DAT_00b9bf18 + iVar3;
        }
        iVar3 = iVar2 % DAT_00b9bf28;
        if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar5 = DAT_00b9bf18;
        }
        else {
          piVar5 = DAT_00b9bf18 + iVar3;
        }
        iVar3 = FUN_0059a740(iVar4,iVar1,iVar6,iVar1);
        if (*piVar5 + iVar3 < *local_18) {
          iVar3 = iVar2 % DAT_00b9bf28;
          if ((iVar3 < 0) || (DAT_00b9bf1c <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_1c = DAT_00b9bf18;
          }
          else {
            local_1c = DAT_00b9bf18 + iVar3;
          }
          iVar2 = (iVar2 + -1) % DAT_00b9bf28;
          if ((iVar2 < 0) || (DAT_00b9bf1c <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = DAT_00b9bf18;
          }
          else {
            piVar5 = DAT_00b9bf18 + iVar2;
          }
          iVar4 = FUN_0059a740(iVar4,iVar1,iVar6,iVar1);
          *piVar5 = *local_1c + iVar4;
          iVar4 = in_ECX[4];
          if ((iVar4 < 0) || (in_ECX[1] <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = (int *)*in_ECX;
          }
          else {
            piVar5 = (int *)(*in_ECX + iVar4 * 8);
          }
          *piVar5 = iVar6;
          piVar5[1] = iVar1;
          iVar4 = in_ECX[4];
          in_ECX[4] = iVar4 + 1;
          if ((param_1 == iVar6) && (param_2 == iVar1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar4 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
          iVar6 = in_ECX[2];
          if ((iVar6 <= in_ECX[3]) || (iVar6 <= in_ECX[4])) goto LAB_0059bf78;
        }
      }
    }
    iVar6 = in_ECX[3];
    if ((in_ECX[4] == iVar6) || (param_5 <= iVar6)) goto LAB_0059bf78;
    if (in_ECX[2] < in_ECX[4] + 4) {
      iVar4 = in_ECX[2] + 0x400;
      in_ECX[2] = iVar4;
      iVar6 = FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathfinder.cpp",0x20e);
      *in_ECX = iVar6;
      in_ECX[1] = iVar4;
    }
  } while( true );
}

