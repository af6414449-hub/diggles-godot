
void FUN_004f4720(int param_1)

{
  CHeightBlockArray *pCVar1;
  CMap *pCVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  CMap *this;
  CHeightBlock *pCVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  uint local_8;
  
  if (param_1 != 0) {
    local_8 = (uint)ROUND(*(float *)(param_1 + 0xc) * 8.0);
    uVar7 = (int)ROUND(*(float *)(param_1 + 0x10) * 8.0) - 2;
    DAT_00772dd8 = (int)ROUND(*(float *)(param_1 + 0x14));
    local_c = DAT_00772dd8;
    if ((((PTR_0077241c != (CMap *)0x0) && ((char)PTR_0077241c->mapFlags != '\0')) &&
        (cVar3 = FUN_00409450(local_8,uVar7,0x40), cVar3 != '\0')) &&
       (uVar4 = FUN_004093f0(this), iVar8 = 0x19, (int)(uVar4 & 0xff) < local_c)) {
      do {
        pCVar2 = PTR_0077241c;
        iVar9 = iVar8 + -1;
        if (iVar8 < 1) break;
        uVar7 = uVar7 + 1;
        piVar5 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar1 = pCVar2->heightBlocks;
        iVar8 = *piVar5;
        if ((iVar8 < 0) || (pCVar1->count <= iVar8)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar6 = pCVar1->data;
        }
        else {
          pCVar6 = pCVar1->data + iVar8;
        }
        iVar8 = iVar9;
      } while ((int)(uint)pCVar6->heights[(uVar7 & 7) << 3 | local_8 & 7] < local_c);
      if (iVar9 < 1) {
        return;
      }
    }
    local_18 = *(float *)(param_1 + 0xc);
    local_10 = *(float *)(param_1 + 0x14);
    local_14 = (float)(int)uVar7 * 0.125;
    if ((((NAN(local_18)) || (*(float *)(param_1 + 0x10) != local_14)) || (NAN(local_10))) &&
       (FUN_005cd8e0(&local_18), *(int *)(param_1 + 0x238) == 0)) {
      FUN_005ebc90(param_1);
      FUN_005eb470(param_1);
    }
  }
  return;
}

