
/* Library Function - Single Match
    public: static bool __cdecl
   __acrt_stdio_char_traits<char>::validate_stream_is_ansi_if_required(struct _iobuf * const)
   
   Library: Visual Studio 2019 Release */

bool __cdecl __acrt_stdio_char_traits<char>::validate_stream_is_ansi_if_required(_iobuf *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  if (((uint)param_1->_flag >> 0xc & 1) == 0) {
    uVar2 = __fileno(param_1);
    puVar4 = &DAT_007672e0;
    if ((uVar2 == 0xffffffff) || (uVar2 == 0xfffffffe)) {
      puVar5 = &DAT_007672e0;
    }
    else {
      puVar5 = (undefined *)((uVar2 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar2 >> 6]);
    }
    if (puVar5[0x29] == '\0') {
      if ((uVar2 != 0xffffffff) && (uVar2 != 0xfffffffe)) {
        puVar4 = (undefined *)((uVar2 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar2 >> 6]);
      }
      if ((puVar4[0x2d] & 1) == 0) goto LAB_006d422a;
    }
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_006e510d();
    bVar1 = false;
  }
  else {
LAB_006d422a:
    bVar1 = true;
  }
  return bVar1;
}

