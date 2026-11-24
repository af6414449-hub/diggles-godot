
/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 2019 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  
  if (_FileHandle == -2) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_00769f80)) {
      iVar3 = (_FileHandle & 0x3fU) * 0x38;
      if ((*(byte *)((&DAT_00769d80)[_FileHandle >> 6] + 0x28 + iVar3) & 1) != 0) {
        return *(intptr_t *)((&DAT_00769d80)[_FileHandle >> 6] + 0x18 + iVar3);
      }
    }
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    FUN_006e510d();
  }
  return -1;
}

