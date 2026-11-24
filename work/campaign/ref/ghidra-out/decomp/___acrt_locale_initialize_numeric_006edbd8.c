
/* Library Function - Single Match
    ___acrt_locale_initialize_numeric
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_locale_initialize_numeric(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  undefined **_Memory;
  byte *pbVar10;
  undefined4 *puVar11;
  undefined **ppuVar12;
  int local_18 [3];
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_18[0] = param_1;
  local_18[1] = 0;
  if ((*(int *)(param_1 + 0xb0) == 0) && (*(int *)(param_1 + 0xac) == 0)) {
    puVar11 = (undefined4 *)0x0;
    local_8 = (undefined4 *)0x0;
    _Memory = &PTR_DAT_007678d8;
  }
  else {
    local_18[2] = 1;
    _Memory = (undefined **)__calloc_base(1,0x50);
    if (_Memory == (undefined **)0x0) {
      return 1;
    }
    puVar11 = *(undefined4 **)(param_1 + 0x88);
    ppuVar12 = _Memory;
    for (iVar8 = 0x14; iVar8 != 0; iVar8 = iVar8 + -1) {
      *ppuVar12 = (undefined *)*puVar11;
      puVar11 = puVar11 + 1;
      ppuVar12 = ppuVar12 + 1;
    }
    puVar11 = (undefined4 *)__malloc_base(4);
    local_8 = puVar11;
    FID_conflict__free((void *)0x0);
    if (puVar11 == (undefined4 *)0x0) {
      FID_conflict__free(_Memory);
      return 1;
    }
    *puVar11 = 0;
    if (*(int *)(param_1 + 0xb0) == 0) {
      *_Memory = PTR_DAT_007678d8;
      _Memory[1] = PTR_DAT_007678dc;
      _Memory[2] = PTR_DAT_007678e0;
      _Memory[0xc] = PTR_DAT_00767908;
      _Memory[0xd] = PTR_DAT_0076790c;
      puVar11 = (undefined4 *)0x0;
    }
    else {
      puVar11 = (undefined4 *)__malloc_base(4);
      local_c = puVar11;
      FID_conflict__free((void *)0x0);
      if (puVar11 == (undefined4 *)0x0) {
        FID_conflict__free(_Memory);
LAB_006edd22:
        FID_conflict__free(local_8);
        return local_18[2];
      }
      *puVar11 = 0;
      uVar2 = *(undefined4 *)(param_1 + 0xb0);
      iVar8 = ___acrt_GetLocaleInfoA(local_18,1,uVar2,0xe);
      iVar4 = ___acrt_GetLocaleInfoA(local_18,1,uVar2,0xf,_Memory + 1);
      iVar5 = ___acrt_GetLocaleInfoA(local_18,1,uVar2,0x10,_Memory + 2);
      iVar6 = ___acrt_GetLocaleInfoA(local_18,2,uVar2,0xe,_Memory + 0xc);
      iVar7 = ___acrt_GetLocaleInfoA(local_18,2,uVar2,0xf,_Memory + 0xd);
      if (iVar7 != 0 || (((iVar8 != 0 || iVar4 != 0) || iVar5 != 0) || iVar6 != 0)) {
        ___acrt_locale_free_numeric(_Memory);
        FID_conflict__free(_Memory);
        FID_conflict__free(local_c);
        local_18[2] = 0xffffffff;
        goto LAB_006edd22;
      }
      pbVar9 = _Memory[2];
      while (bVar1 = *pbVar9, puVar11 = local_c, bVar1 != 0) {
        if ((byte)(bVar1 - 0x30) < 10) {
          *pbVar9 = bVar1 - 0x30;
LAB_006edd40:
          pbVar9 = pbVar9 + 1;
        }
        else {
          pbVar10 = pbVar9;
          if (bVar1 != 0x3b) goto LAB_006edd40;
          do {
            bVar1 = pbVar10[1];
            *pbVar10 = bVar1;
            pbVar10 = pbVar10 + 1;
          } while (bVar1 != 0);
        }
      }
    }
    *local_8 = 1;
    if (puVar11 != (undefined4 *)0x0) {
      *puVar11 = 1;
    }
  }
  piVar3 = *(int **)(param_1 + 0x80);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
  }
  piVar3 = *(int **)(param_1 + 0x7c);
  if (piVar3 != (int *)0x0) {
    LOCK();
    iVar8 = *piVar3;
    *piVar3 = iVar8 + -1;
    UNLOCK();
    if (iVar8 + -1 == 0) {
      FID_conflict__free(*(void **)(param_1 + 0x7c));
      FID_conflict__free(*(void **)(param_1 + 0x88));
    }
  }
  *(undefined4 **)(param_1 + 0x7c) = local_8;
  *(undefined4 **)(param_1 + 0x80) = puVar11;
  *(undefined ***)(param_1 + 0x88) = _Memory;
  return 0;
}

