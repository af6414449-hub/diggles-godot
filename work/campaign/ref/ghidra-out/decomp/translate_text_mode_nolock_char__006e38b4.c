
/* Library Function - Single Match
    int __cdecl translate_text_mode_nolock<char>(int,char * const,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl translate_text_mode_nolock<char>(int param_1,char *param_2,uint param_3)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  char *pcVar6;
  BOOL BVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int unaff_EDI;
  int iVar11;
  DWORD local_20;
  HANDLE local_1c;
  char *local_18;
  char *local_14;
  int local_10;
  char *local_c;
  char local_5;
  
  iVar8 = param_1 >> 6;
  iVar11 = (param_1 & 0x3fU) * 0x38;
  iVar4 = (&DAT_00769d80)[iVar8];
  local_1c = *(HANDLE *)(iVar4 + 0x18 + iVar11);
  if ((param_3 == 0) || (*param_2 != '\n')) {
    pbVar1 = (byte *)(iVar4 + 0x28 + iVar11);
    *pbVar1 = *pbVar1 & 0xfb;
  }
  else {
    pbVar1 = (byte *)(iVar4 + 0x28 + iVar11);
    *pbVar1 = *pbVar1 | 4;
  }
  local_14 = param_2 + param_3;
  local_c = param_2;
  pcVar9 = param_2;
  pcVar10 = param_2;
  local_10 = iVar8;
  if (param_2 < local_14) {
    do {
      cVar2 = *local_c;
      pcVar10 = pcVar9;
      if (cVar2 == '\x1a') {
        bVar3 = *(byte *)((&DAT_00769d80)[iVar8] + 0x28 + iVar11);
        if ((bVar3 & 0x40) == 0) {
          *(byte *)((&DAT_00769d80)[iVar8] + 0x28 + iVar11) = bVar3 | 2;
        }
        else {
          *pcVar9 = '\x1a';
          pcVar10 = pcVar9 + 1;
        }
        break;
      }
      pcVar6 = local_c + 1;
      if (cVar2 == '\r') {
        if (pcVar6 < local_14) {
          cVar2 = *pcVar6;
          cVar5 = '\r';
          if (cVar2 == '\n') {
            cVar5 = '\n';
          }
          *pcVar9 = cVar5;
          local_c = local_c + (cVar2 == '\n') + 1;
          pcVar10 = pcVar9 + 1;
          local_18 = pcVar9 + 1;
        }
        else {
          local_c = pcVar6;
          BVar7 = ReadFile(local_1c,&local_5,1,&local_20,(LPOVERLAPPED)0x0);
          if ((BVar7 == 0) || (local_20 == 0)) {
LAB_006e39df:
            *pcVar9 = '\r';
LAB_006e39e2:
            iVar8 = local_10;
            pcVar10 = pcVar9 + 1;
          }
          else if ((*(byte *)((&DAT_00769d80)[local_10] + 0x28 + iVar11) & 0x48) == 0) {
            if ((local_5 == '\n') && (pcVar9 == param_2)) {
              *pcVar9 = '\n';
              goto LAB_006e39e2;
            }
            __lseeki64_nolock(param_1,0x1ffffffff,unaff_EDI);
            iVar8 = local_10;
            if (local_5 != '\n') goto LAB_006e39df;
          }
          else {
            pcVar10 = pcVar9 + 1;
            iVar8 = local_10;
            local_18 = pcVar10;
            if (local_5 == '\n') {
              *pcVar9 = '\n';
            }
            else {
              *pcVar9 = '\r';
              *(char *)((&DAT_00769d80)[local_10] + 0x2a + iVar11) = local_5;
            }
          }
        }
      }
      else {
        *pcVar9 = cVar2;
        pcVar10 = pcVar9 + 1;
        local_c = pcVar6;
      }
      pcVar9 = pcVar10;
    } while (local_c < local_14);
  }
  return (int)pcVar10 - (int)param_2;
}

