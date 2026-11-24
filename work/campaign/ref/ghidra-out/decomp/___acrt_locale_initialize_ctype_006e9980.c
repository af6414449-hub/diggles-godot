
/* Library Function - Single Match
    ___acrt_locale_initialize_ctype
   
   Library: Visual Studio 2019 Release */

void ___acrt_locale_initialize_ctype(undefined4 *param_1)

{
  short *psVar1;
  byte bVar2;
  int *piVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  BOOL BVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined2 *puVar10;
  undefined4 *puVar11;
  short *psVar12;
  int iVar13;
  BYTE *pBVar14;
  short *psVar15;
  undefined4 *puVar16;
  undefined4 *local_5c;
  undefined4 local_58;
  undefined4 *local_54;
  short *local_50;
  undefined2 *local_4c;
  undefined4 *local_48;
  undefined1 *local_44;
  uint local_40;
  uint local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  short *local_30;
  short *local_2c;
  void *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_38 = param_1;
  psVar12 = (short *)0x0;
  local_20 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  local_28 = (void *)0x0;
  local_5c = param_1;
  local_58 = 0;
  if (param_1[0x2a] == 0) {
    piVar3 = (int *)param_1[0x23];
    if (piVar3 != (int *)0x0) {
      LOCK();
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    param_1[0x23] = 0;
    param_1[0x24] = 0;
    *param_1 = &DAT_00718248;
    param_1[0x25] = &DAT_007184c8;
    param_1[0x26] = &DAT_00718648;
    param_1[1] = 1;
    goto LAB_006e9dcf;
  }
  local_34 = (undefined4 *)0x0;
  if ((param_1[2] == 0) &&
     (iVar6 = ___acrt_GetLocaleInfoA(&local_5c,0,param_1[0x2a],0x1004,param_1 + 2), iVar6 != 0)) {
LAB_006e9d62:
    FID_conflict__free(local_34);
    FID_conflict__free(local_20);
    FID_conflict__free(psVar12);
    FID_conflict__free(local_24);
  }
  else {
    local_34 = (undefined4 *)__calloc_base(1,4);
    FID_conflict__free((void *)0x0);
    local_20 = (undefined4 *)__calloc_base(0x180,2);
    FID_conflict__free((void *)0x0);
    psVar12 = (short *)__calloc_base(0x180,1);
    local_2c = psVar12;
    FID_conflict__free((void *)0x0);
    local_24 = (undefined4 *)__calloc_base(0x180,1);
    FID_conflict__free((void *)0x0);
    local_28 = (void *)__calloc_base(0x101,1);
    FID_conflict__free((void *)0x0);
    if ((local_34 == (undefined4 *)0x0) ||
       ((((local_20 == (undefined4 *)0x0 || (local_28 == (void *)0x0)) || (psVar12 == (short *)0x0))
        || (local_24 == (undefined4 *)0x0)))) goto LAB_006e9d62;
    iVar6 = 0;
    do {
      *(char *)(iVar6 + (int)local_28) = (char)iVar6;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x100);
    BVar7 = GetCPInfo(param_1[2],&local_1c);
    if ((BVar7 == 0) || (5 < local_1c.MaxCharSize)) goto LAB_006e9d62;
    local_3c = local_1c.MaxCharSize & 0xffff;
    if (1 < local_3c) {
      if (param_1[2] == 0xfde9) {
        _memset((void *)((int)local_28 + 0x80),0x20,0x80);
      }
      else {
        pBVar14 = local_1c.LeadByte;
        bVar2 = local_1c.LeadByte[0];
        while ((bVar2 != 0 && (param_1 = local_38, pBVar14[1] != 0))) {
          uVar8 = (uint)*pBVar14;
          if (uVar8 <= pBVar14[1]) {
            do {
              *(undefined1 *)(uVar8 + (int)local_28) = 0x20;
              uVar8 = uVar8 + 1;
            } while ((int)uVar8 <= (int)(uint)pBVar14[1]);
          }
          pBVar14 = pBVar14 + 2;
          bVar2 = *pBVar14;
        }
      }
    }
    local_30 = (short *)((int)local_28 + 1);
    iVar6 = ___acrt_LCMapStringA
                      (0,param_1[0x2a],0x100,local_30,0xff,(int)psVar12 + 0x81,0xff,param_1[2],0);
    if ((iVar6 == 0) ||
       (iVar6 = ___acrt_LCMapStringA
                          (0,param_1[0x2a],0x200,local_30,0xff,(int)local_24 + 0x81,0xff,param_1[2],
                           0), iVar6 == 0)) goto LAB_006e9d62;
    local_48 = local_20 + 0x40;
    iVar6 = ___acrt_GetStringTypeA(0,1,local_28,0x100,local_48,param_1[2],0);
    psVar15 = local_2c;
    puVar4 = local_38;
    if (iVar6 == 0) goto LAB_006e9d62;
    local_4c = (undefined2 *)((int)local_20 + 0xfe);
    *local_4c = 0;
    local_50 = local_2c + 0x40;
    *(undefined1 *)((int)local_2c + 0x7f) = 0;
    *(undefined1 *)((int)local_24 + 0x7f) = 0;
    *(undefined1 *)local_50 = 0;
    local_54 = local_24 + 0x20;
    *(undefined1 *)local_54 = 0;
    if (1 < local_3c) {
      if (param_1[2] == 0xfde9) {
        psVar12 = local_2c + 0x80;
        iVar13 = (int)local_24 - (int)local_2c;
        iVar6 = -0x142 - (int)local_2c;
        local_30 = (short *)(-0x80 - (int)local_2c);
        local_2c = (short *)(local_20 + 0x80);
        do {
          psVar1 = local_2c + 1;
          *local_2c = (-(ushort)((char *)0x32 < (char *)(iVar6 + (int)psVar12)) & 0x8000) + 0x8000;
          cVar5 = (char)psVar12 + (char)local_30;
          *(char *)psVar12 = cVar5;
          *(char *)(iVar13 + (int)psVar12) = cVar5;
          psVar12 = (short *)((int)psVar12 + 1);
          local_2c = psVar1;
        } while ((int)((int)local_30 + (int)psVar12) < 0x100);
      }
      else {
        pBVar14 = local_1c.LeadByte;
        while ((local_1c.LeadByte[0] != 0 && (pBVar14[1] != 0))) {
          local_40 = (uint)*pBVar14;
          if (local_40 <= pBVar14[1]) {
            local_30 = local_2c;
            local_44 = (undefined1 *)((int)local_24 + local_40 + 0x80);
            puVar10 = (undefined2 *)((int)local_20 + local_40 * 2 + 0x100);
            uVar8 = local_40;
            puVar9 = local_44;
            do {
              *puVar10 = 0x8000;
              puVar10 = puVar10 + 1;
              puVar9[(int)local_2c - (int)local_24] = (char)uVar8;
              *puVar9 = (char)uVar8;
              uVar8 = uVar8 + 1;
              puVar9 = puVar9 + 1;
            } while ((int)uVar8 <= (int)(uint)pBVar14[1]);
          }
          pBVar14 = pBVar14 + 2;
          local_1c.LeadByte[0] = *pBVar14;
        }
      }
    }
    puVar11 = local_20 + 0x80;
    puVar16 = local_20;
    for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar16 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar16 = puVar16 + 1;
    }
    *(undefined2 *)puVar16 = *(undefined2 *)puVar11;
    psVar12 = psVar15 + 0x80;
    for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)psVar15 = *(undefined4 *)psVar12;
      psVar12 = psVar12 + 2;
      psVar15 = psVar15 + 2;
    }
    *psVar15 = *psVar12;
    *(char *)(psVar15 + 1) = (char)psVar12[1];
    puVar11 = local_24 + 0x40;
    puVar16 = local_24;
    for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar16 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar16 = puVar16 + 1;
    }
    *(undefined2 *)puVar16 = *(undefined2 *)puVar11;
    *(undefined1 *)((int)puVar16 + 2) = *(undefined1 *)((int)puVar11 + 2);
    piVar3 = (int *)local_38[0x23];
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar6 = *piVar3;
      *piVar3 = iVar6 + -1;
      UNLOCK();
      if (iVar6 + -1 == 0) {
        FID_conflict__free((void *)(local_38[0x24] + -0xfe));
        FID_conflict__free((void *)(puVar4[0x25] + -0x80));
        FID_conflict__free((void *)(puVar4[0x26] + -0x80));
        FID_conflict__free((void *)puVar4[0x23]);
      }
    }
    *local_34 = 1;
    puVar4[0x23] = local_34;
    *puVar4 = local_48;
    puVar4[0x24] = local_4c;
    puVar4[0x25] = local_50;
    puVar4[0x26] = local_54;
    puVar4[1] = local_3c;
  }
  FID_conflict__free(local_28);
LAB_006e9dcf:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

