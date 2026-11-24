
/* Library Function - Single Match
    __write_nolock
   
   Library: Visual Studio 2019 Release */

int __cdecl __write_nolock(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  char cVar1;
  char *pcVar2;
  bool bVar3;
  ulong *puVar4;
  int *piVar5;
  DWORD *pDVar6;
  BOOL BVar7;
  int unaff_EDI;
  DWORD local_2c [6];
  uint local_14;
  int local_10;
  int local_c;
  char *local_8;
  
  local_8 = (char *)_Buf;
  local_14 = _MaxCharCount;
  if (_MaxCharCount == 0) {
    return 0;
  }
  if (_Buf == (void *)0x0) {
LAB_006e4cc2:
    puVar4 = ___doserrno();
    *puVar4 = 0;
    piVar5 = __errno();
    *piVar5 = 0x16;
    FUN_006e510d();
    return -1;
  }
  local_c = _FileHandle >> 6;
  local_10 = (_FileHandle & 0x3fU) * 0x38;
  cVar1 = *(char *)((&DAT_00769d80)[local_c] + 0x29 + local_10);
  if (((cVar1 == '\x02') || (cVar1 == '\x01')) && ((~_MaxCharCount & 1) == 0)) goto LAB_006e4cc2;
  if ((*(byte *)((&DAT_00769d80)[local_c] + 0x28 + local_10) & 0x20) != 0) {
    __lseeki64_nolock(_FileHandle,0x200000000,unaff_EDI);
  }
  local_2c[3] = 0;
  local_2c[4] = 0;
  local_2c[5] = 0;
  bVar3 = write_requires_double_translation_nolock(_FileHandle);
  pcVar2 = local_8;
  if (bVar3) {
    if (cVar1 == '\0') {
      pDVar6 = (DWORD *)write_double_translated_ansi_nolock
                                  ((int)local_2c,(char *)_FileHandle,(uint)local_8);
    }
    else {
      if (1 < (byte)(cVar1 - 1U)) goto LAB_006e4e0f;
      pDVar6 = (DWORD *)write_double_translated_unicode_nolock((char *)local_2c,(uint)local_8);
    }
  }
  else if (*(char *)((&DAT_00769d80)[local_c] + 0x28 + local_10) < '\0') {
    if (cVar1 == '\0') {
      pDVar6 = (DWORD *)write_text_ansi_nolock((int)local_2c,(char *)_FileHandle,(uint)local_8);
    }
    else if (cVar1 == '\x01') {
      pDVar6 = (DWORD *)write_text_utf8_nolock((int)local_2c,(char *)_FileHandle,(uint)local_8);
    }
    else {
      if (cVar1 != '\x02') goto LAB_006e4e0f;
      pDVar6 = (DWORD *)write_text_utf16le_nolock((int)local_2c,(char *)_FileHandle,(uint)local_8);
    }
  }
  else {
    local_2c[0] = 0;
    local_2c[1] = 0;
    local_2c[2] = 0;
    BVar7 = WriteFile(*(HANDLE *)((&DAT_00769d80)[local_c] + 0x18 + local_10),local_8,local_14,
                      local_2c + 1,(LPOVERLAPPED)0x0);
    if (BVar7 == 0) {
      local_2c[0] = GetLastError();
    }
    pDVar6 = local_2c;
  }
  local_2c[3] = *pDVar6;
  local_2c[4] = pDVar6[1];
  local_2c[5] = pDVar6[2];
LAB_006e4e0f:
  if (local_2c[4] != 0) {
    return local_2c[4] - local_2c[5];
  }
  if (local_2c[3] != 0) {
    if (local_2c[3] == 5) {
      piVar5 = __errno();
      *piVar5 = 9;
      puVar4 = ___doserrno();
      *puVar4 = 5;
      return -1;
    }
    ___acrt_errno_map_os_error(local_2c[3]);
    return -1;
  }
  if (((*(byte *)((&DAT_00769d80)[local_c] + 0x28 + local_10) & 0x40) != 0) && (*pcVar2 == '\x1a'))
  {
    return 0;
  }
  piVar5 = __errno();
  *piVar5 = 0x1c;
  puVar4 = ___doserrno();
  *puVar4 = 0;
  return -1;
}

