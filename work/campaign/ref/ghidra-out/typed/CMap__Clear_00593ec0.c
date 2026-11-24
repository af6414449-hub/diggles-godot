
void __thiscall CMap__Clear(CMap *this)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = DAT_0077241c;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070692d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54d0) &&
     (FUN_006cebf4(&DAT_00ca54d0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca54d0 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca54d4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "CMap::Clear";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54d0);
  }
  iVar6 = DAT_00ca54d4;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca54d4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar2;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar8 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  iVar4 = *(int *)(*(int *)(iVar3 + 0x24) + 0x24);
  iVar6 = 0;
  if (iVar4 != -1) {
    iVar6 = iVar4;
  }
  iVar4 = 0;
  if (0 < *(int *)(iVar3 + 0x48) * *(int *)(iVar3 + 0x44)) {
    piVar1 = (int *)(iVar3 + 0x14);
    local_14 = 0;
    do {
      if ((iVar4 < 0) || (*(int *)(iVar3 + 0x18) <= iVar4)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        *(undefined2 *)(*piVar1 + 4) = 0xffff;
        if (-1 < iVar4) goto LAB_00593fc7;
LAB_00593fd7:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        *(undefined1 *)(*piVar1 + 6) = 0xff;
        if (-1 < iVar4) goto LAB_00593ff7;
LAB_00594008:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        *(int *)*piVar1 = iVar6;
        if (-1 < iVar4) goto LAB_00594029;
LAB_00594039:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        *(undefined1 *)(*piVar1 + 7) = 4;
        if (-1 < iVar4) goto LAB_00594059;
LAB_00594064:
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar5 = *piVar1;
      }
      else {
        *(undefined2 *)(local_14 + 4 + *piVar1) = 0xffff;
LAB_00593fc7:
        if (*(int *)(iVar3 + 0x18) <= iVar4) goto LAB_00593fd7;
        *(undefined1 *)(local_14 + 6 + *piVar1) = 0xff;
LAB_00593ff7:
        if (*(int *)(iVar3 + 0x18) <= iVar4) goto LAB_00594008;
        *(int *)(local_14 + *piVar1) = iVar6;
LAB_00594029:
        if (*(int *)(iVar3 + 0x18) <= iVar4) goto LAB_00594039;
        *(undefined1 *)(local_14 + 7 + *piVar1) = 4;
LAB_00594059:
        if (*(int *)(iVar3 + 0x18) <= iVar4) goto LAB_00594064;
        iVar5 = *piVar1 + local_14;
      }
      _memset((void *)(iVar5 + 8),0,0x74);
      iVar4 = iVar4 + 1;
      local_14 = local_14 + 0x7c;
    } while (iVar4 < *(int *)(iVar3 + 0x48) * *(int *)(iVar3 + 0x44));
  }
  uVar7 = 0;
  do {
    if (7 < uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_00581330(0);
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 8);
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

