
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___report_gsfailure
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void __cdecl ___report_gsfailure(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte bVar4;
  byte bVar5;
  byte in_AF;
  byte bVar6;
  byte bVar7;
  byte in_TF;
  byte in_IF;
  byte bVar8;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined8 uVar9;
  undefined4 unaff_retaddr;
  
  uVar2 = IsProcessorFeaturePresent(0x17);
  uVar9 = CONCAT44(extraout_EDX,uVar2);
  bVar4 = 0;
  bVar8 = 0;
  bVar7 = (int)uVar2 < 0;
  bVar6 = uVar2 == 0;
  bVar5 = (POPCOUNT(uVar2 & 0xff) & 1U) == 0;
  uVar3 = extraout_ECX;
  if (!(bool)bVar6) {
    pcVar1 = (code *)swi(0x29);
    uVar9 = (*pcVar1)();
    uVar3 = extraout_ECX_00;
  }
  _DAT_00769858 = (undefined4)((ulonglong)uVar9 >> 0x20);
  _DAT_00769860 = (undefined4)uVar9;
  _DAT_00769870 =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar8 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar7 & 1) * 0x80 | (uint)(bVar6 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar5 & 1) * 4 | (uint)(bVar4 & 1) |
       (uint)(in_ID & 1) * 0x200000 | (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 |
       (uint)(in_AC & 1) * 0x40000;
  _DAT_00769874 = &stack0x00000004;
  _DAT_007697b0 = 0x10001;
  _DAT_00769760 = 0xc0000409;
  _DAT_00769764 = 1;
  _DAT_00769770 = 1;
  DAT_00769774 = 2;
  _DAT_0076976c = unaff_retaddr;
  _DAT_0076983c = in_GS;
  _DAT_00769840 = in_FS;
  _DAT_00769844 = in_ES;
  _DAT_00769848 = in_DS;
  _DAT_0076984c = unaff_EDI;
  _DAT_00769850 = unaff_ESI;
  _DAT_00769854 = unaff_EBX;
  _DAT_0076985c = uVar3;
  _DAT_00769864 = unaff_EBP;
  DAT_00769868 = unaff_retaddr;
  _DAT_0076986c = in_CS;
  _DAT_00769878 = in_SS;
  ___raise_securityfailure(&PTR_DAT_007157b0);
  return;
}

