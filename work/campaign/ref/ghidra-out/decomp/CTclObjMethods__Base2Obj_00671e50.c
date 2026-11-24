
void * CTclObjMethods__Base2Obj(void)

{
  undefined4 uVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  undefined4 in_ECX;
  void *in_EDX;
  undefined8 uVar5;
  char *pcVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710695;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7478) {
    FUN_006cebf4(&DAT_00ca7478,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7478 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca747c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::Base2Obj()";
      *(int *)(&DAT_00773650 + iVar4) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7478);
    }
  }
  iVar4 = DAT_00ca747c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca747c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(in_ECX);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (in_EDX == (void *)0x0) {
    pcVar6 = "null reference";
  }
  else {
    BVar3 = IsBadReadPtr(in_EDX,0x10);
    if (((BVar3 == 0) && (*(int *)((int)in_EDX + 8) == 0x616e4f62)) &&
       ((DAT_00768398 == '\0' || (*(int *)((int)in_EDX + 0xdc) != 0)))) goto LAB_00671f4a;
    pcVar6 = "invalid reference";
  }
  FUN_006bc6a0(pcVar6,0);
  in_EDX = (void *)0x0;
LAB_00671f4a:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return in_EDX;
}

