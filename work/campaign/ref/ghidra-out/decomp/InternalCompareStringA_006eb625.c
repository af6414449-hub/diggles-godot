
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl InternalCompareStringA(struct __crt_locale_pointers *,wchar_t const *,unsigned
   long,char const *,int,char const *,int,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
InternalCompareStringA
          (__crt_locale_pointers *param_1,wchar_t *param_2,ulong param_3,char *param_4,int param_5,
          char *param_6,int param_7,int param_8)

{
  BOOL BVar1;
  BYTE *pBVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_5 < 1) {
    if (param_5 < -1) goto LAB_006eb89e;
  }
  else {
    param_5 = ___strncnt(param_4,param_5);
  }
  if (param_7 < 1) {
    if (param_7 < -1) goto LAB_006eb89e;
  }
  else {
    param_7 = ___strncnt(param_6,param_7);
  }
  if (param_8 == 0) {
    param_8 = *(int *)(*(int *)param_1 + 8);
  }
  if ((param_5 == 0) || (param_7 == 0)) {
    if ((param_5 == param_7) ||
       (((1 < param_7 || (1 < param_5)) || (BVar1 = GetCPInfo(param_8,&local_1c), BVar1 == 0))))
    goto LAB_006eb89e;
    if (0 < param_5) {
      if (1 < local_1c.MaxCharSize) {
        pBVar2 = local_1c.LeadByte;
        while (((local_1c.LeadByte[0] != 0 && (pBVar2[1] != 0)) &&
               (((byte)*param_4 < *pBVar2 || (pBVar2[1] < (byte)*param_4))))) {
          pBVar2 = pBVar2 + 2;
          local_1c.LeadByte[0] = *pBVar2;
        }
      }
      goto LAB_006eb89e;
    }
    if (0 < param_7) {
      if (1 < local_1c.MaxCharSize) {
        pBVar2 = local_1c.LeadByte;
        while (((local_1c.LeadByte[0] != 0 && (pBVar2[1] != 0)) &&
               (((byte)*param_6 < *pBVar2 || (pBVar2[1] < (byte)*param_6))))) {
          pBVar2 = pBVar2 + 2;
          local_1c.LeadByte[0] = *pBVar2;
        }
      }
      goto LAB_006eb89e;
    }
  }
  iVar7 = ___acrt_MultiByteToWideChar(param_8,9,param_4,param_5,0,0);
  if (iVar7 == 0) goto LAB_006eb89e;
  uVar3 = iVar7 * 2 + 8;
  uVar3 = -(uint)((uint)(iVar7 * 2) < uVar3) & uVar3;
  if (uVar3 == 0) {
    local_20 = (undefined4 *)0x0;
LAB_006eb7bd:
    if (((local_20 != (undefined4 *)0x0) &&
        (iVar4 = ___acrt_MultiByteToWideChar(param_8,1,param_4,param_5,local_20,iVar7), iVar4 != 0))
       && (iVar4 = ___acrt_MultiByteToWideChar(param_8,9,param_6,param_7,0,0), iVar4 != 0)) {
      uVar3 = iVar4 * 2 + 8;
      uVar3 = -(uint)((uint)(iVar4 * 2) < uVar3) & uVar3;
      if (uVar3 == 0) {
        puVar8 = (undefined4 *)0x0;
LAB_006eb841:
        if ((puVar8 != (undefined4 *)0x0) &&
           (iVar6 = ___acrt_MultiByteToWideChar(param_8,1,param_6,param_7,puVar8,iVar4), iVar6 != 0)
           ) {
          ___acrt_CompareStringEx_36(param_2,param_3,local_20,iVar7,puVar8,iVar4,0,0,0);
        }
      }
      else if (uVar3 < 0x401) {
        puVar5 = (undefined4 *)&stack0xffffffc4;
        puVar8 = (undefined4 *)&stack0xffffffc4;
        if (&stack0x00000000 != (undefined1 *)0x3c) {
LAB_006eb83a:
          puVar8 = puVar5 + 2;
          goto LAB_006eb841;
        }
      }
      else {
        puVar5 = (undefined4 *)__malloc_base(uVar3);
        puVar8 = puVar5;
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = 0xdddd;
          goto LAB_006eb83a;
        }
      }
      __freea_crt(puVar8);
    }
  }
  else if (uVar3 < 0x401) {
    puVar8 = (undefined4 *)&stack0xffffffc4;
    local_20 = (undefined4 *)&stack0xffffffc4;
    if (&stack0x00000000 != (undefined1 *)0x3c) {
LAB_006eb7b0:
      local_20 = puVar8 + 2;
      goto LAB_006eb7bd;
    }
  }
  else {
    puVar8 = (undefined4 *)__malloc_base(uVar3);
    local_20 = puVar8;
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = 0xdddd;
      goto LAB_006eb7b0;
    }
  }
  __freea_crt(local_20);
LAB_006eb89e:
  iVar7 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar7;
}

