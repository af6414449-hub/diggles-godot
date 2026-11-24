
/* Library Function - Single Match
    unsigned int __cdecl _mbstowcs_l_helper(wchar_t *,char const *,unsigned int,struct
   __crt_locale_pointers *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl
_mbstowcs_l_helper(wchar_t *param_1,char *param_2,uint param_3,__crt_locale_pointers *param_4)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  DWORD DVar7;
  byte *pbVar8;
  uint uVar9;
  int local_20;
  localeinfo_struct local_1c;
  char local_14;
  undefined4 local_10;
  uint local_c;
  byte *local_8;
  
  uVar4 = param_3;
  uVar9 = 0;
  if (param_1 != (wchar_t *)0x0) {
    if (param_3 == 0) {
      return 0;
    }
    *param_1 = L'\0';
  }
  if (param_2 == (char *)0x0) {
    piVar5 = __errno();
    *piVar5 = 0x16;
    FUN_006e510d();
    return 0xffffffff;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_20,param_4);
  uVar3 = (local_1c.locinfo)->lc_collate_cp;
  if (uVar3 == 0xfde9) {
    local_10 = 0;
    local_c = 0;
    uVar9 = __crt_mbstring::__mbsrtowcs_utf8(param_1,&param_2,uVar4,(_Mbstatet *)&local_10);
    goto LAB_006eb50e;
  }
  if (param_1 == (wchar_t *)0x0) {
    if ((local_1c.locinfo)->locale_name[2] == (wchar_t *)0x0) {
      pcVar1 = param_2 + 1;
      do {
        cVar2 = *param_2;
        param_2 = param_2 + 1;
      } while (cVar2 != '\0');
      uVar9 = (int)param_2 - (int)pcVar1;
      goto LAB_006eb50e;
    }
    uVar9 = 0xffffffff;
    iVar6 = ___acrt_MultiByteToWideChar(uVar3,9,param_2,0xffffffff,0,0);
    if (iVar6 == 0) {
      piVar5 = __errno();
      *piVar5 = 0x2a;
      goto LAB_006eb50e;
    }
  }
  else {
    if ((local_1c.locinfo)->locale_name[2] == (wchar_t *)0x0) {
      if (uVar4 != 0) {
        do {
          *param_1 = (ushort)(byte)param_2[uVar9];
          if (param_2[uVar9] == '\0') break;
          uVar9 = uVar9 + 1;
          param_1 = param_1 + 1;
        } while (uVar9 < uVar4);
      }
      goto LAB_006eb50e;
    }
    iVar6 = ___acrt_MultiByteToWideChar(uVar3,9,param_2,0xffffffff,param_1,uVar4);
    if (iVar6 == 0) {
      DVar7 = GetLastError();
      if (DVar7 == 0x7a) {
        local_8 = (byte *)param_2;
        uVar9 = uVar4;
        if (uVar4 != 0) {
          do {
            local_c = uVar9 - 1;
            if (*local_8 == 0) break;
            iVar6 = __isleadbyte_l((uint)*local_8,&local_1c);
            pbVar8 = local_8;
            if ((iVar6 != 0) && (pbVar8 = local_8 + 1, *pbVar8 == 0)) goto LAB_006eb4bb;
            local_8 = pbVar8 + 1;
            uVar9 = local_c;
          } while (local_c != 0);
        }
        uVar9 = ___acrt_MultiByteToWideChar
                          ((local_1c.locinfo)->lc_collate_cp,1,param_2,(int)local_8 - (int)param_2,
                           param_1,uVar4);
        if (uVar9 != 0) goto LAB_006eb50e;
      }
LAB_006eb4bb:
      piVar5 = __errno();
      *piVar5 = 0x2a;
      *param_1 = L'\0';
      uVar9 = 0xffffffff;
      goto LAB_006eb50e;
    }
  }
  uVar9 = iVar6 - 1;
LAB_006eb50e:
  if (local_14 != '\0') {
    *(uint *)(local_20 + 0x350) = *(uint *)(local_20 + 0x350) & 0xfffffffd;
  }
  return uVar9;
}

