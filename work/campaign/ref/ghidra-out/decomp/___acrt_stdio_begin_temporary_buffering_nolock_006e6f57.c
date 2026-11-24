
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___acrt_stdio_begin_temporary_buffering_nolock
   
   Library: Visual Studio 2019 Release */

uint ___acrt_stdio_begin_temporary_buffering_nolock(FILE *param_1)

{
  int *piVar1;
  int iVar2;
  FILE *pFVar3;
  char *pcVar4;
  int *piVar5;
  
  iVar2 = __fileno(param_1);
  pFVar3 = (FILE *)__isatty(iVar2);
  if (pFVar3 == (FILE *)0x0) {
LAB_006e7003:
    return (uint)pFVar3 & 0xffffff00;
  }
  pFVar3 = (FILE *)___acrt_iob_func(1);
  if (param_1 == pFVar3) {
    piVar5 = &DAT_00769d70;
  }
  else {
    pFVar3 = (FILE *)___acrt_iob_func(2);
    if (param_1 != pFVar3) goto LAB_006e7003;
    piVar5 = &DAT_00769d74;
  }
  _DAT_00769b48 = _DAT_00769b48 + 1;
  piVar1 = &param_1->_flag;
  pFVar3 = (FILE *)*piVar1;
  if (((uint)pFVar3 & 0x4c0) != 0) goto LAB_006e7003;
  LOCK();
  *piVar1 = *piVar1 | 0x282;
  UNLOCK();
  iVar2 = *piVar5;
  if (iVar2 == 0) {
    iVar2 = __malloc_base(0x1000);
    *piVar5 = iVar2;
    FID_conflict__free((void *)0x0);
    iVar2 = *piVar5;
    if (iVar2 == 0) {
      param_1->_base = (char *)0x2;
      param_1->_cnt = (int)&param_1->_charbuf;
      param_1->_ptr = (char *)&param_1->_charbuf;
      param_1->_bufsiz = 2;
      pcVar4 = (char *)0x0;
      goto LAB_006e6fe8;
    }
  }
  param_1->_cnt = iVar2;
  pcVar4 = (char *)*piVar5;
  param_1->_ptr = pcVar4;
  param_1->_base = (char *)0x1000;
  param_1->_bufsiz = 0x1000;
LAB_006e6fe8:
  return CONCAT31((int3)((uint)pcVar4 >> 8),1);
}

