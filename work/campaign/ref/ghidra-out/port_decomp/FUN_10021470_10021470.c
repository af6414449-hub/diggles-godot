
/* WARNING: Removing unreachable block (ram,0x100214b4) */
/* WARNING: Removing unreachable block (ram,0x10021492) */

uint FUN_10021470(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((DAT_1416f070 == 0) && (piVar1 = (int *)cpuid_basic_info(0), 0 < *piVar1)) {
    iVar2 = cpuid_Version_info(1);
    uVar3 = *(uint *)(iVar2 + 8) & 0x4000000;
    DAT_1416f070 = uVar3 + 1;
    return uVar3;
  }
  return DAT_1416f070 - 1;
}

