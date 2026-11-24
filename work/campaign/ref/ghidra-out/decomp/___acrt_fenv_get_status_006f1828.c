
/* Library Function - Single Match
    ___acrt_fenv_get_status
   
   Library: Visual Studio 2019 Release */

uint ___acrt_fenv_get_status(void)

{
  uint uVar1;
  uint uVar2;
  ushort in_FPUStatusWord;
  
  uVar1 = in_FPUStatusWord & 0x3f;
  uVar1 = (uVar1 >> 1 & 1) << 5 | (uVar1 >> 2 & 1) << 3 | (uVar1 >> 3 & 1) << 2 |
          (uVar1 >> 4 & 1) * 2 | (in_FPUStatusWord & 1) << 4 | uVar1 >> 5;
  if (DAT_00769a88 < 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = MXCSR & 0x3f;
  }
  uVar2 = (uVar2 >> 1 & 1) << 5 | (uVar2 >> 2 & 1) << 3 | (uVar2 >> 3 & 1) << 2 |
          (uVar2 >> 4 & 1) * 2 | (uVar2 & 1) << 4 | uVar2 >> 5;
  return (uVar2 << 8 | uVar1) << 0x10 | uVar2 | uVar1;
}

