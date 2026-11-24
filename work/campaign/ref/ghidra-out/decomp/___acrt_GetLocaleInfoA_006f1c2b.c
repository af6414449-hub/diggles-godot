
/* Library Function - Single Match
    ___acrt_GetLocaleInfoA
   
   Library: Visual Studio 2019 Release */

void ___acrt_GetLocaleInfoA
               (__crt_locale_pointers *param_1,int param_2,wchar_t *param_3,uint param_4,
               int *param_5)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  char *_Memory;
  wchar_t *local_8c;
  char local_88 [128];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_8c = param_3;
  *param_5 = 0;
  if (param_2 == 1) {
    iVar1 = InternalGetLocaleInfoA(param_1,param_3,param_4,local_88,0x80);
    if (iVar1 != 0) {
      iVar2 = __calloc_base(iVar1,1);
      *param_5 = iVar2;
      FID_conflict__free((void *)0x0);
      if ((*param_5 != 0) && (iVar1 = FUN_006e9950(*param_5,iVar1,local_88,iVar1 + -1), iVar1 != 0))
      {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      goto LAB_006f1dc1;
    }
    DVar3 = GetLastError();
    if ((DVar3 != 0x7a) ||
       (iVar1 = InternalGetLocaleInfoA(param_1,param_3,param_4,(char *)0x0,0), iVar1 == 0))
    goto LAB_006f1dc1;
    _Memory = (char *)__calloc_base(iVar1,1);
    if (_Memory != (char *)0x0) {
      iVar1 = InternalGetLocaleInfoA(param_1,local_8c,param_4,_Memory,iVar1);
LAB_006f1d30:
      if (iVar1 != 0) {
        *param_5 = (int)_Memory;
        _Memory = (char *)0x0;
      }
    }
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 0) {
        local_8c = (wchar_t *)0x0;
        iVar1 = ___acrt_GetLocaleInfoEx_16(param_3,param_4 | 0x20000000,&local_8c,2);
        if (iVar1 != 0) {
          *(undefined1 *)param_5 = local_8c._0_1_;
        }
      }
      goto LAB_006f1dc1;
    }
    iVar1 = ___acrt_GetLocaleInfoEx_16(param_3,param_4,0,0);
    if (iVar1 == 0) goto LAB_006f1dc1;
    _Memory = (char *)__calloc_base(iVar1,2);
    if (_Memory != (char *)0x0) {
      iVar1 = ___acrt_GetLocaleInfoEx_16(local_8c,param_4,_Memory,iVar1);
      goto LAB_006f1d30;
    }
  }
  FID_conflict__free(_Memory);
LAB_006f1dc1:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

