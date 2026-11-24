
/* Library Function - Single Match
    __seh_filter_exe
   
   Library: Visual Studio 2019 Release */

undefined4 __seh_filter_exe(uint param_1,int param_2)

{
  uint *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  
  piVar5 = (int *)___acrt_getptd_noexit();
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  puVar1 = (uint *)*piVar5;
  for (puVar8 = puVar1; puVar8 != puVar1 + 0x24; puVar8 = puVar8 + 3) {
    if (*puVar8 == param_1) goto LAB_006e0bd6;
  }
  puVar8 = (uint *)0x0;
LAB_006e0bd6:
  if (puVar8 == (uint *)0x0) {
    return 0;
  }
  pcVar2 = (code *)puVar8[2];
  if (pcVar2 == (code *)0x0) {
    return 0;
  }
  if (pcVar2 == (code *)&DAT_00000005) {
    puVar8[2] = 0;
    return 1;
  }
  if (pcVar2 == (code *)0x1) {
    return 0xffffffff;
  }
  iVar3 = piVar5[1];
  piVar5[1] = param_2;
  if (puVar8[1] != 8) {
    puVar8[2] = 0;
    guard_check_icall(puVar8[1]);
    (*pcVar2)();
    goto LAB_006e0ce3;
  }
  for (puVar6 = puVar1 + 9; puVar6 != puVar1 + 0x24; puVar6 = puVar6 + 3) {
    puVar6[2] = 0;
  }
  iVar4 = piVar5[2];
  iVar7 = iVar4;
  if (*puVar8 < 0xc0000092) {
    if (*puVar8 == 0xc0000091) {
      iVar7 = 0x84;
    }
    else if (*puVar8 == 0xc000008d) {
      iVar7 = 0x82;
    }
    else if (*puVar8 == 0xc000008e) {
      iVar7 = 0x83;
    }
    else if (*puVar8 == 0xc000008f) {
      iVar7 = 0x86;
    }
    else {
      if (*puVar8 != 0xc0000090) goto LAB_006e0cc0;
      iVar7 = 0x81;
    }
LAB_006e0cbd:
    piVar5[2] = iVar7;
  }
  else {
    if (*puVar8 == 0xc0000092) {
      iVar7 = 0x8a;
      goto LAB_006e0cbd;
    }
    if (*puVar8 == 0xc0000093) {
      iVar7 = 0x85;
      goto LAB_006e0cbd;
    }
    if (*puVar8 == 0xc00002b4) {
      iVar7 = 0x8e;
      goto LAB_006e0cbd;
    }
    if (*puVar8 == 0xc00002b5) {
      iVar7 = 0x8d;
      goto LAB_006e0cbd;
    }
  }
LAB_006e0cc0:
  guard_check_icall(8,iVar7);
  (*pcVar2)();
  piVar5[2] = iVar4;
LAB_006e0ce3:
  piVar5[1] = iVar3;
  return 0xffffffff;
}

