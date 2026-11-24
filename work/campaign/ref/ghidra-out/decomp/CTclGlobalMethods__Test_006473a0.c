
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CTclGlobalMethods__Test(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9d4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70f0) {
    FUN_006cebf4(&DAT_00ca70f0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca70f0 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca70f4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::Test()";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca70f0);
    }
  }
  iVar3 = DAT_00ca70f4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70f4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  if (param_3 == 2) {
    piVar1 = *(int **)(param_4 + 4);
    if (piVar1 == (int *)0x0) {
      uVar7 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      *piVar1 = *piVar1 + -1;
      uVar7 = -(uint)(iVar2 != 1) & param_3;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    puVar6 = &DAT_00772490;
    do {
      if ((HMODULE)*puVar6 != (HMODULE)0x0) {
        FreeLibrary((HMODULE)*puVar6);
      }
      puVar6 = puVar6 + 1;
    } while ((int)puVar6 < 0x7724b0);
    if (uVar7 != 0) {
      DAT_00772490 = LoadLibraryA("mscat32.dll");
      pcVar4 = "Loaded %s";
      if (DAT_00772490 == (HMODULE)0x0) {
        pcVar4 = "Failed %s";
      }
      FUN_0054efe0(DAT_00772400 + 0x368,pcVar4,"mscat32.dll");
      DAT_00772494 = LoadLibraryA("mmdrv.dll");
      pcVar4 = "Loaded %s";
      if (DAT_00772494 == (HMODULE)0x0) {
        pcVar4 = "Failed %s";
      }
      FUN_0054efe0(DAT_00772400 + 0x368,pcVar4,"mmdrv.dll");
      _DAT_00772498 = LoadLibraryA("nv4_disp.dll");
      if (_DAT_00772498 == (HMODULE)0x0) {
        pcVar4 = "Failed %s";
      }
      else {
        pcVar4 = "Loaded %s";
      }
      FUN_0054efe0(DAT_00772400 + 0x368,pcVar4,"nv4_disp.dll");
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

