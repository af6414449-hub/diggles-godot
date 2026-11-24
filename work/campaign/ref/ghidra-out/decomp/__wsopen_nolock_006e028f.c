
/* Library Function - Single Match
    __wsopen_nolock
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl
__wsopen_nolock(int *UnlockFlag,int *_FileHandle,wchar_t *_Filename,int _OpenFlag,int _ShareFlag,
               int _PermissionFlag,int _SecureFlag)

{
  uint uVar1;
  undefined4 *puVar2;
  ulong *puVar3;
  int *piVar4;
  void *pvVar5;
  DWORD DVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  wchar_t **ppwVar10;
  wchar_t *apwStack_74 [4];
  uint _FileHandle_00;
  undefined1 local_48 [24];
  byte local_30 [4];
  uint local_2c;
  int local_24;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 local_6;
  byte local_5;
  
  apwStack_74[3] = L"쒃贐푽\xf08b٪\xf359莥ￎ甹痠\xe819܇";
  puVar2 = (undefined4 *)decode_options((int)local_48,_OpenFlag,_ShareFlag);
  pbVar9 = local_30;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined4 *)pbVar9 = *puVar2;
    puVar2 = puVar2 + 1;
    pbVar9 = pbVar9 + 4;
  }
  if (local_24 == -1) {
    puVar3 = ___doserrno();
    *puVar3 = 0;
    *_FileHandle = -1;
    goto LAB_006e02ce;
  }
  iVar7 = __alloc_osfhnd();
  *_FileHandle = iVar7;
  if (iVar7 == -1) {
    puVar3 = ___doserrno();
    *puVar3 = 0;
    *_FileHandle = -1;
    piVar4 = __errno();
    *piVar4 = 0x18;
    goto LAB_006e02ce;
  }
  local_14 = 0;
  local_18 = 0xc;
  *UnlockFlag = 1;
  local_10 = ~((uint)_OpenFlag >> 7) & 1;
  apwStack_74[1] = (wchar_t *)&local_18;
  apwStack_74[0] = _Filename;
  pbVar9 = local_30;
  ppwVar10 = apwStack_74 + 2;
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppwVar10 = (wchar_t *)*(undefined4 *)pbVar9;
    pbVar9 = pbVar9 + 4;
    ppwVar10 = ppwVar10 + 1;
  }
  pvVar5 = create_file();
  local_c = pvVar5;
  if (pvVar5 == (void *)0xffffffff) {
    if (((local_2c & 0xc0000000) == 0xc0000000) && ((_OpenFlag & 1U) != 0)) {
      apwStack_74[1] = (wchar_t *)&local_18;
      local_2c = local_2c & 0x7fffffff;
      apwStack_74[0] = _Filename;
      pbVar9 = local_30;
      ppwVar10 = apwStack_74 + 2;
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *ppwVar10 = (wchar_t *)*(undefined4 *)pbVar9;
        pbVar9 = pbVar9 + 4;
        ppwVar10 = ppwVar10 + 1;
      }
      pvVar5 = create_file();
      local_c = pvVar5;
      if (pvVar5 != (void *)0xffffffff) goto LAB_006e03b5;
    }
    pbVar9 = (byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x28 + (*_FileHandle & 0x3fU) * 0x38);
    *pbVar9 = *pbVar9 & 0xfe;
    GetLastError();
    ___acrt_errno_map_os_error();
  }
  else {
LAB_006e03b5:
    local_c = pvVar5;
    DVar6 = GetFileType(pvVar5);
    if (DVar6 != 0) {
      if (DVar6 == 2) {
        local_30[0] = local_30[0] | 0x40;
      }
      else if (DVar6 == 3) {
        local_30[0] = local_30[0] | 8;
      }
      local_5 = local_30[0];
      ___acrt_lowio_set_os_handle();
      local_5 = local_5 | 1;
      local_30[0] = local_5;
      *(byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x28 + (*_FileHandle & 0x3fU) * 0x38) = local_5
      ;
      *(undefined1 *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x29 + (*_FileHandle & 0x3fU) * 0x38) = 0
      ;
      if (((_OpenFlag & 2U) == 0) || (iVar7 = truncate_ctrl_z_if_present(*_FileHandle), iVar7 == 0))
      {
        local_6 = 0;
        iVar7 = *_FileHandle;
        pbVar9 = local_30;
        ppwVar10 = apwStack_74;
        for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
          *ppwVar10 = (wchar_t *)*(undefined4 *)pbVar9;
          pbVar9 = pbVar9 + 4;
          ppwVar10 = ppwVar10 + 1;
        }
        iVar7 = configure_text_mode(iVar7);
        uVar1 = local_2c;
        _FileHandle_00 = *_FileHandle;
        if (iVar7 == 0) {
          *(undefined1 *)
           ((&DAT_00769d80)[(int)_FileHandle_00 >> 6] + 0x29 + (_FileHandle_00 & 0x3f) * 0x38) =
               local_6;
          iVar7 = (*_FileHandle & 0x3fU) * 0x38;
          pbVar9 = (byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x2d + iVar7);
          *pbVar9 = *pbVar9 ^ ((byte)((uint)_OpenFlag >> 0x10) ^
                              *(byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x2d + iVar7)) & 1;
          if (((local_5 & 0x48) == 0) && ((_OpenFlag & 8U) != 0)) {
            pbVar9 = (byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x28 +
                             (*_FileHandle & 0x3fU) * 0x38);
            *pbVar9 = *pbVar9 | 0x20;
          }
          if (((local_2c & 0xc0000000) == 0xc0000000) && ((_OpenFlag & 1U) != 0)) {
            CloseHandle(local_c);
            apwStack_74[1] = (wchar_t *)&local_18;
            local_2c = uVar1 & 0x7fffffff;
            apwStack_74[0] = _Filename;
            pbVar9 = local_30;
            ppwVar10 = apwStack_74 + 2;
            for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
              *ppwVar10 = (wchar_t *)*(undefined4 *)pbVar9;
              pbVar9 = pbVar9 + 4;
              ppwVar10 = ppwVar10 + 1;
            }
            pvVar5 = create_file();
            if (pvVar5 == (void *)0xffffffff) {
              GetLastError();
              ___acrt_errno_map_os_error();
              pbVar9 = (byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x28 +
                               (*_FileHandle & 0x3fU) * 0x38);
              *pbVar9 = *pbVar9 & 0xfe;
              __free_osfhnd(*_FileHandle);
              goto LAB_006e02ce;
            }
            *(void **)((&DAT_00769d80)[*_FileHandle >> 6] + 0x18 + (*_FileHandle & 0x3fU) * 0x38) =
                 pvVar5;
          }
          return 0;
        }
      }
      else {
        _FileHandle_00 = *_FileHandle;
      }
      __close_nolock(_FileHandle_00);
      return iVar7;
    }
    DVar6 = GetLastError();
    ___acrt_errno_map_os_error();
    pbVar9 = (byte *)((&DAT_00769d80)[*_FileHandle >> 6] + 0x28 + (*_FileHandle & 0x3fU) * 0x38);
    *pbVar9 = *pbVar9 & 0xfe;
    CloseHandle(pvVar5);
    if (DVar6 == 0) {
      piVar4 = __errno();
      *piVar4 = 0xd;
    }
  }
LAB_006e02ce:
  piVar4 = __errno();
  return *piVar4;
}

