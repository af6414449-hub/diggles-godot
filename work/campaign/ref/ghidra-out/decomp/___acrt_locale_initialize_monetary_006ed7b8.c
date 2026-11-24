
/* Library Function - Single Match
    ___acrt_locale_initialize_monetary
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_locale_initialize_monetary(int param_1)

{
  byte bVar1;
  int *piVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined4 uVar26;
  byte *pbVar27;
  byte *pbVar28;
  undefined **ppuVar29;
  int local_1c [2];
  undefined **local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined **local_8;
  
  local_10 = (undefined4 *)0x0;
  local_1c[0] = param_1;
  local_1c[1] = 0;
  if ((*(int *)(param_1 + 0xac) == 0) && (*(int *)(param_1 + 0xb0) == 0)) {
    local_c = (undefined4 *)0x0;
    ppuVar3 = &PTR_DAT_007678d8;
LAB_006edb24:
    puVar4 = local_10;
    piVar2 = *(int **)(param_1 + 0x84);
    if (piVar2 != (int *)0x0) {
      LOCK();
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    piVar2 = *(int **)(param_1 + 0x7c);
    if (piVar2 != (int *)0x0) {
      LOCK();
      iVar5 = *piVar2;
      *piVar2 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        FID_conflict__free(*(void **)(param_1 + 0x88));
        FID_conflict__free(*(void **)(param_1 + 0x7c));
      }
    }
    *(undefined4 **)(param_1 + 0x7c) = local_c;
    uVar26 = 0;
    *(undefined4 **)(param_1 + 0x84) = puVar4;
    *(undefined ***)(param_1 + 0x88) = ppuVar3;
  }
  else {
    ppuVar3 = (undefined **)__calloc_base(1,0x50);
    local_8 = ppuVar3;
    FID_conflict__free((void *)0x0);
    if (ppuVar3 != (undefined **)0x0) {
      puVar4 = (undefined4 *)__calloc_base(1,4);
      local_c = puVar4;
      FID_conflict__free((void *)0x0);
      if (puVar4 == (undefined4 *)0x0) {
        FID_conflict__free(ppuVar3);
      }
      else {
        if (*(int *)(param_1 + 0xac) == 0) {
          ppuVar3 = &PTR_DAT_007678d8;
          ppuVar29 = local_8;
          for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
            *ppuVar29 = *ppuVar3;
            ppuVar3 = ppuVar3 + 1;
            ppuVar29 = ppuVar29 + 1;
          }
LAB_006edad6:
          *local_8 = (undefined *)**(undefined4 **)(param_1 + 0x88);
          local_8[1] = *(undefined **)(*(int *)(param_1 + 0x88) + 4);
          local_8[2] = *(undefined **)(*(int *)(param_1 + 0x88) + 8);
          local_8[0xc] = *(undefined **)(*(int *)(param_1 + 0x88) + 0x30);
          local_8[0xd] = *(undefined **)(*(int *)(param_1 + 0x88) + 0x34);
          *local_c = 1;
          ppuVar3 = local_8;
          if (local_10 != (undefined4 *)0x0) {
            *local_10 = 1;
          }
          goto LAB_006edb24;
        }
        puVar4 = (undefined4 *)__calloc_base(1,4);
        local_10 = puVar4;
        FID_conflict__free((void *)0x0);
        if (puVar4 == (undefined4 *)0x0) {
          FID_conflict__free(ppuVar3);
          FID_conflict__free(local_c);
        }
        else {
          uVar26 = *(undefined4 *)(param_1 + 0xac);
          iVar5 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x15,ppuVar3 + 3);
          iVar6 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x14,local_8 + 4);
          iVar7 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x16,local_8 + 5);
          iVar8 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x17,local_8 + 6);
          local_14 = local_8 + 7;
          iVar9 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x18,local_14);
          iVar10 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x50,local_8 + 8);
          iVar11 = ___acrt_GetLocaleInfoA(local_1c,1,uVar26,0x51,local_8 + 9);
          iVar12 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x1a,local_8 + 10);
          iVar13 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x19,(int)local_8 + 0x29);
          iVar14 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x54,(int)local_8 + 0x2a);
          iVar15 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x55,(int)local_8 + 0x2b);
          iVar16 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x56,local_8 + 0xb);
          iVar17 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x57,(int)local_8 + 0x2d);
          iVar18 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x52,(int)local_8 + 0x2e);
          iVar19 = ___acrt_GetLocaleInfoA(local_1c,0,uVar26,0x53,(int)local_8 + 0x2f);
          iVar20 = ___acrt_GetLocaleInfoA(local_1c,2,uVar26,0x15,local_8 + 0xe);
          iVar21 = ___acrt_GetLocaleInfoA(local_1c,2,uVar26,0x14,local_8 + 0xf);
          iVar22 = ___acrt_GetLocaleInfoA(local_1c,2,uVar26,0x16,local_8 + 0x10);
          iVar23 = ___acrt_GetLocaleInfoA(local_1c,2,uVar26,0x17,local_8 + 0x11);
          iVar24 = ___acrt_GetLocaleInfoA(local_1c,2,uVar26,0x50,local_8 + 0x12);
          iVar25 = ___acrt_GetLocaleInfoA(local_1c,2,uVar26,0x51,local_8 + 0x13);
          ppuVar3 = local_8;
          if (iVar25 == 0 &&
              (((((((((((((((((((iVar5 == 0 && iVar6 == 0) && iVar7 == 0) && iVar8 == 0) &&
                             iVar9 == 0) && iVar10 == 0) && iVar11 == 0) && iVar12 == 0) &&
                         iVar13 == 0) && iVar14 == 0) && iVar15 == 0) && iVar16 == 0) && iVar17 == 0
                     ) && iVar18 == 0) && iVar19 == 0) && iVar20 == 0) && iVar21 == 0) &&
                iVar22 == 0) && iVar23 == 0) && iVar24 == 0)) {
            pbVar27 = *local_14;
            while (bVar1 = *pbVar27, bVar1 != 0) {
              if ((byte)(bVar1 - 0x30) < 10) {
                *pbVar27 = bVar1 - 0x30;
LAB_006edaab:
                pbVar27 = pbVar27 + 1;
              }
              else {
                pbVar28 = pbVar27;
                if (bVar1 != 0x3b) goto LAB_006edaab;
                do {
                  bVar1 = pbVar28[1];
                  *pbVar28 = bVar1;
                  pbVar28 = pbVar28 + 1;
                } while (bVar1 != 0);
              }
            }
            goto LAB_006edad6;
          }
          ___acrt_locale_free_monetary(local_8);
          FID_conflict__free(ppuVar3);
          FID_conflict__free(local_c);
          FID_conflict__free(local_10);
        }
      }
    }
    uVar26 = 1;
  }
  return uVar26;
}

