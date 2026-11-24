
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::__c16rtomb_utf8(char *,char16_t,struct _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl __crt_mbstring::__c16rtomb_utf8(char *param_1,wchar16 param_2,_Mbstatet *param_3)

{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_3 == (_Mbstatet *)0x0) {
    param_3 = (_Mbstatet *)&DAT_0076a224;
  }
  if (*(int *)param_3 == 0) {
    if (0x3ff < (ushort)(param_2 + L'␀')) {
      if (0x3ff < (ushort)(param_2 + L'⠀')) {
        uVar1 = FUN_006efecc(param_1,param_2,param_3);
        return uVar1;
      }
      *(uint *)param_3 = (((ushort)param_2 & 0x27ff) + 0x40) * 0x400;
      return 0;
    }
  }
  else if ((ushort)(param_2 + L'␀') < 0x400) {
    local_c = 0;
    local_8 = 0;
    uVar1 = FUN_006efecc(param_1,((ushort)param_2 & 0x23ff) + *(int *)param_3,&local_c);
    *(undefined4 *)param_3 = 0;
    *(undefined4 *)(param_3 + 4) = 0;
    return uVar1;
  }
  uVar1 = return_illegal_sequence(param_3);
  return uVar1;
}

