
/* WARNING: Removing unreachable block (ram,0x006cf672) */
/* WARNING: Removing unreachable block (ram,0x006cf637) */
/* WARNING: Removing unreachable block (ram,0x006cf6e9) */
/* Library Function - Single Match
    ___isa_available_init
   
   Library: Visual Studio 2019 Release */

undefined4 ___isa_available_init(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint in_XCR0;
  
  DAT_00769a88 = 0;
  DAT_00767010 = DAT_00767010 | 1;
  BVar4 = IsProcessorFeaturePresent(10);
  uVar5 = DAT_00767010;
  if (BVar4 != 0) {
    piVar1 = (int *)cpuid_basic_info(0);
    puVar2 = (uint *)cpuid_Version_info(1);
    uVar6 = puVar2[3];
    if (((piVar1[1] == 0x756e6547 && piVar1[3] == 0x6c65746e) && piVar1[2] == 0x49656e69) &&
       (((((uVar5 = *puVar2 & 0xfff3ff0, uVar5 == 0x106c0 || (uVar5 == 0x20660)) ||
          (uVar5 == 0x20670)) || ((uVar5 == 0x30650 || (uVar5 == 0x30660)))) || (uVar5 == 0x30670)))
       ) {
      DAT_00769a8c = DAT_00769a8c | 1;
    }
    if (*piVar1 < 7) {
      uVar7 = 0;
    }
    else {
      iVar3 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar7 = *(uint *)(iVar3 + 4);
      if ((uVar7 & 0x200) != 0) {
        DAT_00769a8c = DAT_00769a8c | 2;
      }
    }
    DAT_00769a88 = 1;
    uVar5 = DAT_00767010 | 2;
    if ((uVar6 & 0x100000) != 0) {
      uVar5 = DAT_00767010 | 6;
      DAT_00769a88 = 2;
      if ((((uVar6 & 0x8000000) != 0) && ((uVar6 & 0x10000000) != 0)) && ((in_XCR0 & 6) == 6)) {
        DAT_00769a88 = 3;
        uVar5 = DAT_00767010 | 0xe;
        if ((uVar7 & 0x20) != 0) {
          DAT_00769a88 = 5;
          uVar5 = DAT_00767010 | 0x2e;
          if (((uVar7 & 0xd0030000) == 0xd0030000) && ((in_XCR0 & 0xe0) == 0xe0)) {
            DAT_00767010 = DAT_00767010 | 0x6e;
            DAT_00769a88 = 6;
            uVar5 = DAT_00767010;
          }
        }
      }
    }
  }
  DAT_00767010 = uVar5;
  return 0;
}

