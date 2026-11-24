
bool __thiscall FUN_00413aa0(CAct_Lore *this)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int *in_stack_0000000c;
  int *in_stack_00000010;
  int *in_stack_00000014;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9cd5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c3ca94) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00c3ca94 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00c3ca98 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "LORE-INIT";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar4 = DAT_00c3ca98;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c3ca98 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar5 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = CONCAT31(local_8._1_3_,3);
  if (in_stack_00000014 != (int *)0x0) {
    *in_stack_00000014 = *in_stack_00000014 + 1;
  }
  if (in_stack_00000010 != (int *)0x0) {
    *in_stack_00000010 = *in_stack_00000010 + 1;
  }
  if (in_stack_0000000c != (int *)0x0) {
    *in_stack_0000000c = *in_stack_0000000c + 1;
  }
  FUN_00406630((CAct *)this);
  cVar2 = FUN_00412840();
  if (cVar2 != '\0') {
    FUN_00413570();
  }
  FUN_0043fd30();
  if ((in_stack_0000000c != (int *)0x0) &&
     (*in_stack_0000000c = *in_stack_0000000c + -1, *in_stack_0000000c < 1)) {
    TclFreeObj();
  }
  if ((in_stack_00000010 != (int *)0x0) &&
     (*in_stack_00000010 = *in_stack_00000010 + -1, *in_stack_00000010 < 1)) {
    TclFreeObj();
  }
  if ((in_stack_00000014 != (int *)0x0) &&
     (*in_stack_00000014 = *in_stack_00000014 + -1, *in_stack_00000014 < 1)) {
    TclFreeObj();
  }
  ExceptionList = local_10;
  return cVar2 != '\0';
}

