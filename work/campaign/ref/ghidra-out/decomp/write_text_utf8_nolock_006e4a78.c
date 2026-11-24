
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    struct `anonymous namespace'::write_result __cdecl write_text_utf8_nolock(int,char const *
   const,unsigned int)
   
   Library: Visual Studio 2019 Release */

void __cdecl write_text_utf8_nolock(int param_1,char *param_2,uint param_3)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  BOOL BVar4;
  DWORD DVar5;
  uint uVar6;
  short *psVar7;
  int in_stack_00000010;
  DWORD local_1418;
  HANDLE local_1414;
  short *local_1410;
  undefined1 local_140c [3416];
  short local_6b4 [854];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_1414 = *(HANDLE *)
                ((&DAT_00769d80)[(int)param_2 >> 6] + 0x18 + ((uint)param_2 & 0x3f) * 0x38);
  local_1410 = (short *)(in_stack_00000010 + param_3);
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  psVar7 = (short *)param_3;
  if (param_3 < local_1410) {
    do {
      psVar2 = local_6b4;
      do {
        if (local_1410 <= psVar7) break;
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
        if (sVar1 == 10) {
          *psVar2 = 0xd;
          psVar2 = psVar2 + 1;
        }
        *psVar2 = sVar1;
        psVar2 = psVar2 + 1;
      } while (psVar2 < local_6b4 + 0x354);
      uVar3 = ___acrt_WideCharToMultiByte
                        (0xfde9,0,local_6b4,(int)psVar2 - (int)local_6b4 >> 1,local_140c,0xd55,0,0);
      if (uVar3 == 0) {
LAB_006e4b91:
        DVar5 = GetLastError();
        *(DWORD *)param_1 = DVar5;
        break;
      }
      uVar6 = 0;
      if (uVar3 != 0) {
        do {
          BVar4 = WriteFile(local_1414,local_140c + uVar6,uVar3 - uVar6,&local_1418,
                            (LPOVERLAPPED)0x0);
          if (BVar4 == 0) goto LAB_006e4b91;
          uVar6 = uVar6 + local_1418;
        } while (uVar6 < uVar3);
      }
      *(uint *)(param_1 + 4) = (int)psVar7 - param_3;
    } while (psVar7 < local_1410);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

