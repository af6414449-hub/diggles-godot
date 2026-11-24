
/* Library Function - Single Match
    ___acrt_fenv_set_status
   
   Library: Visual Studio 2019 Release */

void ___acrt_fenv_set_status(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_24 [8];
  
  puVar3 = local_24;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  uVar2 = param_1 >> 0x18 & 0x3f;
  if (0 < DAT_00769a88) {
    MXCSR = MXCSR & 0xffffffc0 |
            (param_1 >> 0x18 & 1) << 5 | (uVar2 >> 1 & 1) << 4 | (uVar2 >> 2 & 1) << 3 |
            (uVar2 >> 3 & 1) << 2 | uVar2 >> 4 & 1 | (uVar2 >> 5) * 2;
  }
  return;
}

