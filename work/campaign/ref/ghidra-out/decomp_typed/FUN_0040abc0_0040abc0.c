
undefined4
FUN_0040abc0(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4,int *param_5)

{
  float fVar1;
  double dVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  int this;
  int iVar10;
  byte *pbVar11;
  char *pcVar12;
  uint uVar13;
  bool bVar14;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f98fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  if (param_5 != (int *)0x0) {
    *param_5 = *param_5 + 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = *param_4 + 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = *param_3 + 1;
  }
  cVar4 = FUN_00406630(param_1,param_2,param_3);
  if (cVar4 != '\0') {
    iVar8 = this->i_0c;
    if ((*(uint *)(iVar8 + 0x3d0) & 0x2000) != 0) {
      this->i_2c = this->i_2c + 1;
    }
    FUN_006b49b0(iVar8,this->i_2c,this->i_30);
    dVar2 = *(double *)(DAT_00772400 + 0xa088);
    this->d_60 = dVar2 + (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    *(undefined4 *)(iVar8 + 0x24c) = 0;
    uVar13 = 0;
    if (0 < this->i_28) {
      do {
        iVar8 = (int)ROUND((float)(dVar2 * 10.0));
        uVar5 = this->i_28;
        DAT_00772dd8 = iVar8;
        if (uVar5 <= uVar13) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar5 = this->i_28;
        }
        iVar10 = this->i_24;
        piVar6 = (int *)(iVar10 + uVar13 * 4);
        if (uVar5 <= uVar13) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = this->i_24;
        }
        *(int *)(iVar10 + uVar13 * 4) = *piVar6 + iVar8;
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < this->i_28);
    }
    uVar13 = *(uint *)(this->i_1c + 0x39c);
    uVar5 = *(uint *)(this->i_1c + 0x3a0);
    if ((uVar5 | uVar13) != 0xffffffff) {
      piVar6 = (int *)(DAT_00772400 + 0x5c8);
      if (uVar13 < 0x100) {
        piVar6 = piVar6 + uVar13;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar7 = (int *)(*piVar6 + 0x34);
      if (((int)uVar5 < 0) || (*(int *)(*piVar6 + 0x38) <= (int)uVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = *piVar7;
      }
      else {
        iVar8 = *piVar7 + uVar5 * 0xe8;
      }
      fVar1 = *(float *)(iVar8 + 0x48);
      piVar6 = (int *)(DAT_00772400 + 0x5c8);
      if (uVar13 < 0x100) {
        piVar6 = piVar6 + uVar13;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar7 = (int *)(*piVar6 + 0x34);
      if (((int)uVar5 < 0) || (*(int *)(*piVar6 + 0x38) <= (int)uVar5)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = *piVar7;
      }
      else {
        iVar8 = *piVar7 + uVar5 * 0xe8;
      }
      pbVar11 = &DAT_0071ce84;
      this->f_58 = (fVar1 * 0.005 - *(float *)(iVar8 + 0x54) * 0.005) * 0.5;
      iVar8 = *(int *)(*(int *)(this->i_1c + 0xd4) + 0xc);
      pbVar9 = (byte *)(iVar8 + 0xc);
      do {
        bVar3 = *pbVar9;
        bVar14 = bVar3 < *pbVar11;
        if (bVar3 != *pbVar11) {
LAB_0040aeb0:
          uVar13 = -(uint)bVar14 | 1;
          goto LAB_0040aeb5;
        }
        if (bVar3 == 0) break;
        bVar3 = pbVar9[1];
        bVar14 = bVar3 < pbVar11[1];
        if (bVar3 != pbVar11[1]) goto LAB_0040aeb0;
        pbVar9 = pbVar9 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar3 != 0);
      uVar13 = 0;
LAB_0040aeb5:
      if (uVar13 == 0) {
        this->c_55 = 1;
      }
      else {
        pcVar12 = "Plattmachfalle";
        pbVar9 = (byte *)(iVar8 + 0xc);
        do {
          bVar3 = *pbVar9;
          bVar14 = bVar3 < (byte)*pcVar12;
          if (bVar3 != *pcVar12) {
LAB_0040aee7:
            uVar13 = -(uint)bVar14 | 1;
            goto LAB_0040aeec;
          }
          if (bVar3 == 0) break;
          bVar3 = pbVar9[1];
          bVar14 = bVar3 < ((byte *)pcVar12)[1];
          if (bVar3 != ((byte *)pcVar12)[1]) goto LAB_0040aee7;
          pbVar9 = pbVar9 + 2;
          pcVar12 = (char *)((byte *)pcVar12 + 2);
        } while (bVar3 != 0);
        uVar13 = 0;
LAB_0040aeec:
        if (uVar13 == 0) {
          this->f_58 = 0xbfe66666;
        }
      }
      iVar8 = this->i_0c;
      FUN_0040a590(*(float *)(iVar8 + 0xc) + 0.0,*(float *)(iVar8 + 0x10) - 0.5,
                   *(float *)(iVar8 + 0x14) + 0.0,*(float *)(this->i_1c + 0xc) + 0.0);
      if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
        TclFreeObj();
      }
      if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
        TclFreeObj();
      }
      if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
        TclFreeObj();
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    TclFreeObj();
  }
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 < 1)) {
    TclFreeObj();
  }
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj();
  }
  ExceptionList = local_10;
  return 0;
}

