
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    ___acrt_GetStringTypeA
   
   Library: Visual Studio 2019 Release */

void ___acrt_GetStringTypeA
               (__crt_locale_pointers *param_1,DWORD param_2,undefined4 param_3,undefined4 param_4,
               LPWORD param_5,int param_6,int param_7)

{
  uint uVar1;
  LPCWSTR lpSrcStr;
  int cchSrc;
  LPCWSTR pWVar2;
  int local_20;
  int local_1c;
  char local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_20,param_1);
  if (param_6 == 0) {
    param_6 = *(int *)(local_1c + 8);
  }
  local_10 = ___acrt_MultiByteToWideChar(param_6,(param_7 != 0) * '\b' + '\x01',param_3,param_4,0,0)
  ;
  if (local_10 == 0) goto LAB_006ec139;
  local_c = local_10 * 2;
  uVar1 = -(uint)(local_c < local_c + 8) & local_c + 8;
  if (uVar1 == 0) {
    lpSrcStr = (LPCWSTR)0x0;
  }
  else if (uVar1 < 0x401) {
    pWVar2 = (LPCWSTR)&stack0xffffffd4;
    lpSrcStr = (LPCWSTR)&stack0xffffffd4;
    if (&stack0x00000000 != (undefined1 *)0x2c) {
LAB_006ec0f3:
      lpSrcStr = pWVar2 + 4;
    }
  }
  else {
    lpSrcStr = (LPCWSTR)__malloc_base(uVar1);
    if (lpSrcStr != (LPCWSTR)0x0) {
      lpSrcStr[0] = L'\xdddd';
      lpSrcStr[1] = L'\0';
      pWVar2 = lpSrcStr;
      goto LAB_006ec0f3;
    }
  }
  if (lpSrcStr != (LPCWSTR)0x0) {
    _memset(lpSrcStr,0,local_c);
    cchSrc = ___acrt_MultiByteToWideChar(param_6,1,param_3,param_4,lpSrcStr,local_10);
    if (cchSrc != 0) {
      GetStringTypeW(param_2,lpSrcStr,cchSrc,param_5);
    }
  }
  __freea_crt(lpSrcStr);
LAB_006ec139:
  if (local_14 != '\0') {
    *(uint *)(local_20 + 0x350) = *(uint *)(local_20 + 0x350) & 0xfffffffd;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

