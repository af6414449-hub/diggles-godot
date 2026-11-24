
/* Library Function - Single Match
    __int64 __cdecl count_newline_bytes(char const * const,char const * const,enum
   __crt_lowio_text_mode)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl count_newline_bytes(char *param_1,char *param_2,__crt_lowio_text_mode param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (((undefined1)param_3 == 1) || ((undefined1)param_3 == 2)) {
    uVar4 = 0;
    iVar2 = 0;
    uVar1 = 0;
    uVar3 = ~-(uint)(param_2 < param_1) & (uint)(param_2 + (1 - (int)param_1)) >> 1;
    if (uVar3 != 0) {
      do {
        if (*(short *)param_1 == 10) {
          bVar6 = 0xfffffffe < uVar4;
          uVar4 = uVar4 + 1;
          iVar2 = iVar2 + (uint)bVar6;
        }
        param_1 = (char *)((int)param_1 + 2);
        uVar1 = uVar1 + 1;
      } while (uVar1 != uVar3);
    }
    uVar1 = iVar2 << 1 | uVar4 >> 0x1f;
    uVar4 = uVar4 * 2;
  }
  else {
    uVar4 = 0;
    uVar1 = 0;
    uVar3 = 0;
    uVar5 = ~-(uint)(param_2 < param_1) & (int)param_2 - (int)param_1;
    if (uVar5 != 0) {
      do {
        if (*param_1 == '\n') {
          bVar6 = 0xfffffffe < uVar4;
          uVar4 = uVar4 + 1;
          uVar1 = uVar1 + bVar6;
        }
        param_1 = param_1 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 != uVar5);
    }
  }
  return CONCAT44(uVar1,uVar4);
}

