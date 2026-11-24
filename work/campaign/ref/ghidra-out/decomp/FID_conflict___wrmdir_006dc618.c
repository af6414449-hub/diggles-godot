
/* Library Function - Multiple Matches With Different Base Names
    __wremove
    __wrmdir
   
   Library: Visual Studio 2019 Release */

int __cdecl FID_conflict___wrmdir(wchar_t *_Filename)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeleteFileW(_Filename);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    ___acrt_errno_map_os_error(DVar2);
    return -1;
  }
  return 0;
}

