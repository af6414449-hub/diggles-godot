
/* Library Function - Single Match
    int __cdecl translate_text_mode_nolock<wchar_t>(int,wchar_t * const,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl translate_text_mode_nolock<wchar_t>(int param_1,wchar_t *param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  wchar_t wVar3;
  int iVar4;
  wchar_t wVar5;
  BOOL BVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  int unaff_EDI;
  int iVar9;
  DWORD local_28;
  HANDLE local_24;
  wchar_t *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  wchar_t *local_14;
  wchar_t *local_10;
  int local_c;
  short local_8 [2];
  
  local_c = param_1 >> 6;
  iVar9 = (param_1 & 0x3fU) * 0x38;
  iVar4 = (&DAT_00769d80)[local_c];
  local_24 = *(HANDLE *)(iVar9 + 0x18 + iVar4);
  if ((param_3 == 0) || (*param_2 != L'\n')) {
    pbVar1 = (byte *)(iVar9 + 0x28 + iVar4);
    *pbVar1 = *pbVar1 & 0xfb;
  }
  else {
    pbVar1 = (byte *)(iVar9 + 0x28 + iVar4);
    *pbVar1 = *pbVar1 | 4;
  }
  local_14 = param_2 + param_3;
  pwVar8 = param_2;
  if (param_2 < local_14) {
    local_18 = 0x1a;
    local_1c = 0xd;
    pwVar7 = param_2;
    do {
      wVar5 = *pwVar7;
      if (wVar5 == (wchar_t)local_18) {
        bVar2 = *(byte *)((&DAT_00769d80)[local_c] + 0x28 + iVar9);
        if ((bVar2 & 0x40) == 0) {
          *(byte *)((&DAT_00769d80)[local_c] + 0x28 + iVar9) = bVar2 | 2;
        }
        else {
          *pwVar8 = L'\x1a';
          pwVar8 = pwVar8 + 1;
        }
        break;
      }
      local_10 = pwVar7 + 1;
      if (wVar5 == (wchar_t)local_1c) {
        if (local_10 < local_14) {
          wVar3 = *local_10;
          local_20 = pwVar8 + 1;
          if (wVar3 == L'\n') {
            wVar5 = L'\n';
          }
          *pwVar8 = wVar5;
          local_10 = pwVar7 + (wVar3 == L'\n') + 1;
          pwVar8 = local_20;
        }
        else {
          BVar6 = ReadFile(local_24,local_8,2,&local_28,(LPOVERLAPPED)0x0);
          if ((BVar6 == 0) || (local_28 == 0)) {
LAB_006e3ba3:
            wVar5 = L'\r';
            goto LAB_006e3ba6;
          }
          if ((*(byte *)(iVar9 + 0x28 + (&DAT_00769d80)[local_c]) & 0x48) == 0) {
            if ((local_8[0] != 10) || (pwVar8 != param_2)) {
              __lseeki64_nolock(param_1,0x1ffffffff,unaff_EDI);
              if (local_8[0] == 10) goto LAB_006e3baf;
              goto LAB_006e3ba3;
            }
            *pwVar8 = L'\n';
          }
          else {
            local_20 = pwVar8 + 1;
            if (local_8[0] == 10) {
              *pwVar8 = L'\n';
            }
            else {
              *pwVar8 = L'\r';
              *(char *)(iVar9 + 0x2a + (&DAT_00769d80)[local_c]) = (char)local_8[0];
              *(char *)(iVar9 + 0x2b + (&DAT_00769d80)[local_c]) = (char)((ushort)local_8[0] >> 8);
              *(undefined1 *)(iVar9 + 0x2c + (&DAT_00769d80)[local_c]) = 10;
            }
          }
          pwVar8 = pwVar8 + 1;
        }
      }
      else {
LAB_006e3ba6:
        *pwVar8 = wVar5;
        pwVar8 = pwVar8 + 1;
      }
LAB_006e3baf:
      pwVar7 = local_10;
    } while (local_10 < local_14);
  }
  return (int)pwVar8 - (int)param_2 & 0xfffffffe;
}

