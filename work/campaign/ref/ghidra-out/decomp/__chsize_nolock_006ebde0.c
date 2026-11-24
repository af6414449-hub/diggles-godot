
/* Library Function - Single Match
    __chsize_nolock
   
   Library: Visual Studio 2019 Release */

int __cdecl __chsize_nolock(int _FileHandle,longlong _Size)

{
  void *_Buf;
  int *piVar1;
  uint uVar2;
  ulong *puVar3;
  HANDLE hFile;
  BOOL BVar4;
  DWORD DVar5;
  int unaff_EDI;
  uint uVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  __crt_seek_guard::__crt_seek_guard
            ((__crt_seek_guard *)&local_2c,_FileHandle,CONCAT44(unaff_EDI,(undefined4)_Size));
  if (((local_2c & local_28) != 0xffffffff) && ((local_24 & local_20) != 0xffffffff)) {
    local_8 = local_18;
    if (-1 < local_18) {
      if ((local_18 < 1) && (local_1c == 0)) {
        if ((local_18 < 1) && (local_18 < 0)) goto LAB_006ebeeb;
      }
      else {
        _Buf = (void *)__calloc_base(0x1000,1);
        if (_Buf == (void *)0x0) {
          piVar1 = __errno();
          *piVar1 = 0xc;
LAB_006ebed1:
          piVar1 = __errno();
          iVar8 = *piVar1;
          FID_conflict__free(_Buf);
          goto LAB_006ebf36;
        }
        local_c = __setmode_nolock(_FileHandle,0x8000);
        do {
          uVar6 = local_1c;
          if (local_18 < 0) goto LAB_006ebe81;
          uVar7 = local_1c;
          if ((local_18 < 1) && (local_1c < 0x1000)) goto LAB_006ebe81;
          do {
            local_1c = 0x1000;
            uVar6 = uVar7;
LAB_006ebe81:
            uVar2 = __write_nolock(_FileHandle,_Buf,local_1c);
            if (uVar2 == 0xffffffff) {
              puVar3 = ___doserrno();
              if (*puVar3 == 5) {
                piVar1 = __errno();
                *piVar1 = 0xd;
              }
              goto LAB_006ebed1;
            }
            uVar7 = uVar6 - uVar2;
            local_18 = (local_8 - ((int)uVar2 >> 0x1f)) - (uint)(uVar6 < uVar2);
            local_8 = local_18;
          } while (0 < local_18);
        } while ((-1 < local_18) && (local_1c = uVar7, uVar7 != 0));
        __setmode_nolock(_FileHandle,local_c);
        FID_conflict__free(_Buf);
      }
LAB_006ebeb8:
      iVar8 = 0;
      goto LAB_006ebf36;
    }
LAB_006ebeeb:
    lVar9 = __lseeki64_nolock(_FileHandle,_Size & 0xffffffff,unaff_EDI);
    if (lVar9 != -1) {
      hFile = (HANDLE)__get_osfhandle(_FileHandle);
      BVar4 = SetEndOfFile(hFile);
      if (BVar4 != 0) goto LAB_006ebeb8;
      piVar1 = __errno();
      *piVar1 = 0xd;
      puVar3 = ___doserrno();
      DVar5 = GetLastError();
      *puVar3 = DVar5;
    }
  }
  piVar1 = __errno();
  iVar8 = *piVar1;
LAB_006ebf36:
  __lseeki64_nolock(local_14,(ulonglong)local_28,unaff_EDI);
  return iVar8;
}

