
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::__c32rtomb_utf8(char *,char32_t,struct _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl __crt_mbstring::__c32rtomb_utf8(char *param_1,wchar32 param_2,_Mbstatet *param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (char *)0x0) {
    if (param_2 != L'\0') {
      if ((param_2 & 0xffffff80U) == 0) {
        *param_1 = (char)param_2;
        return 1;
      }
      if ((param_2 & 0xfffff800U) == 0) {
        bVar3 = 0xc0;
        iVar4 = 1;
        iVar5 = iVar4;
      }
      else if ((param_2 & 0xffff0000U) == 0) {
        if ((0xd7ff < (uint)param_2) && ((uint)param_2 < 0xe000)) {
LAB_006efea0:
          uVar2 = return_illegal_sequence(param_3);
          return uVar2;
        }
        iVar4 = 2;
        bVar3 = 0xe0;
        iVar5 = iVar4;
      }
      else {
        if (((param_2 & 0xffe00000U) != 0) || (0x10ffff < (uint)param_2)) goto LAB_006efea0;
        iVar4 = 3;
        bVar3 = 0xf0;
        iVar5 = iVar4;
      }
      do {
        bVar1 = (byte)param_2;
        param_2 = (uint)param_2 >> 6;
        param_1[iVar4] = bVar1 & 0x3f | 0x80;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      *param_1 = (byte)param_2 | bVar3;
      *(undefined4 *)param_3 = 0;
      *(undefined4 *)(param_3 + 4) = 0;
      return iVar5 + 1;
    }
    *param_1 = (char)param_2;
  }
  *(undefined4 *)param_3 = 0;
  *(undefined4 *)(param_3 + 4) = 0;
  return 1;
}

