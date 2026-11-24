
/* Library Function - Single Match
    __setmbcp_nolock
   
   Library: Visual Studio 2019 Release */

void __setmbcp_nolock(int param_1,__crt_multibyte_data *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  BOOL BVar5;
  BYTE *pBVar6;
  __crt_multibyte_data *p_Var7;
  wchar_t *pwVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  undefined2 *puVar12;
  uint uVar13;
  int local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar3 = getSystemCP(param_1);
  if (uVar3 != 0) {
    uVar13 = 0;
    uVar4 = 0;
    local_20 = 0;
LAB_006ecd4c:
    if (*(uint *)((int)&DAT_007677e8 + uVar4) != uVar3) goto code_r0x006ecd58;
    _memset(param_2 + 0x18,0,0x101);
    pbVar9 = (byte *)(local_20 * 0x30 + 0x7677f8);
    do {
      bVar1 = *pbVar9;
      pbVar11 = pbVar9;
      while ((bVar1 != 0 && (bVar1 = pbVar11[1], bVar1 != 0))) {
        for (uVar4 = (uint)*pbVar11; (uVar4 <= bVar1 && (uVar4 < 0x100)); uVar4 = uVar4 + 1) {
          param_2[uVar4 + 0x19] =
               (__crt_multibyte_data)((byte)param_2[uVar4 + 0x19] | (&DAT_007677e0)[uVar13]);
          bVar1 = pbVar11[1];
        }
        pbVar11 = pbVar11 + 2;
        bVar1 = *pbVar11;
      }
      uVar13 = uVar13 + 1;
      pbVar9 = pbVar9 + 8;
    } while (uVar13 < 4);
    *(uint *)(param_2 + 4) = uVar3;
    *(undefined4 *)(param_2 + 8) = 1;
    pwVar8 = CPtoLocaleName(uVar3);
    *(wchar_t **)(param_2 + 0x21c) = pwVar8;
    p_Var7 = param_2 + 0xc;
    puVar12 = (undefined2 *)(local_20 * 0x30 + 0x7677ec);
    iVar10 = 6;
    do {
      uVar2 = *puVar12;
      puVar12 = puVar12 + 1;
      *(undefined2 *)p_Var7 = uVar2;
      p_Var7 = p_Var7 + 2;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    goto LAB_006ecda8;
  }
LAB_006ecef3:
  setSBCS(param_2);
LAB_006ecefc:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
code_r0x006ecd58:
  local_20 = local_20 + 1;
  uVar4 = uVar4 + 0x30;
  if (0xef < uVar4) goto code_r0x006ecd66;
  goto LAB_006ecd4c;
code_r0x006ecd66:
  if ((uVar3 == 65000) || (BVar5 = IsValidCodePage(uVar3 & 0xffff), BVar5 == 0)) goto LAB_006ecefc;
  if (uVar3 == 0xfde9) {
    *(undefined4 *)(param_2 + 4) = 0xfde9;
    *(undefined4 *)(param_2 + 0x21c) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined2 *)(param_2 + 0x1c) = 0;
  }
  else {
    BVar5 = GetCPInfo(uVar3,&local_1c);
    if (BVar5 == 0) {
      if (DAT_0076a1f0 == 0) goto LAB_006ecefc;
      goto LAB_006ecef3;
    }
    _memset(param_2 + 0x18,0,0x101);
    *(uint *)(param_2 + 4) = uVar3;
    *(undefined4 *)(param_2 + 0x21c) = 0;
    if (local_1c.MaxCharSize == 2) {
      pBVar6 = local_1c.LeadByte;
      while ((local_1c.LeadByte[0] != 0 && (bVar1 = pBVar6[1], bVar1 != 0))) {
        for (uVar3 = (uint)*pBVar6; uVar3 <= bVar1; uVar3 = uVar3 + 1) {
          param_2[uVar3 + 0x19] = (__crt_multibyte_data)((byte)param_2[uVar3 + 0x19] | 4);
        }
        pBVar6 = pBVar6 + 2;
        local_1c.LeadByte[0] = *pBVar6;
      }
      p_Var7 = param_2 + 0x1a;
      iVar10 = 0xfe;
      do {
        *p_Var7 = (__crt_multibyte_data)((byte)*p_Var7 | 8);
        p_Var7 = p_Var7 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      pwVar8 = CPtoLocaleName(*(int *)(param_2 + 4));
      *(wchar_t **)(param_2 + 0x21c) = pwVar8;
      uVar13 = 1;
    }
  }
  *(uint *)(param_2 + 8) = uVar13;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
LAB_006ecda8:
  setSBUpLow(param_2);
  goto LAB_006ecefc;
}

