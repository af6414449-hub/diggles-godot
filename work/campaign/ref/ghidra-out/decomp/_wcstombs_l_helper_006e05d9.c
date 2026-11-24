
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    unsigned int __cdecl _wcstombs_l_helper(char *,wchar_t const *,unsigned int,struct
   __crt_locale_pointers *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl
_wcstombs_l_helper(char *param_1,wchar_t *param_2,uint param_3,__crt_locale_pointers *param_4)

{
  char cVar1;
  wchar_t wVar2;
  int *piVar3;
  wchar_t *pwVar4;
  int iVar5;
  DWORD DVar6;
  uint uVar7;
  uint uVar8;
  int local_40;
  int local_3c;
  char local_34;
  undefined4 local_30;
  char *local_2c;
  int local_28;
  int local_24;
  wchar_t *local_20;
  char local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x6e05e5;
  uVar8 = 0;
  local_2c = param_1;
  local_20 = param_2;
  local_24 = 0;
  if ((param_1 != (char *)0x0) && (param_3 == 0)) goto LAB_006e087c;
  if (param_2 == (wchar_t *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
    goto LAB_006e087c;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_40,param_4);
  local_8 = 0;
  iVar5 = *(int *)(local_3c + 8);
  if (iVar5 == 0xfde9) {
    local_30 = 0;
    local_2c = (char *)0x0;
    __crt_mbstring::__wcsrtombs_utf8(param_1,&local_20,param_3,(_Mbstatet *)&local_30);
  }
  else if (param_1 == (char *)0x0) {
    if (*(int *)(local_3c + 0xa8) == 0) {
      wVar2 = *local_20;
      pwVar4 = local_20;
      while (wVar2 != L'\0') {
        if (0xff < (ushort)wVar2) goto LAB_006e085c;
        pwVar4 = pwVar4 + 1;
        wVar2 = *pwVar4;
      }
    }
    else {
      iVar5 = ___acrt_WideCharToMultiByte(iVar5,0,local_20,0xffffffff,0,0,0,&local_24);
      if ((iVar5 == 0) || (local_24 != 0)) {
LAB_006e085c:
        piVar3 = __errno();
        *piVar3 = 0x2a;
      }
    }
  }
  else if (*(int *)(local_3c + 0xa8) == 0) {
    if (param_3 != 0) {
      do {
        if (0xff < (ushort)*local_20) goto LAB_006e07f6;
        param_1[uVar8] = (char)*local_20;
        wVar2 = *local_20;
        local_20 = local_20 + 1;
      } while ((wVar2 != L'\0') && (uVar8 = uVar8 + 1, uVar8 < param_3));
    }
  }
  else if (*(int *)(local_3c + 4) == 1) {
    pwVar4 = local_20;
    uVar8 = param_3;
    if (param_3 != 0) {
      do {
        if (*pwVar4 == L'\0') break;
        pwVar4 = pwVar4 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      if ((uVar8 != 0) && (*pwVar4 == L'\0')) {
        param_3 = ((int)pwVar4 - (int)local_20 >> 1) + 1;
      }
    }
    iVar5 = ___acrt_WideCharToMultiByte(iVar5,0,local_20,param_3,param_1,param_3,0,&local_24);
    if (iVar5 != 0) {
joined_r0x006e0730:
      if (local_24 == 0) goto LAB_006e086a;
    }
LAB_006e07f6:
    piVar3 = __errno();
    *piVar3 = 0x2a;
  }
  else {
    iVar5 = ___acrt_WideCharToMultiByte(iVar5,0,local_20,0xffffffff,param_1,param_3,0,&local_24);
    if (iVar5 != 0) goto joined_r0x006e0730;
    if ((local_24 != 0) || (DVar6 = GetLastError(), DVar6 != 0x7a)) goto LAB_006e07f6;
    if (param_3 != 0) {
      uVar8 = 0;
      do {
        iVar5 = *(int *)(local_3c + 4);
        if (5 < iVar5) {
          iVar5 = 5;
        }
        uVar7 = ___acrt_WideCharToMultiByte
                          (*(undefined4 *)(local_3c + 8),0,local_20,1,local_1c,iVar5,0,&local_24);
        if ((((uVar7 == 0) || (local_24 != 0)) || ((int)uVar7 < 0)) || (5 < uVar7))
        goto LAB_006e085c;
        if (param_3 < uVar7 + uVar8) break;
        local_28 = 0;
        if (0 < (int)uVar7) {
          do {
            cVar1 = local_1c[local_28];
            local_2c[uVar8] = cVar1;
            if (cVar1 == '\0') goto LAB_006e086a;
            local_28 = local_28 + 1;
            uVar8 = uVar8 + 1;
          } while (local_28 < (int)uVar7);
        }
        local_20 = local_20 + 1;
      } while (uVar8 < param_3);
    }
  }
LAB_006e086a:
  if (local_34 != '\0') {
    *(uint *)(local_40 + 0x350) = *(uint *)(local_40 + 0x350) & 0xfffffffd;
  }
LAB_006e087c:
  uVar8 = FUN_006f37c8();
  return uVar8;
}

