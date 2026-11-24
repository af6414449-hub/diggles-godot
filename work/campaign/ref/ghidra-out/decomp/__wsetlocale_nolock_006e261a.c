
/* Library Function - Single Match
    __wsetlocale_nolock
   
   Library: Visual Studio 2019 Release */

void __wsetlocale_nolock(int param_1,int param_2,wchar_t *param_3)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  size_t sVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  ushort *puVar10;
  wchar_t wVar11;
  undefined4 *puVar12;
  undefined **ppuVar13;
  bool bVar14;
  wchar_t *local_1d0;
  int local_1cc;
  size_t local_1c8;
  undefined4 local_1c4;
  undefined4 *local_1c0;
  undefined1 local_1bc [172];
  ushort local_110 [132];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_1cc = param_1;
  if (param_2 != 0) {
    if (param_3 != (wchar_t *)0x0) {
      __wsetlocale_set_cat(param_1,param_2,param_3);
    }
    goto LAB_006e28e9;
  }
  local_1c8 = 1;
  puVar12 = (undefined4 *)0x0;
  local_1c0 = (undefined4 *)0x0;
  if (param_3 != (wchar_t *)0x0) {
    if (((*param_3 == L'L') && (param_3[1] == L'C')) && (param_3[2] == L'_')) {
      do {
        local_1d0 = _wcspbrk(param_3,L"=;");
        if (((local_1d0 == (wchar_t *)0x0) ||
            (sVar4 = (int)local_1d0 - (int)param_3 >> 1, local_1c8 = sVar4, sVar4 == 0)) ||
           (*local_1d0 == L';')) goto LAB_006e28e9;
        ppuVar13 = &PTR_u_LC_COLLATE_00717294;
        local_1c4 = 1;
        do {
          iVar5 = _wcsncmp((wchar_t *)*ppuVar13,param_3,sVar4);
          if (iVar5 == 0) {
            psVar9 = (short *)*ppuVar13;
            psVar1 = psVar9 + 1;
            do {
              sVar2 = *psVar9;
              psVar9 = psVar9 + 1;
            } while (sVar2 != 0);
            if (sVar4 == (int)psVar9 - (int)psVar1 >> 1) break;
          }
          local_1c4 = local_1c4 + 1;
          ppuVar13 = ppuVar13 + 3;
        } while ((int)ppuVar13 < 0x7172c5);
        param_3 = local_1d0 + 1;
        sVar4 = _wcscspn(param_3,L";");
        param_1 = local_1cc;
        if ((sVar4 == 0) && (*param_3 != L';')) goto LAB_006e28e9;
        if (local_1c4 < 6) {
          iVar5 = FUN_006ed6af(local_110,0x83,param_3,sVar4);
          if (iVar5 != 0) {
LAB_006e28fd:
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          if (0x105 < sVar4 * 2) {
            ___report_rangecheckfailure();
            goto LAB_006e28fd;
          }
          local_110[sVar4] = 0;
          iVar5 = __wsetlocale_set_cat(param_1,local_1c4,local_110);
          if (iVar5 != 0) {
            local_1c0 = (undefined4 *)((int)local_1c0 + 1);
          }
        }
        param_3 = param_3 + sVar4;
        wVar11 = *param_3;
        if (wVar11 != L'\0') {
          param_3 = param_3 + 1;
          wVar11 = *param_3;
        }
        puVar12 = local_1c0;
      } while (wVar11 != L'\0');
    }
    else {
      iVar5 = __expandlocale(param_3,local_110,0x83,local_1bc,0x55,&local_1d0);
      if (iVar5 == 0) goto LAB_006e28e9;
      local_1c0 = (undefined4 *)(param_1 + 0x20);
      iVar5 = 0;
      do {
        if (iVar5 != 0) {
          puVar10 = (ushort *)*local_1c0;
          puVar6 = local_110;
          do {
            bVar14 = *puVar6 < *puVar10;
            if (*puVar6 != *puVar10) {
LAB_006e2885:
              uVar7 = -(uint)bVar14 | 1;
              goto LAB_006e288c;
            }
            if (*puVar6 == 0) break;
            uVar3 = puVar6[1];
            bVar14 = uVar3 < puVar10[1];
            local_1c4 = CONCAT22(uVar3,(undefined2)local_1c4);
            if (uVar3 != puVar10[1]) goto LAB_006e2885;
            puVar6 = puVar6 + 2;
            puVar10 = puVar10 + 2;
          } while (uVar3 != 0);
          uVar7 = 0;
LAB_006e288c:
          param_1 = local_1cc;
          if (uVar7 == 0) {
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
          else {
            iVar8 = __wsetlocale_set_cat(local_1cc,iVar5,local_110);
            if (iVar8 == 0) {
              local_1c8 = 0;
            }
            else {
              puVar12 = (undefined4 *)((int)puVar12 + 1);
            }
          }
        }
        iVar5 = iVar5 + 1;
        local_1c0 = local_1c0 + 4;
      } while (iVar5 < 6);
      if (local_1c8 != 0) goto LAB_006e28e2;
    }
    if (puVar12 == (undefined4 *)0x0) goto LAB_006e28e9;
  }
LAB_006e28e2:
  __wsetlocale_get_all(param_1);
LAB_006e28e9:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

