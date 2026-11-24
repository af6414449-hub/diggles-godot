
/* Library Function - Single Match
    _TestDefaultLanguage
   
   Library: Visual Studio 2019 Release */

undefined4 _TestDefaultLanguage(uint param_1,int param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  uint local_8;
  
  iVar3 = ___acrt_getptd();
  iVar4 = GetLocaleInfoW(param_1 & 0x3ff | 0x400,0x20000001,(LPWSTR)&local_8,2);
  if (iVar4 == 0) {
LAB_006ef723:
    uVar5 = 0;
  }
  else {
    if ((param_1 != local_8) && (param_2 != 0)) {
      psVar6 = *(short **)(iVar3 + 0x50);
      psVar1 = psVar6 + 1;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      iVar3 = _GetPrimaryLen(*(undefined4 *)(iVar3 + 0x50));
      if (iVar3 == (int)psVar6 - (int)psVar1 >> 1) goto LAB_006ef723;
    }
    uVar5 = 1;
  }
  return uVar5;
}

