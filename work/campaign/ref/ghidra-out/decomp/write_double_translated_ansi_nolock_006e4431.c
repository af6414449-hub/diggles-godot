
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_double_translated_ansi_nolock(int,char
   const * const,unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl write_double_translated_ansi_nolock(int param_1,char *param_2,uint param_3)

{
  byte **ppbVar1;
  uint uVar2;
  ushort *puVar3;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  int in_stack_00000010;
  _Mbstatet *p_Var11;
  size_t _SrcSizeInBytes;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  UINT local_7c;
  byte *local_78;
  HANDLE local_74;
  byte *local_70;
  byte *local_6c;
  byte *local_68;
  byte *local_64;
  DWORD local_60;
  byte *local_5c;
  int local_58;
  int local_54;
  int local_50;
  wchar_t local_4c [2];
  int local_48;
  int local_44;
  char local_3c;
  byte *local_38;
  byte *local_34;
  undefined2 local_30;
  uint local_2c;
  byte *local_28;
  byte local_21;
  undefined1 local_20 [8];
  byte local_18;
  byte local_17;
  byte local_10 [8];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_50 = ((uint)param_2 & 0x3f) * 0x38;
  local_54 = (int)param_2 >> 6;
  local_70 = (byte *)param_3;
  local_74 = *(HANDLE *)(local_50 + 0x18 + (&DAT_00769d80)[local_54]);
  local_68 = (byte *)(in_stack_00000010 + param_3);
  local_7c = GetConsoleCP();
  iVar6 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_48,(__crt_locale_pointers *)0x0);
  local_60 = 0;
  local_80 = *(int *)(local_44 + 8);
  local_5c = (byte *)0x0;
  local_58 = 0;
  local_28 = local_70;
  pbVar10 = local_70;
  if ((byte *)(in_stack_00000010 + param_3) <= local_70) {
LAB_006e47b5:
    if (local_3c != '\0') {
      *(uint *)(local_48 + 0x350) = *(uint *)(local_48 + 0x350) & 0xfffffffd;
    }
    *(DWORD *)param_1 = local_60;
    *(byte **)(param_1 + 4) = local_5c;
    *(int *)(param_1 + 8) = local_58;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_006e44af:
  pbVar9 = local_28;
  pbVar7 = local_5c;
  local_30 = CONCAT11(*pbVar10,(undefined1)local_30);
  local_4c[0] = L'\0';
  local_4c[1] = L'\0';
  local_2c = 1;
  local_34 = (byte *)(&DAT_00769d80)[local_54];
  if (local_80 == 0xfde9) {
    local_6c = local_34 + local_50 + 0x2e;
    local_2c = 0;
    do {
      if (local_6c[local_2c] == 0) break;
      local_2c = local_2c + 1;
    } while ((int)local_2c < 5);
    iVar8 = (int)local_68 - (int)local_28;
    if ((int)local_2c < 1) {
      local_34 = (byte *)((char)(&DAT_00767110)[*local_28] + 1);
      if (iVar8 < (int)local_34) {
        if (0 < iVar8) {
          do {
            iVar5 = local_50 + iVar6;
            pbVar10 = local_28 + iVar6;
            iVar6 = iVar6 + 1;
            *(byte *)(iVar5 + 0x2e + (&DAT_00769d80)[local_54]) = *pbVar10;
          } while (iVar6 < iVar8);
        }
        goto LAB_006e4757;
      }
      local_90 = 0;
      p_Var11 = (_Mbstatet *)&local_90;
      local_8c = 0;
      local_38 = local_28;
      ppbVar1 = &local_38;
      pbVar10 = local_34;
    }
    else {
      local_38 = (byte *)((char)(&DAT_00767110)[local_34[local_50 + 0x2e]] + 1);
      local_34 = local_38 + -local_2c;
      if (iVar8 < (int)local_34) {
        if (0 < iVar8) {
          do {
            iVar5 = local_50 + iVar6;
            pbVar10 = local_28 + iVar6;
            iVar6 = iVar6 + 1;
            *(byte *)(iVar5 + local_2c + 0x2e + (&DAT_00769d80)[local_54]) = *pbVar10;
          } while (iVar6 < iVar8);
        }
LAB_006e4757:
        local_5c = local_5c + iVar8;
        goto LAB_006e47b5;
      }
      iVar8 = 0;
      if (0 < (int)local_2c) {
        do {
          local_10[iVar8] = local_6c[iVar8];
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)local_2c);
      }
      if (0 < (int)local_34) {
        FUN_006d2250(local_10 + local_2c,local_28,local_34);
      }
      if (0 < (int)local_2c) {
        iVar8 = 0;
        do {
          iVar5 = local_50 + iVar8;
          iVar8 = iVar8 + 1;
          *(undefined1 *)(iVar5 + 0x2e + (&DAT_00769d80)[local_54]) = 0;
          pbVar9 = local_28;
        } while (iVar8 < (int)local_2c);
      }
      local_78 = local_10;
      local_88 = 0;
      p_Var11 = (_Mbstatet *)&local_88;
      local_84 = 0;
      ppbVar1 = &local_78;
      pbVar10 = local_38;
    }
    local_2c = (pbVar10 == &DAT_00000004) + 1;
    uVar2 = __crt_mbstring::__mbsrtowcs_utf8(local_4c,(char **)ppbVar1,local_2c,p_Var11);
    if (uVar2 == 0xffffffff) goto LAB_006e47b5;
    pbVar10 = pbVar9 + (int)(local_34 + -1);
  }
  else {
    if ((local_34[local_50 + 0x2d] & 4) == 0) {
      local_21 = *pbVar10;
      puVar3 = ___pctype_func();
      if ((short)puVar3[local_21] < 0) {
        local_38 = pbVar10 + 1;
        if (local_38 < local_68) {
          iVar8 = _mbtowc(local_4c,(char *)pbVar10,2);
          pbVar10 = local_38;
          if (iVar8 != -1) goto LAB_006e4686;
        }
        else {
          *(byte *)(local_50 + 0x2e + (&DAT_00769d80)[local_54]) = local_21;
          pbVar10 = (byte *)(local_50 + 0x2d + (&DAT_00769d80)[local_54]);
          *pbVar10 = *pbVar10 | 4;
          local_5c = pbVar7 + 1;
        }
        goto LAB_006e47b5;
      }
      _SrcSizeInBytes = 1;
      pbVar7 = pbVar10;
    }
    else {
      local_18 = local_34[local_50 + 0x2e];
      local_17 = *pbVar10;
      _SrcSizeInBytes = 2;
      local_34[local_50 + 0x2d] = local_34[local_50 + 0x2d] & 0xfb;
      pbVar7 = &local_18;
    }
    iVar8 = _mbtowc(local_4c,(char *)pbVar7,_SrcSizeInBytes);
    if (iVar8 == -1) goto LAB_006e47b5;
  }
LAB_006e4686:
  pbVar10 = pbVar10 + 1;
  local_28 = pbVar10;
  local_38 = (byte *)___acrt_WideCharToMultiByte(local_7c,0,local_4c,local_2c,local_20,5,0,0);
  if (local_38 == (byte *)0x0) goto LAB_006e47b5;
  BVar4 = WriteFile(local_74,local_20,(DWORD)local_38,(LPDWORD)&local_64,(LPOVERLAPPED)0x0);
  if (BVar4 == 0) {
LAB_006e47a9:
    local_60 = GetLastError();
    goto LAB_006e47b5;
  }
  pbVar7 = pbVar10 + (local_58 - (int)local_70);
  local_5c = pbVar7;
  if (local_64 < local_38) goto LAB_006e47b5;
  if (local_30._1_1_ == '\n') {
    local_30 = 0xd;
    BVar4 = WriteFile(local_74,&local_30,1,(LPDWORD)&local_64,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) goto LAB_006e47a9;
    if (local_64 == (byte *)0x0) goto LAB_006e47b5;
    local_58 = local_58 + 1;
    pbVar7 = pbVar7 + 1;
  }
  local_5c = pbVar7;
  if (local_68 <= pbVar10) goto LAB_006e47b5;
  goto LAB_006e44af;
}

