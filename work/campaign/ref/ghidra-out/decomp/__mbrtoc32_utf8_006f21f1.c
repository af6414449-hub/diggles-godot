
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::__mbrtoc32_utf8(char32_t *,char const *,unsigned int,struct
   _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl
__crt_mbstring::__mbrtoc32_utf8(wchar32 *param_1,char *param_2,uint param_3,_Mbstatet *param_4)

{
  _Mbstatet _Var1;
  _Mbstatet _Var2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined **ppuVar7;
  uint *puVar8;
  uint local_20;
  uint local_1c;
  char local_17;
  byte local_16;
  char local_15;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_4 == (_Mbstatet *)0x0) {
    param_4 = (_Mbstatet *)&DAT_0076a22c;
  }
  ppuVar7 = (undefined **)param_2;
  if (param_2 == (char *)0x0) {
    ppuVar7 = &PTR_0071ce50;
    param_3 = 1;
  }
  puVar8 = (uint *)(-(uint)(param_2 != (char *)0x0) & (uint)param_1);
  if (param_3 == 0) goto LAB_006f2389;
  if (*(short *)(param_4 + 6) == 0) {
    local_16 = *(byte *)ppuVar7;
    ppuVar7 = (undefined **)((int)ppuVar7 + 1);
    if (-1 < (char)local_16) {
      if (puVar8 != (uint *)0x0) {
        *puVar8 = (uint)local_16;
      }
      goto LAB_006f2389;
    }
    if ((local_16 & 0xe0) == 0xc0) {
      local_15 = '\x02';
    }
    else if ((local_16 & 0xf0) == 0xe0) {
      local_15 = '\x03';
    }
    else {
      if ((local_16 & 0xf8) != 0xf0) goto LAB_006f2382;
      local_15 = '\x04';
    }
    local_17 = local_15;
    uVar6 = CONCAT11(local_15,local_15);
    uVar5 = (1 << (7U - local_15 & 0x1f)) - 1U & (uint)local_16;
LAB_006f22d6:
    uVar4 = (uint)(uVar6 >> 8);
    local_20 = param_3;
    if (uVar4 < param_3) {
      local_20 = uVar4;
    }
    local_1c = (int)ppuVar7 - (int)param_2;
    while (local_1c < local_20) {
      bVar3 = *(byte *)ppuVar7;
      ppuVar7 = (undefined **)((int)ppuVar7 + 1);
      local_1c = local_1c + 1;
      if ((bVar3 & 0xc0) != 0x80) goto LAB_006f2382;
      uVar5 = uVar5 << 6 | bVar3 & 0x3f;
    }
    if (local_20 < uVar4) {
      *(ushort *)(param_4 + 4) = uVar6 & 0xff;
      *(uint *)param_4 = uVar5;
      *(ushort *)(param_4 + 6) = (ushort)(byte)((char)(uVar6 >> 8) - (char)local_20);
      goto LAB_006f2389;
    }
    if (((uVar5 < 0xd800) || (0xdfff < uVar5)) && (uVar5 < 0x110000)) {
      local_14 = 0x80;
      local_10 = 0x800;
      local_c = 0x10000;
      if ((&local_1c)[uVar6 & 0xff] <= uVar5) {
        if (puVar8 != (uint *)0x0) {
          *puVar8 = uVar5;
        }
        *(undefined4 *)param_4 = 0;
        *(undefined4 *)(param_4 + 4) = 0;
        goto LAB_006f2389;
      }
    }
  }
  else {
    _Var1 = param_4[4];
    uVar5 = *(uint *)param_4;
    _Var2 = param_4[6];
    uVar6 = CONCAT11(_Var2,_Var1);
    if ((((byte)((char)_Var1 - 2U) < 3) && (_Var2 != (_Mbstatet)0x0)) && ((byte)_Var2 < (byte)_Var1)
       ) goto LAB_006f22d6;
  }
LAB_006f2382:
  return_illegal_sequence(param_4);
LAB_006f2389:
  uVar5 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return uVar5;
}

