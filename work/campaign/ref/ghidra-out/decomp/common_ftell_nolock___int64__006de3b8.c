
/* Library Function - Single Match
    __int64 __cdecl common_ftell_nolock<__int64>(class __crt_stdio_stream)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl common_ftell_nolock<__int64>(FILE *param_1)

{
  char cVar1;
  int *piVar2;
  uint _FileHandle;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  longlong lVar5;
  __int64 _Var6;
  longlong lVar7;
  __crt_lowio_text_mode local_8;
  
  if (param_1 == (FILE *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return -1;
  }
  _FileHandle = __fileno(param_1);
  if ((int)param_1->_base < 0) {
    param_1->_base = (char *)0x0;
  }
  lVar5 = __lseeki64(_FileHandle,0x100000000,unaff_ESI);
  if ((lVar5 < 0x100000000) && (lVar5 < 0)) {
LAB_006de4e3:
    lVar7 = -1;
  }
  else {
    if ((param_1->_flag & 0xc0U) == 0) {
      return lVar5 - (int)param_1->_base;
    }
    iVar3 = (int)_FileHandle >> 6;
    iVar4 = (_FileHandle & 0x3f) * 0x38;
    cVar1 = *(char *)(iVar4 + 0x29 + (&DAT_00769d80)[iVar3]);
    local_8 = CONCAT31(local_8._1_3_,cVar1);
    lVar7 = (longlong)((int)param_1->_ptr - param_1->_cnt);
    if ((param_1->_flag & 3U) == 0) {
      if (((uint)param_1->_flag >> 2 & 1) == 0) {
        piVar2 = __errno();
        *piVar2 = 0x16;
        goto LAB_006de4e3;
      }
    }
    else {
      if ((cVar1 == '\x01') && ((*(byte *)(iVar4 + 0x2d + (&DAT_00769d80)[iVar3]) & 2) != 0)) {
        _Var6 = common_ftell_translated_utf8_nolock();
        return _Var6;
      }
      if (*(char *)(iVar4 + 0x28 + (&DAT_00769d80)[iVar3]) < '\0') {
        _Var6 = count_newline_bytes((char *)param_1->_cnt,param_1->_ptr,local_8);
        lVar7 = _Var6 + lVar7;
      }
    }
    if (lVar5 != 0) {
      if ((param_1->_flag & 1U) == 0) {
        if (cVar1 == '\x01') {
          lVar7 = __alldiv(lVar7,2,0);
        }
        lVar7 = lVar7 + lVar5;
      }
      else {
        lVar7 = common_ftell_read_mode_nolock(param_1,lVar5,lVar7);
      }
    }
  }
  return lVar7;
}

