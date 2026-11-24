
undefined4
CTclGlobalMethods__SetSequence(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070decd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7108) &&
     (FUN_006cebf4(&DAT_00ca7108,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7108 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca710c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SetSequence()";
    *(int *)(&DAT_00773650 + iVar5) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7108);
  }
  iVar5 = DAT_00ca710c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca710c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar7;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar4 == 0) {
    uVar9 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  iVar3 = param_3;
  (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (iVar3 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_20 + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      bVar6 = false;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetBooleanFromObj(0,piVar2,&param_3);
      bVar6 = iVar4 != 1 && param_3 != 0;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    iVar4 = DAT_00772400;
    if ((bool)*(char *)(DAT_00772400 + 0x8c) != bVar6) {
      cVar1 = *(char *)(DAT_00772400 + 0x8f);
      *(bool *)(DAT_00772400 + 0x8c) = bVar6;
      *(bool *)(iVar4 + 0x598) = bVar6;
      *(undefined1 *)(iVar4 + 0x8d) = 0;
      if (cVar1 == '\0') {
        iVar4 = FUN_00501450();
        *(undefined4 *)(iVar4 + 0x101fc) = 1;
      }
      else {
        iVar4 = FUN_00501450();
        if (bVar6 == false) {
          *(undefined4 *)(iVar4 + 0x101fc) = 2;
          iVar4 = FUN_004d1090();
          SoloudAudioPlayer::Stop
                    ((SoloudAudioPlayer *)(&DAT_00b83e60 + *(int *)(iVar4 + 0xc) * 0x38));
          iVar4 = FUN_004d1090();
          SoloudAudioPlayer::Close
                    ((SoloudAudioPlayer *)(&DAT_00b83e60 + *(int *)(iVar4 + 0xc) * 0x38));
        }
        else {
          *(undefined4 *)(iVar4 + 0x101fc) = 4;
        }
      }
    }
    uVar7 = 0;
  }
  else {
    FUN_006bc8f0(1);
    uVar7 = 1;
  }
  FUN_006bc0d0();
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

