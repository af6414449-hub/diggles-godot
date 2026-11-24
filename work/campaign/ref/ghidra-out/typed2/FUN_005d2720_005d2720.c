
void FUN_005d2720(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  uint uVar8;
  int *piVar9;
  float fVar10;
  double dVar11;
  
  iVar6 = DAT_00772400;
  if (*(char *)(DAT_00772400 + 0xa098) != '\0') {
    dVar4 = *(double *)(DAT_00772400 + 0xa0b0);
    dVar11 = *(double *)(in_ECX + 0x410);
    if (*(double *)(in_ECX + 0x410) == 0.0) {
      dVar11 = dVar4;
    }
    *(double *)(in_ECX + 0x410) = dVar4;
    fVar10 = (float)(dVar4 - dVar11);
    if ((*(char *)(iVar6 + 0x8a) != '\0') && ((char)PTR_0077241c->mapFlags != '\0')) {
      uVar8 = 0xffffffff;
      while( true ) {
        uVar8 = uVar8 + 1;
        if ((int)*(uint *)(in_ECX + 0x84b5) <= (int)uVar8) break;
        if (*(uint *)(in_ECX + 0x84b5) <= uVar8) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar9 = (int *)(in_ECX + 0x488);
        uVar5 = *(uint *)(*(int *)(in_ECX + 0x84b1) + uVar8 * 4);
        if (uVar5 < 0x2000) {
          piVar7 = piVar9 + uVar5;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar7 = piVar9;
        }
        if (*piVar7 != 0) {
          if (uVar5 < 0x2000) {
            piVar7 = piVar9 + uVar5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar7 = piVar9;
          }
          iVar6 = *piVar7;
          if (((*(float *)(iVar6 + 0x28) != 0.0) || (*(float *)(iVar6 + 0x2c) != 0.0)) ||
             (*(float *)(iVar6 + 0x30) != 0.0)) {
            if (uVar5 < 0x2000) {
              piVar7 = piVar9 + uVar5;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar7 = piVar9;
            }
            iVar6 = *piVar7;
            fVar1 = *(float *)(iVar6 + 0x28);
            fVar2 = *(float *)(iVar6 + 0x30);
            fVar3 = *(float *)(iVar6 + 0x2c);
            if (uVar5 < 0x2000) {
              piVar9 = piVar9 + uVar5;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *piVar9;
            *(float *)(iVar6 + 0xc) = *(float *)(iVar6 + 0xc) + fVar1 * fVar10;
            *(float *)(iVar6 + 0x14) = fVar2 * fVar10 + *(float *)(iVar6 + 0x14);
            *(float *)(iVar6 + 0x10) = *(float *)(iVar6 + 0x10) + fVar3 * fVar10;
          }
        }
      }
    }
  }
  return;
}

