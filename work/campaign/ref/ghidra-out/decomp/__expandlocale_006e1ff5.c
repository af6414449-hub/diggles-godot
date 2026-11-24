
/* Library Function - Single Match
    __expandlocale
   
   Library: Visual Studio 2019 Release */

void __expandlocale(wchar_t *param_1,wchar_t *param_2,rsize_t param_3,wchar_t *param_4,uint param_5,
                   uint *param_6)

{
  wchar_t wVar1;
  uint *puVar2;
  char cVar3;
  errno_t eVar4;
  int iVar5;
  uint uVar6;
  wchar_t *pwVar7;
  uint uVar8;
  wchar_t *pwVar9;
  wchar_t *_Src;
  uint uVar10;
  bool bVar11;
  _expandlocale_locale_name_cache local_200 [16];
  wchar_t *local_1f0;
  uint local_1ec;
  uint *local_1e8;
  undefined4 local_1e4;
  wchar_t *local_1e0;
  wchar_t *local_1dc;
  uint *local_1d8;
  undefined1 local_1d4 [256];
  ushort local_d4;
  ushort local_d2;
  ushort local_d0;
  short local_ce;
  short local_cc;
  short local_ca;
  wchar_t local_b4;
  undefined1 local_b2 [170];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_1e8 = param_6;
  local_1f0 = param_2;
  if (param_1 == (wchar_t *)0x0) goto LAB_006e239f;
  local_1e4 = 0;
  if ((*param_1 == L'C') && (param_1[1] == L'\0')) {
    eVar4 = _wcscpy_s(param_2,param_3,L"C");
    if (eVar4 == 0) {
      *local_1e8 = 0;
      goto LAB_006e239f;
    }
    goto LAB_006e23ae;
  }
  iVar5 = ___acrt_getptd();
  local_1d8 = (uint *)(iVar5 + 0x68);
  _Src = (wchar_t *)(iVar5 + 0x172);
  local_1e0 = (wchar_t *)(iVar5 + 0x6c);
  local_1dc = _Src;
  _expandlocale_locale_name_cache::_expandlocale_locale_name_cache
            (local_200,param_4,param_5,(__crt_qualified_locale_data *)(iVar5 + 0x50));
  pwVar7 = param_1;
  do {
    wVar1 = *pwVar7;
    pwVar7 = pwVar7 + 1;
  } while (wVar1 != L'\0');
  uVar10 = (int)pwVar7 - (int)(param_1 + 1) >> 1;
  pwVar7 = _Src;
  pwVar9 = param_1;
  local_1ec = uVar10;
  if (uVar10 < 0x83) {
    do {
      wVar1 = *pwVar7;
      bVar11 = (ushort)wVar1 < (ushort)*pwVar9;
      if (wVar1 != *pwVar9) {
LAB_006e20eb:
        uVar6 = -(uint)bVar11 | 1;
        goto LAB_006e20f0;
      }
      if (wVar1 == L'\0') break;
      wVar1 = pwVar7[1];
      bVar11 = (ushort)wVar1 < (ushort)pwVar9[1];
      if (wVar1 != pwVar9[1]) goto LAB_006e20eb;
      pwVar7 = pwVar7 + 2;
      pwVar9 = pwVar9 + 2;
    } while (wVar1 != L'\0');
    uVar6 = 0;
LAB_006e20f0:
    pwVar7 = local_1e0;
    pwVar9 = param_1;
    if (uVar6 != 0) {
      do {
        wVar1 = *pwVar7;
        bVar11 = (ushort)wVar1 < (ushort)*pwVar9;
        if (wVar1 != *pwVar9) {
LAB_006e2126:
          uVar6 = -(uint)bVar11 | 1;
          goto LAB_006e212b;
        }
        if (wVar1 == L'\0') break;
        wVar1 = pwVar7[1];
        bVar11 = (ushort)wVar1 < (ushort)pwVar9[1];
        if (wVar1 != pwVar9[1]) goto LAB_006e2126;
        pwVar7 = pwVar7 + 2;
        pwVar9 = pwVar9 + 2;
      } while (wVar1 != L'\0');
      uVar6 = 0;
LAB_006e212b:
      if (uVar6 != 0) goto LAB_006e2133;
    }
LAB_006e2366:
    *local_1e8 = *local_1d8;
    eVar4 = _wcscpy_s(local_1f0,param_3,_Src);
    if (eVar4 != 0) {
LAB_006e23ae:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  else {
LAB_006e2133:
    cVar3 = ___acrt_can_use_vista_locale_apis();
    iVar5 = ___lc_wcstolc(local_1d4,param_1);
    puVar2 = local_1d8;
    if (iVar5 == 0) {
      if (cVar3 == '\0') {
        iVar5 = ___acrt_get_qualified_locale_downlevel();
      }
      else {
        iVar5 = ___acrt_get_qualified_locale(local_1d4,local_1d8,local_1d4);
      }
      _Src = local_1dc;
      if (iVar5 == 0) goto LAB_006e21d1;
      ___lc_lctowcs(local_1dc,0x83,local_1d4);
      pwVar7 = &local_b4;
      do {
        wVar1 = *pwVar7;
        pwVar7 = pwVar7 + 1;
      } while (wVar1 != (wchar_t)local_1e4);
      _expandlocale_locale_name_cache::commit_locale_name_cache_already_updated
                (local_200,&local_b4,((int)pwVar7 - (int)local_b2 >> 1) + 1);
LAB_006e2330:
      if ((*param_1 == L'\0') || (0x82 < local_1ec)) {
        *local_1e0 = L'\0';
      }
      else {
        iVar5 = FUN_006ed6af(local_1e0,0x83,param_1,uVar10 + 1);
        if (iVar5 != 0) goto LAB_006e23ae;
      }
      goto LAB_006e2366;
    }
LAB_006e21d1:
    iVar5 = ___acrt_IsValidLocaleName_4(param_1);
    if (iVar5 != 0) {
      uVar8 = get_default_code_page();
      _Src = local_1dc;
      uVar6 = uVar10 + 1;
      *puVar2 = uVar8 & 0xffff;
      iVar5 = FUN_006ed6af(local_1dc,0x83,param_1,uVar6);
      pwVar7 = param_1;
      if (iVar5 != 0) goto LAB_006e23ae;
LAB_006e2325:
      _expandlocale_locale_name_cache::commit_locale_name(local_200,pwVar7,uVar6);
      goto LAB_006e2330;
    }
    cVar3 = parse_bcp47(local_1d4,param_1);
    if ((cVar3 != '\0') && (iVar5 = ___acrt_IsValidLocaleName_4(&local_b4), iVar5 != 0)) {
      if (local_d4 == 0) {
        uVar6 = get_default_code_page(&local_b4);
      }
      else {
        uVar6 = (uint)local_d4;
        if (uVar6 - 0x41 < 0x1a) {
          uVar6 = uVar6 + 0x20;
        }
        if (uVar6 == 0x75) {
          uVar6 = (uint)local_d2;
          if (uVar6 - 0x41 < 0x1a) {
            uVar6 = uVar6 + 0x20;
          }
          if (uVar6 != 0x74) goto LAB_006e229d;
          uVar6 = (uint)local_d0;
          if (uVar6 - 0x41 < 0x1a) {
            uVar6 = uVar6 + 0x20;
          }
          if (((uVar6 != 0x66) || (local_ce != 0x38)) || (local_cc != 0)) goto LAB_006e229d;
        }
        else {
LAB_006e229d:
          if (((local_ce != 0x2d) || (local_cc != 0x38)) || (local_ca != 0)) goto LAB_006e2392;
        }
        uVar6 = 0xfde9;
      }
      _Src = local_1dc;
      *puVar2 = uVar6 & 0xffff;
      iVar5 = FUN_006ed6af(local_1dc,0x83,param_1,uVar10 + 1);
      if (iVar5 != 0) goto LAB_006e23ae;
      pwVar7 = &local_b4;
      do {
        wVar1 = *pwVar7;
        pwVar7 = pwVar7 + 1;
      } while (wVar1 != (wchar_t)local_1e4);
      uVar6 = ((int)pwVar7 - (int)local_b2 >> 1) + 1;
      pwVar7 = &local_b4;
      goto LAB_006e2325;
    }
  }
LAB_006e2392:
  _expandlocale_locale_name_cache::~_expandlocale_locale_name_cache(local_200);
LAB_006e239f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

