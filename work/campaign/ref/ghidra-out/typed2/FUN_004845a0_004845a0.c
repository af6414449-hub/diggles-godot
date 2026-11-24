
void FUN_004845a0(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *in_ECX;
  uint uVar9;
  int *piVar10;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((int)in_ECX[1] < 8) {
    if ((((PTR_0077241c->x0f + 12.0 <= *(float *)(param_1 + 0xc)) &&
         (*(float *)(param_1 + 0xc) < PTR_0077241c->x1f - 12.0)) &&
        (PTR_0077241c->y0f + 12.0 <= *(float *)(param_1 + 0x10))) &&
       (*(float *)(param_1 + 0x10) < PTR_0077241c->y1f - 12.0)) {
      iVar3 = FUN_005cb3a0(*(undefined4 *)(DAT_00772400 + 100));
      if (((0x7f < iVar3) && (*(int *)(param_1 + 0x39c) != -1)) &&
         (iVar3 = *(int *)(param_1 + 0x3a0), iVar3 != -1)) {
        FUN_0040b550(*(int *)(param_1 + 0x39c));
        iVar3 = FUN_004059a0(iVar3);
        uVar5 = *(undefined4 *)(param_1 + 0x3a0);
        fVar1 = *(float *)(iVar3 + 0x44);
        local_8 = *(float *)(iVar3 + 0x48);
        local_c = *(float *)(iVar3 + 0x4c);
        FUN_0040b550(*(undefined4 *)(param_1 + 0x39c));
        iVar3 = FUN_004059a0(uVar5);
        local_24 = fVar1 - 500.0;
        local_20 = local_8 - 500.0;
        local_1c = local_c - 500.0;
        local_18 = *(float *)(iVar3 + 0x50) + 500.0;
        local_14 = *(float *)(iVar3 + 0x54) + 500.0;
        local_10 = *(float *)(iVar3 + 0x58) + 500.0;
        cVar2 = FUN_00472e80(param_1 + 0xc,param_1 + 0x40,&local_24,&local_18);
        if (cVar2 != '\0') {
          puVar4 = (undefined4 *)FUN_006ba810(0x1c3);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            *puVar4 = 0;
            puVar4[1] = 0;
          }
          FUN_004830a0(param_1);
          uVar9 = in_ECX[1];
          if ((uVar9 + 0x10 & 0xfffffff0) != (uVar9 + 0xf & 0xfffffff0)) {
            uVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                 ,0x9b);
            uVar9 = in_ECX[1];
            *in_ECX = uVar5;
          }
          uVar6 = uVar9 + 1;
          in_ECX[1] = uVar6;
          if (uVar6 <= uVar9) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar6 = in_ECX[1];
          }
          puVar7 = (undefined4 *)FUN_0040b900(uVar6 - 1);
          piVar10 = (int *)(param_1 + 0x37c);
          *puVar7 = puVar4;
          if (*(uint *)(DAT_00772400 + 100) < 8) {
            piVar10 = piVar10 + *(uint *)(DAT_00772400 + 100);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar3 = *piVar10;
          if (iVar3 != -1) {
            iVar8 = FUN_005b78b0();
            if ((iVar3 < 0) || (*(int *)(iVar8 + 0xc00c) <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(iVar8 + 0xc008);
            }
            else {
              iVar3 = iVar3 * 0xd8 + *(int *)(iVar8 + 0xc008);
            }
            FUN_00453f00(iVar3);
          }
          *(undefined1 *)(param_1 + 0x3b4) = 1;
        }
      }
    }
  }
  return;
}

