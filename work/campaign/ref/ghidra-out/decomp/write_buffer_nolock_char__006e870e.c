
/* Library Function - Single Match
    bool __cdecl write_buffer_nolock<char>(char,class __crt_stdio_stream)
   
   Library: Visual Studio 2019 Release */

bool __cdecl write_buffer_nolock<char>(undefined1 param_1,FILE *param_2)

{
  uint _FileHandle;
  undefined *puVar1;
  int iVar2;
  uint _MaxCharCount;
  int unaff_EDI;
  uint uVar3;
  char cVar4;
  longlong lVar5;
  
  _FileHandle = __fileno(param_2);
  if ((param_2->_flag & 0xc0U) == 0) {
    iVar2 = __write(_FileHandle,&param_1,1);
    cVar4 = '\x01' - (iVar2 != 1);
  }
  else {
    uVar3 = 0;
    _MaxCharCount = (int)param_2->_ptr - param_2->_cnt;
    param_2->_ptr = (char *)(param_2->_cnt + 1);
    param_2->_base = (char *)(param_2->_bufsiz + -1);
    if ((int)_MaxCharCount < 1) {
      if ((_FileHandle == 0xffffffff) || (_FileHandle == 0xfffffffe)) {
        puVar1 = &DAT_007672e0;
      }
      else {
        puVar1 = (undefined *)((_FileHandle & 0x3f) * 0x38 + (&DAT_00769d80)[(int)_FileHandle >> 6])
        ;
      }
      if (((puVar1[0x28] & 0x20) != 0) &&
         (lVar5 = __lseeki64(_FileHandle,0x200000000,unaff_EDI), lVar5 == -1)) {
        LOCK();
        param_2->_flag = param_2->_flag | 0x10;
        UNLOCK();
        return true;
      }
    }
    else {
      uVar3 = __write(_FileHandle,(void *)param_2->_cnt,_MaxCharCount);
    }
    cVar4 = uVar3 == _MaxCharCount;
    *(undefined1 *)param_2->_cnt = param_1;
  }
  return (bool)cVar4;
}

