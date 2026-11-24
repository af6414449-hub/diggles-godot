
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __acrt_LCMapStringA_stat(struct __crt_locale_pointers *,wchar_t const *,unsigned
   long,char const *,int,char *,int,int,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_LCMapStringA_stat
          (__crt_locale_pointers *param_1,wchar_t *param_2,ulong param_3,char *param_4,int param_5,
          char *param_6,int param_7,int param_8,int param_9)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar5 = param_5;
  if (0 < param_5) {
    iVar2 = ___strncnt(param_4,param_5);
    iVar5 = iVar2 + 1;
    if (param_5 <= iVar2) {
      iVar5 = iVar2;
    }
  }
  if (param_8 == 0) {
    param_8 = *(int *)(*(int *)param_1 + 8);
  }
  iVar2 = ___acrt_MultiByteToWideChar(param_8,(param_9 != 0) * '\b' + '\x01',param_4,iVar5,0,0);
  if (iVar2 == 0) goto LAB_006e92bf;
  uVar3 = iVar2 * 2 + 8;
  uVar3 = -(uint)((uint)(iVar2 * 2) < uVar3) & uVar3;
  if (uVar3 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  else if (uVar3 < 0x401) {
    puVar6 = (undefined4 *)&stack0xffffffe8;
    puVar4 = (undefined4 *)&stack0xffffffe8;
    if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_006e91a2:
      puVar4 = puVar6 + 2;
    }
  }
  else {
    puVar4 = (undefined4 *)__malloc_base(uVar3);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0xdddd;
      puVar6 = puVar4;
      goto LAB_006e91a2;
    }
  }
  if (((puVar4 != (undefined4 *)0x0) &&
      (iVar5 = ___acrt_MultiByteToWideChar(param_8,1,param_4,iVar5,puVar4,iVar2), iVar5 != 0)) &&
     (iVar5 = ___acrt_LCMapStringEx_36(param_2,param_3,puVar4,iVar2,0,0,0,0,0), iVar5 != 0)) {
    if ((param_3 & 0x400) == 0) {
      uVar3 = iVar5 * 2 + 8;
      uVar3 = -(uint)((uint)(iVar5 * 2) < uVar3) & uVar3;
      if (uVar3 == 0) {
        puVar6 = (undefined4 *)0x0;
LAB_006e926f:
        if ((puVar6 != (undefined4 *)0x0) &&
           (iVar2 = ___acrt_LCMapStringEx_36(param_2,param_3,puVar4,iVar2,puVar6,iVar5,0,0,0),
           iVar2 != 0)) {
          if (param_7 == 0) {
            param_7 = 0;
            param_6 = (char *)0x0;
          }
          iVar5 = ___acrt_WideCharToMultiByte(param_8,0,puVar6,iVar5,param_6,param_7,0,0);
          if (iVar5 != 0) {
            __freea_crt(puVar6);
            goto LAB_006e92b6;
          }
        }
      }
      else if (uVar3 < 0x401) {
        puVar7 = (undefined4 *)&stack0xffffffe8;
        puVar6 = (undefined4 *)&stack0xffffffe8;
        if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_006e9268:
          puVar6 = puVar7 + 2;
          goto LAB_006e926f;
        }
      }
      else {
        puVar6 = (undefined4 *)__malloc_base(uVar3);
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = 0xdddd;
          puVar7 = puVar6;
          goto LAB_006e9268;
        }
      }
      __freea_crt(puVar6);
    }
    else if ((param_7 != 0) && (iVar5 <= param_7)) {
      ___acrt_LCMapStringEx_36(param_2,param_3,puVar4,iVar2,param_6,param_7,0,0,0);
    }
  }
LAB_006e92b6:
  __freea_crt(puVar4);
LAB_006e92bf:
  iVar5 = __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return iVar5;
}

