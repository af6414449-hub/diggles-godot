
/* Library Function - Single Match
    int __cdecl common_find_next_wide<struct _wfinddata64i32_t>(int,struct _wfinddata64i32_t *
   const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_find_next_wide<struct__wfinddata64i32_t>(int param_1,_wfinddata64i32_t *param_2)

{
  int *piVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  errno_t eVar5;
  __int64 _Var6;
  _WIN32_FIND_DATAW local_258;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (((param_1 == 0) || (param_1 == -1)) || (param_2 == (_wfinddata64i32_t *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    goto LAB_006dc956;
  }
  BVar3 = FindNextFileW((HANDLE)param_1,&local_258);
  if (BVar3 != 0) {
    *(uint *)param_2 = -(uint)(local_258.dwFileAttributes != 0x80) & local_258.dwFileAttributes;
    _Var6 = convert_file_time_to_time_t<__int64>(&local_258.ftCreationTime);
    *(__int64 *)(param_2 + 8) = _Var6;
    _Var6 = convert_file_time_to_time_t<__int64>(&local_258.ftLastAccessTime);
    *(__int64 *)(param_2 + 0x10) = _Var6;
    _Var6 = convert_file_time_to_time_t<__int64>(&local_258.ftLastWriteTime);
    *(int *)(param_2 + 0x18) = (int)_Var6;
    *(DWORD *)(param_2 + 0x20) = local_258.nFileSizeLow;
    *(int *)(param_2 + 0x1c) = (int)((ulonglong)_Var6 >> 0x20);
    eVar5 = _wcscpy_s((wchar_t *)(param_2 + 0x24),0x104,local_258.cFileName);
    if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    goto LAB_006dc956;
  }
  DVar4 = GetLastError();
  if (DVar4 < 2) {
LAB_006dc99a:
    piVar1 = __errno();
    *piVar1 = 0x16;
  }
  else {
    if (3 < DVar4) {
      if (DVar4 == 8) {
        piVar1 = __errno();
        *piVar1 = 0xc;
        goto LAB_006dc956;
      }
      if (DVar4 != 0x12) goto LAB_006dc99a;
    }
    piVar1 = __errno();
    *piVar1 = 2;
  }
LAB_006dc956:
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

