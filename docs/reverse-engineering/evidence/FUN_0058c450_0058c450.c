
void FUN_0058c450(int *param_1,float param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  int iVar8;
  code *pcVar9;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar3 = param_1;
  pcVar9 = RaiseException_exref;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706675;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != (int *)0xffffffff) {
    if (*(int **)(in_ECX + 0x2c) <= param_1) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar1 = *(int *)(in_ECX + 0x28);
    if (*(int *)(iVar1 + (int)piVar3 * 0x1c) == -1) {
      uVar2 = *(uint *)(iVar1 + 0x18 + (int)piVar3 * 0x1c);
      param_1 = DAT_00772478;
      if ((uint)DAT_00772478[0x2007] <= uVar2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = *(int *)(param_1[0x2006] + uVar2 * 4);
      pcVar9 = RaiseException_exref;
      if (iVar6 != 0) {
        if (*(int *)(iVar6 + 0x14) < 1) {
          uVar5 = 0xffffffff;
        }
        else {
          if (*(int *)(iVar6 + 0x14) == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar5 = **(undefined4 **)(iVar6 + 0x10);
        }
        *(undefined4 *)(iVar1 + (int)piVar3 * 0x1c) = uVar5;
        if (*(int *)(iVar6 + 0x1c) < 1) {
          uVar5 = 0xffffffff;
        }
        else {
          if (*(int *)(iVar6 + 0x1c) == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar5 = **(undefined4 **)(iVar6 + 0x18);
        }
        *(undefined4 *)(iVar1 + 4 + (int)piVar3 * 0x1c) = uVar5;
        *(undefined4 *)(iVar1 + 8 + (int)piVar3 * 0x1c) = *(undefined4 *)(iVar6 + 0x24);
        pcVar9 = RaiseException_exref;
      }
    }
    if ((*(uint *)(iVar1 + 4 + (int)piVar3 * 0x1c) | *(uint *)(iVar1 + (int)piVar3 * 0x1c)) !=
        0xffffffff) {
      iVar6 = *(int *)(iVar1 + 0x14 + (int)piVar3 * 0x1c);
      iVar8 = DAT_00768388;
      if (*(char *)(DAT_00772400 + 0x590) != '\0') {
        iVar8 = 2;
      }
      if (iVar8 < 2 - iVar6) {
        if (iVar6 == 0) {
          FUN_005d7450();
          ExceptionList = local_10;
          return;
        }
        if (iVar6 == 1) {
          FUN_005d7450();
          ExceptionList = local_10;
          return;
        }
      }
      else {
        param_1 = DAT_00772478;
        if ((uint)DAT_00772478[0x2007] <= *(uint *)(iVar1 + 0x18 + (int)piVar3 * 0x1c)) {
          (*pcVar9)(0xc000008c);
        }
        iVar6 = FUN_00601df0();
        if (iVar6 != 0) {
          *(undefined4 *)(iVar6 + 0x3d0) = 0x20000081;
          *(undefined4 *)(iVar6 + 0x39c) = *(undefined4 *)(iVar1 + (int)piVar3 * 0x1c);
          FUN_0040b550();
          iVar8 = FUN_00405960();
          if (*(int *)(iVar8 + 0xc) < 1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(undefined4 *)(iVar6 + 0x3a0) = **(undefined4 **)(iVar8 + 8);
          *(undefined4 *)(iVar6 + 0x3a8) = *(undefined4 *)(iVar1 + 4 + (int)piVar3 * 0x1c);
          FUN_005cdae0(*(undefined4 *)(iVar1 + (int)piVar3 * 0x1c));
          *(undefined4 *)(iVar6 + 0x2a8) = *(undefined4 *)(iVar1 + 0x14 + (int)piVar3 * 0x1c);
          FUN_005cd7e0();
          FUN_005cd840();
          FUN_006b8fb0();
          local_8 = 0;
          FUN_00405e10();
          local_8._0_1_ = 3;
          if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 2;
          if (param_1 != (int *)0x0) {
            FUN_006b8f50();
            local_8._0_1_ = 4;
            FUN_006b9040(&local_14,"{%f %f %f} 0.8",(double)param_2,(double)param_3);
            FUN_006b8f50();
            local_8 = CONCAT31(local_8._1_3_,5);
            FUN_006b9040();
            piVar3 = param_1;
            if (local_14 != (int *)0xfffffff4) {
              piVar7 = (int *)Tcl_NewStringObj();
              *piVar7 = *piVar7 + 1;
            }
            if (local_18 + 3 != (int *)0x0) {
              piVar7 = (int *)Tcl_NewStringObj(local_18 + 3);
              *piVar7 = *piVar7 + 1;
              piVar7 = (int *)Tcl_NewStringObj();
              *piVar7 = *piVar7 + 1;
            }
            cVar4 = (**(code **)(*piVar3 + 8))();
            if (cVar4 != '\0') {
              FUN_00409280(&param_1);
            }
            local_8._0_1_ = 6;
            if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
              FUN_006ba940();
            }
            local_8 = CONCAT31(local_8._1_3_,7);
            if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
              FUN_006ba940();
            }
            if (param_1 != (int *)0x0) {
              LOCK();
              iVar1 = param_1[1] + -1;
              param_1[1] = iVar1;
              UNLOCK();
              if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
                (**(code **)*param_1)(1);
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

