
undefined4
CTclGlobalMethods__LogMask(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  FILE *_File;
  undefined4 uVar3;
  undefined4 *puVar4;
  int local_30;
  char local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bbcd;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004298b0(param_3,param_4);
  local_8 = 0;
  FUN_006bc170(param_2);
  _File = _fopen("data/GameScripts/timeline.txt","a");
  if (_File != (FILE *)0x0) {
    FUN_00405ab0(_File,&DAT_0072e758,(int)*(double *)(DAT_00772400 + 0xa088),uVar2);
    uVar2 = 1;
    if (1 < param_3) {
      do {
        if ((int)uVar2 < local_18) {
          if (local_1c <= uVar2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar4 = local_20 + uVar2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar4 = local_20;
          if (local_1c == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        piVar1 = (int *)*puVar4;
        if (piVar1 == (int *)0x0) {
          FUN_00405ab0(_File,&DAT_00721a84,&PTR_0071ce50);
        }
        else {
          *piVar1 = *piVar1 + 1;
          uVar3 = Tcl_GetStringFromObj(piVar1,0);
          FUN_00405ab0(_File,&DAT_00721a84,uVar3);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 1) {
            TclFreeObj(piVar1);
          }
        }
        uVar2 = uVar2 + 1;
      } while ((int)uVar2 < param_3);
    }
    FUN_00405ab0(_File,&DAT_00721a8c);
    _fclose(_File);
  }
  if ((local_2c != '\0') && (local_30 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_30);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 1;
  if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
    FUN_006ba940();
  }
  local_8 = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return 0;
}

