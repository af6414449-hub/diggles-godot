
/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2019 Release */

int __cdecl __isatty(int _FileHandle)

{
  int *piVar1;
  
  if (_FileHandle == -2) {
    piVar1 = __errno();
    *piVar1 = 9;
  }
  else {
    if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_00769f80)) {
      return *(byte *)((&DAT_00769d80)[_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3fU) * 0x38) &
             0x40;
    }
    piVar1 = __errno();
    *piVar1 = 9;
    FUN_006e510d();
  }
  return 0;
}

