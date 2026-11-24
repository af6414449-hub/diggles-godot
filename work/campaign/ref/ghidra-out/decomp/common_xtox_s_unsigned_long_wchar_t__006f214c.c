
/* Library Function - Single Match
    int __cdecl common_xtox_s<unsigned long,wchar_t>(unsigned long,wchar_t * const,unsigned
   int,unsigned int,bool)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_xtox_s<unsigned_long,wchar_t>
          (ulong param_1,wchar_t *param_2,uint param_3,uint param_4,bool param_5)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  if (param_3 != 0) {
    *param_2 = L'\0';
    if (param_3 <= param_5 + 1) {
      piVar1 = __errno();
      iVar2 = 0x22;
      goto LAB_006f219f;
    }
    if (param_4 - 2 < 0x23) {
      iVar2 = common_xtox<unsigned_long,wchar_t>(param_1,param_2,param_3,param_4,param_5);
      return iVar2;
    }
  }
  piVar1 = __errno();
  iVar2 = 0x16;
LAB_006f219f:
  *piVar1 = iVar2;
  FUN_006e510d();
  return iVar2;
}

