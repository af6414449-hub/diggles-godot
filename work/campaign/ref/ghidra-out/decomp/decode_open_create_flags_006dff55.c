
/* Library Function - Single Match
    unsigned long __cdecl decode_open_create_flags(int)
   
   Library: Visual Studio 2019 Release */

ulong __cdecl decode_open_create_flags(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = param_1 & 0x700;
  if (uVar1 < 0x401) {
    if ((uVar1 == 0x400) || (uVar1 == 0)) {
      return 3;
    }
    if (uVar1 == 0x100) {
      return 4;
    }
    if (uVar1 != 0x200) {
      if (uVar1 == 0x300) {
        return 2;
      }
LAB_006dffa7:
      piVar2 = __errno();
      *piVar2 = 0x16;
      FUN_006e510d();
      return 0xffffffff;
    }
  }
  else {
    if (uVar1 == 0x500) {
      return 1;
    }
    if (uVar1 != 0x600) {
      if (uVar1 == 0x700) {
        return 1;
      }
      goto LAB_006dffa7;
    }
  }
  return 5;
}

