
/* Library Function - Single Match
    __read_nolock
   
   Library: Visual Studio 2019 Release */

int __cdecl __read_nolock(int _FileHandle,void *_DstBuf,uint _MaxCharCount)

{
  byte bVar1;
  char cVar2;
  ulong *puVar3;
  int *piVar4;
  wchar_t *pwVar5;
  int iVar6;
  BOOL BVar7;
  DWORD DVar8;
  uint uVar9;
  int unaff_ESI;
  wchar_t *_Memory;
  int iVar10;
  longlong lVar11;
  DWORD local_2c;
  wchar_t *local_28;
  uint local_24;
  uint local_20;
  HANDLE local_1c;
  wchar_t *local_18;
  int local_14;
  uint local_10;
  int local_c;
  char local_5;
  
  if (_FileHandle == -2) {
    puVar3 = ___doserrno();
    *puVar3 = 0;
    piVar4 = __errno();
    *piVar4 = 9;
    return -1;
  }
  if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_00769f80)) {
    local_c = _FileHandle >> 6;
    iVar10 = (_FileHandle & 0x3fU) * 0x38;
    iVar6 = (&DAT_00769d80)[local_c];
    local_24 = 1;
    bVar1 = *(byte *)(iVar6 + 0x28 + iVar10);
    local_14 = iVar10;
    if ((bVar1 & 1) != 0) {
      if (_MaxCharCount < 0x80000000) {
        if ((_MaxCharCount == 0) || ((bVar1 & 2) != 0)) {
          return 0;
        }
        if (_DstBuf != (void *)0x0) {
          local_1c = *(HANDLE *)(iVar6 + 0x18 + iVar10);
          local_5 = *(char *)(iVar6 + 0x29 + iVar10);
          _Memory = (wchar_t *)0x0;
          if (local_5 == '\x01') {
            if ((~_MaxCharCount & 1) == 0) {
LAB_006e3fa4:
              puVar3 = ___doserrno();
              *puVar3 = 0;
              piVar4 = __errno();
              *piVar4 = 0x16;
              FUN_006e510d();
              pwVar5 = _Memory;
            }
            else {
              local_10 = 4;
              if (3 < _MaxCharCount >> 1) {
                local_10 = _MaxCharCount >> 1;
              }
              pwVar5 = (wchar_t *)__malloc_base(local_10);
              FID_conflict__free((void *)0x0);
              FID_conflict__free((void *)0x0);
              local_18 = pwVar5;
              if (pwVar5 != (wchar_t *)0x0) {
                lVar11 = __lseeki64_nolock(_FileHandle,0x100000000,unaff_ESI);
                iVar6 = (&DAT_00769d80)[local_c];
                *(int *)(iVar10 + 0x20 + iVar6) = (int)lVar11;
                *(int *)(iVar10 + 0x24 + iVar6) = (int)((ulonglong)lVar11 >> 0x20);
                iVar6 = (&DAT_00769d80)[local_c];
                _Memory = pwVar5;
                goto LAB_006e405c;
              }
              piVar4 = __errno();
              *piVar4 = 0xc;
              puVar3 = ___doserrno();
              *puVar3 = 8;
            }
LAB_006e4190:
            uVar9 = 0xffffffff;
            _Memory = pwVar5;
          }
          else {
            pwVar5 = (wchar_t *)_DstBuf;
            if (local_5 == '\x02') {
              if ((~_MaxCharCount & 1) == 0) goto LAB_006e3fa4;
              local_10 = _MaxCharCount;
              local_18 = (wchar_t *)_DstBuf;
              iVar6 = (&DAT_00769d80)[local_c];
            }
            else {
              local_10 = _MaxCharCount;
              local_18 = (wchar_t *)_DstBuf;
            }
LAB_006e405c:
            iVar10 = 0;
            uVar9 = local_10;
            if ((((*(byte *)(local_14 + 0x28 + iVar6) & 0x48) != 0) &&
                (cVar2 = *(char *)(local_14 + 0x2a + iVar6), cVar2 != '\n')) && (local_10 != 0)) {
              iVar10 = 1;
              *(char *)pwVar5 = cVar2;
              local_18 = (wchar_t *)((int)pwVar5 + 1);
              uVar9 = local_10 - 1;
              *(undefined1 *)(local_14 + 0x2a + (&DAT_00769d80)[local_c]) = 10;
              if (((local_5 != '\0') &&
                  (cVar2 = *(char *)(local_14 + 0x2b + (&DAT_00769d80)[local_c]), cVar2 != '\n')) &&
                 (uVar9 != 0)) {
                *(char *)local_18 = cVar2;
                local_18 = pwVar5 + 1;
                uVar9 = local_10 - 2;
                iVar10 = 2;
                *(undefined1 *)(local_14 + 0x2b + (&DAT_00769d80)[local_c]) = 10;
                if (((local_5 == '\x01') &&
                    (cVar2 = *(char *)(local_14 + 0x2c + (&DAT_00769d80)[local_c]), cVar2 != '\n'))
                   && (uVar9 != 0)) {
                  *(char *)local_18 = cVar2;
                  local_18 = (wchar_t *)((int)pwVar5 + 3);
                  iVar10 = 3;
                  *(undefined1 *)(local_14 + 0x2c + (&DAT_00769d80)[local_c]) = 10;
                  uVar9 = local_10 - 3;
                }
              }
            }
            local_10 = uVar9;
            local_28 = pwVar5;
            iVar6 = __isatty(_FileHandle);
            pwVar5 = _Memory;
            if (((iVar6 == 0) || (-1 < *(char *)(local_14 + 0x28 + (&DAT_00769d80)[local_c]))) ||
               (BVar7 = GetConsoleMode(local_1c,&local_2c), BVar7 == 0)) {
              local_24 = local_24 & 0xffffff00;
LAB_006e41b1:
              BVar7 = ReadFile(local_1c,local_18,local_10,&local_20,(LPOVERLAPPED)0x0);
              if ((BVar7 == 0) || (_MaxCharCount < local_20)) {
                DVar8 = GetLastError();
                if (DVar8 != 5) {
                  if (DVar8 == 0x6d) {
                    uVar9 = 0;
                    goto LAB_006e4193;
                  }
                  goto LAB_006e4189;
                }
                piVar4 = __errno();
                *piVar4 = 9;
                puVar3 = ___doserrno();
                *puVar3 = 5;
                goto LAB_006e4190;
              }
            }
            else {
              if (local_5 != '\x02') goto LAB_006e41b1;
              BVar7 = ReadConsoleW(local_1c,local_18,local_10 >> 1,&local_20,
                                   (PCONSOLE_READCONSOLE_CONTROL)0x0);
              if (BVar7 == 0) {
                DVar8 = GetLastError();
LAB_006e4189:
                ___acrt_errno_map_os_error(DVar8);
                goto LAB_006e4190;
              }
              local_20 = local_20 * 2;
            }
            uVar9 = iVar10 + local_20;
            if (*(char *)(local_14 + 0x28 + (&DAT_00769d80)[local_c]) < '\0') {
              if (local_5 == '\x02') {
                if ((char)local_24 == '\0') {
                  uVar9 = translate_text_mode_nolock<wchar_t>(_FileHandle,local_28,uVar9 >> 1);
                }
                else {
                  uVar9 = translate_utf16_from_console_nolock(_FileHandle,local_28,uVar9 >> 1);
                }
              }
              else {
                uVar9 = translate_ansi_or_utf8_nolock
                                  (_FileHandle,(char *)local_18,uVar9,(wchar_t *)_DstBuf,
                                   _MaxCharCount >> 1);
              }
            }
          }
LAB_006e4193:
          FID_conflict__free(_Memory);
          return uVar9;
        }
      }
      puVar3 = ___doserrno();
      *puVar3 = 0;
      piVar4 = __errno();
      *piVar4 = 0x16;
      goto LAB_006e4270;
    }
  }
  puVar3 = ___doserrno();
  *puVar3 = 0;
  piVar4 = __errno();
  *piVar4 = 9;
LAB_006e4270:
  FUN_006e510d();
  return -1;
}

