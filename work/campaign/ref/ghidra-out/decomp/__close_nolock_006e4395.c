
/* Library Function - Single Match
    __close_nolock
   
   Library: Visual Studio 2019 Release */

int __cdecl __close_nolock(int _FileHandle)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  int iVar4;
  DWORD DVar5;
  
  iVar1 = __get_osfhandle(_FileHandle);
  if (iVar1 != -1) {
    if (((_FileHandle == 1) && ((*(byte *)(DAT_00769d80 + 0x98) & 1) != 0)) ||
       ((_FileHandle == 2 && ((*(byte *)(DAT_00769d80 + 0x60) & 1) != 0)))) {
      iVar1 = __get_osfhandle(2);
      iVar2 = __get_osfhandle(1);
      if (iVar2 == iVar1) goto LAB_006e43ab;
    }
    hObject = (HANDLE)__get_osfhandle(_FileHandle);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar5 = GetLastError();
      goto LAB_006e43fd;
    }
  }
LAB_006e43ab:
  DVar5 = 0;
LAB_006e43fd:
  __free_osfhnd(_FileHandle);
  *(undefined1 *)((&DAT_00769d80)[_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3fU) * 0x38) = 0;
  if (DVar5 == 0) {
    iVar4 = 0;
  }
  else {
    ___acrt_errno_map_os_error(DVar5);
    iVar4 = -1;
  }
  return iVar4;
}

