
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10040d70(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 unaff_EBX;
  short sVar6;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_SS;
  undefined2 in_FS;
  undefined1 auStack_4 [4];
  int iVar7;
  
  puVar1 = (undefined4 *)segment(in_FS,0);
  sVar6 = (short)auStack_4 + -4;
  iVar7 = CONCAT22((short)((uint)auStack_4 >> 0x10),sVar6);
  puVar4 = (undefined4 *)segment(in_SS,sVar6);
  *puVar4 = *puVar1;
  iVar2 = *(int *)(iVar7 + 0x10);
  *(undefined4 *)(iVar7 + 0x10) = unaff_EBP;
  iVar2 = -iVar2;
  *(undefined4 *)(iVar7 + iVar2 + -4) = unaff_EBX;
  *(undefined4 *)(iVar7 + iVar2 + -8) = unaff_ESI;
  *(undefined4 *)(iVar7 + iVar2 + -0xc) = unaff_EDI;
  uVar5 = DAT_1005000c;
  *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) ^ DAT_1005000c;
  *(uint *)(iVar7 + iVar2 + -0x10) = uVar5 ^ iVar7 + 0x10U;
  *(int *)(iVar7 + -8) = iVar7 + iVar2 + -0x10;
  *(undefined4 *)(iVar7 + iVar2 + -0x14) = *(undefined4 *)(iVar7 + 8);
  uVar3 = *(undefined4 *)(iVar7 + 0xc);
  *(undefined4 *)(iVar7 + 0xc) = 0xfffffffe;
  *(undefined4 *)(iVar7 + 8) = uVar3;
  uVar3 = segment(in_FS,0);
  *(int *)uVar3 = iVar7;
  return;
}

