
/* Library Function - Single Match
    void __cdecl initialize_inherited_file_handles_nolock(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl initialize_inherited_file_handles_nolock(void)

{
  byte bVar1;
  HANDLE hFile;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  _STARTUPINFOW local_4c;
  undefined4 *local_8;
  
  GetStartupInfoW(&local_4c);
  if ((local_4c.cbReserved2 != 0) && ((uint *)local_4c.lpReserved2 != (uint *)0x0)) {
    uVar4 = *(uint *)local_4c.lpReserved2;
    local_8 = (undefined4 *)((int)local_4c.lpReserved2 + uVar4 + 4);
    if (0x1fff < (int)uVar4) {
      uVar4 = 0x2000;
    }
    ___acrt_lowio_ensure_fh_exists(uVar4);
    if ((int)DAT_00769f80 < (int)uVar4) {
      uVar4 = DAT_00769f80;
    }
    uVar5 = 0;
    if (uVar4 != 0) {
      do {
        hFile = (HANDLE)*local_8;
        if ((((hFile != (HANDLE)0xffffffff) && (hFile != (HANDLE)0xfffffffe)) &&
            (bVar1 = *(byte *)(uVar5 + 4 + (int)local_4c.lpReserved2), (bVar1 & 1) != 0)) &&
           (((bVar1 & 8) != 0 || (DVar2 = GetFileType(hFile), DVar2 != 0)))) {
          iVar3 = (uVar5 & 0x3f) * 0x38 + (&DAT_00769d80)[(int)uVar5 >> 6];
          *(undefined4 *)(iVar3 + 0x18) = *local_8;
          *(undefined1 *)(iVar3 + 0x28) = *(undefined1 *)(uVar5 + 4 + (int)local_4c.lpReserved2);
        }
        uVar5 = uVar5 + 1;
        local_8 = local_8 + 1;
      } while (uVar5 != uVar4);
    }
  }
  return;
}

