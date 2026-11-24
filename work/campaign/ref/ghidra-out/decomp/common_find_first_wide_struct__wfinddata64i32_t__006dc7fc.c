
/* Library Function - Single Match
    int __cdecl common_find_first_wide<struct _wfinddata64i32_t>(wchar_t const * const,struct
   _wfinddata64i32_t * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_find_first_wide<struct__wfinddata64i32_t>(wchar_t *param_1,_wfinddata64i32_t *param_2)

{
  int *piVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  int iVar4;
  errno_t eVar5;
  __int64 _Var6;
  uint local_258;
  _FILETIME local_254;
  _FILETIME local_24c;
  _FILETIME local_244;
  undefined4 local_238;
  wchar_t local_22c [274];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if ((param_2 == (_wfinddata64i32_t *)0x0) || (param_1 == (wchar_t *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    goto LAB_006dc87e;
  }
  pvVar2 = FindFirstFileExW(param_1,FindExInfoStandard,&local_258,FindExSearchNameMatch,(LPVOID)0x0,
                            0);
  if (pvVar2 != (HANDLE)0xffffffff) {
    *(uint *)param_2 = -(uint)(local_258 != 0x80) & local_258;
    _Var6 = convert_file_time_to_time_t<__int64>(&local_254);
    *(__int64 *)(param_2 + 8) = _Var6;
    _Var6 = convert_file_time_to_time_t<__int64>(&local_24c);
    *(__int64 *)(param_2 + 0x10) = _Var6;
    _Var6 = convert_file_time_to_time_t<__int64>(&local_244);
    *(int *)(param_2 + 0x18) = (int)_Var6;
    *(undefined4 *)(param_2 + 0x20) = local_238;
    *(int *)(param_2 + 0x1c) = (int)((ulonglong)_Var6 >> 0x20);
    eVar5 = _wcscpy_s((wchar_t *)(param_2 + 0x24),0x104,local_22c);
    if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    goto LAB_006dc87e;
  }
  DVar3 = GetLastError();
  if (DVar3 < 2) {
LAB_006dc86e:
    piVar1 = __errno();
    *piVar1 = 0x16;
  }
  else {
    if (3 < DVar3) {
      if (DVar3 == 8) {
        piVar1 = __errno();
        *piVar1 = 0xc;
        goto LAB_006dc87e;
      }
      if (DVar3 != 0x12) goto LAB_006dc86e;
    }
    piVar1 = __errno();
    *piVar1 = 2;
  }
LAB_006dc87e:
  iVar4 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar4;
}

