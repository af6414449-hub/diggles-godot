
/* Library Function - Single Match
    __int64 __cdecl common_ftell_read_mode_nolock(class __crt_stdio_stream,__int64,__int64)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl
common_ftell_read_mode_nolock
          (FILE *param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  char *pcVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  int unaff_EDI;
  bool bVar9;
  longlong lVar10;
  __int64 _Var11;
  longlong lVar12;
  __crt_lowio_text_mode local_18;
  undefined4 local_10;
  
  lVar3 = CONCAT44(param_3,param_2);
  uVar4 = __fileno(param_1);
  iVar6 = (uVar4 & 0x3f) * 0x38;
  cVar1 = *(char *)((&DAT_00769d80)[(int)uVar4 >> 6] + 0x29 + iVar6);
  local_18 = CONCAT31(local_18._1_3_,cVar1);
  if (cVar1 == '\x01') {
    local_10 = 2;
  }
  else {
    local_10 = 1;
  }
  pcVar2 = param_1->_base;
  if (pcVar2 == (char *)0x0) {
    return lVar3;
  }
  uVar7 = (int)param_1->_ptr - param_1->_cnt;
  pcVar8 = pcVar2 + uVar7;
  iVar5 = ((int)uVar7 >> 0x1f) + ((int)pcVar2 >> 0x1f) + (uint)CARRY4(uVar7,(uint)pcVar2);
  if (-1 < *(char *)((&DAT_00769d80)[(int)uVar4 >> 6] + 0x28 + iVar6)) {
    lVar10 = __alldiv(pcVar8,iVar5,local_10,0);
    goto LAB_006de6dd;
  }
  lVar10 = __lseeki64(uVar4,0x200000000,unaff_EDI);
  if (lVar10 == lVar3) {
    _Var11 = count_newline_bytes((char *)param_1->_cnt,pcVar8 + param_1->_cnt,local_18);
    lVar10 = _Var11 + CONCAT44(iVar5,pcVar8);
    iVar5 = (int)((ulonglong)lVar10 >> 0x20);
    uVar4 = 1;
    if (((uint)param_1->_flag >> 5 & 1) != 0) {
      if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        uVar4 = 2;
      }
      bVar9 = CARRY4((uint)lVar10,uVar4);
      iVar6 = (uint)lVar10 + uVar4;
LAB_006de6c8:
      lVar10 = CONCAT44(iVar5 + (uint)bVar9,iVar6);
    }
  }
  else {
    lVar10 = __lseeki64(uVar4,(ulonglong)param_3,unaff_EDI);
    if (lVar10 == -1) {
      return -1;
    }
    if ((iVar5 < 1) &&
       ((((uVar7 = 0x200, iVar5 < 0 || (pcVar8 < (char *)0x201)) &&
         (((uint)param_1->_flag >> 6 & 1) != 0)) && ((param_1->_flag & 0x100U) == 0)))) {
      iVar5 = 0;
    }
    else {
      uVar7 = param_1->_bufsiz;
      iVar5 = (int)uVar7 >> 0x1f;
    }
    lVar10 = CONCAT44(iVar5,uVar7);
    if ((*(byte *)((&DAT_00769d80)[(int)uVar4 >> 6] + 0x28 + iVar6) & 4) != 0) {
      uVar4 = 1;
      if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        uVar4 = 2;
      }
      bVar9 = CARRY4(uVar7,uVar4);
      iVar6 = uVar7 + uVar4;
      goto LAB_006de6c8;
    }
  }
  lVar10 = __alldiv(lVar10,local_10,0);
LAB_006de6dd:
  lVar12 = __alldiv(param_4,param_5,local_10,0);
  return (lVar12 - lVar10) + lVar3;
}

