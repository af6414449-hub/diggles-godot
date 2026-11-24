
undefined4 FUN_0059ab90(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  CMap *pCVar2;
  int *piVar3;
  int iVar4;
  CMapCell *pCVar5;
  int *piVar6;
  int iVar7;
  int *in_ECX;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  undefined1 local_5;
  
  pcVar11 = RaiseException_exref;
  in_ECX[3] = 0;
  if (in_ECX[1] < 1) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  piVar6 = (int *)*in_ECX;
  *piVar6 = param_3;
  piVar6[1] = param_4;
  iVar10 = (DAT_00b9bf20 * param_4 + param_3) % DAT_00b9bf28;
  if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = DAT_00b9bf18;
  }
  else {
    piVar6 = DAT_00b9bf18 + iVar10;
  }
  iVar10 = FUN_0059a740(param_3,param_4,param_3,param_4);
  *piVar6 = iVar10;
  in_ECX[4] = 1;
  local_5 = 0;
  while( true ) {
    iVar10 = in_ECX[3];
    if ((iVar10 < 0) || (in_ECX[1] <= iVar10)) {
      (*pcVar11)(0xc000008c,1,0,0);
      piVar6 = (int *)*in_ECX;
      iVar10 = in_ECX[3];
      piVar3 = piVar6;
    }
    else {
      piVar6 = (int *)*in_ECX;
      piVar3 = piVar6 + iVar10 * 2;
    }
    iVar7 = *piVar3;
    if ((iVar10 < 0) || (in_ECX[1] <= iVar10)) {
      (*pcVar11)(0xc000008c,1,0,0);
      piVar6 = (int *)*in_ECX;
      iVar10 = in_ECX[3];
    }
    else {
      piVar6 = piVar6 + iVar10 * 2;
    }
    iVar1 = piVar6[1];
    in_ECX[3] = iVar10 + 1;
    pCVar2 = PTR_0077241c;
    if ((((DAT_00b9bf2c + 2 <= iVar7) && (DAT_00b9bf30 + 2 <= iVar1)) &&
        (iVar7 < DAT_00b9bf2c + -2 + DAT_00b9bf20)) &&
       (pcVar11 = RaiseException_exref, iVar1 < DAT_00b9bf24 + DAT_00b9bf30 + -2)) {
      iVar8 = iVar1 + 1;
      iVar12 = DAT_00b9bf20 * iVar1 + iVar7;
      iVar10 = PTR_0077241c->cellX0;
      if (PTR_0077241c->cellX0 <= iVar7) {
        iVar10 = iVar7;
      }
      iVar9 = PTR_0077241c->cellY0;
      if (PTR_0077241c->cellY0 <= iVar8) {
        iVar9 = iVar8;
      }
      iVar4 = PTR_0077241c->cellY1 + -1;
      if (iVar9 < PTR_0077241c->cellY1) {
        iVar4 = iVar9;
      }
      iVar9 = PTR_0077241c->cellX1 + -1;
      if (iVar10 < PTR_0077241c->cellX1) {
        iVar9 = iVar10;
      }
      iVar10 = (iVar4 * PTR_0077241c->mapWidth + iVar9) % PTR_0077241c->cellCountTotal;
      if ((iVar10 < 0) || (PTR_0077241c->cellCount <= iVar10)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar5 = pCVar2->cells;
      }
      else {
        pCVar5 = PTR_0077241c->cells + iVar10;
      }
      if (pCVar5->field_0x6 != -1) {
        iVar10 = (DAT_00b9bf20 + iVar12) % DAT_00b9bf28;
        if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_1c = DAT_00b9bf18;
        }
        else {
          local_1c = DAT_00b9bf18 + iVar10;
        }
        iVar10 = iVar12 % DAT_00b9bf28;
        if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = DAT_00b9bf18;
        }
        else {
          piVar6 = DAT_00b9bf18 + iVar10;
        }
        iVar10 = FUN_0059a740(iVar7,iVar1,iVar7,iVar8);
        if ((*piVar6 + iVar10 < *local_1c) && ((pCVar5->field_0x12 & 0x40) != 0)) {
          iVar10 = iVar12 % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = (DAT_00b9bf20 + iVar12) % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar3 = DAT_00b9bf18;
          }
          else {
            piVar3 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = FUN_0059a740(iVar7,iVar1,iVar7,iVar1 + 1);
          *piVar3 = *piVar6 + iVar10;
          iVar10 = in_ECX[4];
          if ((iVar10 < 0) || (in_ECX[1] <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = (int *)*in_ECX;
          }
          else {
            piVar6 = (int *)(*in_ECX + iVar10 * 8);
          }
          *piVar6 = iVar7;
          piVar6[1] = iVar1 + 1;
          iVar10 = in_ECX[4];
          in_ECX[4] = iVar10 + 1;
          if ((param_1 == iVar7) && (param_2 == iVar1 + 1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar10 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
        }
      }
      pCVar2 = PTR_0077241c;
      iVar10 = iVar1 + -1;
      iVar8 = PTR_0077241c->cellX0;
      if (PTR_0077241c->cellX0 <= iVar7) {
        iVar8 = iVar7;
      }
      iVar9 = PTR_0077241c->cellY0;
      if (PTR_0077241c->cellY0 <= iVar10) {
        iVar9 = iVar10;
      }
      iVar4 = PTR_0077241c->cellY1 + -1;
      if (iVar9 < PTR_0077241c->cellY1) {
        iVar4 = iVar9;
      }
      iVar9 = PTR_0077241c->cellX1 + -1;
      if (iVar8 < PTR_0077241c->cellX1) {
        iVar9 = iVar8;
      }
      iVar8 = (iVar4 * PTR_0077241c->mapWidth + iVar9) % PTR_0077241c->cellCountTotal;
      if ((iVar8 < 0) || (PTR_0077241c->cellCount <= iVar8)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar5 = pCVar2->cells;
      }
      else {
        pCVar5 = PTR_0077241c->cells + iVar8;
      }
      if (pCVar5->field_0x6 != -1) {
        iVar8 = (iVar12 - DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar8 < 0) || (DAT_00b9bf1c <= iVar8)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_18 = DAT_00b9bf18;
        }
        else {
          local_18 = DAT_00b9bf18 + iVar8;
        }
        iVar8 = iVar12 % DAT_00b9bf28;
        if ((iVar8 < 0) || (DAT_00b9bf1c <= iVar8)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = DAT_00b9bf18;
        }
        else {
          piVar6 = DAT_00b9bf18 + iVar8;
        }
        iVar10 = FUN_0059a740(iVar7,iVar1,iVar7,iVar10);
        if ((*piVar6 + iVar10 < *local_18) && ((pCVar5->field_0x12 & 0x40) != 0)) {
          iVar10 = iVar12 % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = DAT_00b9bf18;
          }
          else {
            local_24 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = (iVar12 - DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = FUN_0059a740(iVar7,iVar1,iVar7,iVar1 + -1);
          *piVar6 = *local_24 + iVar10;
          iVar10 = in_ECX[4];
          if ((iVar10 < 0) || (in_ECX[1] <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = (int *)*in_ECX;
          }
          else {
            piVar6 = (int *)(*in_ECX + iVar10 * 8);
          }
          *piVar6 = iVar7;
          piVar6[1] = iVar1 + -1;
          iVar10 = in_ECX[4];
          in_ECX[4] = iVar10 + 1;
          if ((param_1 == iVar7) && (param_2 == iVar1 + -1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar10 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
        }
      }
      pCVar2 = PTR_0077241c;
      iVar8 = iVar7 + 1;
      iVar10 = PTR_0077241c->cellX0;
      if (PTR_0077241c->cellX0 <= iVar8) {
        iVar10 = iVar8;
      }
      iVar9 = PTR_0077241c->cellY0;
      if (PTR_0077241c->cellY0 <= iVar1) {
        iVar9 = iVar1;
      }
      iVar4 = PTR_0077241c->cellY1 + -1;
      if (iVar9 < PTR_0077241c->cellY1) {
        iVar4 = iVar9;
      }
      iVar9 = PTR_0077241c->cellX1 + -1;
      if (iVar10 < PTR_0077241c->cellX1) {
        iVar9 = iVar10;
      }
      iVar10 = (iVar4 * PTR_0077241c->mapWidth + iVar9) % PTR_0077241c->cellCountTotal;
      if ((iVar10 < 0) || (PTR_0077241c->cellCount <= iVar10)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar5 = pCVar2->cells;
      }
      else {
        pCVar5 = PTR_0077241c->cells + iVar10;
      }
      if (pCVar5->field_0x6 != -1) {
        iVar10 = (iVar12 + 1) % DAT_00b9bf28;
        if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_20 = DAT_00b9bf18;
        }
        else {
          local_20 = DAT_00b9bf18 + iVar10;
        }
        iVar10 = iVar12 % DAT_00b9bf28;
        if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = DAT_00b9bf18;
        }
        else {
          piVar6 = DAT_00b9bf18 + iVar10;
        }
        iVar10 = FUN_0059a740(iVar7,iVar1,iVar8,iVar1);
        if ((*piVar6 + iVar10 < *local_20) && ((pCVar5->field_0x12 & 0x40) != 0)) {
          iVar10 = iVar12 % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = DAT_00b9bf18;
          }
          else {
            local_24 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = (iVar12 + 1) % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = FUN_0059a740(iVar7,iVar1,iVar8,iVar1);
          *piVar6 = *local_24 + iVar10;
          iVar10 = in_ECX[4];
          if ((iVar10 < 0) || (in_ECX[1] <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = (int *)*in_ECX;
          }
          else {
            piVar6 = (int *)(*in_ECX + iVar10 * 8);
          }
          *piVar6 = iVar8;
          piVar6[1] = iVar1;
          iVar10 = in_ECX[4];
          in_ECX[4] = iVar10 + 1;
          if ((param_1 == iVar8) && (param_2 == iVar1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar10 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
        }
      }
      pCVar2 = PTR_0077241c;
      pcVar11 = RaiseException_exref;
      iVar8 = iVar7 + -1;
      iVar10 = PTR_0077241c->cellX0;
      if (PTR_0077241c->cellX0 <= iVar8) {
        iVar10 = iVar8;
      }
      iVar9 = PTR_0077241c->cellY0;
      if (PTR_0077241c->cellY0 <= iVar1) {
        iVar9 = iVar1;
      }
      iVar4 = PTR_0077241c->cellY1 + -1;
      if (iVar9 < PTR_0077241c->cellY1) {
        iVar4 = iVar9;
      }
      iVar9 = PTR_0077241c->cellX1 + -1;
      if (iVar10 < PTR_0077241c->cellX1) {
        iVar9 = iVar10;
      }
      iVar10 = (iVar4 * PTR_0077241c->mapWidth + iVar9) % PTR_0077241c->cellCountTotal;
      if ((iVar10 < 0) || (PTR_0077241c->cellCount <= iVar10)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar5 = pCVar2->cells;
      }
      else {
        pCVar5 = PTR_0077241c->cells + iVar10;
      }
      if (pCVar5->field_0x6 != -1) {
        iVar10 = (iVar12 + -1) % DAT_00b9bf28;
        if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_20 = DAT_00b9bf18;
        }
        else {
          local_20 = DAT_00b9bf18 + iVar10;
        }
        iVar10 = iVar12 % DAT_00b9bf28;
        if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = DAT_00b9bf18;
        }
        else {
          piVar6 = DAT_00b9bf18 + iVar10;
        }
        iVar10 = FUN_0059a740(iVar7,iVar1,iVar8,iVar1);
        if ((*piVar6 + iVar10 < *local_20) && ((pCVar5->field_0x12 & 0x40) != 0)) {
          iVar10 = iVar12 % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = DAT_00b9bf18;
          }
          else {
            local_24 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = (iVar12 + -1) % DAT_00b9bf28;
          if ((iVar10 < 0) || (DAT_00b9bf1c <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = DAT_00b9bf18;
          }
          else {
            piVar6 = DAT_00b9bf18 + iVar10;
          }
          iVar10 = FUN_0059a740(iVar7,iVar1,iVar8,iVar1);
          *piVar6 = *local_24 + iVar10;
          iVar10 = in_ECX[4];
          if ((iVar10 < 0) || (in_ECX[1] <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = (int *)*in_ECX;
          }
          else {
            piVar6 = (int *)(*in_ECX + iVar10 * 8);
          }
          *piVar6 = iVar8;
          piVar6[1] = iVar1;
          iVar10 = in_ECX[4];
          in_ECX[4] = iVar10 + 1;
          if ((param_1 == iVar8) && (param_2 == iVar1)) {
            local_5 = 1;
            DAT_00772dd8 = (int)ROUND((float)(iVar10 + 1) * 1.5);
            if (DAT_00772dd8 <= param_5) {
              DAT_00772dd8 = (int)ROUND((float)in_ECX[4] * 1.5);
              param_5 = DAT_00772dd8;
            }
          }
        }
      }
    }
    iVar10 = in_ECX[3];
    if ((in_ECX[4] == iVar10) || (param_5 <= iVar10)) break;
    if (in_ECX[2] < in_ECX[4] + 4) {
      iVar10 = in_ECX[2] + 0x400;
      in_ECX[2] = iVar10;
      iVar7 = FUN_006baad0("C:\\dev\\wiggles\\Wiggles\\Wiggles\\Map\\MapPathfinder.cpp",0x1ad);
      in_ECX[1] = iVar10;
      pcVar11 = RaiseException_exref;
      *in_ECX = iVar7;
    }
  }
  return CONCAT31((int3)((uint)iVar10 >> 8),local_5);
}

