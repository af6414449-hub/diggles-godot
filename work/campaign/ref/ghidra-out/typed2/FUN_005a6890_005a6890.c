
void FUN_005a6890(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char cVar14;
  uint uVar15;
  int *piVar16;
  int iVar17;
  
  iVar4 = DAT_0077244c;
  iVar5 = (int)(*param_1 + (*param_1 >> 0x1f & 7U)) >> 3;
  iVar6 = (int)(param_1[3] + 7 + (param_1[3] + 7 >> 0x1f & 7U)) >> 3;
  iVar7 = (int)(param_1[1] + (param_1[1] >> 0x1f & 7U)) >> 3;
  iVar8 = (int)(param_1[2] + 7 + (param_1[2] + 7 >> 0x1f & 7U)) >> 3;
  uVar15 = 0xffffffff;
  while( true ) {
    uVar15 = uVar15 + 1;
    if ((int)*(uint *)(iVar4 + 0x84c6) <= (int)uVar15) break;
    if (*(uint *)(iVar4 + 0x84c6) <= uVar15) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar1 = *(uint *)(*(int *)(iVar4 + 0x84c2) + uVar15 * 4);
    piVar16 = (int *)(iVar4 + 0x488);
    if (uVar1 < 0x2000) {
      piVar16 = piVar16 + uVar1;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar2 = *piVar16;
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x264) != 0)) &&
       ((*(uint *)(iVar2 + 0x3d0) & 0x400001) == 0x400001)) {
      DAT_00772dd8 = (int)ROUND(*(float *)(iVar2 + 0xc) * 8.0);
      iVar9 = *(int *)(iVar2 + 0x254) + DAT_00772dd8;
      iVar10 = (int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3;
      iVar9 = (int)ROUND(*(float *)(iVar2 + 0x10) * 8.0) + 7 + *(int *)(iVar2 + 0x260);
      iVar11 = (int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3;
      iVar9 = *(int *)(iVar2 + 600) + (int)ROUND(*(float *)(iVar2 + 0x10) * 8.0);
      iVar9 = (int)((iVar9 >> 0x1f & 7U) + iVar9) >> 3;
      iVar12 = (int)ROUND(*(float *)(iVar2 + 0xc) * 8.0) + 7 + *(int *)(iVar2 + 0x25c);
      iVar12 = (int)((iVar12 >> 0x1f & 7U) + iVar12) >> 3;
      if (((iVar10 < iVar8) && (iVar5 < iVar12)) && ((iVar9 < iVar6 && (iVar7 < iVar11)))) {
        if (iVar10 < iVar5) {
          iVar10 = iVar5;
        }
        if (iVar6 < iVar11) {
          iVar11 = iVar6;
        }
        if (iVar9 < iVar7) {
          iVar9 = iVar7;
        }
        if (iVar8 < iVar12) {
          iVar12 = iVar8;
        }
        if (iVar10 < iVar12) {
          for (; iVar17 = iVar10, iVar9 < iVar11; iVar9 = iVar9 + 1) {
            do {
              iVar13 = FUN_00592f10(PTR_0077241c);
              iVar3 = *(int *)(iVar2 + 0x264);
              if ((iVar3 == 0x7fffffff) || (*(char *)(iVar13 + 6) == -1)) {
                cVar14 = -1;
              }
              else if (iVar3 == -0x80000000) {
                cVar14 = '\x01';
              }
              else {
                cVar14 = *(char *)(iVar13 + 6) + (char)iVar3;
                if (cVar14 == '\0') {
                  cVar14 = '\x01';
                }
                else if (cVar14 == -1) {
                  cVar14 = -2;
                }
              }
              iVar17 = iVar17 + 1;
              *(char *)(iVar13 + 6) = cVar14;
            } while (iVar17 < iVar12);
          }
        }
      }
    }
  }
  return;
}

