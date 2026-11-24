
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl InternalGetLocaleInfoA(struct __crt_locale_pointers * const,wchar_t const *
   const,unsigned long,char * const,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
InternalGetLocaleInfoA
          (__crt_locale_pointers *param_1,wchar_t *param_2,ulong param_3,char *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_1c;
  int local_18;
  char local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_1c,param_1);
  local_c = *(undefined4 *)(local_18 + 8);
  iVar1 = ___acrt_GetLocaleInfoEx_16(param_2,param_3,0,0);
  if (iVar1 == 0) goto LAB_006f1c07;
  uVar2 = iVar1 * 2 + 8;
  uVar2 = -(uint)((uint)(iVar1 * 2) < uVar2) & uVar2;
  if (uVar2 == 0) {
    puVar3 = (undefined4 *)0x0;
LAB_006f1bcc:
    if ((puVar3 != (undefined4 *)0x0) &&
       (iVar1 = ___acrt_GetLocaleInfoEx_16(param_2,param_3,puVar3,iVar1), iVar1 != 0)) {
      ___acrt_WideCharToMultiByte
                (local_c,0,puVar3,0xffffffff,-(uint)(param_5 != 0) & (uint)param_4,param_5,0,0);
    }
  }
  else if (uVar2 < 0x401) {
    puVar4 = (undefined4 *)&stack0xffffffd8;
    puVar3 = (undefined4 *)&stack0xffffffd8;
    if (&stack0x00000000 != &DAT_00000028) {
LAB_006f1bc5:
      puVar3 = puVar4 + 2;
      goto LAB_006f1bcc;
    }
  }
  else {
    puVar3 = (undefined4 *)__malloc_base(uVar2);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0xdddd;
      puVar4 = puVar3;
      goto LAB_006f1bc5;
    }
  }
  __freea_crt(puVar3);
LAB_006f1c07:
  if (local_10 != '\0') {
    *(uint *)(local_1c + 0x350) = *(uint *)(local_1c + 0x350) & 0xfffffffd;
  }
  iVar1 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar1;
}

