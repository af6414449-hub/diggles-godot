
/* Library Function - Single Match
    __fwrite_nolock
   
   Library: Visual Studio 2019 Release */

size_t __cdecl __fwrite_nolock(void *_DstBuf,size_t _Size,size_t _Count,FILE *_File)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_c;
  char *local_8;
  
  if ((_Size != 0) && (_Count != 0)) {
    if ((_File != (FILE *)0x0) &&
       ((_DstBuf != (void *)0x0 && (_Count <= (uint)(0xffffffff / (ulonglong)_Size))))) {
      piVar1 = &_File->_flag;
      if ((*piVar1 & 0x4c0U) == 0) {
        local_8 = (char *)0x1000;
      }
      else {
        local_8 = (char *)_File->_bufsiz;
      }
      pcVar5 = (char *)(_Size * _Count);
      do {
        if (pcVar5 == (char *)0x0) {
          return _Count;
        }
        if (((_File->_flag & 0xc0U) == 0) || (_File->_base == (char *)0x0)) {
          if (local_8 <= pcVar5) {
            if (((_File->_flag & 0xc0U) != 0) &&
               (iVar2 = ___acrt_stdio_flush_nolock(_File), iVar2 != 0)) goto LAB_006d4b6e;
            local_c = pcVar5;
            if (local_8 != (char *)0x0) {
              local_c = pcVar5 + -((uint)pcVar5 % (uint)local_8);
            }
            if ((char *)0xfffffffd < local_c) {
              local_c = (char *)0xfffffffe;
            }
            pcVar3 = (char *)_DstBuf;
            pcVar4 = local_c;
            iVar2 = __fileno(_File);
            pcVar3 = (char *)__write(iVar2,pcVar3,(uint)pcVar4);
            if (pcVar3 != (char *)0xffffffff) {
              pcVar4 = local_c;
              if (pcVar3 <= local_c) {
                pcVar4 = pcVar3;
              }
              pcVar5 = pcVar5 + -(int)pcVar4;
              if (local_c <= pcVar3) goto LAB_006d4b4d;
            }
LAB_006d4b65:
            LOCK();
            *piVar1 = *piVar1 | 0x10;
            UNLOCK();
LAB_006d4b6e:
            return (uint)((int)(_Size * _Count) - (int)pcVar5) / _Size;
          }
                    /* WARNING: Load size is inaccurate */
          iVar2 = FUN_006e885f((int)*_DstBuf,_File);
          if (iVar2 == -1) goto LAB_006d4b6e;
          local_8 = (char *)_File->_bufsiz;
          pcVar5 = pcVar5 + -1;
          if ((int)local_8 < 1) {
            local_8 = (char *)0x1;
          }
          pcVar4 = (char *)0x1;
        }
        else {
          if ((int)_File->_base < 0) goto LAB_006d4b65;
          if ((_File->_flag & 1U) != 0) goto LAB_006d4b6e;
          pcVar4 = _File->_base;
          if (pcVar5 < _File->_base) {
            pcVar4 = pcVar5;
          }
          FUN_006d2250(_File->_ptr,_DstBuf,pcVar4);
          _File->_base = _File->_base + -(int)pcVar4;
          pcVar5 = pcVar5 + -(int)pcVar4;
          _File->_ptr = pcVar4 + (int)_File->_ptr;
        }
LAB_006d4b4d:
        _DstBuf = (void *)((int)_DstBuf + (int)pcVar4);
      } while( true );
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  return 0;
}

