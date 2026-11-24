
/* Library Function - Single Match
    __getdrive
   
   Library: Visual Studio 2019 Release */

int __cdecl __getdrive(void)

{
  DWORD DVar1;
  wchar_t *lpBuffer;
  int *piVar2;
  int iVar3;
  WCHAR local_214 [262];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  _memset(local_214,0,0x20a);
  DVar1 = GetCurrentDirectoryW(0x105,local_214);
  if (DVar1 < 0x105) {
    get_drive_number_from_path(local_214);
    goto LAB_006eb2e0;
  }
  lpBuffer = (wchar_t *)__calloc_base(DVar1 + 1,2);
  if (lpBuffer == (wchar_t *)0x0) {
LAB_006eb2bf:
    piVar2 = __errno();
    *piVar2 = 0xc;
  }
  else {
    DVar1 = GetCurrentDirectoryW(DVar1 + 1,lpBuffer);
    if (DVar1 == 0) goto LAB_006eb2bf;
    get_drive_number_from_path(lpBuffer);
  }
  FID_conflict__free(lpBuffer);
LAB_006eb2e0:
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}

