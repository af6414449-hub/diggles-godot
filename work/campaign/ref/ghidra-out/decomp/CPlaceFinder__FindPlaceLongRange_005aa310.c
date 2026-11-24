
float * CPlaceFinder__FindPlaceLongRange
                  (float *param_1,int param_2,int param_3,char param_4,char param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  float fVar13;
  float in_XMM3_Da;
  undefined8 uVar14;
  uint local_2c;
  uint local_28;
  int local_20;
  int local_1c;
  
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5558) &&
     (FUN_006cebf4(&DAT_00ca5558), iVar2 = DAT_00783650, DAT_00ca5558 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00ca555c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "CPlaceFinder::FindPlaceLongRange()";
    *(int *)(&DAT_00773650 + iVar12) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5558);
  }
  iVar12 = DAT_00ca555c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca555c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar2 == 0) {
    uVar14 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar2 + 1;
  fVar13 = (float)param_2 - in_XMM3_Da;
  DAT_00772dd8 = (int)ROUND(fVar13);
  iVar2 = *(int *)(DAT_0077241c + 0x84);
  if (*(int *)(DAT_0077241c + 0x84) <= DAT_00772dd8) {
    iVar2 = DAT_00772dd8;
  }
  iVar12 = *(int *)(DAT_0077241c + 0x8c);
  if ((int)ROUND((float)param_2 + in_XMM3_Da) <= *(int *)(DAT_0077241c + 0x8c)) {
    iVar12 = (int)ROUND((float)param_2 + in_XMM3_Da);
  }
  iVar8 = *(int *)(DAT_0077241c + 0x88);
  if (*(int *)(DAT_0077241c + 0x88) <= (int)ROUND((float)param_3 - in_XMM3_Da)) {
    iVar8 = (int)ROUND((float)param_3 - in_XMM3_Da);
  }
  iVar9 = *(int *)(DAT_0077241c + 0x90);
  if ((int)ROUND((float)param_3 + in_XMM3_Da) <= *(int *)(DAT_0077241c + 0x90)) {
    iVar9 = (int)ROUND((float)param_3 + in_XMM3_Da);
  }
  uVar11 = 0xffffffff;
  local_20 = -1;
  local_2c = 0xffffffff;
  local_28 = 0xffffffff;
  do {
    iVar5 = iVar2;
    iVar3 = DAT_0077241c;
    if (iVar9 <= iVar8) {
      *param_1 = -1.0;
      param_1[1] = -1.0;
      param_1[2] = -1.0;
      if (uVar11 != 0xffffffff) {
        if ((param_4 != '\0') &&
           (iVar2 = FUN_00592f10((int)uVar11 >> 3,(int)local_28 >> 3),
           (*(byte *)(((local_28 & 7) << 3 | uVar11 & 7) + 0x3c + iVar2) & 2) == 0)) {
          local_1c = 8;
          iVar2 = (int)(((int)uVar11 >> 0x1f & 7U) + uVar11) >> 3;
          iVar12 = (int)(((int)local_28 >> 0x1f & 7U) + local_28) >> 3;
          do {
            iVar12 = iVar12 + 1;
            iVar8 = FUN_00592f10(iVar2,iVar12);
            if ((*(byte *)(iVar8 + 0x12) & 0x40) != 0) {
              iVar8 = FUN_00592f10(iVar2,iVar12);
              local_2c = (*(byte *)(iVar8 + 0x12) & 7) + iVar2 * 8;
              iVar8 = FUN_00592f10(iVar2,iVar12);
              local_28 = (*(byte *)(iVar8 + 0x12) >> 3 & 7) + iVar12 * 8;
            }
            local_1c = local_1c + -1;
            uVar11 = local_2c;
          } while (local_1c != 0);
        }
        iVar2 = DAT_0077241c;
        param_1[2] = 0.0;
        iVar8 = (int)uVar11 >> 3;
        *param_1 = (float)(int)uVar11 * 0.125;
        param_1[1] = (float)(int)local_28 * 0.125;
        iVar12 = *(int *)(iVar2 + 0x84);
        if (*(int *)(iVar2 + 0x84) <= iVar8) {
          iVar12 = iVar8;
        }
        iVar9 = *(int *)(iVar2 + 0x88);
        if (*(int *)(iVar2 + 0x88) <= (int)local_28 >> 3) {
          iVar9 = (int)local_28 >> 3;
        }
        iVar5 = *(int *)(iVar2 + 0x90) + -1;
        if (iVar9 < *(int *)(iVar2 + 0x90)) {
          iVar5 = iVar9;
        }
        iVar9 = *(int *)(iVar2 + 0x8c) + -1;
        if (iVar12 < *(int *)(iVar2 + 0x8c)) {
          iVar9 = iVar12;
        }
        iVar12 = (iVar5 * *(int *)(iVar2 + 0x44) + iVar9) % *(int *)(iVar2 + 0x4c);
        if ((iVar12 < 0) || (*(int *)(iVar2 + 0x18) <= iVar12)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = *(int *)(iVar2 + 0x14);
        }
        else {
          iVar2 = iVar12 * 0x7c + *(int *)(iVar2 + 0x14);
        }
        iVar12 = DAT_0077241c;
        if ((*(byte *)(((local_28 & 7) << 3 | local_2c & 7) + 0x3c + iVar2) & 2) == 0) {
          FUN_004238e0();
          param_1[2] = fVar13;
        }
        else {
          piVar6 = (int *)FUN_00592f10(iVar8,(int)(local_28 - 2) >> 3);
          iVar2 = *(int *)(iVar12 + 0x24);
          iVar12 = *piVar6;
          if ((iVar12 < 0) || (*(int *)(iVar2 + 0x14) <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar2 = *(int *)(iVar2 + 0x10);
          }
          else {
            iVar2 = iVar12 * 0x59 + *(int *)(iVar2 + 0x10);
          }
          iVar12 = *(byte *)(((local_28 - 2 & 7) << 3 | local_2c & 7) + iVar2) + 1;
          iVar2 = _rand();
          param_1[2] = (float)(iVar2 * (0xf - iVar12)) * 3.0517578e-05 + (float)iVar12;
        }
      }
      FUN_0043fd30();
      return param_1;
    }
    for (; DAT_0077241c = iVar3, iVar5 < iVar12; iVar5 = iVar5 + 1) {
      iVar10 = *(int *)(iVar3 + 0x84);
      if (*(int *)(iVar3 + 0x84) <= iVar5) {
        iVar10 = iVar5;
      }
      iVar7 = *(int *)(iVar3 + 0x88);
      if (*(int *)(iVar3 + 0x88) <= iVar8) {
        iVar7 = iVar8;
      }
      iVar4 = *(int *)(iVar3 + 0x90) + -1;
      if (iVar7 < *(int *)(iVar3 + 0x90)) {
        iVar4 = iVar7;
      }
      iVar7 = *(int *)(iVar3 + 0x8c) + -1;
      if (iVar10 < *(int *)(iVar3 + 0x8c)) {
        iVar7 = iVar10;
      }
      iVar10 = (iVar4 * *(int *)(iVar3 + 0x44) + iVar7) % *(int *)(iVar3 + 0x4c);
      if ((iVar10 < 0) || (*(int *)(iVar3 + 0x18) <= iVar10)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(iVar3 + 0x14);
      }
      else {
        iVar3 = iVar10 * 0x7c + *(int *)(iVar3 + 0x14);
      }
      iVar10 = DAT_0077241c;
      if (*(char *)(iVar3 + 6) != -1) {
        if (param_5 != '\0') {
          iVar3 = *(int *)(DAT_0077241c + 0x84);
          if (*(int *)(DAT_0077241c + 0x84) <= iVar5) {
            iVar3 = iVar5;
          }
          iVar7 = *(int *)(DAT_0077241c + 0x88);
          if (*(int *)(DAT_0077241c + 0x88) <= iVar8) {
            iVar7 = iVar8;
          }
          iVar4 = *(int *)(DAT_0077241c + 0x90) + -1;
          if (iVar7 < *(int *)(DAT_0077241c + 0x90)) {
            iVar4 = iVar7;
          }
          iVar7 = *(int *)(DAT_0077241c + 0x8c) + -1;
          if (iVar3 < *(int *)(DAT_0077241c + 0x8c)) {
            iVar7 = iVar3;
          }
          iVar3 = (iVar4 * *(int *)(DAT_0077241c + 0x44) + iVar7) % *(int *)(DAT_0077241c + 0x4c);
          if ((iVar3 < 0) || (*(int *)(DAT_0077241c + 0x18) <= iVar3)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(iVar10 + 0x14);
          }
          else {
            iVar3 = iVar3 * 0x7c + *(int *)(DAT_0077241c + 0x14);
          }
          if ((*(byte *)(iVar3 + 0x12) & 0x40) == 0) goto LAB_005aa602;
        }
        iVar3 = _rand();
        if (local_20 < iVar3) {
          iVar10 = FUN_00592f10(iVar5,iVar8);
          local_28 = (*(byte *)(iVar10 + 0x12) >> 3 & 7) + iVar8 * 8;
          iVar10 = FUN_00592f10(iVar5,iVar8);
          local_2c = (*(byte *)(iVar10 + 0x12) & 7) + iVar5 * 8;
          local_20 = iVar3;
        }
      }
LAB_005aa602:
      uVar11 = local_2c;
      iVar3 = DAT_0077241c;
    }
    iVar8 = iVar8 + 1;
  } while( true );
}

