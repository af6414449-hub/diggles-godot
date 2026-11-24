
/* Library Function - Single Match
    _ProcessCodePage
   
   Library: Visual Studio 2019 Release */

long _ProcessCodePage(wchar_t *param_1,int param_2)

{
  wchar_t wVar1;
  uint uVar2;
  int iVar3;
  wchar_t *pwVar4;
  long lVar5;
  wchar_t *pwVar6;
  uint uVar7;
  bool bVar8;
  undefined4 uVar9;
  int local_8;
  
  if ((param_1 != (wchar_t *)0x0) && (uVar7 = 0, *param_1 != L'\0')) {
    pwVar6 = L"ACP";
    pwVar4 = param_1;
    do {
      wVar1 = *pwVar4;
      bVar8 = (ushort)wVar1 < (ushort)*pwVar6;
      if (wVar1 != *pwVar6) {
LAB_006eecc4:
        uVar2 = -(uint)bVar8 | 1;
        goto LAB_006eecc9;
      }
      if (wVar1 == L'\0') break;
      wVar1 = pwVar4[1];
      bVar8 = (ushort)wVar1 < (ushort)pwVar6[1];
      if (wVar1 != pwVar6[1]) goto LAB_006eecc4;
      pwVar4 = pwVar4 + 2;
      pwVar6 = pwVar6 + 2;
    } while (wVar1 != L'\0');
    uVar2 = 0;
LAB_006eecc9:
    if (uVar2 != 0) {
      iVar3 = __wcsicmp(param_1,L"utf8");
      if (iVar3 == 0) {
        return 0xfde9;
      }
      iVar3 = __wcsicmp(param_1,L"utf-8");
      if (iVar3 == 0) {
        return 0xfde9;
      }
      pwVar6 = L"OCP";
      pwVar4 = param_1;
      do {
        wVar1 = *pwVar4;
        bVar8 = (ushort)wVar1 < (ushort)*pwVar6;
        if (wVar1 != *pwVar6) {
LAB_006eed1e:
          uVar7 = -(uint)bVar8 | 1;
          break;
        }
        if (wVar1 == L'\0') break;
        wVar1 = pwVar4[1];
        bVar8 = (ushort)wVar1 < (ushort)pwVar6[1];
        if (wVar1 != pwVar6[1]) goto LAB_006eed1e;
        pwVar4 = pwVar4 + 2;
        pwVar6 = pwVar6 + 2;
      } while (wVar1 != L'\0');
      if (uVar7 != 0) {
        lVar5 = __wtol(param_1);
        return lVar5;
      }
      uVar9 = 0x2000000b;
      goto LAB_006eed32;
    }
  }
  uVar9 = 0x20001004;
LAB_006eed32:
  iVar3 = ___acrt_GetLocaleInfoEx_16(param_2 + 0x250,uVar9,&local_8,2);
  if (iVar3 == 0) {
    return 0;
  }
  if (local_8 < 3) {
    return 0xfde9;
  }
  return local_8;
}

