
void FUN_0057c6e0(void)

{
  uchar *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  CMap *pCVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  CMapCell *pCVar11;
  bool bVar12;
  CMap *local_18;
  
  local_18 = (CMap *)0x0;
  if (0 < in_ECX[1]) {
    iVar10 = 0;
    bVar12 = in_ECX[1] != 0;
    do {
      if (!bVar12) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar8 = *in_ECX;
      *(undefined4 *)(iVar10 + 0xc + iVar8) = 0;
      *(undefined4 *)(iVar10 + 8 + iVar8) = 0;
      *(undefined4 *)(iVar10 + 4 + iVar8) = 0;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(iVar10 + 0x10 + *in_ECX) = 0xffffffff;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(iVar10 + 0x18 + *in_ECX) = 0xbf800000;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(iVar10 + 0x14 + *in_ECX) = 0xbf800000;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(iVar10 + 0x1c + *in_ECX) = 0xbf800000;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)(iVar10 + 0x20 + *in_ECX) = 0xbf800000;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined1 *)(iVar10 + 0x24 + *in_ECX) = 0;
      if ((uint)in_ECX[1] <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = (int *)(DAT_0077244c + 0x488);
      if (*(uint *)(iVar10 + *in_ECX) < 0x2000) {
        piVar2 = piVar2 + *(uint *)(iVar10 + *in_ECX);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_00555b60(*(int *)(*piVar2 + 0xd4) + 0xc90);
      iVar10 = iVar10 + 0x28;
      local_18 = (CMap *)((int)local_18 + 1);
      bVar12 = local_18 < (uint)in_ECX[1];
    } while ((int)local_18 < in_ECX[1]);
  }
  iVar10 = *(int *)((int)in_ECX + 0xcb1);
  if (iVar10 < 0) {
    iVar8 = iVar10;
    if ((iVar10 + 0x1fU & 0xffffffe0) != 0) {
      uVar3 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar8 = *(int *)((int)in_ECX + 0xcb1);
      *(undefined4 *)((int)in_ECX + 0xcad) = uVar3;
    }
    *(int *)((int)in_ECX + 0xcb1) = iVar8 - iVar10;
  }
  else if (0 < iVar10) {
    *(undefined4 *)((int)in_ECX + 0xcb1) = 0;
  }
  iVar10 = in_ECX[0x322];
  if (iVar10 < 0) {
    iVar8 = iVar10;
    if ((iVar10 + 0x3fU & 0xffffffc0) != 0) {
      iVar4 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar8 = in_ECX[0x322];
      in_ECX[0x321] = iVar4;
    }
    in_ECX[0x322] = iVar8 - iVar10;
  }
  else if (0 < iVar10) {
    in_ECX[0x322] = 0;
  }
  iVar10 = in_ECX[0x324];
  if (iVar10 < 0) {
    iVar8 = iVar10;
    if ((iVar10 + 0x3fU & 0xffffffc0) != 0) {
      iVar4 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar8 = in_ECX[0x324];
      in_ECX[0x323] = iVar4;
    }
    in_ECX[0x324] = iVar8 - iVar10;
  }
  else if (0 < iVar10) {
    in_ECX[0x324] = 0;
  }
  iVar10 = in_ECX[0x31e];
  if (iVar10 < 0) {
    iVar8 = iVar10;
    if ((iVar10 + 0x3fU & 0xffffffc0) != 0) {
      iVar4 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar8 = in_ECX[0x31e];
      in_ECX[0x31d] = iVar4;
    }
    in_ECX[0x31e] = iVar8 - iVar10;
  }
  else if (0 < iVar10) {
    in_ECX[0x31e] = 0;
  }
  iVar10 = in_ECX[800];
  if (iVar10 < 0) {
    iVar8 = iVar10;
    if ((iVar10 + 0x3fU & 0xffffffc0) != 0) {
      iVar4 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar8 = in_ECX[800];
      in_ECX[799] = iVar4;
    }
    in_ECX[800] = iVar8 - iVar10;
  }
  else if (0 < iVar10) {
    in_ECX[800] = 0;
  }
  local_18 = PTR_0077241c;
  iVar10 = PTR_0077241c->cellY0;
  pCVar5 = PTR_0077241c;
  if (PTR_0077241c->cellY1 <= iVar10) {
    in_ECX[0x31b] = 0;
    return;
  }
  do {
    iVar8 = pCVar5->cellX0;
    if (iVar8 < pCVar5->cellX1) {
      do {
        iVar4 = pCVar5->cellX0;
        if (pCVar5->cellX0 <= iVar8) {
          iVar4 = iVar8;
        }
        iVar7 = pCVar5->cellY0;
        if (pCVar5->cellY0 <= iVar10) {
          iVar7 = iVar10;
        }
        iVar6 = pCVar5->cellY1 + -1;
        if (iVar7 < pCVar5->cellY1) {
          iVar6 = iVar7;
        }
        iVar7 = pCVar5->cellX1 + -1;
        if (iVar4 < pCVar5->cellX1) {
          iVar7 = iVar4;
        }
        iVar4 = (iVar6 * local_18->mapWidth + iVar7) % local_18->cellCountTotal;
        if ((iVar4 < 0) || (local_18->cellCount <= iVar4)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar11 = local_18->cells;
        }
        else {
          pCVar11 = local_18->cells + iVar4;
        }
        uVar9 = 0;
        do {
          if (uVar9 < 2) {
            puVar1 = pCVar11->ownerIndex + uVar9 * 4 + -0x18;
            puVar1[0] = '\0';
            puVar1[1] = '\0';
            puVar1[2] = '\0';
            puVar1[3] = '\0';
            pCVar11->ownerIndex[uVar9 - 0x1a] = '\0';
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *(undefined4 *)&pCVar11->field_0x1c = 0;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar11->field_0x1a = 0;
          }
          pCVar5 = PTR_0077241c;
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 < 2);
        local_18 = PTR_0077241c;
        pCVar11->flags = pCVar11->flags & 0xfb;
        iVar8 = iVar8 + 1;
      } while (iVar8 < pCVar5->cellX1);
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < pCVar5->cellY1);
  in_ECX[0x31b] = 0;
  return;
}

