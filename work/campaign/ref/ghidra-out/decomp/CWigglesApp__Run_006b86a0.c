
void CWigglesApp__Run(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined **local_1bc [14];
  undefined2 local_184;
  undefined8 local_13c;
  undefined4 local_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  DWORD local_120;
  DWORD local_11c;
  undefined1 local_118;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined2 local_d4;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined1 local_74;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined8 local_2c;
  undefined4 *local_24;
  int local_20;
  char local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = DAT_007724bc;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712fc6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7f30) {
    FUN_006cebf4(&DAT_00ca7f30,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar3 = DAT_00783650;
    if (DAT_00ca7f30 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca7f34 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "CWigglesApp::Run()";
      *(int *)(&DAT_00773650 + iVar4) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7f30);
    }
  }
  iVar4 = DAT_00ca7f34;
  local_24 = &DAT_00ca7f34;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7f34 * 0x40);
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
  local_8 = 0;
  FUN_006bc020();
  if ((local_1c != '\0') && (local_20 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_20);
  }
  local_20 = 0;
  local_20 = Tcl_CreateInterp();
  local_1c = '\x01';
  LOCK();
  DAT_00772dd4 = DAT_00772dd4 + 1;
  UNLOCK();
  if ((char)piVar2[2] != '\0') {
    FUN_00440000("CGameThread");
    local_1bc[0] = Threads::CGameThread::vftable;
    FUN_00440bd0();
    local_8._0_1_ = 3;
    local_dc = 0;
    local_d8 = 0;
    FUN_00462cf0();
    local_44 = 0;
    local_48 = 0;
    local_4c = 0;
    local_2c = 0;
    local_13c = 0;
    local_d4 = 0;
    local_7c = 0;
    local_5c = 0xbf4ccccd;
    local_58 = 0;
    local_120 = GetTickCount();
    local_11c = GetTickCount();
    local_3c = (undefined4)local_2c;
    uStack_38 = local_2c._4_4_;
    local_134 = (undefined4)local_2c;
    uStack_130 = local_2c._4_4_;
    uStack_12c = (undefined4)local_2c;
    uStack_128 = local_2c._4_4_;
    local_60 = 0x3f99999a;
    local_80 = 0x3f99999a;
    local_5c = 0;
    local_58 = 0;
    local_74 = 0;
    local_118 = 0;
    local_88 = 0xc47a0000;
    local_84 = 0xc47a0000;
    local_78 = 0;
    local_7c = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_006ae6b0(*piVar2 + 0xc,DAT_0076a2b0);
    local_184 = 1;
    FUN_00448cd0(local_1bc);
    FUN_006ae630();
  }
  if ((local_1c != '\0') && (local_20 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_20);
  }
  local_20 = 0;
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 5;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

