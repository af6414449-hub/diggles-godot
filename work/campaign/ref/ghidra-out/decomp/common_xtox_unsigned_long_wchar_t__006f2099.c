
/* Library Function - Single Match
    int __cdecl common_xtox<unsigned long,wchar_t>(unsigned long,wchar_t * const,unsigned
   int,unsigned int,bool)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_xtox<unsigned_long,wchar_t>
          (ulong param_1,wchar_t *param_2,uint param_3,uint param_4,bool param_5)

{
  wchar_t wVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  int *piVar4;
  int iVar5;
  wchar_t *pwVar6;
  uint local_c;
  wchar_t *local_8;
  
  local_8 = param_2;
  if (param_5) {
    *param_2 = L'-';
    local_8 = param_2 + 1;
    param_1 = -param_1;
  }
  local_c = (uint)param_5;
  pwVar3 = local_8;
  do {
    pwVar6 = pwVar3;
    uVar2 = (ulonglong)param_1;
    param_1 = param_1 / param_4;
    local_c = local_c + 1;
    *pwVar6 = (-(ushort)(9 < (uint)(uVar2 % (ulonglong)param_4)) & 0x27) + 0x30 +
              (short)(uVar2 % (ulonglong)param_4);
    if (param_1 == 0) break;
    pwVar3 = pwVar6 + 1;
  } while (local_c < param_3);
  if (local_c < param_3) {
    pwVar6[1] = L'\0';
    do {
      wVar1 = *pwVar6;
      *pwVar6 = *local_8;
      pwVar6 = pwVar6 + -1;
      *local_8 = wVar1;
      local_8 = local_8 + 1;
    } while (local_8 < pwVar6);
    iVar5 = 0;
  }
  else {
    *param_2 = L'\0';
    piVar4 = __errno();
    iVar5 = 0x22;
    *piVar4 = 0x22;
    FUN_006e510d();
  }
  return iVar5;
}

