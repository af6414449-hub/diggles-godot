
/* Library Function - Single Match
    __wchmod
   
   Library: Visual Studio 2019 Release */

int __cdecl __wchmod(wchar_t *_Filename,int _Mode)

{
  ulong *puVar1;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  uint local_2c [9];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (_Filename == (wchar_t *)0x0) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  else {
    BVar3 = GetFileAttributesExW(_Filename,GetFileExInfoStandard,local_2c);
    if (BVar3 != 0) {
      if ((_Mode & 0x80U) == 0) {
        local_2c[0] = local_2c[0] | 1;
      }
      else {
        local_2c[0] = local_2c[0] & 0xfffffffe;
      }
      BVar3 = SetFileAttributesW(_Filename,local_2c[0]);
      if (BVar3 != 0) goto LAB_006efa59;
    }
    DVar4 = GetLastError();
    ___acrt_errno_map_os_error(DVar4);
  }
LAB_006efa59:
  iVar5 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar5;
}

